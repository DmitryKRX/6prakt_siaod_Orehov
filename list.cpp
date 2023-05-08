#include "list.h"
#include <iomanip>
#include <iostream>
using namespace std;
list::list() : first(nullptr), last(nullptr) {}   // �����������

bool list::is_empty() {   
    return first == nullptr;
}

void list::push_front(string book, string group, int grade) {    
    Node* p = new Node(book, group, grade);   // �������� ���� � �������� ���������
    if (is_empty()) {
        first = p;
        last = p;
        return;
    }
    p->next = first;         // ����� ��������� �� ����. ������� �� ���������� ������
    first->prev = p;   // ����� ��������� �� ����. ������� � ����������� ������� �������� �� ����� �������
    first = p;               // ����� ������� ���������� ������

}

void list::push_back(string book, string group, int grade) {  
    Node* p = new Node(book, group, grade);       // �������� ���� � �������� ���������
    if (is_empty()) {
        first = p;
        last = p;
        return;
    }
    last->next = p;     // ���������, ��� ����� ���� ����� ����� ���������� ����
    p->prev = last;     // ��������, ��� ����� ����� ��������� ����� ���������� ���������
    last = p;           // ����� ������� ���������� ���������
}

void list::print_fromBegin() {
    if (is_empty()) {   // �������� �� ������� ����� � ������
        cout << "������ ����.\n";
        return;
    }
    int i = 1;
    cout << endl;
    cout << setw(6) << "# | ";
    cout << setw(15) << "���. ������: | ";
    cout << setw(13) << "������: | ";
    cout << setw(8) << "������: ";
    cout << endl;
    Node* p = first;      // ��������� �� ������ ����
    while (p) {          // ���� p != nullptr
        cout << setw(3) << i << " |";
        cout << setw(13) << p->book; cout << " |";
        cout << setw(11) << p->group; cout << " |";
        cout << setw(7) << p->grade;
        cout << endl;
        i++;
        p = p->next;    // ��������� �������� p �� ����. ����
    }
    cout << endl;
}

void list::print_fromEnd() {
    if (is_empty()) {   // �������� �� ������� ����� � ������
        cout << "������ ����.\n";
        return;
    }
    int i = 1;
    cout << endl;
    cout << setw(6) << "# | ";
    cout << setw(15) << "���. ������: | ";
    cout << setw(13) << "������: | ";
    cout << setw(8) << "������: ";
    cout << endl;
    Node* p = last;      // ��������� �� ��������� ����
    while (p) {          // ���� p != nullptr
        cout << setw(3) << i << " |";
        cout << setw(13) << p->book; cout << " |";
        cout << setw(11) << p->group; cout << " |";
        cout << setw(7) << p->grade;
        cout << endl;
        i++;
        p = p->prev;    // ��������� �������� p �� ����. ����
    }
    cout << endl;
}

Node* list::find(string book) {   // ������� ������ ���� �� �����
    Node* p = first;        // ��������� �� ������ ����

    while (p && p->book != book) p = p->next;   // ������� ������, ���� ��������� p �� ������ 
    // � ���� �������� ���� p �� ����� �����                                     
    return (p && p->book == book) ? p : nullptr;   // ���������� ����
}

void list::remove_first() {
    if (is_empty()) {
        cout << "������ ����.\n";
        return;
    }
    Node* p = first;     // ������� ��������� p �� ������ ���� 
    first = p->next;     // ������ ����. ������� ���� �� ����.
    first->prev = nullptr;
    delete p;            // ������� ���� p
}

void list::remove_last() {
    if (is_empty()) {
        cout << "������ ����.\n";
        return;
    }
    if (first == last) {   // ���� � ������ ���� ����
        remove_first();
        return;
    }
    Node* p = last->prev;          // ������� ��������� p �� ������������� ����
    p->next = nullptr;   // ������� ��������� �� ����. ���� � ��������������
    delete last;         // ������� ������ ����
    last = p;          // ��������� ����� ��������� ����
}

void list::delete_list() {
    if (is_empty()) {
        return;
    }
    Node* p = first;
    while (p->next != last) {
        remove_first();
        if (is_empty()) {
            break;
        }
    }
}

void list::remove(string _book) {
    if (is_empty()) {
        cout << "������ ����.\n";
        return;
    }
    if (first->book == _book) { 
        remove_first();       
        return;
    }
    else if (last->book == _book) {   
        remove_last();               
        return;
    }
    Node* p = first;
    while (p && p->book != _book)
        p = p->next;

    if (!p) {
        cout << "��������� ������� �� ������.\n";
        return;
    }
    Node* next = p->next;
    Node* prev = p->prev;

    next->prev = p->prev;
    prev->next = p->next;
    delete p;
}

