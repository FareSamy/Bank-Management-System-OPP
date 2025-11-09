#pragma once
#include<iostream>
#include "clsInputValidate.h"
#include<iomanip>
#include"clsScreen.h"
#include"clsClientListScreen.h"
#include"clsShowAddNewClientScreen.h"
#include"clsDeleteClientScreen.h"
#include"clsupdateClientScreen.h"
#include"clsFindClientScreen.h"
#include"clsTransactionScreen.h"
#include "clsManageUserScreen.h"
#include"Global.h"
#include "clsShowLoginRegisterScreen.h"
#include"clsCurrenyScreen.h"

using namespace std;


class clsMainScreen :protected clsScreen
{
private:

    enum enMainMenueOptions
    {
        eListClients = 1, eAddNewClient = 2, eDeleteClient = 3,
        eUpdateClient = 4, eFindClient = 5, eShowTransactionsMenue = 6,
        eManageUsers = 7, eLoginRegister =8 , eCurrency = 9,eExit = 10
    };

    static short _ReadMainMenueOption()
    {
        cout << setw(37) << left << "" << "Choose what do you want [1 to 10]?";
        short Choice = clsInputValidate::ReadDblNumberBetween(1, 10, "Enter Number between 1 to 10? ");
        return Choice;
    }

    static  void _GoBackToMainMenue()
    {
        cout << setw(37) << left << "" << "\n\tPress any key to go back to Main Menue...\n";

        system("pause>0");
        ShowMainMenue();
    }

    static void _ShowAllClientsScreen()
    {
       //cout << "\nClient List Screen \n";
        clsClientListScreen::ShowClientList();
       
    }

    static void _ShowAddNewClientsScreen()
    {
       // cout << "\nAdd New Client Screen Will be here...\n";
        clsShowAddNewClientScreen::ShowAddNewAddScreen();
    }

    static void _ShowDeleteClientScreen()
    {
        //cout << "\nDelete Client Screen Will be here...\n";
        clsDeleteClientScreen::ShowDeleteClientScreen();
    }

    static void _ShowUpdateClientScreen()
    {
        // cout << "\nUpdate Client Screen Will be here...\n";

        clsupdateClientScreen::ShowUpdateClientScreen();
    }

    static void _ShowFindClientScreen()
    {
        //cout << "\nFind Client Screen Will be here...\n";
        clsFindClientScreen::ShowFindClientScreen();

    }

    static void _ShowTransactionsMenue()
    {
       // cout << "\nTransactions Menue Will be here...\n";
        clsTransactionScreen::ShowTransactionMenue();
    }

    static void _ShowManageUsersMenue()
    {
       // cout << "\nUsers Menue Will be here...\n";
        clsManageUserScreen::ShowMangeUserMenueScreen();
    }

    static void _ShowLoginRegister()
    {
        //cout << "\Login Register Screen Will be here...\n";
        clsShowLoginRegisterScreen::ShowLoginRegister();
    }

    static void _ShowCurrencyMenue()
    {
       // cout << "Currency menue will be here ";
        clsCurrenyScreen::ShowCurrencyMenue();
         
    }

    static void _Logout()
    {
        CurrentUser = clsUser::Find("", "");
    

    }

    static void _PerformMainMenueOptios(enMainMenueOptions MainMenueOption)
    {
        switch (MainMenueOption)
        {
        case clsMainScreen::eListClients:
            system("cls");
            _ShowAllClientsScreen();
            clsBankClient::GetClientList();
            _GoBackToMainMenue();
            break;

        case clsMainScreen::eAddNewClient:
            system("cls");
            _ShowAddNewClientsScreen();
            _GoBackToMainMenue();
            break;

        case clsMainScreen::eDeleteClient:
            system("cls");
            _ShowDeleteClientScreen();
            _GoBackToMainMenue();
            break;

        case clsMainScreen::eUpdateClient:
            system("cls");
            _ShowUpdateClientScreen();
            _GoBackToMainMenue();
            break;

        case clsMainScreen::eFindClient:
            system("cls");
            _ShowFindClientScreen();
            _GoBackToMainMenue();
            break;

        case clsMainScreen::eShowTransactionsMenue:
            system("cls");
            _ShowTransactionsMenue();
            _GoBackToMainMenue();
            break;

        case clsMainScreen::eManageUsers:
            system("cls");
            _ShowManageUsersMenue();
            _GoBackToMainMenue();
            break;

        case clsMainScreen::eLoginRegister:
            system("cls");
            _ShowLoginRegister();
            _GoBackToMainMenue();

        case clsMainScreen ::eCurrency:
            system("cls");
            _ShowCurrencyMenue();
            _GoBackToMainMenue();

        case clsMainScreen::eExit:
            system("cls");
            _Logout();
            //_GoBackToMainMenue();
            break;
        default:
            break;
        }
    }

public:

	static void ShowMainMenue()
	{
		system("cls");
		_DrawScreenHeader("\t\tMain Screen");

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t\tMain Menue\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] Show Client List.\n";
        cout << setw(37) << left << "" << "\t[2] Add New Client.\n";
        cout << setw(37) << left << "" << "\t[3] Delete Client.\n";
        cout << setw(37) << left << "" << "\t[4] Update Client Info.\n";
        cout << setw(37) << left << "" << "\t[5] Find Client.\n";
        cout << setw(37) << left << "" << "\t[6] Transactions.\n";
        cout << setw(37) << left << "" << "\t[7] Manage Users.\n";
        cout << setw(37) << left << "" << "\t[8] Login Register.\n";
        cout << setw(37) << left << "" << "\t[9] Currency Exchange.\n";
        cout << setw(37) << left << "" << "\t[10] Logout.\n";
        cout << setw(37) << left << "" << "===========================================\n";
        
        _PerformMainMenueOptios((enMainMenueOptions)_ReadMainMenueOption());
	}

};

