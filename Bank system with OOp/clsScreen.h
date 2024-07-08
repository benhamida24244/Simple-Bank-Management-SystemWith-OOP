#pragma once
#include <iostream>
#include "clsUser.h"
#include "globals.h"
#include "clsDate.h"
using namespace std;

class clsScreen
{
private:
    static void _printUsersandDate() {
        cout << "\n\t\t\t\t\tUser :" << CurrentUser.GetUserName() << "\n";
        cout << "\t\t\t\t\tDate :" << clsDate::DateToString(clsDate()) << "\n\n"; 
    }


protected:


	static void _DrawScreenHeader(string Title, string SubTitle = "") {
        cout << "\t\t\t\t\t______________________________________";
        cout << "\n\n\t\t\t\t\t  " << Title;
        if (SubTitle != "")
        {
            cout << "\n\t\t\t\t\t  " << SubTitle;
        }
        cout << "\n\t\t\t\t\t______________________________________\n\n";
        _printUsersandDate();
    }
    static bool CheckAccessRights(clsUser::enPermissions permission) {
        if (!CurrentUser.CheckAccessPermission(permission))
        {
            cout << "\t\t\t\t\t______________________________________";
            cout << "\n\n\t\t\t\t\t  Access Denied! Contact your Admin.";
            cout << "\n\t\t\t\t\t______________________________________\n\n";
            return false;
        }
        else
        {
            return true;
        }
    }

};

