#include "camera.h"

Camera::Camera()
    : camera_id_(kInvalidCameraId),
      model_id_(kInvalidCameraModelId),
      width_(0),
      height_(0),
      prior_focal_length_(false) {}

std::string Camera::ModelName() const { return CameraModelIdToName(model_id_); }

void Camera::SetModelId(const int model_id) {
  CHECK(ExistsCameraModelWithId(model_id));
  model_id_ = model_id;
  params_.resize(CameraModelNumParams(model_id_), 0);
}