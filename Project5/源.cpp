#include<iostream>
#include<string>
using namespace std;
#define MAX 1000
struct Person
{
	string name;//����
	int sex;//�Ա�1 boy;2 girl
	int age;//����
	string phone;//�绰
	string addr;//סַ
};

struct Addressbooks
{
	struct Person personarray[MAX];
	int size;
};

//�����ϵ��
void AddPerson(Addressbooks* abs)
{
	//�ж�ͨѶ¼�Ƿ�����
	if (abs->size == MAX)
	{
		cout << "ͨѶ¼����" << endl;
	}
	else
	{
		string name;
		cout << "������������" << endl;
		cin >> name;
		abs->personarray[abs->size].name = name;

		int sex = 0;
		cout << "�������Ա�" << endl;
		cout << "1--��" << endl;
		cout << "2--Ů" << endl;
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personarray[abs->size].sex = sex;
				break;
			}
			cout << "�����������������룡" << endl;
		}
		int age = 0;
		cout << "���������䣺" << endl;
		cin >> age;
		abs->personarray[abs->size].age = age;

		string phone;
		cout << "������绰��" << endl;
		cin >> phone;
		abs->personarray[abs->size].phone = phone;

		string addr;
		cout << "������סַ��" << endl;
		cin >> addr;
		abs->personarray[abs->size].addr = addr;

		abs->size++;//����ͨѶ¼����
		cout << "��ӳɹ���" << endl;

		system("pause");//�����������
		system("cls");//����
	}
}

//��ʾ��ϵ��
void showPerson(Addressbooks* abs)
{
	if (abs->size == 0)
	{
		cout << "ͨѶ¼��¼Ϊ��" << endl;
	}
	else
	{
		for (int i = 0; i < abs->size; i++)
		{
			cout << "������" << abs->personarray[i].name << "\t\t";
			cout << "�Ա�" << (abs->personarray[i].sex == 1 ? "��" : "Ů") << "\t\t";
			cout << "���䣺" << abs->personarray[i].age << "\t\t";
			cout << "�绰��" << abs->personarray[i].phone << "\t\t";
			cout << "סַ��" << abs->personarray[i].addr << endl;
		}
	}
	system("pause");
	system("cls");
}

//���ͨѶ¼�Ƿ������ϵ��
int testPerson(Addressbooks *abs, string name)
{
	for (int i = 0; i < abs->size; i++)
	{
		if (abs->personarray[i].name == name)
		{
			return i;
		}		
	}
	return -1;
}

//ɾ����ϵ��
void delPerson(Addressbooks* abs)
{
	string name;
	cout << "��������ϵ��������" << endl;
	cin >> name;
	if (testPerson(abs, name) == -1)
	{
		cout << "ͨѶ¼��û�������ϵ�ˣ�" << endl;
	}
	else
	{
		for (int i = testPerson(abs, name); i < abs->size; i++)
		{
			abs->personarray[i] = abs->personarray[i + 1];
		}
		abs->size--;//����ͨѶ¼��Ա��
		cout << "ɾ���ɹ���" << endl;
	}
	system("pause");
	system("cls");
}

//������ϵ��
void searchPerson(Addressbooks* abs)
{
	string name;
	cout << "��������ϵ��������" << endl;
	cin >> name;
	if (testPerson(abs, name) == -1)
	{
		cout << "ͨѶ¼��û�������ϵ�ˣ�" << endl;
	}
	else
	{
		int i = testPerson(abs, name);
		cout << "������" << abs->personarray[i].name << "\t\t";
		cout << "�Ա�" << (abs->personarray[i].sex == 1 ? "��" : "Ů") << "\t\t";
		cout << "���䣺" << abs->personarray[i].age << "\t\t";
		cout << "�绰��" << abs->personarray[i].phone << "\t\t";
		cout << "סַ��" << abs->personarray[i].addr << endl;
	}
	system("pause");//�����������
	system("cls");//����
}

//�޸���ϵ��
void changPerson(Addressbooks* abs)
{
	string name;
	cout << "��������ϵ��������" << endl;
	cin >> name;
	if (testPerson(abs, name) == -1)
	{
		cout << "ͨѶ¼��û�������ϵ�ˣ�" << endl;
	}
	else
	{
		int i = testPerson(abs, name);
		cout << "��������ϵ��������" << endl;
		cin >> abs->personarray[i].name;
		cout << "��������ϵ���Ա�" << endl;
		cin >> abs->personarray[i].sex;
		cout << "��������ϵ�����䣺" << endl;
		cin >> abs->personarray[i].age;
		cout << "��������ϵ�˵绰��" << endl;
		cin >> abs->personarray[i].phone; 
		cout << "��������ϵ�˵�ַ��" << endl;
		cin >> abs->personarray[i].addr;
	}
	cout << "�޸ĳɹ�!" << endl;
	system("pause");
	system("cls");
}

void showMenu()
{
	cout << "*-*-*-*-*-*-*-*-*-*-* ͨѶ¼����ϵͳ*-*-*-*-*-*-*-*-*-*-*\n";
	cout << "*-*-*-*-*-*-*-*-*-*-* 1�������ϵ�� *-*-*-*-*-*-*-*-*-*-*\n";
	cout << "*-*-*-*-*-*-*-*-*-*-* 2����ʾ��ϵ�� *-*-*-*-*-*-*-*-*-*-*\n";
	cout << "*-*-*-*-*-*-*-*-*-*-* 3��ɾ����ϵ�� *-*-*-*-*-*-*-*-*-*-*\n";
	cout << "*-*-*-*-*-*-*-*-*-*-* 4��������ϵ�� *-*-*-*-*-*-*-*-*-*-*\n";
	cout << "*-*-*-*-*-*-*-*-*-*-* 5���޸���ϵ�� *-*-*-*-*-*-*-*-*-*-*\n";
	cout << "*-*-*-*-*-*-*-*-*-*-* 6�������ϵ�� *-*-*-*-*-*-*-*-*-*-*\n";
	cout << "*-*-*-*-*-*-*-*-*-*-* 0���˳�ͨѶ¼ *-*-*-*-*-*-*-*-*-*-*\n";
}

void cleanPerson(Addressbooks* abs)
{
	abs->size = 0;
	cout << "���ͨѶ¼�ɹ���" << endl;
	system("pause");
	system("cls");
}
int main()
{
	int select = 0;
	Addressbooks abs;
	abs.size = 0;
	
	
	while (true)
	{
		showMenu();
		cout << "����������ѡ��" << endl;
		cin >> select;
		switch (select)
		{
		case 1://���
			AddPerson(&abs);
			break;
		case 2://��ʾ
			showPerson(&abs);
			break;
		case 3://ɾ��
			delPerson(&abs);
			break;
		case 4://����
			searchPerson(&abs);
			break;
		case 5://�޸�
			changPerson(&abs);
			break;
		case 6://���
			cleanPerson(&abs);
			break;
		case 0:
			cout << "��ӭ�´�ʹ��" << endl;
			//system("pause");
			exit(0);
			break;
		default:
			cout << "�����������������" << endl;
			break;
		}
	}
	return 0;
}