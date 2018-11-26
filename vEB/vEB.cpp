#ifndef _vEB_cpp_
#define _vEB_cpp_

vEB::vEB(const size_t & usize) /* usize should be 2^k for some integer k > 0 */
{
	int lowsqrtu = static_cast<int>(pow(2,floor(log2(usize)/2)));
	int upsqrtu = static_cast<int>(pow(2,ceil(log2(usize)/2)));

	u = upsqrtu * lowsqrtu;

	minv = -1;
	maxv = -1;
	count = 0;

	if(u != 2)
	{ 
		summary = new vEB(upsqrtu);

		cluster = new vEB* [upsqrtu];
		for(int i =0; i < upsqrtu; ++i) {
			cluster[i] = new vEB(lowsqrtu);
		}
	}
}

vEB::~vEB()
{
	minv = -1;
	maxv = -1;
	u = 0;
	count = 0;
	delete summary;
	delete[] cluster;
}

int vEB::high(const int x) const 
{
	int lowsqrtu = static_cast<int>(pow(2,floor(log2(u)/2)));
	//cout << "\nhigh: " << static_cast<int>(floor(x/lowsqrtu)) << endl;
	return static_cast<int>(floor(x/lowsqrtu));
}

int vEB::low(const int x) const 
{
	int lowsqrtu = static_cast<int>(pow(2,floor(log2(u)/2)));
	//cout << "\nlow: " << (x % lowsqrtu) << endl;
	return (x % lowsqrtu);
}

int vEB::index(const int x, const int y) const 
{
	int lowsqrtu = static_cast<int>(pow(2,floor(log2(u)/2)));
	//cout << "\nindex: " << (x*lowsqrtu) + y << endl;
	return (x*lowsqrtu) + y;
}


bool vEB::member(const int x) const {

	if(x == minv or x == maxv)
	{
		return true;
	}

	else if(u == 2) return false;
	else return cluster[high(x)]->member(low(x));
}

int vEB::min() const {

	return minv;
}

int vEB::max() const {
	return maxv;
}

int vEB::succ(const int x) const {

	if(u == 2) {
		if(x == 0 && maxv == 1) return 1;
		else return -1;
	}

	else if(minv != -1 && x < minv) return minv;
	else {
		int max_low = cluster[high(x)]->max();

		if(max_low != -1 && low(x) < max_low){
			int offset = cluster[high(x)]->succ(low(x));
			return index(high(x), offset);
		}
		else {
			int succ_cluster = summary->succ(high(x));

			if(succ_cluster == -1) return -1;

			else {
				int offset = cluster[succ_cluster]->min();
				return index(succ_cluster, offset);
			}
		}
	}
}

int vEB::pred(const int x) const {

	if(u == 2) {
		if(x == 1 && minv == 0) return 0;
		else return -1;
	}

	else if(maxv != -1 && x > maxv) return maxv;
	else {
		int min_low = cluster[high(x)]->min();

		if(min_low != -1 && low(x) > min_low){
			int offset = cluster[high(x)]->pred(low(x));
			return index(high(x), offset);
		}
		else {
			int pred_cluster = summary->pred(high(x));

			if(pred_cluster == -1) {
				if(minv != -1 && x > minv ) return minv;
				else return -1;
			}

			else {
				int offset = cluster[pred_cluster]->max();
				return index(pred_cluster, offset);
			}
		}
	}
}

size_t vEB::size() const {return count;}

bool vEB::empty() const {return count == 0;}

void vEB::emptyinsert(const int x) 
{
	minv = x;
	maxv = x;
}

void vEB::insert(int x) 
{
	if(minv == -1) emptyinsert(x);
	else 
	{
		if(x < minv) 
			swap(x, minv);

		if(u > 2)
		{
			if(cluster[high(x)]->min() == -1)
			{
				summary->insert(high(x));
				cluster[high(x)]->emptyinsert(low(x));
			}

			else
				cluster[high(x)]->insert(low(x));
		}

		if(x > maxv)
			maxv = x;
	}

	count++;
}

void vEB::remove(int x)
{
	if(minv == maxv) 
	{ 
		minv = -1;
		maxv = -1;
	}

	else if(u == 2)
	{
		if(x == 0) minv = 1;
		else minv = 0;
		maxv = minv;
	}

	else  
	{
		if(x == minv)
		{
			int first_cluster = summary->min();
			x = index(first_cluster, cluster[first_cluster]->min());
			minv = x;
		}
		cluster[high(x)]->remove(low(x));
		if(cluster[high(x)]->min() == -1)
		{
			summary->remove(high(x));

			if(x == maxv){
				int summary_max = summary->max();
				if(summary_max == -1)
					maxv = minv;
				else
					maxv = index(summary_max, cluster[summary_max]->max());
			}
		}

		else if(x == maxv)
			maxv = index(high(x), cluster[high(x)]->max());
	}

	count--;
}


void vEB::clear()
{
	minv = -1;
	maxv = -1;

	if(u != 2)
	{ 
		summary->clear();

		for(size_t i = 0; i < sqrt(u); ++i)
			cluster[i]->clear();
	}
	count = 0;
}
#endif //_vEB_cpp_
