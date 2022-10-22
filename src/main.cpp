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
    int n = images.size();  //number of images
    
    Image Image1 = Image();

    
}