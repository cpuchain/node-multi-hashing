#include "yespower.h"

void yespower_hash(const char* input, char* output, uint32_t len) {
    static const yespower_params_t params = {
        .version = YESPOWER_1_0,
        .N = 2048,
        .r = 32,
        .pers = NULL,
        .perslen = 0
    };
    yespower_tls((const uint8_t*)input, 80, &params, (yespower_binary_t*)output);
}

void cpupower_hash(const char *input, char *output, uint32_t len) {
    static const yespower_params_t params = {
        .version = YESPOWER_1_0,
        .N = 2048,
        .r = 32,
        .pers = (const uint8_t*)"CPUpower: The number of CPU working or available for proof-of-work mining",
        .perslen = 73
    };
    yespower_tls((const uint8_t*)input, 80, &params, (yespower_binary_t*)output);
}
