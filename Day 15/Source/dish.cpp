/*
 * Function: class dish
 * Description: Used to create a dish list include ID, name, price
 */
#include "../Head/dish.hpp"

Dish::Dish(string name, int price)
{
	static int Id = 0;
	Id++;
	ID = Id;
	NAME = name;
	PRICE = price;
}
void Dish::setName(string newName)
{
	NAME = newName;
}
void Dish::setPrice(int newPrice)
{
	PRICE = newPrice;
}
uint16_t Dish::getID()
{
	return ID;
}
string Dish::getName()
{
	return NAME;
}
double Dish::getPrice()
{
	return PRICE;
}