#include <iostream>
using namespace std;

class ATM {
private:
    int pin;
    float balance;

public:
    ATM(int p, float b) {
        pin = p;
        balance = b;
    }

    bool authenticate(int enteredPin) {
        return enteredPin == pin;
    }

    void showBalance() {
        cout << "Current Balance: Rs " << balance << endl;
    }

    void withdraw(float amount) {
        if (amount <= balance && amount > 0) {
            balance -= amount;
            cout << "Withdrawal successful.\n";
        } else {
            cout << "Invalid or insufficient balance.\n";
        }
    }

    void deposit(float amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposit successful.\n";
        } else {
            cout << "Invalid amount.\n";
        }
    }
};

int main() {
    ATM users[3] = {
        ATM(1111, 5000),
        ATM(2222, 10000),
        ATM(3333, 7500)
    };

    int userChoice, pin, choice;
    float amount;

    cout << "===== ATM SYSTEM (OOP VERSION) =====\n";

    cout << "Select User (1-3): ";
    cin >> userChoice;

    if (userChoice < 1 || userChoice > 3) {
        cout << "Invalid user.\n";
        return 0;
    }

    int index = userChoice - 1;

    cout << "Enter PIN: ";
    cin >> pin;

    if (!users[index].authenticate(pin)) {
        cout << "Incorrect PIN. Access denied.\n";
        return 0;
    }

    cout << "Login successful!\n";

    do {
        cout << "\n===== MENU =====\n";
        cout << "1. Check Balance\n";
        cout << "2. Withdraw\n";
        cout << "3. Deposit\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                users[index].showBalance();
                break;

            case 2:
                cout << "Enter amount: ";
                cin >> amount;
                users[index].withdraw(amount);
                break;

            case 3:
                cout << "Enter amount: ";
                cin >> amount;
                users[index].deposit(amount);
                break;

            case 4:
                cout << "Thank you for using ATM.\n";
                break;

            default:
                cout << "Invalid choice.\n";
        }

    } while (choice != 4);

    return 0;
}