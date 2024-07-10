#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"

class clsTransferBalance:protected clsScreen
{
private:
    static void _PrintClient(clsBankClient Client)
    {
        cout << "\nClient Card:";
        cout << "\n___________________";
        cout << "\nFirstName   : " << Client.FirstName;
        cout << "\nLastName    : " << Client.LastName;
        cout << "\nFull Name   : " << Client.FullName();
        cout << "\nEmail       : " << Client.Email;
        cout << "\nPhone       : " << Client.Phone;
        cout << "\nAcc. Number : " << Client.AccountNumber();
        cout << "\nPassword    : " << Client.PinCode;
        cout << "\nBalance     : " << Client.AccountBalance;
        cout << "\n___________________\n";

    }

    static string _ReadAccountNumber()
    {
        string AccountNumber = "";
        cout << "\nPlease enter Account Number to transfer from :  ";
        cin >> AccountNumber;
        return AccountNumber;
    }


public:
    static void ShowBalanceScreen() {
        _DrawScreenHeader("\t   Transfer Balance Screen");
        string AccountNumber1 = _ReadAccountNumber();
      
        while (!clsBankClient::IsClientExist(AccountNumber1))
        {
            cout << "\nClient with [" << AccountNumber1 << "] does not exist.\n";
            AccountNumber1 = _ReadAccountNumber();
        }
        clsBankClient Client1 = clsBankClient::Find(AccountNumber1);
        _PrintClient(Client1);
         string AccountNumber2 = _ReadAccountNumber();
         while (!clsBankClient::IsClientExist(AccountNumber2))
         {
             cout << "\nClient with [" << AccountNumber2 << "] does not exist.\n";
             AccountNumber2 = _ReadAccountNumber();
         }
         clsBankClient Client2 = clsBankClient::Find(AccountNumber2);
         _PrintClient(Client2);
         double Amount = 0;
         cout << "\nEntre Tranfert amount :  ";
         Amount = clsInputValidate::ReadDblNumber();
       
     while (Amount > Client1.AccountBalance)
             {
                cout << "Amount Exeeds the available Balnces , Pleace another Amount ?";
                Amount = clsInputValidate::ReadDblNumber();
             }
     cout << "\nAre you sure you want to perform this transaction? ";
         char Answer = 'n';
         cin >> Answer;
         if (Answer == 'Y' || Answer == 'y')
         {
             if (Client1.Transfert(Amount, Client2))
             {
                      cout << "\nTransfer Done Successfully.\n";
             }
             else
             {
                     cout << "\nTransfer Field.\n";
             }
             _PrintClient(Client1);
             _PrintClient(Client2);
         }
    }
};

