#include<iostream>
#include<fstream>
int main()
{
    std::ifstream ifile("E:/test.txt");
    if(!ifile)
    {
        std::cout << "the file cannnot be open";
        return 0;
    }
    std::ofstream ofs("E:/test2.txt");
    if(!ofs)
    {
        std::cout << "the file cannot be opened"<<std::endl;
        return 0;
    }
    char ch;
    while (ifile.get(ch))
    {
        /* code */
        std::cout << ch<<"  ";
        ofs.put(ch);

    }
    ifile.close();
    ofs.close();




    std::ifstream ifile1("E:\\test.txt");
    if (!ifile1 )
    {
        std::cout << "cannot open the file";
        return 0;
    }
    char str[50];
    ifile1.getline(str, 50);
    std::cout << str;
    ifile1.close();
    return 0;
}