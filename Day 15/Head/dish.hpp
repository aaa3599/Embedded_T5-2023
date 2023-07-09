#include "main.hpp"



class Dish
{
private:
    uint16_t ID;
    string NAME;
    double PRICE;

public:
    Dish(string name, int price);
    void setName(string newName);
    void setPrice(int newPrice);
    uint16_t getID();
    string getName();
    double getPrice();
};