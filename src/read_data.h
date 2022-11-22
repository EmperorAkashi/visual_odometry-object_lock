#ifndef READ_DATA_H_
#define READ_DATA_H_

#include <vector>
#include <unordered_map>
#include "types.h"

class ReadData{
    public:

    // Read data from text or binary file. 
    ReadData(std::string filename);
    std::string filename;
    void ReadCamerasText(const std::string& path);
    void ReadImagesText(const std::string& path);
    void ReadPoints3DText(const std::string& path);

    // Get reference to all objects. Empty map???
    const std::unordered_map<camera_t, class Camera> & Cameras() const;
    const std::unordered_map<image_t, class Image> & Images() const;
    const std::unordered_map<point3D_t, class Point3D> & Points3D() const;
    
    //map to store images/camera info
    private:
    std::unordered_map<camera_t, class Camera> cameras_; //hashmap vs EigenMap?
    std::unordered_map<image_t, class Image> images_;
    std::unordered_map<point3D_t, class Point3D> points3D_;

    // { image_id, ... } where `images_.at(image_id).registered == true`.
    std::vector<image_t> reg_image_ids_;
};

////////////////////////////////////////////////////////////////////////////////
// Accessors
////////////////////////////////////////////////////////////////////////////////
std::unordered_map<camera_t, class Camera> ReadData::Cameras() const{
   return cameras_; 
}

std::unordered_map<image_t, class Image> ReadData::Images() const{
   return images_; 
}

std::unordered_map<point3D_t, class Point_3D> ReadData::Point_3D() const{
   return points3D_; 
}

#endif // READ_DATA_H_ 
