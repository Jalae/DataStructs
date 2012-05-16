
#pragma once
#include "Node.h"
#include "../Queue_list/queue_list.h"
template <typename T>
class BinarySearchTree
{
	bNode<T> * root;
	
	bNode<T>* Insert(bNode<T>* tree, T d)
	{
		if(tree)
		{
			if(d < tree->Key)//left
				tree->left = Insert(tree->left, d);
			else if(tree->Key < d)//right
				tree->right = Insert(tree->right, d);
			else//already exists
				;
			return tree;
		}
		else
		{
			bNode<T>* temp = new bNode<T>(d);
			return temp;
		}
	}
	bNode<T>* Delete(bNode<T>* tree, T d)
	{
		if(tree)
		{
			if(d < tree->Key)
			{//look left
				tree->left = Delete(tree->left, d);
				return tree;
			}
			else if(tree->Key < d)
			{//look right
				tree->right = Delete(tree->right, d);
				return tree;
			}
			else
			{//s'gotta be me
				if(!(tree->right||tree->left))//i have no children
				{
					delete tree;
					return nullptr;
				}
				else if(tree->right)
				{//right children are more important.
					//find smallest
					bNode<T> * cur = tree->right;
					if(cur->left)
					{
						do
							cur = cur->left;
						while(cur->left);

						if(cur->right)
						{
							bNode<T> * PARENT = tree->right;
							while(PARENT->left != cur)
								PARENT = PARENT->left;
							PARENT->left = cur->right;
						}
					}
					cur->left = tree->left;
					if(cur != tree->right)
						cur->right = tree->right;
					delete(tree);
					return cur;
				}else
				{
					bNode<T> * temp = tree->left;
					delete(tree);
					return(temp);
				}
			}
		}
		//we didn't find it.
		return tree;
	}
	int Height(bNode<T>* tree, int cur)
	{
		if(tree)
		{
			int l = Height(tree->left, cur+1);
			int r = Height(tree->right, cur+1);
			return (r>l)?r:l;
		}
		else
			return cur;
	}
	void Purge(bNode<T>* tree)
	{
		if(tree)
		{
			Purge(tree->left);
			Purge(tree->right);
			delete(tree);
			tree = nullptr;
		}
	}

	void InOrderTraversal(bNode<T>* tree, void(*func)(T))
	{
		if(tree)
		{
			InOrderTraversal(tree->left, func);
			func(*tree); //visit
			InOrderTraversal(tree->right, func);
		}
		return;
	}
	void PreOrderTraversal(bNode<T>* tree, void(*func)(T))
	{
		if(tree)
		{
			func(*tree); //visit
			PreOrderTraversal(tree->left, func);
			PreOrderTraversal(tree->right, func);
		}
		return;
	}
	void PostOrderTraversal(bNode<T>* tree, void(*func)(T))
	{
		if(tree)
		{
			PostOrderTraversal(tree->left, func);
			PostOrderTraversal(tree->right, func);
			func(*tree); //visit
		}
		return;
	}
	void BreadthFirstTraversal(Queue_list<bNode<T>*> & temp)
	{
		if(temp.Front()->left)
			temp.Enqueue(temp.Front()->left);
		if(temp.Front()->right)
			temp.Enqueue(temp.Front()->right);
	}
public:
	BinarySearchTree():root(nullptr)
	{}

	void Insert(T d)
	{
		if(root)
		{
			if(d < root->Key)//left
				root->left = Insert(root->left, d);
			else if(root->Key < d)//right
				root->right = Insert(root->right, d);
			else//nothing
				return;
		}
		else
		{
			root = new bNode<T>(d);
			return;
		}
	}

	void Delete(T d)
	{
		if(root)
		{
			if(d < root->Key)
			{//look left
				root->left = Delete(root->left, d);
				return;
			}
			else if(root->Key < d)
			{//look right
				root->right = Delete(root->right, d);
				return;
			}
			else
			{//s'gotta be me
				if(!(root->right||root->left))//i have no children
				{
					delete root;
					root = nullptr;
					return;
				}
				else if(root->right)
				{//right children are more important.
					//find smallest
					bNode<T> * cur = root->right;
					if(cur->left)
					{
						do
							cur = cur->left;
						while(cur->left);

						if(cur->right)
						{
							bNode<T> * PARENT = root->right;
							while(PARENT->left != cur)
								PARENT = PARENT->left;
							PARENT->left = cur->right;
						}
					}
					cur->left = root->left;
					if(cur != root->right)
						cur->right = root->right;
					delete(root);
					root = cur;
					return;
				}else
				{
					bNode<T> * temp = root->left;
					delete(root);
					root = temp;
					return;
				}
			}
		}
		//we didn't find it.
		return;
	}
	void Purge()
	{
		if(root)
		{
			Purge(root->left);
			Purge(root->right);
			delete(root); 
			root = nullptr;
		}
		return;
	}
	int Height()
	{
		if(root)
		{
			int l = Height(root->left, 0);
			int r = Height(root->right, 0);
			return (r>l)?r:l;
		}
		else
		{
			return 0;
		}
	} 
	
	void InOrderTraversal(void(*func)(T))
	{
		if(root)
		{
			InOrderTraversal(root->left, func);
			func(*root); //visit
			InOrderTraversal(root->right, func);
		}
		return;
	}
	void PreOrderTraversal(void(*func)(T))
	{
		if(root)
		{
			func(*root); //visit
			PreOrderTraversal(root->left, func);
			PreOrderTraversal(root->right, func);
		}
	}
	void PostOrderTraversal(void(*func)(T))
	{
		if(root)
		{
			//tDepth
			PostOrderTraversal(root->left, func);
			PostOrderTraversal(root->right, func);
			func(*root); //visit
		}
	}
	void BreadthFirstTraversal(void(*func)(T))
	{
 //do this;
		Queue_list<bNode<T>*> temp;
		if(root)
			temp.Enqueue(root);
		while(!temp.isEmpty())
		{
			BreadthFirstTraversal(temp);
			func(*temp.Dequeue());
		}
	}

};
