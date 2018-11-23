#ifndef _vEB_hpp_
#define _vEB_hpp_
using namespace std;

#include <iostream>
#include <math.h>


class proto_vEB {

	public:

		proto_vEB();
		proto_vEB(const size_t & usize); // u = universe size

		int member(const int x) const;
		int min() const;
		int succ(const int x) const;
		void insert(const int x);
		void remove(const int x);


	private:

		int high(const int x) const;
		int low(const int x) const;
		int index(const int x, const int y) const;

		size_t u;
		int * A;
		proto_vEB * summary;
		proto_vEB* * cluster;
};

#endif //_vEB_hpp_
