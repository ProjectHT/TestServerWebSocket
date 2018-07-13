/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Thong_Laptop
 *
 * Created on July 13, 2018, 11:11 AM
 */

#include <cstdlib>
#include "WebSocket/server_ws.hpp"
#include "WebSocket/base64.h"
#include <fstream>

using namespace std;
using WsServer = SimpleWeb::SocketServer<SimpleWeb::WS>;

bool readFile(string link, char*(&buffer), int& size) {
    ifstream file (link.c_str(), ios::in|ios::binary|ios::ate);
    if (file.is_open()) {
        size = file.tellg();
        if(buffer != NULL) {
            delete[] buffer;
        }
        buffer = new char[size];
        file.seekg (0, ios::beg);
        file.read (buffer, size);
        file.close();
    } else {
        return false;
    }
}

/*
 * 
 */
int main(int argc, char** argv) {
    WsServer server;
    server.config.port = 8080;
    
    auto &echo = server.endpoint["^/test/?$"];
    echo.on_message = [](shared_ptr<WsServer::Connection> connection, shared_ptr<WsServer::Message> message) {
        //message->binary();
        //auto message_str = message->string();
        cout << "Server : received " << std::to_string(message->size()) << " bytes" << endl;
        char* buffer = new char[message->size()];
        message->get(buffer, message->size()+1);
        string str(buffer,message->size());
        cout << "Server : received data to string - " << str << endl;
        
        auto send_stream = make_shared<WsServer::SendStream>();
        char* buffer_file = NULL;
        int size;
        if(readFile("/root/Workspace/test.jpg",buffer_file,size)) {
            cout << "Size image : " << size << endl;
            string tempbuf = base64_encode((const unsigned char*)buffer_file, size);
            cout << tempbuf << endl;
            *send_stream << tempbuf;
            //send_stream->write(buffer_file,size);
        } else {
            *send_stream << "Error read file" << endl;
        }
        //send_stream->write(buffer, message->size());

        connection->send(send_stream, [](const SimpleWeb::error_code &ec) {
            if(ec) {
                cout << "Server: Error sending message. " <<
                  // See http://www.boost.org/doc/libs/1_55_0/doc/html/boost_asio/reference.html, Error Codes for error code meanings
                  "Error: " << ec << ", error message: " << ec.message() << endl;
            }
        });
    };
    
    echo.on_open = [](shared_ptr<WsServer::Connection> connection) {
        cout << "Server: Opened connection " << connection.get() << endl;
    };
    
    echo.on_close = [](shared_ptr<WsServer::Connection> connection, int status, const string & /*reason*/) {
        cout << "Server: Closed connection " << connection.get() << " with status code " << status << endl;
    };
    
    echo.on_error = [](shared_ptr<WsServer::Connection> connection, const SimpleWeb::error_code &ec) {
        cout << "Server: Error in connection " << connection.get() << ". " << "Error: " << ec << ", error message: " << ec.message() << endl;
    };
    
    thread server_thread([&server]() {
        // Start WS-server
        server.start();
    });
    
    server_thread.join();
    return 0;
}

