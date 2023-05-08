
#include <conio.h>
#include <windows.h>
#include <time.h>
#include <iostream>
#include <iomanip>
#include <string>
#include "Node.h"
#include "list.h"
#include "individual_func.cpp"
using namespace std;
 
// вспомогательные средства для интерфейса
HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
COORD CursorPosition;
void setcursor(bool visible, DWORD size) {
    if (size == 0) size = 20;
    CONSOLE_CURSOR_INFO lpCursor;
    lpCursor.bVisible = visible;
    lpCursor.dwSize = size;
    SetConsoleCursorInfo(console, &lpCursor);
}

list manual_input(int len) {
    string book, group;
    int grade;
    list list;
    cout << "Введите " << len << " значений через пробел: \n";
    for (int i = 0; i < len; i++) {
        cin >> book >> group >> grade;
        list.push_back(book, group, grade);
    }
    list.print_fromBegin();
    return list;
}

string GROUP[4] = { "IKBO", "INBO", "IVBO", "IMBO" };
string LETTERS[6] = { "A" , "B", "C", "D", "E", "F" };

list random_input(int len) {
    string book, group, year, group_num;
    list list;
    for (int i = 0; i < len; i++) {
        year = to_string(rand() % 4 + 19);
        group_num = to_string(rand() % 15 + 1);
        if (group_num.length() == 1) group_num = "0" + group_num;
        list.push_back(year + LETTERS[rand() % 6] + to_string(rand() % 2000 + 1000), GROUP[rand() % 4] + "-" + group_num + "-" + year, rand() % 3 + 2 + rand() % 2);
    }

    list.print_fromBegin();
    return list;
}

list create_list() {

    char ch;
    list l;
    cout << "Выберите способ создания списка: \n";
    cout << "\t1. Вручную\n\t2. Автоматически";

    int len;
    while (true) {
        ch = _getch();
        if (ch == '1') {
            system("cls");

            cout << "- - - Ручной ввод - - - \n";
            cout << "Введите размер списка: ";
            cin >> len;
            system("cls");
            cout << "- - - Ручной ввод - - - \n";

            l = manual_input(len);
            break;
        }
        else if (ch == '2') {
            system("cls");

            cout << "- - - Автоматический ввод - - - \n";
            cout << "Введите размер списка: ";
            cin >> len;
            l = random_input(len);
            break;
        }
    }
    return l;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    setcursor(0, 0);
    srand(time(NULL));
    list l; list l1;
    string book, group;
    int grade;
    char ch;
    l = create_list();
    cout << " Инд. операция 1: \n";
    cout << "   Вставить новый узел перед первым узлом с таким же ключом,\n";
    cout << "   если такого узла еще нет, то вставить перед первым узлом,\n";
    cout << "   у которого ключ больше.\n\n";

    cout << " Введите значения элемента списка\n";
    cout << " (Зач. книжка, группа, оценка): ";
    cin >> book >> group >> grade;
    l = remove_by_group(l, group);
    system("cls");
    
    cout << " Инд. операция 1: \n";
    cout << "   Вставить новый узел перед первым узлом с таким же ключом,\n";
    cout << "   если такого узла еще нет, то вставить перед первым узлом,\n";
    cout << "   у которого ключ больше.\n\n";
    cout << " Новый элемент: " << book << " " << group << " " << grade << endl << endl;
    
    cout << " Старый список: \n";
    l.print_fromBegin();
    l = paste_element(l, book, group, grade);
    cout << " Измененный список: \n";
    l.print_fromBegin();

    cout << "\nНажмите любую клавишу, чтобы продолжить.";
    ch = _getch();
    system("cls");
    cout << " Текущий список:\n";
    l.print_fromBegin();
    cout << " Инд. операция  2: \n";
    cout << "   Удалить узлы с указанным номером группы.\n\n";
    cout << "Введите значение номера группы: ";
    cin >> group;
    l = remove_by_group(l, group);
    cout << " Измененный список: \n";
    l.print_fromBegin();
    cout << "\nНажмите любую клавишу, чтобы продолжить.";
    ch = _getch();
    system("cls"); 
    
    cout << " Инд. операция  3: \n";
    cout << "   Сформировать новый список из исходного, включив в него узлы с оценкой неуд,\n";
    cout << "   исключив их при этом из исходного списка.\n\n";
    cout << "Старый список 1:";
    l.print_fromBegin();

    l1 = form_list_grade2(l, l1);
  //  l.push_front("1", "1", 1);
    l = delete_grade2(l);
    cout << "Новый список 1:";
    l.print_fromBegin();
    
    cout << "Новый список 2:";
    l1.print_fromBegin();
    return 0;
}