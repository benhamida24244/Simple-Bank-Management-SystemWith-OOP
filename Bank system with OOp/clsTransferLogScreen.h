#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsBankClient.h"
class clsTransferLogScreen :protected clsScreen
{
private:
    static void PrintTransferHistoryRecordLine(clsBankClient::InfoTransfer info)
    {
        cout << setw(8) << left << "" << "| " << setw(25) << left << info.Date;
        cout << "| " << setw(8) << left << info.Saact;
        cout << "| " << setw(8) << left << info.Daact;
        cout << "| " << setw(8) << left << info.amount;
        cout << "| " << setw(8) << left << info.Sbalace;
        cout << "| " << setw(12) << left << info.Dbalance;
        cout << "| " << setw(8) << left << info.User;
    }


public:
    static void ShowTransferLogScreen() {
        vector<clsBankClient::InfoTransfer> Vlist = clsBankClient::LoadTransferHistoryDataFromFile();
        string Title = "\t  Transfer History Screen";
        string SubTitle = " (" + to_string(Vlist.size()) + ") Transfert Between Account(s).";
        _DrawScreenHeader(Title, SubTitle); 
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        cout << setw(8) << left << "" << "| " << left << setw(25) << "Time";
        cout << "| " << left << setw(8) << "s.Acct";
        cout << "| " << left << setw(8) << "d.Acct";
        cout << "| " << left << setw(8) << "Amount";
        cout << "| " << left << setw(8) << "s.Balance";
        cout << "| " << left << setw(12) << "d.Balance";
        cout << "| " << left << setw(15) << "User";
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;
        if (Vlist.size() == 0)
            cout << "\t\t\t\tNo Login Available In the System!";
        else
            for (clsBankClient::InfoTransfer C : Vlist)
            {
               PrintTransferHistoryRecordLine(C);
                cout << endl;
            }
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;
    }





};

