/*
 * Function: class manager
 * Description: Design interfaces to add, edit, remove, show the dish list
 */
#include "../Head/manager.hpp"

manager::manager()
{
	cout << "------------------------------MANAGER------------------------------" << endl;
	cout << endl;
	cout << "  1. Add dish" << endl;
	cout << "  2. Edit dish" << endl;
	cout << "  3. Remove dish" << endl;
	cout << "  4. List dish" << endl;
	cout << "  5. Set table number" << endl;
	cout << "  0. Back" << endl;
	cout << endl;
	cout << "-------------------------------------------------------------------" << endl;

	uint16_t select = choice(0, 5);
	switch (select)
	{
	case BACK:
		start();
		break;
	case ADDDISH:
		addDish();
		break;
	case EDITDISH:
		editDish();
		break;
	case REMOVEDISH:
		removeDish();
		break;
	case LISTDISH:
		listDish();
		break;
	case SETNUMBERTABLE:
		setNumberTable();
		break;
	}
}
void manager::addDish()
{
	string dishName;
	int dishPrice;
	cout << "-----------------------------ADD DISH------------------------------" << endl;
	cout << endl;
	cout << "-> Enter dish name: ";
	processInput(dishName);
	cout << "-> Enter dish price: ";
	processInput(dishPrice);
	cout << endl;
	Dish newDish(dishName, dishPrice);
	DATABASE.push_back(newDish);
	showList();
	cout << endl;
	cout << "  1. Keep adding dish" << endl;
	cout << "  0. Back" << endl;
	cout << endl;
	cout << "-------------------------------------------------------------------" << endl;
	uint16_t select = choice(0, 1);
	switch (managerMenu(select))
	{
	case ADDDISH:
		addDish();
		break;

	case BACK:
		manager();
		break;
	}
}
void manager::editDish()
{
	int dishId;
	cout << "-----------------------------EDIT DISH-----------------------------" << endl;
	cout << endl;
	showList();
	cout << endl;
	bool isLoop;
	do
	{
		cout << "-> Enter ID: ";
		processInput(dishId);
		for (auto &temp : DATABASE)
		{
			if (temp.getID() == dishId)
			{
				cout << endl;
				cout << "  1. Edit dish name" << endl;
				cout << "  2. Edit dish price" << endl;
				cout << "  0. Back" << endl;
				cout << endl;
				cout << "-------------------------------------------------------------------" << endl;
				uint16_t select = choice(0, 2);
				switch (select)
				{
				case 1:
					setName(temp);
					break;
				case 2:
					setPrice(temp);
					break;
				default:
					manager();
					break;
				}
			}
		}
		isLoop = false;
		char yn;
		if (!isLoop)
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
	cout << "  0. Back" << endl;
	cout << endl;
	cout << "-------------------------------------------------------------------" << endl;
	uint16_t select = choice(0, 0);
	switch (managerMenu(select))
	{
	case BACK:
		manager();
		break;
	default:
		break;
	}
}
void manager::removeDish()
{
	int dishId;
	cout << "----------------------------REMOVE DISH----------------------------" << endl;
	cout << endl;
	showList();
	cout << endl;
	bool isLoop = true;
	do
	{
		cout << "-> Enter ID: ";
		processInput(dishId);
		for (auto temp = DATABASE.begin(); temp != DATABASE.end(); ++temp)
		{
			if ((*temp).getID() == dishId)
			{
				DATABASE.erase(temp);
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
		manager();
		break;
	}
}
void manager::listDish()
{
	cout << "-----------------------------LIST DISH-----------------------------" << endl;
	cout << endl;
	showList();
	cout << endl;
	cout << "  0. Back" << endl;
	cout << endl;
	cout << "-------------------------------------------------------------------" << endl;
	uint16_t select = choice(0, 0);
	switch (managerMenu(select))
	{
	case BACK:
		manager();
		break;
	default:
		break;
	}
}
void manager::setNumberTable()
{
	cout << "-----------------------SET NUMBER OF TABLES------------------------" << endl;
	cout << endl;
	cout << "-> Enter number of tables: ";
	processInput(NUMBEROFTABLES);
	cout << endl;
	cout << "  0. Back" << endl;
	cout << endl;
	cout << "-------------------------------------------------------------------" << endl;
	do{
	uint16_t select = choice(0, 0);
	switch (managerMenu(select))
	{
	case BACK:
		manager();
		break;
	default:

		break;
	}
	}while(1);
}
int manager::getNumberTable()
{
	return NUMBEROFTABLES;
}
list<Dish> manager::getDishList()
{
	return DATABASE;
}
void manager::setName(Dish &temp)
{
	string dishName;
	cout << "-----------------------------EDIT DISH-----------------------------" << endl;
	cout << endl;
	cout << "Old dish name is: " << temp.getName() << endl;
	cout << "-> Enter new dish name: ";
	processInput(dishName);
	temp.setName(dishName);
	cout << "Success!" << endl;
	cout << endl;
	cout << "  1. Keep editing another dish" << endl;
	cout << "  2. Keep editing this dish price" << endl;
	cout << "  0. Back" << endl;
	cout << endl;
	cout << "-------------------------------------------------------------------" << endl;
	uint16_t select = choice(0, 2);
	switch (select)
	{
	case 1:
		editDish();
		break;
	case 2:
		setPrice(temp);
		break;
	default:
		manager();
		break;
	}
}
void manager::setPrice(Dish &temp)
{
	int dishPrice;
	cout << "-----------------------------EDIT DISH-----------------------------" << endl;
	cout << endl;
	cout << "Old dish price is: " << temp.getPrice() << endl;
	cout << "-> Enter new dish price: ";
	processInput(dishPrice);
	temp.setPrice(dishPrice);
	cout << "Success!" << endl;
	cout << endl;
	cout << "  1. Keep editing another dish" << endl;
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
		manager();
		break;
	}
}
void manager::showList()
{
	int idWidth = 8;
	int nameWidth = 15;

	cout << "           >----------------List dishes---------------<" << endl;
	if (DATABASE.empty())
	{
		cout << "                          No items found" << endl;
	}
	else
	{
		cout << "             Dish ID" << string(idWidth - 6, ' ') << " | "
			 << "Dish Name" << string(nameWidth - 9, ' ') << " | "
			 << "Dish Price" << endl;
		for (auto temp : DATABASE)
		{
			cout << "             " << temp.getID() << string(idWidth + 1 - to_string(temp.getID()).length(), ' ') << " | "
				 << temp.getName() << string(nameWidth - temp.getName().length(), ' ') << " | "
				 << temp.getPrice() << endl;
		}
	}
	cout << "           >------------------------------------------<" << endl;
}
void manager::processInput(string &var)
{
	int maxChars = 16;
	string stringVar;
	cin.ignore();
	do
	{
		getline(cin, stringVar);
		if (stringVar.length() > static_cast<std::string::size_type>(maxChars - 1))
		{
			cout << "(No more than " << (maxChars - 1) << " characters. Again!): ";
		}
		else
		{
			break;
		}
	} while (true);

	var = stringVar;
}
void manager::processInput(int &var)
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