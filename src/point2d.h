#ifndef SRC_POINT2D_H_
#define SRC_POINT2D_H_

#include <Eigen/Core>

#include "types.h"


// 2D point class corresponds to a feature in an image. It may or may not have a
// corresponding 3D point if it is part of a triangulated track.
class Point2D {
 public:

  Point2D();

  // The coordinate in image space in pixels.
  inline const Eigen::Vector2d& XY() const;
  inline Eigen::Vector2d& XY();
  inline double X() const;
  inline double Y() const;
  inline void SetXY(const Eigen::Vector2d& xy);

  // The identifier of the observed 3D point. If the image point does not
  // observe a 3D point, the identifier is `kInvalidPoint3Did`.
  inline int Point3DId() const;
  inline bool HasPoint3D() const;
  inline void SetPoint3DId(const uint32_t point3D_id); //fxn fot set the point3d

 private:
  // The image coordinates in pixels, starting at upper left corner with 0.
  Eigen::Vector2d xy_;

  // The identifier of the 3D point. If the 2D point is not part of a 3D point
  // track the identifier is `kInvalidPoint3DId` and `HasPoint3D() = false`.
  int point3D_id_;
};

////////////////////////////////////////////////////////////////////////////////
// Accessory 
////////////////////////////////////////////////////////////////////////////////

const Eigen::Vector2d& Point2D::XY() const { return xy_; }

Eigen::Vector2d& Point2D::XY() { return xy_; }

double Point2D::X() const { return xy_.x(); }

double Point2D::Y() const { return xy_.y(); }

void Point2D::SetXY(const Eigen::Vector2d& xy) { xy_ = xy; }

int Point2D::Point3DId() const { return point3D_id_; }

bool Point2D::HasPoint3D() const { return point3D_id_ != kInvalidPoint3DId; }

void Point2D::SetPoint3DId(const uint32_t point3D_id) {
  point3D_id_ = point3D_id;
}



#endif  // SRC_POINT2D_H_