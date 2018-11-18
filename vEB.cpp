#ifndef _vEB_cpp_
#define _vEB_cpp_

#include "vEB.hpp"

void proto_vEB::operator()(const int & u) 
{
	cout << u << endl;
	int sqrtu = sqrt(u);
	if(u == 2) {
		int * A = new int[2];
		for(int i = 0; i < 2; ++i) cout << A[i];
		cout << endl;
	}

	else { 

		proto_vEB * summary = new proto_vEB;
		(*summary)(sqrtu);

		proto_vEB** cluster = new proto_vEB* [sqrtu];
		for(int i =0; i < sqrtu; ++i) {
			cluster[i] = new proto_vEB;
			(*cluster[i])(sqrtu);
		}
	}
}

#endif //_vEB_cpp_