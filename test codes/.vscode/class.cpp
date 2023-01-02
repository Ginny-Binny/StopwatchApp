#include <bits/stdc++.h>
using namespace std;

class shop
{
    int itemid[20];
    int itemprice[20];
    int counter;

public:
    void initcounter(void) { counter = 0; }
    void setprice(void);
    void displayprice(void);
};

void shop::setprice(void)
{
    cout << "enter the id of your item " << counter + 1 << " : ";
    cin >> itemid[counter];
    cout << "enter the price of your item: ";
    cin >> itemprice[counter];
    counter++;
}

void shop::displayprice(void)
{
    for (int i = 0; i < counter; i++)
    {
        cout << "The price of item with id " << itemid[i] << " is " << itemprice[i] << endl;
    }
}
int main()
{
    shop dukan;
    dukan.initcounter();
    dukan.setprice();
    dukan.setprice();
    dukan.setprice();
    dukan.setprice();
    dukan.displayprice();
    return 0;
}