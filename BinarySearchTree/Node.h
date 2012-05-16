
#pragma once

template <typename T>
class BinarySearchTree;

template <typename T>
class bNode
{
	friend BinarySearchTree<T>;
	
private:
	bNode* left;
	bNode* right;
	T Key;
public:
	bNode(T d):left(nullptr),right(nullptr), Key(d)
	{}
	~bNode()
	{
		left = right = nullptr;
	}
	operator T() const
	{
		return Key;
	}

};