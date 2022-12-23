#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;


class Object {
public:
	virtual void printMsg() = 0;

};

class Cell : public Object {

public:

	void animalPath() {
		cout << "Cell ->";
	}

	int m_age;
	Cell(int age = 0)
		: m_age(age)
	{
	}
	int getAge() const { return m_age; }

};

class Bacterium : public Cell {
public:
	int m_speed;
	void animalPath() {

		Cell::animalPath();
		cout << "Bacterium ->";
	}

	Bacterium(int speed = 0)
		: m_speed(speed)
	{
	}
	int getSpeed() const { return m_speed; }
};

class Fish : public Bacterium {
public:

	float m_weight;

	void animalPath() {

		Bacterium::animalPath();
		cout << "Fish ->";
	}


	virtual void printMsg() {
		cout << "I live in water" << endl;
	}

	Fish(float weight = 0.0)
		: m_weight(weight)
	{
	}
	float getWeight() const { return m_weight; }

};

class Animal : public Fish {
public:
	float m_height;

	void printMsg() override {
		cout << "I live on land" << endl;
	}

	void animalPath() {

		Fish::animalPath();
		cout << "Animal ->";
	}

	Animal(float height = 0.0)
		: m_height(height)
	{
	}
	float getHeight() const { return m_height; }

};

class Human : public Animal {
private:

	string question;
	string array_of_age[5] { "19", "66", "35", "5", "43" };
	string array_of_names[4] { "Aleksandra", "Stepan", "Artem", "Maksim" };
	string array_of_towns[6] { "Lviv", "Berlin", "Chernobl", "Odessa", "London", "Dnepr" };

public:

	void printMsg(Object* object) {
		object->printMsg();
	}

	void printMsg() override {
		cout << "I can speak" << endl;
	}

	void animalPath() {
		Animal::animalPath();
		cout << "Human ->";
	}

	void askQuestion() {

		cout << "Input your question:" << endl;
		getline(cin, question);
		
		cout << endl;
		printAnswer();
		askQuestion();
	};



	void printAnswer() {

		if (question == "How old are you?") {
			cout << "I`m " << findRandomArrayAnswer(array_of_age, 5) << " years old"<< endl;
			return;
		}

		if (question == "What is your name?") {
			cout << "My name is " << findRandomArrayAnswer(array_of_names, 4) << endl;
			return;
		}

		if (question == "Where do you live?") {
			cout << "I live in " << findRandomArrayAnswer(array_of_towns, 6) << endl;
			return;
		}

		else cout << "Invalid data! Try again" << endl;

	};

	string findRandomArrayAnswer(string array[], int size) {

		srand(time(NULL));
		int random_position = rand() % size;
		return array[random_position];
	};

};
int main() {

	Human oleg;

	oleg.askQuestion();

	return 0;
};
