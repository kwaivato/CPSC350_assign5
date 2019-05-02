// Student.h
// A declared Student class that will be used to manage a database of students and faculty.
// @author Vidal M. Arroyo
// @author arroy118@mail.chapman.edu
// @version 1.0

#include <string>
#include <iostream>

using namespace std;

#ifndef STUDENT_H
#define STUDENT_H

class Student
{
  public:
    //Default Constructor
      Student();
    //Overloaded Constructor
      Student(int studentID, string studentName, string studentLevel, string studentMajor, double studentGPA, int studentAdvisorID);
    //Copy Constructor to 'turn' one student into another
      Student(const Student &s1);
    //Destructor
      ~Student();
    //Accessors
      int getStudentID() const;
      string getStudentName() const;
      string getStudentLevel() const;
      string getStudentMajor() const;
      double getStudentGPA() const;
      int getStudentAdvisorID() const;
    //Mutators
      void setStudentID(int studentID);
      void setStudentName(string studentName);
      void setStudentLevel(string studentLevel);
      void setStudentMajor(string studentMajor);
      void setStudentGPA(double studentGPA);
      void setStudentAdvisorID(int studentAdvisorID);
    //Overloaded operators used to compare students or set them equal to one another
      bool operator==(const Student &s1) const;
      bool operator!=(const Student &s1) const;
      bool operator<(const Student &s1) const;
      bool operator>(const Student &s1) const;
      void operator=(const Student &s1); //does the same thing as the copy constructor
    //Utility Functions
      void PrintStudentInfo();
  private:
    //These are the only fields the class contains.
      int m_student_ID; //a unique student ID (an integer)
      string m_student_name; //a String name field
      string m_student_level; //a string level field (Freshman, Sophomore, etc)
      string m_student_major; //a String major field
      double m_student_GPA; //a double GPA field
      int m_student_advisor_ID; //an integer advisor field, which will contain the Faculty ID of their advisor
};

#endif
