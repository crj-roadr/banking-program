#include <stdio.h>

void prompt_user();
void check_balance(float balance);
float deposit();
float withdraw(float balance);

int main() {
    float currentBalance = 0.0f;
    int choice = 0;

    printf("*** BANKING PROGRAM ***\n\n");

    do
    {
        prompt_user();
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                check_balance(currentBalance);
                break;
            case 2:
                currentBalance += deposit();
                break;
            case 3:
                currentBalance = withdraw(currentBalance);
                break;
            case 4:
            printf("Thank you! Come again!\n");
                break;
            
            default:
                break;
        }
    } while (choice != 4);


    return 0;
}

void prompt_user() {
    printf("Select an option:\n\n");

    printf("1. Check Balance\n");
    printf("2. Deposit Money\n");
    printf("3. Withdraw Money\n");
    printf("4. Exit\n\n");

    printf("Enter your choice: ");
}

void check_balance(float balance) {
    printf("You current balance is: $%.2f\n\n", balance);
}

float deposit() {
    float deposited_amount = 0.0f;
    printf("Enter amount to deposit: ");
    scanf("%f", &deposited_amount);
    
    printf("You have deposited $%.2f\n\n", deposited_amount);

    return deposited_amount;
}

float withdraw(float balance) {
    float withdrawAmount = 0.0f;
    printf("Enter amount to withdraw: ");
    scanf("%f", &withdrawAmount);

    if (withdrawAmount > balance) printf("Insufficient funds! Your balance is $%.2f\n\n", balance);
    else {
        balance -= withdrawAmount;
        printf("Successfully withdrew $%.2f\n\n", balance);
    }

    return balance;
}