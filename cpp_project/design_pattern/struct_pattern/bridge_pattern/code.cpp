#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

// 步骤1：创建实现化接口
class TV
{
public:
    virtual void turnOn() = 0;
    virtual void turnOff() = 0;
    virtual void swithChannel() = 0;
};

// 步骤2：创建具体实现化类
class SonyTV : public TV
{
public:
    void turnOn() override
    {
        cout << "Sony TV is on" << endl;
    }
    void turnOff() override
    {
        cout << "Sony TV is off" << endl;
    }
    void swithChannel() override
    {
        cout << "Sony TV is switching channel" << endl;
    }
};

class TCLTV : public TV
{
public:
    void turnOn() override
    {
        cout << "TCL TV is on" << endl;
    }
    void turnOff() override
    {
        cout << "TCL TV is off" << endl;
    }
    void swithChannel() override
    {
        cout << "TCL TV is switching channel" << endl;
    }
};

// 步骤3：创建抽象化接口

class RemoteControl
{
protected:
    TV *tv;

public:
    // 构造函数  冒号后面为将子类变量tv使用参数tv进行初始化
    RemoteControl(TV *tv) : tv(tv) {}
    virtual void performOperation() = 0;
};

// 步骤4：创建扩展抽象化类
class PowerOperation : public RemoteControl
{
public:
    // 构造函数  冒号后面为将父类变量tv使用参数tv进行初始化
    PowerOperation(TV *tv) : RemoteControl(tv) {}
    void performOperation() override
    {
        tv->turnOn();
        tv->turnOff();
    }
};

class OffOperation : public RemoteControl
{
public:
    OffOperation(TV *tv) : RemoteControl(tv) {}
    void performOperation() override
    {
        tv->turnOn();
        tv->turnOff();
    }
};

class ChannelSwitchOperation : public RemoteControl
{
public:
    ChannelSwitchOperation(TV *tv) : RemoteControl(tv) {}
    void performOperation() override
    {
        tv->turnOn();
        tv->turnOff();
        tv->swithChannel();
    }
};

// 步骤5：客户端调用
int main()
{
    int N;
    cout << "请输入操作数目" << endl;
    cin >> N;
    cin.ignore();
    for (int i = 0; i < N; i++)
    {
        string input;
        getline(cin, input);
        istringstream iss(input);

        int brand, operation;
        iss >> brand >> operation;
        TV *tv;
        if (brand == 0)
        {
            tv = new SonyTV();
        }
        else
        {
            tv = new TCLTV();
        }
        RemoteControl *remotecontrol;
        if (operation == 2)
        {
            remotecontrol = new PowerOperation(tv);
        }
        else if (operation == 3)
        {
            remotecontrol = new OffOperation(tv);
        }
        else
        {
            remotecontrol = new ChannelSwitchOperation(tv);
        }
            remotecontrol->performOperation();
        delete tv;
        delete remotecontrol;
    }
    return 0;
}