#ifndef _vertex_
#define _vertex_

#include <iostream>
using std::ostream;
#include <string>
#include <vector>
#include "Valuable.hpp"

// Class for vertex representation, contains id, name, degree values
class Vertex : public Valuable<float> {

public:
    int id;
    std::string name;
    int in_degree, out_degree; // vertex degree
    std::vector<Vertex> v_adjacents;

    Vertex (int __id): id(__id), name(std::to_string(__id)), out_degree(0), in_degree(0), v_adjacents(std::vector<Vertex>()), Valuable() {};

    Vertex (std::string __name): id(0), name(__name), out_degree(0), in_degree(0), v_adjacents(std::vector<Vertex>()), Valuable() {};

    ~Vertex () {};

    int degree() {
        return (in_degree + out_degree);
    }

    // to print on output stream using <<
    friend ostream& operator<< (ostream &_os, const Vertex &_vert) {
        _os << _vert.name;
        return _os;
    };

};


// Class to represent Edges, contains the vertices and values info
class Edge : public std::pair<Vertex, Vertex>, public Valuable<float> {
public:
    using Valuable::valued;
    using Valuable::set_value;
    typedef Vertex V;

    bool directed;
    
    // constructor, extends from std::pair and Valuable
    // gets two Vertex objects
    Edge (V __v1, V __v2) : directed(false), std::pair<V, V>(__v1, __v2), Valuable() {};

    ~Edge () {};

    friend ostream& operator<< (ostream &__os, const Edge &__edge) {
        __os << "(" << __edge.first.name << ", " << __edge.second.name << ")";
        return __os;
    };
};

#endif