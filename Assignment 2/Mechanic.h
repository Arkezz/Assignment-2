#pragma once
#include<iostream>
#include "Person.h"
#include "Customer.h"
using namespace std;
//Mechanic class declaration
class Mechanic : public Person {
private:
	//Number of appointments
	int counter;
	//Array of appointments
	Appointment appointments[10];
public:
	//Default constructor
	Mechanic();
	//Setters and Getters
	void setCounter(int);
	int getCounter() const;
	void setAppointment(Appointment);
	Appointment getAppointment(int) const;

	//isAvailable function returns true if the mechanic is available at the given time. Takes an Appointment
	bool isAvailable(Appointment) const;

	//printInfo
	void printInfo() const;
};
