#include<iostream>
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

using namespace std;

class complaint
{
    string type;
    string message;
    int aadhar_number;
    string pincode;

    complaint(string ty, string msg, int an,string pn)
    {
        type=ty;
        message=msg;
        aadhar_number=an;
        pincode=pn;
    }


};



void report(char* comp_type,char* comp_msg,int locality){
	printf("The employee has been informed about the issue.\n\
        Problem will be rectified shortly.\n");
	system("pause");
}

void alertfunction(char* comp_type,char* comp_msg,char* locality){
	int aadhar_num,sno=1;
	char name[20],address[30],pincode[20],dob[10],phone[10];

	FILE *customer =fopen("connection.txt","r");


    	printf("MESSAGE: %s\n",comp_msg);
    	printf("Sending messages to the required members via SMS: \n");


        while(fscanf(customer,"%d %s %s %s %s %s",&aadhar_num,name,dob,phone,address,pincode)!=EOF)
        {
	        if(strcmp(pincode,locality)){
	            printf("%d.%s - %s\n",sno,name,phone);
	            sno++;
		    }
   		 }

   		 printf("MESSAGE SEND SUCCESSFULLY, our employees will reach out to you shortly\n");

        system("pause");
        fclose(customer);

}

void complaints(char* comp_type,char* comp_msg)
{

	if(comp_type=="HOME" || comp_type=="home")
    {
		int aadhar_number;
		printf("Enter Aadhar Card Number\n");
		cin>>aadhar_number;

		FILE *complaint=fopen("complaint.txt","a+");
		int aadhar_num,flag=-1;

		char name[20],address[30],pincode[20],dob[10],phone[10];
	    FILE *ptr=fopen("connection.txt","r");
	    if(ptr==NULL){
	        return ;
	    }
	    else{
	        while(fscanf(ptr,"%d %s %s %s %s %s",&aadhar_num,name,dob,phone,address,pincode)!=EOF){
                if(aadhar_number==aadhar_num){
                    flag=1;
                }
	        }
	    }
	    fclose(ptr);

    	if(flag==-1){
            printf("Invalid aadhar number try again\n");
            system("pause");
            return;
		}

		fprintf(complaint,"\n%d %s %s",aadhar_number,comp_type,comp_msg);
		report(comp_type,comp_msg,aadhar_number);
		fclose(complaint);
	}

	else if(comp_type,"REGION" || comp_type=="region"){
		char pincode[6];
		printf("Enter PINCODE\n");
		scanf("%s",pincode);

		FILE *alert=fopen("alert.txt","a");
		fprintf(alert,"\n%s %s %s",pincode,comp_type,comp_msg);
		alertfunction(comp_type,comp_msg,pincode);

		fclose(alert);
	}
	else{
		printf("Invalid Input\n");
	}
}
