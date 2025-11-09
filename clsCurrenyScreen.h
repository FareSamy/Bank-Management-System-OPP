#pragma once
#include "clsScreen.h"
#include "clsInputValidate.h"
#include"clsListCurrencyScreen.h"
#include"clsFindCurrencyScreen.h"
#include"clsUpdateCurrencyScreen.h"
#include "clsCurrencyCalculatorScreen.h"

class clsCurrenyScreen : protected clsScreen
{
private:

	enum eCurrencyMenueOption
	{
		eListCurrency = 1, eFindCurrency = 2, eUpdataCurrency = 3 ,eCurrencyCalculator =4 , eMainMeune = 5
	};

	static  void _GoBackToCurrencyMenue()
	{
		cout << setw(37) << left << "" << "\n\tPress any key to go back to Main Menue...\n";

		system("pause>0");
		ShowCurrencyMenue();
	}

	static short _ReadCurrencyMenueOption()
	{
		cout << setw(37) << left << "" << "Choose what do you want [1 to 5]?";
		short Choice = clsInputValidate::ReadDblNumberBetween(1, 5, "Enter Number between 1 to 5? ");
		return Choice;
	}

	static void _ListCurrencyScreen()
	{
		//cout << "List Currency will be here :)";
		clsListCurrencyScreen::ShowListCurrencyScreen();
	}
	
	static void _FindCurrencyScreen()
	{
		//cout << "Find Currency will be here :)";

		clsFindCurrencyScreen::ShowFindCurrencyScreen();
	}

	static void _UpdateCurrencyScreen()
	{
		//cout << "Update Currency will be here :)";
		clsUpdateCurrencyRateScreen::ShowUpdateCurrencyRateScreen();
	}
	
	static void _CurrencyCalculatorScreen()
	{
		//cout << "Currenc yCalculator Currency will be here :)";
		clsCurrencyCalculatorScreen::ShowCurrencyCalculatorScreen();
		
	}

	static void _PerformCurrencyMenueOption(eCurrencyMenueOption CurrencyMenueOption)
	{
		switch (CurrencyMenueOption)
		{
		case clsCurrenyScreen::eListCurrency:
			system("cls");
			_ListCurrencyScreen();
			_GoBackToCurrencyMenue();
			break;

		case clsCurrenyScreen::eFindCurrency:
			system("cls");
			_FindCurrencyScreen();
			_GoBackToCurrencyMenue();
			break;

		case clsCurrenyScreen::eUpdataCurrency:
			system("cls");
			_UpdateCurrencyScreen();
			_GoBackToCurrencyMenue();
			break;
		case clsCurrenyScreen::eCurrencyCalculator:
			system("cls");
			_CurrencyCalculatorScreen();
			_GoBackToCurrencyMenue();
			break;
		case clsCurrenyScreen::eMainMeune:

			break;
		default:
			break;
		}
	}

public:

	static void ShowCurrencyMenue()
	{

		system("cls");
		_DrawScreenHeader("   Currency Exchange Main Screen");

		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t\tCurrency Exchange Menue\n";
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t[1] List Currencies.\n";
		cout << setw(37) << left << "" << "\t[2] Find Currency.\n";
		cout << setw(37) << left << "" << "\t[3] Update Currency.\n";
		cout << setw(37) << left << "" << "\t[4] Currency Calculator.\n";
		cout << setw(37) << left << "" << "\t[5] Main Menue.\n";
		cout << setw(37) << left << "" << "===========================================\n";

		_PerformCurrencyMenueOption((eCurrencyMenueOption )_ReadCurrencyMenueOption());
	}

};

