#ifndef _BST_cpp_
#define _BST_cpp_

#include "BST.hpp"

template<typename keyType>
typename BST<keyType>::BSTNode * BST<keyType>::min(BSTNode * root) const
{
	BSTNode * curr = root;
	if(curr->left == nullptr){

		return curr;
	}

	else return min(curr->left);
}

template<typename keyType>
typename BST<keyType>::BSTNode * BST<keyType>::max(BSTNode * root) const
{
	BSTNode * curr = root;
	if(curr->right == nullptr){

		return curr;
	}

	else return max(curr->right);
}

template<typename keyType>
typename BST<keyType>::BSTNode * BST<keyType>::succ(BSTNode * root) const
{
	BSTNode * curr = root;
	if(curr == nullptr) return curr;

	else if(curr->right == nullptr) return nullptr;

	else{

		curr = curr->right;

		while(curr != nullptr){
			curr = curr->left;
		}
	}
}

template<typename keyType>
typename BST<keyType>::BSTNode * BST<keyType>::pred(BSTNode * root) const
{
	BSTNode * curr = root;
	if(curr == nullptr) return curr;

	else if(curr->left == nullptr) return nullptr;

	else{

		curr = curr->left;

		while(curr != nullptr){
			curr = curr->right;
		}
	}
}

template<typename keyType>
void BST<keyType>::remove(BSTNode * &root, keyType key)
{
	if(root == nullptr)
		return; // Item not found; do nothing
	if(key < root->key) remove(root->left, key);
	else if(key > root->key) remove(root->right, key);
	else if(root->left != nullptr && root->right != nullptr) // Two children
	{ 
		root->key = min(root->right)->key;
		remove(root->right, root->key);
	}

	else
	{
		BSTNode *oldNode = root;
		root = (root->left != nullptr) ? root->left : root->right;
		delete oldNode;
	}
}

template<typename keyType>
typename BST<keyType>::BSTNode * BST<keyType>::copy(BSTNode * root) const
{
	if(root == nullptr) return nullptr;
	else return new BSTNode{root->key, copy(root->left), copy(root->right)};
}

template<typename keyType>
void BST<keyType>::clear(BSTNode * &root)
{
	if(root != nullptr)
	{
		clear(root->left);
		clear(root->right);
		delete root;
	}

	root = nullptr;
}

template<typename keyType>
void BST<keyType>::display(BSTNode * root, std::ostream &out) const
{
	if(root != nullptr)
	{
		display(root->left, out);
		out << root->key << endl;
		display(root->right, out);
	}
}

template<typename keyType>
void BST<keyType>::insert(BSTNode * &root, keyType key)
{
	if(root == nullptr)
	{
		root = new BSTNode{key, nullptr, nullptr};
	}
	else
	{
		if(key != root->key)
		{
			if(key < root->key) insert(root->left, key);
			else insert(root->right, key);
		}
	}
}

template<typename keyType>
typename BST<keyType>::BSTNode * BST<keyType>::find(BSTNode * root, keyType key) const
{
	if(root == nullptr) return nullptr;
	if(key == root->key) return root;
	if(key < root->key) return find(root->left, key);
	else return find(root->right, key);
}

template<typename keyType>
BST<keyType>::BST()
{
	tree = nullptr;
	count = 0;
}

template<typename keyType>
BST<keyType>::BST(const BST &rhs) : tree{nullptr}
{
	tree = copy(rhs.tree);
	count = rhs.count;
}

template<typename keyType>
BST<keyType>::~BST()
{
	clear();
}

template<typename keyType>
void BST<keyType>::remove(keyType key)
{
	remove(tree, key);
	count--;
}

template<typename keyType>
bool BST<keyType>::empty(void) const
{
	return count == 0;
}

template<typename keyType>
void BST<keyType>::clear(void)
{
	clear(tree);
	count = 0;
}

template<typename keyType>
size_t BST<keyType>::size(void) const
{
	return count;
}

template<typename keyType>
bool BST<keyType>::find(keyType key) const
{
	if(find(tree, key) == nullptr) return false;
	else return true;
}

template<typename keyType>
void BST<keyType>::insert(keyType key)
{
	insert(tree, key);
	count++;
}

template<typename keyType>
void BST<keyType>::display(std::ostream &out) const
{
	display(tree, out);
}

#endif //_BST_cpp_