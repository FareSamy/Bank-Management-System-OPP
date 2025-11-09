#pragma once
#include<iostream>
#include"clsScreen.h"
#include "clsBankClient.h"
#include"clsInputValidate.h"

class clsDepositScreen : protected clsScreen
{
private:

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
        _DrawScreenHeader("\t Deposit Screen");
        string AccountNumber = _ReadAccountNumber  ();
        while (!clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "\nClient with [" << AccountNumber << "] does not exist.\n";
            AccountNumber = _ReadAccountNumber();
        }
        clsBankClient Client1 = clsBankClient::Find(AccountNumber);
        _PrintClient(Client1);

        double Amount = 0;
        cout << "Please Enter Deposit Amount?";
        Amount = clsInputValidate::ReadDblNumber();

        cout << "Are You Sure you want performe this transaction ? Y/N?";
        char Answer = 'n';
        cin >> Answer;
        if (Answer == 'y' or Answer == 'Y')
        {
            Client1.Deposit(Amount);
            cout << "\nAmount Deposited Successfully.\n";
            cout << "\nNew Balance Is" << Client1.AccountBalance;
        }
        else
        {
            cout << " Opreation was Cancled .\n";
        }

    }

};

