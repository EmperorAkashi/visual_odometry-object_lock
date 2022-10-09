#ifndef SRC_IMAGE_H_
#define SRC_IMAGE_H_

#include <string>
#include <vector>

class Image {
 public:
  Image();

  // Setup / tear down the image and necessary internal data structures before
  // and after being used in reconstruction.
  void SetUp(const Camera& camera);