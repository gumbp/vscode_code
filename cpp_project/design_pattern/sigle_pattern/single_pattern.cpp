// 题目描述
// 小明去了一家大型商场，拿到了一个购物车，并开始购物。请你设计一个购物车管理器，记录商品添加到购物车的信息（商品名称和购买数量），
// 并在购买结束后打印出商品清单。（在整个购物过程中，小明只有一个购物车实例存在）。
// 输入描述
// 输入包含若干行，每行包含两部分信息，分别是商品名称和购买数量。商品名称和购买数量之间用空格隔开。
// 输出描述
// 输出包含小明购物车中的所有商品及其购买数量。每行输出一种商品的信息，格式为 "商品名称 购买数量"。

#include <iostream>
#include <map>
using namespace std;
class ShoppingCarManager
{
public:
    // get instace of shopping car
    static ShoppingCarManager &get_Instance()
    {
        // instance为静态全局变量 只会被初始化一次 即第一次创建的时候.
        static ShoppingCarManager instance;
        return instance;
    }
    // add goods into shopping cart
    void addToCart(const string &itemName, int nums)
    {
        cart[itemName] += nums;
    }

    // view the shoppin cart
    // 常成员函数，表示本能修改人了类成员的值
    void viewCart() const
    {
        for (const auto &item : cart)
        {
            cout << item.first << " " << item.second << endl;
        }
    }

private:
    // 私有的构造函数
    ShoppingCarManager(){};
    // the map of the item and nums in cart
    map<string, int> cart;
};

int main()
{
    string itemName;
    int quanlity;

    while (cin >> itemName >> quanlity)
    {
        ShoppingCarManager &cart = ShoppingCarManager::get_Instance();
        cart.addToCart(itemName, quanlity);
    }
    const ShoppingCarManager &cart = ShoppingCarManager::get_Instance();
    cart.viewCart();
    return 0;
}