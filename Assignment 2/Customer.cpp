#include "Customer.h"
//Customer class implementation

//Default Constructor
Customer::Customer() {
	mechanicID = 0;
	appointment.hours = 0;
	appointment.mins = 0;
}

//Setters and Getters
void Customer::setMechanicID(int id) {
	mechanicID = id;
}
int Customer::getMechanicID() const {
	return mechanicID;
}
void Customer::setAppointment(int hours, int mins) {
	appointment.hours = hours;
	appointment.mins = mins;
}
Appointment Customer::getAppointment() const {
	return appointment;
}

//Overload the <,>,== operators to compare between customers' appointments
bool Customer::operator < (const Customer& c) {
	if (appointment.hours < c.appointment.hours) {
		return true;
	}
	else if (appointment.hours == c.appointment.hours) {
		if (appointment.mins < c.appointment.mins) {
			return true;
		}
	}
	return false;
}
bool Customer::operator > (const Customer& c) {
	if (appointment.hours > c.appointment.hours) {
		return true;
	}
	else if (appointment.hours == c.appointment.hours) {
		if (appointment.mins > c.appointment.mins) {
			return true;
		}
	}
	return false;
}
bool Customer::operator == (const Customer& c) {
	if (appointment.hours == c.appointment.hours && appointment.mins == c.appointment.mins) {
		return true;
	}
	return false;
}

//printInfo function
void Customer::printInfo() const {
	cout << "Customer Name: " << getName() << endl;
	cout << "Customer ID: " << getID() << endl;
	cout << "Customer Age: " << getAge() << endl;
	cout << "Customer's Mechanic ID: " << mechanicID << endl;
	cout << "Customer's Appointment: " << appointment.hours << ":" << appointment.mins << endl;
}