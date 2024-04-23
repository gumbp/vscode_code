#include <iostream>
#include <vector>

class AirConditioner
{
public:
    void on()
    {
        std::cout << "AirConditioner on" << std::endl;
    }
    void off()
    {
        std::cout << "AirConditioner off" << std::endl;
    }
};

class DeskLamp
{
public:
    void turnoff()
    {
        std::cout << "Desk  Lamp is turned off" << std::endl;
    }
    void turnon()
    {
        std::cout << "Desk  Lamp is turned on" << std::endl;
    }
};

class Television
{
public:
    void turnon()
    {
        std::cout << "Television is turned on" << std::endl;
    }
    void turnoff()
    {
        std::cout << "Television is turned off" << std::endl;
    }
};

class PowerSwitchFacade
{
private:
    DeskLamp deskLamp;
    AirConditioner airconditioner;
    Television television;

public:
    PowerSwitchFacade() {}

    void turnOffDevice(int &deviceCode)
    {
        switch (deviceCode)
        {
        case 1:
            deskLamp.turnoff();
            break;
        case 2:
            airconditioner.off();
            break;
        case 3:
            television.turnoff();
            break;
        default:
            break;
        }
    }
    void turnOnDevice(int &deviceCode)
    {
        switch (deviceCode)
        {
        case 1:
            deskLamp.turnon();
            break;
        case 2:
            airconditioner.on();
            break;
        case 3:
            television.turnon();
            break;
        default:
            break;
        }
    }
};

int main()
{
    // 输入要开启的数字
    // 读取输入
    std::cout << "请输入要读取的次数" << std::endl;
    int n;
    std::cin >> n;
    std::vector<int> input(n);
    for (int i = 0; i < n; i++)
    {
        std::cin >> input[i];
    }
    // 创建电源总开关外观
    PowerSwitchFacade powerSwitchFacade;
    for (int i = 0; i < n; i++)
    {
        powerSwitchFacade.turnOffDevice(input[i]);
        powerSwitchFacade.turnOnDevice(input[i]);
    }
    return 0;
}