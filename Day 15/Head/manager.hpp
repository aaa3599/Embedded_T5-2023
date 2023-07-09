#include "main.hpp"

class manager
{
private:
    typedef enum
    {
        BACK,
        ADDDISH,
        EDITDISH,
        REMOVEDISH,
        LISTDISH,
        SETNUMBERTABLE
    } managerMenu;
    static list<Dish> DATABASE;
    static int NUMBEROFTABLES;
    void addDish();
    void editDish();
    void removeDish();
    void listDish();
    void setNumberTable();
    void setName(Dish &temp);
    void setPrice(Dish &temp);
    void showList();
    void processInput(string &var);
    void processInput(int &var);

public:
    manager();
    int getNumberTable();
    list<Dish> getDishList();
};
list<Dish> manager::DATABASE;
int manager::NUMBEROFTABLES;