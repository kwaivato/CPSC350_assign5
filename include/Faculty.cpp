// Faculty.cpp
// An implemented faculty class that will be used to manage a database of students and faculty.
// @author Vidal M. Arroyo
// @author arroy118@mail.chapman.edu
// @version 1.0

#include "Faculty.h"

using namespace std;

//Default constructor
Faculty::Faculty()
{
  m_faculty_id = 0;
  m_faculty_name = "";
  m_faculty_level = "";
  m_faculty_department = "Communications";
  m_number_of_faculty_advisees = 0;
}

//Overloaded constructor - not going to add a student here because a faculty member doesn't necessarily need a mentee
Faculty::Faculty(int facultyID, string facultyName, string facultyLevel, string facultyDepartment)
{
  m_faculty_id = facultyID;
  m_faculty_name = facultyName;
  m_faculty_level = facultyLevel;
  m_faculty_department = facultyDepartment;
  m_number_of_faculty_advisees = 0;
}

//Copy Constructor
Faculty::Faculty(const Faculty &f1)
{
  m_faculty_id = f1.getFacultyID();
  m_faculty_name = f1.getFacultyName();
  m_faculty_level = f1.getFacultyLevel();
  m_faculty_department = f1.getFacultyDepartment();
  //this is used to populate the student list
  DoublyListNode<int> *curr = f1.getFacultyAdviseeIDFront(); //equals get front
  while (curr!= NULL)
  {
    addFacultyAdviseeID(curr->m_data);
    curr = curr->next;
  }
}

//Destructor
Faculty::~Faculty()
{
  //destructor for DoublyLinkedList is already called when program ends
}

//Accessors
int Faculty::getFacultyID() const
{
  return m_faculty_id;
}

string Faculty::getFacultyName() const
{
  return m_faculty_name;
}

string Faculty::getFacultyLevel() const
{
  return m_faculty_level;
}

string Faculty::getFacultyDepartment() const
{
  return m_faculty_department;
}

int Faculty::getNumberOfFacultyAdvisees() const
{
  return m_number_of_faculty_advisees;
}

DoublyListNode<int>* Faculty::getFacultyAdviseeIDFront() const
{
  return m_faculty_advisee_IDs.getFront();
}

//Mutators
void Faculty::setFacultyID(int facultyID)
{
  m_faculty_id = facultyID;
}

void Faculty::setFacultyName(string facultyName)
{
  m_faculty_name = facultyName;
}

void Faculty::setFacultyLevel(string facultyLevel)
{
  m_faculty_level = facultyLevel;
}

void Faculty::setFacultyDepartment(string facultyDepartment)
{
  m_faculty_department = facultyDepartment;
}

//Used to add an advisee
void Faculty::addFacultyAdviseeID(int studentID)
{
  m_faculty_advisee_IDs.insertBack(studentID);
  m_number_of_faculty_advisees++;
}

//Used to remove an advisee
void Faculty::removeFacultyAdviseeID(int studentID)
{
  m_faculty_advisee_IDs.remove(studentID);
  m_number_of_faculty_advisees--;
}

//Used to tell whether a faculty member has a student
bool Faculty::hasStudent(int studentID)
{
  if (m_faculty_advisee_IDs.contains(studentID))
  {
    return true;
  }
  else
  {
    return false;
  }
}

//Used to tell whether a faculty member has any students
bool Faculty::hasStudents()
{
  return (!m_faculty_advisee_IDs.isEmpty());
}

//Overloaded operators
  //Equality based on ID
bool Faculty::operator==(const Faculty &f1) const
{
  return (m_faculty_id == f1.getFacultyID());
}

  //Inequality based on ID
bool Faculty::operator!=(const Faculty &f1) const
{
  return (m_faculty_id != f1.getFacultyID());
}

  //less than based on ID
bool Faculty::operator<(const Faculty &f1) const
{
  return (m_faculty_id < f1.getFacultyID());
}

  //greater than based on ID
bool Faculty::operator>(const Faculty &f1) const
{
  return (m_faculty_id > f1.getFacultyID());
}

  //does the same thing as the copy constructor
void Faculty::operator=(const Faculty &f1)
{
  m_faculty_id = f1.getFacultyID();
  m_faculty_name = f1.getFacultyName();
  m_faculty_level = f1.getFacultyLevel();
  m_faculty_department = f1.getFacultyDepartment();
  //Used to copy the student list
  //get front
  DoublyListNode<int> *curr = f1.getFacultyAdviseeIDFront();
  while (curr!= NULL)
  {
    //adding all the students in the list
    addFacultyAdviseeID(curr->m_data);
    curr = curr->next;
  }
}

//Used to print all the information about a faculty member, including all of their advisees (or lack thereof)
void Faculty::PrintFacultyInfo()
{
  cout << "Faculty ID: " << m_faculty_id << endl;
  cout << "Name: " << m_faculty_name << endl;
  cout << "Academic Level: " << m_faculty_level << endl;
  cout << "Department: " << m_faculty_department << endl;
  if (!m_faculty_advisee_IDs.isEmpty())
  {
    cout << "Student Advisee IDs: ";
    m_faculty_advisee_IDs.printList();
  }
  else
  {
    cout << "This faculty member has no student advisees." << endl;
  }
}
