#include<iostream>
using namespace std;
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include<time.h>

class bill
{
public:

    int serviceCharges;
    int baseCharges;
    int additionalCharges;
    int aadharNumber;

    bill(int sc, int bc, int ac, int an)
    {
        serviceCharges=sc;
        baseCharges=bc;
        additionalCharges=ac;
        aadharNumber=an;
    }

};


void otp(){
	srand(time(0));
	int otp_no = rand() * 100 + 1 , n;
	otp_no = otp_no % 999998 + 1;
	printf("OTP is sent to the mobile\n");
	FILE *ptr=fopen("otp.txt","w");
    if(ptr==NULL){
        return ;
    }
    else{
        fprintf(ptr,"%d",otp_no);
    }

    fclose(ptr);
    printf("ENTER THE OTP OR -1 to cancel payment: ");
    scanf("%d",&n);
    while(n!=otp_no){
    	printf("INVALID OTP\n");
    	printf("ENTER THE CORRECT OTP: ");
    	scanf("%d",&n);
    	if(n==-1)
            return;
	}
	printf("Your Payment was Successful... \n");
    remove("otp.txt");

}

void paymentGateway(){
	system("title PAYMENT GATEWAY");
	upperPrint();
	int type;
	char payment,debit[16],credit[16],upi[16],cvv[3];

	while(1){
        system("cls");
        upperPrint();
        printf("Choose payment method:\n1.Debit Card\n2.Credit Card\
               \n3.NETBANKING \n4.Offline\n5.Cancel Payment\nCHOICE: ");
        scanf("%d",&type);
        switch(type){
            case 1:
                printf("DEBIT CARD NUMBER (16 DIGITS) :");
                scanf("%s",debit);
                printf("CVV :");
                scanf("%s",cvv);
                if(strlen(cvv)!=3 || strlen(debit)!=16){
                    printf("Invalid details\n");
                    system("pause");
                    break;
                }
                otp();
                return;
            case 2:
                printf("CREDIT CARD NUMBER (16 DIGITS) :");
                scanf("%s",credit);
                printf("CVV :");
                scanf("%s",cvv);
                if(strlen(cvv)!=3 || strlen(credit)!=16){
                    printf("Invalid details\n");
                    system("pause");
                    break;
                }
                otp();
                return;
            case 3:
                char upii[10],cvvv[3];
                printf("NETBANKING REFERNCE NUMBER (10 DIGITS) :");
                scanf("%s",upii);
                printf("PIN (3 DIGITS):");
                scanf("%s",cvvv);
                if(strlen(cvvv)!=3 || strlen(upii)!=10){
                    printf("Invalid details\n");
                    system("pause");
                    break;
                }
                otp();
                return;
            case 4:
                cout<<"You will have to reach out office for offline payment\n";
                system("pause");
                break;
            case 5:
                return;
            default:
                printf("Invalid Input.");
                system("pause");
        }

	}
}

int metering(int aadharNumber){
	system("title METERING");
	int f_units;
	char f_aadhar_number[10],f_pin[6];


	for(int i=0;i<audits.size();i++)
    {
        //cout<<audits[i].aadhar_number<<"--";
        if(audits[i].aadhar_number==aadharNumber)
        {
            return audits[i].units;
			system("pause");
        }

    }

    return 0;
}

void billing(int aadharNumber){
	system("title BILLING PROCESS");
	int unit=0;
	float cost=0;
	int f_units;
	string f_pin;

	for(int i=0;i<audits.size();i++)
    {

        if(audits[i].aadhar_number==aadharNumber)
        {
            unit=audits[i].units;
			break;

        }

    }

    if(unit==0){
            printf("INVALID AADHAR CARD NUMBER!!\n");
            system("pause");
            return;
    }

	if (unit < 150)
		cost = (float)unit * 2.55;

	else if (unit < 250 )
		cost = (float)unit * 4.88;

	else
		cost = (float)unit * 5;

	printf("The cost is %.2f\n",cost);
	system("pause");
	printf("\nRedirecting to payment gateway...\n");
	system("pause");
	paymentGateway();
	system("pause");

}


void billMenu()
{
	int choice,units;
	int aadhar_number;
	initialise_audit();
	while(1)
	{
		system("cls");
		system("title BILLING");
		upperPrint();

		printf("\t\tBILL MAINTENANCE\n");
		printf("1.Metering\n2.Billing\n3.Back\n");
		printf("Enter Choice : ");
		scanf("%d",&choice);
		switch(choice)
		{

			case 1:
				printf("Enter your Aadhar Card Number : ");
				cin>>aadhar_number;
				units=metering(aadhar_number);
				if(units==0)
				{
					printf("INVALID AADHAR CARD NUMBER\n");
					system("pause");
				}
				else
				{
					printf("The Aadhar Card Number %d used %d units\n",aadhar_number,units);
					system("pause");
				}
				break;
			case 2:
				printf("Enter Aadhar Card Number : ");
				cin>>aadhar_number;
				billing(aadhar_number);
				return;
			case 3:
				return;
			default:
				printf("INVALID INPUT\n");
				system("pause");
		}

	}
}
