#include <stdint.h>

const uint32_t gen8_brc_init_bin_vp8[][4] = {
#include "shaders/brc/bsw/vp8_brc_init_genx_0.g8b"
};

const uint32_t gen8_brc_reset_bin_vp8[][4] = {
#include "shaders/brc/bsw/vp8_brc_reset_genx_0.g8b"
};

const uint32_t gen8_scaling_bin_vp8[][4] = {
#include "shaders/brc/bsw/hme_downscale_genx_0.g8b"
};

const uint32_t gen8_me_bin_vp8[][4] = {
#include "shaders/brc/bsw/hme_genx_0.g8b"
};

const uint32_t gen8_mbenc_i_frame_dist_bin_vp8[][4] = {
#include "shaders/brc/bsw/vp8_intra_distortion_genx_0.g8b"
};

const uint32_t gen8_mbenc_i_frame_luma_bin_vp8[][4] = {
#include "shaders/brc/bsw/vp8_enc_genx_0.g8b"
};

const uint32_t gen8_mbenc_i_frame_chroma_bin_vp8[][4] = {
#include "shaders/brc/bsw/vp8_enc_genx_1.g8b"
};

const uint32_t gen8_mbenc_p_frame_bin_vp8[][4] = {
#include "shaders/brc/bsw/vp8_enc_genx_2.g8b"
};

const uint32_t gen8_mpu_bin_vp8[][4] = {
#include "shaders/brc/bsw/vp8_mpu_genx_0.g8b"
};

const uint32_t gen8_tpu_bin_vp8[][4] = {
#include "shaders/brc/bsw/vp8_tpu_genx_0.g8b"
};

const uint32_t gen8_brc_update_bin_vp8[][4] = {
#include "shaders/brc/bsw/vp8_brc_update_genx_0.g8b"
};

const int gen8_brc_init_bin_vp8_size = sizeof(gen8_brc_init_bin_vp8);
const int gen8_brc_reset_bin_vp8_size = sizeof(gen8_brc_reset_bin_vp8);
const int gen8_scaling_bin_vp8_size = sizeof(gen8_scaling_bin_vp8);
const int gen8_me_bin_vp8_size = sizeof(gen8_me_bin_vp8);
const int gen8_mbenc_i_frame_dist_bin_vp8_size = sizeof(gen8_mbenc_i_frame_dist_bin_vp8);
const int gen8_mbenc_i_frame_luma_bin_vp8_size = sizeof(gen8_mbenc_i_frame_luma_bin_vp8);
const int gen8_mbenc_i_frame_chroma_bin_vp8_size = sizeof(gen8_mbenc_i_frame_chroma_bin_vp8);
const int gen8_mbenc_p_frame_bin_vp8_size = sizeof(gen8_mbenc_p_frame_bin_vp8);
const int gen8_mpu_bin_vp8_size = sizeof(gen8_mpu_bin_vp8);
const int gen8_tpu_bin_vp8_size = sizeof(gen8_tpu_bin_vp8);
const int gen8_brc_update_bin_vp8_size = sizeof(gen8_brc_update_bin_vp8);
