/*
 * Function: class employee
 * Description: Design interfaces for adding, editing, deleting, and paying for the order list
 */

#include "../Head/employee.hpp"

employee::employee(int numberOfTable, list<Dish> database)
{
	NUMBEROFTABLE = numberOfTable;
	DISHLIST = database;
	if (TABLESTATUS.empty())
	{
		for (int i = 1; i <= NUMBEROFTABLE; i++)
		{
			TABLESTATUS[i] = 'O';
		}
	}
	cout << "------------------------------EMPLOYEE-----------------------------" << endl;
	cout << endl;
	cout << "  Table number: ";
	for (auto temp : TABLESTATUS)
	{
		cout << "|" << temp.first;
		if (temp.first == NUMBEROFTABLE)
		{
			cout << "|" << endl;
		}
	}
	cout << "  Status      : ";
	for (auto temp : TABLESTATUS)
	{
		if (temp.first <= 10)
		{
			cout << "|" << temp.second;
			if (temp.first == NUMBEROFTABLE)
			{
				cout << " |" << endl;
			}
		}
		else
		{
			cout << " |" << temp.second;
			if (temp.first == NUMBEROFTABLE)
			{
				cout << " |";
			}
		}
	}

	cout << endl;
	cout << endl;
	cout << "-------------------------------------------------------------------" << endl;
	cout << "(Enter '0' to reset the table state)" << endl;
	bool isLoop = false;
	do
	{
		isLoop = false;
		cout << "--> Enter table number: ";
		cin >> TABLE;
		if (cin.fail())
		{
			cout << "Can't find the table. Please try again!" << endl;
			isLoop = true;
			cin.clear();
			while (cin.get() != '\n')
				continue;
		}
		else if (TABLE < 0 || TABLE > NUMBEROFTABLE)
		{
			cout << "Can't find the table, Please try again!" << endl;
			isLoop = true;
		}
	} while (isLoop);
	switch (TABLE)
	{
	case 0:
		resetStatus();
		break;
	default:
		menu();
		break;
	}
}
void employee::menu()
{
	if (TABLE < 10)
	{
		cout << "--";
	}
	else
	{
		cout << "-";
	}
	cout << "----------------------------TABLE[" << TABLE << "]-----------------------------" << endl;
	cout << endl;
	cout << "  1. Add dish" << endl;
	cout << "  2. Edit dish" << endl;
	cout << "  3. Remove dish" << endl;
	cout << "  4. List dishes" << endl;
	cout << "  5. Payment" << endl;
	cout << "  0. Back" << endl;
	cout << endl;
	cout << "-------------------------------------------------------------------" << endl;

	uint16_t select = choice(0, 5);
	switch (employeeMenu(select))
	{
	case ADDDISH:
		addDish();
		break;
	case EDITDISH:
		editDish();
		break;
	case REMOVEDISH:
		removeDish();
		break;
	case LISTORDER:
		showOrderList();
		break;
	case PAYMENT:
		payment();
		break;
	default:
		employee(NUMBEROFTABLE, DISHLIST);
		break;
	}
}
void employee::addDish()
{
	int dishId;
	int numberOfDish;
	cout << "-----------------------------ADD DISH------------------------------" << endl;
	cout << endl;
	listDish();
	cout << endl;
	bool isLoop = true;
	do
	{
		cout << "-> Enter dish ID: ";
		processInput(dishId);
		for (auto temp : DISHLIST)
		{
			if (temp.getID() == dishId)
			{
				cout << "Dish name is: " << temp.getName() << endl;
				isLoop = false;
			}
		}
		char yn;
		if (isLoop)
		{
			cout << "ID not found!" << endl;
			do
			{
				cout << "-> Re-enter(y/n): ";
				cin >> yn;
				yn = tolower(yn);
			} while (yn != 'y' && yn != 'n');
			if (yn == 'y' || yn == 'Y')
			{
				isLoop = true;
			}
			else if (yn == 'n' || yn == 'N')
			{
				isLoop = false;
			}
		}
	} while (isLoop);
	cout << "-> Enter number of the dish: ";
	processInput(numberOfDish);
	ORDERLIST[dishId] = numberOfDish;
	cout << endl;
	orderList();
	cout << endl;
	cout << "  1. keep adding dish" << endl;
	cout << "  0. Back" << endl;
	cout << endl;
	cout << "-------------------------------------------------------------------" << endl;

	uint16_t select = choice(0, 1);
	switch (employeeMenu(select))
	{
	case ADDDISH:
		addDish();
		break;
	case BACK:
		menu();
		break;
	default:
		break;
	}
}
void employee::editDish()
{
	int dishId;
	cout << "-----------------------------EDIT DISH-----------------------------" << endl;
	cout << endl;
	orderList();
	cout << endl;
	bool isLoop = true;
	do
	{
		cout << "-> Enter ID: ";
		processInput(dishId);
		cout << endl;
		for (auto temp : ORDERLIST)
		{
			if (temp.first == dishId)
			{
				cout << "  1. Edit new dish" << endl;
				cout << "  2. Edit dish quantity" << endl;
				cout << "  0. Back" << endl;
				cout << endl;
				cout << "-------------------------------------------------------------------" << endl;
				uint16_t select = choice(0, 2);
				switch (select)
				{
				case 1:
					editID(dishId);
					break;
				case 2:
					editQuantity(dishId);
					break;
				default:
					menu();
					break;
				}
			}
		}
		char yn;
		if (isLoop)
		{
			cout << "ID not found!" << endl;
			do
			{
				cout << "-> Re-enter(y/n): ";
				cin >> yn;
				yn = tolower(yn);
			} while (yn != 'y' && yn != 'n');
			if (yn == 'y' || yn == 'Y')
			{
				isLoop = true;
			}
			else if (yn == 'n' || yn == 'N')
			{
				isLoop = false;
			}
		}
	} while (isLoop);

	cout << "  0. Back" << endl;
	cout << endl;
	cout << "-------------------------------------------------------------------" << endl;
	uint16_t select = choice(0, 0);
	switch (employeeMenu(select))
	{
	case BACK:
		menu();
		break;

	default:
		break;
	}
}
void employee::removeDish()
{
	int dishId;
	cout << "----------------------------REMOVE DISH----------------------------" << endl;
	cout << endl;
	orderList();
	cout << endl;
	bool isLoop = true;
	do
	{
		cout << "-> Enter ID"
			 << ": ";
		processInput(dishId);
		for (auto temp : ORDERLIST)
		{
			if (temp.first == dishId)
			{
				ORDERLIST.erase(dishId);
				cout << "Success!" << endl;
				isLoop = false;
				break;
			}
		}
		char yn;
		if (isLoop)
		{
			cout << "ID not found!" << endl;
			do
			{
				cout << "-> Re-enter(y/n): ";
				cin >> yn;
				yn = tolower(yn);
			} while (yn != 'y' && yn != 'n');
			if (yn == 'y' || yn == 'Y')
			{
				isLoop = true;
			}
			else if (yn == 'n' || yn == 'N')
			{
				isLoop = false;
			}
		}
	} while (isLoop);
	cout << endl;
	cout << "  1. Keep removing dish" << endl;
	cout << "  0. Back" << endl;
	cout << endl;
	cout << "-------------------------------------------------------------------" << endl;
	uint16_t select = choice(0, 1);
	switch (select)
	{
	case 1:
		removeDish();
		break;

	default:
		menu();
		break;
	}
}
void employee::showOrderList()
{
	cout << "-----------------------------LIST DISH-----------------------------" << endl;
	cout << endl;
	orderList();
	cout << endl;
	cout << "  0. Back" << endl;
	cout << endl;
	cout << "-------------------------------------------------------------------" << endl;
	uint16_t select = choice(0, 0);
	switch (employeeMenu(select))
	{
	case BACK:
		menu();
		break;

	default:
		break;
	}
}
void employee::payment()
{
	int total = 0;
	cout << "------------------------------PAYMENT------------------------------" << endl;
	cout << endl;
	orderList();
	cout << endl;
	for (auto temp : ORDERLIST)
	{
		for (auto &item : DISHLIST)
		{
			if (temp.first == item.getID())
			{
				total = total + temp.second * item.getPrice();
			}
		}
	}
	cout << "-> Total: " << total << endl;
	cout << endl;
	cout << "  1. Issue an invoice" << endl;
	cout << "  0. Back" << endl;
	cout << endl;
	cout << "-------------------------------------------------------------------" << endl;
	uint16_t select = choice(0, 1);
	switch (select)
	{
	case 1:
	{
		cout << endl;
		cout << endl;
		cout << "------------------------Successful invoice!------------------------" << endl;
		cout << endl;
		cout << endl;
		TABLESTATUS[TABLE] = 'X';
		ORDERLIST.clear();
		cout << "  0. New order" << endl;
		cout << endl;
		uint16_t select = choice(0, 0);
		switch (select)
		{
		case 0:
			employee(NUMBEROFTABLE, DISHLIST);
			break;

		default:
			break;
		}
	}
	break;
	default:
		menu();
		break;
	}
}
void employee::resetStatus()
{
	if (TABLESTATUS.empty())
	{
		for (int i = 1; i <= NUMBEROFTABLE; i++)
		{
			TABLESTATUS[i] = 'O';
		}
	}
	cout << "------------------------RESET STATUS TABLE-------------------------" << endl;
	cout << endl;
	cout << "  Table number: ";
	for (auto temp : TABLESTATUS)
	{
		cout << "|" << temp.first;
		if (temp.first == NUMBEROFTABLE)
		{
			cout << "|" << endl;
		}
	}
	cout << "  Status      : ";
	for (auto temp : TABLESTATUS)
	{
		if (temp.first <= 10)
		{
			cout << "|" << temp.second;
			if (temp.first == NUMBEROFTABLE)
			{
				cout << " |" << endl;
			}
		}
		else
		{
			cout << " |" << temp.second;
			if (temp.first == NUMBEROFTABLE)
			{
				cout << " |";
			}
		}
	}

	cout << endl;
	cout << endl;
	bool isLoop = false;
	do
	{
		isLoop = false;
		cout << "--> Enter the number of desks to reset: ";
		cin >> TABLE;
		if (cin.fail())
		{
			cout << "Can't find the table. Please try again!" << endl;
			isLoop = true;
			cin.clear();
			while (cin.get() != '\n')
				continue;
		}
		else if (TABLE < 0 || TABLE > NUMBEROFTABLE)
		{
			cout << "Can't find the table, Please try again!" << endl;
			isLoop = true;
		}
	} while (TABLE < 1 || TABLE > NUMBEROFTABLE);
	TABLESTATUS[TABLE] = 'O';
	cout << endl;
	cout << "Success!" << endl;
	cout << endl;
	cout << "1. Keep reseting status of table" << endl;
	cout << "0. Back" << endl;
	cout << endl;
	cout << "-------------------------------------------------------------------" << endl;
	uint16_t select = choice(0, 1);
	switch (select)
	{
	case 1:
		resetStatus();
		break;

	default:
		employee(NUMBEROFTABLE, DISHLIST);
		break;
	}
}
void employee::listDish()
{
	int idWidth = 8;
	int nameWidth = 15;

	cout << "           >----------------List dishes---------------<" << endl;
	if (DISHLIST.empty())
	{
		cout << "                         No dishes found" << endl;
	}
	else
	{
		cout << "             Dish ID" << string(idWidth - 6, ' ') << " | "
			 << "Dish Name" << string(nameWidth - 9, ' ') << " | "
			 << "Dish Price" << endl;
		for (auto temp : DISHLIST)
		{
			cout << "             " << temp.getID() << string(idWidth + 1 - to_string(temp.getID()).length(), ' ') << " | "
				 << temp.getName() << string(nameWidth - temp.getName().length(), ' ') << " | "
				 << temp.getPrice() << endl;
		}
	}
	cout << "           >------------------------------------------<" << endl;
}
void employee::processInput(int &var)
{
	int minInt = 0;
	int intVar;
	bool validInput = false;
	do
	{
		cin >> intVar;

		if (cin.fail())
		{
			cout << "(Please enter a valid number. Again!): ";
			cin.clear();
			while (cin.get() != '\n')
				continue;
			;
		}
		else if (intVar < minInt)
		{
			cout << "(Please enter a number greater than 0. Again!): ";
		}
		else
		{
			validInput = true;
		}
	} while (!validInput);
	var = intVar;
}
void employee::orderList()
{
	int noWidth = 3;
	int idWidth = 7;
	int nameWidth = 15;
	int priceWidth = 10;
	int no = 1;
	cout << "  >--------------------------Order list--------------------------<" << endl;
	if (ORDERLIST.empty())
	{
		cout << "                       No dishes found" << endl;
	}
	else
	{
		cout << "    N.o" << string(noWidth - 3, ' ') << " | "
			 << "Dish ID" << string(idWidth - 7, ' ') << " | "
			 << "Dish Name" << string(nameWidth - 9, ' ') << " | "
			 << "Dish Price" << string(priceWidth - 10, ' ') << " | "
			 << "Dish quantity" << endl;
		for (auto &temp : ORDERLIST)
		{
			int id = temp.first;
			int quant = temp.second;

			cout << "    " << no << string(noWidth - to_string(no).length(), ' ') << " | ";
			no++;
			for (auto &item : DISHLIST)
			{
				if (item.getID() == id)
				{
					cout << item.getID() << string(idWidth - to_string(item.getID()).length(), ' ') << " | "
						 << item.getName() << string(nameWidth - item.getName().length(), ' ') << " | "
						 << item.getPrice() << string(priceWidth - to_string(item.getPrice()).length(), ' ') << " | ";
				}
			}
			cout << quant << endl;
		}
	}
	cout << "  >--------------------------------------------------------------<" << endl;
}
void employee::editID(int id)
{
	int dishId;
	int quantity;
	for (auto temp : ORDERLIST)
	{
		if (temp.first == id)
		{
			cout << "-----------------------------EDIT DISH-----------------------------" << endl;
			cout << endl;
			listDish();
			cout << endl;
			cout << "Old dish ID is: " << temp.first << endl;
			cout << "-> Enter new dish ID"
				 << ": ";
			processInput(dishId);
			quantity = temp.second;
			ORDERLIST.erase(temp.first);
			ORDERLIST[dishId] = quantity;
			cout << "Success!" << endl;
			cout << endl;
			cout << "  1. Edit another dish" << endl;
			cout << "  2. Edit dish quantity" << endl;
			cout << "  0. Back" << endl;
			cout << endl;
			cout << "-------------------------------------------------------------------" << endl;
			int select = choice(0, 2);
			switch (select)
			{
			case 1:
				editDish();
				break;
			case 2:
				editQuantity(dishId);
				break;
			default:
				menu();
				break;
			}
		}
	}
}
void employee::editQuantity(int id)
{
	int quantity;
	for (auto temp : ORDERLIST)
	{
		if (temp.first == id)
		{
			cout << "-----------------------------EDIT DISH-----------------------------" << endl;
			cout << endl;
			orderList();
			cout << endl;
			cout << "Old dish quantity is: " << temp.second << endl;
			cout << "-> Enter new dish quantity"
				 << ": ";
			processInput(quantity);
			ORDERLIST[id] = quantity;
			cout << "Success!" << endl;
			cout << endl;
			cout << "  1. Edit another dish" << endl;
			cout << "  0. Back" << endl;
			cout << endl;
			cout << "-------------------------------------------------------------------" << endl;
			uint16_t select = choice(0, 1);
			switch (select)
			{
			case 1:
				editDish();
				break;

			default:
				menu();
				break;
			}
		}
	}
}