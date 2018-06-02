#include<iostream>
#include "Account.h"
int main()
{
	int ch;
	int num;
	intro();
	do
	{
		ch = 0;
		system("cls");
		cout << "\n\n\n\tMAIN MENU";
		cout << "\n\n\t01. OPEN ACCOUNT";
		cout << "\n\n\t02. DEPOSIT";
		cout << "\n\n\t03. WITHDRAW";
		cout << "\n\n\t04. CHECK BALANCE";
		cout << "\n\n\t05. ALL ACCOUNT HOLDER LIST";
		cout << "\n\n\t06. CLOSE AN ACCOUNT";
		cout << "\n\n\t07. MODIFY AN ACCOUNT";
		cout << "\n\n\t08. EXIT";
		cout << "\n\n\tSelect Your Option (1-8) ";
		cin >> ch;
		system("cls");
		switch (ch)
		{
		case 1:
			write_account();
			break;
		case 2:
			cout << "\t\t\t\t                                              Enter '0' to exit\n ";
			cout << "\tEnter The account No. :"; 
			cin >> num;
			deposit_withdraw(num, 1);
			break;
		case 3:
			cout << "\t\t\t\t                                              Enter '0' to exit\n ";
			cout << "\tEnter The account No. : "; 
			cin >> num;
			deposit_withdraw(num, 2);
			break;
		case 4:
			cout << "\t\t\t\t                                              Enter '0' to exit\n ";
			cout << "\tEnter The account No. : "; 
			cin >> num;
			display_acc(num);
			break;
		case 5:
			display_all();
			break;
		case 6:
			cout << "\t\t\t\t                                              Enter '0' to exit\n ";
			cout << "\tEnter The account No. : "; 
			cin >> num;
			delete_acc(num);
			break;
		case 7:
			cout << "\t\t\t\t                                              Enter '0' to exit\n ";
			cout << "\tEnter The account No. : ";
			cin >> num;
			modify(num);
			break;
		case 8:
			cout <<"\n\n\tTHANK YOU FOR USING MY BANK ACCOUNT MANAGER \n"<< "\n\n\tClosing...";
			break;
		default:
				cout << "PLEASE CHOOSE A VALID FEATURE";
		}
		cin.clear();
		cin.ignore(10,'\n');
		cin.get();
	} while (ch != 8);
	return 0;
}

