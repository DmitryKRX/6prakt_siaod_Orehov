#include "list.h"
#include <iostream>
using namespace std;

inline int cardNumber(string line) {
    string number;
    short i = 0;
    while (i < line.length()) {
        if (isdigit(line[i]))
            number += line[i];
        else {
            number += (to_string(int(line[i])));
        }
        i++;
    }
    return stoi(number);
}

inline list paste_element(list l, string _book, string _group, int _grade) {
    if (l.first->book == _book) {
        l.push_front(_book, _group, _grade);
        return l;
    }
  
    Node* p = new Node(_book, _group, _grade);
    Node* elem = l.find(_book);
    if (elem) {
		elem->prev->next = p;
		p->prev = elem->prev;
		elem->prev = p;
		p->next = elem;
        return l;
	}

    int paste_num = cardNumber(_book);
    if (cardNumber(l.first->book) >= paste_num) {
        l.push_front(_book, _group, _grade);
        return l;
    }
    elem = l.first;
    while (elem) {
        if (cardNumber(elem->book) > paste_num) {
            elem->prev->next = p;
            p->prev = elem->prev;
            elem->prev = p;
            p->next = elem;
            return l;
        }
        elem = elem->next;
    }
    cout << "\n Элемент не вставлен.\n";
    return l;
}
    
inline list del(list l, Node* p, string _group) {
    while (p) {
        if (p->group == _group) {         
            Node* next = p->next;
            Node* prev = p->prev;
            next->prev = p->prev;
            prev->next = p->next; 
            delete p;
            del(l, next, _group);
            break;
        }
        p = p->next;
    }
    return l;
}

inline list remove_by_group(list l, string _group) {
    if (l.is_empty()) {
        cout << "Список пуст.\n";
        return l;
    }
    bool isDeleted = false;
    while (_group == l.first->group) {
        l.remove_first();
    }
    while (_group == l.last->group) {
        l.remove_last();
    }
    
    Node* p = l.first;
    while (p) {
        if (p->group == _group) {
            del(l, p, _group);
            break;
        }
        p = p->next;
    }
    return l;
}

inline list delete_grade2(list l) {
    l.push_front("1", "1", 1);
    Node* p = l.first;
    while (p) {
        Node* next = p->next;
        if (p->grade == 2) {
            Node* prev = p->prev;
            if (prev)
                prev->next = next;
            if (next)
                next->prev = prev;
            delete p;
            Node* p = next;
        }
        p = next;
    }
    l.remove_first();
    return l;
}

inline list form_list_grade2(list l, list l2) {
    Node* p = l.first;
    while (p) {     
        if (p->grade == 2) {
            l2.push_back(p->book, p->group, 2);
        }
        p = p->next;
    }
    return l2;
}
