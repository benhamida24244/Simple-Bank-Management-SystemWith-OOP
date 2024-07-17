#pragma once
#include <iostream>
#include <string>
#include "clsPerson.h"
#include "clsString.h"
#include <vector>
#include <fstream>
#include "clsDate.h"


using namespace std;

class clsCurrency
{
private:
    enum enMode { EmptyMode = 0, UpdateMode = 1};
    enMode _Mode;
    string _Country;
    string _Code;
    string _Name;
    float _Rate;
    bool _MarkedForDelete = false;

    static clsCurrency _ConvertLinetoCurrencyObject(string Line, string Seperator = "#//#")
    {
        vector<string> vCurrencydata;
        vCurrencydata = clsString::Split(Line, Seperator);

        return clsCurrency(enMode::UpdateMode, vCurrencydata[0], vCurrencydata[1], vCurrencydata[2],
            stof(vCurrencydata[3]));
    }
    static string _ConverCurrencyObjectToLine(clsCurrency data, string Seperator = "#//#")
    {
        string CurrencyRecord = "";
        CurrencyRecord += data.Country() + Seperator;
        CurrencyRecord += data.Code() + Seperator;
        CurrencyRecord += data.Name() + Seperator;
        CurrencyRecord += to_string(data.Rate);
        return CurrencyRecord;

    }
    static  vector <clsCurrency> _LoadCurrencyDataFromFile()
    {

        vector <clsCurrency> vCurrency;

        fstream MyFile;
        MyFile.open("Currency.txt", ios::in);//read Mode

        if (MyFile.is_open())
        {

            string Line;


            while (getline(MyFile, Line))
            {

                clsCurrency CurrencyData = _ConvertLinetoCurrencyObject(Line);

                vCurrency.push_back(CurrencyData);
            }

            MyFile.close();

        }
         
        return vCurrency;

    }
    static void _SaveCurrencyDataToFile(vector <clsCurrency> vCurrency)
    {

        fstream MyFile;
        MyFile.open("Currency.txt", ios::out);//overwrite

        string DataLine;

        if (MyFile.is_open())
        {

            for (clsCurrency U : vCurrency)
            {
                if (U.MarkedForDeleted() == false)
                {
                    //we only write records that are not marked for delete.  
                    DataLine = _ConverCurrencyObjectToLine(U);
                    MyFile << DataLine << endl;

                }

            }

            MyFile.close();

        }

    }


    static clsCurrency _GetEmptyCurrencyObject()
    {
        return clsCurrency(enMode::EmptyMode, "", "", "", 0);
    }

    void _Update()
    {
        vector <clsCurrency> _vClients;
        _vClients = _LoadCurrencyDataFromFile();

        for (clsCurrency& C : _vClients)
        {
            if (C.Code() == Code())
            {
                C = *this;
                break;
            }

        }

        _SaveCurrencyDataToFile(_vClients);

    }
public:
    clsCurrency(enMode Mode, string Country, string Code, string Name, float Rate) {
        _Mode = Mode;
        _Country = Country;
        _Code = Code;
        _Name = Name;
        _Rate = Rate;
    }
    bool IsEmpty()
    {
        return (_Mode == enMode::EmptyMode);
    }

    bool MarkedForDeleted()
    {
        return _MarkedForDelete;
    }

    string Country()
    {
        return _Country;
    }

    string Name()
    {
        return _Name;
    }
    string Code() {
        return _Code;
    }

    void  setRate(float rate) {
        _Rate = rate;
    }
    float getRate() {
        return _Rate;
    }
    __declspec(property (get = getRate, put = setRate)) float Rate;

    static vector < clsCurrency> GetCurrencyData() {
        return _LoadCurrencyDataFromFile();
    }
    static clsCurrency Find(string Code)
    {
        Code = clsString::UpperAllString(Code);

        fstream MyFile;
        MyFile.open("Currency.txt", ios::in);//read Mode

        if (MyFile.is_open())
        {
            string Line;
            while (getline(MyFile, Line))
            {
                clsCurrency Currency = _ConvertLinetoCurrencyObject(Line);
                if  (Currency.Code()== Code)
                {
                    MyFile.close();
                    return Currency;
                }

            }

            MyFile.close();

        }

        return _GetEmptyCurrencyObject();
    }

    static bool IsCurrencyExist(string CodeCurrency) {
        clsCurrency Currency = clsCurrency::Find(CodeCurrency);
        return (!Currency.IsEmpty());
    }
    enum enSaveResults { svFaildEmptyObject = 0, svSucceeded = 1, svFaildAccountNumberExists = 2 };
    enSaveResults Save() {
        switch (_Mode)
        {
        case clsCurrency::EmptyMode:
              if (IsEmpty())
                      {
                                 return enSaveResults::svFaildEmptyObject;
                     }
            break;
        case clsCurrency::UpdateMode:
            _Update();

            return enSaveResults::svSucceeded;

            break;
        }
    }

    void CalculatorCurrency(clsCurrency Code , float amount) {
        float TransferDoular;
        float TransferNewCurrency;
        TransferDoular = amount / Rate;
        cout << "\n\nThe amount after Transfer to Dollar : " << TransferDoular << endl;
        TransferNewCurrency = TransferDoular * Code.Rate;
        cout << "\nThe amount after Transfer to " << Code.Name() + ":  " << TransferNewCurrency << endl;
       
    }
};