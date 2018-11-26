#ifndef _vEB_hpp_
#define _vEB_hpp_

#include <iostream>
#include <cmath>
using namespace std;

class vEB {

	public:
		
		vEB(const size_t & usize); /* usize should be 2^k for some integer k > 0 */
		~vEB();

		bool member(const int x) const;
		int min() const;
		int max() const;
		int succ(const int x) const;
		int pred(const int x) const;
		size_t size() const;
		bool empty() const;

		void insert(int x);
		void remove(int x);
		void clear();


	private:

		int high(const int x) const;
		int low(const int x) const;
		int index(const int x, const int y) const;

		void emptyinsert(const int x);

		size_t u;
		size_t count;
		int minv;
		int maxv;

		vEB * summary;
		vEB* * cluster;
};

#include "vEB.cpp"


#endif //_vEB_hpp_
