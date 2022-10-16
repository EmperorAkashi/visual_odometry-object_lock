#include "image.h"

//initialize all attribute with default values
Image::Image() 
    : image_id_(kInvalidImageId),
      name_(""),
      camera_id_(kInvalidCameraId),
      registered_(false),
      num_points3D_(0),
      num_observations_(0),
      num_correspondences_(0),
      num_visible_points3D_(0),
      qvec_(1.0, 0.0, 0.0, 0.0),
      tvec_(0.0, 0.0, 0.0),
      qvec_prior_(kNaN, kNaN, kNaN, kNaN),
      tvec_prior_(kNaN, kNaN, kNaN) {}

void Image::SetUp(const class Camera& camera) {
    CHECK_EQ(camera_id_, camera.CameraId());
}

void Image::SetPoints2D(const std::vector<Eigen::Vector2d>& points) {
  CHECK(points2D_.empty());
  points2D_.resize(points.size());
  num_correspondences_have_point3D_.resize(points.size(), 0);
  for (point2D_t point2D_idx = 0; point2D_idx < points.size(); ++point2D_idx) {
    points2D_[point2D_idx].SetXY(points[point2D_idx]);
  }
}

void Image::SetPoints2D(const std::vector<class Point2D>& points) {
  CHECK(points2D_.empty());
  points2D_ = points;
  num_correspondences_have_point3D_.resize(points.size(), 0);
}


void Image::NormalizeQvec() { qvec_ = NormalizeQuaternion(qvec_); }