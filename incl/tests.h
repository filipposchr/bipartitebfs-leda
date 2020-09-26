#include "bfs.h"
#include <iostream>
#include "LEDA/graph/graph.h"
#include "LEDA/graph/node_list.h"
#include "LEDA/core/queue.h"
#include "LEDA/core/list.h"
#include "LEDA/graph/graph_misc.h"

using namespace leda;
using namespace std;

namespace test 
{
    // Tests
    void test(graph&);
    void testGraph1(int);
    void testGraph2(int);
    void testGraph3(int);
    void benchmark(graph&);
}
