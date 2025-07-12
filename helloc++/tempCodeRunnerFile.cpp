#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

class ATM {
private:
    int account = 0;
    double balance = 0.0;
    int pin = 0;

public:
    ATM() = default;

    void fetchAccount() {
        std::cout << "Please enter your account number: ";
        std::cin >> account;
    }

    void fetchPin() {
        std::cout << "Please enter your PIN: ";
        std::cin >> pin;
    }

    int getAccount() const noexcept { return account; }
    int getPin() const noexcept { return pin; }
    double getBalance() const noexcept { return balance; }
    void setBalance(double newBalance) noexcept { balance = newBalance; }

    void performTransaction() {
        int option = 0;
        do {
            std::cout << "\nChoose an operation to perform:\n"
                      << "1. Check Balance\n2. Deposit\n3. Withdraw\n4. Exit\n"
                      << "Select an option: ";
            std::cin >> option;

            switch (option) {
                case 1:
                    std::cout << "Your balance: " << balance << '\n';
                    break;
                case 2: {
                    double amount;
                    std::cout << "Enter amount to deposit: ";
                    std::cin >> amount;
                    if (amount > 0) {
                        balance += amount;
                        std::cout << "Deposit successful. New balance: " << balance << '\n';
                    } else {
                        std::cout << "Invalid amount entered!\n";
                    }
                    break;
                }
                case 3: {
                    double amount;
                    std::cout << "Enter amount to withdraw: ";
                    std::cin >> amount;
                    if (amount > 0 && amount <= balance) {
                        balance -= amount;
                        std::cout << "Withdrawal successful. New balance: " << balance << '\n';
                    } else {
                        std::cout << "Insufficient balance or invalid amount!\n";
                    }
                    break;
                }
                case 4:
                    std::cout << "Thank you for using LBH Bank. Exiting...\n";
                    break;
                default:
                    std::cout << "Invalid option! Please try again.\n";
            }
        } while (option != 4);
    }
};

struct Account {
    int number;
    int pin;
    double balance;
};

bool loadAccounts(const std::string& filename, std::vector<Account>& accounts) {
    std::ifstream inputFile(filename);
    if (!inputFile) {
        std::cerr << "Error opening file: " << filename << '\n';
        return false;
    }

    Account acc;
    while (inputFile >> acc.number >> acc.pin >> acc.balance) {
        accounts.push_back(acc);
    }
    return true;
}

bool saveAccounts(const std::string& filename, const std::vector<Account>& accounts) {
    std::ofstream outFile(filename);
    if (!outFile) {
        std::cerr << "Error opening file for writing: " << filename << '\n';
        return false;
    }

    for (const auto& acc : accounts) {
        outFile << acc.number << ' ' << acc.pin << ' ' << acc.balance << '\n';
    }
    return true;
}

int main() {
    std::vector<Account> accounts;
    const std::string filename = "bank.txt";

    if (!loadAccounts(filename, accounts)) {
        return 1;
    }

    std::cout << "Welcome to LBH Bank 🙏\n";

    ATM atm;
    atm.fetchAccount();

    auto it = std::find_if(accounts.begin(), accounts.end(),
                           [&atm](const Account& acc) {
                               return acc.number == atm.getAccount();
                           });

    if (it == accounts.end()) {
        std::cerr << "Error: Account not found!\n";
        return 1;
    }

    atm.fetchPin();
    if (it->pin != atm.getPin()) {
        std::cerr << "Error: Invalid PIN!\n";
        return 1;
    }

    atm.setBalance(it->balance);

    atm.performTransaction();

    // Update balance back
    it->balance = atm.getBalance();

    if (!saveAccounts(filename, accounts)) {
        std::cerr << "Error: Could not save account data.\n";
        return 1;
    }

    std::cout << "Account data saved successfully. Have a great day! 😊\n";
    return 0;
}
