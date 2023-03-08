#include <iostream>
using namespace std;
template <class Type>
class Link
{
public:
    Link();
    void Insert(Type &);
    void PrintLink();
    ~Link();

protected:
    // 节点信息
    struct Node
    {
        /* data */
        Node *next;
        Type *p;
    };

    // 定义头节点
    Node *head;
};

template <class Type>
Link<Type>::Link()
{
    head = 0;
}

// 这个析构函数我怎么看不懂？？？
template <class Type>
Link<Type>::~Link()
{
    Node *pp;
    while (pp = head)
    {
        head = head->next;
        delete pp->p;
        delete pp;
    }
}

template <class Type>
void Link<Type>::Insert(Type &t)
{ // 头插法插入新结点
    Node *tem = new Node;
    tem->p = &t;
    tem->next = head;
    head = tem;
}

template <class Type>
void Link<Type>::PrintLink()
{
    for (Node *pp = head; pp; pp = pp->next)
    {
        cout << *(pp->p) << "  ";
    }
    cout << endl;
}

int main()
{
    Link<double> DoubleLink;
for (int i = 0; i < 8; i++)
{
    DoubleLink.Insert(*new double(i + 0.1)); // insert参数类型为double的引用   new double(i+1.1)表示申请一个double的引用并赋值（i+1.1）  之后的*表示进行间接访问  即得到值（i+1.1）
}
DoubleLink.PrintLink();
return 0;
}