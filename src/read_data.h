#ifndef READ_DATA_H_
#define READ_DATA_H_

#include <vector>

class ReadData{
    public:

    read_data(std::string filename);

    void ReadCamerasText(const std::string& path);
    void ReadImagesText(const std::string& path);
    void ReadPoints3DText(const std::string& path);

    private:
    EIGEN_STL_UMAP(image_t, class Image) images_;
    // { image_id, ... } where `images_.at(image_id).registered == true`.
    std::vector<image_t> reg_image_ids_;
};




#endif /* READ_DATA_H_ */
