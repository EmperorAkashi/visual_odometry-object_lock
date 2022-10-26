#ifndef SRC_POINT3D_H_
#define SRC_POINT3D_H_

#include <vector>

#include <Eigen/Core>
class Point3D {
 public:

  Point3D();

  // The point coordinate in world space.
  inline const Eigen::Vector3d& XYZ() const;
  inline Eigen::Vector3d& XYZ();
  inline double XYZ(const size_t idx) const;
  inline double& XYZ(const size_t idx);
  inline double X() const;
  inline double Y() const;
  inline double Z() const;
  inline void SetXYZ(const Eigen::Vector3d& xyz);

  private:
  // The 3D position of the point.
  Eigen::Vector3d xyz_;