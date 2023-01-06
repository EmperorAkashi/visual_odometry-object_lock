#include <vector>
#include <string>
#include <random>
#include <iostream>
#include <stdexcept>
#include "read_data.h"

struct Normalized
{
    /* data */
    Eigen::Matrix6d Point3dSet;

};

Eigen::Matrix3x4d DLT(vector<Eigen::Vector3d> ControlPoints, vector<Eigen::Vector2d> ImagePoints)
{
    if(ControlPoints.size() < 6)
        throw std::invalid_argument( " DLT requires at least 6 calibration points.");
    
    vector<vector<float>> LinearSystem;
    int nPoints = ControlPoints.size();
    for(int i = 0; i < nPoints; i++)
    {
        Point3D curr_3d = ControlPoints[i];
        Point2D curr_2d = ImagePoints[i];
        vector<float> curr;
        curr.push_back(curr_3d.X());
    }
    
}

int main(){

}