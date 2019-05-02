// Menu.cpp
// An implemented menu class that will be used to manage a database of students and faculty.
// @author Vidal M. Arroyo
// @author arroy118@mail.chapman.edu
// @version 1.0

#include "Menu.h"

using namespace std;

Menu::Menu()
{
  m_choice = "Y";
  m_logger_choice = 0;
  m_student_id = 0;
  m_faculty_id = 0;
  m_user_input_string = "";
  m_user_input_double = 0.0;
}

Menu::~Menu()
{

}

void Menu::Run()
{
  cout << "Welcome to MyUniversityDataBase: the only computer program that handles your university database needs with style! :-)" << endl;
  cout << "My name is D-Qwon, and I am your virtual assistant for MyUniversityDataBase." << endl;
  //inputs any previous data
  m_logger.In();
  //cin.fail() is used to handle type mismatch errors
  while (m_choice == "Y" && cin.fail() == false)
  {
    cout << "Here are your choices for action." << endl;
    cout << "1. Print all students and their information, sorted by ascending ID number." << endl;
    cout << "2. Print all faculty and their information, sorted by ascending ID number." << endl;
    cout << "3. Find and display a student's information given the ID number." << endl;
    cout << "4. Find and display a faculty member's information given the ID number." << endl;
    cout << "5. Given a student’s ID number, print the name and information of their faculty advisor." << endl;
    cout << "6. Given a faculty member's ID number, print all the names and information of his/her advisees." << endl;
    cout << "7. Add a new student." << endl;
    cout << "8. Delete a student given the ID number." << endl;
    cout << "9. Add a new faculty member." << endl;
    cout << "10. Delete a faculty member given the ID number." << endl;
    cout << "11. Change a student’s advisor given the student ID number and the new faculty ID number." << endl; //changes student tree
    cout << "12. Remove an advisee from a faculty member given the ID number." << endl; //changes faculty tree AND student tree (must change advisee as well)
    cout << "13. Rollback to the previous version of the database." << endl;
    //BONUS FUNCTIONS
    cout << "14. Print out all students with a given name." << endl;
    cout << "15. Print out all students with a given academic level." << endl;
    cout << "16. Print out all students with a given major." << endl;
    cout << "17. Print out all students with a given GPA." << endl;
    cout << "18. Print out all students with a given advisor ID." << endl;
    cout << "19. Print out all faculty members with a given name." << endl;
    cout << "20. Print out all faculty members with a given academic level." << endl;
    cout << "21. Print out all faculty members with a given department." << endl;
    cout << "22. Exit" << endl;
    cout << "Please enter an integer indicating which action you would like to take: ";
    cin >> m_logger_choice;
    if (m_logger_choice == 1)
    {
      //1. Print all students and their information, sorted by ascending ID number.
      cout << "\n";
      m_logger.StudentTreePrint();
    }
    else if (m_logger_choice == 2)
    {
      //2. Print all faculty and their information, sorted by ascending ID number.
      cout << "\n";
      m_logger.FacultyTreePrint();
    }
    else if (m_logger_choice == 3)
    {
      //3. Find and display a student's information given the ID number.
      cout << "\n";
      cout << "Please enter the ID number of the student that you are looking for: ";
      cin >> m_student_id;
      m_logger.StudentPrint(m_student_id);
    }
    else if (m_logger_choice == 4)
    {
      //4. Find and display a faculty member's information given the ID number.
      cout << "\n";
      cout << "Please enter the ID number of the faculty member that you are looking for: ";
      cin >> m_faculty_id;
      m_logger.FacultyPrint(m_faculty_id);
    }
    else if (m_logger_choice == 5)
    {
      //5. Given a student’s ID number, print the name and information of their faculty advisor.
      cout << "\n";
      cout << "Please enter the ID number of the student that you want faculty advisor information for: ";
      cin >> m_student_id;
      m_logger.FacultyPrintOfStudent(m_student_id);
    }
    else if (m_logger_choice == 6)
    {
      //6. Given a faculty member's ID number, print all the names and information of his/her advisees.
      cout << "\n";
      cout << "Please enter the ID number of the faculty member that you want student advisee information for: ";
      cin >> m_faculty_id;
      m_logger.StudentsPrintOfFaculty(m_faculty_id);
    }
    else if (m_logger_choice == 7)
    {
      //7. Add a new student.
      cout << "\n";
      cout << "Please enter the ID number of the student that you want to add: ";
      cin >> m_student_id;
      m_logger.AddStudent(m_student_id);
    }
    else if (m_logger_choice == 8)
    {
      //8. Delete a student given the ID number.
      cout << "\n";
      cout << "Please enter the ID number of the student that you want to delete: ";
      cin >> m_student_id;
      m_logger.DeleteStudent(m_student_id);
    }
    else if (m_logger_choice == 9)
    {
      //9. Add a new faculty member.
      cout << "\n";
      cout << "Please enter the ID number of the faculty member that you want to add: ";
      cin >> m_faculty_id;
      m_logger.AddFaculty(m_faculty_id);
    }
    else if (m_logger_choice == 10)
    {
      //10. Delete a faculty member given the ID number
      cout << "\n";
      cout << "Please enter the ID number of the faculty member that you want to delete: ";
      cin >> m_faculty_id;
      m_logger.DeleteFaculty(m_faculty_id);
    }
    else if (m_logger_choice == 11)
    {
      //11. Change a student’s advisor given the student ID number and the new faculty ID number.
      cout << "\n";
      cout << "Please enter the ID number of the student whose advisor you want to change: ";
      cin >> m_student_id;
      m_logger.ChangeAdvisor(m_student_id, 0);
    }
    else if (m_logger_choice == 12)
    {
      //12. Remove an advisee from a faculty member given the ID number.
      cout << "\n";
      cout << "Please enter the ID number of the faculty member that you want to change an advisee for: ";
      cin >> m_faculty_id;
      m_logger.RemoveAdvisee(m_faculty_id);
    }
    else if (m_logger_choice == 13)
    {
      //13. Rollback to the previous version of the database.
      cout << "\n";
      m_logger.Rollback();
      cout << "\n";
    }
    else if (m_logger_choice == 14)
    {
      //14. Print out all students with a given name.
      cout << "\n";
      cout << "Please enter the name of the student(s) that you want information for: ";
      cin.ignore();
      getline(cin,m_user_input_string);
      m_logger.StudentPrintName(m_user_input_string);
    }
    else if (m_logger_choice == 15)
    {
      //15. Print out all students with a given academic level.
      cout << "\n";
      cout << "Please enter the academic level of the student(s) that you want information for: ";
      cin.ignore();
      getline(cin,m_user_input_string);
      m_logger.StudentPrintLevel(m_user_input_string);
    }
    else if (m_logger_choice == 16)
    {
      //16. Print out all students with a given major.
      cout << "\n";
      cout << "Please enter the major of the student(s) that you want information for: ";
      cin.ignore();
      getline(cin,m_user_input_string);
      m_logger.StudentPrintMajor(m_user_input_string);
    }
    else if (m_logger_choice == 17)
    {
      //17. Print out all students with a given GPA.
      cout << "\n";
      cout << "Please enter the GPA of the student(s) that you want information for: ";
      cin >> m_user_input_double;
      m_logger.StudentPrintGPA(m_user_input_double);
    }
    else if (m_logger_choice == 18)
    {
      //18. Print out all students with a given advisor ID.
      cout << "\n";
      cout << "Please enter the advisor ID of the student(s) that you want information for: ";
      cin >> m_faculty_id;
      m_logger.StudentPrintAdvisor(m_faculty_id);
    }
    else if (m_logger_choice == 19)
    {
      //19. Print out all faculty members with a given name.
      cout << "\n";
      cout << "Please enter the name of the faculty member(s) that you want information for: ";
      cin.ignore();
      getline(cin,m_user_input_string);
      m_logger.FacultyPrintName(m_user_input_string);
    }
    else if (m_logger_choice == 20)
    {
      //20. Print out all faculty members with a given academic level.
      cout << "\n";
      cout << "Please enter the academic level of the faculty member(s) that you want information for: ";
      cin.ignore();
      getline(cin,m_user_input_string);
      m_logger.FacultyPrintLevel(m_user_input_string);
    }
    else if (m_logger_choice == 21)
    {
      //21. Print out all faculty members with a given department.
      cout << "\n";
      cout << "Please enter the department of the faculty member(s) that you want information for: ";
      cin.ignore();
      getline(cin,m_user_input_string);
      m_logger.FacultyPrintDepartment(m_user_input_string);
    }
    else
    {
      //22. Exit
      m_choice = "N";
      cout << "\n";
      //save databases via logger -> OUT
      m_logger.Out();
      cout << "We have saved the latest versions of your databases for future use." << endl;
      cout << "Thank you for using MyUniversityDataBase, the only computer program that handles your university database needs with style! :-)" << endl;
    }
  }
  //This is used to tell the user a type mismatch error happened (if it happened)
  if (cin.fail() == true)
  {
    cout << "\n";
    cout << "It looks like you entered a mismatched type. As a result, no changes were made to the database." << endl;
    cout << "Please re-launch the program and be sure not to do any funny stuff!" << endl;
  }
}
