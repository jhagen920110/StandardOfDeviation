#pragma once
#include "stdafx.h"
#include <iostream>
using namespace std;
#include "Node.h"
#include "Dllist.h"

Dllist::Dllist()
{
	Node * first;
	listsize = 0;
}

bool Dllist::empty()
{
	if (listsize == 0)
		return 1;
	else return 0;
}

void Dllist::insert(Node *item, Node * pred)
{
	if ((empty()) && (pred != first))	//if node is empty and user tries to insert not on headnode
		cout << "You are inserting the very first node! Try again\n";
	else
	{
		item->next = pred->next;
		item->prev = pred;
		pred->next = item;
		if (item->next != '\0')
			item->next->prev = item;
		listsize++;
	}
}
void Dllist::erase(Node * pred)
{
	Node *deleteNode = pred->next;
	Node *nextNode = deleteNode->next;
	if (!empty())
	{
		if (pred->next->next == '\0')
			pred->next = '\0';
		else
		{
			pred->next = deleteNode->next;
			nextNode->prev = pred;
			deleteNode->next = '\0';
		}
		listsize--;
	}
}
void Dllist::display()
{
	cout << "Students' scores: \n";
	Node *current;
	current = first->next;
	int temp = listsize;
	while (current != '\0')
	{
		if (temp>0)
		{
			cout << current->score << "\n";
			current = current->next;
			temp--;
		}
	}
	cout << "\n";
}

int Dllist::listSize()
{
	cout << "The # of students: " << listsize << "\n";
	return listsize;
}

void Dllist::searchDelete(int score)
{
	Node *search;
	search = first;
	int find = 0;
	for (int i = 0; i<listsize; i++)
	{
		search = search->next;
		if (score == search->score)
		{
			find = 1;
			char ans;
			cout << "The score exists, Do you want to erase it?" << "\n(Press Y for Yes, others for No)";
			cin >> ans;
			if (!empty() && ans == 'Y')
			{
				if (i == listsize - 1)
					search->prev->next = '\0';
				else
				{
					search->prev->next = search->next;
					search->next->prev = search->prev;
					search->next = '\0';
				}
				listsize--;
				break;
			}
		}
	}
	if (find == 0)
		cout << "The score does not exist" << "\n";
}

double Dllist::calculateMean()
{
	Node *add;
	add = first;
	int sum = 0;
	double ans = 0;
	for (int i = 0; i<listsize; i++)
	{
		add = add->next;
		sum = sum + add->score;
	}
	ans = sum / listsize;
	return ans;

}
double Dllist::calculateSD()
{
	Node *add;
	add = first;
	int sum = 0;
	double mean = 0;
	double ans = 0;
	for (int i = 0; i<listsize; i++)
	{
		add = add->next;
		sum = sum + add->score;
	}
	mean = sum / listsize;

	add = first;
	for (int i = 0; i<listsize; i++)
	{
		add = add->next;
		ans = ans + ((add->score - mean)*(add->score - mean));
	}
	ans = ans / listsize;
	ans = sqrt(ans);

	return ans;

}
