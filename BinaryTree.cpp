#include <exception>

#include "BinaryTree.h"


void InitializeTree(BinaryTree* binaryTree)
{
	binaryTree->Root = nullptr;
}

int my_strlen(const char* str)
{
    int len = 0;
    while (str[len] != '\0')
        len++;
    return len;
}

void my_memcpy(char* newstr, char* str, int len)
{
    char* s1 = newstr;
    char* s2 = str;

    for (int i = 0; i < len; i++)
    {
        *(s1++) = *(s2++);
    }
}

char wordob1(char* str, int n, int len1, int dlina)
{
    for (int j = 0; j < n; j++)
    {
        char tmp = str[0];
        for (int i = 0; i < len1; i++)
        {
            str[i] = str[i + 1];
        }

        str[len1] = tmp;
    }
}


BinaryTreeNode* Find(BinaryTreeNode* node, const int value)
{
	if(node == nullptr)
	{
		throw std::exception("Does not exist\n");
	}

	if(node->Data == value)
	{
		return node;
	}

	if(node->Data > value)
	{
		return Find(node->Left, value);
	}

	return Find(node->Right, value);
}


BinaryTreeNode* FindMinimal(BinaryTreeNode* node)
{
	if(node == nullptr)
	{
		throw std::exception("Does not exist\n");
	}

	while(node->Left != nullptr)
	{
		node = node->Left;
	}

	return node;
}


BinaryTreeNode* FindMaximal(BinaryTreeNode* node)
{
	if(node == nullptr)
	{
		throw std::exception("Does not exist\n");
	}

	while(node->Right != nullptr)
	{
		node = node->Right;
	}

	return node;
}


void Insert(BinaryTreeNode*& node, const int value)
{
	if(node == nullptr)
	{
		node = new BinaryTreeNode;
		node->Data = value;
		return;
	}

	if(node->Data > value)
	{
		Insert(node->Left, value);
		return;
	}
	
	Insert(node->Right, value);
	return;
}


/// @todo return void;
void Remove(BinaryTreeNode*& node, const int value)
{
	if(node == nullptr)
	{
		return;
	}

	if(value < node->Data)
	{
		Remove(node->Left, value);
	}
	else if(value > node->Data)
	{
		Remove(node->Right, value);
	}
	else if(node->Left != nullptr && node->Right != nullptr)
	{
		node->Data = FindMinimal(node->Right)->Data;
		Remove(node->Right, node->Data);
	}
	else
	{
		BinaryTreeNode* current = nullptr;
		if(node->Left != nullptr)
		{
			current = node;
			node = current->Left;
			delete current;
		}
		else if(node->Right != nullptr)
		{
			current = node;
			node = current->Right;
			delete current;
		}
		else
		{
			delete node;
			node = nullptr;
		}
	}
	
	return;
}


void FreeTree(BinaryTreeNode* node)
{
	if (node == nullptr)
	{
		return;
	}

	FreeTree(node->Left);
	FreeTree(node->Right);
	delete node;
}
