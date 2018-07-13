/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   InterfaceCamera.h
 * Author: Thong_Laptop
 *
 * Created on July 13, 2018, 1:43 PM
 */

#ifndef INTERFACECAMERA_H
#define INTERFACECAMERA_H

#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <unistd.h>
#include <string>

#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

class InterfaceCamera {
public:
    InterfaceCamera();
    InterfaceCamera(const InterfaceCamera& orig);
    virtual ~InterfaceCamera();
    
    string link_camera;
    string name_camera;
    string dir;
    
    Mat m_buffer;
    
    bool flag_run;
    bool flag_data_ready;
    
    //void init(string name, string link, string dir);
    //Mat getData();
private:
    Mat t_buffer;
};

#endif /* INTERFACECAMERA_H */

