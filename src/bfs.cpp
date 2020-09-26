#include "../incl/bfs.h"
#include "../incl/tests.h"

#include <iostream>
#include "LEDA/graph/graph.h"
#include "LEDA/graph/node_list.h"
#include "LEDA/core/queue.h"
#include "LEDA/core/list.h"
#include "LEDA/graph/graph_misc.h"

#define BLUE 1
#define GREEN 2

using namespace leda;
using namespace std;
bool bipartite = true;
extern list<node> V1, V2;
list<edge> Cycle1, Cycle2;

namespace bfs
{
    
   list<node> my_BFS(const graph &G, node s, node_array<int> &dist, node_array<edge> &pred)
   {
        bipartite = true;
        list<node> n_list;
        queue<node> Q;
        node_array<int> color(G);

        node w;
        edge e;

        //initialise color array and predecessors to null value 
        forall_nodes(w, G)
        {
            color[w] = nil;
            pred[w] = nil;
        }
        dist[s] = 0; //level of first node is 0
        color[s] = BLUE; //color of first node colored as BLUE

        Q.append(s);
        n_list.append(s);
        V1.append(s);

        while (!Q.empty())
        {
            node v = Q.pop();

            forall_adj_edges(e, v)
            {
                node w = G.target(e);
               
                if (dist[w] < 0)
                {
                    dist[w] = dist[v] + 1; //increment level

                    if (pred[w] == nil)
                        pred[w] = e;

                    n_list.append(w);
                    Q.append(w);
                }
                else if (color[w] == color[v]) //two nodes from neighboring levels found to have the same colors
                //so graph cannot be biparted
                {
                    if (bipartite == false)
                        break;

                    bipartite = false;
                        
                    Cycle1.append(e); 
                    //The paths up to their common ancestor of the two nodes (w and v) is the cycle
                    //need to be printed
                    while (pred[w] != pred[v]) {
                        Cycle1.append(pred[v]); //add parents of node v to the list
                        Cycle2.append(pred[w]); //add parents of node w to the list				
                            
                        v = G.source(pred[v]); 
                        w = G.source(pred[w]);
                    }
                }
                
                //levels with even numbering are colored blue
                if (((dist[w] % 2) == 0) && (color[w] == nil))
                {
                    color[w] = BLUE;
                    V1.append(w);
                }
                //levels with odd numbering are colored green
                else if (((dist[w] % 2) != 0) && (color[w] == nil))
                {
                    color[w] = GREEN;
                    V2.append(w);
                }
            }
        }
        
        #ifdef COLORS
        node t; int c=1;
        forall_nodes(t, G)
        {
            cout << "Node [" << c++ << "], ";
            cout << "color: " << color[t] << ", ";
        }
        #endif

       
        return n_list;
    }

    bool my_bipar_checker(const graph &G, list<node> &V1, list<node> &V2)
    {
        node_array<int> dist(G, -1); //initialize all distances to -1
        node_array<edge> pred(G);
        list<node> myList = my_BFS(G, G.first_node(), dist, pred);

        #ifdef LEVELS
        node w;
        forall(w, myList) {
            G.print_node(w);
            cout << " level: " << dist[w] << "\n";	
        }
        #endif

        
        //COMMENT OUT DURING THE TESTS
        cout << endl << "Cycle:" << endl;
        for (edge const& i : Cycle1) {
            G.print_edge(i); 
            cout << "---->";
        }
        for (edge const& i : Cycle2) {
            G.print_edge(i);
            cout << "---->";
        }

        //empty the lists
        Cycle1.clear();
        Cycle2.clear();
        
        //If gaph is bipartied then V1 nodes and V2 nodes need to be printed
        //and return true
        if (bipartite == true) {

            #ifdef V_BIPARTITE
            cout << endl;
            node v1;
            cout << "V1: ";
            
            forall(v1, V1)
                G.print_node(v1);
            
            cout << endl << "V2: ";
            node v2;
            
            forall(v2, V2)
                G.print_node(v2);
            
            cout << endl;
            #endif
            return true;
        }
        else {
            return false;
        }
    }
}
