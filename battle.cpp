#include <iostream>
#include <string>

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

protected:
    std::pair< Item, int > itemPair;
    int life = 100;
    static constexpr int maxAttack = 10;

private:
    static constexpr int maxSizeOfItem = 10;
};

class Hero : public Person{
public:
    int attack()
    {
        int addAttack{ itemPair.first == Item::Sword ? itemPair.second : 0 };
        return ( rand() % maxAttack ) + addAttack;
    }

    void takeDamage( int damage )
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

int main()
{
    srand( time(nullptr ) );

    Hero hero;
    Monster monster;

    hero.getItem();
    monster.getItem();

    while (true)
    {
        monster.takeDamage( hero.attack() );
        if( monster.getLife() <=0 )
        {
            std::cout << "Hero is win!!!";
            return 0;
        }

        hero.takeDamage( monster.attack() );
        if( hero.getLife() <=0 )
        {
            std::cout << "Monster is win!!!";
            return 0;
        }
    }

    return 0;
}