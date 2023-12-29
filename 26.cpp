#include <iostream>
#include <string>
#include <Windows.h>
#include <vector>

using namespace std;

class Date {
public:
    int day;
    int month;
    int year;
    Date(int day, int month, int year) {
        this->day = day;
        this->month = month;
        this->year = year;
    };
    void print() {
        cout << this->day << "." << this->month << "." << this->year << "\n\n";
    };
    void add_month(int length) {
        if (this->month + length > 12) {
            this->year += (this->month + length) / 12;
            this->month = (this->month + length) % 12;
        }
        else {
            this->month += length;
        }
    };
};

class User {
public:
    int id;
    string name;
    int age;
    string gender;
    User(int id, string name, int age, string gender) {
        this->id = id;
        this->name = name;
        this->age = age;
        this->gender = gender;
    };
    void print() {
        cout << "Пользователь: \n" << "\tИмя: " << this->name << "\n\tВозраст: " << this->age << "\n\tПол: " << this->gender << "\n\n";
    };
};

class Tariff {
public:
    int id;
    string name;
    float price;
    int length;
    Tariff(int id, string name, float price, int length) {
        this->id = id;
        this->name = name;
        this->price = price;
        this->length = length;
    };
    void print() {
        cout << "\n\tID: " << this->id << "\n\tНазвание: " << this->name << "\n\tЦена: " << this->price << "\n\tДлительность(в месяцах): " << this->length << "\n\n";
    };
};

vector <Tariff> tariffs = { Tariff(1, "Base", 399 , 1), Tariff(2, "Pro", 499 , 1), Tariff(3, "Vip", 1100 , 2) };

class Subscription {
public:
    int id;
    User* user;
    Tariff* tariff;
    Date* end_date;
    Subscription(int id, User* user, Date* end_date) {
        this->id = id;
        this->user = user;
        int tariff_id;
        cout << "Выбирете подписку(введите id подписки): ";
        for (auto i : tariffs) {
            i.print();
        }
        cin >> tariff_id;
        this->tariff = &(tariffs[tariff_id - 1]);
        this->end_date = end_date;
    };
    void print() {
        cout << "Подписка: \nID: " << this->id << endl;
        cout << "Тариф: " << endl;
        this->tariff->print();
        this->user->print();
        this->end_date->print();
        cout << endl;
    };
    void Extend(int length) {
        this->end_date->add_month(length);
    };
    ~Subscription() {
        cout << "Подписка была удалена!" << endl;
    };
};


int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    User* u1 = new User(1, "Артём", 16, "Мужской");
    Date* d1 = new Date(03, 10, 2023);
    Subscription* s1 = new Subscription(0, u1, d1);
    s1->print();
    s1->Extend(5);
    s1->print();
}