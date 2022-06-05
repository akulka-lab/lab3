#include <iostream>
#include <string>
#include <exception>
#include <iomanip>
#include "Menu.h"

using namespace std;

int main()
{
    cout <<
        " _______________________________________________________________________  \n"
        "|                                                                       | \n"
        "|              Welcome to Lab3! Starting the program....                | \n"
        "|____  _________________________________________________________________| \n"
        "     |/                                                                   \n";

	BinaryTree* binaryTree = new BinaryTree;
	Menu(binaryTree);

	delete binaryTree;
}