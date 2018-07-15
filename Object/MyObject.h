/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   MyObject.h
 * Author: Thong_Laptop
 *
 * Created on July 13, 2018, 6:03 PM
 */

#ifndef MYOBJECT_H
#define MYOBJECT_H

#include <cstdlib>
#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#include <sstream>
#include "../WebSocket/base64.h"

using namespace std;

class MyObject {
public:
    MyObject();
    MyObject(const MyObject& orig);
    virtual ~MyObject();
    
    string name;
    string type;
    
    vector<char> buffer;
    
    void set(string name, string type, char* p_data, int size);
    string convertToData();
    bool convertFromData(string& data);
    bool convertFromBinary(string& input);
private:
    bool checkData(string input, int& index, string comp);
    bool findData(string input, int& index, char data);
};

#endif /* MYOBJECT_H */

