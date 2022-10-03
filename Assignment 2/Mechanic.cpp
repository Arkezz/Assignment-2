#include "Mechanic.h"

//Mechanic class implementation
//Default constructor
Mechanic::Mechanic() {
	counter = 0;
	//initialize appointments
	for (int i = 0; i < 10; i++) {
		appointments[i].hours = 0;
		appointments[i].mins = 0;
	}
}

//Setters and Getters
void Mechanic::setCounter(int c) {
	counter = c;
}
int Mechanic::getCounter() const {
	return counter;
}
void Mechanic::setAppointment(Appointment a) {
	appointments[counter] = a;
	counter++;
}
Appointment Mechanic::getAppointment(int i) const {
	return appointments[i];
}

//isAvailable function returns true if the mechanic is available at the given time. Takes an Appointment
bool Mechanic::isAvailable(Appointment a) const {
	for (int i = 0; i < counter; i++) {
		if (appointments[i].hours == a.hours) {
			if (appointments[i].mins == a.mins) {
				return false;
			}
		}
	}
	return true;
}

//printInfo
void Mechanic::printInfo() const {
	cout << "Mechanic: " << getName() << endl;
	cout << "ID: " << getID() << endl;
	cout << "Appointments: " << endl;
	for (int i = 0; i < counter; i++) {
		cout << appointments[i].hours << ":" << appointments[i].mins << endl;
	}
}