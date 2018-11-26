#ifndef _BST_hpp_
#define _BST_hpp_
using namespace std;

#include <iostream>

template<typename keyType>

class BST {

private:

	struct BSTNode {
		keyType key;
		BSTNode *left, *right, *parent;
	};

	size_t count;
	BSTNode *tree;


	BSTNode * min(BSTNode * root) const;
	BSTNode * max(BSTNode * root) const;
	BSTNode * succ(BSTNode * root) const;
	BSTNode * pred(BSTNode * root) const;

	void remove(BSTNode * &root, keyType key);
	BSTNode * copy(BSTNode *root) const;
	void clear(BSTNode * &root);
	void display(BSTNode *root, std::ostream &out) const;
	void insert(BSTNode * &root, keyType key);
	BSTNode * find(BSTNode * root, keyType key) const;


public:

	BST();
	BST(const BST &rhs);
	~BST();
	void remove(keyType key);
	bool empty(void) const;
	void clear(void);
	size_t size(void) const;
	bool find(keyType key) const;
	void insert(keyType key);
	void display(std::ostream &out = std::cout) const;
};

#include "BST.cpp"

#endif //_BST_hpp_