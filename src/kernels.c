#include "kernels.h"

#include <dlfcn.h>

#include "i965_avc_encoder_kernels.h"
#include "gen9_hevc_enc_kernels.h"
#include "gen9_vp9_encoder_kernels.h"

#define DEFINE_EXTERNAL_KERNEL(name) \
  const unsigned int* name = NULL; \
  int name ##_size = 0

DEFINE_EXTERNAL_KERNEL(media_vp9_kernels);
DEFINE_EXTERNAL_KERNEL(gen9_hevc_encoder_kernels);
DEFINE_EXTERNAL_KERNEL(skl_avc_encoder_kernels);
DEFINE_EXTERNAL_KERNEL(skl_avc_fei_encoder_kernels);
DEFINE_EXTERNAL_KERNEL(kbl_avc_encoder_kernels);
DEFINE_EXTERNAL_KERNEL(bdw_avc_encoder_kernels);

#undef DEFINE_EXTERNAL_KERNEL
#define DEFINE_EXTERNAL_KERNEL(name) \
  const uint32_t (*(name))[4] = NULL; \
  int name ##_size = 0

/* Gen 8 VP8 kernels */
DEFINE_EXTERNAL_KERNEL(gen8_brc_init_bin_vp8);
DEFINE_EXTERNAL_KERNEL(gen8_brc_reset_bin_vp8);
DEFINE_EXTERNAL_KERNEL(gen8_scaling_bin_vp8);
DEFINE_EXTERNAL_KERNEL(gen8_me_bin_vp8);
DEFINE_EXTERNAL_KERNEL(gen8_mbenc_i_frame_dist_bin_vp8);
DEFINE_EXTERNAL_KERNEL(gen8_mbenc_i_frame_luma_bin_vp8);
DEFINE_EXTERNAL_KERNEL(gen8_mbenc_i_frame_chroma_bin_vp8);
DEFINE_EXTERNAL_KERNEL(gen8_mbenc_p_frame_bin_vp8);
DEFINE_EXTERNAL_KERNEL(gen8_mpu_bin_vp8);
DEFINE_EXTERNAL_KERNEL(gen8_tpu_bin_vp8);
DEFINE_EXTERNAL_KERNEL(gen8_brc_update_bin_vp8);

/* Gen 9 VP8 kernels */
DEFINE_EXTERNAL_KERNEL(gen9_brc_init_bin_vp8);
DEFINE_EXTERNAL_KERNEL(gen9_brc_reset_bin_vp8);
DEFINE_EXTERNAL_KERNEL(gen9_scaling_bin_vp8);
DEFINE_EXTERNAL_KERNEL(gen9_me_bin_vp8);
DEFINE_EXTERNAL_KERNEL(gen9_mbenc_i_frame_dist_bin_vp8);
DEFINE_EXTERNAL_KERNEL(gen9_mbenc_i_frame_luma_bin_vp8);
DEFINE_EXTERNAL_KERNEL(gen9_mbenc_i_frame_chroma_bin_vp8);
DEFINE_EXTERNAL_KERNEL(gen9_mbenc_p_frame_bin_vp8);
DEFINE_EXTERNAL_KERNEL(gen9_mpu_bin_vp8);
DEFINE_EXTERNAL_KERNEL(gen9_tpu_bin_vp8);
DEFINE_EXTERNAL_KERNEL(gen9_brc_update_bin_vp8);

/* Gen 7.5 sharpening kernels */
DEFINE_EXTERNAL_KERNEL(gen75_gpe_sharpening_h_blur);
DEFINE_EXTERNAL_KERNEL(gen75_gpe_sharpening_v_blur);
DEFINE_EXTERNAL_KERNEL(gen75_gpe_sharpening_unmask);

/* Gen 8 sharpening kernels */
DEFINE_EXTERNAL_KERNEL(gen8_gpe_sharpening_h_blur);
DEFINE_EXTERNAL_KERNEL(gen8_gpe_sharpening_v_blur);
DEFINE_EXTERNAL_KERNEL(gen8_gpe_sharpening_unmask);
/* Gen 8 post-processing kernels */
DEFINE_EXTERNAL_KERNEL(pp_yuv420p8_scaling_gen8);

/* Gen 9 post-processing kernels */
DEFINE_EXTERNAL_KERNEL(pp_10bit_scaling_gen9);
DEFINE_EXTERNAL_KERNEL(pp_yuv420p8_scaling_gen9);
DEFINE_EXTERNAL_KERNEL(pp_10bit_8bit_scaling_gen9);

static void* dso_handle = NULL;

int load_external_kernels(void) {
  /* already loaded */
  if (dso_handle != NULL) {
    return 1;
  }

  dso_handle = dlopen("./i965_drv_video_shaders.so", RTLD_LOCAL | RTLD_NOW);
  if (dso_handle == NULL) {
    goto err;
  }

#define LOAD_EXTERNAL_KERNEL(name) \
  do { \
    const int* tmp_size = dlsym(dso_handle, #name "_size"); \
    name = dlsym(dso_handle, #name); \
    if (tmp_size == NULL || name == NULL) { \
      goto err; \
    } \
    name##_size = *tmp_size; \
  } while(0)

  LOAD_EXTERNAL_KERNEL(media_vp9_kernels);
  LOAD_EXTERNAL_KERNEL(gen9_hevc_encoder_kernels);
  LOAD_EXTERNAL_KERNEL(skl_avc_encoder_kernels);
  LOAD_EXTERNAL_KERNEL(skl_avc_fei_encoder_kernels);
  LOAD_EXTERNAL_KERNEL(kbl_avc_encoder_kernels);
  LOAD_EXTERNAL_KERNEL(bdw_avc_encoder_kernels);

  LOAD_EXTERNAL_KERNEL(gen8_brc_init_bin_vp8);
  LOAD_EXTERNAL_KERNEL(gen8_brc_reset_bin_vp8);
  LOAD_EXTERNAL_KERNEL(gen8_scaling_bin_vp8);
  LOAD_EXTERNAL_KERNEL(gen8_me_bin_vp8);
  LOAD_EXTERNAL_KERNEL(gen8_mbenc_i_frame_dist_bin_vp8);
  LOAD_EXTERNAL_KERNEL(gen8_mbenc_i_frame_luma_bin_vp8);
  LOAD_EXTERNAL_KERNEL(gen8_mbenc_i_frame_chroma_bin_vp8);
  LOAD_EXTERNAL_KERNEL(gen8_mbenc_p_frame_bin_vp8);
  LOAD_EXTERNAL_KERNEL(gen8_mpu_bin_vp8);
  LOAD_EXTERNAL_KERNEL(gen8_tpu_bin_vp8);
  LOAD_EXTERNAL_KERNEL(gen8_brc_update_bin_vp8);

  LOAD_EXTERNAL_KERNEL(gen9_brc_init_bin_vp8);
  LOAD_EXTERNAL_KERNEL(gen9_brc_reset_bin_vp8);
  LOAD_EXTERNAL_KERNEL(gen9_scaling_bin_vp8);
  LOAD_EXTERNAL_KERNEL(gen9_me_bin_vp8);
  LOAD_EXTERNAL_KERNEL(gen9_mbenc_i_frame_dist_bin_vp8);
  LOAD_EXTERNAL_KERNEL(gen9_mbenc_i_frame_luma_bin_vp8);
  LOAD_EXTERNAL_KERNEL(gen9_mbenc_i_frame_chroma_bin_vp8);
  LOAD_EXTERNAL_KERNEL(gen9_mbenc_p_frame_bin_vp8);
  LOAD_EXTERNAL_KERNEL(gen9_mpu_bin_vp8);
  LOAD_EXTERNAL_KERNEL(gen9_tpu_bin_vp8);
  LOAD_EXTERNAL_KERNEL(gen9_brc_update_bin_vp8);

  LOAD_EXTERNAL_KERNEL(gen75_gpe_sharpening_h_blur);
  LOAD_EXTERNAL_KERNEL(gen75_gpe_sharpening_v_blur);
  LOAD_EXTERNAL_KERNEL(gen75_gpe_sharpening_unmask);

  LOAD_EXTERNAL_KERNEL(gen8_gpe_sharpening_h_blur);
  LOAD_EXTERNAL_KERNEL(gen8_gpe_sharpening_v_blur);
  LOAD_EXTERNAL_KERNEL(gen8_gpe_sharpening_unmask);
  LOAD_EXTERNAL_KERNEL(pp_yuv420p8_scaling_gen8);

  LOAD_EXTERNAL_KERNEL(pp_10bit_scaling_gen9);
  LOAD_EXTERNAL_KERNEL(pp_yuv420p8_scaling_gen9);
  LOAD_EXTERNAL_KERNEL(pp_10bit_8bit_scaling_gen9);

err:
  unload_externel_kernels();
  return 0;
}

void unload_externel_kernels(void) {
  if (dso_handle == NULL) {
    return;
  }

#define UNLOAD_EXTERNAL_KERNEL(name) \
  do { \
    name = NULL; \
    name##_size = 0; \
  } while(0)

  UNLOAD_EXTERNAL_KERNEL(media_vp9_kernels);
  UNLOAD_EXTERNAL_KERNEL(gen9_hevc_encoder_kernels);
  UNLOAD_EXTERNAL_KERNEL(skl_avc_encoder_kernels);
  UNLOAD_EXTERNAL_KERNEL(skl_avc_fei_encoder_kernels);
  UNLOAD_EXTERNAL_KERNEL(kbl_avc_encoder_kernels);
  UNLOAD_EXTERNAL_KERNEL(bdw_avc_encoder_kernels);

  UNLOAD_EXTERNAL_KERNEL(gen8_brc_init_bin_vp8);
  UNLOAD_EXTERNAL_KERNEL(gen8_brc_reset_bin_vp8);
  UNLOAD_EXTERNAL_KERNEL(gen8_scaling_bin_vp8);
  UNLOAD_EXTERNAL_KERNEL(gen8_me_bin_vp8);
  UNLOAD_EXTERNAL_KERNEL(gen8_mbenc_i_frame_dist_bin_vp8);
  UNLOAD_EXTERNAL_KERNEL(gen8_mbenc_i_frame_luma_bin_vp8);
  UNLOAD_EXTERNAL_KERNEL(gen8_mbenc_i_frame_chroma_bin_vp8);
  UNLOAD_EXTERNAL_KERNEL(gen8_mbenc_p_frame_bin_vp8);
  UNLOAD_EXTERNAL_KERNEL(gen8_mpu_bin_vp8);
  UNLOAD_EXTERNAL_KERNEL(gen8_tpu_bin_vp8);
  UNLOAD_EXTERNAL_KERNEL(gen8_brc_update_bin_vp8);

  UNLOAD_EXTERNAL_KERNEL(gen9_brc_init_bin_vp8);
  UNLOAD_EXTERNAL_KERNEL(gen9_brc_reset_bin_vp8);
  UNLOAD_EXTERNAL_KERNEL(gen9_scaling_bin_vp8);
  UNLOAD_EXTERNAL_KERNEL(gen9_me_bin_vp8);
  UNLOAD_EXTERNAL_KERNEL(gen9_mbenc_i_frame_dist_bin_vp8);
  UNLOAD_EXTERNAL_KERNEL(gen9_mbenc_i_frame_luma_bin_vp8);
  UNLOAD_EXTERNAL_KERNEL(gen9_mbenc_i_frame_chroma_bin_vp8);
  UNLOAD_EXTERNAL_KERNEL(gen9_mbenc_p_frame_bin_vp8);
  UNLOAD_EXTERNAL_KERNEL(gen9_mpu_bin_vp8);
  UNLOAD_EXTERNAL_KERNEL(gen9_tpu_bin_vp8);
  UNLOAD_EXTERNAL_KERNEL(gen9_brc_update_bin_vp8);

  UNLOAD_EXTERNAL_KERNEL(gen75_gpe_sharpening_h_blur);
  UNLOAD_EXTERNAL_KERNEL(gen75_gpe_sharpening_v_blur);
  UNLOAD_EXTERNAL_KERNEL(gen75_gpe_sharpening_unmask);

  UNLOAD_EXTERNAL_KERNEL(gen8_gpe_sharpening_h_blur);
  UNLOAD_EXTERNAL_KERNEL(gen8_gpe_sharpening_v_blur);
  UNLOAD_EXTERNAL_KERNEL(gen8_gpe_sharpening_unmask);
  UNLOAD_EXTERNAL_KERNEL(pp_yuv420p8_scaling_gen8);

  UNLOAD_EXTERNAL_KERNEL(pp_10bit_scaling_gen9);
  UNLOAD_EXTERNAL_KERNEL(pp_yuv420p8_scaling_gen9);
  UNLOAD_EXTERNAL_KERNEL(pp_10bit_8bit_scaling_gen9);

  dlclose(dso_handle);
  dso_handle = NULL;
}

int has_external_kernels(void) {
  return dso_handle != NULL;
}

