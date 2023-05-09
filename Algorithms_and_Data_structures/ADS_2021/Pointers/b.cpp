// void pointer 

#include <iostream> 

using namespace std;

void print_number(int* numberPTR) {
    cout << *numberPTR << endl;
}

void print_letter(char* letterPTR) {
    cout << *letterPTR << endl;
}

void print(void* ptrr, char type) {
    if (type == 'i') {
        cout << *((int*)ptrr) << endl;
    }   
    else if (type == 'c') {
        cout << *((char*)ptrr) << endl;
    }
}

int main() {

    int number = 5;
    char letter = 'a';

    print_number(&number);
    print_letter(&letter);

    print(&number, 'i');
    print(&letter, 'c');
    return 0;
}