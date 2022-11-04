#include <iostream>
#include <cstring>
#include <cmath>
#include <cstdio>
using namespace std;
//������ϵ�˽ṹ��
struct person
{
	string name;
	string sex;
	int age;
	string pnum;
	string address;
};
//����ͨѶ¼�ṹ��
#define max 1000 //�궨��ͨѶ¼�������ֵ
struct addressbook
{
	//ͨѶ¼�б������ϵ������
	person parr[max];
	//ͨѶ¼�Ѵ���ϵ�˸���
	int size;
};
//ѧ��ʹ�÷�װ����
void showmenu();
//�������ܺ���
void f1(addressbook* ab);
void f2(addressbook* ab);
void f3(addressbook* ab);
void f4(addressbook* ab);
void f5(addressbook* ab);
void f6(addressbook* ab);
int main()
{	//����ͨѶ¼a1
	addressbook a1;
	//��ʼ��ͨѶ¼����
	a1.size = 0;
	int fnum = -1;
	while (1)//����0�˳�ͨѶ¼
	{
		showmenu();
		cout << "������ָ������" << endl;
		cin >> fnum;
		switch (fnum)//caseһ�������Բ�������
		{
		case 1://�����ϵ��
			f1(&a1);
			break;
		case 2://��ʾ��ϵ��
			f2(&a1);
			break;
		case 3://ɾ����ϵ��
			f3(&a1);
			break;
		case 4://������ϵ��
			f4(&a1);
			break;
		case 5://�޸���ϵ��
			f5(&a1);
			break;
		case 6://�����ϵ��
			f6(&a1);
			break;
		case 0:
			cout << "��ӭ�´�ʹ��" << endl;
			return 0;
		default:
			cout << "��������ȷָ������" << endl;
			break;
		}
		system("pause");
		system("cls");
	}
}
void f1(addressbook *ab)//�����ϵ��
{
	if (ab->size == max)
		cout << "ͨѶ¼�����޷����" << endl;
	else
	{
		cout << "����������" << endl;
		cin >> (ab->parr[ab->size]).name;//����ͨѶ¼ ������ ��ŵ� ����
		cout << "�������Ա�"<<endl;
		cin >> (ab->parr[ab->size]).sex;
		cout << "����������" << endl;
		cin >> (ab->parr[ab->size]).age;
		cout << "������绰����" << endl;
		cin >> (ab->parr[ab->size]).pnum;
		cout << "�������ͥסַ" << endl;
		cin >> (ab->parr[ab->size]).address;
		ab->size++;
		cout << "��ϵ���Ѵ���" << endl;
	}
}
void f2(addressbook* ab)//��ʾ��ϵ��
{
	if (ab->size == 0)
		cout << "ͨѶ¼��������ϵ��" << endl;
	else
	for (int i = 0; i < ab->size; i++)
	{
		cout << "������" << (ab->parr[i]).name << '\t' << "�Ա�" << (ab->parr[i]).sex
			<< '\t' << "���䣺" << (ab->parr[i]).age << '\t' << "�绰���룺" << (ab->parr[i]).pnum
			<< '\t' << "��ͥסַ��" << (ab->parr[i]).address << endl;
	}
	cout << "������ϵ����ȫ����ʾ" << endl;
}
void f3(addressbook *ab)//ɾ����ϵ��
{
	if (ab->size == 0)
		cout << "ͨѶ¼������ϵ��" << endl;
	else 
	{
		string name;
		cout << "��������Ҫɾ������ϵ������" << endl;
		cin >> name;
		//��ͨѶ¼�в�����ϵ��
		int flag = 0;//��Ϊ���ұ��
		for (int i = 0; i < ab->size; i++)
		{
			if (name == (ab->parr[i]).name)
			{
				for (int j = i; j < ab->size - 1; j++)
				{
					ab->parr[j] = ab->parr[j + 1];
				}
				flag++;
				ab->size--;//Ҫ����ϵ��������һ
				cout << "��ϵ��ɾ�����" << endl;
				break;
			}
		}
		if (flag == 0)
			cout << "���޴���" << endl;
	}
}
void f4(addressbook* ab)//������ϵ��
{
	if (ab->size == 0)
		cout << "ͨѶ¼������ϵ��" << endl;
	else
	{
		string name;
		cout << "��������Ҫ���ҵ���ϵ������" << endl;
		cin >> name;
		int flag = 0;
		for (int i = 0; i < ab->size; i++)
		{
			if (name == ab->parr[i].name)
			{
				cout << "������" << (ab->parr[i]).name << endl;
				cout << "�Ա�" << (ab->parr[i]).sex << endl;
				cout << "���䣺" << (ab->parr[i]).age << endl;
				cout << "�绰���룺" << (ab->parr[i]).pnum << endl;
				cout << "��ͥסַ��" << (ab->parr[i]).address << endl;
				flag++;
				break;
			}
		}
		if (flag == 0)
			cout << "���޴���" << endl;
	}
}
void f5(addressbook* ab)//�޸���ϵ��
{
	if (ab->size == 0)
		cout << "ͨѶ¼������ϵ��" << endl;
	else
	{
		string name;
		cout << "��������Ҫ�޸ĵ���ϵ������" << endl;
		cin >> name;
		int flag = 0;
		for (int i = 0; i < ab->size; i++)
		{
			if (name == ab->parr[i].name)
			{
				person newperson;
				cout << "�������޸ĺ�����" << endl;
				cout << "������" << endl;
				cin >> newperson.name;
				cout << "�Ա�" << endl;
				cin >> newperson.sex;
				cout << "���䣺" << endl;
				cin >> newperson.age;
				cout << "�绰���룺" << endl;
				cin >> newperson.pnum;
				cout << "��ͥסַ��" << endl;
				cin >> newperson.address;
				ab->parr[i]=newperson;
				flag++;
				cout << "��ϵ���޸����" << endl;
				break;
			}
		}
		if (flag == 0)
			cout << "���޴���" << endl;
	}
}
void f6(addressbook* ab)
{
	//�߼���ֻҪ��ͨѶ¼��ϵ����������Ϊ0���� ��ʹԭ������Ҳ�ᱻ�������븲��
	ab->size = 0;
	cout << "ͨѶ¼������" << endl;
}
void showmenu()
{ 
	cout << endl;
	cout << "����ϸ�Ķ��������죡����" << endl;
	cout << '\t' << "ʵ��ĳ����������ָ�����ֲ����س���" << endl;
	cout << '\t' << "�����ϵ��������1" << endl;
	cout << '\t' << "��ʾ��ϵ��������2" << endl;
	cout << '\t' << "ɾ����ϵ��������3" << endl;
	cout << '\t' << "������ϵ��������4" << endl;
	cout << '\t' << "�޸���ϵ��������5" << endl;
	cout << '\t' << "�����ϵ��������6" << endl;
	cout << '\t' << "�˳�ͨѶ¼������0" << endl;
}