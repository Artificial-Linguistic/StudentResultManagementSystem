#include<iostream>
#include<stdio.h>
#include<iomanip>
#include<fstream>
#include<cstring>

using namespace std;

class Subject
{
    private:
            char sub_name[40],grade[3],sub_code[10];
            unsigned int grade_pt;
            int marks;
    public:
            void input()
            {
                cout<<"\n Enter Subject Code: ";
                fflush(stdin);
                gets(sub_code);
                cout<<" Enter Subject Name: ";
                gets(sub_name);
                in:
                    cout<<" Enter Marks: ";
                    cin>>marks;
                    if(marks<0||marks>100)
                    {
                        cout<<" MARKS HAVE TO BE BETWEEN 0 AND 100"<<endl;
                        marks=0;
                        goto in;
                    }

                    cal_grade();
            }
            void display()
            {
                cout<<"\n Subject Code: "<<sub_code<<endl;
                cout<<" Subject: "<<sub_name<<endl;
                cout<<" Marks: "<<marks<<endl;
                cout<<" Grade: "<<grade<<endl;
                cout<<" Grade Point: "<<grade_pt<<endl;
            }
            unsigned int get_grade_pt()
            {
                return grade_pt;
            }
            char *get_subcode()
            {
                return sub_code;
            }
            void mod_marks(unsigned int m)
            {
                marks=m;
                cal_grade();
            }
            void operator =(Subject &s)
            {
                unsigned int m;
                char n[30];
                char x[10];

                strcpy(x,s.sub_code);
                strcpy(s.sub_code,sub_code);
                strcpy(sub_code,x);
                m=s.marks;
                strcpy(n,s.sub_name);
                s.marks=marks;
                strcpy(s.sub_name,sub_name);
                marks=m;
                strcpy(sub_name,n);
            }
            void cal_grade();
};

class Student
{
    private:
            char stu_name[20],course[10];
            unsigned int roll_no,index=6;
            Subject subjct[6];
            float gpa=0;
    public:
            Student()
            {
                roll_no=0;
            }
            void cal_gpa()
            {
                gpa=0;

                for(int i=0;i<index;i++)
                    gpa+=subjct[i].get_grade_pt();

                gpa/=index;
            }
            unsigned int get_roll_no()
            {
                return roll_no;
            }
            char *get_name()
            {
                return stu_name;
            }
            int return_index()
            {
                return index;
            }
            void addsub();
            void modsub_marks();
            void modsub_name_marks();
            void delete_sub();
            void input(int);
            void display();

};

void Student::input(int rn)
{
    char choice;

    roll_no=rn;
    cout<<" Name: ";
    fflush(stdin);
    gets(stu_name);
    cout<<" Course: ";
    gets(course);
    cout<<"\n Enter Subjects and Marks: "<<endl;
    for(int i=0;i<index;i++)
    {
        subjct[i].input();
        fflush(stdin);

        for(int j=i-1;j>0;j--)
        {
            if(strcmp(subjct[i].get_subcode(),subjct[j].get_subcode())==0)
            {
                cout<<" SUBJECT CODE EXISTS!!!"<<endl;
                cout<<" REDO INPUT..."<<endl;
                subjct[i].input();
            }
        }

        if(i==4)
        {
            cout<<"\n Do You want to Add Another Subject(Y/N)... ";
            cin>>choice;

            if(choice=='Y'||choice=='y');
            else
            {
                index--;
                break;
            }
        }
    }

    cal_gpa();
}

void Student::display()
{
    cout<<"\n Roll Number: "<<roll_no<<endl;
    cout<<" Name: "<<stu_name<<endl;
    cout<<" Course: "<<course<<endl;
    for(int i=0;i<index;i++)
        subjct[i].display();

    cout<<"\n GPA: "<<setprecision(2)<<gpa<<"\n"<<endl;
}

void Student::addsub()
{
    if(index==6)
    {
        cout<<" TOTAL SUBJECTS CANNOT EXCEED 6..."<<endl;
        cout<<"-------------------------------------------"<<endl;
    }
    else
    {
        char choice;

        cout<<" ADDING SUBJECT...\n";
        cout<<"-------------------------------------------"<<endl;
        cout<<"\n ENTER SUBJECT DETAILS...\n";
        cout<<"-------------------------------------------"<<endl;

        index++;
        on:
        subjct[index-1].input();

        for(int i=0;i<index-1;i++)
        {
            if(strcmp(subjct[i].get_subcode(),subjct[index-1].get_subcode())==0)
            {
                cout<<" SUBJECT CODE EXISTS!!!"<<endl;
                cout<<"\n Do You Want to Continue...(Y/N): ";
                cin>>choice;
                if(choice=='Y'||choice=='y')
                {
                    cout<<" REDO INPUT..."<<endl;
                    goto on;
                }
                else
                {
                    index--;
                    cout<<"\n PROCESS TERMINATED..."<<endl;
                    cout<<"-------------------------------------------"<<endl;
                    return;
                }
            }
        }

        cout<<"\n ** SUBJECT ADDED SUCCSSFULLY **";
        cout<<"\n---------------------------------------------"<<endl;
    }
}

void Student::modsub_name_marks()
{
    char code[10],choice;
    int flag=0;

    cout<<" ENTER OLD DETAILS...\n";
    cout<<"-------------------------------------------"<<endl;
    on:
    cout<<" Enter Subject Code: ";
    fflush(stdin);
    gets(code);

    for(int i=0;i<index;i++)
    {
        if(strcmp(subjct[i].get_subcode(),code)==0)
        {
            flag=1;
            unsigned int m;

            cout<<" UPDATING NOW...\n";
            cout<<"-------------------------------------------"<<endl;
            subjct[i].input();
            cout<<"\n ** SUBJECT SUCCESSFULLY MODIFIED **"<<endl;
            cout<<"--------------------------------------"<<endl;
        }

        else
        {
            cout<<"\n PROCESS TERMINATED..."<<endl;
            cout<<"-------------------------------------------"<<endl;
            return;
        }
            break;
    }

    if(flag==0)
    {
        cout<<" SUBJECT CODE INVALID..."<<endl;
        cout<<"-------------------------------------------"<<endl;
        cout<<"\n Do You Want to Continue...(Y/N): ";
        cin>>choice;
        if(choice=='Y'||choice=='y')
            goto on;
        else
        {
            cout<<"\n PROCESS TERMINATED..."<<endl;
            cout<<"-------------------------------------------"<<endl;
            return;
        }
    }
}

void Student::modsub_marks()
{
    char code[10],choice;
    int flag=0;

    cout<<" ENTER OLD DETAILS...\n";
    cout<<"-------------------------------------------"<<endl;
    on:
    cout<<" Enter Subject Code: ";
    fflush(stdin);
    gets(code);

    for(int i=0;i<index;i++)
    {
        if(strcmp(subjct[i].get_subcode(),code)==0)
        {
            flag=1;
            unsigned int m;

            cout<<" UPDATING NOW...\n";
            cout<<"-------------------------------------------"<<endl;
            in:
                cout<<" Enter New Marks: ";
                cin>>m;

                if(m<0||m>100)
                {
                    cout<<" Marks have to between 0 and 100"<<endl;
                    m=0;
                    goto in;
                }

                subjct[i].mod_marks(m);
                cout<<"\n ** MARKS SUCCESSFULLY MODIFIED **"<<endl;
                cout<<"--------------------------------------"<<endl;
                break;
        }
    }

    if(flag==0)
    {
        cout<<" SUBJECT CODE INVALID..."<<endl;
        cout<<"-------------------------------------------"<<endl;
        cout<<"\n Do You Want to Continue...(Y/N): ";
        cin>>choice;
        if(choice=='Y'||choice=='y')
            goto on;
        else
        {
            cout<<"\n PROCESS TERMINATED..."<<endl;
            cout<<"-------------------------------------------"<<endl;
            return;
        }
    }
}

void Student::delete_sub()
{
    char code[10],choice;
    int flag=0;

    cout<<" ENTER OLD DETAILS...\n";
    cout<<"-------------------------------------------"<<endl;
    on:
    cout<<" Enter Subject Code: ";
    fflush(stdin);
    gets(code);

    for(int i=0;i<index;i++)
    {
        if(strcmp(subjct[i].get_subcode(),code)==0)
        {
            flag=1;
            cout<<" DELETING NOW...\n";
            cout<<"-------------------------------------------"<<endl;
            subjct[i]=subjct[index-1];
            index--;
            cout<<"\n ** SUBJECT DELETED SUCCESSFULLY **"<<endl;
            cout<<"--------------------------------------"<<endl;
            break;
        }
    }

    if(flag==0)
    {
        cout<<" SUBJECT CODE INVALID..."<<endl;
        cout<<"-------------------------------------------"<<endl;
        cout<<"\n Do You Want to Continue...(Y/N): ";
        cin>>choice;
        if(choice=='Y'||choice=='y')
            goto on;
        else
        {
            cout<<"\n PROCESS TERMINATED..."<<endl;
            cout<<"-------------------------------------------"<<endl;
            return;
        }
    }
}

void Subject::cal_grade()
{
    if(marks>=85)
    {
        grade_pt=10;
        strcpy(grade,"O");
    }
    else if(marks>=75&&marks<85)
    {
        grade_pt=9;
        strcpy(grade,"A+");
    }
    else if(marks>=65&&marks<75)
    {
        grade_pt=8;
        strcpy(grade,"A");
    }
    else if(marks>=55&&marks<65)
    {
        grade_pt=7;
        strcpy(grade,"B+");
    }
    else if(marks>=50&&marks<55)
    {
        grade_pt=6;
        strcpy(grade,"B");
    }
    else if(marks>=45&&marks<50)
    {
        grade_pt=5;
        strcpy(grade,"C+");
    }
    else if(marks>=40&&marks<45)
    {
        grade_pt=4;
        strcpy(grade,"C");
    }
    else if(marks>=34&&marks<40)
    {
        grade_pt=3;
        strcpy(grade,"D");
    }
    else
    {
        grade_pt=1;
        strcpy(grade,"F");
    }
}

void new_stu_profile()
{
    Student S;
    int s=sizeof(S);

    ifstream fin("Student_Results.dat",ios::binary);
    fin.seekg(-s,ios::end);
    fin.read((char*)&S,s);

    int new_roll_no=S.get_roll_no()+1;
    fin.close();

    ofstream fout("Student_Results.dat",ios::binary|ios::app);
    S.input(new_roll_no);
    fout.write((char*)&S,s);

    system("cls");
    cout<<"\n **DATA ADDED SUCCESSFULLY**\n\n";
    cout<<" STUDENT DETAILS\n";
    cout<<"-------------------------------------------";

    S.display();
    fout.close();
}

int main()
{
    char ch;

    menu1:
        system("cls");

        cout<<"\n ****************************************\n";
        cout<<" *************** WELCOME ****************\n";
        cout<<" ** STUDENT RESULT MANIPULATION SYSTEM **\n";
        cout<<" ****************************************\n";

        cout<<"\n Main Menu"<<endl;
        cout<<" 1. Create a New Student Record "<<endl;
        cout<<" 2. Display a Student Record "<<endl;
        cout<<" 3. Modify a Student Record "<<endl;
        cout<<" 4. Delete a Student Record "<<endl;
        cout<<" 5. Exit "<<endl;
        cout<<"\n Enter your choice (1..5): ";
        cin>>ch;

        switch(ch)
        {
            case '1':
                    system("cls");
                    cout<<"\n ***ENTER STUDENT DETAILS TO CREATE A NEW RECORD...***\n\n";
                    new_stu_profile();
                    system("pause");
                    goto menu1;


            case '2':
                    {
                        Student S;
                        int pos,flag=0;
                        unsigned int rn;
                        int s=sizeof(S);

                        system("cls");

                        cout<<" Enter Student Roll Number: ";
                        cin>>rn;

                        fstream f("Student_Results.dat",ios::in|ios::out|ios::binary);
                        while(f)
                        {
                            f.read((char*)&S,s);

                            if(S.get_roll_no()==rn)
                            {
                                pos=f.tellg();
                                pos-=s;
                                flag=1;
                                system("cls");

                                cout<<"\n STUDENT DETAILS..."<<endl;
                                cout<<"------------------------------"<<endl;
                                S.display();
                                cout<<"\n---------------------------\n"<<endl;;
                            }
                        }

                        if (flag==0)
                        {
                            system("cls");
                            cout<<"\n ***!!STUDENT RECORD DOES NOT EXISTS!!***"<<endl;
                            cout<<"------------------------------------------------------------------\n"<<endl;
                        }
                        f.close();
                        system("pause");
                        goto menu1;
                    }

            case '3':
                    {
                        Student S;
                        int pos,flag=0,ch1;
                        unsigned int rn;
                        int s=sizeof(S);

                        system("cls");

                        cout<<" Enter Student Roll Number: ";
                        cin>>rn;

                        fstream f("Student_Results.dat",ios::in|ios::out|ios::binary);
                        while(f)
                        {
                            f.read((char*)&S,sizeof(S));
                            if(S.get_roll_no()==rn)
                            {
                                pos=f.tellg();
                                pos-=s;
                                flag=1;
                                system("cls");

                                menu2:
                                    system("cls");
                                    cout<<" STUDENT PROFILE: "<<S.get_name()<<endl;
                                    cout<<"\n Main Menu: "<<endl;
                                    cout<<" 1. Modify Entire Subject"<<endl;
                                    cout<<" 2. Modify Marks"<<endl;
                                    cout<<" 3. Add Subject"<<endl;
                                    cout<<" 4. Delete Subject"<<endl;
                                    cout<<" 5. Return to Welcome Page"<<endl;
                                    cout<<"\n Enter your choice (1..5): ";
                                    cin>>ch1;

                                    switch(ch1)
                                    {
                                        case 3:
                                                system("cls");
                                                S.addsub();
                                                S.cal_gpa();
                                                system("pause");
                                                goto menu2;

                                        case 2:
                                                system("cls");
                                                S.modsub_marks();
                                                S.cal_gpa();
                                                system("pause");
                                                goto menu2;

                                        case 4:
                                                system("cls");
                                                S.delete_sub();
                                                S.cal_gpa();
                                                cout<<S.return_index();
                                                system("pause");
                                                goto menu2;

                                        case 5:
                                                f.seekg(pos,ios::beg);
                                                f.write((char*)&S,sizeof(S));
                                                goto menu1;

                                        case 1:
                                                system("cls");
                                                S.modsub_name_marks();
                                                S.cal_gpa();
                                                system("pause");
                                                goto menu2;


                                        default:
                                                system("cls");
                                                cout<<"\n ***INVALID CHOICE!!!***"<<endl;
                                                cout<<"--------------------------------------"<<endl;
                                                system("pause");
                                                goto menu2;
                                    }
                            }
                        }
                    }

            case '4':
                    {
                        Student S;
                        int flag=0;
                        unsigned int rn;

                        system("cls");

                        cout<<" Enter Student Roll Number: ";
                        cin>>rn;

                        ifstream fin("Student_Results.dat",ios::in|ios::binary);
                        ofstream fout("temp.dat",ios::out|ios::binary);

                        while(!fin.eof())
                        {
                            fin.read((char*)&S,sizeof(S));

                            if(fin)
                            {
                                if(S.get_roll_no()==rn)
                                {
                                    flag=1;

                                    cout<<"\n DELETING STUDENT RECORD... "<<S.get_name()<<endl;
                                    cout<<"-----------------------------------"<<endl;
                                }
                                else
                                    fout.write((char*)&S,sizeof(S));
                            }
                        }

                        fin.close();
                        fout.close();

                        remove("Student_Results.dat");
                        rename("temp.dat","Student_Results.dat");

                        if(flag==1)
                        {
                            cout<<" STUDENT RECORD DELETED SUCCESSFULLY..."<<endl;
                            cout<<"-------------------------------------------"<<endl;
                        }
                        else
                        {
                            cout<<" STUDENT RECORD NOT FOUND..."<<endl;
                            cout<<"-------------------------------------------"<<endl;
                        }

                        system("pause");
                        goto menu1;
                    }

            case '5':
                    cout<<"\n\n\t * SHUTTING DOWN PROGRAM *\n";
                    cout<<"************************************************\n";
                    return 0;

            default:
                    system("cls");
                    cout<<"\n ***INVALID CHOICE!!!***\n\n";
                    system("pause");
                    goto menu1;
        }
}
