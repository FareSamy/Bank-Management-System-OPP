#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsPerson.h"
#include "clsUsers.h"
#include "clsInputValidate.h"

class clsDeleteUserScreen : protected clsScreen

{
private:

    static void _PrintUser(clsUser User)
    {
        cout << "\nUser Card:";
        cout << "\n___________________";
        cout << "\nFirstName   : " << User.FirstName;
        cout << "\nLastName    : " << User.LastName;
        cout << "\nFull Name   : " << User.FullName();
        cout << "\nEmail       : " << User.Email;
        cout << "\nPhone       : " << User.Phone;
        cout << "\nUser Name   : " << User.UserName;
        cout << "\nPassword    : " << User.Password;
        cout << "\nPermissions : " << User.Permissions;
        cout << "\n___________________\n";

    }

public:

    static void ShowDeletUserScreen()
    {
        _DrawScreenHeader("\tDelete User Screen");
        string UserName;
        cout << "Please Enter Users Name?:";
        UserName = clsInputValidate::ReadString();
        while (!clsUser::IsUserExist(UserName))
        {
            cout << "Invalid User Please try Onther one!";
            UserName = clsInputValidate::ReadString();
        }
        clsUser User1 = clsUser::Find(UserName);
        _PrintUser(User1);

        cout << "Are you Sure you want to delete this user Y/N ?!";
        char Answer = 'n';
        cin >> Answer;
        
        if (Answer == 'y' or Answer == 'Y')
        {

                if (User1.Delete())
                {
                    cout << "\nUser Deleted Successfully :-)\n";
                    _PrintUser(User1);
                }
                else
                {
                    cout << "\nError User Was not Deleted\n";
                }

        }
        else
        {
            cout << "\nError User Was not Deleted\n";
        }
    }
};

