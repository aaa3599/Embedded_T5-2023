
class employee
{
private:
    typedef enum
    {
        BACK,
        ADDDISH,
        EDITDISH,
        REMOVEDISH,
        LISTORDER,
        PAYMENT
    } employeeMenu;
    map<int, int> ORDERLIST;
    static map<int, char> TABLESTATUS;
    int TABLE;
    int NUMBEROFTABLE;
    list<Dish> DISHLIST;
    void menu();
    void addDish();
    void editDish();
    void removeDish();
    void showOrderList();
    void payment();
    void resetStatus();
    void listDish();
    void processInput(int &var);
    void orderList();
    void editID(int id);
    void editQuantity(int id);

public:
    employee(int numberOfTable, list<Dish> database);
};
map<int, char> employee::TABLESTATUS;