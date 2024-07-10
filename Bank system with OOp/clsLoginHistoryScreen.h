#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsUser.h"

using namespace std;
class clsLoginHistoryScreen:protected clsScreen
{
private:
    static void PrintLoginHistoryRecordLine(clsUser::LoginHistory info)
    {

        cout << setw(8) << left << "" << "| " << setw(45) << left << info.time;
        cout << "| " << setw(20) << left << info.Username;
        cout << "| " << setw(12) << left << info.Password;
        cout << "| " << setw(20) << left << info.permission;
    }

public:
    static void ShowLoginHistory() {
        if (!CheckAccessRights(clsUser::enPermissions::pLoginHistory))
        {
            return;// this will exit the function and it will not continue
        }
        vector<clsUser::LoginHistory>vLogin = clsUser::LoadLoginHistoryDataFromFile();
        string Title = "\t  Login History Screen";
        string SubTitle = "\t    (" + to_string(vLogin.size()) + ") Users(s).";
        _DrawScreenHeader(Title, SubTitle);
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        cout << setw(8) << left << "" << "| " << left << setw(45) << "Time";
        cout << "| " << left << setw(20) << "Username";
        cout << "| " << left << setw(12) << "Password";
        cout << "| " << left << setw(20) << "Permission";
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;
        if (vLogin.size() == 0)
            cout << "\t\t\t\tNo Login Available In the System!";
        else
            for (clsUser::LoginHistory C : vLogin)
            {
                PrintLoginHistoryRecordLine(C);
                cout << endl;
            }
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;
    }
    


};

