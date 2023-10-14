#include <iostream>
#include <vector>

using namespace std;

// Добавить в уже существующий класс String конструктор переноса.

class String {
    vector<char> string;

public:

    String() {}

    String& operator=(const String& other) {
        if (this != &other) {
            string = other.string;
        }
        return *this;
    }

    String(String&& other) noexcept : string(move(other.string)) {}

    void get() {
        char str[20] = "";

        cout << "Enter String: ";
        cin >> str;
        
        for (char c : str)
        {
            string.push_back(c);
        }
 
    }

    void print() {
        for (auto c : string)
        {
            cout << c;
        }
        cout << "\n";
    }
};

int main()
{
    String string1, string2;
    int choice;
    bool work = true;


    while (work) {
        cout << "\n1) Set Strings\n2) Copy string\n0) Exit\n";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Set String 1: ";
            string1.get();

            cout << "Set String 2: ";
            string2.get();

            cout << "String 1: ";
            string1.print();

            cout << "String 2: ";
            string2.print();

            break;
        case 2:
            string2 = string1;
            
            cout << "String 1: ";
            string1.print();

            cout << "String 2: ";
            string2.print();

            break;
        case 0:
            work = false;
            break;
        default:
            cout << "Wrong input";
            break;
        }
    }

}
