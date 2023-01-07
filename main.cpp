#include <iostream>
#include <string>
using namespace std;

class bank{
    string name;
    string address;
    string account;
    double balance_S;
    double balance_C;
    bool openS = false;
    bool openC = false;

public:
    void openAcc();
    void depositeM();
    void withdrawM();
    void displayAcc();
};

void bank:: openAcc() {
    cout << "1) Open Account" <<endl;
    cout << "Enter your Full Name : ";
    cin >> name;

    cout << "Enter your Address : ";
    cin >> address;

    cout << "Please select the type of account you want to open; Saving(S), Chequing(C) : ";
    cin >> account;

    cout << "Enter amount for deposite : ";
    if(account=="S" || account == "Saving"){
        openS=true;
        cin >> balance_S;
    }else{
        openC=true;
        cin >> balance_C;
    }

    cout << "Your account is created successfully!" << endl<<endl;
}

void bank :: depositeM(){
    double placeHolder;
    cout << "2) Deposite Money" <<endl;
    cout << "Enter the account to deposite : ";
    cin >> account;
    cout << "Enter amount for deposite : ";
    cin >> placeHolder;
    if(account=="S" || account == "Saving") {
        balance_S += placeHolder;
        cout << "Total amount you deposite is : " << placeHolder << endl;
        cout << "Your current balance is : " << balance_S << endl<<endl;
    }else if(account=="C" || account == "Chequing"){
        balance_C += placeHolder;
        cout << "Total amount you deposite is : " << placeHolder << endl;
        cout << "Your current balance is : " << balance_C << endl<<endl;
    }
}

void bank ::withdrawM() {
    double amount;
    cout << "3) Withdraw Money" <<endl;
    cout << "Enter the account to withdraw : ";
    cin >> account;
    cout << "Enter amount to withdraw : ";
    cin>> amount;
    if(account=="S" || account == "Saving") {
        balance_S -= amount;
        cout << "Total amount you withdrawn is : " << amount << endl;
        cout << "Your current balance is : " << balance_S << endl<<endl;
    }else if(account=="C" || account == "Chequing"){
        balance_C -= amount;
        cout << "Total amount you withdrawn is : " << amount << endl;
        cout << "Your current balance is : " << balance_C << endl<<endl;
    }
}

void bank :: displayAcc(){
    cout << "4) Display Account" <<endl;
    cout << "Full Name : " << name << endl;
    cout << "Address : " << address <<endl;
    if(openS==true && openC==true){
        cout << "Type of account(s) : Saving, Chequing" <<endl;
        cout << "Current balance " << endl;
        cout << "Saving : " <<balance_S << endl;
        cout << "Chequing : " <<balance_C <<endl<<endl;
    }else if(openC==true){
        cout << "Type of account(s) : Chequing" << endl;
        cout << "Current balance " << endl;
        cout << "Chequing : " <<balance_C <<endl<<endl;
    }else if(openS==true){
        cout << "Type of account(s) : Saving" << endl;
        cout << "Current balance " << endl;
        cout << "Saving : " <<balance_S << endl<<endl;
    }
}

int main() {
    int select;
    bank obj;
    do {
        cout << "Welcome to the bank, please enter the number of your choice" <<endl;
        cout << "1) Open account" << endl;
        cout << "2) Deposite money" << endl;
        cout << "3) Withdraw" << endl;
        cout << "4) Display account" << endl;
        cout << "5) Exit" << endl;
        cin >> select;
        if(select==1){
            obj.openAcc();
        }else if(select==2){
            obj.depositeM();
        }else if(select==3){
            obj.withdrawM();
        }else if(select==4){
            obj.displayAcc();
        }else if(select==5){
            exit(1);
        }else{
            cout << "This is not an option, please enter the number of your choice : " << endl;
        }

    }while(select != '5');

    return 0;
}
