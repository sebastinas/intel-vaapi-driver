#include <stdint.h>

const uint32_t pp_yuv420p8_scaling_gen8[][4] = {
#include "shaders/post_processing/gen8/conv_nv12.g8b"
};

const int pp_yuv420p8_scaling_gen8_size = sizeof(pp_yuv420p8_scaling_gen8);
