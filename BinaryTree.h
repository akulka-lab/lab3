#pragma once

#ifndef _BINARYTREE_H_
#define _BINARYTREE_H_

#include "BinaryTreeNode.h"

struct BinaryTree
{
	BinaryTreeNode* Root;
};

void InitializeTree(BinaryTree* binaryTree);
BinaryTreeNode* Find(BinaryTreeNode* node, const int value);
BinaryTreeNode* FindMinimal(BinaryTreeNode* node);
BinaryTreeNode* FindMaximal(BinaryTreeNode* node);

void Insert(BinaryTreeNode*& node, const int value);
void Remove(BinaryTreeNode*& node, const int value);
void FreeTree(BinaryTreeNode* node);


#endif //_BINARYTREE_H_
