#pragma once
#include<iostream>
#include "Person.h"
using namespace std;
//Customer class declaration
class Customer : public Person {
private:
	int mechanicID;
	Appointment appointment;
public:
	//Default Constructor
	Customer();

	//Setters and Getters
	void setMechanicID(int id);
	int getMechanicID() const;
	void setAppointment(int hours, int mins);
	Appointment getAppointment() const;

	//Overload the <,>,== operators to compare between customers' appointments
	bool operator < (const Customer& c);
	bool operator > (const Customer& c);
	bool operator == (const Customer& c);

	//printInfo function
	virtual void printInfo() const;
};
