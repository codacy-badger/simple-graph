#ifndef _adjacency_list_
#define _adjacency_list_

#include <iostream>
#include <vector>
#include "adjacency.hpp"

class AdjacencyList : public adjacency, public std::vector< std::vector<Vertex> > {
public:
    using adjacency::vertices;
    using adjacency::num_edges;
    using adjacency::num_vertices;

    typedef std::vector<Vertex>::iterator vertex_iterator; // percorre conjuntos de vertices

    // Adjacency List gets a set of vertices
    AdjacencyList (std::vector<Vertex> __vset) : std::vector< std::vector<Vertex> >(__vset.size(), std::vector<Vertex>()) {
        num_vertices = __vset.size();
        num_edges = 0;
        vertices = __vset;
    };

    ~AdjacencyList () {};

    friend std::ostream& operator<< (std::ostream &__os, const AdjacencyList &__al) {
        for (auto vi = __al.vertices.begin() ; vi != __al.vertices.end() ; ++vi) {
            __os << "[" << *vi << "] --> (";
            for (auto adjacent = vi->v_adjacents.begin() ; adjacent != vi->v_adjacents.end() ; ++adjacent) {
                __os << "  " << *adjacent;
            }
            __os << " )\n";
        }
        return __os;
    };
};

#endif