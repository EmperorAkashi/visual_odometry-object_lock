// manipulate all camera models and their index of parameters,
// i.e. focal (x, y) and principal
#include "base/camera_models.h"

#include <unordered_map>

std::unordered_map<std::string, int> InitialzeCameraModelNameToId() {
  std::unordered_map<std::string, int> camera_model_name_to_id;

  