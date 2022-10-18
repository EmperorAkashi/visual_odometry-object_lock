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

