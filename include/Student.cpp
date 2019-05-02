// Student.cpp
// An implemented Student class that will be used to manage a database of students and faculty.
// @author Vidal M. Arroyo
// @author arroy118@mail.chapman.edu
// @version 1.0

#include "Student.h"
#include <iomanip>

using namespace std;

//Default Constructor
Student::Student()
{
  m_student_ID = 0;
  m_student_name = "";
  m_student_level = "";
  m_student_major = "Humanities";
  m_student_GPA = 0.00;
  m_student_advisor_ID = 0;
}

//Overloaded Constructor
Student::Student(int studentID, string studentName, string studentLevel, string studentMajor, double studentGPA, int studentAdvisorID)
{
  m_student_ID = studentID;
  m_student_name = studentName;
  m_student_level = studentLevel;
  m_student_major = studentMajor;
  m_student_GPA = studentGPA;
  m_student_advisor_ID = studentAdvisorID;
}

//Copy Constructor
Student::Student(const Student &s1)
{
  m_student_ID = s1.getStudentID();
  m_student_name = s1.getStudentName();
  m_student_level = s1.getStudentLevel();
  m_student_major = s1.getStudentMajor();
  m_student_GPA = s1.getStudentGPA();
  m_student_advisor_ID = s1.getStudentAdvisorID();
}

//Destructor
Student::~Student()
{

}
//Accessors
int Student::getStudentID() const
{
  return m_student_ID;
}

string Student::getStudentName() const
{
  return m_student_name;
}

string Student::getStudentLevel() const
{
  return m_student_level;
}

string Student::getStudentMajor() const
{
  return m_student_major;
}

double Student::getStudentGPA() const
{
  return m_student_GPA;
}

int Student::getStudentAdvisorID() const
{
  return m_student_advisor_ID;
}

//Mutators
void Student::setStudentID(int studentID)
{
  m_student_ID = studentID;
}

void Student::setStudentName(string studentName)
{
  m_student_name = studentName;
}

void Student::setStudentLevel(string studentLevel)
{
  m_student_level = studentLevel;
}

void Student::setStudentMajor(string studentMajor)
{
  m_student_major = studentMajor;
}

void Student::setStudentGPA(double studentGPA)
{
  m_student_GPA = studentGPA;
}

void Student::setStudentAdvisorID(int studentAdvisorID)
{
  m_student_advisor_ID = studentAdvisorID;
}

//Overloaded operators
  //Tells if two students are equal
bool Student::operator==(const Student &s1) const
{
  return (m_student_ID == s1.getStudentID());
}

  //Tells if students are not equal
bool Student::operator!=(const Student &s1) const
{
  return (m_student_ID != s1.getStudentID());
}
  //Tells if one student is 'less' than another by comparing their ID's
bool Student::operator<(const Student &s1) const
{
  return (m_student_ID < s1.getStudentID());
}

  //Tells if one student is 'greater' than another by comparing their ID's
bool Student::operator>(const Student &s1) const
{
  return (m_student_ID > s1.getStudentID());
}

//does the same thing as the copy constructor by making one student 'equal' to another student
void Student::operator=(const Student &s1)
{

  m_student_ID = s1.getStudentID();
  m_student_name = s1.getStudentName();
  m_student_level = s1.getStudentLevel();
  m_student_major = s1.getStudentMajor();
  m_student_GPA = s1.getStudentGPA();
  m_student_advisor_ID = s1.getStudentAdvisorID();
}

//This function will be used time and time again to print out all of a student's info
void Student::PrintStudentInfo()
{
  cout << "Student ID: " << m_student_ID << endl;
  cout << "Name: " << m_student_name << endl;
  cout << "Academic Level: " << m_student_level << endl;
  cout << "Major: " << m_student_major << endl;
  cout << fixed;
  cout << setprecision(2);
  cout << "GPA: " << m_student_GPA << endl;
  cout << "Advisor ID: " << m_student_advisor_ID << endl;
}
