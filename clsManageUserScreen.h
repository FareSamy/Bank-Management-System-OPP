#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include <iomanip>
#include "clsListUsersScreen.h"
#include "clsAddNewUserScreen.h"
#include "clsDeleteUserScreen.h"
#include"clsUpdateUserScreen.h"
#include "clsFindUserScreen.h"

class clsManageUserScreen : protected clsScreen
{
private:

    enum enMangeUsersOption
    {
        eListUsers = 1, eAddNewUser = 2, eDeleteUser = 3,
        eUpdateUser = 4, eFindUser = 5, eMainMenue = 6
    };

    static short ReadMangeUserMenueOption()
    {
        cout << setw(37) << left << "" << "choose what do you want [1-6]?";
        short choice;
        choice = clsInputValidate::ReadIntNumberBetween(1, 6);
        return choice;

    }

    static void _GoBackToManageUsersMenue()
    {
        cout << setw(37) << left << "" << "Press any key to go back to Manage Users Menue...";
        system("pause>0");
        ShowMangeUserMenueScreen();
    }

    static void _ShowListUsersScreen()
    {
        //cout << "\nList Users Screen Will Be Here.\n";
        clsListUsersScreen::ShowUsersList();
    }

    static void _ShowAddNewUserScreen()
    {
        //cout << "\nAdd New User Screen Will Be Here.\n";
        clsAddNewUserScreen::ShowAddNewUserScreen();

    }

    static void _ShowDeleteUserScreen()
    {
        //cout << "\nDelete User Screen Will Be Here.\n";
        clsDeleteUserScreen::ShowDeletUserScreen();
    }

    static void _ShowUpdateUserScreen()
    {
        //cout << "\nUpdate User Screen Will Be Here.\n";
        clsUpdateUserScreen::ShowUpdateUserScreen();
    }

    static void _ShowFindUserScreen()
    {
        //cout << "\nFind User Screen Will Be Here.\n";
        clsFindUserScreen::ShowFindUserScreen();
    }

    static void _PerformManageUsersMenueOption(enMangeUsersOption ManageUsersMenueOption)
    {
        switch (ManageUsersMenueOption)
        {
        case clsManageUserScreen::eListUsers:

            system("cls");
            _ShowListUsersScreen();
            _GoBackToManageUsersMenue();
            break;

        case clsManageUserScreen::eAddNewUser:

            system("cls");
            _ShowAddNewUserScreen();
            _GoBackToManageUsersMenue();
            break;

        case clsManageUserScreen::eDeleteUser:

            system("cls");
            _ShowDeleteUserScreen();
            _GoBackToManageUsersMenue();
            break;

        case clsManageUserScreen::eUpdateUser:

            system("cls");
            _ShowUpdateUserScreen();
            _GoBackToManageUsersMenue();
            break;

        case clsManageUserScreen::eFindUser:

            system("cls");
            _ShowFindUserScreen();
            _GoBackToManageUsersMenue();
            break;

        case clsManageUserScreen::eMainMenue:

            break;

        default:
            break;
        }


    };

public:

	static void ShowMangeUserMenueScreen()
	{
        if (!CheckAccessRights(clsUser::enPermission::PMangeUser))
        {
            return;
        }
        system("cls");
        _DrawScreenHeader("\t Manage Users Screen");

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t  Manage Users Menue\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] List Users.\n";
        cout << setw(37) << left << "" << "\t[2] Add New User.\n";
        cout << setw(37) << left << "" << "\t[3] Delete User.\n";
        cout << setw(37) << left << "" << "\t[4] Update User.\n";
        cout << setw(37) << left << "" << "\t[5] Find User.\n";
        cout << setw(37) << left << "" << "\t[6] Main Menue.\n";
        cout << setw(37) << left << "" << "===========================================\n";

        _PerformManageUsersMenueOption((enMangeUsersOption)ReadMangeUserMenueOption());
    }
};

