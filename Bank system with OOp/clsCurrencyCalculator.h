#pragma once
#include <iostream>
#include "clsScreen.h"
#include <iomanip>
#include "clsCurrency.h"
#include "clsInputValidate.h"
using namespace std;
class clsCurrencyCalculator :protected clsScreen
{
private:

    static void _PrintCurrency(clsCurrency Client)
    {
        cout << "\nClient Card:";
        cout << "\n___________________";
        cout << "\nCountry : " << Client.Country();
        cout << "\nCode : " << Client.Code();
        cout << "\nName : " << Client.Name();
        cout << "\nRate : " << Client.Rate;
        cout << "\n___________________\n";
    }


public:
    static void ShowCurrencyClaculatorScreen() {
        system("cls");
        _DrawScreenHeader("\tCurrency Calculator Screen");
        string CurrencyCode1;
        cout << "Please Entre Currency Code you want conver from : ";
        CurrencyCode1 = clsInputValidate::ReadString();
        while (!clsCurrency::IsCurrencyExist(CurrencyCode1))
        {
            cout << "\nCurrency is not found, choose another one: ";
            CurrencyCode1 = clsInputValidate::ReadString();
        }
        clsCurrency Currency1 = clsCurrency::Find(CurrencyCode1);
        _PrintCurrency(Currency1);
        string CurrencyCode2;
        cout << "Please Entre Currency Code you want conver to : ";
        CurrencyCode2 = clsInputValidate::ReadString();
        while (!clsCurrency::IsCurrencyExist(CurrencyCode2))
        {
            cout << "\nCurrency is not found, choose another one: ";
            CurrencyCode2 = clsInputValidate::ReadString();
        }
        clsCurrency Currency2 = clsCurrency::Find(CurrencyCode2);
        _PrintCurrency(Currency2);
        float amount;
        cout << "\n\nPlease Entre the amount do you want to Transfer  : ";
        amount = clsInputValidate::ReadFloatNumber();
        Currency1.CalculatorCurrency(Currency2, amount);
        string choose;
        cout << "Do you want perform a more Calculation [Y/N] ?";
        choose = clsInputValidate::ReadString();
        if (choose == "y" || choose == "Y")
        {
            ShowCurrencyClaculatorScreen();
        }
        else {
            return;
        }
    }

};

