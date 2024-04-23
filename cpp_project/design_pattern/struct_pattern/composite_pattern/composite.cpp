#include <iostream>
#include <sstream>
#include <vector>

class Component
{
public:
    virtual void display(int depth) = 0;
};

class Deparment : public Component
{
private:
    std::string name;
    std::vector<Component *> children;

public:
    Deparment(const std::string &name) : name(name) {}
    void add(Component *component)
    {
        children.push_back(component);
    }

    void display(int depth) override
    {
        std::string s(depth, '-');
        std::cout << s << name << std::endl;
        for (auto &c : children)
        {
            c->display(depth + 2);
        }
    }
};

class Employee : public Component
{
private:
    std::string name;

public:
    Employee(const std::string &name) : name(name) {}

    void display(int depth) override
    {
        std::string indent((depth + 1) * 2, '-');
        std::cout << indent << name << std::endl;
    }
};



// 定义枝节点 存储子部件
class Company
{
private:
    std::string name;
    Deparment *root;

public:
    Company(const std::string &name) : name(name), root(new Deparment(name)) {}

    void add(Component *component)
    {
        root->add(component);
    }

    void display()
    {
        std::cout << "company structure:" << std::endl;
        root->display(1);
    }
};

/**
 * The main function of the program.
 *
 * This function creates a Company object and adds departments and employees to it based on user input.
 * It then displays the company's information.
 */
int main()
{
    std::string companyName;
    std::getline(std::cin, companyName);

    // 调用Company的构造函数，并用companyName初始化name
    Company company(companyName);
    int n;
    std::cin >> n;
    std::cin.ignore();
    for (int i = 0; i < n; i++)
    {
        // 定义输入的类型 名字
        std::string type, name;
        std::cin >> type;
        std::getline(std::cin >> std::ws, name);
        if (type == "Deparment")
        {
            company.add(new Deparment(name));
        }
        else if (type == "Employee")
        {
            company.add(new Employee(name));
        }
    }
    company.display();
}