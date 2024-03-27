#include <iostream>
using namespace std;

// usb接口
class usb
{
public:
    virtual void charge() = 0;
};

// TypeC接口
class TypeC
{
public:
    virtual void chargeWithTypeC() = 0;
};

// 适配器类
class TypeCAdapter : public usb
{
private:
    TypeC *typeC;

public:
    TypeCAdapter(TypeC *typeC) : typeC(typeC) {}
    void charge() override
    {
        typeC->chargeWithTypeC();
    }
};

// 新电脑类，使用TypeC接口
class NewComputer : public TypeC
{
public:
    void chargeWithTypeC() override
    {
        cout << "TypeC" << endl;
    }
};

// 适配器充电器类，使用usb接口
class AdapterCharger : public usb
{
public:
    void charge() override
    {
        cout << "usb adapter" << endl;
    }
};

int main()
{
    int N;
    cin >> N;
    cin.ignore(); // 消耗换行符
    for (int i = 0; i < N; i++)
    {
        // 读取用户选择
        int choice;
        cin >> choice;

        // 根据用户的选择创建相应对象
        if (choice == 1)
        {
            TypeC *newComputer = new NewComputer();
            newComputer->chargeWithTypeC();
            delete newComputer;
        }
        else if (choice == 2)
        {
            usb *usbAdapter = new AdapterCharger();
            usbAdapter->charge();
            delete usbAdapter;
        }
    }
    return 0;
}
