// Faculty.h
// A declared faculty class that will be used to manage a database of students and faculty.
// @author Vidal M. Arroyo
// @author arroy118@mail.chapman.edu
// @version 1.0

#include "DoublyList.cpp"

using namespace std;

#ifndef FACULTY_H
#define FACULTY_H

class Faculty
{
  public:
    //Default constructor
      Faculty();
    //Overloaded constructor - not going to add a student here because a faculty doesn't necessarily need a mentee
      Faculty(int facultyID, string facultyName, string facultyLevel, string facultyDepartment);
    //Copy Constructor
      Faculty(const Faculty &f1);
    //Destructor
      ~Faculty();
    //Accessors
      int getFacultyID() const;
      string getFacultyName() const;
      string getFacultyLevel() const;
      string getFacultyDepartment() const;
      int getNumberOfFacultyAdvisees() const;
      DoublyListNode<int>* getFacultyAdviseeIDFront() const;
    //Mutators
      void setFacultyID(int facultyID);
      void setFacultyName(string facultyName);
      void setFacultyLevel(string facultyLevel);
      void setFacultyDepartment(string facultyDepartment);
      //Add students to the faculty member's Linked-List
      void addFacultyAdviseeID(int studentID);
      //Remove students from the faculty member's Linked-List
      void removeFacultyAdviseeID(int studentID);
      //Used to tell whether the faculty member has a specific student based on the ID
      bool hasStudent(int studentID);
      //Used to tell whether the faculty member has any students
      bool hasStudents();
    //Overloaded operators
      //Equality operators overloading
      bool operator==(const Faculty &f1) const;
      bool operator!=(const Faculty &f1) const;
      bool operator<(const Faculty &f1) const;
      bool operator>(const Faculty &f1) const;
      void operator=(const Faculty &f1);
    //Utility Functions
      void PrintFacultyInfo();
  private:
    //These are the only fields the class contains.
      int m_faculty_id; //an integer Faculty ID
      string m_faculty_name; //a String name
      string m_faculty_level; //a String level (lecturer, assistant prof, associate prof, etc)
      string m_faculty_department; //a String department
      int m_number_of_faculty_advisees; //keeps track of how many advisees a faculty member has
      DoublyList<int> m_faculty_advisee_IDs; //a list of integers corresponding to all of the faculty member’s advisees’ ids

};

#endif
