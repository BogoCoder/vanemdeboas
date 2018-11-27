#ifndef _proto_vEB_cpp_
#define _proto_vEB_cpp_

/* Constructor, it receives u argument which refers to the universe size. O(u)*/
proto_vEB::proto_vEB(const size_t & usize) /* usize should be 2^2^k for some integer k >= 1 */
{
	u = usize;
	count = 0;
	//cout << u << endl;
	
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

proto_vEB::~proto_vEB()
{
	u = 0;
	count = 0;
	if(u == 2) delete[] A;
	delete summary;
	delete[] cluster;
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

	if(u == 2)
	{
		return A[x];
	}

	else return cluster[high(x)]->member(low(x));
}

/*  Finds and returns the minimun element of the structure. θ(lg u) */
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
		else 
		{
			int offset = cluster[min_cluster]->min();
			return index(min_cluster, offset);
		}
	}
}

/* Finds and returns the miximun element of the structure. θ(lg u) */
int proto_vEB::max() const {

	if(u == 2) {
		if(A[1] == 1) return 1;
		else if (A[0] == 1) return 0;
		else return -1;
	}
	else 
	{
		int max_cluster = summary->max();

		if(max_cluster == -1) return -1;
		else 
		{
			int offset = cluster[max_cluster]->max();
			return index(max_cluster, offset);
		}
	}
}
 
/* Finds the successor of the element x. θ(lg u lglg u)*/
int proto_vEB::succ(const int x) const {

	if(u == 2) {
		if(x == 0 && A[1] == 1) return 1;
		else return -1;
	}

	else 
	{
		int offset = cluster[high(x)]->succ(low(x));
		if(offset != -1) return index(high(x), offset);
		else
		{
			int succ_cluster = summary->succ(high(x));
			if(succ_cluster == -1) return -1;
			else
			{
				offset = cluster[succ_cluster]->min();
				return index(succ_cluster, offset);
			}
		}
	}
}

/* Finds the predecessor of the element x. θ(lg u lglg u) */
int proto_vEB::pred(const int x) const {

	if(u == 2) {
		if(x == 1 && A[0] == 1) return 0;
		else return -1;
	}

	else 
	{
		int offset = cluster[high(x)]->pred(low(x));
		if(offset != -1) return index(high(x), offset);
		else
		{
			int pred_cluster = summary->pred(high(x));
			if(pred_cluster == -1) return -1;
			else
			{
				offset = cluster[pred_cluster]->max();
				return index(pred_cluster, offset);
			}
		}
	}
}
 
/* Returns the number of elements of the structure. O(1) */
size_t proto_vEB::size() const {return count;}

/* Returns 1 if the structure is empty, or 0 otherwise O(1) */
bool proto_vEB::empty() const {return count == 0;}

/* Inserts element x to the structure O(lg u) */
void proto_vEB::insert(const int x) 
{
	if(u == 2) A[x] = 1;
	else
	{
		cluster[high(x)]->insert(low(x));

		int elem_cluster = cluster[high(x)]->count;

    	if(elem_cluster == 1) {
    		summary->insert(high(x));
    	}

	}

	count++;
}

/*  Removes element x of the structure O(lg u) */
void proto_vEB::remove(const int x)
{
	if(u == 2) A[x] = 0;
	else 
	{
        cluster[high(x)]->remove(low(x));
        
        // iterative remove
        /*int elem_cluster = 0, beg = static_cast<int>(high(x)*sqrt(u)), end = static_cast<int>((high(x) + 1)*sqrt(u));
        
        for(int i = beg; i < end; ++i)
            elem_cluster += cluster[high(x)]->member(low(i));
    	if(elem_cluster == 0) summary->remove(high(x));*/

    	int elem_cluster = cluster[high(x)]->count;

    	if(elem_cluster == 0) {
    		summary->remove(high(x));
    	}
	}  

	count--;
}

/* Clears the structure. O(lg u)*/
void proto_vEB::clear(){
	//cout << u << endl;

	if(u == 2) fill_n(A, 2, 0);

	else 
	{ 
		summary->clear();

		for(size_t i = 0; i < sqrt(u); ++i)
			cluster[i]->clear();
	}

	count = 0;

}
#endif //_proto_vEB_cpp_
