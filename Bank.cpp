/* Design a class BankAccount with private balance.
a. Use constructors (default + parameterized)
b. Provide deposit/withdraw functions
c. Ensure balance cannot go negative */

#include<iostream>
using namespace std;

class BankAccount {
private:
	int balance;
public:
	BankAccount() {
		balance = 0;
	}
	BankAccount(int b) {
		balance = b;
	}
	int deposit(int amount) {
		balance += amount;
		return balance;
	}
	void withdraw(int amount) {
		if (balance < amount)
			cout << "Your Balance is not enough!!!" << endl;
		else
			cout << "Your balance is now: " << balance - amount;
	}
};

int main() {
	int amt, choice;
	BankAccount b;

	do {
		cout << "\nCHOOSE:" << endl;
		cout << "1. Deposit" << endl;
		cout << "2. Withdraw" << endl;
		cout << "3. Exit \n" << endl;
		cout << "Enter choice : ";
		cin >> choice;

		switch (choice) {
		case 1:
			cout << "Enter amount: ";
			cin >> amt;
			cout << "Your balance is now: " << b.deposit(amt) << endl;  break;
		case 2:
			cout << "Enter amount: ";
			cin >> amt;
			b.withdraw(amt);  break;
		case 3:
			cout << "---EXIT---" << endl;   break;
		default:
			cout << "Invalid choice!" << endl;    break;
		}
	} while (choice != 3);

	return 0;
}