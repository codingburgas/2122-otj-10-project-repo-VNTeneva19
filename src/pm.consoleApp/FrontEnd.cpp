#include<iostream>

#include "FrontEnd.h"
#include "BackEnd.h"
#include "../pm.types/User.h"

using namespace std;

int c = 1;

HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);

void Menu::clearScreen()
{
	COORD cursor;

	cursor.X = 0;
	cursor.Y = 0;

	SetConsoleCursorPosition(console, cursor);
}

void Menu::gotoXY(int x, int y)
{
	COORD coords;

	coords.X = x;
	coords.Y = y;

	SetConsoleCursorPosition(console, coords);
}

//Menu options
void Menu::displayOptions()
{
	system("cls");

	bool here2 = true;
	int y = 14, choice = 0;

	while (here2 == true)
	{
		gotoXY(50, 0); cout << "*--------------------------------------------------------------*" << endl;
		gotoXY(50, 1); cout << ":                                                              :" << endl;
		gotoXY(50, 2); cout << ":  _______  _______  _______  ___   _______  __    _  _______  :" << endl;
		gotoXY(50, 3); cout << ": |       ||       ||       ||   | |       ||  |  | ||       | :" << endl;
		gotoXY(50, 4); cout << ": |   _   ||    _  ||_     _||   | |   _   ||   |_| ||  _____| :" << endl;
		gotoXY(50, 5); cout << ": |  | |  ||   |_| |  |   |  |   | |  | |  ||       || |_____  :" << endl;
		gotoXY(50, 6); cout << ": |  |_|  ||    ___|  |   |  |   | |  |_|  ||  _    ||_____  | :" << endl;
		gotoXY(50, 7); cout << ": |       ||   |      |   |  |   | |       || | |   | _____| | :" << endl;
		gotoXY(50, 8); cout << ": |_______||___|      |___|  |___| |_______||_|  |__||_______| :" << endl;
		gotoXY(50, 9); cout << ":                                                              :" << endl;
		gotoXY(50, 10); cout << ":                                                              :" << endl;
		gotoXY(50, 11); cout << "*--------------------------------------------------------------*" << endl;


		gotoXY(75, 14); cout << "Display List";
		gotoXY(75, 15); cout << "Push to the end";
		gotoXY(75, 16); cout << "Push to the front";
		gotoXY(75, 17); cout << "Find event(s)";
		gotoXY(75, 18); cout << "Change event's info";
		gotoXY(75, 19); cout << "Delete event(s)\n";
		gotoXY(75, 20); cout << "Go Back\n";

		system("pause>nul");

		if (GetAsyncKeyState(VK_DOWN) && y != 20)
		{
			gotoXY(72, y); cout << "  ";
			y++;
			gotoXY(72, y); cout << "-> ";
			choice++;
			continue;
		}

		if (GetAsyncKeyState(VK_UP) && y != 14)
		{
			gotoXY(72, y); cout << "  ";
			y--;
			gotoXY(72, y); cout << "-> ";
			choice--;
			continue;
		}


		if (GetAsyncKeyState(VK_RETURN))
		{
			system("cls");

			switch (choice)
			{
			case 0:
			{
				if (name == "")
				{
					cout << "You must be logged into your account to use this benefits";
					Sleep(1500);
					displaySigninOptions();
				}
				else {
					list.loadFromFile(name + "-data");
					displayList();

					system("pause>nul");
					system("cls");
				}
			} break;
			case 1:
			{
				if (name == "")
				{
					cout << "You must be logged into your account to use this benefits";
					Sleep(1500);
					displaySigninOptions();
				}
				{
					pushBack();
					list.saveToFile(name + "-data");
				}
			} break;
			case 2:
			{
				if (name == "")
				{
					cout << "You must be logged into your account to use this benefits";
					Sleep(1500);
					displaySigninOptions();
				}
				{
					pushFront();
					list.saveToFile(name + "-data");
				}
			} break;
			case 3:
			{
				if (name == "")
				{
					cout << "You must be logged into your account to use this benefits";
					Sleep(1500);
					displaySigninOptions();
				}
				else
				{
					list.loadFromFile(name + "-data");
					findEvents();
					system("pause>nul");
					system("cls");
				}
			} break;
			case 4:
			{
				if (name == "")
				{
					cout << "You must be logged into your account to use this benefits";
					Sleep(1500);
					displaySigninOptions();
				}
				else
				{
					list.loadFromFile(name + "-data");
					changeInfo();
					list.saveToFile(name + "-data");
					system("cls");
				}
			} break;
			case 5:
			{
				if (name == "")
				{
					cout << "You must be logged into your account to use this benefits";
					Sleep(1500);
					displaySigninOptions();
				}
				else
				{
					list.loadFromFile(name + "-data");
					deleteEvents();
					list.saveToFile(name + "-data");
					system("cls");
				}
			} break;
			case 6:
			{
				displaySigninOptions();
				break;
			}break;
			} //switch
		}
	}
}

void Menu::displayList()
{
	EventsList::DATA data1;
	list.moveToFirst();

	while (list.getData(data1) == true)
	{
		cout << data1.year << "." << data1.month << '.' << data1.day << " |Subject - ";

		if (strlen(data1.subject) == 0)
			cout << "Unknown";
		else
			cout << data1.subject;

		cout << " |Leader - ";

		if (strlen(data1.leader) == 0)
			cout << "Unknown";
		else
			cout << data1.leader;

		cout << " |Place - ";

		if (strlen(data1.place) == 0)
			cout << "Unknown";
		else
			cout << data1.place;

		cout << endl;
		list.moveToNext();
	}
}

void Menu::pushBack()
{
	EventsList::DATA data;

	gotoXY(75, 0); cout << "! IF YOU DON'T KNOW OR DON'T WANT TO GIVE DETAILS ABOUT THE DATE -> TYPE \"0\" !" << endl;
	gotoXY(75, 0); cout << "! IF YOU DON'T KNOW SOMETHING BELOW THE DATE PRESS ENTER !" << endl << endl;

	gotoXY(75, 14); cout << "Please enter the year of the event: "; cin >> data.year;
	gotoXY(75, 15); cout << "Please enter the month of the event: "; cin >> data.month;
	gotoXY(75, 16); cout << "Please enter the day of the event: "; cin >> data.day; cin.ignore();
	gotoXY(75, 17); cout << "Please enter the name of the event: "; cin.getline(data.subject, sizeof(data.subject));
	gotoXY(75, 18); cout << "Please enter the leader of the event: "; cin.getline(data.leader, sizeof(data.leader));
	gotoXY(75, 19); cout << "Please enter the place where the event happened: "; cin.getline(data.place, sizeof(data.place));

	list.pushBack(data);
	system("cls");
}

void Menu::pushFront()
{
	EventsList::DATA data;

	gotoXY(75, 0); cout << "! IF YOU DON'T KNOW OR DON'T WANT TO GIVE DETAILS ABOUT THE DATE -> TYPE \"0\" !" << endl;
	gotoXY(75, 0); cout << "! IF YOU DON'T KNOW SOMETHING BELOW THE DATE PRESS ENTER !" << endl << endl;

	gotoXY(75, 14); cout << "Please enter the year of the event: "; cin >> data.year;
	gotoXY(75, 15); cout << "Please enter the month of the event: "; cin >> data.month;
	gotoXY(75, 16); cout << "Please enter the day of the event: "; cin >> data.day; cin.ignore();
	gotoXY(75, 17); cout << "Please enter the name of the event: "; cin.getline(data.subject, sizeof(data.subject));
	gotoXY(75, 18); cout << "Please enter the leader of the event: "; cin.getline(data.leader, sizeof(data.leader));
	gotoXY(75, 19); cout << "Please enter the place where the event happened: "; cin.getline(data.place, sizeof(data.place));

	list.pushFront(data);
	system("cls");
}

void Menu::findEvents()
{
	EventsList::DATA data{ 0, 0, 0, "", "", "" }, * dp;

	gotoXY(75, 0); cout << "! (1)You can enter 0 if you want to ignore the date field !" << endl;
	gotoXY(75, 0); cout << "! (2)You can also enter an empty string if you want to ignore any of the fields below the date !" << endl << endl;

	gotoXY(75, 14); cout << "Please enter the year of the event: "; cin >> data.year;
	gotoXY(75, 15); cout << "Please enter the month of the event: "; cin >> data.month;
	gotoXY(75, 16); cout << "Please enter the day of the event: "; cin >> data.day; cin.ignore();
	gotoXY(75, 17); cout << "Please enter the name of the event: "; cin.getline(data.subject, sizeof(data.subject));
	gotoXY(75, 18); cout << "Please enter the leader of the event: "; cin.getline(data.leader, sizeof(data.leader));
	gotoXY(75, 19); cout << "Please enter the place where the event happened: "; cin.getline(data.place, sizeof(data.place));

	system("cls");
	list.moveToFirst();
	for (dp = list.find(data); dp != nullptr; dp = list.find())
	{
		cout << dp->year << "." << dp->month << '.' << dp->day << " |Subject - ";

		if (strlen(dp->subject) == 0)
			cout << "Unknown";
		else
			cout << dp->subject;

		cout << " |Leader - ";

		if (strlen(dp->leader) == 0)
			cout << "Unknown";
		else
			cout << dp->leader;

		cout << " |Place - ";

		if (strlen(dp->place) == 0)
			cout << "Unknown";
		else
			cout << dp->place;

		cout << endl;
	}
}

void Menu::changeInfo()
{
	findEvents();

	int choice = 0, y = 2, size = list.foundAdrs.size();
	system("cls");

	for (int i = 0; i < size; i++)
	{
		gotoXY(4, y + i);
		cout << list.foundAdrs[i]->data.year << "." << list.foundAdrs[i]->data.month << '.' << list.foundAdrs[i]->data.day << " |Subject - ";

		if (strlen(list.foundAdrs[i]->data.subject) == 0)
			cout << "Unknown";
		else
			cout << list.foundAdrs[i]->data.subject;

		cout << " |Leader - ";

		if (strlen(list.foundAdrs[i]->data.leader) == 0)
			cout << "Unknown";
		else
			cout << list.foundAdrs[i]->data.leader;

		cout << " |Place - ";

		if (strlen(list.foundAdrs[i]->data.place) == 0)
			cout << "Unknown";
		else
			cout << list.foundAdrs[i]->data.place;

	}

	while (true)
	{
		system("pause>nul");

		if (GetAsyncKeyState(VK_DOWN) && (choice < size - 1))
		{
			gotoXY(1, y + choice); cout << "   ";
			choice++;
			gotoXY(1, y + choice); cout << "-> ";

			continue;
		}
		else if (GetAsyncKeyState(VK_UP) && (choice > 0))
		{
			gotoXY(1, y + choice); cout << "   ";
			choice--;
			gotoXY(1, y + choice); cout << "-> ";

			continue;
		}
		else if (GetAsyncKeyState(VK_RETURN))
		{
			system("cls");
			break;
		}
	}

	EventsList::DATA d{ 0, 0, 0, "", "", "" };
	gotoXY(75, 0); cout << "! IF YOU DON'T KNOW OR DON'T WANT TO GIVE DETAILS ABOUT THE DATE -> TYPE \"0\" !" << endl;
	gotoXY(75, 0); cout << "! IF YOU DON'T KNOW SOMETHING BELOW THE DATE PRESS ENTER !" << endl << endl;

	gotoXY(75, 14); cout << "Please enter the year of the event: "; cin >> d.year;
	gotoXY(75, 15); cout << "Please enter the month of the event: "; cin >> d.month;
	gotoXY(75, 16); cout << "Please enter the day of the event: "; cin >> d.day; cin.ignore();
	gotoXY(75, 17); cout << "Please enter the name of the event: "; cin.getline(d.subject, sizeof(d.subject));
	gotoXY(75, 18); cout << "Please enter the leader of the event: "; cin.getline(d.leader, sizeof(d.leader));
	gotoXY(75, 19); cout << "Please enter the place where the event happened: "; cin.getline(d.place, sizeof(d.place));

	list.moveTo(list.foundAdrs[choice]);
	list.set(d);

	system("cls");
}

void Menu::deleteEvents()
{
	findEvents();

	int choice = 0, y = 2, size = list.foundAdrs.size();
	system("cls");

	for (int i = 0; i < size; i++)
	{
		gotoXY(4, y + i);
		cout << list.foundAdrs[i]->data.year << "." << list.foundAdrs[i]->data.month << '.' << list.foundAdrs[i]->data.day << " |Subject - ";

		if (strlen(list.foundAdrs[i]->data.subject) == 0)
			cout << "Unknown";
		else
			cout << list.foundAdrs[i]->data.subject;

		cout << " |Leader - ";

		if (strlen(list.foundAdrs[i]->data.leader) == 0)
			cout << "Unknown";
		else
			cout << list.foundAdrs[i]->data.leader;

		cout << " |Place - ";

		if (strlen(list.foundAdrs[i]->data.place) == 0)
			cout << "Unknown";
		else
			cout << list.foundAdrs[i]->data.place;

	}

	while (true)
	{
		system("pause>nul");

		if (GetAsyncKeyState(VK_DOWN) && (choice < size - 1))
		{
			gotoXY(1, y + choice); cout << "   ";
			choice++;
			gotoXY(1, y + choice); cout << "-> ";

			continue;
		}

		if (GetAsyncKeyState(VK_UP) && (choice > 0))
		{
			gotoXY(1, y + choice); cout << "   ";
			choice--;
			gotoXY(1, y + choice); cout << "-> ";

			continue;
		}

		if (GetAsyncKeyState(VK_RETURN))
		{
			system("cls");
			break;
		}
	}

	list.moveTo(list.foundAdrs[choice]);
	list.remove();

	system("cls");
}

//Account
void Menu::displaySigninOptions()
{
	system("cls");

	bool here2 = true;
	int y = 14, choice = 0;

	while (here2 == true)
	{
		gotoXY(50, 0); cout << "*--------------------------------------------------------------*" << endl;
		gotoXY(50, 1); cout << ":                                                              :" << endl;
		gotoXY(50, 2); cout << ":  _______  _______  _______  ___   _______  __    _  _______  :" << endl;
		gotoXY(50, 3); cout << ": |       ||       ||       ||   | |       ||  |  | ||       | :" << endl;
		gotoXY(50, 4); cout << ": |   _   ||    _  ||_     _||   | |   _   ||   |_| ||  _____| :" << endl;
		gotoXY(50, 5); cout << ": |  | |  ||   |_| |  |   |  |   | |  | |  ||       || |_____  :" << endl;
		gotoXY(50, 6); cout << ": |  |_|  ||    ___|  |   |  |   | |  |_|  ||  _    ||_____  | :" << endl;
		gotoXY(50, 7); cout << ": |       ||   |      |   |  |   | |       || | |   | _____| | :" << endl;
		gotoXY(50, 8); cout << ": |_______||___|      |___|  |___| |_______||_|  |__||_______| :" << endl;
		gotoXY(50, 9); cout << ":                                                              :" << endl;
		gotoXY(50, 10); cout << ":                                                              :" << endl;
		gotoXY(50, 11); cout << "*--------------------------------------------------------------*" << endl;


		gotoXY(75, 14); cout << "Login\n";
		gotoXY(75, 15); cout << "Sign in\n";
		gotoXY(75, 16); cout << "List options\n";
		gotoXY(75, 17); cout << "Quit";

		system("pause>nul");

		if (GetAsyncKeyState(VK_DOWN) && y != 17)
		{
			gotoXY(72, y); cout << "  ";
			y++;
			gotoXY(72, y); cout << "-> ";
			choice++;
			continue;
		}

		if (GetAsyncKeyState(VK_UP) && y != 14)
		{
			gotoXY(72, y); cout << "  ";
			y--;
			gotoXY(72, y); cout << "-> ";
			choice--;
			continue;
		}


		if (GetAsyncKeyState(VK_RETURN))
		{
			system("cls");

			switch (choice)
			{
			case 0:
			{
				Login();
			}break;
			case 1:
			{
				SignUp();
			}break;
			case 2:
			{
				displayOptions();
			} break;
			case 3:
			{
				system("cls");
				gotoXY(75, 0); cout << "You have successfully quited!" << endl;
				exit(0);
			}break;
			}
		}
	}
}

void Menu::SignUp()
{
	string username, pass, repeated_pass, finalPassword;
	bool flag = false;

	while (flag != true)
	{
		system("cls");

		gotoXY(75, 2); cout << "         -- SIGNIN --         " << endl;
		gotoXY(75, 3); cout << " ---------------------------- " << endl;
		gotoXY(75, 4); cout << "|          Username:         |" << endl;
		gotoXY(75, 5); cout << "|         -> "; getline(cin, username); std::cout << "\033[F";
		gotoXY(75, 6); cout << "|          Password:         |" << endl;
		gotoXY(75, 7); cout << "|         -> "; getline(cin, pass);  std::cout << "\033[F";
		gotoXY(75, 8); cout << "|       Confirm Password:    |" << endl;
		gotoXY(75, 9); cout << "|         -> "; getline(cin, repeated_pass);  std::cout << "\033[F";
		gotoXY(75, 10); cout << " ---------------------------- " << endl;

		Sleep(1000);

		ifstream temp;
		temp.open(username);

		if (temp)
		{
			system("cls");
			cout << "                         USERNAME ALREADY EXISTS" << endl;
			Sleep(1000);
		}
		else if (pass == repeated_pass && username != "" && pass != "")
			flag = true;
		else
		{
			system("cls");
			cout << "                         REPEATED PASSWORD DOESN'T MATCH THE ORIGINAL" << endl;
			Sleep(1000);
		}
	}

	ofstream fo;
	fo.open(username, ios::out);

	if (fo.fail()) {
		cout << "WRONG INFORMATION" << endl;
		Sleep(1000);
		displaySigninOptions();
	}
	else {
		fo << username << endl;

		for (size_t i = 0; i < pass.size(); i++)
		{
			string bin = decToBin(pass[i]);
			finalPassword += binaryToGray(bin);
		}

		fo << finalPassword << endl;
	}

	system("cls");
	gotoXY(25, 0); cout << "YOU ARE ALL DONE, NOW WE ARE REDIRECTING YOU TO THE LOGIN PAGE";

	Sleep(2000);
	system("cls");
	Login();
}

void Menu::Login()
{
	string password, temp, result;
	bool flag = false;
	int checks, info;

	if (c == 2)
	{
		system("cls");
		gotoXY(25, 0); cout << "!!! YOU HAVE TO EXIT THE PROGRAM AND THAN LAUNCH IT AGAIN TO BE ABLE TO LOG INTO A DIFFERENT ACCOUNT !!!" << endl << endl;
		Sleep(2000);
		system("cls");
		gotoXY(25, 0); cout << "Logging out..";
		Sleep(1000);

		system("cls");
		gotoXY(25, 0); cout << "You have successfully quited!" << endl;
		exit(0);
	}

	while (flag != true)
	{
		system("cls");
		gotoXY(25, 0); cout << "!!! YOU HAVE TO EXIT THE PROGRAM AND THAN LAUNCH IT AGAIN TO BE ABLE TO LOG INTO A DIFFERENT ACCOUNT !!!" << endl << endl;

		checks = 0;
		info = 1;

		gotoXY(75, 2); cout << "      -- LOGIN --       " << endl;
		gotoXY(75, 3); cout << " ---------------------- " << endl;
		gotoXY(75, 4); cout << "|       Username:      |" << endl;
		gotoXY(75, 5); cout << "|     -> "; getline(cin, name); std::cout << "\033[F";
		gotoXY(75, 6); cout << "|       Password:      |" << endl;
		gotoXY(75, 7); cout << "|     -> "; getline(cin, password);  std::cout << "\033[F";
		gotoXY(75, 8); cout << " ---------------------- " << endl;

		Sleep(1000);

		ifstream fi;
		fi.open(name, ios::in);

		if (fi.fail()) {
			system("cls");
			gotoXY(75, 0); cout << "Username doesn't match!" << endl;
			Sleep(1500);
		}
		else {
			do {
				getline(fi, temp);

				if (info == 1)
				{
					if (name == temp)
					{
						checks++;
						info++;
					}
				}
				else if (info == 2)
				{
					for (size_t i = 0; i < password.size(); i++)
					{
						string bin = decToBin(password[i]);
						result += binaryToGray(bin);
					}

					if (result == temp)
						checks++;
				}


			} while (!fi.eof());
		}
		if (checks == 2 && password != "")
		{
			c++;
			flag = true;
		}
		else {
			system("cls");
			gotoXY(75, 0); cout << "Password doesn't match" << endl;
			Sleep(1000);
			displaySigninOptions();
		}
	}

	displayOptions();
}

//Gray's algorithm
string Menu::decToBin(int n)
{
	string bin;

	while (n != 0)
	{
		bin += to_string(n % 2);
		n /= 2;
	}

	reverse(bin.begin(), bin.end());

	return bin;
}

string Menu::binaryToGray(string bin)
{
	string gray = "";

	gray += bin[0];

	for (int i = 1; i < bin.length(); i++)
		gray += xor_func(bin[i - 1], bin[i]);

	return gray;
}