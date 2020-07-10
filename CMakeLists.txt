cmake_minimum_required(VERSION 3.0)
project(cre_app)
set(SOURCE main.cpp factory.cpp node.cpp drawer.cpp flyweight.cpp config.cpp)
add_executable(${PROJECT_NAME} ${SOURCE})