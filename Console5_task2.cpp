#include <iostream>
#include <time.h>
#include <string>

class Person {
public:
    enum Item {
        Shield,
        Sword,
        Armor,
        Count
    };

    void getItem() {
        Item item{ static_cast<Item> (rand() % Item::Count) };
        const auto sizeOfItem{ rand() % maxSizeOfItem };

        itemPair = { item, sizeOfItem };
    }

    int getLife() {
        return life;
    }

protected:
    std::pair< Item, int > itemPair;
    int life = 100;
    static constexpr int maxAttack = 10;
    static constexpr int maxSizeOfItem = 10;
};


class Warrior : public Person
{
public:
    Warrior() 
    {
        score_warrior =  (rand() % maxSizeOfItem * 0.8) + 1;
    }

    std::string GetName() { return "warrior"; }

    int attack()
    {
        int addAttack = score_warrior;
        if (itemPair.first == Item::Sword)
            addAttack += itemPair.second;
        return (rand() % maxAttack) + addAttack;
    }

    void takeDamage(int damage)
    {
        if (itemPair.first == Item::Shield || itemPair.first == Item::Armor)
        {
            life -= damage - itemPair.second;
            return;
        }
        life -= damage;
    }
protected:
    int score_warrior;
};


class Magician : public Person
{
public:
    Magician()
    {
        score_magician = (rand() % maxSizeOfItem * 0.8) + 1;
    }

    int attack()
    {
        int addAttack = score_magician;
        if (itemPair.first == Item::Sword)
            addAttack += itemPair.second;
        return (rand() % maxAttack) + addAttack;
    };

    void takeDamage(int damage)
    {
        if (itemPair.first == Item::Shield || itemPair.first == Item::Armor)
        {
            life -= damage - itemPair.second;
            return;
        }
        life -= damage;
    }
protected:
    int score_magician;
};

class WarriorMag : public Warrior, public Magician
{
public:
    WarriorMag(int value)
    {
        Person::life = value;
    }

    void getItem() 
    {
        Item item{ static_cast<Item> (rand() % Item::Count) };
        const auto sizeOfItem{ rand() % maxSizeOfItem };
        Person::itemPair = { item, sizeOfItem };
    }

    int getLife() 
    {
        return Person::life;
    }

    int attack()
    {
        int addAttack = (rand() %  Warrior::score_warrior ) + (rand() % Magician::score_magician);
        //std::cout << addAttack << std::endl;
        if (Person::itemPair.first == Item::Sword)
            addAttack += Person::itemPair.second;
        return (rand() % maxAttack) + addAttack;
    };

    void takeDamage(int damage)
    {
        if (Person::itemPair.first == Item::Shield || Person::itemPair.first == Item::Armor)
        {
            Person::life -= damage - Person::itemPair.second;
            return;
        }

        Person::life -= damage;
    }
};



class Monster : public Person 
{
public:
    Monster(int value)
    {
        life = value;
    };

    int attack()
    {
        return (rand() % maxAttack);
    }

    void takeDamage(int damage)
    {
        if (itemPair.first == Item::Shield || itemPair.first == Item::Armor)
        {
            life -= damage - itemPair.second;
            return;
        }
        life -= damage;
    }
};

int main()
{
    srand(time(nullptr));

    int life_orc, life_monster;
    std::cout << "Input the number of lifes of the orc (50..150)" << std::endl;
    std::cin >> life_orc;
    std::cout << "Input the number of lifes of the monster (100..200)" << std::endl;
    std::cin >> life_monster;
    

    //Warrior orc();    
    //Magician orc();
    WarriorMag orc(life_orc);
    Monster monster(life_monster);

    monster.getItem();
    orc.getItem();

    while (true)
    {
        std::cout << "Orc life:" << orc.getLife() << std::endl;
        std::cout << "Monster life:" << monster.getLife() << std::endl;
        monster.takeDamage(orc.attack());
        if (monster.getLife() <= 0)
        {
            std::cout << "Orc is win!!!";
            return 0;
        }

        orc.takeDamage(monster.attack());
        if (orc.getLife() <= 0)
        {
            std::cout << "Monster is win!!!";
            return 0;
        }
    }
}

