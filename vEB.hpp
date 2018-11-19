#ifndef _vEB_hpp_
#define _vEB_hpp_
using namespace std;

#include <iostream>
#include <math.h>


class proto_vEB {
public:
	void operator()(const size_t & u); // u = universe size
	int high(int x);

	int low(int x);

	size_t u;
	int * A;
	proto_vEB** cluster;

private:

};

class vEB {
public:
	int member(proto_vEB  V, int x);

};

#endif //_vEB_hpp_