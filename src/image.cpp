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

//
void Image::SetUp(const class Camera& camera) {
    CHECK_EQ(camera_id_, camera.CameraId());
}

void Image::SetPoints2D(const std::vector<class Point2D>& points) {
  CHECK(points2D_.empty());
  points2D_.resize(points.size());
  //resize the vector w/ 3d pts
  num_correspondences_have_point3D_.resize(points.size(), 0);
  for (uint32_t point2D_idx = 0; point2D_idx < points.size(); ++point2D_idx) {
    points2D_[point2D_idx].SetXY(points[point2D_idx]);//attribute of point2d
  }
}

//image's attr: vec of 2d points; each 2d point have 3d point id as attr
void Image::SetPoint3DForPoint2D(const uint32_t point2D_idx,
                                 const uint32_t point3D_id) {
  CHECK_NE(point3D_id, kInvalidPoint3DId);
  class Point2D& point2D = points2D_.at(point2D_idx);
  if (!point2D.HasPoint3D()) {
    num_points3D_ += 1;
  }
  point2D.SetPoint3DId(point3D_id);
}

Eigen::Matrix3x4d Image::ProjectionMatrix() const {
  return ComposeProjectionMatrix(qvec_, tvec_);
}


void Image::IncrementCorrespondenceHasPoint3D(const _int32 point2D_idx) {
  const class Point2D& point2D = points2D_.at(point2D_idx);

  num_correspondences_have_point3D_[point2D_idx] += 1;
}

void Image::DecrementCorrespondenceHasPoint3D(const _int32 point2D_idx) {
  const class Point2D& point2D = points2D_.at(point2D_idx);

  num_correspondences_have_point3D_[point2D_idx] -= 1;
}



void Image::NormalizeQvec() { qvec_ = NormalizeQuaternion(qvec_); }