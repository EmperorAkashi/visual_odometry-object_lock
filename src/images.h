#ifndef SRC_IMAGE_H_
#define SRC_IMAGE_H_

#include <string>
#include <vector>
#include <Eigen/Core>

#include "camera.h"
#include "types.h"

class Image {
    public:
    
    Image();

    // Setup / tear down the image and necessary internal data structures before
    // and after being used in reconstruction.
    void SetUp(const Camera& camera);

    image_t ImageId() const;
    void SetImageId(const image_t image_id);
    void SetName(const std::string& name);

    camera_t CameraId() const;
    void SetCameraId(const camera_t camera_id);
    // Check whether identifier of camera has been set.
    bool HasCamera() const;

    // Check if image is registered.
    bool IsRegistered() const;
    void SetRegistered(const bool registered);

    // Get the number of image points.
    inline point2D_t NumPoints2D() const;

    // Get the number of triangulations, i.e. the number of points that
    // are part of a 3D point track.
    inline point2D_t NumPoints3D() const;

     // Access quaternion vector as (qw, qx, qy, qz) specifying the rotation of the
     // pose which is defined as the transformation from world to image space.
      inline const Eigen::Vector4d& Qvec() const;
      inline Eigen::Vector4d& Qvec();
      inline double Qvec(const size_t idx) const;
      inline double& Qvec(const size_t idx);
      inline void SetQvec(const Eigen::Vector4d& qvec);

    // Access the coordinates of image points.
    // need wrap the class of point2D&3D OR use a vector
    inline const class Point2D& Point2D(const point2D_t point2D_idx) const;
    inline class Point2D& Point2D(const point2D_t point2D_idx);
    inline const std::vector<class Point2D>& Points2D() const;
    void SetPoints2D(const std::vector<Eigen::Vector2d>& points);
    void SetPoints2D(const std::vector<class Point2D>& points);

    // Access translation vector as (tx, ty, tz) specifying the translation of the
    // pose which is defined as the transformation from world to image space.
    inline const Eigen::Vector3d& Tvec() const;
    inline Eigen::Vector3d& Tvec();
    inline double Tvec(const size_t idx) const;
    inline double& Tvec(const size_t idx);
    inline void SetTvec(const Eigen::Vector3d& tvec);
    
    private:
    // Identifier of the image, if not specified `kInvalidImageId`.
    _int32 image_id_;

    // The name of the image, i.e. the relative path.
    std::string name_;

    // The identifier of the associated camera. Note that multiple images might
    // share the same camera. If not specified `kInvalidCameraId`.
    _int32 camera_id_;

    // Whether the image is successfully registered in the reconstruction.
    bool registered_;

    // The number of 3D points the image observes, i.e. the sum of its `points2D`
    // where `point3D_id != kInvalidPoint3DId`.
    _int32 num_points3D_;

    // The number of image points that have at least one correspondence to
    // another image.
    _int32 num_observations_;

    // The sum of correspondences per image point.
    _int32 num_correspondences_;

    // The number of 2D points, which have at least one corresponding 2D point in
    // another image that is part of a 3D point track, i.e. the sum of `points2D`
    // where `num_tris > 0`.
    _int32 num_visible_points3D_;

    // The pose of the image, defined as the transformation from world to image.
    Eigen::Vector4d qvec_;
    Eigen::Vector3d tvec_;

    // The pose prior of the image, e.g. extracted from EXIF tags.
    Eigen::Vector4d qvec_prior_;
    Eigen::Vector3d tvec_prior_;

    // All image points, including points that are not part of a 3D point track.
    std::vector<class Point2D> points2D_;

    // Per image point, the number of correspondences that have a 3D point.
    std::vector<point2D_t> num_correspondences_have_point3D_;

    }；