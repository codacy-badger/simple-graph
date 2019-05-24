#ifndef _vertex_
#define _vertex_

#include <iostream>
using std::ostream;
#include <string>
#include <vector>
#include "Valuable.hpp"


// Class for vertex representation, contains id, name, degree values
class Vertex : Valuable<double> {
public:
    using Valuable::valued;
    using Valuable::is_valued;

    int id; // number id of the vertex
    std::string name; // vertex name
    int in_degree, out_degree; // vertex degree

    // Vertex Constructor gets an id for the vertex
    explicit Vertex (int __id): id(__id), name(std::to_string(__id)),
     out_degree(0), in_degree(0), Valuable() {};

    ~Vertex () {};

    int degree() {
        return (in_degree + out_degree);
    }

    // to print on output stream using <<
    friend ostream& operator<< (ostream &_os, const Vertex &_vert) {
        _os << _vert.name;
        return _os;
    };

    // Comparison Operators:
    // compare two vertices
    friend bool operator==(const Vertex& v, const Vertex& u) {
        return (v.id == u.id);
    };

    // compare int value with vertex, use id (int)
    friend bool operator==(const Vertex& v, const int u) {
        return (v.id == u);
    };
};



// Class to represent Edges, contains the vertices and values info
class Edge : public std::pair<Vertex&, Vertex&>, public Valuable<float> {
public:
    using Valuable::valued;
    using Valuable::is_valued;
    typedef Vertex V;
    
    // constructor, extends from std::pair and Valuable
    // gets reference to 2 Vertex objects
    Edge (V &__v1, V &__v2) : std::pair<V&, V&>(__v1, __v2), Valuable() {};

    ~Edge () {};

    friend ostream& operator<< (ostream &__os, const Edge &__edge) {
        __os << "(" << __edge.first.name << ", " << __edge.second.name << ")";
        return __os;
    };
};

#endif