#pragma once
#include <iostream>
#include "clsScreen.h"
#include <iomanip>
#include "clsCurrency.h"
#include "clsInputValidate.h"
using namespace std;
class clsFindCurrency :protected clsScreen
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

static void ShowFindCurrencyScreen() {
    _DrawScreenHeader("\tCurrency Screen");
    string CurrencyCode;
    cout << "Please Entre Currency Code : ";
    CurrencyCode = clsInputValidate::ReadString();
    while (!clsCurrency::IsCurrencyExist(CurrencyCode))
    {
        cout << "\nCurrency is not found, choose another one: ";
        CurrencyCode  = clsInputValidate::ReadString();
    }
    clsCurrency Currency = clsCurrency::Find(CurrencyCode);
    if (!Currency.IsEmpty())
    {
        cout << "\nCurrency Found :-)\n";
    }
    else
    {
        cout << "\nCurrency Was not Found :-(\n";
    }
    _PrintCurrency(Currency);
}

};

