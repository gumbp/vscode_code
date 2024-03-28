#include <iostream>
#include <memory>

// 抽象主题
class HomePurchase
{
public:
    virtual void requestPurchase(int area) = 0;
};

// 真实主题
class HomeBuyer : public HomePurchase
{
public:
    void requestPurchase(int area) override
    {
        std::cout << "yes" << std::endl;
    }
};

// 代理类别
class HomeAgentProxy : public HomePurchase
{
private:
    std::shared_ptr<HomeBuyer> homeBuyer;

public:
    HomeAgentProxy() : homeBuyer(std::make_shared<HomeBuyer>()) {}

    void requestPurchase(int area) override
    {
        if (area > 100)
        {
            homeBuyer->requestPurchase(area);
        }
        else
        {
            std::cout << "no" << std::endl;
        }
    }
};

// int main()
// {
//     int n;
//     std::cin >> n;
//     std::unique_ptr<HomePurchase> buyerProxy = std::make_unique<HomeAgentProxy>();
//     for (int i = 0; i < n; i++)
//     {
//         int area;
//         std::cin >> area;
//         buyerProxy->requestPurchase(area);
//     }
//     return 0;
// }
