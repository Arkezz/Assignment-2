#include <iostream>
#include <fstream>
#include <string>
#include "Person.h"
#include "Customer.h"
#include "Mechanic.h"
#include "Queue.h"
#include "Functions.h"
using namespace std;

int main() {
	//Random seed
	srand((unsigned int)time(NULL));

	//Choose whether to manually enter the information or generate it randomly or read it from a file
	int choice;
	cout << "Enter 1 to manually enter the information, 2 to generate it randomly, 3 to read it from a file: ";
	cin >> choice;
	//Validate the input
	while (choice < 1 || choice > 3) {
		cout << "Invalid input, please enter a number between 1 and 3: ";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cin >> choice;
	}

	//use the choice to determine what to do using a switch statement
	switch (choice) {
	case 1: {
		//Ask the user to enter the number of customers and mechanics
		int numCustomers, numMechanics;
		cout << "Enter the number of customers: ";
		cin >> numCustomers;
		//Validate the input
		while (numCustomers < 1) {
			cout << "Invalid input, please enter a number greater than 0: ";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cin >> numCustomers;
		}
		cout << "Enter the number of mechanics: ";
		cin >> numMechanics;
		//Validate the input
		while (numMechanics < 1) {
			cout << "Invalid input, please enter a number greater than 0: ";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cin >> numMechanics;
		}

		//enterPeople
		Customer* customers = new Customer[numCustomers];
		Mechanic* mechanics = new Mechanic[numMechanics];
		enterPeople(customers, numCustomers, mechanics, numMechanics);

		//assign customer 1 mechanic 1 check whether the mechanic isAvailabe if not assign the next mechanic
		//The system chooses the first mechanic available in the appointment time chosen by the customer and assigns this mechanicID to the customer
		//assign
		for (int i = 0; i < numCustomers; i++) {
			for (int j = 0; j < numMechanics; j++) {
				if (mechanics[j].isAvailable(customers[i].getAppointment())) {
					customers[i].setMechanicID(mechanics[j].getID());
					//add the appointment to the mechanic
					mechanics[j].setAppointment(customers[i].getAppointment());
					break;
				}
			}
		}

		//the customer with an earlier appointment is stored at the beginning of the queue and the customer with the latest appointment is stored at the end.
		//using a bubble sort to sort the customers by appointment time
		for (int i = 0; i < numCustomers - 1; i++) {
			for (int j = 0; j < numCustomers - i - 1; j++) {
				if (customers[j] > customers[j + 1]) {
					Customer temp = customers[j];
					customers[j] = customers[j + 1];
					customers[j + 1] = temp;
				}
			}
		}
		Queue<Customer> queue;
		for (int i = 0; i < numCustomers; i++) {
			queue.push(customers[i]);
		}

		//print the info of the customers and mechanics
		cout << "Customers: " << endl;
		for (int i = 0; i < numCustomers; i++) {
			customers[i].printInfo();
			cout << endl;
		}
		cout << "Mechanics: " << endl;
		for (int i = 0; i < numMechanics; i++) {
			mechanics[i].printInfo();
			cout << endl;
		}
		break;
	}
	case 2: {
		//Ask the user to enter the number of customers and mechanics
		int numCustomers, numMechanics;
		cout << "Enter the number of customers: ";
		cin >> numCustomers;
		//Validate the input
		while (numCustomers < 1) {
			cout << "Invalid input, please enter a number greater than 0: ";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cin >> numCustomers;
		}
		cout << "Enter the number of mechanics: ";
		cin >> numMechanics;
		//Validate the input
		while (numMechanics < 1) {
			cout << "Invalid input, please enter a number greater than 0: ";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cin >> numMechanics;
		}

		//Generatepeople
		Customer* customers = new Customer[numCustomers];
		Mechanic* mechanics = new Mechanic[numMechanics];
		generatePeople(customers, numCustomers, mechanics, numMechanics);

		//assign customer 1 mechanic 1 check whether the mechanic isAvailabe if not assign the next mechanic
		//The system chooses the first mechanic available in the appointment time chosen by the customer and assigns this mechanicID to the customer
		//assign
		for (int i = 0; i < numCustomers; i++) {
			for (int j = 0; j < numMechanics; j++) {
				if (mechanics[j].isAvailable(customers[i].getAppointment())) {
					customers[i].setMechanicID(mechanics[j].getID());
					//add the appointment to the mechanic
					mechanics[j].setAppointment(customers[i].getAppointment());
					break;
				}
			}
		}

		//the customer with an earlier appointment is stored at the beginning of the queue and the customer with the latest appointment is stored at the end.
		//using a bubble sort to sort the customers by appointment time
		for (int i = 0; i < numCustomers - 1; i++) {
			for (int j = 0; j < numCustomers - i - 1; j++) {
				if (customers[j] > customers[j + 1]) {
					Customer temp = customers[j];
					customers[j] = customers[j + 1];
					customers[j + 1] = temp;
				}
			}
		}
		Queue<Customer> queue;
		for (int i = 0; i < numCustomers; i++) {
			queue.push(customers[i]);
		}

		//print the info of the customers and mechanics
		cout << "Customers: " << endl;
		for (int i = 0; i < numCustomers; i++) {
			customers[i].printInfo();
			cout << endl;
		}
		cout << "Mechanics: " << endl;
		for (int i = 0; i < numMechanics; i++) {
			mechanics[i].printInfo();
			cout << endl;
		}
		break;
	}
	case 3: {
		//open mechanics.txt
		ifstream mechanicsFile("mechanics.txt");
		//check if the file is open
		if (!mechanicsFile.is_open()) {
			cout << "Error opening the file" << endl;
			return 0;
		}

		break;
	}
	}
}