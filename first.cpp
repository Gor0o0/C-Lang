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

int CalculateDamage(int baseDamage, float multiplier, int armor)
{
    float multup = baseDamage * multiplier;
    float armor = multup - armor;
    if (armor < 0.0f)
    {
        armor = 0.0f;
    }
    return static_cast<int>(round(armor));
}
int main()
{
    CharacterStats oleg{"oleg", 50, 100, 20};
    PrintPlayer(oleg);
    int playerHP = 50;
    int maxHP = 100;
    
    HealByPointer(&playerHP, 50, maxHP);// Передаем адрес player hp через оператор &

    cout << "playerHP" << ":" << playerHP << endl;
    // &playerHp - это адрес переменной
    // hp* - это указатель на значение по этому адресу
    
    float critM = 1.5f;
    int baseDamage = 40;     
    int armorHis = 20;      
    int finale = CalculateDamage(baseDamage, critM, armorHis);

    cout << "Final Damage: " << finale << endl;

    return 0;
}
