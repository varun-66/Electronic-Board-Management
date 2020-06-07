#include<iostream>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<ctype.h>


class employee
{
public:

    int e_id;
    string e_password;
    string e_name;
    string e_department;
    string e_dob;
    string e_phone;
    string gender;
    string working_area;

    employee()
    {
    }

    employee(int eid, string epass, string en, string ed, string edob, string eph,string g,string wa)
    {
        e_id=eid;
        e_password=epass;
        e_name=en;
        e_department=ed;
        e_dob=edob;
        e_phone=eph;
        gender=g;
        working_area=wa;
    }

    bool newEmployee(employee e)
    {
        int id=e.e_id;
        string password=e.e_password;
        string name=e.e_name;
        string department=e.e_department;
        string dob=e.e_dob;
        string phone=e.e_phone;
        string gen=e.gender;
        string wA=e.working_area;

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


        i=0;
        while(i<department.size()){
            if(!isalpha(department[i])){
                printf("department should contain only alphabets\n");
                system("pause");
                return 0;
            }
            i++;
        }

        i=0;
        while(i<wA.size()){
            if(!isdigit(wA[i])){
                printf("Pincode should contain only digits\n");
                system("pause");
                return 0;
            }
            i++;
        }

        return true;

    }


};

