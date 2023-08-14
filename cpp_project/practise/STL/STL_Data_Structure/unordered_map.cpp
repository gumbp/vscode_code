#include <iostream>
#include <unordered_map>

int main() {
    // 创建一个unordered_map对象
    std::unordered_map<std::string, int> myMap;

    // 插入键值对
    myMap.insert({"apple", 5});
    myMap.insert({"banana", 3});
    myMap.insert({"orange", 7});

    //手动插入键值对
    std::pair<std::string, int> mypair;
    std::cout << "pleanse input you key-value" << std::endl;
    while(std::cin>>mypair.first>>mypair.second)
    {
        myMap.insert(mypair);
        std::cout << "pleanse input you key-value" << std::endl;
    }

    // 查找键值对
    auto it = myMap.find("banana");
    if (it != myMap.end()) {
        std::cout << "The value of banana is: " << it->second << std::endl;
    } else {
        std::cout << "banana not found" << std::endl;
    }

    // 删除键值对
    myMap.erase("orange");

    // 遍历键值对
    for (const auto& pair : myMap) {
        std::cout << "Key: " << pair.first << ", Value: " << pair.second << std::endl;
    }

    // 获取容器大小
    std::cout << "Size of the unordered_map: " << myMap.size() << std::endl;

    return 0;
}
