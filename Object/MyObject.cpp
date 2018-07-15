/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   MyObject.cpp
 * Author: Thong_Laptop
 * 
 * Created on July 13, 2018, 6:03 PM
 */

#include <ostream>

#include "MyObject.h"

MyObject::MyObject() {
    buffer.clear();
}

MyObject::MyObject(const MyObject& orig) {
    this->name = orig.name;
    this->type = orig.type;
    this->buffer.clear();
    this->buffer.insert(this->buffer.begin(), orig.buffer.begin(), orig.buffer.end());
}

MyObject::~MyObject() {
    buffer.clear();
}

void MyObject::set(string name, string type, char* p_data, int size) {
    this->name = name;
    this->type = type;
    buffer.clear();
    buffer.insert(buffer.end(),p_data, p_data+size);
}

string MyObject::convertToData() {
    string temp;
    stringstream ss;
    ss << "{name:\"";
    ss << name;
    ss << "\";type:\"";
    ss << type;
    ss << "\";data_length:\"";
    if(type.compare("string") || type.compare("string[]")) {
        ss << std::to_string(buffer.size());
        ss << "\";data:";
        string t_str(buffer.data(),buffer.size());
        ss << t_str;
        ss << "}";
    } else {
        string t_base_64 = base64_encode((const unsigned char*)buffer.data(), buffer.size());
        ss << std::to_string(t_base_64.length());
        ss << "\";data:";
        ss << t_base_64;
        ss << "}";
    }
    
    return ss.str();
}

bool MyObject::convertFromData(string& data) {
    std::stringstream ss;
    
    int index = 0;
    
}

bool MyObject::convertFromBinary(string& input) {
    std::stringstream ss;
        
    int index = 0;
    if(!checkData(input, index, "{name:\"")) {
        return false;
    }
    int temp_index = index;
    if(!findData(input,index,'\"')) {
       return false; 
    }
    ss.clear();
    ss.write((input.data()+temp_index), index - temp_index);
    name = ss.str();
    index++;
    //cout << "Name : " << name << endl;

    if(!checkData(input, index, ";type:\"")) {
        return false;
    }
    temp_index = index;
    if(!findData(input,index,'\"')) {
       return false; 
    }

    ss.str("");
    ss.write((input.data()+temp_index), index - temp_index);
    type = ss.str();
    index++;
    //cout << "Type : " << type << endl;

    if(!checkData(input, index, ";data_length:\"")) {
        return false;
    }
    temp_index = index;
    if(!findData(input,index,'\"')) {
       return false; 
    }

    ss.str("");
    ss.write((input.data()+temp_index), index - temp_index);
    int length = atoi(ss.str().c_str());
    index++;
    //cout << "Length : " << length << endl;

    if(!checkData(input, index, ";data:")) {
        return false;
    }

    buffer.clear();
    if(type.compare("string") || type.compare("string[]")) {
        buffer.insert(buffer.end(), input.begin()+ index, input.begin()+ index + length);
    } else {
        string temp(input.begin()+ index, input.begin()+ index + length);
        base64_decode(temp,buffer);
    }
    if(*(input.data() + index + length) != '}') {
        return false;
    }
    return true;
}

bool MyObject::checkData(string input, int& index, string comp) {
    bool flag = true;
    int length = comp.length();

    if(index + length >= input.size()) {
        return false;
    }
    string::iterator pointer_1 = input.begin() + index;
    string::iterator pointer_2 = comp.begin();
    for(pointer_2 = comp.begin(); pointer_2 < comp.end(); pointer_2++) {
        if(pointer_1[0] != pointer_2[0]) {
            return false;
        } else {
            pointer_1++;
        }
    }
    index += length;
    return true;
}
/*
bool MyObject::checkData(vector<char>& input, int& index, string comp) {
    bool flag = true;
    int length = comp.length();

    if(index + length >= input.size()) {
        return false;
    }
    vector<char>::iterator pointer_1 = input.begin() + index;
    string::iterator pointer_2 = comp.begin();
    for(pointer_2 = comp.begin(); pointer_2 < comp.end(); pointer_2++) {
        if(pointer_1[0] != pointer_2[0]) {
            return false;
        } else {
            pointer_1++;
        }
    }
    index += length;
    return true;
}
*/
bool MyObject::findData(string input, int& index, char data) {
    for(string::iterator pointer = input.begin() + index; pointer < input.end(); pointer++) {
        if(pointer[0] == data) {
            index = pointer - input.begin();
            return true;
        }
    }
    return false;
}
/*
bool MyObject::findData(vector<char>& input, int& index, char data) {
    for(vector<char>::iterator pointer = input.begin() + index; pointer < input.end(); pointer++) {
        if(pointer[0] == data) {
            index = pointer - input.begin();
            return true;
        }
    }
    return false;
}
 * */