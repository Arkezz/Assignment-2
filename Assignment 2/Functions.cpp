#include "Functions.h"
//generatePeople function takes in 2 dynamic arrays and their sizes then generates their values in order
void generatePeople(Customer* customers, int customerSize, Mechanic* mechanics, int mechanicSize) {
	//make 3 appointments
	Appointment a[3];
	a[0].hours = 9;
	a[0].mins = 30;
	a[1].hours = 10;
	a[1].mins = 30;
	a[2].hours = 11;
	a[2].mins = 30;
	for (int i = 0; i < customerSize; i++) {
		customers[i].setName("Customer " + to_string(i + 1));
		customers[i].setID(i + 1);
		customers[i].setAge(rand() % 50 + 18);
		//pick one of the 3 appointments randomly
		int index = rand() % 3;
		customers[i].setAppointment(a[index].hours, a[index].mins);
	}
	for (int i = 0; i < mechanicSize; i++) {
		mechanics[i].setName("Mechanic " + to_string(i + 1));
		mechanics[i].setID(i + 1);
		mechanics[i].setAge(rand() % 50 + 18);
	}
}

//enterPeople function takes in 2 dynamic arrays and their sizes and asks the user to enter their values
void enterPeople(Customer* customers, int customerSize, Mechanic* mechanics, int mechanicSize) {
	//make 3 appointments
	Appointment a[3];
	a[0].hours = 9;
	a[0].mins = 30;
	a[1].hours = 10;
	a[1].mins = 30;
	a[2].hours = 11;
	a[2].mins = 30;
	for (int i = 0; i < customerSize; i++) {
		string name;
		int id;
		int age;
		int hours;
		int mins;
		cout << "Enter Customer " << i + 1 << "'s Name: ";
		cin >> name;
		cout << "Enter Customer " << i + 1 << "'s ID: ";
		cin >> id;
		cout << "Enter Customer " << i + 1 << "'s Age: ";
		cin >> age;
		//Ask the user to pick one of the 3 appointments
		cout << "Enter Customer " << i + 1 << "'s Appointment: " << endl;
		cout << "1. 9:30" << endl;
		cout << "2. 10:30" << endl;
		cout << "3. 11:30" << endl;
		int choice;
		cin >> choice;
		switch (choice) {
		case 1:
			hours = a[0].hours;
			mins = a[0].mins;
			break;
		case 2:
			hours = a[1].hours;
			mins = a[1].mins;
			break;
		case 3:
			hours = a[2].hours;
			mins = a[2].mins;
			break;
		}
		customers[i].setName(name);
		customers[i].setID(id);
		customers[i].setAge(age);
		customers[i].setAppointment(hours, mins);
	}
	for (int i = 0; i < mechanicSize; i++) {
		string name;
		int id;
		int age;
		cout << "Enter Mechanic " << i + 1 << "'s Name: ";
		cin >> name;
		cout << "Enter Mechanic " << i + 1 << "'s ID: ";
		cin >> id;
		cout << "Enter Mechanic " << i + 1 << "'s Age: ";
		cin >> age;
		mechanics[i].setName(name);
		mechanics[i].setID(id);
		mechanics[i].setAge(age);
	}
}