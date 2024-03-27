#include <iostream>
#include <string>
#include <vector>
using namespace std;

// 抽象原型类
class Prototype
{
public:
    virtual Prototype *clone() const = 0;
    virtual string getDetails() const = 0;
    virtual ~Prototype(){};
};

// 具体矩形原型类
class RtanglePrototype : public Prototype
{
private:
    string color;
    int width;
    int height;

public:
    // 构造方法
    RtanglePrototype(string color, int width, int height) : color(color), width(width), height(height) {}

    // 克隆方法
    Prototype *clone() const override
    {
        // this指针指向当前对象  *this通过间接访问  表示该对象引用。
        return new RtanglePrototype(*this);
    }

    // 获取矩形的详细信息
    string getDetails() const override
    {
        return "color:" + color + ", Width: " + std::to_string(width) + ", Height: " + std::to_string(height);
    }
};

// 客户端程序
int main()
{
    vector<Prototype *> retangles;

    // 读取时需要创建的矩形数量
    int N;
    cin>>N;
    for (auto i = 0; i < N; i++)
    {
        string color;
        int height;
        int width;
        cin >> color >> width >> height;
        // 创建原型对象
        Prototype *originalRetangle = new RtanglePrototype(color, width, height);

        // 将原型对象保存到向量中
        retangles.push_back(originalRetangle);
    }

    for (const auto &rectangle : retangles)
    {
        Prototype *cloneRetangle = rectangle->clone();
        cout << cloneRetangle->getDetails() << endl;

        // 释放克隆对象的内存
        delete cloneRetangle;
    }

    // 释放原型对象的内存
    for (const auto &retangle : retangles)
    {
        delete retangle;
    }
    return 0;
}