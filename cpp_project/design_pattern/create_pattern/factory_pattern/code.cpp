#include <iostream>
#include <vector>

// 抽象积木接口
class Block
{
public:
    virtual void produce() = 0;
};

// 具体原型积木实现
class CircleBlock : public Block
{
public:
    void produce() override
    {
        std::cout << "this is CircleBlock" << std::endl;
    }
};

// 具体方形积木实现
class SquareBlock : public Block
{
public:
    void produce() override
    {
        std::cout << "this is squareblock" << std::endl;
    }
};

// 抽象积木工厂接口
class BlockFactory
{
public:
    virtual Block *createBlock() = 0;
};

// 具体圆型积木工厂实现
class CirleBlockFactory : public BlockFactory
{
    Block *createBlock() override
    {
        return new CircleBlock();
    }
};

// 具体方形积木工厂实现
class SquareBlockFactory : public BlockFactory
{
    Block *createBlock() override
    {
        return new SquareBlock();
    }
};

// 积木工厂系统
class BlockFactorySystem
{
private:
    std::vector<Block *> blocks;

public:
    void produceBlocks(BlockFactory *factory, int quantity)
    {
        for (int i = 0; i < quantity; i++)
        {
            Block *block = factory->createBlock();
            blocks.push_back(block);
            block->produce();
        }
    }

    const std::vector<Block *> &getBlocks() const
    {
        return blocks;
    }

    ~BlockFactorySystem()
    {
        // 释放所有动态分配的内存
        for (Block *block : blocks)
        {
            delete block;
        }
    }
};

int main()
{
    // 创建积木工厂系统
    BlockFactorySystem factorySystem;
    // 读取生产次数
    int productCount;
    std::cin >> productCount;

    for (int i = 0; i < productCount; i++)
    {
        std::string blockType;
        int quantity;
        std::cin >> blockType >> quantity;

        if (blockType == "circle")
        {
            factorySystem.produceBlocks(new CirleBlockFactory, quantity);
        }
        else if (blockType == "Square")
        {
            factorySystem.produceBlocks(new SquareBlockFactory(), quantity);
        }
    }
    return 0;
}
