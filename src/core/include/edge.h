/**
 * Copyright (C) 2016 - Marcos Cardinot
 * @author Marcos Cardinot <mcardinot@gmail.com>
 */

#ifndef EDGE_H
#define EDGE_H

#include <vector>

#include "attributes.h"

namespace evoplex {

class Agent;
class Edge;

typedef std::vector<Edge*> Edges;

class Edge
{
public:
    explicit Edge();
    explicit Edge(Agent* origin, Agent* neighbour, Attributes* attrs, bool isDirected);
    explicit Edge(Agent* origin, Agent* neighbour, bool isDirected);
    ~Edge();

    inline const Value& attr(const char* name) const { return m_attrs->value(name); }
    inline const Value& attr(const int id) const { return m_attrs->value(id); }
    inline void setAttr(const int id, const Value& value) { m_attrs->setValue(id, value); }

    inline Agent* origin() const { return m_origin; }
    inline Agent* neighbour() const { return m_neighbour; }

private:
    Agent* m_origin;
    Agent* m_neighbour;
    Attributes* m_attrs;

    // If it's an undirected edge, it'll create a new edge in the
    // opposite direction with the same attrs.
    // This new edge is added for the sake of letting the neighbour
    // aware that an edge has been attached to him, allowing him to
    // access the attrs of this connection.
    Edge* m_undirectedEdge;
};
}
#endif // EDGE_H