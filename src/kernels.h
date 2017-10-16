#ifndef KERNELS_H
#define KERNELS_H

#include <stddef.h>
#include <stdint.h>



int load_external_kernels(void);
void unload_externel_kernels(void);
int has_external_kernels(void);

#define DECLARE_EXTERNAL_KERNEL(name) \
  const uint32_t (*(name))[4]; \
  int name ##_size

DECLARE_EXTERNAL_KERNEL(gen8_brc_init_bin_vp8);
DECLARE_EXTERNAL_KERNEL(gen8_brc_reset_bin_vp8);
DECLARE_EXTERNAL_KERNEL(gen8_scaling_bin_vp8);
DECLARE_EXTERNAL_KERNEL(gen8_me_bin_vp8);
DECLARE_EXTERNAL_KERNEL(gen8_mbenc_i_frame_dist_bin_vp8);
DECLARE_EXTERNAL_KERNEL(gen8_mbenc_i_frame_luma_bin_vp8);
DECLARE_EXTERNAL_KERNEL(gen8_mbenc_i_frame_chroma_bin_vp8);
DECLARE_EXTERNAL_KERNEL(gen8_mbenc_p_frame_bin_vp8);
DECLARE_EXTERNAL_KERNEL(gen8_mpu_bin_vp8);
DECLARE_EXTERNAL_KERNEL(gen8_tpu_bin_vp8);
DECLARE_EXTERNAL_KERNEL(gen8_brc_update_bin_vp8);

DECLARE_EXTERNAL_KERNEL(gen9_brc_init_bin_vp8);
DECLARE_EXTERNAL_KERNEL(gen9_brc_reset_bin_vp8);
DECLARE_EXTERNAL_KERNEL(gen9_scaling_bin_vp8);
DECLARE_EXTERNAL_KERNEL(gen9_me_bin_vp8);
DECLARE_EXTERNAL_KERNEL(gen9_mbenc_i_frame_dist_bin_vp8);
DECLARE_EXTERNAL_KERNEL(gen9_mbenc_i_frame_luma_bin_vp8);
DECLARE_EXTERNAL_KERNEL(gen9_mbenc_i_frame_chroma_bin_vp8);
DECLARE_EXTERNAL_KERNEL(gen9_mbenc_p_frame_bin_vp8);
DECLARE_EXTERNAL_KERNEL(gen9_mpu_bin_vp8);
DECLARE_EXTERNAL_KERNEL(gen9_tpu_bin_vp8);
DECLARE_EXTERNAL_KERNEL(gen9_brc_update_bin_vp8);

DECLARE_EXTERNAL_KERNEL(gen75_gpe_sharpening_h_blur);
DECLARE_EXTERNAL_KERNEL(gen75_gpe_sharpening_v_blur);
DECLARE_EXTERNAL_KERNEL(gen75_gpe_sharpening_unmask);

DECLARE_EXTERNAL_KERNEL(gen8_gpe_sharpening_h_blur);
DECLARE_EXTERNAL_KERNEL(gen8_gpe_sharpening_v_blur);
DECLARE_EXTERNAL_KERNEL(gen8_gpe_sharpening_unmask);
DECLARE_EXTERNAL_KERNEL(pp_yuv420p8_scaling_gen8);

DECLARE_EXTERNAL_KERNEL(pp_10bit_scaling_gen9);
DECLARE_EXTERNAL_KERNEL(pp_yuv420p8_scaling_gen9);
DECLARE_EXTERNAL_KERNEL(pp_10bit_8bit_scaling_gen9);

#endif
