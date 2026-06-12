#include <iostream>
using namespace std;

class Inventory
{
private:
    int itemNumber;
    int quantity;
    double cost;
    double totalCost;

public:
    Inventory()
    {
        itemNumber = 0;
        quantity = 0;
        cost = 0;
        totalCost = 0;
    }

    Inventory(int item, int qty, double c)
    {
        setItemNumber(item);
        setQuantity(qty);
        setCost(c);
        setTotalCost();
    }

    void setItemNumber(int item)
    {
        while (item < 0)
        {
            cout << "Item number cannot be negative. Enter again: ";
            cin >> item;
        }
        itemNumber = item;
    }

    void setQuantity(int qty)
    {
        while (qty < 0)
        {
            cout << "Quantity cannot be negative. Enter again: ";
            cin >> qty;
        }
        quantity = qty;
    }

    void setCost(double c)
    {
        while (c < 0)
        {
            cout << "Cost cannot be negative. Enter again: ";
            cin >> c;
        }
        cost = c;
    }

    void setTotalCost()
    {
        totalCost = quantity * cost;
    }

    int getItemNumber()
    {
        return itemNumber;
    }

    int getQuantity()
    {
        return quantity;
    }

    double getCost()
    {
        return cost;
    }

    double getTotalCost()
    {
        return totalCost;
    }
};

int main()
{
    int item, qty;
    double c;

    cout << "Enter item number: ";
    cin >> item;

    cout << "Enter quantity: ";
    cin >> qty;

    cout << "Enter cost per item: ";
    cin >> c;

    Inventory obj = Inventory(item, qty, c);

    cout << "\nInventory Details\n";
    cout << "Item Number: " << obj.getItemNumber() << endl;
    cout << "Quantity: " << obj.getQuantity() << endl;
    cout << "Cost per Item: " << obj.getCost() << endl;
    cout << "Total Cost: " << obj.getTotalCost() << endl;

    return 0;
}