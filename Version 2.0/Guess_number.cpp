#include <iostream>
#include <Windows.h>
#include <ctime>
using namespace std;

void logic(int min, int max);
void ClearInput(void);
int InputVers(int min, int max);
int InputRange(char const text[]);


int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    srand(time(NULL));
input:
    cout << "Ведіть діапазон!\n";
    int min_numb = InputRange("Min: "), max_numb= InputRange("Max: ");
    if (max_numb == min_numb) {
        cout << "Min та Max не повині біти рівними!\n\n";
        goto input;
    }
    else if (max_numb < min_numb) {
        cout << "Max не повинен бути більший, ніж Min!\n\n";
        goto input;
    }
    cout << "Компютер загадав число від " << min_numb << " до " << max_numb << "!\n\n";
    logic(min_numb, max_numb);
    system("PAUSE");
}


void logic(int min, int max) {
    int unkwn_numb = rand() % max + min, version;
    cout << "Ведіть ціле число у заданому діапазоні!\n";
    while (true) {
        version = InputVers(min, max);
        cout << endl;
        if (version == unkwn_numb) {
            cout << "! Вітаю ви відгадали !\n\n";
            break;
        }
        cout << "Не вгадали. Компютер змінює число!\n\n";
        unkwn_numb = rand() % max + min - 1;
    }
}

void ClearInput(void) {
    cin.clear();
    cin.ignore(32767, '\n');
}

int InputVers(int min, int max) {
    int numb;
    do {
        cout << "Вашa версія: ";
        cin >> numb;
        if (!cin || numb < min || numb > max) {
            cerr << "Не коректний від: ведіть ціле число від " << min << " до " << max << "!\n\n";
            ClearInput();
            continue;
        }
        ClearInput();
        return numb;
    } while (true);
}

int InputRange(char const text[]) {
    int numb;
    do {
        cout << text;
        cin >> numb;
        if (!cin) {
            cerr << "Не коректний від: ведіть ціле число!\n";
            ClearInput();
            continue;
        }
        ClearInput();
        return numb;
    } while (true);
}
