#pragma once
#include "clsMainScreen.h"
#include"clsUsers.h"
#include <iostream>
#include"Global.h"


class clsLoginScreen : protected clsScreen

{
private:

	static bool Login()
	{

		bool LoginFaild = false;
		short LoginFaildCount = 0;
		string UserName, Password;
		do
		{


			if (LoginFaild)
			{
				LoginFaildCount++;
				system("cls");
				_DrawScreenHeader("\tLogin Screen");
				cout << "Invalid UserName/Passaword !" << endl;;
				cout << "You Have" <<" " << (3 - LoginFaildCount) <<
					" Trial(s) To login.\n\n";
			}
			if (LoginFaildCount == 3)
			{
				cout << "\You Are Locked After 3 Faild trials\n\n";
				return false;
			}
			
			cout << "Please Enter User Name?";
			cin >> UserName;

			cout << "Please Enter Password?";
			cin >> Password;

			CurrentUser = clsUser::Find(UserName, Password);
			LoginFaild = CurrentUser.IsEmpty();

		} while (LoginFaild);

		CurrentUser.RegisterLogin();
		clsMainScreen::ShowMainMenue();
		return true;
	}

public:
	static bool ShowLoginScreen()
	{

		system("cls");
		_DrawScreenHeader("\tLogin Screen");
		 return Login();

	}


};

