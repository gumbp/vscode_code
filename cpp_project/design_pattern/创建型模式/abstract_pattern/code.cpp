#include <iostream>
#include <string>
using namespace std;

// 抽象椅子接口
// 接口定义了对该类对象的一组操作方法
class Chair
{
public:
    virtual void showInfo() = 0;
};

// 具体现代风格的椅子
class ModernChair : public Chair
{
public:
    void showInfo() override
    {
        cout << "modern chair" << endl;
    }
};

// 具体古典风格的椅子
class ClassicalChair : public Chair
{
public:
    void showInfo() override
    {
        cout << "classical chair" << endl;
    }
};

// 抽象沙发接口
class Sofa
{
public:
    virtual void display() = 0;
};

//  具体现代风格沙发
class ModernSofa : public Sofa
{
public:
    void display() override
    {
        cout << "modern sofa" << endl;
    }
};

// 具体古典风格的沙发
class ClassicalSofa : public Sofa
{
public:
    void display() override
    {
        cout << "classical sofa" << endl;
    }
};

// 抽象家具工厂接口
class furniturefactory
{

public:
    virtual Chair *createdChair() = 0;
    virtual Sofa *createSofa() = 0;
};

// 现代风格家居工厂
class ModernFurnitureFactory : public furniturefactory
{
public:
    Chair *createdChair() override
    {
        return new ModernChair();
    }

    Sofa *createSofa()
    {
        return new ModernSofa();
    }
};

// 具体古典家具工厂
class ClassicalFurnitureFactory : public furniturefactory
{
public:
    Chair *createdChair() override
    {
        return new ClassicalChair();
    }

    Sofa *createSofa() override
    {
        return new ClassicalSofa();
    }
};

int main()
{
    // 读取订单量
    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        // 读取家具类型
        string furnitureType;
        cin >> furnitureType;

        // 创建相应风格的家具装饰品工厂
        furniturefactory *factory = nullptr;
        if (furnitureType == "modern")
        {
            factory = new ModernFurnitureFactory();
        }
        else if (furnitureType == "classical")
        {
            factory = new ClassicalFurnitureFactory();
        }
        // 其他类型则返回
        else
        {
            continue;
        }

        // 根据工厂生产椅子和沙发
        Sofa *sofa = factory->createSofa();
        Chair *chair = factory->createdChair();
        // 输出厂家信息
        chair->showInfo();
        sofa->display();
        // 释放动态分配的内存
        delete factory;
        delete sofa;
        delete chair;
    }
    return 0;
}
