#include "analyzer_brownout.h"

#include "util.h"
#include "analyzer_util.h"

bool Analyzer_Brownout::configure(INIReader *config)
{
    if (!Analyzer::configure(config)) {
	return false;
    }

    max_last_relative_altitude = config->GetReal("loganalyzer", "brownout::max_last_relative_altitude", 15.0f);

    return true;
}

void Analyzer_Brownout::evaluate()
{
    bool new_is_flying = _vehicle->is_flying();
    if (new_is_flying && !_old_is_flying) {
        _result.set_takeoff_altitude(_vehicle->altitude());
        _old_is_flying = new_is_flying;
    } else if (!new_is_flying && _old_is_flying) {
        _old_is_flying = new_is_flying;
    }
}

void Analyzer_Brownout::end_of_log(const uint32_t packet_count UNUSED)
{
    double last_altitude = _vehicle->altitude();
    _result.set_last_altitude(last_altitude);

    if (_vehicle->alt_modtime() > 0) {
        _result.add_evidence(string_format("Final altitude %f metres", _result.last_altitude()));
        if (_vehicle->is_flying()) {

            _result.add_evidence(string_format("Takeoff altitude %f metres", _result.takeoff_altitude()));
            double last_relative_altitude = _result.last_altitude() - _result.takeoff_altitude();
            _result.add_evidence(string_format("Final relative altitude %f metres", last_relative_altitude));

            _result.set_status(analyzer_status_fail);
            _result.increase_severity_score(10);
            if (last_relative_altitude > max_last_relative_altitude) {
                _result.increase_severity_score(10);
            }
            _result.add_source(_data_sources.get("SERVO_OUTPUT"));
            _result.add_source(_data_sources.get("ALTITUDE"));
            _result.set_reason("Log ended while craft still flying");
            _result.add_evidence("Vehicle still flying");
        } else {
            _result.set_status(analyzer_status_ok);
            _result.add_source(_data_sources.get("SERVO_OUTPUT"));
            _result.add_source(_data_sources.get("ALTITUDE"));
            _result.set_reason("No brownout detected");
        }
    } else {
        _result.set_status(analyzer_status_warn);
        _result.increase_severity_score(5);
        _result.set_reason("Altitude never changed");
        _result.add_source(_data_sources.get("ALTITUDE"));
    }

    add_result(&_result);
}
