// Menu.h
// A declared menu class that will be used to manage a database of students and faculty.
// @author Vidal M. Arroyo
// @author arroy118@mail.chapman.edu
// @version 1.0

#include "Logger.h"

using namespace std;

class Menu
{
  public:
    Menu();
    ~Menu();
    //Runs the program
    void Run();
  private:
    Logger m_logger;
    string m_choice;
    int m_logger_choice; //function choice
    //Variables for user input
    int m_student_id;
    int m_faculty_id;
    string m_user_input_string;
    double m_user_input_double;
};
