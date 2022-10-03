#include "Person.h"
//Abstract Person class implementation
//Default Constructor
Person::Person() {
	Name = "";
	ID = 0;
	Age = 0;
}

//Setters and Getters
void Person::setName(string name) {
	Name = name;
}
string Person::getName() const {
	return Name;
}
void Person::setID(int id) {
	ID = id;
}
int Person::getID() const {
	return ID;
}
void Person::setAge(int age) {
	Age = age;
}
int Person::getAge() const {
	return Age;
}