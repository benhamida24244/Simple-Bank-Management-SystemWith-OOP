#pragma once
#include <iostream>
#include "clsScreen.h"
#include <iomanip>
#include "clsCurrency.h"
#include "clsInputValidate.h"
using namespace std;
class clsListCurrencyScreen :protected clsScreen
{
private:
    static void _PrintCurrencyrRecordLine(clsCurrency Currency)
    {
        cout << setw(8) << left << "" << "| " << setw(30) << left << Currency.Country();
        cout << "| " << setw(8) << left << Currency.Code();
        cout << "| " << setw(28) << left << Currency.Name();
        cout << "| " << setw(10) << left << Currency.Rate;
    }


public:
    static void ShowCurrencyList()
    {
        vector <clsCurrency> vCurrency = clsCurrency::GetCurrencyData();

        string Title = "\t  Currency List Screen";
        string SubTitle = "\t    (" + to_string(vCurrency.size()) + ") Currency(s).";

        _DrawScreenHeader(Title, SubTitle);

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "______________________________________________\n" << endl;

        cout << setw(8) << left << "" << "| " << left << setw(30) << "Country";
        cout << "| " << left << setw(8) << "Code";
        cout << "| " << left << setw(28) << "Name";
        cout << "| " << left << setw(10) << "Rate / (1$)";
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "______________________________________________\n" << endl;

        if (vCurrency.size() == 0)
            cout << "\t\t\t\tNo Currency Available In the System!";
        else

            for (clsCurrency Currency : vCurrency)
            {

                _PrintCurrencyrRecordLine(Currency);
                cout << endl;
            }

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "______________________________________________\n" << endl;
    }




};

