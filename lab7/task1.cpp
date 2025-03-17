#include <iostream>
using namespace std;

class Account {
protected:
    int accountNumber;
    double balance;
    string accountHolderName;
    string accountType;

public:
    Account(int accNum, double bal, string holderName, string accType = "General")
        : accountNumber(accNum), balance(bal), accountHolderName(holderName), accountType(accType) {}

    virtual void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposited: $" << amount << endl;
        } else {
            cout << "Invalid deposit amount." << endl;
        }
    }

    virtual void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Withdrawn: " << amount << endl;
        } else {
            cout << "Invalid withdrawal or insufficient balance." << endl;
        }
    }

    virtual double calculateInterest() const {
        return 0.0;
    }

    virtual void printStatement() const {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Balance: " << balance << endl;
        cout << "Account Holder: " << accountHolderName << endl;
        cout << "Account Type: " << accountType << endl;
    }

    virtual void getAccountInfo() const {
        printStatement();
    }

    virtual ~Account() {}
};

class SavingsAccount : public Account {
    double interestRate;
    double minimumBalance;

public:
    SavingsAccount(int accNum, double bal, string holderName, double rate, double minBal)
        : Account(accNum, bal, holderName, "Savings"), interestRate(rate), minimumBalance(minBal) {}

    double calculateInterest() const {
        return balance * interestRate / 100;
    }

    void withdraw(double amount)  {
        if (balance - amount >= minimumBalance) {
            Account::withdraw(amount);
        } else {
            cout << "Cannot withdraw. Minimum balance requirement not met." << endl;
        }
    }

    void printStatement() const  {
        Account::printStatement();
        cout << "Interest Rate: " << interestRate << "%\nMinimum Balance: " << minimumBalance << endl;
    }
};

class CheckingAccount : public Account {
    double overdraftLimit;

public:
    CheckingAccount(int accNum, double bal, string holderName, double overdraft)
        : Account(accNum, bal, holderName, "Checking"), overdraftLimit(overdraft) {}

    void withdraw(double amount)  {
        if (balance - amount >= -overdraftLimit) {
            balance -= amount;
            cout << "Withdrawn: $" << amount << endl;
        } else {
            cout << "Overdraft limit exceeded." << endl;
        }
    }

    void printStatement() const  {
        Account::printStatement();
        cout << "Overdraft Limit: $" << overdraftLimit << endl;
    }
};

class FixedDepositAccount : public Account {
    double fixedInterestRate;
    string maturityDate;

public:
    FixedDepositAccount(int accNum, double bal, string holderName, double rate, string maturity)
        : Account(accNum, bal, holderName, "Fixed Deposit"), fixedInterestRate(rate), maturityDate(maturity) {}

    double calculateInterest() const  {
        return balance * fixedInterestRate / 100;
    }

    void printStatement() const  {
        Account::printStatement();
        cout << "Fixed Interest Rate: " << fixedInterestRate << "%\nMaturity Date: " << maturityDate << endl;
    }
};

int main() {
    Account* accounts[3];

    accounts[0] = new SavingsAccount(1001, 5000.0, "Lucky", 5.0, 1000.0);
    accounts[1] = new CheckingAccount(1002, 2000.0, "Kumar", 500.0);
    accounts[2] = new FixedDepositAccount(1003, 10000.0, "Maheshwari", 7.0, "2025-12-31");

    for (int i = 0; i < 3; ++i) {
        accounts[i]->getAccountInfo();
        cout << "Interest Earned: $" << accounts[i]->calculateInterest() << "\n";
        cout << "\n";
        delete accounts[i];
    }

    return 0;
}
