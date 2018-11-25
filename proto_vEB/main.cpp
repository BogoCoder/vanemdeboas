#include <iostream>
#include <random>
#include <cmath>
#include <ctime>
#include <queue>
#include "proto_vEB.hpp"
#include "BST.hpp"
using namespace std;

int main() {

    clock_t t;

    const int k = 4;

    const int min = 1;
    const int max = pow(2,pow(2,k));
    std::random_device rd;
    std::default_random_engine generator{rd()};
    std::uniform_int_distribution<int> distribution(min, max - 1);
    
    // declare and initialize heap and proto_vEB to compare
    cout<< max << endl;
    BST<int> bst;
    std::priority_queue<int> heap;
    proto_vEB proto(max);
    
    /*INSERT*/

    // fill proto_vEB
    t = clock();
    for (int i = min; i < max; i++) {
        int number = distribution(generator);
        proto.insert(number);
        //std::cout << "Inserted " << number << std::endl;
    }
    t = clock() - t;

    cout << "proto_vEB(INSERT): It took me " << (int)t << " clicks (" << (((float)t)/CLOCKS_PER_SEC) << " seconds).\n" << endl;

    // fill tree
    t = clock();
    for (int i = min; i < max; i++) {
        int number = distribution(generator);
        bst.insert(number);
        //std::cout << "Inserted " << number << std::endl;
    }
    t = clock() - t;

    cout << "BST(INSERT): It took me " << (int)t << " clicks (" << (((float)t)/CLOCKS_PER_SEC) << " seconds).\n" << endl;
    
    // fill heap
    t = clock();
    for (int i = min; i < max; i++) {
        int number = distribution(generator);
        heap.push(number);
        //std::cout << "Inserted " << number << std::endl;
    }
    t = clock() - t;

    cout << "HEAP(INSERT): It took me " << (int)t << " clicks (" << (((float)t)/CLOCKS_PER_SEC) << " seconds).\n" << endl;

    /******/

    /*FIND*/
    t = clock();
    int num1 = distribution(generator);
    proto.member(num1);
    t = clock() - t;
	cout << "proto_vEB(FIND): It took me " << (int)t << " clicks (" << (((float)t)/CLOCKS_PER_SEC) << " seconds).\n" << endl;

    t = clock();
    int num2 = distribution(generator);
    bst.find(num2);
    t = clock() - t;
	cout << "BST(FIND): It took me " << (int)t << " clicks (" << (((float)t)/CLOCKS_PER_SEC) << " seconds).\n" << endl;
	/******/
    return 0;
}
