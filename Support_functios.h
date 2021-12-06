#pragma once
#include <iostream>
#include <fstream>
#include "Class.h"

using namespace std;

ostream& operator<< (ostream& out, const List& list)
{
	Node* current = list.head;
	int i = 1;
	if (current == NULL)
	{
		out << "List is Empty!\n";
		return(out);
	}
	else
	{
		while (current != NULL)
		{
			out << i++ << ")" << current->getData() << " ";
			current = current->getNext();
		}
		out << " \n";
		return(out);
	}
}

void completion(List& list, int count)
{
	ifstream in("input.txt");
	ifstream in2("input2.txt");
	char tmp = NULL;
	in.unsetf(ios::skipws);
	in2.unsetf(ios::skipws);
	string data;
	if (count == 1)
	{
		while (!in.eof())
		{
			in >> tmp;
			while (tmp != '\n')
			{
				data += tmp;
				in >> tmp;
				if (in.eof()) break;
			}
			list.add(data);
			data = "";
		}
	}
	else
	{
		while (!in2.eof())
		{
			in2 >> tmp;
			while (tmp != '\n')
			{
				data += tmp;
				in2 >> tmp;
				if (in2.eof()) break;
			}
			list.add(data);
			data = "";
		}
	}
}