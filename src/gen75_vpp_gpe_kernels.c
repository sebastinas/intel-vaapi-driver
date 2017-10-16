
const unsigned int gen75_gpe_sharpening_h_blur[][4] = {
#include "shaders/post_processing/gen75/sharpening_h_blur.g75b"
};
const unsigned int gen75_gpe_sharpening_v_blur[][4] = {
#include "shaders/post_processing/gen75/sharpening_v_blur.g75b"
};
const unsigned int gen75_gpe_sharpening_unmask[][4] = {
#include "shaders/post_processing/gen75/sharpening_unmask.g75b"
};

const unsigned int gen8_gpe_sharpening_h_blur[][4] = {
#include "shaders/post_processing/gen8/sharpening_h_blur.g8b"
};
const unsigned int gen8_gpe_sharpening_v_blur[][4] = {
#include "shaders/post_processing/gen8/sharpening_v_blur.g8b"
};
const unsigned int gen8_gpe_sharpening_unmask[][4] = {
#include "shaders/post_processing/gen8/sharpening_unmask.g8b"
};

const int gen75_gpe_sharpening_h_blur_size = sizeof(gen75_gpe_sharpening_h_blur);
const int gen75_gpe_sharpening_v_blur_size = sizeof(gen75_gpe_sharpening_v_blur);
const int gen75_gpe_sharpening_unmask_size = sizeof(gen75_gpe_sharpening_unmask);

const int gen8_gpe_sharpening_h_blur_size = sizeof(gen8_gpe_sharpening_h_blur);
const int gen8_gpe_sharpening_v_blur_size = sizeof(gen8_gpe_sharpening_v_blur);
const int gen8_gpe_sharpening_unmask_size = sizeof(gen8_gpe_sharpening_unmask);
