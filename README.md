<<<<<<< HEAD
# visual_odometry-object_lock
This project is aimed to lock marked object and find the homography transformation so does 3d transformation of different sensor,
The code are heavily adapted from COLMAP's src: https://github.com/colmap/colmap.git
=======
# sift-cpp

## Introduction
This is a C++ implementation of [SIFT](https://en.wikipedia.org/wiki/Scale-invariant_feature_transform), a feature detection algorithm.

## Libraries used
[stb_image](https://github.com/nothings/stb) and stb_image_write for loading and saving images. (included in this repo)

## Usage example
Find keypoints, match features in two images and save the result:
```cpp
#include <vector>
#include "image.hpp"
#include "sift.hpp"

int main()
{
    Image img("./../imgs/book_rotated.jpg");
    Image img2("./../imgs/book_in_scene.jpg");
    img = rgb_to_grayscale(img);
    img2 = rgb_to_grayscale(img2);
    std::vector<sift::Keypoint> kps1 = sift::find_keypoints_and_descriptors(img);
    std::vector<sift::Keypoint> kps2 = sift::find_keypoints_and_descriptors(img2);
    std::vector<std::pair<int, int>> matches = sift::find_keypoint_matches(kps1, kps2);
    Image book_matches = sift::draw_matches(img, img2, kps1, kps2, matches);
    book_matches.save("book_matches.jpg");
    return 0;
}
```


