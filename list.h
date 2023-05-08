//#pragma once
#ifndef __LIST__H
#define __LIST__H

#include "Node.h"
#include <string>

class list
{
public:
	Node* first;   // указатель на первый узел
	Node* last;		// указатель на последний узел

	list();
	bool is_empty();
	void push_front(string book, string group, int grade);
	void push_back(string book, string group, int grade);
	void print_fromBegin();
	void print_fromEnd();
	Node* find(string book);
	void remove_first();
	void remove_last();
	void delete_list();
	void remove(string _book);

};
#endif


