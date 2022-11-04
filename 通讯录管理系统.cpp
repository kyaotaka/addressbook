#include <iostream>
#include <cstring>
#include <cmath>
#include <cstdio>
using namespace std;
//定义联系人结构体
struct person
{
	string name;
	string sex;
	int age;
	string pnum;
	string address;
};
//定义通讯录结构体
#define max 1000 //宏定义通讯录人数最大值
struct addressbook
{
	//通讯录中保存的联系人数组
	person parr[max];
	//通讯录已存联系人个数
	int size;
};
//学会使用封装函数
void showmenu();
//声明功能函数
void f1(addressbook* ab);
void f2(addressbook* ab);
void f3(addressbook* ab);
void f4(addressbook* ab);
void f5(addressbook* ab);
void f6(addressbook* ab);
int main()
{	//创建通讯录a1
	addressbook a1;
	//初始化通讯录人数
	a1.size = 0;
	int fnum = -1;
	while (1)//输入0退出通讯录
	{
		showmenu();
		cout << "请输入指令数字" << endl;
		cin >> fnum;
		switch (fnum)//case一个语句可以不加括号
		{
		case 1://添加联系人
			f1(&a1);
			break;
		case 2://显示联系人
			f2(&a1);
			break;
		case 3://删除联系人
			f3(&a1);
			break;
		case 4://查找联系人
			f4(&a1);
			break;
		case 5://修改联系人
			f5(&a1);
			break;
		case 6://清空联系人
			f6(&a1);
			break;
		case 0:
			cout << "欢迎下次使用" << endl;
			return 0;
		default:
			cout << "请输入正确指令数字" << endl;
			break;
		}
		system("pause");
		system("cls");
	}
}
void f1(addressbook *ab)//添加联系人
{
	if (ab->size == max)
		cout << "通讯录已满无法添加" << endl;
	else
	{
		cout << "请输入姓名" << endl;
		cin >> (ab->parr[ab->size]).name;//更改通讯录 人数组 序号的 名字
		cout << "请输入性别"<<endl;
		cin >> (ab->parr[ab->size]).sex;
		cout << "请输入年龄" << endl;
		cin >> (ab->parr[ab->size]).age;
		cout << "请输入电话号码" << endl;
		cin >> (ab->parr[ab->size]).pnum;
		cout << "请输入家庭住址" << endl;
		cin >> (ab->parr[ab->size]).address;
		ab->size++;
		cout << "联系人已存入" << endl;
	}
}
void f2(addressbook* ab)//显示联系人
{
	if (ab->size == 0)
		cout << "通讯录中暂无联系人" << endl;
	else
	for (int i = 0; i < ab->size; i++)
	{
		cout << "姓名：" << (ab->parr[i]).name << '\t' << "性别：" << (ab->parr[i]).sex
			<< '\t' << "年龄：" << (ab->parr[i]).age << '\t' << "电话号码：" << (ab->parr[i]).pnum
			<< '\t' << "家庭住址：" << (ab->parr[i]).address << endl;
	}
	cout << "现有联系人已全部显示" << endl;
}
void f3(addressbook *ab)//删除联系人
{
	if (ab->size == 0)
		cout << "通讯录暂无联系人" << endl;
	else 
	{
		string name;
		cout << "请输入你要删除的联系人姓名" << endl;
		cin >> name;
		//在通讯录中查找联系人
		int flag = 0;//作为查找标记
		for (int i = 0; i < ab->size; i++)
		{
			if (name == (ab->parr[i]).name)
			{
				for (int j = i; j < ab->size - 1; j++)
				{
					ab->parr[j] = ab->parr[j + 1];
				}
				flag++;
				ab->size--;//要是联系人数量减一
				cout << "联系人删除完毕" << endl;
				break;
			}
		}
		if (flag == 0)
			cout << "查无此人" << endl;
	}
}
void f4(addressbook* ab)//查找联系人
{
	if (ab->size == 0)
		cout << "通讯录暂无联系人" << endl;
	else
	{
		string name;
		cout << "请输入你要查找的联系人姓名" << endl;
		cin >> name;
		int flag = 0;
		for (int i = 0; i < ab->size; i++)
		{
			if (name == ab->parr[i].name)
			{
				cout << "姓名：" << (ab->parr[i]).name << endl;
				cout << "性别：" << (ab->parr[i]).sex << endl;
				cout << "年龄：" << (ab->parr[i]).age << endl;
				cout << "电话号码：" << (ab->parr[i]).pnum << endl;
				cout << "家庭住址：" << (ab->parr[i]).address << endl;
				flag++;
				break;
			}
		}
		if (flag == 0)
			cout << "查无此人" << endl;
	}
}
void f5(addressbook* ab)//修改联系人
{
	if (ab->size == 0)
		cout << "通讯录暂无联系人" << endl;
	else
	{
		string name;
		cout << "请输入你要修改的联系人姓名" << endl;
		cin >> name;
		int flag = 0;
		for (int i = 0; i < ab->size; i++)
		{
			if (name == ab->parr[i].name)
			{
				person newperson;
				cout << "请输入修改后内容" << endl;
				cout << "姓名：" << endl;
				cin >> newperson.name;
				cout << "性别：" << endl;
				cin >> newperson.sex;
				cout << "年龄：" << endl;
				cin >> newperson.age;
				cout << "电话号码：" << endl;
				cin >> newperson.pnum;
				cout << "家庭住址：" << endl;
				cin >> newperson.address;
				ab->parr[i]=newperson;
				flag++;
				cout << "联系人修改完毕" << endl;
				break;
			}
		}
		if (flag == 0)
			cout << "查无此人" << endl;
	}
}
void f6(addressbook* ab)
{
	//逻辑上只要把通讯录联系人数量更改为0即可 即使原有数据也会被重新输入覆盖
	ab->size = 0;
	cout << "通讯录清空完毕" << endl;
}
void showmenu()
{ 
	cout << endl;
	cout << "请仔细阅读操作纲领！！！" << endl;
	cout << '\t' << "实现某功能请输入指定数字并按回车键" << endl;
	cout << '\t' << "添加联系人请输入1" << endl;
	cout << '\t' << "显示联系人请输入2" << endl;
	cout << '\t' << "删除联系人请输入3" << endl;
	cout << '\t' << "查找联系人请输入4" << endl;
	cout << '\t' << "修改联系人请输入5" << endl;
	cout << '\t' << "清空联系人请输入6" << endl;
	cout << '\t' << "退出通讯录请输入0" << endl;
}