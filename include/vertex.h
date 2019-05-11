#ifndef _vertex_
#define _vertex_

#include <string>

class Vertex {
public:
    int id;
    std::string name;
    int degree; // vertex degree
    bool valuated; // define if vertex has value
    float value;

    Vertex (int __id): id(__id), name(std::to_string(__id)), valuated(false), value((float)0) {};

    Vertex (std::string __name): id(0), name(__name), valuated(false), value((float)0) {};

    ~Vertex () {};

};

#endif