#pragma once
#include<iostream>
using namespace std;
//Abstract Person class declaration
class Person {
private:
	string Name;
	int ID;
	int Age;
public:
	//Default Constructor
	Person();

	//Setters and Getters
	void setName(string name);
	string getName() const;
	void setID(int id);
	int getID() const;
	void setAge(int age);
	int getAge() const;
	//Pure virtual function that will be implemented in the derived classes
	virtual void printInfo() const = 0;
};
//Struct Appointment declaration
struct Appointment {
	int hours;
	int mins;
};