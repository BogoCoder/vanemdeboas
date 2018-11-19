#ifndef _vEB_cpp_
#define _vEB_cpp_

#include "vEB.hpp"

void proto_vEB::operator()(const size_t & usize) 
{
	u = usize;
	cout << u << endl;
	int sqrtu = sqrt(u);
	if(u == 2) {
		A = new int[2];
		for(int i = 0; i < 2; ++i) cout << A[i];
		cout << endl;
	}

	else { 

		proto_vEB * summary = new proto_vEB;
		(*summary)(sqrtu);

		cluster = new proto_vEB* [sqrtu];
		for(int i =0; i < sqrtu; ++i) {
			cluster[i] = new proto_vEB;
			(*cluster[i])(sqrtu);
			//cout << cluster[i] << " ";
		}
		cout << endl;
	}
}

int proto_vEB::high(int x){
	return x/sqrt(u);
}

int proto_vEB::low(int x){
	return (int)(x % (int)floor(sqrt(u)));
}

int vEB::member(proto_vEB  V, int x){

	if(V.u == 2)
	{
		return V.A[x];
	}

	else return member(*V.cluster[V.high(x)], V.low(x));
}

#endif //_vEB_cpp_