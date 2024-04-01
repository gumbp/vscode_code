#include <iostream>
#include <memory>
using namespace std;

// 咖啡接口
class Coffee
{
public:
    virtual ~Coffee(){};
    // brew 酝酿
    virtual void brew() = 0;
};

// 具体的黑咖啡类别
class BlackCoffee : public Coffee
{
public:
    void brew() override
    {
        cout << "Brewing Black Coffee" << endl;
    }
};

// 具体的拿铁类别
class Latte : public Coffee
{
public:
    void brew() override
    {
        cout << "Brewing Latte" << endl;
    }
};

// 装饰者抽象类
class Decorator : public Coffee
{
protected:
    // coffee参数是一个unique_ptr类型的智能指针，指向Coffee类的对象
    // unique_ptr是C++11标准库中的一个智能指针类，它是一个独占所有权的智能指针，
    // 即它所指向的对象只能有一个unique_ptr指针拥有，当unique_ptr指针被销毁时，
    // 它所指向的对象也会被销毁。
    unique_ptr<Coffee> coffee;

public:
    // 构造函数，将传入的coffee参数（）赋值给类的成员变量coffee
    Decorator(unique_ptr<Coffee> coffee) : coffee(move(coffee)) {}

    void brew() override
    {
        if (coffee)
        {
            coffee->brew();
        }
    }
};

// 具体的牛奶装饰者类
class MilkDecorator : public Decorator
{
public:
    // 构造函数，将传入的coffee参数移动到父类Decorator的构造函数当中
    MilkDecorator(unique_ptr<Coffee> coffee) : Decorator(move(coffee)) {}

    void brew() override
    {
        Decorator::brew();
        cout << "Adding Milk" << endl;
    }
};

// 具体的糖装饰者类
class SugarDecorator : public Decorator
{
public:
    // 构造函数，将传入的coffee参数移动到父类Decorator的构造函数当中
    SugarDecorator(unique_ptr<Coffee> coffee) : Decorator(move(coffee)) {}

    void brew() override
    {
        Decorator::brew();
        cout << "Adding Sugar" << endl;
    }
};

// 好抽象的代码

// 客户端代码
int main()
{
    int coffeeType, condimentType; // 咖啡类型、调味品类型
    while (cin >> coffeeType >> condimentType)
    {
        // 根据输入制作咖啡
        unique_ptr<Coffee> coffee;
        switch (coffeeType)
        {
        case 1:
            coffee = make_unique<BlackCoffee>();
            break;
        case 2:
            coffee = make_unique<Latte>();
            break;
        default:
            break;
        }

        // 根据输入添加调味品
        switch (condimentType)
        {
        case 1:
            coffee = make_unique<MilkDecorator>(move(coffee));
            break;
        case 2:
            coffee = make_unique<SugarDecorator>(move(coffee));
            break;
        default:
            break;
        }
        // 输出制作过程
        if (coffee)
        {

            coffee->brew();
        }
        else
        {
            cout << "指针为空，请正确输入序号" << endl;
        }
    }
}