#include <iostream>
using namespace std;

struct Product {
    char name[5];
    int size;
    int price;
};

int main()
{
    Product a, b;
    cin >> a.name >> a.size >> a.price;
    cin >> b.name >> b.size >> b.price;

    cout << a.name << "," << b.name << "\n";
    cout << "AverageSize=" << (a.size + b.size) / 2 << "\n";
    cout << "AveragePrice=" << (a.price + b.price) / 2;

    return 0;
}