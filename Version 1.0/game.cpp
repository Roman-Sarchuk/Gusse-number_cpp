#include <iostream>
#include <Windows.h>
#include <ctime>
using namespace std;

int ProtectInput(int min, int max);

void main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    srand(time(NULL));
    int min_numb, max_numb;
    cout << "Ведіть діапазон!\n" << "Min: ";
    cin >> min_numb;
    cout << "Max: ";
    cin >> max_numb;
    int unkwn_numb = rand() % max_numb + min_numb - 1, version;
    cout << "Компютер загадав число від " << min_numb << " до " << max_numb << "!\n\n";

    cout << "Ведіть ціле число у заданому діапазоні!\n";
    while (true) {
        version = ProtectInput(min_numb, max_numb);
        cout << endl;
        if (version == unkwn_numb) {
            cout << "! Вітаю ви відгадали !\n";
            break;
        }
        else {
            cout << "Це не те число. Компютер змінює число!\n\n";
            unkwn_numb = rand() % max_numb + min_numb - 1;
        }
    }
}

int ProtectInput(int min, int max) {
    int numb;
    do {
        cout << "Вашa версія: ";
        cin >> numb;
        if (numb >= min && numb <= max) {
            break;
        } 
        else {
            cout << "Число не в діапазоні: веділь від " << min << " до " << max << "!\n";
        }
    } while (true);
    return numb;
}
