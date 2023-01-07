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
        float x, y, z = curr_3d.X(), curr_3d.Y(), curr_3d.Z();
        float u, v = curr_2d.X(), curr_2d.Y();
        vector<float> curr_1{x, y, z, 1, 0, 0, 0, 0, -u*x, -u*y, -u*z, -u};
        vector<float> curr_2{0, 0, 0, 0, x, y, z, 1, -v*x, -v*y, -v*z, -v}; //does the negative sign matters?
        LinearSystem.push_back(curr_1);
        LinearSystem.push_back(curr_2);
    }

    int n_rows, n_cols = LinearSystem.size(), LinearSystem[0].size();
    DLTMatrix M = Eigen::Map<DLTMatrix>(LinearSystem.data(), n_rows, n_cols);
    
}

int main(){

}