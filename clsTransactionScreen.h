#pragma once
#include <iostream>
#include"clsScreen.h"
#include "clsInputValidate.h"
#include<iomanip>
#include"clsDepositScreen.h"
#include "clsWithdrawScreen.h"
#include"clsTotalBalanceSceen.h"
#include "clsTransferScreen.h"
#include "clsTransferLogScreen.h"

class clsTransactionScreen :protected clsScreen
{
private:
    enum enTransactionMenue
    {
        eDeposit = 1, eWithdraw = 2, eTotalBalance = 3, eTransfer = 4, eTransferLog =5,eMainMenue = 6
    };

    static short _ReadTransactionMenueOption()
    {
        cout << setw(37) << left << "" << "Choose What Do you Want [1-5]?";
        short Choice = clsInputValidate::ReadIntNumberBetween(1, 5);
        return Choice;
    }

    static void _ShowDepositScreen()
    {
        //cout << "Deposit Screen will be here ";
        clsDepositScreen::ShowDepositScreen();
    }

    static void _ShowWithdrawtScreen()
    {
        //cout << "Withdraw Screen will be here";
        clsWithdrawScreen::ShowDepositScreen();
    }

    static void _ShowTotoalBalancesScreen()
    {
        //cout << "Total Balances Screen will be here";
        clsTotalBalanceSceen::ShowTotalBalances();
    }

    static void _ShowTransferScreen()
    {
        //cout << "transfer screen will be here ";
        clsTransferScreen::ShowTransferScreen();
    }

    static void _ShowTransferLogScreen()
    {
        //cout << "Transfer log will be here :)";
        clsTransferLogScreen::ShowTranferLogScreen();
    }

    static void _BackToTransactionMenue()
    {
        cout << "\n\nPress any key to go back to Transactions Menue...";
        system("pause>0");
        ShowTransactionMenue();
    }

    static void _PerformTransactionMenue(enTransactionMenue TransactionsMenueOption)
    {
        switch (TransactionsMenueOption)
        {
        case clsTransactionScreen::eDeposit:
            system("cls");
            _ShowDepositScreen();
            _BackToTransactionMenue();
            break;

        case clsTransactionScreen::eWithdraw:
            system("cls");
            _ShowWithdrawtScreen();
            _BackToTransactionMenue();
            break;

        case clsTransactionScreen::eTotalBalance:
            system("cls");
            _ShowTotoalBalancesScreen();
            _BackToTransactionMenue();
            break;

        case clsTransactionScreen :: eTransfer:
            system("cls");
            _ShowTransferScreen();
            _BackToTransactionMenue();
            break;
        case clsTransactionScreen::eTransferLog :
            system("cls");
            _ShowTransferLogScreen();
            _BackToTransactionMenue();
            break;
        case clsTransactionScreen::eMainMenue:
            //system("cls");
            //do nothing here the main screen will handle it :-) ;
            break;

        default:
            break;
        }
    
    }
public:
	static void ShowTransactionMenue()
	{
        if (!CheckAccessRights(clsUser::enPermission::pTransaction))
        {
            return;
        }
        system("cls");
		_DrawScreenHeader("\tTransactions Menue Screen");

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t\Transaction Menue\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] Deposit.\n";
        cout << setw(37) << left << "" << "\t[2] Withdraw.\n";
        cout << setw(37) << left << "" << "\t[3] Total Balance.\n";
        cout << setw(37) << left << "" << "\t[4] Transfers.\n";
        cout << setw(37) << left << "" << "\t[5] Transfers Log.\n";
        cout << setw(37) << left << "" << "\t[6] Main Menue.\n";
        cout << setw(37) << left << "" << "===========================================\n";
        _PerformTransactionMenue((enTransactionMenue)_ReadTransactionMenueOption());
    
    }

};

