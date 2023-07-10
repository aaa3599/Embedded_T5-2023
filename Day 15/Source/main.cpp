/*
* File: main.cpp
* Author: Le Duc Anh
* Date: 08/07/2023
* Description: This's an example about create an order interface for managers and employees
*/

#include "../Head/main.hpp"
#include "dish.cpp"
#include "manager.cpp"
#include "employee.cpp"

/*
 * Function: Start menu
 * Description: Start interface
 */
void start()
{
	manager *Manager;
	cout << "-------------------------------ORDER-------------------------------" << endl;
	cout << endl;
	cout << "  1. Manager" << endl;
	cout << "  2. Employee" << endl;
	cout << endl;
	cout << "-------------------------------------------------------------------" << endl;
	uint16_t select = choice(1, 2);
	switch (startMenu(select))
	{
	case MANAGER:
		Manager = new manager();
		break;
	case EMPLOYEE:
		employee Employee(Manager->getNumberTable(), Manager->getDishList());
		break;
	}
}

//Function is used to selecte your choice
uint16_t choice(uint16_t start, uint16_t end)
{
	uint16_t n = 0;
    do
    {
        cout << "\nEnter your choice: ";
	    cin >> n;
    } while (n<start||n>end);
    return n;
}





int main(){

	start();

    return 0;
}

