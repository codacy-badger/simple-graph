#ifndef _adjacency_
#define _adjacency_

#include <vector>
#include "ve_descriptors.hpp"

// adjacency class defines methods and variables witch will be
// implemented by adjacency_list and adjacency_matrix
class adjacency_base {
public:
    // redefine types
    typedef Vertex V;
    typedef Edge E;

    unsigned int num_vertices;
    unsigned int num_edges;

    virtual ~adjacency_base();

    // add edges with differents paramethers
    virtual void add_edge(E& __edge);
    virtual void add_edge(V& __v1, V& __v2);
    virtual void add_edge(int _id1, int _id2);

    // add vertices with differents paramethers
    virtual void add_vertex(V& vertex);
    virtual void add_vertex(int __id);
    virtual void add_vertex(std::string _vname);
};

#endif