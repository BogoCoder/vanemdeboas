#ifndef _proto_vEB_hpp_
#define _proto_vEB_hpp_

#include <iostream>
#include <cmath>
using namespace std;

class proto_vEB {

	public:
		
		proto_vEB(const size_t & usize); /*(usize = universe size): usize should be 2^2^k for some integer k >= 1 */
		~proto_vEB();

		int member(const int x) const;
		int min() const;
		int max() const;
		int succ(const int x) const;
		int pred(const int x) const;
		size_t size() const;
		bool empty() const;

		void insert(const int x);
		void remove(const int x);
		void clear();


	private:

		int high(const int x) const;
		int low(const int x) const;
		int index(const int x, const int y) const;

		size_t u;
		size_t count;

		int * A;
		proto_vEB * summary;
		proto_vEB* * cluster;
};

#include "proto_vEB.cpp"


#endif //_proto_vEB_hpp_
