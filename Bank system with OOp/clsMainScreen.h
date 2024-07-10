#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsClientListScreen.h"
#include "clsAddNewClientsScreen.h"
#include "clsDeleteClientScreen.h"
#include"clsFindClientScreen.h"
#include"clsManageUsersScreen.h"
#include"clsShowUpdateClientScreen.h"
#include"clsTransactionsScreen.h"
#include "clsManageUsersScreen.h"
#include "clsLoginHistoryScreen.h"
#include "globals.h"
#include <iomanip>
class clsMainScreen : protected clsScreen
{
private:
    enum enMainMenueOptions {
        eListClients = 1, eAddNewClient = 2, eDeleteClient = 3,
        eUpdateClient = 4, eFindClient = 5, eShowTransactionsMenue = 6,
        eManageUsers = 7,eLoginHistory = 8 , eExit = 9
    };
    static short _ReadMainMenuOption() {
        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 9]? ";
        short choise = clsInputValidate::ReadShortNumberBetween(1, 9, "Enter Number between 1 to 9? ");
        return choise;
   }

    static  void _GoBackToMainMenue()
    {
        cout << setw(37) << left << "" << "\n\tPress any key to go back to Main Menue...\n";
        system("pause>0");
        ShowMainMenue();
    }

    static void _Logout()
    {

        CurrentUser = clsUser::Find("", "");
        //then it will go back to main function.
    }

    static void _ShowAllClientsScreen()
    {
        clsClientListScreen::ShowClientsList();
    }

    static void _ShowAddNewClientsScreen()
    {
        clsAddNewClientsScreen::AddNewClient();
    }

    static void _ShowDeleteClientScreen()
    {
        clsDeleteClientScreen::DeleteClient();
    }

    static void _ShowUpdateClientScreen()
    {
        clsShowUpdateClientScreen::UpdateClient();

    }

    static void _ShowFindClientScreen()
    {
        clsFindClientScreen::FindClient();

    }

    static void _ShowTransactionsMenue()
    {
       clsTransactionsScreen::TransactionsMenue();

    }

    static void _ShowManageUsersMenue()
    {
       clsManageUsersScreen::ShowManageUsersMenue();

    }

    static void _ShowLoginHistory()
    {
        clsLoginHistoryScreen::ShowLoginHistory();
    }

    static void _ShowEndScreen()
    {
        cout << "\nEnd Screen Will be here...\n";

    }
    static void _PerfromMainMenueOption(enMainMenueOptions Main) {
        switch (Main)
        {
        case clsMainScreen::eListClients:
            system("cls");
            _ShowAllClientsScreen();
            _GoBackToMainMenue();
            break;
        case clsMainScreen::eAddNewClient:
            system("cls");
            _ShowAddNewClientsScreen();
            _GoBackToMainMenue();
            break;
        case clsMainScreen::eDeleteClient:
            system("cls");
            _ShowDeleteClientScreen();
            _GoBackToMainMenue();
            break;
        case clsMainScreen::eUpdateClient:
            system("cls");
            _ShowUpdateClientScreen();
            _GoBackToMainMenue();
            break;
        case clsMainScreen::eFindClient:
            system("cls");
            _ShowFindClientScreen();
            _GoBackToMainMenue();
            break;
        case clsMainScreen::eShowTransactionsMenue:
            system("cls");
            _ShowTransactionsMenue();
            _GoBackToMainMenue();
            break;
        case clsMainScreen::eManageUsers:
            system("cls");
            _ShowManageUsersMenue();
            _GoBackToMainMenue();
            break;
        case clsMainScreen::eLoginHistory:
            system("cls");
            _ShowLoginHistory();
            _GoBackToMainMenue();
            break;
        case clsMainScreen::eExit:
            system("cls");
            _Logout();
            break;
        }
    }
public:
	static void ShowMainMenue() {
        system("cls");
		_DrawScreenHeader("\t\tMain Screen");
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t\tMain Menu\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] Show Client List.\n";
        cout << setw(37) << left << "" << "\t[2] Add New Client.\n";
        cout << setw(37) << left << "" << "\t[3] Delete Client.\n";
        cout << setw(37) << left << "" << "\t[4] Update Client Info.\n";
        cout << setw(37) << left << "" << "\t[5] Find Client.\n";
        cout << setw(37) << left << "" << "\t[6] Transactions.\n";
        cout << setw(37) << left << "" << "\t[7] Manage Users.\n";
        cout << setw(37) << left << "" << "\t[8] Login History.\n";
        cout << setw(37) << left << "" << "\t[9] Logout.\n";
        cout << setw(37) << left << "" << "===========================================\n";
        _PerfromMainMenueOption((enMainMenueOptions)_ReadMainMenuOption());
	}
  
};

