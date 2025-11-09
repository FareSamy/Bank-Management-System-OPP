#pragma once
#include <iostream>
#include "clsScreen.h"
#include"clsInputValidate.h"

class clsTransferScreen : protected clsScreen
{
private:

	static void _PrintClientCard(clsBankClient Client)
	{
		cout << endl;
		cout << "Client Card:" << endl;;
		cout << "___________________" << endl;

		cout << "Full Name :" << Client.FullName() << endl;
		cout << "Acc Number:" << Client.AccountNumber() << endl;
		cout << "Balance     :" << Client.AccountBalance << endl;

		cout << "___________________" << endl;

	}

	static string _ReadAccountNumber()
	{
		string AccountNumber;
		float Amount = 0;

		cout << endl;
		cout << "Please Enter Account Number to Transfer From:";

		AccountNumber = clsInputValidate::ReadString();
		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "Invalid Account Number Please Try Onther one!:";
			AccountNumber = clsInputValidate::ReadString();
		}
		return AccountNumber;
		
	}

	static float ReadAmount(clsBankClient SourceClient)
	{
		float Amount;
		cout << "\nEnter Transfer Amount?";
		Amount = clsInputValidate::ReadFloatNumber();
		while (Amount > SourceClient.AccountBalance)
		{
			cout << "\nAmount Exceeds the available Balance, Enter another Amount ? ";
			Amount = clsInputValidate::ReadDblNumber();
		}
		return Amount;
	}

public:

	static void ShowTransferScreen()
	{
		
		_DrawScreenHeader("\tTransfer Screen");

		clsBankClient SourceClient = clsBankClient::Find(_ReadAccountNumber());

		_PrintClientCard (SourceClient);

		clsBankClient DestinationClient = clsBankClient::Find(_ReadAccountNumber());

		_PrintClientCard(DestinationClient);

		float Amount = ReadAmount(SourceClient);


		cout << "\nAre you sure you want to perform this operation? y/n? ";
		char Answer = 'n';
		cin >> Answer;
		if (Answer == 'Y' || Answer == 'y')
		{
			if (SourceClient.Transfer(Amount, DestinationClient,CurrentUser.UserName))
			{
				cout << "\nTransfer done successfully\n";
				
			}
			else
			{
				cout << "\nTransfer Faild \n";
			}
		}

		_PrintClientCard(SourceClient);
		_PrintClientCard(DestinationClient);
		
	
	}
};

