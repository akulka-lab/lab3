#pragma once

#ifndef _MENU_H_
#define _MENU_H_

#include "BinaryTree.h"

enum class MenuTreeOption
{
	Add		= 1,
	Remove		= 2,
	Find		= 3,
	FindMinimal	= 4,
	FindMaximal	= 5,
	Show		= 6,
	Exit		= 7
};

void errorsPrint(int *errorCode, char *nameFunction);
void PrintTree(BinaryTreeNode* node, int indent);
void Menu(BinaryTree* binaryTree);
int  mini_menu(int *menu_number);

#endif //_MENU_H_
