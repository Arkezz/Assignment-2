#pragma once
#include "Customer.h"
#include "Mechanic.h"
#include <string>

//functions declaration
//Generates the values for customer and mechanics randomly out of set arrays
void generatePeople(Customer* customers, int customerSize, Mechanic* mechanics, int mechanicSize);
//Takes the input for values of customers and mechanics and sets them
void enterPeople(Customer* customers, int customerSize, Mechanic* mechanics, int mechanicSize);