#include <iostream>
#include <string>
using namespace std;

// 定义自行车产品
class Bike
{
public:
    string frame;
    string tires;
    // 设置框架
    void setFrame(const string &frame)
    {
        this->frame = frame;
    }

    // 设置轮胎
    void setTires(const string &tires)
    {
        this->tires = tires;
    }

    // 使用友元重载<<运算符，使得方法可以访问类的私有成员变量
    friend ostream &operator<<(ostream &os, const Bike &bike)
    {
        os << bike.frame << "  " << bike.tires;
        return os;
    }
};

// 自行车建造者接口
class BikeBuilder
{
public:
    virtual void buildFrame() = 0;
    virtual void buildTires() = 0;
    virtual Bike getBike() = 0;
};

// 山地自行车建造者
class MountainBikeBuilder : public BikeBuilder
{
private:
    Bike bike;

public:
    void buildFrame() override
    {
        bike.setFrame("Aluminum Frame");
    }

    void buildTires() override
    {
        bike.setTires("Knobby Tires");
    }

    Bike getBike() override
    {
        return bike;
    }
};

class RoadBikeBuilder : public BikeBuilder
{
private:
    Bike bike;

public:
    void buildFrame() override
    {
        bike.setFrame("Carbon Frame");
    }

    void buildTires() override
    {
        bike.setTires("Slim Tires");
    }

    Bike getBike() override
    {
        return bike;
    }
};

// 自行车Director,负责构建自行车
class BikeDirector
{
public:
    Bike construct(BikeBuilder &builder)
    {
        builder.buildFrame();
        builder.buildTires();
        return builder.getBike();
    }
};

int main()
{
    int N;
    cin >> N; // 订单数量
    BikeDirector director;
    for (int i = 0; i < N; i++)
    {
        string bikeType;
        cin >> bikeType;
        BikeBuilder *builder;

        // 根据输入类别，创建不同的具体建造者
        // new class_name()返回的是指向实例化的类的对象的指针
        if (bikeType == "mountain")
        {
            builder = new MountainBikeBuilder();
        }
        else if (bikeType == "RoadBike")
        {
            builder = new RoadBikeBuilder();
        }
        else
        {
            continue;
        }

        // Director负责指导生产产品
        Bike bike = director.construct(*builder);
        cout << bike << endl;
        delete builder;
    }
    return 0;
}
