#ifndef _vEB_cpp_
#define _vEB_cpp_

#include "vEB.hpp"

proto_vEB::proto_vEB(const size_t & usize)
{
	u = usize;
	//cout << u << endl;
	
	if(u % 2 != 0) throw invalid_argument("usize should be 2^2^k for some integer k >= 1");
	if(u == 2) {
		A = new int[2];
		//for(int i = 0; i < 2; ++i) cout << A[i];
		//cout << endl;
	}

	else { 

		int sqrtu = sqrt(u);

		summary = new proto_vEB(sqrtu);
		cluster = new proto_vEB* [sqrtu];
		for(int i =0; i < sqrtu; ++i) {
			cluster[i] = new proto_vEB(sqrtu);
			//cout << cluster[i] << " ";
		}
		//cout << endl;
	}
}

int proto_vEB::high(const int x) const 
{
	//cout << "\nhigh: " << static_cast<int>(floor(x/sqrt(u))) << endl;
	return static_cast<int>(floor(x/sqrt(u)));
}

int proto_vEB::low(const int x) const 
{
	int sqrtu = sqrt(u);
	//cout << "\nlow: " << (x % sqrtu) << endl;
	return (x % sqrtu);
}

int proto_vEB::index(const int x, const int y) const 
{
	int sqrtu = sqrt(u);
	//cout << "\nindex: " << (x*sqrtu) + y << endl;
	return (x*sqrtu) + y;
}


int proto_vEB::member(const int x) const {

	//cout << x << endl;
	if(u == 2)
	{
		return A[x];
	}

	else return cluster[high(x)]->member(low(x));
}

int proto_vEB::min() const {

	if(u == 2) {
		if(A[0] == 1) return 0;
		else if (A[1] == 1) return 1;
		else return -1;
	}
	else 
	{
		int min_cluster = summary->min();

		if(min_cluster == -1) return -1;
		else {
			int offset = cluster[min_cluster]->min();
			return index(min_cluster, offset);
		}
	}
}

int proto_vEB::succ(const int x) const {

	if(u == 2) {
		if(x == 0 && A[1] == 1) return 1;
		else return -1;
	}

	else 
	{
		int offset = cluster[high(x)]->succ(low(x));
		if(offset != -1) return index(high(x), offset);
		else{
			int succ_cluster = summary->succ(high(x));
			if(succ_cluster == -1) return -1;
			else{
				offset = cluster[succ_cluster]->min();
				return index(succ_cluster, offset);
			}
		}

	}
}


void proto_vEB::insert(const int x) {

	if(u == 2) A[x] = 1;
	else{
		cluster[high(x)]->insert(low(x));
		summary->insert(high(x));
	}
}

void proto_vEB::remove(const int x)
{
	if(u == 2) A[x] = 0;
	else {
        cluster[high(x)]->remove(low(x));
        
        int count = 0, beg = static_cast<int>(high(x)*sqrt(u)), end = static_cast<int>((high(x) + 1)*sqrt(u));
        std::cout << "REMOVE:" << beg << " " << end << " " << high(x) << " " << u<< std::endl;
        
        for(int i = beg; i < end; ++i){
            count+=cluster[high(x)]->member(low(i));
            std::cout << i << " ";
            std::cout<< cluster[high(x)]->member(low(i)) << std::endl;
        }
        std::cout << "COUNT " << count << std::endl;
        if(count == 0) summary->remove(high(x));
	}  
}

#endif //_vEB_cpp_
