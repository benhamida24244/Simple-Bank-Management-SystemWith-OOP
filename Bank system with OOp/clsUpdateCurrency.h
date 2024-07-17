#pragma once
#include <iostream>
#include"clsCurrency.h"
#include "clsInputValidate.h"
#include "clsScreen.h"
using namespace std;
class clsUpdateCurrency :protected clsScreen
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

    static void ReadCurrencytInfo(clsCurrency& Client)
    {
        cout << "\nEnter New Rate : ";
        Client.Rate = clsInputValidate::ReadFloatNumber();
    }


public:
    static void UpdateCurrency() {
        _DrawScreenHeader("\tUpdate Currency Screen");

        string CurrencyCode = "";

        cout << "\nPlease Enter Currency Code: ";
        CurrencyCode = clsInputValidate::ReadString();
        while (!clsCurrency::IsCurrencyExist(CurrencyCode))
        {
            cout << "\nCurrency Code is not found, choose another one: ";
            CurrencyCode = clsInputValidate::ReadString();
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
        cout << "\nAre you sure you want to update this Currency/n? ";

        char Answer = 'n';
        cin >> Answer;

        if (Answer == 'y' || Answer == 'Y') {
            cout << "\n\nUpdate Currency Info:";
            cout << "\n____________________\n";
            ReadCurrencytInfo(Currency);
            clsCurrency::enSaveResults SaveResult;

            SaveResult = Currency.Save();

            switch (SaveResult)
            {
            case  clsCurrency::enSaveResults::svSucceeded:
            {
                cout << "\nCurrency Updated Successfully :-)\n";

                _PrintCurrency(Currency);
                break;
            }
            case clsCurrency::enSaveResults::svFaildEmptyObject:
            {
                cout << "\nError Currency was not saved because it's Empty";
                break;

            }
            }
        }
    }
};