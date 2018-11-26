#include <iostream>
#include <random>
#include <cmath>
#include <ctime>
#include "vEB.hpp"
#include "BST.hpp"
using namespace std;

int main() {

    clock_t t;

    const int k = 16;

    const int min = 1;
    const int max = pow(2,k);
    std::random_device rd;
    std::default_random_engine generator{rd()};
    std::uniform_int_distribution<int> distribution(min, max - 1);
    
    // declare and initialize heap and boas_vEB to compare
    cout<< max << endl;
    BST<int> bst;
    vEB boas(max);
    
    /*INSERT*/

    // fill vEB
    t = clock();
    for (int i = min; i < max; i++) {
        boas.insert(i);
        //std::cout << "Inserted " << i << std::endl;
    }
    t = clock() - t;

    cout << "vEB(INSERT): It took me " << (int)t << " clicks (" << (((float)t)/CLOCKS_PER_SEC) << " seconds).\n" << endl;

    /*cout << "vEB(SUCC):" << boas.succ(7) << endl;
    cout << "vEB(PRED):" << boas.pred(7) << endl;
    cout << "vEB(MEMBER):" << boas.member(7) << endl;

    int x = 13;
    boas.remove(x);

    cout << "THE ELEMENT " << x << " WAS REMOVED" << endl;

    cout << "vEB(SUCC):" << boas.succ(14) << endl;
    cout << "vEB(PRED):" << boas.pred(14) << endl;
    cout << "vEB(MEMBER):" << boas.member(13) << endl;

    cout << "vEB(SIZE):" << boas.size() << endl;
    cout << "vEB(EMPTY):" << boas.empty() << endl;

    boas.clear();
    cout << "THE vEB WAS CLEARED" << endl;

    cout << "vEB(SIZE):" << boas.size() << endl;
    cout << "vEB(EMPTY):" << boas.empty() << endl;

    cout << "vEB(SUCC):" << boas.succ(7) << endl;
    cout << "vEB(PRED):" << boas.pred(7) << endl;
    cout << "vEB(MEMBER):" << boas.member(7) << endl;*/
    
    // fill BST
    t = clock();
    for (int i = min; i < max; i++) {
        bst.insert(i);
        //std::cout << "Inserted " << i << std::endl;
    }
    t = clock() - t;
    cout << "BST(INSERT): It took me " << (int)t << " clicks (" << (((float)t)/CLOCKS_PER_SEC) << " seconds).\n" << endl;

    /*FIND*/

    int num1 = distribution(generator);

    t = clock();
    boas.member(num1);
    t = clock() - t;
	cout << "vEB(FIND): It took me " << (int)t << " clicks (" << (((float)t)/CLOCKS_PER_SEC) << " seconds).\n" << endl;

    t = clock();
    bst.find(num1);
    t = clock() - t;
	cout << "BST(FIND): It took me " << (int)t << " clicks (" << (((float)t)/CLOCKS_PER_SEC) << " seconds).\n" << endl;

    /*REMOVE*/

    int num2 = distribution(generator);

    t = clock();
    boas.member(num2);
    t = clock() - t;
    cout << "vEB(REMOVE): It took me " << (int)t << " clicks (" << (((float)t)/CLOCKS_PER_SEC) << " seconds).\n" << endl;

    t = clock();
    bst.find(num2);
    t = clock() - t;
    cout << "BST(REMOVE): It took me " << (int)t << " clicks (" << (((float)t)/CLOCKS_PER_SEC) << " seconds).\n" << endl;

    return 0;
}
