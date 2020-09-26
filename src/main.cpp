#include <iostream>
#include "../incl/tests.h"
#include "../incl/bfs.h"
using namespace std;
list<node> V1;
list<node> V2;

int main(int argc, char **argv)
{
	
	cout << "*******************************************************************************" << endl;
	cout << "Test Graph 1 LOADING...." << endl;
	cout << endl << "n = 10000 " << endl;
   	test::testGraph1(10000);
	cout <<  endl << "n = 40000 " << endl;   
    test::testGraph1(40000);
	cout <<  endl << "n = 90000 " << endl;   
    test::testGraph1(90000);
 	cout << endl << "Test Graph 1 SUCCESSFUL! " << endl;
	cout << "*******************************************************************************" << endl;
	
	cout << "Test Graph 2 LOADING...." << endl;
	cout << endl << "n = 10001 " << endl;
	test::testGraph2(10001);
	cout << endl << "n = 40001 " << endl;
    test::testGraph2(40001);
	cout << endl << "n = 90001 " << endl;
    test::testGraph2(90001);
 	cout << "Test Graph 2 Successful! " << endl;
	cout << "*******************************************************************************" << endl;

	cout << "Test Graph 3 LOADING...." << endl;
	cout << endl << "n = 500 " << endl;
	test::testGraph3(500);
	cout << endl << "n = 1000 " << endl;
    test::testGraph3(1000);
	cout << endl << "n = 1500 " << endl;
    test::testGraph3(1500);
 	cout << "Test Graph 3 Successful! " << endl;
	cout << "*******************************************************************************" << endl;
	
	return 0;
}