#include<iostream>
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include<iostream>
using namespace std;

class customer
{
public:

    int adharNumber;
    string name;
    string address;
    int pincode;
    string dateofbirth;
    string phone;

    customer(int an, string n, string add, int pin,string dob, string ph)
    {
        adharNumber=an;
        name=n;
        address=add;
        pincode=pin;
        dateofbirth=dob;
        phone=ph;
    }


    bool newCustomer(customer c)
    {
        int an=c.adharNumber;
        string name=c.name;
        string address=c.address;
        string dob=c.dateofbirth;
        int pin=c.pincode;
        string phone=c.phone;

        if(dob.size()!=10 || dob[2]!='/' || dob[5]!='/'){
            printf("DD/MM/YYYY(format is invalid)\n");
            system("pause");
            return false;
        }

        if(phone.size()!=10){
                printf("phone number should be 10 digits\n");
                system("pause");
                return false;
        }

        int i;
        i=0;
        while(i<phone.size()){
            if(phone[i]<'0' || phone[i]>'9'){
                printf("phone number should contain only numbers\n");
                system("pause");
                return false;
            }
            i++;
        }

        i=0;
        while(i<name.size()){
            if(!isalpha(name[i])){
                printf("name should contain only alphabets\n");
                system("pause");
                return false;
            }
            i++;
        }

        return true;

    }

};

