//#pragma once
#ifndef __NODE__H
#define __NODE__H

#include <string>
using std::string;

class Node {
public:
    string book;
    string group;
    int grade;

    Node* next;
    Node* prev;
    Node(string _book, string _group, int _grade);
};
#endif

