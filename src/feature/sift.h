#ifndef SRC_FEATURE_SIFT_H_
#define SRC_FEATURE_SIFT_H_

//constants/config params for SIFT
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
  int first_octave = -1; //scale down the image for DoG

  // Number of octaves.
  int num_octaves = 4;

  // Number of levels per octave.
  int octave_resolution = 3;
};

struct SiftMatchingOptions {
  // Number of threads for feature matching and geometric verification.
  int num_threads = -1;

  // Whether to use the GPU for feature matching.
  bool use_gpu = true;

  // Index of the GPU used for feature matching. For multi-GPU matching,
  // you should separate multiple GPU indices by comma, e.g., "0,1,2,3".
  std::string gpu_index = "-1";

  // Maximum distance ratio between first and second best match.
  double max_ratio = 0.8;

  // Maximum distance to best match.
  double max_distance = 0.7;

  // Whether to enable cross checking in matching.
  bool cross_check = true;

  // Maximum number of matches.
  int max_num_matches = 32768;

  // Maximum epipolar error in pixels for geometric verification.
  double max_error = 4.0;

  // Confidence threshold for geometric verification.
  double confidence = 0.999;

  // Minimum/maximum number of RANSAC iterations. Note that this option
  // overrules the min_inlier_ratio option.
  int min_num_trials = 100;
  int max_num_trials = 10000;

  // A priori assumed minimum inlier ratio, which determines the maximum
  // number of iterations.
  double min_inlier_ratio = 0.25;

  // Minimum number of inliers for an image pair to be considered as
  // geometrically verified.
  int min_num_inliers = 15;
  }；

  