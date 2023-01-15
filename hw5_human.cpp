#include <iostream>
#include <array>
#include <string>
using namespace std;
string stage;


class Cell
{
public:
    string array_of_name_cell[5]{ "Stem cell", "Red blood cell", "Nerve cells", "Muscle cell",
        "Cartillage cell" };
    int array_of_age_cell[5]{ 1, 2, 3, 4, 5 };


    int lifetime;

    Cell()
    {
        lifetime = 1000;
    };

    ~Cell(){};
};

class Bacterium : public Cell
{

public:
    string array_of_name_bacterium[5]{ "Bacillus", "Staphylococcus", "Helicobacter", "Spirillum",
        "Strepticoccus" };
    int array_of_age_bacterium[5]{ 10, 20, 30, 40, 50 };


    float size;

    Bacterium()
    {
        lifetime = 10000;
        size = 0.001;
    };

    ~Bacterium(){};
};

class Monkey : public Bacterium
{

public:
    string array_of_name_monkey[5]{ "Loco", "Goffy", "Hector", "Nutty", "Bonker" };
    int array_of_age_monkey[5]{ 100, 200, 300, 400, 500 };


    string male[2] = { "female,male" };

    Monkey()
    {
        lifetime = 100000;
        size = 100;
    }

    ~Monkey(){};
};

class Human : public Monkey
{

public:
    string randomOptionStr(string array[], int size)
    {

        srand(time(NULL));
        int random_position = rand() % size;
        return array[random_position];
    };

    int randomOptionInt(int array[], int size)
    {

        srand(time(NULL));
        int random_position = rand() % size;
        return array[random_position];
    };

    void findName(string array[], int size)
    {

        cout << "Name: " << randomOptionStr(array, size) << endl;
    }

    void findAge(int array[], int size)
    {

        cout << "Age: " << randomOptionInt(array, size) << endl;
    }


    void showStage()
    {

        if (stage == "Cell")
        {
            cout << "Options:" << endl;
            cout << "Name - print (1)" << endl << "Age - print (2)" << endl;
            int option;
            cout << "Choose option: ";
            cin >> option;
            switch (option)
            {
                case 1:

                    findName(array_of_name_cell, 5);
                    break;
                case 2:
                    findAge(array_of_age_cell, 5);
            }
            return;
        }

        if (stage == "Bacterium")
        {
            cout << "Options:" << endl;
            cout << "Name - print (1)" << endl << "Age - print (2)" << endl;
            int option;
            cout << "Choose option: ";
            cin >> option;
            switch (option)
            {
                case 1:

                    findName(array_of_name_bacterium, 5);
                    break;
                case 2:
                    findAge(array_of_age_bacterium, 5);
            }
            return;
        }

        if (stage == "Monkey")
        {
            cout << "Options:" << endl;
            cout << "Name - print (1)" << endl << "Age - print (2)" << endl;
            int option;
            cout << "Choose option: ";
            cin >> option;
            switch (option)
            {
                case 1:

                    findName(array_of_name_monkey, 5);
                    break;
                case 2:
                    findAge(array_of_age_monkey, 5);
            }
            return;
        }

        if (stage == "Human")
        {
            cout << "Options:" << endl;
            cout << "Name - print (1)" << endl << "Age - print (2)" << endl;
            int option;
            cout << "Choose option: ";
            cin >> option;
            switch (option)
            {
                case 1:

                    findName(array_of_name_human, 5);
                    break;
                case 2:
                    findAge(array_of_age_human, 5);
            }
            return;
        }

        else
            cout << "Invalid stage! Check and try again" << endl;
    };

    void ChooseStage()
    {

        cout << "Input stage: ";
        getline(cin, stage);

        cout << endl;
        showStage();
    };

    string array_of_name_human[5]{ "Oleg", "David", "Max", "Dima", "Jassy" };
    int array_of_age_human[5]{ 1000, 2000, 3000, 4000, 5000 };

    Human()
    {
        lifetime = 1000000;
        size = 1000;
    }

    ~Human(){};
};

int main()
{
    cout << "Stages of evolution: " << endl;
    cout << "1 - Cell" << endl
         << "2 - Bacterium" << endl
         << "3 - Monkey" << endl
         << "4 - Human" << endl;
    Human human;
    human.ChooseStage();
    return 0;
};



