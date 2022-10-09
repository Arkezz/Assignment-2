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

		//If theres noone free send a message to cancel the appointment else print the info of the customer and his assigned mechanic use the queue class
		for (int i = 0; i < numCustomers; i++) {
			if (queue.Front().getMechanicID() == 0) {
				cout << "No mechanic available for customer " << queue.Front().getName() << " at " << queue.Front().getAppointment().hours << ":" << queue.Front().getAppointment().mins << endl;
				cout << endl;
				queue.pop();
			}
			else {
				//ex:Mr. Ahmed has an appointment at 1:00. with Ayman
				cout << queue.Front().getName() << " has an appointment at " << queue.Front().getAppointment().hours << ":" << queue.Front().getAppointment().mins << " with " << mechanics[queue.Front().getMechanicID() - 1].getName() << endl;
				cout << endl;
				queue.pop();
			}
		}
		//Open file customers.txt
		ofstream customersFile;
		customersFile.open("customers.txt");
		//Check that the file is open
		if (!customersFile.is_open()) {
			cout << "Error opening file" << endl;
			return 0;
		}
		//Write the info of the customers to the file simmilar to the printInfo function
		customersFile << numCustomers << endl;
		for (int i = 0; i < numCustomers; i++) {
			customersFile << customers[i].getName() << endl;
			customersFile << customers[i].getID() << endl;
			customersFile << customers[i].getAppointment().hours << endl;
			customersFile << customers[i].getAppointment().mins << endl;
			customersFile << customers[i].getMechanicID() << endl;
		}
		//Close the file
		customersFile.close();
		//Do the same for mechanics.txt
		ofstream mechanicsFile;
		mechanicsFile.open("mechanics.txt");
		if (!mechanicsFile.is_open()) {
			cout << "Error opening file" << endl;
			return 0;
		}
		mechanicsFile << numMechanics << endl;
		for (int i = 0; i < numMechanics; i++) {
			mechanicsFile << mechanics[i].getName() << endl;
			mechanicsFile << mechanics[i].getID() << endl;
			mechanicsFile << mechanics[i].getAge() << endl;
			//Number of appointments
			mechanicsFile << mechanics[i].getCounter() << endl;
			//Appointments
			for (int j = 0; j < mechanics[i].getCounter(); j++) {
				mechanicsFile << mechanics[i].getAppointment(j).hours << endl;
				mechanicsFile << mechanics[i].getAppointment(j).mins << endl;
			}
		}
		//Close the file
		mechanicsFile.close();
		//Delete anything taking up memory
		delete[] customers;
		delete[] mechanics;
		break;
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

		//If theres noone free send a message to cancel the appointment else print the info of the customer and his assigned mechanic use the queue class
		for (int i = 0; i < numCustomers; i++) {
			if (queue.Front().getMechanicID() == 0) {
				cout << "No mechanic available for customer " << queue.Front().getName() << " at " << queue.Front().getAppointment().hours << ":" << queue.Front().getAppointment().mins << endl;
				cout << endl;
				queue.pop();
			}
			else {
				//ex:Mr. Ahmed has an appointment at 1:00. with Ayman
				cout << queue.Front().getName() << " has an appointment at " << queue.Front().getAppointment().hours << ":" << queue.Front().getAppointment().mins << " with " << mechanics[queue.Front().getMechanicID() - 1].getName() << endl;
				cout << endl;
				queue.pop();
			}
		}

		//Open file customers.txt
		ofstream customersFile;
		customersFile.open("customers.txt");
		//Check that the file is open
		if (!customersFile.is_open()) {
			cout << "Error opening file" << endl;
			return 0;
		}
		//Write the info of the customers to the file simmilar to the printInfo function
		customersFile << numCustomers << endl;
		for (int i = 0; i < numCustomers; i++) {
			customersFile << customers[i].getName() << endl;
			customersFile << customers[i].getID() << endl;
			customersFile << customers[i].getAppointment().hours << endl;
			customersFile << customers[i].getAppointment().mins << endl;
			customersFile << customers[i].getMechanicID() << endl;
		}
		//Close the file
		customersFile.close();
		//Do the same for mechanics.txt
		ofstream mechanicsFile;
		mechanicsFile.open("mechanics.txt");
		if (!mechanicsFile.is_open()) {
			cout << "Error opening file" << endl;
			return 0;
		}
		mechanicsFile << numMechanics << endl;
		for (int i = 0; i < numMechanics; i++) {
			mechanicsFile << mechanics[i].getName() << endl;
			mechanicsFile << mechanics[i].getID() << endl;
			mechanicsFile << mechanics[i].getAge() << endl;
			//Number of appointments
			mechanicsFile << mechanics[i].getCounter() << endl;
			//Appointments
			for (int j = 0; j < mechanics[i].getCounter(); j++) {
				mechanicsFile << mechanics[i].getAppointment(j).hours << endl;
				mechanicsFile << mechanics[i].getAppointment(j).mins << endl;
			}
		}
		//Close the file
		mechanicsFile.close();
		//Delete anything taking up memory
		delete[] customers;
		delete[] mechanics;
		break;
	}
	case 3: {
		int numCustomers = 20, numMechanics = 20;
		//create an array of customers
		Customer* customers = new Customer[numCustomers];
		//create an array of mechanics
		Mechanic* mechanics = new Mechanic[numMechanics];

		//open customers.txt
		ifstream customersFile;
		customersFile.open("customers.txt");
		//Check that the file is open
		if (!customersFile.is_open()) {
			cout << "Error opening file" << endl;
			return 0;
		}
		//Check that the file is not empty
		if (customersFile.peek() == ifstream::traits_type::eof()) {
			cout << "The customers file is empty, please run the program once or manually enter some information" << endl;
			return 0;
		}

		string line2;
		while (getline(customersFile, line2)) {
			//number of customers
			numCustomers = stoi(line2);
			//read the info of the customers
			for (int i = 0; i < numCustomers; i++) {
				//Validate each line
				getline(customersFile, line2);
				customers[i].setName(line2);
				//id
				getline(customersFile, line2);
				customers[i].setID(stoi(line2));
				//appointment hours
				getline(customersFile, line2);
				int hours = stoi(line2);
				//appointment mins
				getline(customersFile, line2);
				int mins = stoi(line2);
				//set the appointment
				customers[i].setAppointment(hours, mins);
				//mechanic id
				getline(customersFile, line2);
				customers[i].setMechanicID(stoi(line2));
			}
		}
		//close the file
		customersFile.close();

		//open mechanics.txt
		ifstream mechanicsFile;
		mechanicsFile.open("mechanics.txt");
		//Check that the file is open
		if (!mechanicsFile.is_open()) {
			cout << "Error opening file" << endl;
			return 0;
		}
		//Check that the file is not empty
		if (mechanicsFile.peek() == ifstream::traits_type::eof()) {
			cout << "The mechanics file is empty, please run the program once or manually enter some information" << endl;
			return 0;
		}
		string line1;
		while (getline(mechanicsFile, line1)) {
			//number of mechanics
			numMechanics = stoi(line1);
			//read the info of the mechanics
			for (int i = 0; i < numMechanics; i++) {
				//name
				getline(mechanicsFile, line1);
				mechanics[i].setName(line1);
				//id
				getline(mechanicsFile, line1);
				mechanics[i].setID(stoi(line1));
				//age
				getline(mechanicsFile, line1);
				mechanics[i].setAge(stoi(line1));
				//number of appointments
				getline(mechanicsFile, line1);
				int numAppointments = stoi(line1);
				// appointments

				for (int j = 0; j < numAppointments; j++) {
					//hours
					getline(mechanicsFile, line1);
					int hours = stoi(line1);
					//mins
					getline(mechanicsFile, line1);
					int mins = stoi(line1);
					//add the appointment to the mechanic
					mechanics[i].setAppointment({ hours, mins });
				}
			}
		}
		//close the file
		mechanicsFile.close();

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

		//If theres noone free send a message to cancel the appointment else print the info of the customer and his assigned mechanic use the queue class
		for (int i = 0; i < numCustomers; i++) {
			if (queue.Front().getMechanicID() == 0) {
				cout << "No mechanic available for customer " << queue.Front().getName() << " at " << queue.Front().getAppointment().hours << ":" << queue.Front().getAppointment().mins << endl;
				cout << endl;
				queue.pop();
			}
			else {
				//ex:Mr. Ahmed has an appointment at 1:00. with Ayman
				cout << queue.Front().getName() << " has an appointment at " << queue.Front().getAppointment().hours << ":" << queue.Front().getAppointment().mins << " with " << mechanics[queue.Front().getMechanicID() - 1].getName() << endl;
				cout << endl;
				queue.pop();
			}
		}

		//Deconstruct the queue
		queue.~Queue();
		//Clear anything taking up memory
		delete[] customers;
		delete[] mechanics;
		break;
	}
	}
}