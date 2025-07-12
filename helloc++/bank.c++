#include <iostream>
#include <string>
#include <stdexcept>

class BankAccount
{
private:
    std::string accountNumber;
    double balance;

public:
    // constructor
    BankAccount(const std::string &accNum, double initialBalance)
        : accountNumber(accNum), balance(initialBalance)
    {
        if (initialBalance < 0)
        {
            throw std::runtime_error("Initial balance cannot be negative!");
        }
    }

    // deposit money
    void deposit(double amount)
    {
        if (amount <= 0)
        {
            throw std::runtime_error("Deposit amount must be positive!");
        }
        balance += amount;
    }

    // withdraw money
    void withdraw(double amount)
    {
        if (amount <= 0)
        {
            throw std::runtime_error("Withdrawl amount should be greater than 0");
            balance -= amount;
        }
    }

    // gett current balance
    double getBalance() const
    {
        return balance;
    }

    // get account number
    std::string getAccountNumber() const
    {
        return accountNumber;
    }
};


int main(){
    try{
        //create an account with $1000 initial balance
        BankAccount myAccount("12345",1000.0);

        std::cout<<"Account Number:"<<myAccount.getAccountNumber()<<std::endl;
        std::cout<<"Initial Balance:"<<myAccount.getBalance()<<std::endl;

        //Deposit $500
        myAccount.deposit(500.0);
        std::cout<<"After depositing $500: $"<<myAccount.getBalance()<<std::endl;

        //withdraw $200
        myAccount.withdraw(200.0);
        std::cout<<"After withdrawing $200: $"<<myAccount.getBalance()<<std::endl;
    }
    catch(const std::runtime_error& e) {
        std::cerr<<"Error"<< e.what()<<std::endl;
        return 1;
    }
    return 0;

}