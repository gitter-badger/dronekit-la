#ifndef ANALYZE_COMPASS_OFFSETS_H
#define ANALYZE_COMPASS_OFFSETS_H

/*
 * analyze_compass_offsets
 *
 */

#include "analyzer.h"

class Analyzer_Compass_Offsets : public Analyzer {

public:
    Analyzer_Compass_Offsets(int fd, struct sockaddr_in &sa) :
	Analyzer(fd, sa),
        warn_offset(100),
        fail_offset(200),
        compass_offset_results_offset(0)
    {
        have_compass_ofs[0] = false;
        have_compass_ofs[1] = false;
        have_compass_ofs[2] = false;
    }

    const char *name() { return "Compass Offsets"; }
    const char *description() {
        return "Compass offsets and vector length are reasonable";
    }

    bool configure(INIReader *config);
    void handle_decoded_message(uint64_t T, mavlink_param_value_t &param) override;
    bool is_zero(double x) { return x < 0.00001; } // FIXME

private:
    double compass_ofs[3];
    bool have_compass_ofs[3];
    const uint16_t warn_offset;
    const uint16_t fail_offset;

    enum compass_offset_status {
        compass_offset_warn = 17,
        compass_offset_fail,
        compass_offset_zero,
        compass_offset_ok,
    };
    struct compass_offset_result {
        uint64_t timestamp;
        double len;
        compass_offset_status status;
    };
    void do_add_evilness(struct compass_offset_result result);

    #define MAX_COMPASS_OFFSET_RESULTS 100
    uint8_t compass_offset_results_offset;
    compass_offset_result compass_offset_results[MAX_COMPASS_OFFSET_RESULTS];
    bool compass_offset_results_overrun;
    
    void addStatusReason(Json::Value &root, compass_offset_result result);
    uint32_t results_json_compass_offsets_status_reason(char *buf, const uint32_t buflen, compass_offset_result result);
    const char * results_json_compass_offsets_status_string(compass_offset_result result);
    uint32_t results_json_compass_offsets(char *buf, uint32_t buflen);
    void results_json_results(Json::Value &root);

    void results_json_compass_offsets(Json::Value &root);
};

#endif