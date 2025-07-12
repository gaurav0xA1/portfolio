#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

class atm
{
private:
    int account;
    float balance;
    int pin;
    int option;
    float amount;

public:

    void fetchacc()
    {
        cout << "Please enter your account number :" << endl;
        cin >> account;
    }

    void fetchpass()
    {
        cout << "\nPlease enter your PIN :" << endl;
        cin >> pin;
    }
    int getAccount() const
    {
        return account;
    }

    int getPin() const
    {
        return pin;
    }

    void setbalance(float newBalance){
        balance=newBalance;
    }

    void displayoptions()
    {
        cout << "\nChoose an operation ot perform :\n"
             << endl;
        cout << "1. Check Balance : \n 2. Deposit \n 3. Withdraw \n 4. Exit" << endl;
        cin >> option;
    }
    
    int getOption() const { return option; }

    float getBalance(){
        return balance;
    }

    void pinreset(){

    }

    void selectoption()
    {
        if (option == 1)
        {
            // checkbal
            cout << "Your balance for account " << account << " is :" << balance << endl;
        }
        else if (option == 2)
        {
            // deposit
            cout << "Enter the amount you want to deposit :" << endl;
            cin >> amount;
            balance += amount;
        }
        else if (option == 3)
        {
            // withdraw
            cout << "Enter the amount you want to withdraw:" << endl;
            cin >> amount;
            if (amount <= balance)
            {
                balance -= amount;
            }
            else
            {
                cout << "Insufficient Balance!" << endl;
            }
        }
        else if (option == 4)
        {
            // exit
            return;
        }
        else
        {
            cout << "Invalid output!";
        }
    }
};

int main()
{

    std::vector<int> pins;
    std::vector<int> accounts;
    std::vector<int> balance;

    std::ifstream inputfile("bank.txt"); // open the file

    // check if the file opened successfully
    if (!inputfile.is_open())
    {
        std::cerr << "Error opening the file !" << endl;
        return 1;
    }

    // read from the file and store those to respective vector arrays
    int acc, pin, bal;
    while (inputfile >> acc >> pin >> bal)
    {
        accounts.push_back(acc);
        pins.push_back(pin);
        balance.push_back(bal);
    }

    inputfile.close();

    // welcome the user first
    cout << "Welcome to LBH Bank 🙏" << endl;
    atm obj;

    obj.fetchacc();

    // check if the account exists
    bool account_exists = false;
    size_t account_index = 0;
    for (; account_index < accounts.size(); account_index++)
    {
        if (accounts[account_index] == obj.getAccount())
        { // Need getAccount()
            account_exists = true;
            break;
        }
    }

    if (!account_exists)
    {
        cerr << "Error : Acount not found !" << endl;
        return 1;
    }

    obj.fetchpass();
    if (pins[account_index] != obj.getPin())
    { // Need getPin()
        cerr << "Error: Invalid PIN!" << endl;
        return 1; // Exit if PIN is wrong
    }
    obj.setbalance(balance[account_index]);

    do {
            obj.displayoptions();
        obj.selectoption();
        balance[account_index]=obj.getBalance();
    } while (obj.getOption()!=4);

    //save to file 
    ofstream outfile("bank.txt");
    if (!outfile.is_open()){
        cerr<<"Error opening the file !!"<<endl;
        return 1;
    }

    for(size_t i=0;i<accounts.size();i++){
        outfile<<accounts[i]<<" "<<pins[i]<<" "<<balance[i]<<endl;
    }

    outfile.close();
    cout<<"Account data saved successfully . Thank you."<<endl;
}