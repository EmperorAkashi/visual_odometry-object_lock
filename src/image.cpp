#include "image.h"

void Image::SetUp(const class Camera& camera) {
  CHECK_EQ(camera_id_, camera.CameraId());
  point3D_visibility_pyramid_ = VisibilityPyramid(
      kNumPoint3DVisibilityPyramidLevels, camera.Width(), camera.Height());
}

void Image::TearDown() {
  point3D_visibility_pyramid_ = VisibilityPyramid(0, 0, 0);
}