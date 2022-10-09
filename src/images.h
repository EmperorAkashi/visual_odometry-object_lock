#ifndef SRC_IMAGE_H_
#define SRC_IMAGE_H_

#include <string>
#include <vector>
#include "camera.h"

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