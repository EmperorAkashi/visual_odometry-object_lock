#include <vector>
#include <string>
#include <random>
#include "read_data.h"
#include "images.h"

int random()
{
    std::random_device rd; // obtain a random number from hardware
    std::mt19937 gen(rd()); // seed the generator
    std::uniform_int_distribution<> distr(25, 63); // define the range

    
    int idx =  distr(gen) ; // generate numbers
    return idx;
}



//check exe file of COLMAP, read image files by argument
int main(int argc, char** argv){
    if (argc < 4)
    {
        std::cout << "Standard Input" << std::endl;
        std::cout << " " << argv[0] << "<image> <camera> <point3d>" << endl;
    }

    std::string image_file = argv[1];
    std::string camera_file = argv[2];
    std::string point3d_file = argv[3];
    ReadData read_image = ReadData(image_file);
    ReadData read_camera = ReadData(camera_file);
    ReadData read_point3d = ReadData(point3d_file);
    int n = read_image.images_.size();  //number of images by access member data

    int idx1 = random();
    int idx2 = random();
    //image instances and corresponding data already set in image class
    //images_ is a map of images
    Image Image1 = read_image.images_[idx1]; //check image_t == image_id??
    Image Image2 = read_image.images_[idx2];

    //create camera for image1&2, read camera paras
    int camera_id1 = Image1.camera_id_;
    int camera_id2 = Image2.camera_id_;
    
}