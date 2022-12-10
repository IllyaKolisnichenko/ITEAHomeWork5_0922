#include <iostream>
#include <string>
#include <vector>
#include <array>

class Bacterium
{
public:
    Bacterium()
    {
        life = 0.001;
        dna = true;
    };

    void SetName(std::string value) { name = value; }
    std::string GetName() { return name; }

    void SetLife(double value) { life = value; }
    double GetLife() { return life; }

    void SetDNA(bool value) { dna = value; }
    bool GetDNA() { return dna; }

private:
    std::string name;
    double life;
    bool dna; //deoxyribonucleic acid
};

class Plants : public Bacterium
{
public:
    Plants()
    {
        SetLife(100);
        breath = true;
        reproduction = true;
    };

    void SetBreath(bool value) { breath = value; }
    bool GetBreath() { return breath; }

    void SetReproduction(bool value) { reproduction = value; }
    bool GetReproduction() { return reproduction; }

private:
    bool breath;
    bool reproduction;
};

enum ItemSex { Male, Female };

class Animals : public Plants
{
public:
    Animals()
    {
        SetLife(50);
        sex = ItemSex::Female;
        vision = true;
        tail = true;
    };

    void SetSex(ItemSex value) { sex = value; }
    ItemSex GetSex() { return sex; }

    void SetVision(bool value) { vision = value; }
    bool GetVision() { return vision; }

    void SetTail(bool value) { tail = value; }
    bool GetTail() { return tail; }

private:
    ItemSex sex;
    bool vision; 
    bool tail;
};

enum ItemLanguages {
    Ukrainian,
    Orcostanian, 
    English,
    Polish,
    Turkish,
};

class Human :public Animals
{
public:
    Human()
    {
        SetLife(70);
        SetTail(false);
        language = ItemLanguages::Ukrainian;
        intellect = 75;
    };

    void SetLanguage(ItemLanguages value) { language = value; }
    ItemLanguages GetLanguage() { return language; }

    void SetIntellect(int value) { intellect = value; }
    int GetIntellect() { return intellect; }

private:
    ItemLanguages language;
    int intellect; //0..100
};

int main()
{
    Human human;
    human.SetSex(ItemSex::Male);
    human.SetName("Ignat");
    human.SetLanguage(ItemLanguages::Orcostanian);
    human.SetIntellect(0);
    //
    std::cout << "Entity created. Name:" << human.GetName() << std::endl;
    std::string sex = human.GetSex() == ItemSex::Male ? "Male" : "Hemale";
    std::cout << "Sex:" << sex << std::endl;
    
    std::string language;
    switch (human.GetLanguage())
    {
        case Ukrainian: language = "Ukrainian"; 
            break;
        case Orcostanian: language = "Orcostanian"; 
            break;
        case English: language = "English";
            break;
        case Polish: language = "Polish";
            break;
        case Turkish: language = "Turkish";
            break;
    }
    std::cout << "Language:" << language << std::endl;
    std::cout << "IQ:" << human.GetIntellect() << std::endl;
    std::cout << "Tail:" << std::boolalpha << human.GetTail() << std::endl;
    std::cout << "Vision:" << std::boolalpha << human.GetVision() << std::endl;
    std::cout << "DNA:" << std::boolalpha << human.GetDNA() << std::endl << std::endl; 
    //
    std::cout << "Work with pseudoAI. Choise a question (1 or 2) :" << std::endl;
    std::cout << "1. What types of bacteria?" << std::endl;
    std::cout << "2. What is the tallest animal?" << std::endl;
    int user_input;
    std::cin >> user_input;
    switch (user_input)
    {
        case 1:
        {
            std::array<std::string, 4> bact = {"cocci", "spirilla", "vibrios","bacilli"} ;
            for (auto single_bact : bact)
            {
                std::cout << single_bact << " ";
            }
            break;
        }
        case 2:
        {
            std::vector <std::pair<std::string, double>> aninals = { {"dog",0.6},{"cat",0.25},{"giraffe",6},{"elephant",5.2} };
            double growth = 0;
            std::string name_animal;
            for (int i = 0; i < aninals.size(); i++)
            {
                if (aninals[i].second > growth)
                {
                    growth = aninals[i].second;
                    name_animal = aninals[i].first;
                }
            }
            std::cout << "Answer:" << name_animal << std::endl;
            break;
        }
        default: std::cout << "Sorry, you losser ;)" << std::endl;
            break;
    }
}

