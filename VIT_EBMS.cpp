#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<ctype.h>
#include"connection.h"
#include"audit.h"
#include"bill.h"
#include"complaint.h"
#include"employee.h"
using namespace std;


vector<employee> employees;


int login(int emp_id,string emp_password) {


	for(int i=0;i<employees.size();i++)
    {
        if((employees[i].e_id==emp_id) &&
           compare(employees[i].e_password,emp_password))
        {
            system("cls");
			printf("LOGIN SUCCESSFUL\n");
			cout<<"WELCOME BACK "<<employees[i].e_name<<", \n";
			return 1;
        }
    }

	return 0;

}

void initialise_employees()
{

    employees.emplace_back(employee(1142,"varun123","varun","software","08/10/1998","9376373373","male","135001"));
    employees.emplace_back(employee(1112,"@sanskar1","sanskar","operations","28/02/1999","383823373","male","156336"));
    employees.emplace_back(employee(3931,"anish_","anish","hardware","01/11/2000","9919339391","male","334224"));
    employees.emplace_back(employee(2210,"priya2210","priya","software","08/11/1998","9376993773","female","311345"));
    employees.emplace_back(employee(5382,"rishabh4","rishabh","hardware","14/07/1999","7077553345","male","123456"));
    employees.emplace_back(employee(6638,"sai382","sai","head","23/03/2001","9376373333","male","919332"));
    employees.emplace_back(employee(1142,"kohli123","virat","software","08/10/1999","7379373373","male","156336"));

}

void viewEmployee(){
        int access_key;
        printf("ENTER THE ADMIN ACCESS KEY: ");
        cin>>access_key;

        if(access_key!=ADMIN_ACCESS_KEY){
            printf("WRONG ACCESS KEY, ACCESS DENIED!!!\n");
            system("pause");
        }
        else
        {
            cout<<"\t ID       PSWD       NAME       DEPART      DOB      PHONE      GENDER      Area Pincode\n";

            for(int i=0;i<employees.size();i++)
            {
                cout<<"\t"<<employees[i].e_id<<"    "<<employees[i].e_password<<"   "<<
                employees[i].e_name<<"    "<<employees[i].e_department<<"   "<<
                employees[i].e_dob<<"    "<<employees[i].e_phone<<"    "<<employees[i].gender<<"    "<<
                employees[i].working_area<<" \n";
            }

            system("pause");
        }
}


void displayMenu(string str){
    system("cls");

    int choice;
    while(true) {
        system("cls");
        system("title VIT ELECTRICITY BOARD MANAGEMENT SYSTEM");
        upperPrint();

        cout<<"\t\tWelcome back, "<<str<<"\n\n";

        printf("1.Connection Maintenance\n2.Energy Audit\n3.Billing\n4.Logout\n");
        printf("YOUR CHOICE: ");
        cin>>choice;

        switch(choice){

            case 1:
                upperPrint();
                connectionMenu();
                break;

            case 2:
                upperPrint();
                auditMenu();
                break;

            case 3:
                upperPrint();
                billMenu();
                break;

            case 4:
                return;

            default:
                printf("INVALID INPUT\n");
        }

    }
}


int main(){
	int choice;
	int emp_id;
	string emp_password,emp_name,emp_dob,emp_phone,emp_dept,emp_gender;
	char comp_type[100000],comp_msg[100000];
	initialise_employees();


	while(true) {
        system("cls");
        system("title VIT ELECTRICITY BOARD MANAGEMENT SYSTEM");
        upperPrint();
        printf("1.Employee Login\n2.Add Employee\n3.View Employee\
               \n4.Complaint\n5.Pay Bills\n6.Exit\n\nCHOICE: ");

        cin>>choice;

	switch(choice) {
		case 1:
        {
			system("cls");
			system("title EMPLOYEE LOGIN");
			upperPrint();
			printf("EMPLOYEE ID: ");
			cin>>emp_id;
			printf("EMPLOYEE PASSWORD: ");
			cin>>emp_password;

			if(login(emp_id,emp_password)){
                    string name;
                    for(auto it:employees)
                    {
                        if(it.e_id==emp_id && it.e_password==emp_password)
                        {
                            name=it.e_name;
                            break;
                        }
                    }
				displayMenu(name);
			}
			else{
                printf("LOGIN FAILED TRY AGAIN\n");
                system("pause");
			}
			break;
        }
		case 2:
		    {

			system("title EMPLOYEE REGISTRATION");

			cout<<"EMPLOYEE ID: ";
			cin>>emp_id;

			printf("\nEMPLOYEE NAME: ");
			cin>>emp_name;

                while(1){
                    printf("\nEMPLOYEE PASSWORD: ");
                    cin>>emp_password;
                    if(((emp_password.size()))>6)
                        break;
                    else
                        printf("enter more than 6 characters\n");
                }

                printf("\nEMPLOYEE DEPARTMENT: ");
                cin>>emp_dept;
                printf("\nEMPLOYEE DATE OF BIRTH: ");
                cin>>emp_dob;
                printf("\nEMPLOYEE PHONE NUMBER: ");
                cin>>emp_phone;
                cout<<"\nEMPLOYEE GENDER [ male / female ]: ";
                cin>>emp_gender;

                employee e;

                e.e_id=emp_id;
                e.e_password=emp_password;
                e.e_name=emp_name;
                e.e_department=emp_dept;
                e.e_dob=emp_dob;
                e.e_phone=emp_phone;
                e.gender=emp_gender;
                employee *obj;

                if(obj->newEmployee(e))
                {
                    employees.emplace_back(e);
                    cout<<"\nEmployee was added successfully !!";

                }

                else
                {
                    cout<<"PLEASE TRY AGAIN,INVALID DETAILS\n";
                }
                system("pause");

                break;
		    }
            case 3:{
                system("title EMPLOYEE DETAILS");
                viewEmployee();
                break;
            }
            case 4:{
                system("cls");
                system("title COMPLAINTS");
                upperPrint();
                printf("\t\t\tCOMPLAINTS SECTION\n");

                printf("COMPLAINT TYPE (HOME OR REGION) :");
                cin>>comp_type;
                printf("COMPLAINT : ");
                cin>>comp_msg;
                complaints(comp_type,comp_msg);
                break;
            }
            case 5:{
                system("cls");
                system("title BILLS PAYMENT");
                upperPrint();
                printf("\t\t\tBILLS PAYMENT SECTION\n");
                billMenu();
                break;
            }
            case 6:
                exit(0);
            default:
                printf("Invalid input\n");
                system("pause");

        }
	}
	return 0;
}
