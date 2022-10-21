// manipulate all camera models and their index of parameters,
// i.e. focal (x, y) and principal
#include "camera_models.h"

#include <unordered_map>

std::unordered_map<std::string, int> InitialzeCameraModelNameToId() {
  std::unordered_map<std::string, int> camera_model_name_to_id;

// Initialize params_info, focal_length_idxs, principal_point_idxs,
// extra_params_idxs
//Macro of camera model by initialized with standard template CameraModel
#define CAMERA_MODEL_CASE(CameraModel)                          \
  const int CameraModel::model_id = InitializeModelId();        \
  const std::string CameraModel::model_name =                   \
      CameraModel::InitializeModelName();                       \
  const size_t CameraModel::num_params = InitializeNumParams(); \
  const std::string CameraModel::params_info =                  \
      CameraModel::InitializeParamsInfo();                      \
  const std::vector<size_t> CameraModel::focal_length_idxs =    \
      CameraModel::InitializeFocalLengthIdxs();                 \
  const std::vector<size_t> CameraModel::principal_point_idxs = \
      CameraModel::InitializePrincipalPointIdxs();              \
  const std::vector<size_t> CameraModel::extra_params_idxs =    \
      CameraModel::InitializeExtraParamsIdxs();

CAMERA_MODEL_CASES

#undef CAMERA_MODEL_CASE

std::unordered_map<std::string, int> InitialzeCameraModelNameToId() {
  std::unordered_map<std::string, int> camera_model_name_to_id;
//use macro to set cameramodel id & name??
#define CAMERA_MODEL_CASE(CameraModel)                     \
  camera_model_name_to_id.emplace(CameraModel::model_name, \
                                  CameraModel::model_id);

  CAMERA_MODEL_CASES

#undef CAMERA_MODEL_CASE

  return camera_model_name_to_id;
}

//use macro to generate model's id and name then append it to map
std::unordered_map<int, std::string> InitialzeCameraModelIdToName() {
  std::unordered_map<int, std::string> camera_model_id_to_name;

#define CAMERA_MODEL_CASE(CameraModel)                   \
  camera_model_id_to_name.emplace(CameraModel::model_id, \
                                  CameraModel::model_name);

  CAMERA_MODEL_CASES

#undef CAMERA_MODEL_CASE

  return camera_model_id_to_name;
}

std::unordered_map<int, std::string> InitialzeCameraModelIdToName() {
  std::unordered_map<int, std::string> camera_model_id_to_name;

#define CAMERA_MODEL_CASE(CameraModel)                   \
  camera_model_id_to_name.emplace(CameraModel::model_id, \
                                  CameraModel::model_name);

  CAMERA_MODEL_CASES

#undef CAMERA_MODEL_CASE

  return camera_model_id_to_name;
}

//method that create generate a map of model to/ id
static const std::unordered_map<std::string, int> CAMERA_MODEL_NAME_TO_ID =
    InitialzeCameraModelNameToId();

static const std::unordered_map<int, std::string> CAMERA_MODEL_ID_TO_NAME =
    InitialzeCameraModelIdToName();

bool ExistsCameraModelWithName(const std::string& model_name) {
  return CAMERA_MODEL_NAME_TO_ID.count(model_name) > 0;
}

//create an iterator to search camera's model name
int CameraModelNameToId(const std::string& model_name) {
  const auto it = CAMERA_MODEL_NAME_TO_ID.find(model_name);
  if (it == CAMERA_MODEL_NAME_TO_ID.end()) {
    return kInvalidCameraModelId;
  } else {
    return it->second;
  }
}

std::string CameraModelIdToName(const int model_id) {
  const auto it = CAMERA_MODEL_ID_TO_NAME.find(model_id);
  if (it == CAMERA_MODEL_ID_TO_NAME.end()) {
    return "";
  } else {
    return it->second;
  }
}