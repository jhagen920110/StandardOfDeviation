// Project2.cpp : Defines the entry point for the console application.
//

#pragma once
#include "stdafx.h"
#include <iostream>
using namespace std;
#include "Node.h"
#include "Dllist.h"
#include <ctime>
using std::time;

int main()
{
	int numOfStudents = 30;
	srand(time(0));
	Node *students[30];
	for (int i = 0; i<numOfStudents; i++)
	{
		students[i] = new Node;
		students[i]->score = 1 + rand() % 100;
	}

	Dllist studentsList;
	studentsList.first = new Node;
	studentsList.insert(students[0], studentsList.first); //inserting first node to first->next
	for (int i = 1; i<numOfStudents; i++)
		studentsList.insert(students[i], students[i - 1]); // inserting rest of nodes in order

	studentsList.display();

	studentsList.listSize();
	cout << "\n";

	int searchScore;
	cout << "What score do you want to search and delete?...";
	cin >> searchScore;
	cout << "\n";

	studentsList.searchDelete(searchScore);
	cout << "\n";

	studentsList.display();

	studentsList.listSize();

	cout << "Mean is: " << studentsList.calculateMean() << '\n';
	cout << "Standard of Deviation is: " << studentsList.calculateSD() << '\n';

	return 0;
}

