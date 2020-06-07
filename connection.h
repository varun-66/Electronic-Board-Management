#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<vector>
#include<string.h>
#include<conio.h>
#include<ctype.h>
#include"customer.h"
using namespace std;



char stars()
{
    for(int i=0;i<80;i++)
        cout<<'*';

}

void box(int x, int y)
{
	for(int i=0;i<y;i++)
	cout<<(char)x;
}

void initialise_customer(vector<customer> &customers)
{
    customers.emplace_back(customer(1373838337,"Varun","haryana",135001,"08/10/1998","9376373373"));
    customers.emplace_back(customer(6373236737,"jayesh","jharkhand",535041,"28/01/1999","9884736663"));

}

void upperPrint()
{
    cout<<endl<<endl<<endl;
     box(178,20);
     cout<<"  W E L C O M E   T O   V I T - E B M S ";
     box(178,20);
     cout<<endl<<endl;
     cout<<stars()<<endl<<endl;

}


int getcid(){
	int c_id;
	FILE *temp1 = fopen("cus.txt","r");
	fscanf(temp1,"%d",&c_id);
	fclose(temp1);
	printf("CUSTOMER ID IS %d\n",c_id);
	return c_id;
}

void inccid(int value){
	FILE *temp2 = fopen("cus.txt","w");
	fprintf(temp2,"%d",value);
	fclose(temp2);
}



int addConnection(char *name,char *address,char *pincode,char *dob,char *phone){
	int aadhar_number = getcid();
    FILE *ptr=fopen("connection.txt","a");
    if(ptr==NULL)
    {
        fclose(ptr);
        return 0;
    }
    else
    {
    	aadhar_number++;
    	inccid(aadhar_number);
        fprintf(ptr,"%d %s %s %s %s %s\n",aadhar_number,name,dob,phone,address,pincode);
    }
    fclose(ptr);
    return 1;

}

int disconnection(int number,char *reason){
    int aadhar_num;
	char name[20],address[30],pincode[20],dob[10],phone[10];

    FILE *ptr=fopen("connection.txt","r");
	FILE *temp=fopen("temp.txt","w");
    if(ptr==NULL){
        return 0;
    }
    else
    {

        printf("The connection of %d will be disconnected shortly\nReason of disconnection : %s\n",aadhar_num,reason);

		fclose(ptr);
        fclose(temp);
        if(remove("connection.txt"))
            printf("deleted\n");
        rename("temp.txt","connection.txt");
   		system("pause");
		return 1;
    }

    return 0;
}

int displayCustomer(int number, vector<customer> &customers){
	int aadhar_num,flag=-1;
	char name[20],address[30],pincode[20],dob[10],phone[10];
    FILE *ptr=fopen("connection.txt","r");

    if(ptr==NULL){
        return 0;
    }
    else{
            for(int i=0;i<customers.size();i++)
            {
                if(customers[i].adharNumber==number)
                {
                    flag=1;
                    cout<<customers[i].adharNumber<<"  "<<
                           customers[i].name<<"  "<<
                           customers[i].address<<"  "<<
                           customers[i].pincode<<"  "<<
                           customers[i].dateofbirth<<"  "<<
                           customers[i].phone<<endl;
                           break;
                }
            }

    }
    fclose(ptr);
    if(flag==-1)
        printf("Invalid Aadhar number try again\n");
    system("pause");
    return 1;
}


void connectionMenu(){
    system("cls");
    upperPrint();
    vector<customer> customers;
    initialise_customer(customers);
    int choice,aadhar_no;
    char reason[100];
    while(1){
        system("cls");
        upperPrint();
        system("title VIT CONNECTION MAINTENANCE");

        printf("1.New Connection\n2.Disconnection\n3.Customer Details\n4.Go Back\n");
        printf("CHOICE: ");
        scanf("%d",&choice);
        char name[20],address[20],pincode[6],dob[10],phone[10];
        switch(choice){
            case 1:
                system("title CONNECTION REGISTRATION");

                printf("CUSTOMER NAME: ");
                scanf("%s",name);
                printf("CUSTOMER ADDRESS: ");
                scanf("%s",address);
                printf("CUSTOMER PINCODE: ");
                scanf("%s",pincode);
                printf("CUSTOMER DATE OF BIRTH: ");
                scanf("%s",dob);
                printf("CUSTOMER PHONE NUMBER: ");
                scanf("%s",phone);
                if(addConnection(name,address,pincode,dob,phone)){
                    printf("CONNECTION REGISTERED\n");
                    system("pause");
                }
                else{
                    printf("PLEASE TRY AGAIN\n");
                }

                break;
            case 2:
                system("title DISCONNECTION");
                printf("AADHAR NUMBER: ");
                scanf("%d",&aadhar_no);
                printf("REASON: ");
                scanf(" %[^\n]",reason);
                if(!disconnection(aadhar_no,reason)){
                    printf("FILE NOT FOUND\n");
                }
                break;
            case 3:
                system("title CONNECTION QUERY");
                printf("CUSTOMER AADHAR NUMBER: ");
                scanf("%d",&aadhar_no);
                if(!displayCustomer(aadhar_no,customers)){
                    printf("INVALID CUSTOMER NUMBER\n");
                }
                break;
            case 4:
                return;
            default:
                printf("INVALID INPUT\n");
        }
    }
    system("pause");
}
