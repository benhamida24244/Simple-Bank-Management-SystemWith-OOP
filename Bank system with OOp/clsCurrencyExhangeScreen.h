#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsUser.h"
#include <iomanip>
#include "clsInputValidate.h"
#include "clsListCurrencyScreen.h"
#include "clsFindCurrency.h"
#include "clsUpdateCurrency.h"
#include "clsCurrencyCalculator.h"
using namespace std;

class clsCurrencyExhangeScreen:protected  clsScreen
{
private:
	enum CurrencyMenueOptions {
		eListCurrency = 1, eFindCurrency = 2,
		eUpdateCurrency = 3, eCurrencyCalculator = 4, eShowMainMenue = 5
	};
	static short ReadCurrencyMenueOption()
	{
		cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 5]? ";
		short Choice = clsInputValidate::ReadShortNumberBetween(1, 5, "Enter Number between 1 to 5? ");
		return Choice;
	}
	static void _ShowListCurrencyScreen() {
		clsListCurrencyScreen::ShowCurrencyList();
		//cout << "\n List Currency Screen will be here.\n";
	}
		static void _ShowFindCurrencyScreen() {
			clsFindCurrency::ShowFindCurrencyScreen();
		//cout << "\n Find Currency Screen will be here.\n";
	}
	static void _ShowUpdateCurrencyScreen() {
		clsUpdateCurrency::UpdateCurrency();
		//cout << "\n Update Currency Screen will be here.\n";
	}
	static void _ShowCurrencyCalculatorScreen() {
		clsCurrencyCalculator::ShowCurrencyClaculatorScreen();
		//cout << "\n  Currency Calculator Screen will be here.\n";
	}
	static void _GoBackToCurrencyMenue() {
		cout << "\n\nPress any key to go back to Currency Menue...";
		system("pause>0");
		CurrencyMenue();
	}





	static void _PerformCurrencyMenueOption(CurrencyMenueOptions CurrencyMainOption) {
		switch (CurrencyMainOption)
		{
		case clsCurrencyExhangeScreen::eListCurrency:
			system("cls");
			_ShowListCurrencyScreen();
			_GoBackToCurrencyMenue();
			break;
		case clsCurrencyExhangeScreen::eFindCurrency:
			system("cls");
			_ShowFindCurrencyScreen();
			_GoBackToCurrencyMenue();
			break;
		case clsCurrencyExhangeScreen::eUpdateCurrency:
			system("cls");
			_ShowUpdateCurrencyScreen();
			_GoBackToCurrencyMenue();
			break;
		case clsCurrencyExhangeScreen::eCurrencyCalculator:
			system("cls");
			_ShowCurrencyCalculatorScreen();
			_GoBackToCurrencyMenue();
			break;
		case clsCurrencyExhangeScreen::eShowMainMenue:

			break;
		}
	}
public:
	static void CurrencyMenue() {
		if (!CheckAccessRights(clsUser::enPermissions::pCurrencyExhange))
		{
			return;
		}
		system("cls");
		_DrawScreenHeader("\tCurrency Exhange Main Screen");
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t\t  Currency Exhange Menue\n";
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t[1] List Currencies.\n";
		cout << setw(37) << left << "" << "\t[2] Find Currency.\n";
		cout << setw(37) << left << "" << "\t[3] Update Rate.\n";
		cout << setw(37) << left << "" << "\t[4] Currency Calculator.\n";
		cout << setw(37) << left << "" << "\t[5] Main Menue.\n";
		cout << setw(37) << left << "" << "===========================================\n";
		_PerformCurrencyMenueOption((CurrencyMenueOptions)ReadCurrencyMenueOption());
	}


};

