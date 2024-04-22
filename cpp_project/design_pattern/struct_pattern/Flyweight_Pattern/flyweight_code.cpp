#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>

enum ShapeType
{
    CIRCLE,
    RECTANGLE,
    TRIANGLE
};

std::string shapeTypeToString(ShapeType &type)
{
    switch (type)
    {
    case CIRCLE:
        return "CIRCLE";
    case RECTANGLE:
        return "RECTANGLE";
    case TRIANGLE:
        return "TRIANGLE";
    }
    return "Unknown";
}

class Position
{
private:
    int x;
    int y;

public:
    Position(int x, int y) : x(x), y(y) {}
    int getX() const
    {
        return x;
    }

    int getY() const
    {
        return y;
    }
};

class Shape
{
public:
    virtual void draw(const Position &Position) = 0;
    virtual ~Shape() {}
};

class ConcreteShape : public Shape
{
private:
    ShapeType shapetype;
    bool isFirstTime;

public:
    ConcreteShape(ShapeType type) : shapetype(type), isFirstTime(true) {}
    void draw(const Position &position) override
    {
        std::cout << shapeTypeToString(shapetype) << (isFirstTime ? "Draw" : "Redraw") << " at position (" << position.getX() << "," << position.getY() << ")" << std::endl;
    }

    void setFirstTime(bool firsttime)
    {
        isFirstTime = firsttime;
    }
};

class ShapeFactory
{
private:
    std::unordered_map<ShapeType, Shape *> shapes;

public:
    Shape *getShape(ShapeType type)
    {
        // 如果在图形库中找不到对应类型  则新建一个
        if (shapes.find(type) == shapes.end())
        {
            shapes[type] = new ConcreteShape(type);
        }
        return shapes[type];
    }

    ~ShapeFactory()
    {
        for (auto &shape : shapes)
        {
            delete shape.second;
        }
    }

    void processCommand(ShapeFactory &factory, const std::string &command)
    {
        std::istringstream stream(command);
        std::string shapeTypestr;
        int x, y;
        stream >> shapeTypestr >> x >> y;
        ShapeType type;
        if (shapeTypestr == "CIRCLE")
        {
            type = CIRCLE;
        }
        else if (shapeTypestr == "RECTANGLE")
        {
            type = RECTANGLE;
        }
        else if (shapeTypestr == "TRIANGLE")
        {
            type = TRIANGLE;
        }
        else
        {
            std::cout << "Unknown shape type" << std::endl;
            return;
        }

        Shape *shape = factory.getShape(type);
        shape->draw(Position(x, y));
        // dynamic_cast 是一种特殊的类型转换运算符，主要用于执行安全的向下转型和运行时类型检查。
        // 向下转型主要是从基类指针或者引用转换为子类指针或者引用。这种转换在静态类型检查中是不安全的，因为基类并不一定包含派生类的所有特性。
        // 然而，dynamic_cast可以在运行时检查转换是否合法。如果转换是合法的，dynamic_cast会返回转换后的指针或引用。
        // 如果转换是非法的，dynamic_cast会返回空指针（对于指针类型）或抛出std::bad_cast异常（对于引用类型）。

        // 本句中将基类指针shape转换为子类指针ConcreteShape，如果转换成功，则将ConcreteShape的isFirstTime设置为false
        dynamic_cast<ConcreteShape *>(shape)->setFirstTime(false);
    }
};

int main()
{
    ShapeFactory factory;
    factory.processCommand(factory, "CIRCLE 10 10");
    factory.processCommand(factory, "CIRCLE 20 20");
    factory.processCommand(factory, "RECTANGLE 30 30");
    factory.processCommand(factory, "TRIANGLE 40 40");
    factory.processCommand(factory, "CIRCLE 50 50");
    factory.processCommand(factory, "RECTANGLE 60 60");
    factory.processCommand(factory, "TRIANGLE 70 70");
    return 0;
}