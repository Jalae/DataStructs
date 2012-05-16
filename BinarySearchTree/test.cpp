
#include <iostream>
#include "BinarySearchTree.h"

void print(int i)
{
	std::cout << i << " ";
}

int main()
{
BinarySearchTree<int> test;

test.Insert(5);
test.Insert(11);
test.Insert(12);
test.Insert(913);
test.Insert(2);
test.Insert(23);
test.Insert(1);
test.Insert(3);
test.Insert(13);
test.Insert(1);
test.Insert(3);
test.Insert(13);
test.Insert(151);
test.Insert(212);
test.Insert(16);

test.InOrderTraversal(*print);
std::cout << "\n";
test.PostOrderTraversal(*print);
std::cout << "\n";
test.PreOrderTraversal(*print);
std::cout << "\n";
test.BreadthFirstTraversal(*print);

std::cout << "\n" << test.Height();

test.Purge();
std::cout << "\n" << test.Height();

test.InOrderTraversal(*print);
test.PostOrderTraversal(*print);
test.PreOrderTraversal(*print);
test.BreadthFirstTraversal(*print);

test.Insert(16);
test.Insert(5);
test.Insert(11);
test.Insert(12);
test.Insert(913);
test.Insert(2);
test.Insert(23);
test.Insert(1);
test.Insert(3);
test.Insert(13);
test.Insert(1);
test.Insert(3);
test.Insert(13);
test.Insert(151);
test.Insert(212);
std::cout << "\n" << test.Height() << "\n";
test.Delete(16);
test.Delete(151);
test.InOrderTraversal(*print);
std::cout << "\n";
test.BreadthFirstTraversal(*print);
std::cout << "\n" << test.Height();


std::cin.ignore();
}


