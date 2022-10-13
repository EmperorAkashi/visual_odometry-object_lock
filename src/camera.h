#ifndef SRC_CAMERA_H_
#define SRC_CAMERA_H_

#include <vector>
#include "types.h"

class Camera{
    public:
    Camera();

    // Access the unique identifier of the camera.
    inline camera_t CameraId() const;
    inline void SetCameraId(const camera_t camera_id);

    // Access the camera model.
    inline int ModelId() const;
    std::string ModelName() const;
    void SetModelId(const int model_id);
    void SetModelIdFromName(const std::string& model_name);

    // Access dimensions of the camera sensor.
    inline size_t Width() const;
    inline size_t Height() const;
    inline void SetWidth(const size_t width);
    inline void SetHeight(const size_t height);

    // Access focal length parameters.
    double MeanFocalLength() const;
    double FocalLength() const;
    double FocalLengthX() const;
    double FocalLengthY() const;
    void SetFocalLength(const double focal_length);
    void SetFocalLengthX(const double focal_length_x);
    void SetFocalLengthY(const double focal_length_y);

    // Check if camera has prior focal length.
    inline bool HasPriorFocalLength() const;
    inline void SetPriorFocalLength(const bool prior);

    // Access principal point parameters. Only works if there are two
    // principal point parameters.
    double PrincipalPointX() const;
    double PrincipalPointY() const;
    void SetPrincipalPointX(const double ppx);
    void SetPrincipalPointY(const double ppy);

    private:
    // The unique identifier of the camera. If the identifier is not specified
    // it is set to `kInvalidCameraId`.
    camera_t camera_id_;

    // The identifier of the camera model. If the camera model is not specified
    // the identifier is `kInvalidCameraModelId`.
    int model_id_;

    // The dimensions of the image, 0 if not initialized.
    size_t width_;
    size_t height_;

    // The focal length, principal point, and extra parameters. If the camera
    // model is not specified, this vector is empty.
    std::vector<double> params_;

};
//////////////
//Accessors
/////////////
camera_t Camera::CameraId() const { return camera_id_; }

void Camera::SetCameraId(const camera_t camera_id) { camera_id_ = camera_id; }

int Camera::ModelId() const { return model_id_; }

size_t Camera::Width() const { return width_; }

size_t Camera::Height() const { return height_; }

void Camera::SetWidth(const size_t width) { width_ = width; }

void Camera::SetHeight(const size_t height) { height_ = height; }

bool Camera::HasPriorFocalLength() const { return prior_focal_length_; }

#endif  // SRC_CAMERA_H_
