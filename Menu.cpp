#include <iostream>
#include <string>
#include <exception>
#include <iomanip>

#include "Menu.h"
#include "Header.h"

using namespace std;

void PrintTree(BinaryTreeNode* node, int indent)
{
	if (node == nullptr)
	{
		return;
	}
	
	if (node->Right) 
	{
		PrintTree(node->Right, indent + 4);
	}
	
	if (indent) 
	{
		cout << setw(indent) << ' ';
	}
	
	if (node->Right)
	{
		cout << " /\n" << setw(indent) << ' ';
	}
	
	cout << node->Data << "\n ";
	if (node->Left) 
	{
		cout << setw(indent) << ' ' << " \\\n";
		PrintTree(node->Left, indent + 4);
	}
	
}

int get()
{
	while (true)
	{
		int count;
		int inputValue;
		
		cout << "Enter kolvo: ";
		int n;
		cin >> n; 
		cout << "Enter menu Value: ";
		for (int i = 0; i < n; i++)
		{
			cin >> inputValue;
			return inputValue;
		}
	}
}


void Menu(BinaryTree* binaryTree)
{
	InitializeTree(binaryTree);
	int valueForMenu = -1;
	int valueForTree;
	bool isValueForPrint = false;
	int count = 1;
	
	int menu_num = 0;

	while (valueForMenu !=0)
	{
		if(isValueForPrint)
		{
			PrintTree(binaryTree->Root, 3);
		}

		mini_menu();
		cin >> valueForMenu;

		if (valueForMenu == 1)
		{
			valueForTree = get();

			Insert(binaryTree->Root, valueForTree);
			
		}
		else if (valueForMenu == 2)
		{
			valueForTree = get();
			Remove(binaryTree->Root, valueForTree);
		}
		else if (valueForMenu == 3)
		{
			valueForTree = get();
			try
			{
				cout << Find(binaryTree->Root, valueForTree)->Data << endl;
			}
			catch (exception& exceptionFind)
			{
				cout << exceptionFind.what();
			}
			system("pause");
		}
		else if (valueForMenu == 4)
		{
			try
			{
				cout << FindMinimal(binaryTree->Root)->Data << endl;
			}
			catch (exception& exceptionFindMinimal)
			{
				cout << exceptionFindMinimal.what();
			}
			system("pause");
		}
		else if (valueForMenu == 5)
		{
			try
			{
				cout << FindMaximal(binaryTree->Root)->Data << endl;
			}
			catch (exception& exceptionFindMaximal)
			{
				cout << exceptionFindMaximal.what();
			}
			system("pause");
		}
		else if (valueForMenu == 6)
		{
			isValueForPrint = true;
		}
		else if (valueForMenu == 7)
		{
			FreeTree(binaryTree->Root);
			return;
		}
	}
}


