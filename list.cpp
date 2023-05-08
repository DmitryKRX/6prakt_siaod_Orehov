#include "list.h"
#include <iomanip>
#include <iostream>
using namespace std;
list::list() : first(nullptr), last(nullptr) {}   // конструктор

bool list::is_empty() {   
    return first == nullptr;
}

void list::push_front(string book, string group, int grade) {    
    Node* p = new Node(book, group, grade);   // создание узла с заданным значением
    if (is_empty()) {
        first = p;
        last = p;
        return;
    }
    p->next = first;         // смена указателя на след. элемент на предыдущий первый
    first->prev = p;   // смена указателя на пред. элемент у предыдущего первого элемента на новый элемент
    first = p;               // новый элемент становится первым

}

void list::push_back(string book, string group, int grade) {  
    Node* p = new Node(book, group, grade);       // создание узла с заданным значением
    if (is_empty()) {
        first = p;
        last = p;
        return;
    }
    last->next = p;     // указываем, что новый узел стоит после последнего узла
    p->prev = last;     // указывем, что перед новым элементом стоит предыдущий последний
    last = p;           // новый элемент становится последним
}

void list::print_fromBegin() {
    if (is_empty()) {   // проверка на наличие узлов в списке
        cout << "Список пуст.\n";
        return;
    }
    int i = 1;
    cout << endl;
    cout << setw(6) << "# | ";
    cout << setw(15) << "Зач. книжка: | ";
    cout << setw(13) << "Группа: | ";
    cout << setw(8) << "Оценка: ";
    cout << endl;
    Node* p = first;      // указатель на первый узел
    while (p) {          // пока p != nullptr
        cout << setw(3) << i << " |";
        cout << setw(13) << p->book; cout << " |";
        cout << setw(11) << p->group; cout << " |";
        cout << setw(7) << p->grade;
        cout << endl;
        i++;
        p = p->next;    // обновляем значение p на след. узел
    }
    cout << endl;
}

void list::print_fromEnd() {
    if (is_empty()) {   // проверка на наличие узлов в списке
        cout << "Список пуст.\n";
        return;
    }
    int i = 1;
    cout << endl;
    cout << setw(6) << "# | ";
    cout << setw(15) << "Зач. книжка: | ";
    cout << setw(13) << "Группа: | ";
    cout << setw(8) << "Оценка: ";
    cout << endl;
    Node* p = last;      // указатель на последний узел
    while (p) {          // пока p != nullptr
        cout << setw(3) << i << " |";
        cout << setw(13) << p->book; cout << " |";
        cout << setw(11) << p->group; cout << " |";
        cout << setw(7) << p->grade;
        cout << endl;
        i++;
        p = p->prev;    // обновляем значение p на пред. узел
    }
    cout << endl;
}

Node* list::find(string book) {   // функция поиска узла по ключу
    Node* p = first;        // указатель на первый узел

    while (p && p->book != book) p = p->next;   // обходим список, пока указатель p не пустой 
    // и пока значение узла p не равно ключу                                     
    return (p && p->book == book) ? p : nullptr;   // возвращаем узел
}

void list::remove_first() {
    if (is_empty()) {
        cout << "Список пуст.\n";
        return;
    }
    Node* p = first;     // создаем указатель p на первый узел 
    first = p->next;     // меняем знач. первого узла на след.
    first->prev = nullptr;
    delete p;            // удаляем узел p
}

void list::remove_last() {
    if (is_empty()) {
        cout << "Список пуст.\n";
        return;
    }
    if (first == last) {   // если в списке один узел
        remove_first();
        return;
    }
    Node* p = last->prev;          // создаем указатель p на предпоследний узел
    p->next = nullptr;   // удаляем указатель на след. узел у предпоследнего
    delete last;         // удаляем старый узел
    last = p;          // обновляем новый последний узел
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
        cout << "Список пуст.\n";
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
        cout << "Указанный элемент не найден.\n";
        return;
    }
    Node* next = p->next;
    Node* prev = p->prev;

    next->prev = p->prev;
    prev->next = p->next;
    delete p;
}

