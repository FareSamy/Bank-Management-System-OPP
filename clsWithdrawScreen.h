#pragma once
#include<iostream>
#include"clsScreen.h"
#include "clsBankClient.h"
#include"clsInputValidate.h"

class clsWithdrawScreen : protected clsScreen
{

    static void _PrintClient(clsBankClient Client)
    {
        cout << "\nClient Card:";
        cout << "\n___________________";
        cout << "\nFirstName   : " << Client.FirstName;
        cout << "\nLastName    : " << Client.LastName;
        cout << "\nFull Name   : " << Client.FullName();
        cout << "\nEmail       : " << Client.Email;
        cout << "\nPhone       : " << Client.Phone;
        cout << "\nAcc. Number : " << Client.AccountNumber();
        cout << "\nPassword    : " << Client.PinCode;
        cout << "\nBalance     : " << Client.AccountBalance;
        cout << "\n___________________\n";
    }
    static string _ReadAccountNumber()
    {
        string AccountNumber = "";
        cout << "\nPlease enter AccountNumber? ";
        cin >> AccountNumber;
        return AccountNumber;

    }

public:

    static void ShowDepositScreen()
    {
        _DrawScreenHeader("\t WithDraw Screen");
        string AccountNumber = _ReadAccountNumber();
        while (!clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "\nClient with [" << AccountNumber << "] does not exist.\n";
            AccountNumber = _ReadAccountNumber();
        }
        clsBankClient Client1 = clsBankClient::Find(AccountNumber);
        _PrintClient(Client1);

        double Amount = 0;
        cout << "Please Enter Withdraw Amount?";
        Amount = clsInputValidate::ReadDblNumber();
        while (Amount > Client1.AccountBalance)
        {
            cout << "Invalid Balance - Please Inter Valid Balance!!";
            Amount = clsInputValidate::ReadDblNumber();
        }

        cout << "Are You Sure you want performe this transaction ? Y/N?";
        char Answer = 'n';
        cin >> Answer;
        if (Answer == 'y' or Answer == 'Y')
        {
            if (Client1.Withdraw(Amount))
            {
                cout << "\nAmount Withdrawed Successfully.\n";
                cout << "\nNew Balance Is" << Client1.AccountBalance;
            }
            else
            {
                cout << "\Cannot Withdrawed ,Insffecient Balance.\n";
                cout << "\Amount to Withdrawed is .\n"<< Amount ;
                cout << "\Your Balance Is" << Client1.AccountBalance;

            }
        }
        else
        {
            cout << " Opreation was Cancled .\n";
        }

    }

};

