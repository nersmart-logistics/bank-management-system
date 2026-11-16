#include <stdio.h>
#include <string.h>
struct amount(){
  int accountNo;
  char name[];
  float balance;
};
int findAccount(FILE *fp, int accNo, struct Account *acc,long *position){
  rewind(fp);
    while (fread(acc, sizeof(struct Account), 1, fp) == 1){
long pos=ftell(fp) - sizeof(struct Account);
if (acc->accountNo == accNo){
*position = pos;
    return 1;
}}}
void createAccount()
{
    FILE *fp = fopen("accounts.dat", "ab+");
    struct Account acc;
    struct Account temp;
    long pos;
if (fp == NULL){
printf("File opening error!\n");
return 0;}
printf("\nEnter Account Number: ");
scanf("%d", &acc.accountNo);
if (findAccount(fp, acc.accountNo, &temp, &pos)){
printf("Account already exists!\n");
        fclose(fp);
        return;}
printf("Enter Customer Name: ");
scanf(" %49[^\n]", acc.name);
printf("Enter Initial Balance: ");
scanf("%f", &acc.balance);
if (acc.balance < 0){
printf("Invalid balance!\n");
fclose(fp);
return;}
fseek(fp, 0, SEEK_END);
fwrite(&acc, sizeof(struct Account), 1, fp);
printf("\nAccount created successfully!\n");
fclose(fp);
void depositMoney()
{
    FILE *fp = fopen("accounts.dat", "rb+");
    struct Account acc;
    int accNo;
    float amount;
    long pos;
if (fp ==NULL){
printf("No accounts found!\n");
return;}
printf("\nEnter Account Number: ");
scanf("%d", &accNo);
if (findAccount(fp, accNo, &acc, &pos)){
printf("Customer: %s\n", acc.name);
printf("Enter Deposit Amount: ");
scanf("%f", &amount);
if (amount <= 0){
printf("Invalid amount!\n");}
else{
acc.balance += amount;}
            fseek(fp, pos, SEEK_SET);
            fwrite(&acc, sizeof(struct Account), 1, fp);
            printf("Money deposited successfully!\n");
            printf("New Balance: %.2f\n", acc.balance);}}
else{
printf("Account not found!\n");}
fclose(fp);}
void withdrawMoney(){
    FILE *fp = fopen("accounts.dat", "rb+");
    struct Account acc;
    int accNo;
    float amount;
    long pos:
if (fp == NULL){
printf("No accounts found!\n");
return;}
printf("\nEnter Account Number: ");
scanf("%d", &accNo);
if (findAccount(fp, accNo, &acc, &pos)){
        printf("Customer: %s\n", acc.name);
        printf("Enter Withdrawal Amount: ");
        scanf("%f", &amount);
if (amount <= 0){
            printf("Invalid amount!\n");}
        else if (amount > acc.balance){
            printf("Insufficient balance!\n");}
        else{
            acc.balance -= amount;
            fseek(fp, pos, SEEK_SET);
            fwrite(&acc, sizeof(struct Account), 1, fp);
            printf("Withdrawal successful!\n");
            printf("Remaining Balance: %.2f\n", acc.balance);}}
    else{
        printf("Account not found!\n");}
    fclose(fp);}
void checkBalance(){
    FILE *fp = fopen("accounts.dat", "rb");
    struct Account acc;
    int accNo;
    long pos;
    if (fp == NULL){
        printf("No accounts found!\n");
        return;}
    printf("\nEnter Account Number: ");
    scanf("%d", &accNo);
    if (findAccount(fp, accNo, &acc, &pos)){
        printf("\n----- ACCOUNT DETAILS -----\n");
        printf("Account Number: %d\n", acc.accountNo);
        printf("Customer Name: %s\n", acc.name);
        printf("Balance: %.2f\n", acc.balance);}
    else{
        printf("Account not found!\n");}
    fclose(fp);}
void displayAllAccounts(){
    FILE *fp = fopen("accounts.dat", "rb");
    struct Account acc;
    if (fp == NULL){
        printf("No accounts found!\n");
        return;}
    printf("\n========== ALL ACCOUNTS ==========\n");
    while (fread(&acc, sizeof(struct Account), 1, fp) == 1){
        printf("\nAccount Number: %d\n", acc.accountNo);
        printf("Customer Name: %s\n", acc.name);
        printf("Balance: %.2f\n", acc.balance);
        printf("----------------------------------\n");}
    fclose(fp);}
int main(){
    int choice;
    do{
        printf("\n================================\n");
        printf("       BANK MANAGEMENT SYSTEM\n");
        printf("================================\n");
        printf("1. Create New Account\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. Check Account Balance\n");
        printf("5. Display All Accounts\n");
        printf("6. Exit\n");
        printf("\nEnter Your Choice: ");
        scanf("%d", &choice);
        switch (choice){
            case 1:
                createAccount();
                break;
            case 2:
                depositMoney();
                break;
            case 3:
                withdrawMoney();
                break;
            case 4:
                checkBalance();
                break;
            case 5:
                displayAllAccounts();
                break;
            case 6:
                printf("\nThank you for using our bank system!\n");
                break;
            default:
                printf("\nInvalid choice! Try again.\n");}}
      while (choice != 6);
    return 0;}

