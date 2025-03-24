#include<iostream>
using namespace std;
class Currency
{
  public:
  double amount;
  string CurrencyCode,Symbol;
  double ExchangeRate;
  Currency(double amount,string cc,string cs,double er):amount(amount),CurrencyCode(cc),
  Symbol(cs),ExchangeRate(er){}
  Currency(){amount = 3;}
  virtual void convertToBase(){cout << "Converting to Base" << endl;}
  virtual void convertToTargetCurrency() { cout << "Converting to Target currency" << endl; }
  virtual void displayCurrent()
  {
    cout << "Amount  Currency : " << amount << endl;
    cout << "ExchangeRate of Currency : " << ExchangeRate << endl;
    cout << "Symbol  : " << Symbol << endl;
    cout << "Code of Currency : " << CurrencyCode << endl;
  }
};
class Dollar : public Currency
{
  private:
  double amount,ExchangeRate;
  string Symbol,CurrencyCode;
  public:
    void convertToBase() 
    { cout << "Converting to Base" << endl; 
      cout << "One "<< Symbol << " equals to " << ExchangeRate << "Base Currency" << endl; 
      cout << "now , " << amount << " " << Symbol << " are " << ExchangeRate*amount << " Base Currency" << endl;  
    }
    void displayCurrent()
     { cout << "Amount of Currency : " << amount << endl;
       cout << "ExchangeRate of Currency : " << ExchangeRate << endl;
       cout << "CurrencySymbol  : " << Symbol << endl;
       cout << "Code of Currency : " << CurrencyCode << endl; }
};
class Euro : public Currency
{
private:
  double amount, ExchangeRate;
  string Symbol, CurrencyCode;

public:
  void convertToBase()
  {
    cout << "Converting to Base" << endl;
    cout << "One " << Symbol << " equals to " << ExchangeRate << "Base Currency" << endl;
    cout << "now , " << amount << " " << Symbol << " are " << ExchangeRate * amount << " Base Currency" << endl;
  }
  void displayCurrent()
  {
    cout << "Amount of Currency : " << amount << endl;
    cout << "ExchangeRate of Currency : " << ExchangeRate << endl;
    cout << "CurrencySymbol  : " << Symbol << endl;
    cout << "Code of Currency : " << CurrencyCode << endl;
  }
};
class Rupee : public Currency
{
private:
  double amount, ExchangeRate;
  string Symbol, CurrencyCode;

public:
  Rupee(double amount, string cc, string cs, double er) : amount(amount),CurrencyCode(cc),Symbol(cs), ExchangeRate(er),
  Currency(amount,cc,cs,er){}
  Rupee(){cout << amount << endl;}
  void convertToBase()
  {
    cout << "Converting to Base" << endl;
    cout << "One " << Symbol << " equals to " << ExchangeRate << " Base Currency" << endl;
    cout << "now , " << amount << " " << Symbol << " are " << ExchangeRate * amount << " Base Currency" << endl;
  }
  void displayCurrent()
  {
    cout << "Amount of Currency : " << amount << endl;
    cout << "ExchangeRate of Currency : " << ExchangeRate << endl;
    cout << "CurrencySymbol  : " << Symbol << endl;
    cout << "Code of Currency : " << CurrencyCode << endl;
  }
};
int main()
{
  cout << "Running " << endl;
  Currency c(10,"Dollar","$",200);
  c.displayCurrent();
  Rupee r(100, "RUpee", "pkr", 300);
  r.displayCurrent();
  r.convertToBase();
}
