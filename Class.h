#pragma once
#include <iostream>

using namespace std;

class Node
{
private:
	string data;
	Node* next;

public:
	Node(string initdata)
	{
		data = initdata;
		next = NULL;
	}

	string getData()
	{
		return data;
	}

	Node* getNext() { return next; }

	void SetData(string newData)
	{
		data = newData;
	}

	void setNext(Node* newnext) { next = newnext; }

};

class List
{
private:
	Node* head;
public:
	List() { head = NULL;}

	bool isEmpty() { return head == NULL; }

	void add(string item)
	{
		Node* temp = new Node(item);
		temp->setNext(head);
		head = temp;
	}

	friend ostream& operator<< (ostream& out, const List& new_List);

	int size()
	{
		Node* current = head;
		int count = 0;

		while (current != NULL)
		{
			count++;
			current = current->getNext();
		}

		return count;
	}

	string at(int index)
	{
		Node* current = head; int i = 0;
		while (current->getNext() != NULL)
		{
			if (i == index) break;
			i++;
			current = current->getNext();
		}
		return current->getData();
	}

	void push_front(string item)
	{
		Node* temp = new Node(item);
		temp->setNext(head);
		head = temp;
	}

	void push_back(string item)
	{
		Node* current = head;
		while (current->getNext() != NULL)
		{
			current = current->getNext();
		}

		Node* temp = new Node(item);
		current->setNext(temp);
		current = temp;
	}

	void insert(string item, int index)
	{
		Node* current = head; int i = 1;
		while (current->getNext() != NULL)
		{
			if (i + 1 == index) break;
			i++;
			current = current->getNext();
		}
		Node* temp = new Node(item);
		temp->setNext(current->getNext());

		current->setNext(temp);
		current = temp;
	}

	void remove(int index)
	{
		Node* current = head; int i = 1;
		Node* previous = NULL;
		bool found = false;
		while (!found)
		{
			if (i == index) found = true;
			else
			{
				previous = current;
				current = current->getNext();
			}
			i++;
		}
		if (previous == NULL) head = current->getNext();
		else previous->setNext(current->getNext());
	}
	void pop_back()
	{
		Node* current = head; int i = 0;
		Node* previous = NULL;
		while (current->getNext() != NULL)
		{
			previous = current;
			current = current->getNext();
		}
		previous->setNext(current->getNext());
	}
	void pop_front()
	{
		Node* current = head;
		head = current->getNext();
	}
	void clear()
	{
		Node* current = head;
		while (current->getNext() != NULL)
		{
			head = current->getNext();
			current = current->getNext();
		}
		head = NULL;
	}
	void set(string item, int index)
	{
		Node* current = head; int i = 1;
		Node* previous = NULL;
		bool found = false;
		while (!found)
		{
			if (i == index) found = true;
			else
			{
				previous = current;
				current = current->getNext();
			}
			i++;
		}
		if (previous == NULL) head = current->getNext();
		else previous->setNext(current->getNext());

		Node* temp = new Node(item);
		temp->setNext(previous->getNext());

		previous->setNext(temp);
		previous = temp;
	}

	int find_first(List side_list)
	{
		Node* current = head; int i = 1; int entry_count, compleat_count{};
		int index = side_list.size();
		bool entry = false, complete_passage = false;
		while (current != NULL)
		{
			if (current->getData() == side_list.at(0))
			{
			    entry = true;
				entry_count = i;
				current = current->getNext();
				i++;
				int j = 1;
				while (j < index)
				{
					if (current->getData() == side_list.at(j)) complete_passage = true;
					else { complete_passage = false;}
					current = current->getNext();
					i++; j++;
				}
				if (entry == true and complete_passage == true) 
				{
					compleat_count = entry_count; break; 
				}
			}
			else 
			{
				current = current->getNext(); i++;
			}
		}
		return compleat_count;
	}
};
