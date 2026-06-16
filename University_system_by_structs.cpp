#include<iostream>
using std::cout,std::cin,std::string,std::endl;

static inline int student_count = 0;
struct Address {
    string Country;
    string Province;
    string City;
    string Block;
};
struct Student {
    Address address;
    string Student_ID;
    string Name;
    double CGPA;
    int Age;
    Student() {
        student_count++;
    }
};
struct Instructor {
    Address address;
    string Employee_ID;
    string Name;
    int Salary;
};
struct Course {
    Student student;
    Instructor instructor;
    string Course_ID;
    string Course_name;
    int Credit_hours;
};
struct Department {
    Course course;
    string Student_count = std::to_string(student_count);
};
struct University {
    Address address;
    Department department;
    string Name;
};

void input(University &U) {


    U.Name = "Akhuwat College and University Kasur";

    U.address.Country = "Pakistan";
    U.address.Province = "Punjab";
    U.address.City = "Kasur";
    U.address.Block = "Mustafabad";

    // Student information

    U.department.course.student.Student_ID = "BSIT-25F.0012";
    U.department.course.student.Name = "Abdul Wahab";
    U.department.course.student.CGPA = 3.51;
    U.department.course.student.Age = 18;


    U.department.course.student.address.Country = "Pakistan";
    U.department.course.student.address.Province = "Punjab";
    U.department.course.student.address.City = "Lahore";
    U.department.course.student.address.Block = "K.block";

    // Employee information

    U.department.course.instructor.address.Country = "Pakistan";
    U.department.course.instructor.address.Province = "Punjab";
    U.department.course.instructor.address.City = "Lahore";
    U.department.course.instructor.address.Block = "DHA Phase-6";

    U.department.course.instructor.Employee_ID = "ACK-CS-DS";
    U.department.course.instructor.Name = "Kamran Shabir";
    U.department.course.instructor.Salary = 200000;

    U.department.course.Course_ID = "DS-CS-2026";
    U.department.course.Course_name = "Discrete Structures";
    U.department.course.Credit_hours = 3;
}

void output(University &U) {
    cout<<"University Name is: "<<U.Name <<endl;

    cout<<"University Address is: "<<endl;
    cout<<"\t"<<"Country: "<<U.address.Country<<endl;
    cout<<"\t"<<"Province: "<<U.address.Province<<endl;
    cout<<"\t"<<"City: "<<U.address.City<<endl;
    cout<<"\t"<<"Block: "<<U.address.Block<<endl;

    // Student information

    cout<<"Student Information is: "<<endl;
    cout<<"\t"<<"Student name is: "<<U.department.course.student.Name<<endl;
    cout<<"\t"<<"Student_ID is: "<<U.department.course.student.Student_ID<<endl;

    cout<<"\t"<<"Country: "<<U.department.course.student.address.Country<<endl;
    cout<<"\t"<<"Province: "<<U.department.course.student.address.Province<<endl;
    cout<<"\t"<<"City: "<<U.department.course.student.address.City<<endl;
    cout<<"\t"<<"Block: "<<U.department.course.student.address.Block<<endl;


    cout<<"\t"<<"CGPA is: "<<U.department.course.student.CGPA<<endl;
    cout<<"\t"<<"Age is: "<<U.department.course.student.Age<<endl;




    // Employee information
    cout<<"Employee Information is: "<<endl;
    cout<<"\t"<<"Employee ID is: "<<U.department.course.instructor.Employee_ID<<endl;
    cout<<"\t"<<"Employee name is: "<<U.department.course.instructor.Name<<endl;

    cout<<"\t"<<"Country :"<<U.department.course.instructor.address.Country<<endl;
    cout<<"\t"<<"Province: "<<U.department.course.instructor.address.Province<<endl;
    cout<<"\t"<<"City: "<<U.department.course.instructor.address.City<<endl;
    cout<<"\t"<<"Block: "<<U.department.course.instructor.address.Block<<endl;

    cout<<"\t"<<"Employee Salary is: "<<U.department.course.instructor.Salary<<endl;

    cout<<"Course information is: "<<endl;
    cout<<"\t"<<"Course ID is: "<<U.department.course.Course_ID<<endl;
    cout<<"\t"<<"Course name is: "<<U.department.course.Course_name<<endl;
    cout<<"\t"<<"Credit hours is: "<<U.department.course.Credit_hours<<endl;
    cout<<"\t"<<"Total student is: "<<U.department.Student_count<<endl;
}
int main() {
    University U;

    input(U);
    output(U);

}
