#include<iostream>
#include <limits>
using std::cout,std::cin,std::string,std::endl;

struct Address {
    string Country;
    string Province;
    string City;
    string Block;
};
struct University {
    struct Student {
        Address address;
        string Student_ID;
        string Name;
        double CGPA;
        int Age;
    };
    struct Instructor {
        Address address;
        string Employee_ID;
        string Name;
        int Salary;
    };
    struct Course {
        Student student[15];
        Instructor instructor;
        string Course_ID;
        string Course_name;
        int Credit_hours;
    };
    struct Department {
        string department_name;
        Course course[5];
    };
    Address address;
    Department department[3];
    string Name;
};

void input(University &U) {
    cout<<"Enter the University Name: "<<endl;
    getline(cin,U.Name);
    cout<<"Enter the Address of "<<U.Name<<": "<<endl;
    cout<<"Enter Country: "<<endl;getline(cin,U.address.Country);
    cout<<"Enter State of "<<U.address.Country<<": "<<endl;getline(cin,U.address.Province);
    cout<<"Enter City of "<<U.address.Province<<": "<<endl;getline(cin,U.address.City);
    cout<<"Enter Block of "<<U.address.City<<": "<<endl;
    getline(cin,U.address.Block);
    for (int i=0;i<3;i++) {
        string Department_name;
        cout<<"Enter the Department name: "<<endl;
        getline(cin,U.department[i].department_name);
        for (int j=0;j<5;j++) {
            cout<<"Enter the "<<j+1<<" Course name in "<<U.department[i].department_name<<": "<<endl;
            getline(cin,U.department[i].course[j].Course_name);
            cout<<"Enter the Course ID of "<<U.department[i].course[j].Course_name<<": "<<endl;
            cin>>U.department[i].course[j].Course_ID;
            cout<<"Enter Credit Hours of "<<U.department[i].course[j].Course_name<<": "<<endl;
            cin>>U.department[i].course[j].Credit_hours;
            cout<<"Enter the name of instructor of "<<U.department[i].course[j].Course_name<<": "<<endl;
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            getline(cin,U.department[i].course[j].instructor.Name);
            cout<<"Enter the employee ID of "<<U.department[i].course[j].instructor.Name<<": "<<endl;
            cin>>U.department[i].course[j].instructor.Employee_ID;
            cout<<"Enter the salary of "<<U.department[i].course[j].instructor.Name<<": "<<endl;
            cin>>U.department[i].course[j].instructor.Salary;
            cout<<"Enter the address of "<<U.department[i].course[j].instructor.Name<<": "<<endl;
            cout<<"Enter Country: "<<endl; cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            getline(cin,U.department[i].course[j].instructor.address.Country);
            cout<<"Enter State of "<<U.department[i].course[j].instructor.address.Country<<": "<<endl; getline(cin,U.department[i].course[j].instructor.address.Province);
            cout<<"Enter City of "<<U.department[i].course[j].instructor.address.Province<<": "<<endl; getline(cin,U.department[i].course[j].instructor.address.City);
            cout<<"Enter Block of "<<U.department[i].course[j].instructor.address.City<<": "<<endl;
            getline(cin,U.department[i].course[j].instructor.address.Block);
            for (int k=0;k<15;k++) {
                cout<<"Enter the name of "<<k+1<<" student: "<<endl;
                getline(cin,U.department[i].course[j].student[k].Name);
                cout<<"Enter the Student ID of "<<U.department[i].course[j].student[k].Name<<": "<<endl;
                cin>>U.department[i].course[j].student[k].Student_ID;
                double CGPA;
                do {
                    cout<<"Enter the CGPA of "<<U.department[i].course[j].student[k].Name<<": "<<endl;
                    cin>>CGPA;
                }while (CGPA>4.0 || CGPA<0.0);
                U.department[i].course[j].student[k].CGPA = CGPA;
                int Age;
                do {
                    cout<<"Enter the Age of "<<U.department[i].course[j].student[k].Name<<": "<<endl;
                    cin>>Age;
                }while (Age<0 || Age>25);
                U.department[i].course[j].student[k].Age = Age;
                cout<<"Enter the address of "<<U.department[i].course[j].student[k].Name<<": "<<endl;
                cout<<"Enter Country: "<<endl; cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                getline(cin,U.department[i].course[j].student[k].address.Country);
                cout<<"Enter State of "<<U.department[i].course[j].student[k].address.Country<<": "<<endl; getline(cin,U.department[i].course[j].student[k].address.Province);
                cout<<"Enter City of "<<U.department[i].course[j].student[k].address.Province<<": "<<endl; getline(cin,U.department[i].course[j].student[k].address.City);
                cout<<"Enter Block of "<<U.department[i].course[j].student[k].address.City<<endl;
                getline(cin,U.department[i].course[j].student[k].address.Block);
            }
        }
    }
}

void output(const University &U) {
    cout<<"University Name is: "<<U.Name <<endl;
    cout<<"University Address is: "<<endl;
    cout<<"\t"<<"Country: "<<U.address.Country <<endl;
    cout<<"\t"<<"State: "<<U.address.Province <<endl;
    cout<<"\t"<<"City: "<<U.address.City <<endl;
    cout<<"\t"<<"Block: "<<U.address.Block <<endl;

    for (int i=0;i<3;i++) {
        cout<<"Information of "<<U.department[i].department_name<<" department: "<<endl;
        for (int j=0;j<5;j++) {
            cout<<"\t"<<"Information of "<<U.department[i].course[j].Course_name<<" course: "<<endl;
            cout<<"\t\t"<<"Course ID of "<<U.department[i].course[j].Course_name<<" is: "<<U.department[i].course[j].Course_ID<<endl;
            cout<<"\t\t"<<"Credit Hours of "<<U.department[i].course[j].Course_name<<" is: "<<U.department[i].course[j].Credit_hours<<endl;
            cout<<"\t"<<"Information of Instructor of "<<U.department[i].course[j].Course_name<<" is:"<<endl;
            cout<<"\t\t"<<"Instructor Name is: "<<U.department[i].course[j].instructor.Name<<endl;
            cout<<"\t\t"<<"Employee ID of "<<U.department[i].course[j].instructor.Name<<" is: "<<U.department[i].course[j].instructor.Employee_ID<<endl;
            cout<<"\t\t"<<"Salary of "<<U.department[i].course[j].instructor.Name<<" is: "<<U.department[i].course[j].instructor.Salary<<endl;
            cout<<"\t"<<"Address of "<<U.department[i].course[j].instructor.Name<<" is: "<<endl;
            cout<<"\t\t"<<"Country is: "<<U.department[i].course[j].instructor.address.Country<<endl;
            cout<<"\t\t"<<"State is: "<<U.department[i].course[j].instructor.address.Province<<endl;
            cout<<"\t\t"<<"City is: "<<U.department[i].course[j].instructor.address.City<<endl;
            cout<<"\t\t"<<"Block is: "<<U.department[i].course[j].instructor.address.Block<<endl;
            for (int k=0;k<15;k++) {
                cout<<"\tInformation of Student "<<k+1<<": "<<endl;
                cout<<"\t\tName of Student is: "<<U.department[i].course[j].student[k].Name <<endl;
                cout<<"\t\tStudent ID of "<<U.department[i].course[j].student[k].Name <<" is: "<<U.department[i].course[j].student[k].Student_ID <<endl;
                cout<<"\t\tAge of "<<U.department[i].course[j].student[k].Name <<" is: "<<U.department[i].course[j].student[k].Age <<endl;
                cout<<"\t\tCGPA of "<<U.department[i].course[j].student[k].Name <<" is: "<<U.department[i].course[j].student[k].CGPA <<endl;
                cout<<"\tAddress of "<<U.department[i].course[j].student[k].Name<<" is: "<<endl;
                cout<<"\t\tCountry is: "<<U.department[i].course[j].student[k].address.Country <<endl;
                cout<<"\t\tState is: "<<U.department[i].course[j].student[k].address.Province <<endl;
                cout<<"\t\tCity is: "<<U.department[i].course[j].student[k].address.City <<endl;
                cout<<"\t\tBlock is: "<<U.department[i].course[j].student[k].address.Block <<endl;
            }
        }
    }
}

int main() {
    University U;
    input(U);
    output(U);
}
