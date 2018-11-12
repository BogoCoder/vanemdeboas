#ifndef _vEB_hpp_
#define _vEB_hpp_

template <typename datatype>
class vEB {
	private:
		struct vEBC {
			/*todo*/
		};

		size_t count;
		vEBC *root;

		vEBC * min(/**/) const;
		vEBC * max(/**/) const;
		vEBC * succ(/**/) const;
		vEBC * pred(/**/) const;

		void remove(/**/);
		void clear(vEBC *root);
		void insert(vEBC * &root, /**/);
		vEBC * find(vEBC *root, datatype key) const;

	public:
		vEB();
		vEB(const vEB & rhs);
		~vEB();
		void remove(datatype key);
		bool empty(void) const;
		bool member(vEB * ts);
		void clear(void);
		size_t size(void) const;
		bool find(datatype key) const;
		void insert(datatype key);
};

#include "vEB.cpp"

#endif //_vEB_hpp_