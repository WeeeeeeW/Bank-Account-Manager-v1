#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <list>
using namespace std;

//#include "List.h"

#define DB "Account.txt"


using namespace std;


struct acc {
	int id;
	string name;
	int balance;
};
list<acc> AllAcc;


void write_account();
void display_acc(int x);
void delete_acc(int x);
void display_all();
void deposit_withdraw(int x, int opt);
void intro();
void readFile();
void writeFile();
void modify(int x);

void readFile() {
	acc	a;
	ifstream inFile(DB);
	string line;

	if (!inFile)
	{
		cout << "File could not be open !! Press any Key...";
		return;
	}
	while (!inFile.eof()) {
		inFile >> a.id;
		getline(inFile, line);
		getline(inFile, a.name);
		inFile >> a.balance;
		getline(inFile, line);
		AllAcc.push_front(a);
	}
	AllAcc.pop_front();
	inFile.close();
}

void writeFile() {
	acc a;
	ofstream outFile;
	outFile.open(DB);
	int Size = AllAcc.size();
	while (!AllAcc.empty()) {
		a.id = AllAcc.back().id;
		a.name = AllAcc.back().name;
		a.balance = AllAcc.back().balance;
		outFile << a.id << endl << a.name << endl << a.balance << endl;
		AllAcc.pop_back();
	}
	outFile.close();
}


void write_account(){
	AllAcc.clear();
	readFile();
	acc a;
	int Size = AllAcc.size();
	cout << "\n--------------------ACCOUNT REGISTRATION-------------------                               Enter '0' to exit\n";
	cout << "\n\tEnter The account No.:";
	cin >> a.id;
	if (a.id == 0)
		return;
	while (a.id <= 100) {
		cout << "\tINVALID ACCOUNT NUMBER\n\tACCOUNT NUMBER MUST BE GREATER THAN 100\n\tPlease re-enter account number: ";
		cin >> a.id;
		if (a.id == 0)
			return;
	}
	for (int i = 0; i < Size; i++) {
		if (AllAcc.back().id == a.id) {
			cout<< "\n\tAccount number already existed, please choose another account number: ";
			i = -1;
			cin >> a.id;
			if (a.id == 0)
				return;
			while (a.id <= 100) {
				cout << "\tINVALID ACCOUNT NUMBER\n\tACCOUNT NUMBER MUST BE GREATER THAN 100\n\tPlease re-enter account number: ";
				cin >> a.id;
				if (a.id == 0)
					return;
				if (a.id == 0)
					return;
			}
			if (a.id == 0)
				return;
			AllAcc.clear();
			readFile();
		}
		else {
			AllAcc.pop_back();
		}
	}
	cout << "\n\tEnter The Name of The account Holder: ";
	cin.ignore();
	getline(cin, a.name);
	if (a.name.compare("0") == 0)
		return;
	cout << "\n\tEnter The Initial amount: ";
	cin >> a.balance;
	while (a.balance < 0) {
		cout << "\n\tIntitial amount cannot smaller than 0\n";
		cout << "\n\tEnter The Initial amount: ";
		cin >> a.balance;
	}
	readFile();
	AllAcc.push_front(a);
	writeFile();
	cout << "\n\t\t ACCOUNT CREATED";
}



void display_acc(int x) {
	acc a;
	AllAcc.clear();
	readFile();
	int Size = AllAcc.size();
	if (x == 0)
		return;
	while (x <= 100) {
		cout << "\tINVALID ACCOUNT NUMBER\n";
		cout << "\tEnter The account No. : ";
		cin >> x;
		if (x == 0)
			return;
	}
	while (!AllAcc.empty()) {
		if (AllAcc.back().id == x) {
			cout << "\n-----------------------ACCOUNT DETAIL----------------------\n";
			cout << "\n\tAccount No. : " << AllAcc.back().id;
			cout << "\n\tAccount Holder Name : " << AllAcc.back().name;
			cout << "\n\tBalance amount : " << AllAcc.back().balance;
			return;
		}
		AllAcc.pop_back();
	}
	cout << "\tACCOUNT NOT EXIST\n";
}

void display_all() {
	AllAcc.clear();
	readFile();
	int Size = AllAcc.size();
	if (Size == 0) {
		cout << "__________________________________________________\n";	
		cout << "|                                                 |\n";
		cout << "|                                                 |\n";
		cout << "|         THERE ARE NO ACCOUNT AT THE MOMENT      |\n";
		cout << "|                                                 |\n";
		cout << "|_________________________________________________|\n";
		return;
	}
	cout << "\n\n\t\tACCOUNT HOLDER LIST\n\n";
	cout << "====================================================\n";
	cout << "ACC NO.\t      NAME \t\t          BALANCE(VND)\n";
	cout << "====================================================\n";
	while(!AllAcc.empty()){
		cout << AllAcc.back().id << "\t      " << AllAcc.back().name << "\t\t  " << AllAcc.back().balance << endl;
		AllAcc.pop_back();
	}
}


void deposit_withdraw(int x, int opt) {
	int amount;
	list<acc> temp;
	ofstream outFile;
	bool check = false; 
	AllAcc.clear();
	readFile();
	int Size = AllAcc.size();
	cout << "\n--------------------ACCOUNT REGISTRATION-------------------     \n";
	if (x == 0)
		return;
	while (x <= 100) {
		cout << "\tINVALID ACCOUNT NUMBER\n";
		cout << "\tEnter The account No. : ";
		cin >> x;
		if (x == 0)
			return;
	}
	while (!AllAcc.empty()) {
		if (AllAcc.back().id == x) {
			cout << "\n-----------------------ACCOUNT DETAIL----------------------\n";
			cout << "\n\tAccount No. : " << AllAcc.back().id;
			cout << "\n\tAccount Holder Name : " << AllAcc.back().name;
			cout << "\n\tBalance amount : " << AllAcc.back().balance;
			check = true;
		}
		AllAcc.pop_back();
	}
	if (!check) {
		cout << "\tACCOUNT NOT EXIST\n";
		return;
	}
	AllAcc.clear();
	readFile();
	if (opt == 1) {
		cout << "\n\tEnter deposit amount: ";
		cin >> amount;
		if (amount == 0)
			return;
		while (amount < 0) {
			cout << "\tInvalid amount\n\tAmount must greater than 0\n\tPlease re-enter deposit amount: ";
			cin >> amount;
		}
		while (!AllAcc.empty()) {
			if (AllAcc.back().id == x) {
				AllAcc.back().balance += amount;
			}
			temp.push_front(AllAcc.back());
			AllAcc.pop_back();
		}
		AllAcc.clear();
		AllAcc.swap(temp);
		writeFile();
		cout << "\t\tBALANCE UPDATED";
	}
	else if (opt == 2) {
		cout << "\n\tEnter withdrawal amount: ";
		cin >> amount;
		if (amount == 0)
			return;
		while (amount < 0) {
			cout << "\tInvalid amount\n\tAmount must greater than 0\n\tPlease re-enter withdrawal amount: ";
			cin >> amount;
		}
		while (!AllAcc.empty()) {
			if (amount == 0)
				return;
			if (AllAcc.back().id == x) {
				if (amount > AllAcc.back().balance) {
					cout << "\n\tINSUFFICIENT BALANCE\n";
					return;
				}
				else
					AllAcc.back().balance -= amount;
			}
			temp.push_front(AllAcc.back());
			AllAcc.pop_back();
		}
		AllAcc.clear();
		AllAcc.swap(temp);
		writeFile();
		cout << "\t\tBALANCE UPDATED";
	}
}

void delete_acc(int x) {
	list<acc> temp;
	ofstream outFile;
	bool check = false;
	AllAcc.clear();
	readFile();
	if (x == 0) {
		return;
	}
	while (x <= 100) {
		cout << "\tINVALID ACCOUNT NUMBER\n";
		cout << "\tEnter The account No. : ";
		cin >> x;
		if (x == 0)
			return;
	}
	while (!AllAcc.empty()) {
		if (AllAcc.back().id == x) {
			check = true;
		}
		AllAcc.pop_back();
	}
	if (!check) {
		cout << "\tACCOUNT NOT EXIST\n";
		return;
	}
	AllAcc.clear();
	readFile();
	while (!AllAcc.empty()) {
		if (AllAcc.back().id != x) {
			temp.push_front(AllAcc.back());
		}
		AllAcc.pop_back();
	}
	AllAcc.clear();
	AllAcc.swap(temp);
	writeFile();
	cout << "--------------------ACCOUNT DELETED--------------------";
}

void modify(int x) {
	int amount;
	list<acc> temp;
	ofstream outFile;
	bool check = false;
	AllAcc.clear();
	readFile();
	int Size = AllAcc.size();
	if (x == 0)
		return;
	while (x <= 100) {
		cout << "\tINVALID ACCOUNT NUMBER\n";
		cout << "\tEnter The account No. : ";
		cin >> x;
		if (x == 0)
			return;
	}
	while (!AllAcc.empty()) {
		if (AllAcc.back().id == x) {
			cout << "\n-----------------------ACCOUNT DETAIL----------------------\n";
			cout << "\n\tAccount No. : " << AllAcc.back().id;
			cout << "\n\tAccount Holder Name : " << AllAcc.back().name;
			cout << "\n\tBalance amount : " << AllAcc.back().balance;
			check = true;
		}
		AllAcc.pop_back();
	}
	if (!check) {
		cout << "\tACCOUNT NOT EXIST\n";
		return;
	}
	cout << "\n-----------------------ACCOUNT UPDATE----------------------\n";
	AllAcc.clear();
	readFile();
	while (!AllAcc.empty()) {
		if (AllAcc.back().id == x) {
			cout << "\n\tAccount No. : " << AllAcc.back().id;
			cout << "\n\tAccount Holder Name : " ;
			cin.ignore();
			getline(cin, AllAcc.back().name);
			cout << "\tBalance amount : " ;
			cin >> AllAcc.back().balance;
			if (AllAcc.back().balance < 0 || AllAcc.back().name.compare("0") == 0) {
				cout << "\t\tUPDATE FAILED";
				return;
			}
			check = true;
		}
		temp.push_front(AllAcc.back());
		AllAcc.pop_back();
	}
	AllAcc.clear();
	AllAcc.swap(temp);
	writeFile();
	cout << "\t\tACCOUNT UPDATED";
}
void intro()
{
	cout << "\n\n\n\t  BANK";
	cout << "\n\n\tMANAGEMENT";
	cout << "\n\n\t  SYSTEM";
	cout << "\n\n\n\nMADE BY : HOANG NHAT MINH-A29785";
	cout << "\n\nSCHOOL : TLU";
	cin.get();
}