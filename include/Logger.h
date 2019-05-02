// Logger.h
// A declared Logger class that will be used to manage a database of students and faculty.
// @author Vidal M. Arroyo
// @author arroy118@mail.chapman.edu
// @version 1.0

#include "BST.cpp"
#include "Faculty.h"
#include "Student.h"
#include <fstream>

using namespace std;

class Logger
{
  public:
    //Constructor
    Logger();
    //Destructor
    ~Logger();
    //Used to help print all the students in the database
    void RecursiveStudentPrint(TreeNode<Student>* node);
    //Used to help print all the faculty in the database
    void RecursiveFacultyPrint(TreeNode<Faculty>* node);
    //Prints all the students in the database
    void StudentTreePrint();
    //Prints all the faculty in the database
    void FacultyTreePrint();
    //Prints a student given the ID
    void StudentPrint(int studentID);
    //Prints a faculty member given the ID
    void FacultyPrint(int facultyID);
    //Prints the faculty advisor of a student
    void FacultyPrintOfStudent(int studentID);
    //Prints all the student advisees of a faculty member
    void StudentsPrintOfFaculty(int facultyID);
    //Adds a student to the database
    void AddStudent(int studentID);
    //Removes a student from the database
    void DeleteStudent(int studentID);
    //Adds a faculty member to the database
    void AddFaculty(int facultyID);
    //Removes a faculty member from the database
    void DeleteFaculty(int facultyID);
    //Changes a student's advisor
    void ChangeAdvisor(int studentID, int style);
    //Removes an advisee from a faculty member
    void RemoveAdvisee(int facultyID);
    //Updates the trees in the database used to manage rollback
    void Update();
    //Allows the user to undo what they just did if it changed the database
    void Rollback();
    //In function to read tree from file -> loads both tree5 and current tree
    void In();
    //Out function to write a tree
    void Out();
    //Bonus functions
      //Used to help print all the students with a certain name in the database
    void RecursiveStudentPrintName(TreeNode<Student>* node, string name);
      //Prints all the students with a certain name in the database
    void StudentPrintName(string name);
      //Used to help print all the students with a certain academic level in the database
    void RecursiveStudentPrintLevel(TreeNode<Student>* node, string level);
      //Prints all the students with a certain academic level in the database
    void StudentPrintLevel(string level);
      //Used to help print all the students with a certain major in the database
    void RecursiveStudentPrintMajor(TreeNode<Student>* node, string major);
      //Prints all the students with a certain major in the database
    void StudentPrintMajor(string major);
      //Used to help print all the students with a certain GPA in the database
    void RecursiveStudentPrintGPA(TreeNode<Student>* node, double GPA);
      //Prints all the students with a certain GPA in the database
    void StudentPrintGPA(double GPA);
      //Used to help print all the students with a certain advisor in the database
    void RecursiveStudentPrintAdvisor(TreeNode<Student>* node, int advisor);
      //Prints all the students with a certain advisor in the database
    void StudentPrintAdvisor(int advisor);
      //Used to help print all the faculty with a certain name in the database
    void RecursiveFacultyPrintName(TreeNode<Faculty>* node, string name);
      //Prints all the faculty with a certain name in the database
    void FacultyPrintName(string name);
      //Used to help print all the faculty with a certain academic level in the database
    void RecursiveFacultyPrintLevel(TreeNode<Faculty>* node, string level);
      //Printss all the faculty with a certain academic level in the database
    void FacultyPrintLevel(string level);
      //Used to help print all the faculty with a certain department in the database
    void RecursiveFacultyPrintDepartment(TreeNode<Faculty>* node, string department);
      //Prints all the faculty with a certain department in the database
    void FacultyPrintDepartment(string department);
  private:
    ifstream m_input_stream;
    ofstream m_output_stream;
    bool m_has_made_change; //used to tell whether the user has made a change to the database
    int m_number_of_changes; //keeps track of the relative number of changes in the database for rollback
    BST<Faculty> m_current_faculty_tree; //tree of faculty members
    BST<Faculty> m_faculty_tree_5; //snapshot of faculty tree
    BST<Faculty> m_faculty_tree_4; //snapshot of faculty tree
    BST<Faculty> m_faculty_tree_3; //snapshot of faculty tree
    BST<Faculty> m_faculty_tree_2; //snapshot of faculty tree
    BST<Faculty> m_faculty_tree_1; //snapshot of faculty tree
    BST<Student> m_current_student_tree; //tree of students
    BST<Student> m_student_tree_5; //snapshot of student tree
    BST<Student> m_student_tree_4; //snapshot of student tree
    BST<Student> m_student_tree_3; //snapshot of student tree
    BST<Student> m_student_tree_2; //snapshot of student tree
    BST<Student> m_student_tree_1; //snapshot of student tree
    DoublyList<int> m_student_IDs; //list that keeps track of all the ID's of the students in the DB
    DoublyList<int> m_faculty_IDs; //list that keeps track of all the ID's of the faculty in the DB
    //Helper functions that insert/remove faculty/students from the list that we use to keep track of them
    void ListInsertStudent(int studentID);
    void ListRemoveStudent(int studentID);
    void ListInsertFaculty(int facultyID);
    void ListRemoveFaculty(int facultyID);
    //Variables used to customize input in the case that no students/faculty are printed for the bonus functions
    int m_students_printed;
    int m_faculty_printed;
};


//logger rollback function
//use rollback ints...
  //5 only (changes = 0)-> no rollback
  //5 and 4 (changes = 1)-> delete 4, copy 5 to curr, changes --
  //5, 4, and 3 (changes = 2) -> delete 3, copy 4 to curr, changes --
  //5, 4, 3, and 2 (changes = 3) -> delete 2, copy 3 to curr, changes --
  //5, 4, 3, 2, and 1 (changes = 4(+)) -> delete 1, copy 2 to curr, changes --
