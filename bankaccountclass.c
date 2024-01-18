#include <stdio.h>
#include <string.h>

struct BankAccount {
    char account_holder_name[50];
    int account_number;
    double balance;
};

void initBankAccount(struct BankAccount *account, const char *account_holder_name, int account_number, double balance) {
    strcpy(account->account_holder_name, account_holder_name);
    account->account_number = account_number;
    account->balance = balance;
}

void deposit(struct BankAccount *account, double amount) {
    account->balance += amount;
    printf("%.2lf rupees has been credited in your account.\n", amount);
}

void withdraw(struct BankAccount *account, double amount) {
    if (amount > account->balance) {
        printf("!!!!Insufficient funds.!!!!\n");
    } else {
        account->balance -= amount;
        printf("%.2lf rupees has been debited from your account.\n", amount);
    }
}

void get_balance(struct BankAccount *account) {
    printf("Current balance is %.2lf rupees\n", account->balance);
}

void get_customer_details(struct BankAccount *account) {
    printf("Account holder Name: %s\n", account->account_holder_name);
    printf("Account Number: %d\n", account->account_number);
}

int main() {
    struct BankAccount customer_1, customer_2, customer_3;

    initBankAccount(&customer_1, "Hari", 45456790, 5000);
    initBankAccount(&customer_2, "Ram", 12345678, 3000);
    initBankAccount(&customer_3, "Sai", 24689135, 2506);

    printf("-----Account Holder Details-----\n");
    get_customer_details(&customer_1);
    get_customer_details(&customer_2);
    get_customer_details(&customer_3);

    printf("---Deposit and Withdrawl---\n");
    deposit(&customer_2, 15000);
    withdraw(&customer_2, 5000);
    get_balance(&customer_2);

    withdraw(&customer_3, 4000);
    deposit(&customer_3, 3500);
    get_balance(&customer_3);

    return 0;
}
