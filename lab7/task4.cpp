
#include<iostream>
using namespace std;
class Person
{
  private:
  string name,address,PhoneNumber,Email;
  static int id;
  public:
  Person(string n , string a, string p, string e):name(n),
  address(a),PhoneNumber(p),Email(e){id++;}
  virtual void displayInfo()
  {
    cout << "ID : " << id << endl;
    cout << "Name : " << name << endl;
    cout << "address : " << address << endl;
    cout << "PhoneNumber : " << PhoneNumber << endl;
    cout << "Email : " << Email << endl;
  }
  void modifyInfo()
  {
    cout << "Enter name " << endl;
    cin >> name ;
    cout << "Enter address " << endl;
    cin >> address ;
    cout << "Enter PhoneNumber " << endl;
    cin >> PhoneNumber ;
    cout << "Enter Email " << endl;
    cin >> Email ;
  }
};
int Person:: id = 1;
class student: virtual public Person
{
  private:
  string CourseEnrolled;
  float gpa;
  string EnrollmentYear;
  public:
    student(string ce, float gpa, string ey, string n, string a, string p, string e)
        : CourseEnrolled(ce), gpa(gpa), EnrollmentYear(ey), Person(n, a, p, e)
    {}
     void displayInfo()
    {
      cout << "Course Enrolled " << CourseEnrolled << endl;
      cout << "GPA : " << gpa << endl;
      cout << "Enrollment Year : " << EnrollmentYear << endl;
  }
};
class professor:virtual public Person
{
  private:
  string department,position;
  double salary;
  public:
   professor(string dep, double s, string pos, string n, string a, string p, string e)
        : department(dep), position(pos), salary(s), Person(n, a, p, e)
    {}
  void displayInfo()
  {
    cout << "Department : " << department << endl;
    cout << "Position : " << position << endl;
    cout << "Salary : " << salary << endl;
  }
};
class staff:virtual public Person
{
  private:
  string department , position ;
  double salary;
  public:
    staff(string dep,string post,double sal,string n, string a, string p, string e)
    : department(dep),position(post),salary(sal),Person(n,a,p,e)
    {}
    void displayInfo()
    {
      cout << "Department : " << department << endl;
      cout << "Position : " << position << endl;
      cout << "Salary : " << salary << endl;
  }
};
class Course
{
  private:
  int courseID;
  string courseName , credits , instructor , schedule;
  public:
  void registerStudent(student s)
  {
    cout << "Registered Successfully" << endl;
  }
  void calculateGrade()
  {
    cout << "Calculating Grade" << endl;
  }
};
int main()
{
  student s("CS", 2.79, "2024", "Lucky", "karachi", "0309988888", "lamaheshwari9@gmail.com");
  Person *p = &s;
  p->displayInfo();
}
