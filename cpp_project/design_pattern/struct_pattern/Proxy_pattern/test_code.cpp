#include <iostream>
#include "code.cpp"

int main()
{
    // Test case 1: Area greater than 100
    HomePurchase *buyerProxy1 = new HomeAgentProxy();
    buyerProxy1->requestPurchase(120);
    delete buyerProxy1;

    // Test case 2: Area less than or equal to 100
    HomePurchase *buyerProxy2 = new HomeAgentProxy();
    buyerProxy2->requestPurchase(80);
    delete buyerProxy2;

    // Test case 3: Multiple areas
    HomePurchase *buyerProxy3 = new HomeAgentProxy();
    int n;
    std::cout << "Enter the number of areas: ";
    std::cin >> n;
    for (int i = 0; i < n; i++)
    {
        int area;
        std::cout << "Enter the area: ";
        std::cin >> area;
        buyerProxy3->requestPurchase(area);
    }
    delete buyerProxy3;

    return 0;
}