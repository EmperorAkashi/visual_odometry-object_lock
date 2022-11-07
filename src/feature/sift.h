#ifndef SRC_FEATURE_SIFT_H_
#define SRC_FEATURE_SIFT_H_


struct SiftExtractionOptions {
  // Number of threads for feature extraction.
  int num_threads = -1;

  // Whether to use the GPU for feature extraction.
  bool use_gpu = true;

  // Index of the GPU used for feature extraction. For multi-GPU extraction,
  // you should separate multiple GPU indices by comma, e.g., "0,1,2,3".
  std::string gpu_index = "-1";

  // Maximum image size, otherwise image will be down-scaled.
  int max_image_size = 3200;

  // Maximum number of features to detect, keeping larger-scale features.
  int max_num_features = 8192;

  // First octave in the pyramid, i.e. -1 upsamples the image by one level.
  int first_octave = -1;

  // Number of octaves.
  int num_octaves = 4;

  // Number of levels per octave.
  int octave_resolution = 3;
};