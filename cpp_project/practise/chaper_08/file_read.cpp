#include<iostream>
#include <fstream>
#include <string.h>
void CreateFile(char* s);
void ReadFile(char* s);
int main(){
    std::ifstream in;//定义一个输入流对象in
    std::ofstream out;//定义一个输出流对象
    std::fstream io;//定义一个输入/输入流对象
    CreateFile("f1.txt");
    ReadFile("f1.txt");
    return 0;

}
//建立一个文本文件
void CreateFile(char* s)
{
    std::ofstream outf(s); // 定义输出流对象outf，打开s文件;
    if(!outf)
    {
        std::cout << "cannot open the file" << std::endl;
        return;
    }
    std::cout << "file has been created" << std::endl;
    std::cout << "please put data in it" << std::endl;
    //向里面写入一个整数 一个实数
    int temp1;
    double temp2;
    std::string str;
    std::cin >> temp1 >> temp2;
    std::cin >> str;
    outf << temp1 << " " << temp2<< std::endl;
    outf << "this is a short text file."<<std::endl;
    outf << str << std::endl;
    outf.close();//关闭文件
}

void ReadFile(char* s)
{
    int i = 0;
    double d = 0;
    char str[50];
    std::ifstream ifs(s);//定义输入流对象inf，打开s文件
    if (!ifs)
    {
        /* code */
        std::cout << "cannot open the file" << std::endl;
        return;
    }

    ifs>>i>>d;//从文件中读数据给内存变量
    std::cout << i << " " << d;
    ifs.getline(str, 50);//从文件中读出包含空格的字符串
    std::cout << str << std::endl;
    ifs.close();
    
}