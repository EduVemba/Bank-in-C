#include <stdio.h>
#include <string.h>


typedef struct Account {
    char name[100];
    int ID;
    float balance;
    char accountType[100];
} Account;


#define MAX_ACCOUNTS 100
Account accounts[MAX_ACCOUNTS];
int accountCount = 0;

// Função para limpar o buffer de entrada
void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}


void createAccount() {
    if (accountCount >= MAX_ACCOUNTS) {
        printf("Não é possível criar mais contas, o limite foi alcançado.\n");
        return;
    }

    Account *account = &accounts[accountCount];

    printf("--------------------------------------\n");
    printf("Que tipo de conta deseja criar?\n");
    printf("--------------------------------------\n");
    printf("1. Conta Poupança\n2. Conta Corrente\n3. Conta Fixa\n");

    int accountType;
    while (scanf("%d", &accountType) != 1 || accountType < 1 || accountType > 3) {
        printf("Tipo de conta inválido. Tente novamente.\n");
        clearInputBuffer(); 
    }
    clearInputBuffer(); 

    switch (accountType) {
        case 1:
            strcpy(account->accountType, "Conta Poupança");
            printf("--------------------------------------\n");
            printf("Você está criando uma Conta Poupança\n");
            printf("--------------------------------------\n");
            break;
        case 2:
            strcpy(account->accountType, "Conta Corrente");
            printf("--------------------------------------\n");
            printf("Você está criando uma Conta Corrente\n");
            printf("--------------------------------------\n");
            break;
        case 3:
            strcpy(account->accountType, "Conta Fixa");
            printf("--------------------------------------\n");
            printf("Você está criando uma Conta Fixa\n");
            printf("--------------------------------------\n");
            break;
    }

    printf("Digite o nome do titular da conta: ");
    scanf("%99s", account->name);
    clearInputBuffer(); 
    printf("Digite o ID da conta: ");
    while (scanf("%d", &account->ID) != 1) {
        printf("ID inválido. Tente novamente.\n");
        clearInputBuffer(); 
    }
    clearInputBuffer(); 

    account->balance = 0.0;
    accountCount++;
    printf("Conta criada com sucesso!\n");
}


void bubbleSortAccounts() {
    for (int i = 0; i < accountCount - 1; i++) {
        for (int j = 0; j < accountCount - i - 1; j++) {
            if (accounts[j].balance < accounts[j + 1].balance) {
                Account temp = accounts[j];
                accounts[j] = accounts[j + 1];
                accounts[j + 1] = temp;
            }
        }
    }
}


void displayHighestBalanceAccounts() {
    if (accountCount == 0) {
        printf("Nenhuma conta criada.\n");
        return;
    }

    bubbleSortAccounts();

    printf("--------------------------------------\n");
    printf("Contas em ordem decrescente de saldo:\n");
    printf("--------------------------------------\n");

    for (int i = 0; i < accountCount; i++) {
        printf("Conta %d:\n", i + 1);
        printf("Nome: %s\n", accounts[i].name);
        printf("ID: %d\n", accounts[i].ID);
        printf("Saldo: %.2f\n", accounts[i].balance);
        printf("Tipo de Conta: %s\n", accounts[i].accountType);
        printf("--------------------------------------\n");
    }
}


void withdraw(Account* account) {
    float amount;
    printf("--------------------------------------\n");
    printf("Quanto dinheiro deseja sacar?\n");
    printf("--------------------------------------\n");

    while (scanf("%f", &amount) != 1 || amount < 0) {
        printf("Quantia inválida. Tente novamente.\n");
        clearInputBuffer(); 
    }
    clearInputBuffer(); 

    if (account->balance >= amount) {
        account->balance -= amount;
        printf("Saque bem-sucedido. Saldo atual: %.2f\n", account->balance);
    } else {
        printf("Saldo insuficiente\n");
    }
}


void deposit(Account* account) {
    float amount;
    printf("--------------------------------------\n");
    printf("Quanto dinheiro deseja depositar?\n");
    printf("--------------------------------------\n");

    while (scanf("%f", &amount) != 1 || amount < 0) {
        printf("Quantia inválida. Tente novamente.\n");
        clearInputBuffer(); 
    }
    clearInputBuffer(); 

    account->balance += amount;
    printf("Depósito bem-sucedido. Saldo atual: %.2f\n", account->balance);
}


void getAccountType(Account* account, char* type) {
    strcpy(type, account->accountType);
}

Account* findAccountByID(int ID) {
    for (int i = 0; i < accountCount; i++) {
        if (accounts[i].ID == ID) {
            return &accounts[i];
        }
    }
    return NULL;
}


void statusAccount(Account* account) {
    char type[100];
    getAccountType(account, type);

    printf("--------------------------------------\n");
    printf("Status da Conta:\n");
    printf("--------------------------------------\n");
    printf("Tipo de Conta: %s\n", type);
    printf("Nome: %s\n", account->name);
    printf("ID: %d\n", account->ID);
    printf("Saldo: %.2f\n", account->balance);
    printf("--------------------------------------\n");
}

int main() {
    int option;
    do {
        printf("1. Criar uma nova conta\n");
        printf("2. Exibir todas as contas em ordem decrescente de saldo\n");
        printf("3. Sacar\n");
        printf("4. Depositar\n");
        printf("5. Exibir status da conta\n");
        printf("6. Sair\n");
        printf("Escolha uma opção: ");
        while (scanf("%d", &option) != 1 || option < 1 || option > 6) {
            printf("Opção inválida. Tente novamente.\n");
            clearInputBuffer(); 
        }
        clearInputBuffer(); 

        int accountID;
        Account* account;

        switch (option) {
            case 1:
                createAccount();
                break;
            case 2:
                displayHighestBalanceAccounts();
                break;
            case 3:
                printf("Digite o ID da conta para saque: ");
                while (scanf("%d", &accountID) != 1) {
                    printf("ID inválido. Tente novamente.\n");
                    clearInputBuffer(); 
                }
                clearInputBuffer(); 
                account = findAccountByID(accountID);
                if (account != NULL) {
                    withdraw(account);
                } else {
                    printf("Conta não encontrada\n");
                }
                break;
            case 4:
                printf("Digite o ID da conta para depósito: ");
                while (scanf("%d", &accountID) != 1) {
                    printf("ID inválido. Tente novamente.\n");
                    clearInputBuffer(); 
                }
                clearInputBuffer(); 
                account = findAccountByID(accountID);
                if (account != NULL) {
                    deposit(account);
                } else {
                    printf("Conta não encontrada\n");
                }
                break;
            case 5:
                printf("Digite o ID da conta para exibir o status: ");
                while (scanf("%d", &accountID) != 1) {
                    printf("ID inválido. Tente novamente.\n");
                    clearInputBuffer(); 
                }
                clearInputBuffer(); 
                account = findAccountByID(accountID);
                if (account != NULL) {
                    statusAccount(account);
                } else {
                    printf("Conta não encontrada\n");
                }
                break;
            case 6:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    } while (option != 6);

    return 0;
}