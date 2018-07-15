/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   base64.h
 * Author: Thong_Laptop
 *
 * Created on July 13, 2018, 3:02 PM
 */

#ifndef BASE64_H
#define BASE64_H

#include <string>
#include <iostream>
#include <vector>

using namespace std;

string base64_encode(unsigned char const* , unsigned int len);
void base64_decode(string const& s, vector<char>& data);

#endif /* BASE64_H */

