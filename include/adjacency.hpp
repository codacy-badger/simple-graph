#ifndef _SGRAPH_ADJACENCY_HPP_
#define _SGRAPH_ADJACENCY_HPP_

#include <vector>
#include "ve_descriptors.hpp"

/** Enum to define edges direction */
enum dir {bidiretional, directed};

/** Adjacency class (abstract)
 * 
 * defines methods and variables witch will be implemented
 * by adjacency_list and adjacency_matrix
 */
class adjacency_base {
public:
    unsigned int num_vertices;
    unsigned int num_edges;
    virtual ~adjacency_base();
    virtual void add_edge(Vertex&, Vertex&);
};


/** Adjacency list class
 * 
 * Represents a graph through a list of lists, 
 * is a specification of adjacency
 */
class AdjacencyList : public adjacency_base, public std::vector< std::vector<Vertex> > {
public:
    /** Adjacency list constructor
     * 
     * @param: Number of vertices
     * @param: Direction of edges
     * gets the sets of vertices and edges
     */
    explicit AdjacencyList (unsigned int _N, dir __direction = directed) : direction_(__direction), std::vector<std::vector<Vertex> >(_N) {};

    /** Returns true if the graph is directed */
    bool is_directed() {
        if (direction_ == directed)
            return true;
        return false;
    };

private:
    dir direction_;
};


/** Adjacency matrix class
 * 
 * Represents the adjacencies of graphs through boolean matrix
 */
class AdjacencyMatrix : public adjacency_base, public std::vector< std::vector<bool> > {
public:
    explicit AdjacencyMatrix (unsigned int _N, dir __directed = directed) : direction_(__directed),
     std::vector< std::vector<bool> >(_N, std::vector<bool>(_N, 0)) {};

private:
    dir direction_;
};

#endif