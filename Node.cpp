#include "Node.h"

Node::Node(string _book, string _group, int _grade) : book(_book), group(_group), grade(_grade), next(nullptr), prev(nullptr) {}