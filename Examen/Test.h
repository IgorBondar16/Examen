#pragma once
#include <iostream>�
#include"Menu.h"
using namespace std;

class User{
	string name;
	string password;
public:
	User();
	User(string name, string pass);
	virtual ~User();
	virtual void menu() const = 0;
protected:
	void setName();
	void setPassword();
	void getName() const;
	void getPassword() const;
};

User::User() : name("no name"), password("no pass") {};

User::User(string name, string pass) : name(name), password(pass) {};

User::~User(){}

class Student : public User
{
	string number;
	string address;
	string FIO;
protected:
	Student();
	Student(string name, string pass, string number, string address, string FIO);
	virtual ~Student();
	virtual void menu() const override;

	void setNumber();
	void setAddress();
	void setFIO();
	void getNumber() const;
	void getAddress() const;
	void get_FIO() const;

	void viewing_previons_tests();//���������� ���������� ����� � �� ����������
	void take_a_test();//������ ����
	void contine_test();//���������� ����
};

Student::Student() : User(), number("no number"), address("no address"), FIO("no FIO") {};

Student::Student(string name, string pass, string number, string address, string FIO)
	: User(name, pass), number(number), address(address), FIO(FIO) {};

Student::~Student() {}

void Student::menu() const
{
	do {
		system("cls");
		int choice = Menu::select_vertical(
			{ "�������� ��������i� ���������i�",
			"������ ����",
			"���������� ����",
			"�����" },
			HorizontalAlignment::Center);
		switch (choice)
		{
		case 0: /*viewing_previons_tests();;*/		break;
		case 1: /*take_a_test();*/					break;
		case 2: /*contine_test();*/					break;
		case 3: return;
		}
	} while (true);
}

class Admin : public User
{
protected:
	Admin();
	Admin(string name, string pass);
	virtual void menu() const override;

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
	void add_category();// ������� ���������
	void add_questions();//�������� �������
	void inport_txt();// ������������� �� �����
	void export_txt();// �������������� � ����
};

Admin::Admin() :User() {};

Admin::Admin(string name, string pass) : User(name, pass) {};

void Admin::menu() const
{
	do {
		system("cls");
		int choice = Menu::select_vertical(
			{ "������i��� �������������",
			"�������� ����������",
			"��������� ������������",
			"�����" },
			HorizontalAlignment::Center);
		switch (choice)
		{
		case 0: /*menegment_user();*/		break;
		case 1: /*statistic();*/			break;
		case 2: /*menegment_tests();*/		break;
		case 3: return;
		}
	} while (true);
}

class Testing_system
{
	User* users;
	void login();
	void Registration();
public:
	Testing_system();
	~Testing_system();
	virtual void menu() const ;
};

Testing_system::Testing_system() : users(nullptr) {}
Testing_system::~Testing_system() { /*delete[] users;*/ }

void Testing_system::menu() const
{
	do {
		system("cls");
		int choice = Menu::select_vertical(
			{ "��i���",
			"��������������",
			"�����" },
			HorizontalAlignment::Center);
		switch (choice)
		{
		case 0: /*login();*/		break;
		case 1: /*Registration();*/ break;
		case 2: return;
		}
	} while (true);
}