#pragma once
#include <iostream>�
#include"Menu.h"
#include<list>
#include"BTree.h"

using namespace std;

class test 
{
	string title;
	size_t size;
	list<string> question;
protected:
	test() : title("no name"), size(0) {}
	test(string title, size_t size) : title(title), size(size = 1) {}
	void print();
	void setTitle(string name);
	void setQuestion();
	string getTitle();
	size_t getSize();
	string getQuestion();
public:
	void go_test();
};

void test::print()
{
	cout << "����� : " << this->getTitle();
	cout << "ʳ������ �������� : " << this->getSize();
}

void test::setTitle(string name){	this->title = name;	}

size_t test::getSize() { return size; }

string test::getTitle() { return title; }

void test::go_test()
{
	print();

}

class User
{
	string name;
	string password;
public:
	User();
	User(string name, string pass);
	virtual void menu() = 0;
	virtual ~User();
	string getName() const;
	string getPassword() const;
	void setName(string name);
	void setPassword(string pass);

	friend ostream& operator<<(ostream& out, const User* p);
	friend istream& operator>>(istream& in, User* p);
	
};	

User::User() : name("no name"), password("no pass") {};

User::User(string name, string pass) : name(name) { setPassword(pass); };

User::~User(){}

void User::setName(string name){	this->name = name;	}

string User::getName() const{	return name;	}

void User::setPassword(string pass) {	password = pass;	}

string User::getPassword() const {	return password; }

//istream& operator>>(istream& in, User* p)
//{
//	cout << " Name : "; getline(in, p->name);
//	return in;
//}

class Student : public User
{
	string number;
	string address;
	string FIO;
public:
	Student();
	Student(string name, string pass, string number, string address, string FIO);
	virtual ~Student();
	virtual void menu() override;

	void setNumber(string number) { this->number = number; }
	void setAddress(string address) { this->address = address; }
	void setFIO(string fio) { FIO = fio; }
	string getNumber() const { return number; }
	string getAddress()  const { return address; }
	string get_FIO() const { return FIO; }

	void viewing_previons_tests();//���������� ���������� ����� � �� ����������
	void take_a_test();//������ ����
	void contine_test();//���������� ����

	void profil();
};

Student::Student() : User(), number("no number"), address("no address"), FIO("no FIO") {};

Student::Student(string name, string pass, string number, string address, string FIO)
	: User(name, pass), number(number), address(address), FIO(FIO) {};

Student::~Student() {}

void Student::menu()
{
	do {
		system("cls");
		cout << "\n\n\n\n\n\n\t\t\t\t����i�� �������� : " << User::getName();
		int choice = Menu::select_vertical(
			{ "�������� ��������i� ���������i�",
			"������ ����",
			"���������� ����",
			"����������� �������",
			"�����" },
			HorizontalAlignment::Center);
		switch (choice)
		{
		case 0: /*viewing_previons_tests();*/		break;
		case 1: /*take_a_test();*/					break;
		case 2: /*contine_test();*/					break;
		case 3: profil();							break;
		case 4: return;
		}
	} while (true);
}

void Student::profil()
{
	cout << "Name - " << this->getName();
	cout << "\nFIO - " << this->get_FIO();
	cout << "\nNumber - " << this->getNumber();
	cout << "\nAddress - " << this->getAddress();
	cout << "\nPassword - " << this->getPassword();
	cout << "\n";
	system("pause");
}

void Student::viewing_previons_tests()
{

}

void Student::take_a_test()
{

}

void Student::contine_test()
{

}

class Admin : public User, public test
{
	BTree<string, list<test*>> tests;
public:
	Admin();
	Admin(string name, string pass);
	virtual void menu() override;

	void menegment_user();// ��������� �������������
	void add_user();//������ �����������
	void delete_user();// ������� �����������
	void user_modification();// �������� �������� ������������

	void statistic();//����������
	void statistic_categories();//�� ��������
	void statistic_test();// �� �����
	void statistic_user();//�� ������������
	void statistic_output_fille();//��������� ���������� � ����

	void menegment_tests();// ���������� �������
	void add_test();// �������� ����
	void delete_test();
	void add_category();//  ���������
	void delete_category();
	void add_questions();//�������� �������
	void delete_questions();
	void inport_txt();// ������������� �� �����
	void export_txt();// �������������� � ����
};

Admin::Admin() :User() {};

Admin::Admin(string name, string pass) : User(name, pass) {};

void Admin::menu()
{
	do {
		system("cls");
		cout << "\n\n\n\n\n\n\t\t\t\t����i�� ����� : " << User::getName();
		int choice = Menu::select_vertical(
			{ "������i��� �������������",
			"�������� ����������",
			"��������� ������������",
			"�����" },
			HorizontalAlignment::Center);
		switch (choice)
		{
		case 0: menegment_user();		break;
		case 1: //statistic();			break;
		case 2: menegment_tests();		break;
		case 3: return;
		}
	} while (true);
}

void Admin::menegment_user()
{
	do {
		system("cls");
		cout << "\n\n\n\n\n\n\t\t\t\t��������� ������������� ";
		int choice = Menu::select_vertical(
			{ "������ �����������",
			"�������� �����������",
			"������ ���������� �����������",
			"�����" },
			HorizontalAlignment::Center);
		switch (choice)
		{
		case 0: //add_user();					break;
		case 1: /*delete_user();*/			break;
		case 2: /*user_modification();*/	break;
		case 3: return;
		}
	} while (true);
}

void statistic() {
	do {
		system("cls");
		cout << "\n\n\n\n\n\n\t\t\t\t���������� ";
		int choice = Menu::select_vertical(
			{ "�� ����������",
			"�� ������",
			"�� ���������",
			"�����" },
			HorizontalAlignment::Center);
		switch (choice)
		{
		case 0: /*statistic_categories();*/		break;
		case 1: /*statistic_test;*/			break;
		case 2: /*statistic_user();*/		break;
		case 3: return;
		}
	} while (true);
}

void Admin::menegment_tests()
{
	do {
		system("cls");
		cout << "\n\n\n\n\n\n\t\t\t\t��������� ������� ";
		int choice = Menu::select_vertical(
			{ "������ ���� ",
			"�������� ���� ",
			"������ �������� ",
			"�������� ��������",
			"�����" },
			HorizontalAlignment::Center);
		switch (choice)
		{
		case 0: /*add_test();*/		break;
		case 1: /*delete_test();*/			break;
		case 2: /*add_category();*/		break;
		case 3: /*delete_category();*/		break;
		case 4: return;
		}
	} while (true);
}

class Testing_system
{
	/*list<User*> user;
	size_t size;*/
	BTree<string, list<User*>> user;
	void login();
	void Registration();
public:
	Testing_system();
	~Testing_system();
	virtual void menu();
};

Testing_system::Testing_system() {}
Testing_system::~Testing_system() {  }



void Testing_system::menu()
{
	do {
		system("cls");
		int choice = Menu::select_vertical(
			{ "��i���",
			"��������������",
			"������������",
			"�����" },
			HorizontalAlignment::Center);
		switch (choice)
		{
		case 0: login();		break;
		case 1: Registration(); break;
		case 2: settingConsole(); break;
		case 3: exit(0);
		}
	} while (true);
}

void Testing_system::Registration()
{
	string new_name, new_pass;
	cout << "Name :"; getline(cin, new_name);
	
	list<User*>* new_list = user.getValue(new_name);
	if (!new_list) {
		cout << "Password :"; getline(cin, new_pass);
		if (user.isEmpty() == 1) {
			User* admin = new Admin(new_name, new_pass);
			list<User*> newList;
			newList.push_back(admin);
			user.push_r(admin->getName(), newList);
			admin->menu();
		}
		else {
			string new_FIO, new_number, new_address;
			cout << "FIO :"; getline(cin, new_FIO);
			cout << "Mobile number :"; getline(cin, new_number);
			cout << "Home address :"; getline(cin, new_address);
			User* student = new Student(new_name, new_pass, new_FIO, new_number, new_address);
			list<User*> newList;
			newList.push_back(student);
			user.push_r(student->getName(), newList);
			student->menu();
		}
	}
	else { cout << "�� ��'� ������� "; system("pause");	}
}

void Testing_system::login()
{
	
	//for(User* u : user)
	//{
	//	if (user == new_name)
	//	{

	//	}
	//}
	/*for (size_t i = 0; i < user.size(); i++)
	{
		if (new_name == user.rend()) {}
	}*/
	string name;
	getline(cin, name);
	list<User*>* list = user.getValue(name);
	if (!list) 
	{ 
		cout << "������� �� �������� \n";
		system("pause");
		system("cls");
		Registration(); }
	else 
	{
	/*	string pass;
		getline(cin, pass);
		if(pass == user.getPassword())*/
		
	}

}