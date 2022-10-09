#include <fstream>
#include <string>
#include "read_data.h"
#include "string.h"

ReadData::ReadData(std::string filename){
  public:
    string filename = filename;
}

void ReadData::ReadImagesText(const std::string& path) {
  images_.clear(); 

  std::ifstream file(path);
  CHECK(file.is_open()) << path;

  std::string line;
  std::string item;

  while (std::getline(file, line)) {
    StringTrim(&line);

    if (line.empty() || line[0] == '#') {
      continue;
    }

    std::stringstream line_stream1(line);

    // ID
    std::getline(line_stream1, item, ' ');
    const image_t image_id = std::stoul(item);

    Image image; //?
    image.SetImageId(image_id);

    image.SetRegistered(true);
    reg_image_ids_.push_back(image_id);

    // QVEC (qw, qx, qy, qz)
    std::getline(line_stream1, item, ' ');
    image.Qvec(0) = std::stold(item);

    std::getline(line_stream1, item, ' ');
    image.Qvec(1) = std::stold(item);

    std::getline(line_stream1, item, ' ');
    image.Qvec(2) = std::stold(item);

    std::getline(line_stream1, item, ' ');
    image.Qvec(3) = std::stold(item);

    image.NormalizeQvec();

    // TVEC
    std::getline(line_stream1, item, ' ');
    image.Tvec(0) = std::stold(item);

    std::getline(line_stream1, item, ' ');
    image.Tvec(1) = std::stold(item);

    std::getline(line_stream1, item, ' ');
    image.Tvec(2) = std::stold(item);

    // CAMERA_ID
    std::getline(line_stream1, item, ' ');
    image.SetCameraId(std::stoul(item));

    // NAME
    std::getline(line_stream1, item, ' ');
    image.SetName(item);

    // POINTS2D
    if (!std::getline(file, line)) {
      break;
    }

    StringTrim(&line);
    std::stringstream line_stream2(line);

    std::vector<Eigen::Vector2d> points2D;
    std::vector<point3D_t> point3D_ids;

    if (!line.empty()) {
      while (!line_stream2.eof()) {
        Eigen::Vector2d point;

        std::getline(line_stream2, item, ' ');
        point.x() = std::stold(item);

        std::getline(line_stream2, item, ' ');
        point.y() = std::stold(item);

        points2D.push_back(point);

        std::getline(line_stream2, item, ' ');
        if (item == "-1") {
          point3D_ids.push_back(kInvalidPoint3DId);
        } else {
          point3D_ids.push_back(std::stoll(item));
        }
      }
    }

    image.SetUp(Camera(image.CameraId()));
    image.SetPoints2D(points2D);

    for (point2D_t point2D_idx = 0; point2D_idx < image.NumPoints2D();
         ++point2D_idx) {
      if (point3D_ids[point2D_idx] != kInvalidPoint3DId) {
        image.SetPoint3DForPoint2D(point2D_idx, point3D_ids[point2D_idx]);
      }
    }

    images_.emplace(image.ImageId(), image);
  }
}