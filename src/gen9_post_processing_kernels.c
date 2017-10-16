#include <stdint.h>

const uint32_t pp_10bit_scaling_gen9[][4] = {
#include "shaders/post_processing/gen9/conv_p010.g9b"
};

const uint32_t pp_yuv420p8_scaling_gen9[][4] = {
#include "shaders/post_processing/gen9/conv_nv12.g9b"
};

const uint32_t pp_10bit_8bit_scaling_gen9[][4] = {
#include "shaders/post_processing/gen9/conv_10bit_8bit.g9b"
};

const uint32_t pp_10bit_scaling_gen9_size = sizeof(pp_10bit_scaling_gen9);
const uint32_t pp_yuv420p8_scaling_gen9_size = sizeof(pp_yuv420p8_scaling_gen9);
const uint32_t pp_10bit_8bit_scaling_gen9_size = sizeof(pp_10bit_8bit_scaling_gen9);
