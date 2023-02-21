#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>


class LivingThing {
protected:
    std::string m_type;
    int m_size;
    std::string m_color;
    int m_age;
public:
    LivingThing()
            : m_type(""), m_size(0), m_color(""), m_age(0) {}
    LivingThing(const std::string& type, int size, const std::string& color, int age)
            : m_type(type), m_size(size), m_color(color), m_age(age) {}

    const std::string& getType() const { return m_type; }
    int getSize() const { return m_size; }
    const std::string& getColor() const { return m_color; }
    int getAge() const { return m_age; }

    void setType(const std::string& type) { m_type = type; }
    void setSize(int size) { m_size = size; }
    void setColor(const std::string& color) { m_color = color; }
    void setAge(int age) { m_age = age; }

    virtual void printInfo() const {
        std::cout << "Type: " << m_type << std::endl;
        std::cout << "Size: " << m_size << std::endl;
        std::cout << "Color: " << m_color << std::endl;
        std::cout << "Age: " << m_age << std::endl;
    }
};

class Bacterium : public LivingThing {
public:
    Bacterium() : LivingThing() { setType("Bacterium"); }

    Bacterium(const std::string& type, int size, const std::string& color, int age)
            : LivingThing(type, size, color, age) {}

    void printInfo() const override {
        LivingThing::printInfo();
        std::cout << "This is a bacterium" << std::endl;
    }
};

class Multicellular : public LivingThing {
protected:
    int m_numCells;

public:

    Multicellular() : LivingThing(), m_numCells(0) {}

    Multicellular(const std::string& type, int size, const std::string& color, int age, int numCells)
            : LivingThing(type, size, color, age), m_numCells(numCells) {}

    int getNumCells() const { return m_numCells; }

    void setNumCells(int numCells) { m_numCells = numCells; }
};

class Human : public Multicellular {
private:
    std::string m_name;   // Имя
    std::string m_gender; // Пол

public:

    void setName(const std::string& name) {m_name = name;};
    void setGender(const std::string& gender) {m_gender = gender;};


    void interact() {
        std::cout << "Hello! My name is " << m_name << ". What would you like to know?" << std::endl;

        while (true) {
            std::cout << "> ";
            std::string question;
            getline(std::cin, question);

            std::string response;
            if (question.find("name") != std::string::npos) {
                response = "My name is " + m_name + ".";
            }
            else if (question.find("gender") != std::string::npos) {
                response = "I am " + m_gender + ".";
            }
            else if (question.find("age") != std::string::npos) {
                response = "I am " + std::to_string(m_age) + " years old.";
            }
            else if (question.find("size") != std::string::npos) {
                response = "I am " + std::to_string(m_size) + " cm tall.";
            }
            else if (question.find("num cells") != std::string::npos) {
                response = "I have " + std::to_string(m_numCells) + " cells.";
            }
            else if (question.find("type") != std::string::npos) {
                response = "I am a " + m_type + ".";
            }
            else if (question.find("color") != std::string::npos) {
                response = "I am " + m_color + ".";
            }
            else if (question.find("goodbye") != std::string::npos) {
                response = "Goodbye!";
                break;
            }
            else {
                response = "I don`t know your question!";
            }

            std::cout << response << std::endl;
        }
    }
};

int main() {
    srand(time(0));

    Human human;

    human.setName("Kristina");
    human.setGender("female");
    human.setAge(17);
    human.setSize(170);
    human.setColor("White");
    human.setNumCells(1000000000);

    human.interact();

    return 0;
}