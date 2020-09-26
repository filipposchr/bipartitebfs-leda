#include <iostream>
#include "LEDA/graph/graph.h"
#include "LEDA/graph/node_list.h"
#include "LEDA/core/queue.h"
#include "LEDA/core/list.h"
#include "LEDA/graph/graph_misc.h"
using namespace leda;
using namespace std;

namespace bfs 
{
    list<node> my_BFS(const graph &G, node s, node_array<int> &dist, node_array<edge> &pred);
    bool my_bipar_checker(const graph &G, list<node> &V1, list<node> &V2);
}
