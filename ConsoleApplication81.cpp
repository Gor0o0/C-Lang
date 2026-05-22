#include <iostream>
using namespace std;

// передача параметров функций
// передача по значению
void TakeDamage(int hp, int damage) {
    hp = hp - damage;
}

// здесь hp копируется
//Если вызвать
//int playerHp = 100;
//TakeDamage(playerHp, 30);
// To playerHp остаётся 100

struct CharacterStats {
    string name;
    int hp;
    int maxHp;
    int damage;
};

// Передача по ссылке
//void TakeDamage(int& hp, int damage) {
//    hp = hp - damage;
//}
// int& hp означает:
// hp - это ссылка на оригинальную переменную

//Передача по const-ссылке
// Подходит когда объекты передаются большими но функция не должна их менять
void PrintPlayer(const CharacterStats& statas) {
    cout << stats.name << endl;
    cout << stats.hp << " / " << stats.maxHp << endl;
    cout << stats.damage << endl;
};
// const - запрещает менять объект
// & - позволяет не копировать объект

//Передача через укаатель
// Указатель похож на ссылку, но он может быть пустым(nullptr)
// null ptr - pointer \ указатель
void Heal(int* hp, int amout);
//Функция принимает адрес переменной 

void HealByPointer(int* hp, int amount, int maxHp) {
    if (hp == nullptr) { // проверяем не пустой ли указатель(найденый адрес)
        return;
    }

    *hp = *hp + amount; // Разыменование указателя 9меняем оригинальное значение)

    if (*hp > maxHp) {
        *hp = maxHp;
    }
}

// Задание:

int main()
{
    CharacterStats oleg{ "Oleg", 80, 100, 20 };
    PrintPlayer(oleg);

    int playerHp = 50;
    int maxHp = 100;

    HealByPointer(&playerHp, 50, maxHp); // педаём адрес  playerHp через оператора &

    cout << "Player hp: " << playerHp << endl;

    return 0;
}
