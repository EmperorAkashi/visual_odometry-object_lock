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
    int n = images.size();  //number of images

    int idx1 = random();
    int idx2 = random();
    
    Image Image1 = Image();

    
}