#include <iostream>
#include <fstream> 
#include<string>
#include<vector>

using namespace std;

int main ()
{
    std::vector<int> pins;
    std::vector<int> accounts;
    std::vector<int> balance;

    std::ifstream inputfile("bank.txt"); //open the file 

    //check if the file opened successfully 
    if (!inputfile.is_open()){
        std::cerr<<"Error opening the file !"<<endl;
        return 1;
    }

    //read from the file and store those to respective vector arrays
  int acc,pin,bal;
  while (inputfile>>acc>>pin>>bal){
    accounts.push_back(acc);
    pins.push_back(pin);
    balance.push_back(bal);

  }

  inputfile.close();

  cout << "Accounts: ";
for (int a : accounts) cout << a << " ";

cout << "\nPINs: ";
for (int p : pins) cout << p << " ";

cout << "\nBalances: ";
for (int b : balance) cout << b << " ";

cout << endl;




int useracc,userpin;

//ask the user for account
cout<<"Please enter the account :"<<endl;
cin>>useracc;
for(int i=0;i++;i<accounts.size()){
  if(accounts[i]=useracc){
    return 1;
  }
  else{cout<<"account not found!";}
}


    
}