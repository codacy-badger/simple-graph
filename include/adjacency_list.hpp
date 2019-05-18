#ifndef _adjacency_list_
#define _adjacency_list_

#include <iostream>
#include <vector>
#include <list>
#include "ve_descriptors.hpp"

// Adjacency list class is built from sets of vertices and edges

class adjacency_list : public std::vector< std::list<Vertex> > {
public:
    using std::vector< std::list<Vertex> >::iterator;
    using std::vector< std::list<Vertex> >::push_back;

    typedef std::vector<Edge> vec_edge; // conjunto de arestas
    typedef std::vector<Vertex> vec_vertex; // conjunto de vertices
    typedef std::vector<Vertex>::iterator vertex_iterator; // percorre conjuntos de vertices
    typedef iterator adjacency_iterator; // percorre o vector de vectors de vertices
    

    // class constructor gets the sets of vertices and edges
    // should build the adjacency structure 
    adjacency_list (vec_vertex& V, vec_edge& E) : std::vector< std::list<Vertex> >(V.size(), std::list<Vertex>()) {
        /*
        vertex_iterator vi = V.begin();
        for (; vi != V.end(); ++vi) {
            for (Edge e : E) { // para cada aresta
                if (*vi == e.first) // inserir adjacecia (e.second)
            }
        }
        */
    };

    ~adjacency_list () {};

    void add_vertex(int __id) {
    };

};

#endif