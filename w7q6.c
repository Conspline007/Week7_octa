#include <stdio.h>
#include <string.h>

int place_holder;

struct customer 
{
	long long int acc_no; 
	char name[51]; 
	float acc_bal;
}bank[10];

void storage();

int transaction(long long int acc_no, int req_type, int amt)
{
	int flag = 0, i;  // Initialize flag to 0
	
	for (i = 0; i < 10; i++)
	{
		if (acc_no == bank[i].acc_no)
		{
			flag = 1; 
			place_holder = i;  // Correct logic for setting flag and place_holder
			break;  // Exit the loop once the account is found
		}
	}
	
	if (flag == 0)
	{
		printf("There is no existing account with the given account number in our bank\n");
		return 0;
	}
	
	if (req_type == 0)
	{
		bank[place_holder].acc_bal += amt;  // Deposit logic is correct
		return 1;
	}
	else if (req_type == 1)
	{
		if (bank[place_holder].acc_bal < amt)
		{
			printf("You do not have the required balance!\n");  // Correct insufficient balance logic
			return 0;
		}
		else
		{
			bank[place_holder].acc_bal -= amt;  // Withdrawal logic is correct
			return 1;
		}
	}
	return 0;  // Added return for completeness
}

int main()
{
	storage();
	
	int i; 
	char test;
	long long int tr_acc_no;
	int tr_req_type;
	int tr_amt;  // Changed to int to match the transaction function
	
	while (1)
	{
		printf("Enter your Account Number: "); 
		scanf("%lld", &tr_acc_no);
	    printf("Do you want to make a deposit (0) or a withdrawal (1): "); 
	    scanf("%d", &tr_req_type);
	    printf("Enter the amount: "); 
	    scanf("%d", &tr_amt);  // Changed to int to match the transaction function
	    
		int x = transaction(tr_acc_no, tr_req_type, tr_amt);
		
		if (x == 1)
			printf("Your transaction is successfully completed.\nYour current balance is: %.2f\n", bank[place_holder].acc_bal);
		
		printf("Do you want to make another transaction? (y/n): ");
		scanf(" %c", &test); 
		
		if (test == 'n' || test == 'N')
		{
			printf("Thank you for your time at our bank.\n");
			break;
		}
	}
	
	return 0;
}

void storage()
{
	bank[0].acc_no = 1600000000019877;
	strcpy(bank[0].name, "Vihaan");
	bank[0].acc_bal = 1999;
	
	bank[1].acc_no = 1600000000020432;
	strcpy(bank[1].name, "Dhruv");
	bank[1].acc_bal = 19999;
	
	bank[2].acc_no = 1600000000040402;
	strcpy(bank[2].name, "Kavya");
	bank[2].acc_bal = 21000;
	
	bank[3].acc_no = 1600000000020222;
	strcpy(bank[3].name, "Anastassakis");
	bank[3].acc_bal = 4200000;
	
	bank[4].acc_no = 1600000000030419;
	strcpy(bank[4].name, "Papasifakis");
	bank[4].acc_bal = 23;
}
