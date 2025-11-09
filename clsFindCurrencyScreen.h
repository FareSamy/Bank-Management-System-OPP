#pragma once

#include "clsScreen.h"
#include "clsCurrency.h"
#include"string.h"

class clsFindCurrencyScreen : protected clsScreen
{
private:

	static void _PrintCurrency(clsCurrency Currency)
	{
		cout << "\nCurrency Card:\n";
		cout << "_____________________________\n";
		cout << "\nCountry    : " << Currency.Country();
		cout << "\nCode       : " << Currency.CurrencyCode();
		cout << "\nName       : " << Currency.CurrencyName();
		cout << "\nRate(1$) = : " << Currency.Rate();

		cout << "\n_____________________________\n";

	}

	static void _ShowResults(clsCurrency Currency)
	{
		if (!Currency.IsEmpty())
		{
			cout << "\nCurrency Found :-)\n";
			_PrintCurrency(Currency);
		}
		else
		{
			cout << "\nCurrency Was not Found :-(\n";
		}
	}
public:

	static void ShowFindCurrencyScreen()
	{

		_DrawScreenHeader("\t  Find Currency Screen");


		short Answer;
		cout << "Find By : [1] Code or [2] Country ? ";
		cin >> Answer;
		if (Answer == 1)
		{
			cout << "Please enter Currency Code?";
			string Code;
			cin >> Code;
			clsCurrency Currency = clsCurrency::FindByCode(Code);
			_ShowResults(Currency);
		}
		else
		{
			string Country;
			cout << "Please enter Country Name?";
			cin >> Country;
			clsCurrency Currency = clsCurrency::FindByCountry(Country);
			_ShowResults(Currency);

		}
	}

};

