#include<iostream>
#include<string>
using namespace std;
#define MAX 1000
struct Person
{
	string name;//姓名
	int sex;//性别：1 boy;2 girl
	int age;//年龄
	string phone;//电话
	string addr;//住址
};

struct Addressbooks
{
	struct Person personarray[MAX];
	int size;
};

//添加联系人
void AddPerson(Addressbooks* abs)
{
	//判断通讯录是否已满
	if (abs->size == MAX)
	{
		cout << "通讯录已满" << endl;
	}
	else
	{
		string name;
		cout << "请输入姓名：" << endl;
		cin >> name;
		abs->personarray[abs->size].name = name;

		int sex = 0;
		cout << "请输入性别：" << endl;
		cout << "1--男" << endl;
		cout << "2--女" << endl;
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personarray[abs->size].sex = sex;
				break;
			}
			cout << "输入有误，请重新输入！" << endl;
		}
		int age = 0;
		cout << "请输入年龄：" << endl;
		cin >> age;
		abs->personarray[abs->size].age = age;

		string phone;
		cout << "请输入电话：" << endl;
		cin >> phone;
		abs->personarray[abs->size].phone = phone;

		string addr;
		cout << "请输入住址：" << endl;
		cin >> addr;
		abs->personarray[abs->size].addr = addr;

		abs->size++;//更新通讯录人数
		cout << "添加成功！" << endl;

		system("pause");//按任意键结束
		system("cls");//清屏
	}
}

//显示联系人
void showPerson(Addressbooks* abs)
{
	if (abs->size == 0)
	{
		cout << "通讯录记录为空" << endl;
	}
	else
	{
		for (int i = 0; i < abs->size; i++)
		{
			cout << "姓名：" << abs->personarray[i].name << "\t\t";
			cout << "性别：" << (abs->personarray[i].sex == 1 ? "男" : "女") << "\t\t";
			cout << "年龄：" << abs->personarray[i].age << "\t\t";
			cout << "电话：" << abs->personarray[i].phone << "\t\t";
			cout << "住址：" << abs->personarray[i].addr << endl;
		}
	}
	system("pause");
	system("cls");
}

//检测通讯录是否存在联系人
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

//删除联系人
void delPerson(Addressbooks* abs)
{
	string name;
	cout << "请输入联系人姓名：" << endl;
	cin >> name;
	if (testPerson(abs, name) == -1)
	{
		cout << "通讯录中没有这个联系人！" << endl;
	}
	else
	{
		for (int i = testPerson(abs, name); i < abs->size; i++)
		{
			abs->personarray[i] = abs->personarray[i + 1];
		}
		abs->size--;//更新通讯录人员数
		cout << "删除成功！" << endl;
	}
	system("pause");
	system("cls");
}

//查找联系人
void searchPerson(Addressbooks* abs)
{
	string name;
	cout << "请输入联系人姓名：" << endl;
	cin >> name;
	if (testPerson(abs, name) == -1)
	{
		cout << "通讯录中没有这个联系人！" << endl;
	}
	else
	{
		int i = testPerson(abs, name);
		cout << "姓名：" << abs->personarray[i].name << "\t\t";
		cout << "性别：" << (abs->personarray[i].sex == 1 ? "男" : "女") << "\t\t";
		cout << "年龄：" << abs->personarray[i].age << "\t\t";
		cout << "电话：" << abs->personarray[i].phone << "\t\t";
		cout << "住址：" << abs->personarray[i].addr << endl;
	}
	system("pause");//按任意键结束
	system("cls");//清屏
}

//修改联系人
void changPerson(Addressbooks* abs)
{
	string name;
	cout << "请输入联系人姓名：" << endl;
	cin >> name;
	if (testPerson(abs, name) == -1)
	{
		cout << "通讯录中没有这个联系人！" << endl;
	}
	else
	{
		int i = testPerson(abs, name);
		cout << "请输入联系人姓名：" << endl;
		cin >> abs->personarray[i].name;
		cout << "请输入联系人性别：" << endl;
		cin >> abs->personarray[i].sex;
		cout << "请输入联系人年龄：" << endl;
		cin >> abs->personarray[i].age;
		cout << "请输入联系人电话：" << endl;
		cin >> abs->personarray[i].phone; 
		cout << "请输入联系人地址：" << endl;
		cin >> abs->personarray[i].addr;
	}
	cout << "修改成功!" << endl;
	system("pause");
	system("cls");
}

void showMenu()
{
	cout << "*-*-*-*-*-*-*-*-*-*-* 通讯录管理系统*-*-*-*-*-*-*-*-*-*-*\n";
	cout << "*-*-*-*-*-*-*-*-*-*-* 1、添加联系人 *-*-*-*-*-*-*-*-*-*-*\n";
	cout << "*-*-*-*-*-*-*-*-*-*-* 2、显示联系人 *-*-*-*-*-*-*-*-*-*-*\n";
	cout << "*-*-*-*-*-*-*-*-*-*-* 3、删除联系人 *-*-*-*-*-*-*-*-*-*-*\n";
	cout << "*-*-*-*-*-*-*-*-*-*-* 4、查找联系人 *-*-*-*-*-*-*-*-*-*-*\n";
	cout << "*-*-*-*-*-*-*-*-*-*-* 5、修改联系人 *-*-*-*-*-*-*-*-*-*-*\n";
	cout << "*-*-*-*-*-*-*-*-*-*-* 6、清空联系人 *-*-*-*-*-*-*-*-*-*-*\n";
	cout << "*-*-*-*-*-*-*-*-*-*-* 0、退出通讯录 *-*-*-*-*-*-*-*-*-*-*\n";
}

void cleanPerson(Addressbooks* abs)
{
	abs->size = 0;
	cout << "清空通讯录成功！" << endl;
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
		cout << "请输入您的选择：" << endl;
		cin >> select;
		switch (select)
		{
		case 1://添加
			AddPerson(&abs);
			break;
		case 2://显示
			showPerson(&abs);
			break;
		case 3://删除
			delPerson(&abs);
			break;
		case 4://查找
			searchPerson(&abs);
			break;
		case 5://修改
			changPerson(&abs);
			break;
		case 6://清空
			cleanPerson(&abs);
			break;
		case 0:
			cout << "欢迎下次使用" << endl;
			//system("pause");
			exit(0);
			break;
		default:
			cout << "输入错误，请重新输入" << endl;
			break;
		}
	}
	return 0;
}