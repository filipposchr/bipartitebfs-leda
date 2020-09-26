#include "../incl/tests.h"
using namespace leda;
using namespace std;
extern list<node> V1, V2;
namespace test 
{
    void testGraph1(int n)
    {    
        graph G;
        node v[n];
        unsigned int i, counter, tetr;

        for (i = 1; i <= n; i++)
            v[i] = G.new_node();

        i = 1;
        counter = 1;
        tetr = n / 4; //number of squares that needs to be created

        //Creating the squares with 4 edges
        for (i = 1; i <= tetr; i++)
        {
            G.new_edge(v[counter], v[counter + 1]);
            G.new_edge(v[counter + 1], v[counter + 2]);
            G.new_edge(v[counter], v[counter + 3]);
            G.new_edge(v[counter + 3], v[counter + 2]);
            counter = counter + 4;
        }
        //Connects all the squares with 4 extra edges
        counter = 1;
        for (i = 1; i < tetr; i++)
        {
            G.new_edge(v[counter], v[counter + 4]);
            G.new_edge(v[counter + 1], v[counter + 5]);
            G.new_edge(v[counter + 2], v[counter + 6]);
            G.new_edge(v[counter + 3], v[counter + 7]);
            counter = counter + 4;
        }
            test(G);   
    }

    void testGraph2(int n)
    {  
        //Creating a ring graph G
        graph G;
        node v[n + 1];
        int i;

        for (i = 0; i < n; i++)
        {
            v[i] = G.new_node(); //create n nodes
        }
        for (i = 0; i < n - 1; i++)
        {
            G.new_edge(v[i], v[i + 1]); //conect the n nodes with n-1 edges
        }
        G.new_edge(v[n - 1], v[0]); //create the nth edge between the first and last nodes
       
        test(G); 
    }

    void testGraph3(int n)
    {
        graph G;
        int i;
        node v[n * 4]; //4 levels of n nodes
        for (int i = 0; i < 4 * n; i++)
            v[i] = G.new_node();

        int counter = 0;
        int k = 0;
        for (i = 0; i < 3 * n; i += n)
        {
            for (counter = 0; counter <= n - 1; counter++)
                G.new_edge(v[i + counter], v[n + counter + i]);
        }

        int ran_num, upper, lower;

        //Produce random node of the first level and connect it with all nodes
        //of the second level
        upper = n - 1;
        lower = 0;
        srand(time(0));
        ran_num = (rand() % (upper - lower + 1)) + lower;
        for (i = 0; i < n; i++)
            G.new_edge(v[ran_num], v[n + i]);

        //Produce random node of the second level and connect it with all nodes
        //of the third level
        srand(time(0));
        upper = 2 * n - 1;
        lower = n;
        ran_num = (rand() % (upper - lower + 1)) + lower;
        for (i = 0; i < n; i++)
            G.new_edge(v[ran_num], v[2 * n + i]);

        //Produce random node of the third level and connect it with all nodes
        //of the last level
        srand(time(0));
        upper = 3 * n - 1;
        lower = 2 * n;
        ran_num = (rand() % (upper - lower + 1)) + lower;
        for (i = 0; i < n; i++)
            G.new_edge(v[ran_num], v[3 * n + i]);

        //2 random nodes to connect 1st with 3rd level with one edge
        int ran_num2, upper2, lower2;

        srand(time(0));
        upper = n - 1;
        lower = 0;
        srand(time(0));
        upper2 = 3 * n - 1;
        lower2 = 2 * n;
        ran_num = (rand() % (upper - lower + 1)) + lower;
        ran_num2 = (rand() % (upper2 - lower2 + 1)) + lower2;
        G.new_edge(v[ran_num], v[ran_num2]);

        //2 random nodes to connect 2nd with 4th level with one edge
        srand(time(0));
        upper = 2 * n - 1;
        lower = n;
        srand(time(0));
        upper2 = 4 * n - 1;
        lower2 = 3 * n;
        ran_num = (rand() % (upper - lower + 1)) + lower;
        ran_num2 = (rand() % (upper2 - lower2 + 1)) + lower2;
        G.new_edge(v[ran_num], v[ran_num2]);

        test(G);
    }
   
    void test(graph& G)
    {
        G.make_bidirected(); //transform the graph to bidirectional
	    bool is_bip; //0 if graph is bipartite, 1 if graph is not bipartite
	    is_bip = Is_Bipartite(G);

        bool my_bar_checker_boo = bfs::my_bipar_checker(G, V1, V2);
        cout << endl << "Is_Bipartite Result: " << is_bip;
	    cout << endl << "My_bar_checker Result: " << my_bar_checker_boo << endl;
        
        benchmark(G);
    }

    //Running the algorithms multiple times in order to have more accurate results.
    void benchmark(graph& G)
    {
        int exec_times = 40;
        clock_t begin = clock();
        for (int i = 0; i < exec_times; ++i){
            Is_Bipartite(G, V1, V2);
        }
        clock_t end = clock();
        double elapsed_secs_leda = double(end- begin) / CLOCKS_PER_SEC / exec_times;

        begin = clock();
        //for (int i = 0; i < exec_times; ++i){
          //  bfs::my_bipar_checker(G, V1, V2);
        //}
        end = clock();
        double elapsed_secs_my_checker = double(end - begin) / CLOCKS_PER_SEC / exec_times;
        cout << endl;
        cout << endl << "Benchmark results: " << endl;
        cout << "Time elapsed leda: " << elapsed_secs_leda << " seconds" << endl;
        cout << "Time elapsed my checker: " << elapsed_secs_my_checker << " seconds" << endl;
    }
}
