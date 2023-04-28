// PS：帮一个小学妹看的代码

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#define LEN sizeof(struct People) // 在模块中可以用LEN来代替sizeof关键字
struct People
{
  char name[10];   // 姓名
  char sex[4];     // 性别
  int age;         // 年龄
  int num;         // 电话号码
  int QQ;          // QQ
  char WeChat[20]; // 微信
  char email[20];  // 邮箱
  char sign[10];   // 标签
  char addr[30];   // 家庭地址
  struct People *next;
};
struct People *head = NULL;
struct People *end = NULL;
void add_people()
{ // 添加信息 (主要通过动态链表的创建实现）
  system("cls");
  int count;
  printf("请输入要添加联系人个数：\n");
  scanf("%d", &count);
  struct People *p1, *p2;                 // 首尾指针
  p1 = p2 = (struct People *)malloc(LEN); // 开辟动态存储区，把起始地址赋给p1
  int i = 0;
  printf("------------------------------------\n");
  if (head == NULL)
  {
    head = p1;
  }
  else
  {
    end->next = p1;
  }
  while (count > 0)
  {
    printf("请输第%d个联系人信息：\n", ++i);
    printf("姓名：\n");
    scanf("%s", &p1->name);
    printf("性别：\n");
    scanf("%s", &p1->sex);
    printf("年龄：\n");
    scanf("%d", &p1->age);
    printf("电话号码：\n");
    scanf("%d", &p1->num);
    printf("QQ:\n");
    scanf("%d", &p1->QQ);
    printf("微信：\n");
    scanf("%s", &p1->WeChat);
    printf("邮箱：\n");
    scanf("%s", &p1->email);
    printf("标签：\n");
    scanf("%s", &p1->sign);
    printf("家庭地址：\n");
    scanf("%s", &p1->addr);
    count--;
    p2->next = p1;
    p2 = p1;
    p1 = (struct People *)malloc(LEN);
    system("cls");
  }
  p2->next = NULL; // 将NULL赋值给最后一个结构体next指针，使其不再指向任何地址
  end = p2;
  printf("全部添加成功！\n");
  system("pause");
}
void views_people()
{ // 查看全部信息
  system("cls");
  struct People *pt;
  if (head != NULL)
  {
    for (pt = head; pt != NULL;)
    {
      printf("姓名：%s\n性别：%s\n年龄：%d\n电话号码:%d\nQQ:%d\n微信：%s\n邮箱：%s\n标签：%s\n家庭地址：%s\n", pt->name, pt->sex, pt->age, pt->num, pt->QQ, pt->WeChat, pt->email, pt->sign, pt->addr);
      pt = pt->next;
      printf("-------------------------------------------------------------\n");
    }
  }
  else
  {
    printf("该系统中无数据！");
  }
  system("pause");
}
void delall_people()
{ // 全部删除
  system("cls");
  printf("正在删除中···\n");
  system("pause");
  struct People *pt;
  for (pt = head; pt != NULL;)
  {
    struct People *temp = pt;
    pt = pt->next;
    free(pt); // 通过free()函数开辟的空间释放，从而达到数据删除的作用
  }
  head = NULL;
  end = NULL;
  printf("删除成功！\n");
  system("pause");
}
void view_people()
{ // 单个查询,通过名字查询
  system("cls");
  struct People *pt;
  printf("输入要查询的联系人名字：\n"); /*将链表中的数据一一遍历，与所输入数据进行对比，若匹配成功，则将该指针指向结构体中的数据输出*/
  char name[10];
  int flag = 1;
  scanf("%s", &name);
  for (pt = head; pt != NULL;)
  {
    if (strcmp(pt->name, name) == 0)
    { // strcmp用于比较两个字符数组大小，并返回整数
      printf("成功找到该联系人！\n");
      printf("姓名：%s\n性别：%s\n年龄：%d\n电话号码:%d\nQQ:%d\n微信：%s\n邮箱：%s\n标签：%s\n家庭地址：%s\n", pt->name, pt->sex, pt->age, pt->num, pt->QQ, pt->WeChat, pt->email, pt->sign, pt->addr);
      flag = 0;
      break;
    }
    pt = pt->next;
  }
  if (flag)
  {
    printf("不好意思，未找到！\n");
  }
  system("pause");
}
void revise_people()
{ // 修改内容
  system("cls");
  struct People *pt;
  printf("输入要修改的联系人名字：\n");
  char name[10];
  int flag = 1;
  scanf("%s", &name);
  for (pt = head; pt != NULL;)
  {
    if (strcmp(name, pt->name) == 0)
    {
      printf("成功找到该联系人！\n");
      printf("姓名：%s\n性别：%s\n年龄：%d\n电话号码:%d\nQQ:%d\n微信：%s\n邮箱：%s\n标签：%s\n家庭地址：%s\n", pt->name, pt->sex, pt->age, pt->num, pt->QQ, pt->WeChat, pt->email, pt->sign, pt->addr);
      flag = 0;
      printf("请分别对该联系人的信息进行修改：\n");
      printf("姓名：\n");
      scanf("%s", &pt->name);
      printf("性别：\n");
      scanf("%s", &pt->sex);
      printf("年龄：\n");
      scanf("%d", &pt->age);
      printf("电话号码：\n");
      scanf("%d", &pt->num);
      printf("QQ:\n");
      scanf("%d", &pt->QQ);
      printf("微信：\n");
      scanf("%s", &pt->WeChat);
      printf("邮箱：\n");
      scanf("%s", &pt->email);
      printf("标签：\n");
      scanf("%s", &pt->sign);
      printf("家庭地址：\n");
      scanf("%s", &pt->addr);
      break;
    }
    pt = pt->next;
  }
  if (flag)
  {
    printf("不好意思，未找到！\n");
  }
  system("pause");
}
void del_people()
{ // 删除单个联系人信息
  system("cls");
  struct People *pt, *temp;
  pt = head;
  printf("请输入要删除的联系人：");
  char name[10];
  scanf("%s", &name);
  int flag = 1;
  while (pt != NULL)
  {
    if (strcmp(name, pt->name) == 0)
    {
      if (pt == head)
      {
        head = pt->next;
        flag = 0;
        printf("删除成功！\n");
        system("pause");
      }
      else
      {
        printf("删除成功···\n");
        system("pause");
        temp->next = pt->next;
        free(pt);
        flag = 0;
        break;
      }
    }
    temp = pt;
    pt = pt->next;
  }
  if (flag)
  {
    printf("不好意思，未找到！\n");
    system("pause");
  }
}
void menu()
{ // 主要通过goto语句，switch语句以及函数的调用三种方法来实现
  system("cls");
  printf("                   **********************************************************\n");
  printf("                     ***********         通讯录管理系统         ***********\n");
  printf("                       ********----------1、录入信息    ---------********\n");
  printf("                          ####*----------2、查看全部信息---------*####\n");
  printf("                            ##*----------3、查看单个信息---------*##\n");
  printf("                              *----------4、删除全部信息---------*\n");
  printf("                           ###*----------5、删除单个信息---------*###\n");
  printf("                         ******----------6、修改单个信息---------******\n");
  printf("                       ********----------7、退出系统    ---------********\n");
  printf("                          ********************************************\n");
  int choice;
  printf("选择任意一个功能：\n");
loop: // 为了配合goto语句
  scanf("%d", &choice);
  switch (choice)
  {
  case 1:
    add_people();
    menu();
  case 2:
    views_people();
    menu();
  case 3:
    view_people();
    menu();
    break;
  case 4:
    delall_people();
    menu();
  case 5:
    del_people();
    menu();
  case 6:
    revise_people();
    menu();
  case 7:
    exit(1); // 程序异常，结束程序
    break;
  default:
    printf("输入错误！请重新输入:");
    goto loop;
  }
}
int main()
{
  void add_people();
  void views_people();
  void delall_people();
  void view_people();
  void revise_people();
  void del_people();
  void menu();
  menu();
  return 0;
}