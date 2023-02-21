#include <iostream>
#include <string>
#include <map>



class Person{
public:
    enum Item{
        Shield,
        Sword,
        Armor,
        Count
    };

    void getItem(){
        Item item { static_cast< Item > ( rand() % Item::Count ) };
        const auto sizeOfItem{ rand() % maxSizeOfItem };

        itemPair = { item, sizeOfItem };
    }

    int getLife(){
        return life;
    }
    void setLife(int hp) { life = hp; };

protected:
    std::pair< Item, int > itemPair;
    int life = 100;
    static constexpr int maxAttack = 20;

private:
    static constexpr int maxSizeOfItem = 5;
};

class Hero : virtual public Person{
public:


    int attack(bool withSword)
    {
        if (withSword)
        {
            int addAttack{ itemPair.first == Item::Sword ? itemPair.second : 0 };
            return ( rand() % maxAttack ) + addAttack;
        }
        return rand() % maxAttack;
    }

    virtual void takeDamage( int damage )
    {
        if ( itemPair.first == Item::Shield || itemPair.first == Item::Armor )
        {
            life -=  damage - itemPair.second;
            return;
        }

        life -= damage;
    }
};

class Monster : public Person{
public:

    int attack()
    {
        return ( rand() % maxAttack );
    }

    void takeDamage( int damage )
    {
        if ( itemPair.first == Item::Shield || itemPair.first == Item::Armor )
        {
            life -= damage - itemPair.second;
            return;
        }

        life -= damage;
    }
};

class Mage : virtual public Person{
public:
    Mage()
    {
        magicScore = (rand() % maxSizeOfMagic) + 1;
    }

    virtual int attack(bool withSword)
    {
        if (withSword)
        {
            int addAttack{ itemPair.first == Item::Sword ? itemPair.second + magicScore : magicScore };
            return (rand() % maxAttack) + addAttack;
        }
        return rand() % maxAttack;
    }

    void takeDamage( int damage )
    {
        if ( itemPair.first == Item::Shield || itemPair.first == Item::Armor )
        {
            life -= damage - itemPair.second;
            return;
        }

        life -= damage;
    }

protected:
    int magicScore;
    static constexpr int maxSizeOfMagic = 8;
};



class WarriorMage : public Mage, public Hero{
public:

    int attack(bool withSword) override
    {

        if (withSword and withMagic_)
        {
            int addAttack{ itemPair.first == Item::Sword ? itemPair.second + magicScore : magicScore };
            return (rand() % maxAttack) + addAttack;
        }

        else if (withSword and !withMagic_)
        {
            int addAttack{ itemPair.first == Item::Sword ? itemPair.second : magicScore };
            return (rand() % maxAttack) + addAttack;
        }

        else if (!withSword and withMagic_)
            return (rand() % maxAttack) + magicScore;


        return (rand() % maxAttack);
    }


    void takeDamage( int damage ) override
    {
        if ( itemPair.first == Item::Shield || itemPair.first == Item::Armor )
        {
            life -= damage - itemPair.second;
            return;
        }

        life -= damage;
    }


    bool withMagic() { return withMagic_; };

private:
    bool withMagic_ = rand() % 2;
};


void playGame(auto& warrior, Monster& monster, const bool withSwords)
{
    while (true) {
        monster.takeDamage(warrior.attack(withSwords));
        if (monster.getLife() <= 0) {
            std::cout << "\nWarrior is win!!!\n";
            std::cout << "The warrior has " << warrior.getLife() << " HP left\n";

            return;
        }

        warrior.takeDamage(monster.attack());
        if (warrior.getLife() <= 0) {
            std::cout << "\nMonster is win!!!\n";
            std::cout << "The monster has " << monster.getLife() << "HP left\n";
            return;
        }
    }
}

int main() {
    srand(time(nullptr));
    int numOfWarrior;
    int hp;
    std::string tmp;
    bool withSwords;

    Monster monster1;


    while(true)
    {
        std::cout << "battle game 1.0\n\n";
        std::cout << "choose your warrior:\n";

        std::cout << "Type 1 if you want to choose Hero\n";
        std::cout << "Type 2 if you want to choose Mage\n";
        std::cout << "Type 3 if you want to choose Warrior Mage\n";
        std::cin >> numOfWarrior;
        std::cout << "\nBattle with swords? type 'yes'\n";
        std::cin >> tmp;

        tmp == "yes" ? withSwords = true : withSwords = false;

        if (numOfWarrior == 1)
        {
            Hero hero1;
            hero1.getItem();
            std::cout << "\nYour warrior: Hero\n";
            std::cout << "Type HP of your warrior. Default is 100, Max is 120\n";
            std::cin >> hp;
            if (!(hp > 0 and hp <= 120)) hp = 100;

            hero1.setLife(hp);
            monster1.setLife(120);
            playGame(hero1, monster1, withSwords);
        }
        if (numOfWarrior == 2)
        {
            Mage mage1;
            mage1.getItem();
            std::cout << "\nYour warrior: Mage\n";
            std::cout << "Type HP of your warrior. Default is 100, Max is 150\n";
            std::cin >> hp;
            if (!(hp > 0 and hp <= 150)) hp = 100;

            mage1.setLife(hp);
            monster1.setLife(120);
            playGame(mage1, monster1, withSwords);
        }
        if (numOfWarrior == 3)
        {
            WarriorMage warriorMage1;
            warriorMage1.getItem();
            std::cout << "\nYour warrior: Warrior Mage\n";
            std::cout << std::boolalpha << "With magic? " << warriorMage1.withMagic() << std::endl;
            std::cout << "Type HP of your warrior. Default is 100, Max is 200\n";
            std::cin >> hp;
            if (!(hp > 0 and hp <= 200)) hp = 100;

            warriorMage1.setLife(hp);
            monster1.setLife(120);
            playGame(warriorMage1, monster1, withSwords);
        }


        tmp = "";
        std::cout << "\n\nTry again? type 'yes'\n";
        std::cin >> tmp;
        if (tmp != "yes") break;
    }

    return 0;

}

