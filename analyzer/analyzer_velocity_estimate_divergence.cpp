#include "analyzer_velocity_estimate_divergence.h"

#include "analyzer_util.h"

void Analyzer_Velocity_Estimate_Divergence::end_of_log(const uint32_t packet_count UNUSED)
{
    // for (std::map<const std::string, Analyzer_Velocity_Estimate_Divergence_Result*>::iterator it = _result.begin();
    //      it != _result.end();
    //      ++it) {
    //     Analyzer_Velocity_Estimate_Divergence_Result *result = (*it).second;
    //     if (result != NULL) {
    //         close_result((*it).first);
    //     }        
    // }
}

// void Analyzer_Velocity_Estimate_Divergence::evaluate_estimate(
//     const std::string name,
//     AnalyzerVehicle::Velocity velocity,
//     AnalyzerVehicle::Velocity estimate)
// {
    // if (estimate.lat_modtime() == 0) {
    //     // No estimate for this  yet
    //     return;
    // }
    // double delta = estimate.horizontal_distance_to(velocity);

    // bool failing = (delta > delta_warn());
    // // ::fprintf(stderr, "%s: delta=%f delta_warn=%f: %s\n", name.c_str(), delta, delta_warn(), failing ? "FAILING" : "");

    // if (_result.count(name) == 0 ||
    //     _result[name] == NULL) {
    //     // no current problem
    //     if (failing) {
    //         open_result(name, delta);
    //     }
    // } else {
    //     // problem currently underway
    //     if (failing) {
    //         update_result(name, delta);
    //     } else {
    //         close_result(name);
    //     }
    // }
// }

// void Analyzer_Velocity_Estimate_Divergence::open_result(const std::string name,
//                                                         double delta)
// {
//     _result[name] = new Analyzer_Velocity_Estimate_Divergence_Result(name);
//    _result[name]->set_reason("This velocity estimate differs from the canonical craft velocity");
//     _result[name]->set_T_start(_vehicle->T());
//     _result[name]->set_max_delta(0);
//     _result[name]->add_source(_data_sources.get("VELOCITY"));
//     _result[name]->add_source(_data_sources.get(std::string("VELOCITY_ESTIMATE_") + name));
//     update_result(name, delta);
// }

// void Analyzer_Velocity_Estimate_Divergence::update_result(std::string name,
//                                                           double delta)
// {
//     if (delta > _result[name]->max_delta()) {
//         _result[name]->set_max_delta(delta);
//         if (delta >= delta_fail()) {
//             _result[name]->set_delta_threshold(delta_fail());
//             _result[name]->set_status(analyzer_status_fail);
//             _result[name]->set_evilness(20);
//         } else if (delta >= delta_warn()) {
//             _result[name]->set_status(analyzer_status_warn);
//             _result[name]->set_delta_threshold(delta_warn());
//             _result[name]->set_evilness(10);
//         }
//     }
// }

// void Analyzer_Velocity_Estimate_Divergence::close_result(const std::string name)
// {
//     _result[name]->set_T_stop(_vehicle->T());
//     if (_result[name]->duration() < delta_time_threshold()) {
//         delete _result[name];
//         _result[name] = NULL;
//         return;
//     }

//     _result[name]->add_evidence(string_format("max-delta=%f metres", _result[name]->max_delta()));
//     _result[name]->add_evidence(string_format("delta-threshold=%f metres", _result[name]->delta_threshold()));
//     _result[name]->add_evidence(string_format("delta-time-threshold=%f seconds", delta_time_threshold() / 1000000.0f));

//     add_result(_result[name]);
//     _result[name] = NULL;
// }

void Analyzer_Velocity_Estimate_Divergence::evaluate()
{
    // const std::map<const std::string, AnalyzerVehicle::VelocityEstimate*> &estimates =
    //     _vehicle->velocity_estimates();
    AnalyzerVehicle::Velocity vel = _vehicle->vel();
    if (vel.velocity_modtime() == 0) {
        // No craft velocity yet
        return;
    }
    // ::fprintf(stderr, "Velocity: %f\n", vel.size());
    if (vel.size() > _maximum_velocity) {
        _maximum_velocity = vel.size();
    }
    // for (std::map<const std::string, AnalyzerVehicle::VelocityEstimate*>::const_iterator it = estimates.begin();
    //      it != estimates.end();
    //      ++it) {
    //     AnalyzerVehicle::VelocityEstimate *est = (*it).second;
    //     AnalyzerVehicle::Velocity estimate = est->velocity();
    //     evaluate_estimate((*it).first, pos, estimate);
    // }

    // if (!prevpos.is_zero_zero() &&
    //     !pos.is_zero_zero()) {
    //     _total_distance_travelled += prevpos.horizontal_distance_to(pos);
    //     const double dfo = _vehicle->distance_from_origin();
    //     if (!is_equal(dfo, -1)) {
    //         if (dfo > _maximum_distance_from_origin) {
    //             _maximum_distance_from_origin = dfo;
    //         }
    //     }
    // }
    // prevpos = pos;
}
