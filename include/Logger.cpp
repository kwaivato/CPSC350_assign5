// Logger.cpp
// An implemented Logger class that will be used to manage a database of students and faculty.
// @author Vidal M. Arroyo
// @author arroy118@mail.chapman.edu
// @version 1.0

#include "Logger.h"

using namespace std;

Logger::Logger()
{
  m_number_of_changes = 0;
  m_has_made_change = false;
  m_students_printed = 0;
  m_faculty_printed = 0;
}

Logger::~Logger()
{

}

void Logger::RecursiveStudentPrint(TreeNode<Student>* node)
{
  if(node == NULL)
  {
    return;
  }
  RecursiveStudentPrint(node->left);
  node->key.PrintStudentInfo();
  cout << "\n";
  RecursiveStudentPrint(node->right);
}

void Logger::RecursiveFacultyPrint(TreeNode<Faculty>* node)
{
  if(node == NULL)
  {
    return;
  }
  RecursiveFacultyPrint(node->left);
  node->key.PrintFacultyInfo();
  cout << "\n";
  RecursiveFacultyPrint(node->right);
}

void Logger::StudentTreePrint()
{
  if(m_current_student_tree.isEmpty())
  {
    cout << "\n";
    cout << "Nothing to print! There are no students in our database." << endl;
    cout << "\n";
  }
  else
  {
    cout << "\n";
    RecursiveStudentPrint(m_current_student_tree.getRoot());
  }
}

void Logger::FacultyTreePrint()
{
  if(m_current_faculty_tree.isEmpty())
  {
    cout << "\n";
    cout << "Nothing to print! There are no faculty in our database." << endl;
    cout << "\n";
  }
  else
  {
    cout << "\n";
    RecursiveFacultyPrint(m_current_faculty_tree.getRoot());
  }
}

void Logger::StudentPrint(int studentID)
{
  Student s(studentID, "", "", "", 1.00, 0);
  if (m_current_student_tree.isEmpty())
  {
    cout << "\n";
    cout << "There are no students in our database! Please add a student before searching for them." << endl;
    cout << "\n";
  }
  else if (!(m_current_student_tree.contains(s)))
  {
    cout << "\n";
    cout << "This student is not in our database! Please add this student before searching for them." << endl;
    cout << "\n";
  }
  else if (m_current_student_tree.contains(s))
  {
    //student is in the database so we can print them
    cout << "\n";
    m_current_student_tree.getNode(s)->key.PrintStudentInfo();
    cout << "\n";
  }
}

void Logger::FacultyPrint(int facultyID)
{
  Faculty f(facultyID, "","","");
  if (m_current_faculty_tree.isEmpty())
  {
    cout << "\n";
    cout << "There are no faculty members in our database! Please add a faculty member before searching for them." << endl;
    cout << "\n";
  }
  else if (!(m_current_faculty_tree.contains(f)))
  {
    cout << "\n";
    cout << "This faculty member is not in our database! Please add this faculty member before searching for them." << endl;
    cout << "\n";
  }
  else if (m_current_faculty_tree.contains(f))
  {
    //faculty member is in the database so we can print them
    cout << "\n";
    m_current_faculty_tree.getNode(f)->key.PrintFacultyInfo();
    cout << "\n";
  }
}

void Logger::FacultyPrintOfStudent(int studentID)
{
  Student s(studentID, "", "", "", 1.00, 0);
  //check if student is there
  if (m_current_student_tree.isEmpty())
  {
    // if not -> let user know
    cout << "\n";
    cout << "There are no students in our database! Please add a student before quering information for them." << endl;
    cout << "\n";
  }
  else if (!(m_current_student_tree.contains(s)))
  {
    // if not -> let user know
    cout << "\n";
    cout << "This student is not in our database! Please add this student before quering information for them." << endl;
    cout << "\n";
  }
  else if (m_current_student_tree.contains(s))
  {
    // if yes -> proceed and print their faculty advisor
    int facultyID = m_current_student_tree.getNode(s)->key.getStudentAdvisorID();
    FacultyPrint(facultyID);
  }
}

void Logger::StudentsPrintOfFaculty(int facultyID)
{
  //check if faculty is there
  Faculty f(facultyID, "","","");
  if (m_current_faculty_tree.isEmpty())
  {
    // if not -> let user know
    cout << "\n";
    cout << "There are no faculty members in our database! Please add a faculty member before quering information for them." << endl;
    cout << "\n";
  }
  else if (!(m_current_faculty_tree.contains(f)))
  {
    // if not -> let user know
    cout << "\n";
    cout << "This faculty member is not in our database! Please add this faculty member before quering information for them." << endl;
    cout << "\n";
  }
  else if (m_current_faculty_tree.contains(f))
  {
    // if yes -> proceed and print their student advisors
    DoublyListNode<int> *curr = m_current_faculty_tree.getNode(f)->key.getFacultyAdviseeIDFront(); //equals get front
    if (m_current_faculty_tree.getNode(f)->key.hasStudents())
    {
      while (curr!= NULL)
      {
        StudentPrint(curr->m_data);
        curr = curr->next;
      }
    }
    else
    {
      cout << "\n";
      cout << "This faculty member has no advisees!" << endl;
      cout << "\n";
    }
  }
}

void Logger::ListInsertStudent(int studentID)
{
  m_student_IDs.insertBack(studentID);
}

void Logger::AddStudent(int studentID)
{
  cin.ignore();
  //get name of student
  cout << "Please enter the name of the student that you want to add: ";
  string studentName;
  getline(cin, studentName);
  //get level of student
  cout << "Please enter the academic level of the student that you want to add: ";
  string academicLevel;
  getline(cin, academicLevel);
  //get major of student
  cout << "Please enter the major of the student that you want to add: ";
  string studentMajor;
  getline(cin, studentMajor);
  //get GPA of student
  cout << "Please enter the GPA of the student that you want to add: ";
  double studentGPA;
  cin >> studentGPA;
  //get advisor ID of student
  cout << "Please enter the ID of the faculty advisor of the student that you want to add: ";
  int facultyID;
  cin >> facultyID;
  Faculty f(facultyID,"","","");
  //Is the student already in the tree?
  Student s(studentID, studentName, academicLevel, studentMajor, studentGPA, facultyID);
  if(m_current_student_tree.contains(s) == true)
  {
    // yes - don't do anything
    cout << "\n";
    cout << "There is already a student in our database with that ID! Thus, we cannot add another." << endl;
    cout << "\n";
  }
  else
  {
    // no - proceed
    //is advisor ID in faculty table?
    if (m_current_faculty_tree.isEmpty())
    {
      //no - do not add the student, let user know that they need to add a faculty advisor
      cout << "\n";
      cout << "There are no faculty members in our database! Please add a faculty member before adding a student with a faculty member as an advisor." << endl;
      cout << "\n";
    }
    else if (!(m_current_faculty_tree.contains(f)))
    {
      //no - do not add the student, let user know that they need to add a faculty advisor
      cout << "\n";
      cout << "This faculty member is not in our database! Please add this faculty member before adding a student with this faculty member as an advisor." << endl;
      cout << "\n";
    }
    else if (m_current_faculty_tree.contains(f))
    {
      //yes - add the student and add the student to the faculty's list of advisees
      m_current_faculty_tree.getNode(f)->key.addFacultyAdviseeID(studentID);
      m_current_student_tree.insert(s);
      //insert student into list for input/output
      ListInsertStudent(studentID);
      cout << "\n";
      cout << "Your student has been successfully added to our database!" << endl;
      cout << "\n";
      //trees are updated for rollback
      Update();
    }
  }
}

void Logger::ListRemoveStudent(int studentID)
{
  m_student_IDs.remove(studentID);
}

void Logger::DeleteStudent(int studentID)
{
  Student s(studentID, "", "", "", 1.00, 0);
  //Is student in tree?
  if (m_current_student_tree.isEmpty())
  {
    //no - let user know
    cout << "\n";
    cout << "There are no students in our database! Therefore, we cannot remove anyone." << endl;
    cout << "\n";
  }
  else if (!(m_current_student_tree.contains(s)))
  {
    //no - let user know
    cout << "\n";
    cout << "This student is not in our database! Therefore, we cannot remove this student." << endl;
    cout << "\n";
  }
  else if (m_current_student_tree.contains(s))
  {
    //yes - continue
    int facultyID = m_current_student_tree.getNode(s)->key.getStudentAdvisorID();
    Faculty f(facultyID,"","","");
    //is the advisor ID in faculty table?
    if (m_current_faculty_tree.isEmpty())
    {
      //no - do not add the student, let user know that they need to add a faculty advisor
      //This error will never happen because of how this program is written, but we add it here for posterity
      cout << "\n";
      cout << "There are no faculty members in our database! How did a student get an advisor ID for a faculty member that doesnt exist???" << endl;
      cout << "\n";
    }
    else if (!(m_current_faculty_tree.contains(f)))
    {
      //no - do not add the student, let user know that they need to add a faculty advisor
      //This error will never happen because of how this program is written, but we add it here for posterity
      cout << "\n";
      cout << "This faculty member is not in our database! How did a student get an advisor ID for a faculty member that doesnt exist???" << endl;
      cout << "\n";
    }
    else if (m_current_faculty_tree.contains(f))
    {
      //yes - remove the student and remove the student to the faculty's list of advisees
      m_current_faculty_tree.getNode(f)->key.removeFacultyAdviseeID(studentID);
      //remove student from list for input/output
      ListRemoveStudent(studentID);
      m_current_student_tree.deleteNode(s);
      cout << "\n";
      cout << "Your student has been successfully deleted from our database!" << endl;
      cout << "\n";
      //trees are updated for rollback
      Update();
    }
  }
}

void Logger::ListInsertFaculty(int facultyID)
{
  m_faculty_IDs.insertBack(facultyID);
}

void Logger::AddFaculty(int facultyID)
{
  cin.ignore();
  //get faculty name
  cout << "Please enter the name of the faculty member that you want to add: ";
  string facultyName;
  getline(cin, facultyName);
  //get faculty level
  cout << "Please enter the academic level of the faculty member that you want to add: ";
  string facultyLevel;
  getline(cin, facultyLevel);
  //get faculty department
  cout << "Please enter the name of the department of the faculty member that you want to add: ";
  string facultyDepartment;
  getline(cin, facultyDepartment);
  //check if already contains faculty member or does not
  Faculty f(facultyID, facultyName, facultyLevel, facultyDepartment);
  if(m_current_faculty_tree.contains(f) == true)
  {
    // yes - don't do anything
    cout << "\n";
    cout << "There is already a faculty member in our database with that ID! Thus, we cannot add another." << endl;
    cout << "\n";
  }
  else
  {
    //no -  add the faculty member, which is not yet dependent on any students
    m_current_faculty_tree.insert(f);
    ListInsertFaculty(facultyID);
    cout << "\n";
    cout << "Your faculty member has been successfully added to our database!" << endl;
    cout << "\n";
    //trees are updated for rollback
    Update();
  }
}

void Logger::ListRemoveFaculty(int facultyID)
{
  m_faculty_IDs.remove(facultyID);
}

void Logger::DeleteFaculty(int facultyID)
{
  Faculty f(facultyID, "", "", "");
  //check if faculty exists
  if (m_current_faculty_tree.isEmpty())
  {
    //no - program ends
    cout << "\n";
    cout << "There are no faculty in our database! Therefore, we cannot remove anyone." << endl;
    cout << "\n";
  }
  else if (!(m_current_faculty_tree.contains(f)))
  {
    //no - program ends
    cout << "\n";
    cout << "This faculty member is not in our database! Therefore, we cannot remove this faculty member." << endl;
    cout << "\n";
  }
  else if (m_current_faculty_tree.contains(f))
  {
    //yes - continue
    // 2 conditions
      //Condition 1: this faculty member is not the last faculty member in the tree
    if (m_current_faculty_tree.getSize() >= 2)
    {
      DoublyListNode<int>* curr1 = m_faculty_IDs.getFront();
      //finding an ID of a faculty member who we can give this student to
      while (curr1->m_data == facultyID)
      {
        curr1 = curr1->next;
      }
      //found substitute faculty member
      int newFacultyID = curr1->m_data;
      Faculty sub(newFacultyID,"","","");

      //will now move students to this other faculty member
      DoublyListNode<int> *curr = m_current_faculty_tree.getNode(f)->key.getFacultyAdviseeIDFront(); //equals get front
      while (curr!= NULL)
      {
        Student s(curr->m_data, "", "", "", 1.00, 0);
        //check if students in student list exist
        if (m_current_student_tree.contains(s) == false)
        {
          // if does not exist: don't do anything - previous faculty somehow had an advisee that's not in the list (unexplainable)
          // this error will never happen based on the way this program is wrriten
          cout << "An advisee of the faculty advisor is not in our database! How did a faculty member get an advisee ID for an advisee doesnt exist???" << endl;
        }
        else if(m_current_student_tree.contains(s) == true)
        {
          //will now move students between faculty, changing both the faculty and the student data
            //changing advisee data
          m_current_student_tree.getNode(s)->key.setStudentAdvisorID(m_current_faculty_tree.getNode(sub)->key.getFacultyID());
            //changing new advisor data
          m_current_faculty_tree.getNode(sub)->key.addFacultyAdviseeID(curr->m_data);
        }
        curr = curr->next;
      }
      //remove faculty from list used for out
      ListRemoveFaculty(facultyID);
      //faculty member has been deleted! all students with faculty member x now have faculty member y as their advisor
      cout << m_current_faculty_tree.getNode(f)->key.getFacultyLevel() << " " << m_current_faculty_tree.getNode(f)->key.getFacultyName() << " with ID " << m_current_faculty_tree.getNode(f)->key.getFacultyID() << " has been removed!" << endl;
      cout << "Now, all of "<< m_current_faculty_tree.getNode(f)->key.getFacultyName() << "'s advisees have " << m_current_faculty_tree.getNode(sub)->key.getFacultyLevel() << " " << m_current_faculty_tree.getNode(sub)->key.getFacultyName() << " with ID " << m_current_faculty_tree.getNode(sub)->key.getFacultyID() << " as their faculty advisor."<< endl;
      cout << "\n";
    }
    else
    {
      //faculty to be removed is the last node and its the root!
      //To resolve this, we will have Rene German step in and become everyone's advisor (update BOTH students and our new faculty)
          // Rene will become President, Full Professor, Football Coach, and Janitor
      cout << "It looks like the faculty member that you want to remove is the last faculty member in our database!" << endl;
      cout << "To resolve this, we will ask Rene German to step in as temporary President, Full Professor, Football Coach, and Janitor. Rene will become every student's advisor." << endl;
      Faculty f1((m_current_faculty_tree.getNode(f)->key.getFacultyID()+1), "Rene German", "President, Full Professor, Football Coach, and Janitor", "Computer Science");
      m_current_faculty_tree.insert(f1);
      //now set every student's advisor to be Rene
      DoublyListNode<int> *curr = m_current_faculty_tree.getNode(f)->key.getFacultyAdviseeIDFront(); //equals get front
      while (curr!= NULL)
      {
        Student s(curr->m_data, "", "", "", 1.00, 0);
        //check if students in student list exist
        if (m_current_student_tree.contains(s) == false)
        {
          // if does not exist: don't do anything - previous faculty somehow had an advisee that's not in the list (unexplainable)
          // this error will never happen in this program
          cout << "An advisee of the faculty advisor is not in our database! How did a faculty member get an advisee ID for an advisee doesnt exist???" << endl;
        }
        else if(m_current_student_tree.contains(s) == true)
        {
          //will now move students between faculty, changing both the faculty and the student data
            //changing advisee data
          m_current_student_tree.getNode(s)->key.setStudentAdvisorID((m_current_faculty_tree.getNode(f)->key.getFacultyID()+1));
            //changing new advisor data
          m_current_faculty_tree.getNode(f1)->key.addFacultyAdviseeID(curr->m_data);
        }
        curr = curr->next;
      }
      //remove faculty from list used for out
      ListRemoveFaculty(facultyID);
      //faculty member has been deleted! all students with faculty member x now have faculty member y as their advisor
      ListInsertFaculty(m_current_faculty_tree.getNode(f)->key.getFacultyID()+1);
      cout << "Thanks Rene!" << endl;
      cout << "\n";
    }
    m_current_faculty_tree.deleteNode(f);
    //trees are updated for rollback
    Update();
  }
}

void Logger::ChangeAdvisor(int studentID, int style)
{
  Student s(studentID, "", "", "", 1.00, 0);
  //check if student is in database
  if (m_current_student_tree.isEmpty())
  {
    //it not, let user know
    cout << "\n";
    cout << "There are no students in our database! Therefore, we cannot change anyone's advisor." << endl;
    cout << "\n";
  }
  else if (!(m_current_student_tree.contains(s)))
  {
    //it not, let user know
    cout << "\n";
    cout << "This student is not in our database! Therefore, we cannot change this student's advisor." << endl;
    cout << "\n";
  }
  else if (m_current_student_tree.contains(s))
  {
    //yes - continue
    cout << "It looks like you want change the student's advisor from the advisor with ID " << m_current_student_tree.getNode(s)->key.getStudentAdvisorID() << endl;
    //style variable is used to customize output depending on whether the user chose 11 and 12
    if (style == 0)
    {
      cout << "We will see if this advisor is in our database." << endl;
    }
    Faculty f1(m_current_student_tree.getNode(s)->key.getStudentAdvisorID(),"","","");
    //does the faculty member exist in the database?
    if (m_current_faculty_tree.contains(f1) != true)
    {
      //no - let the user know
      cout << "It looks like the previous advisor of the student is not in the data base! That shouldn't happen..." << endl;
    }
    else if (m_current_faculty_tree.contains(f1) == true)
    {
      //yes - do the switch
      //if int = 0
      if (style == 0)
      {
        cout << "Success! We found the old advisor." << endl;
      }
      cout << "Please provide the ID of the new advisor for the student: ";
      int facultyID;
      cin >> facultyID;
      Faculty f2(facultyID,"","","");
      //does the second advisor exist in the DB?
      if (m_current_faculty_tree.contains(f2) != true)
      {
        //if not, let user know so they can add them
        cout << "\n";
        cout << "It looks like you want to give a student an advisor that is not in our database." << endl;
        cout << "Please add this faculty member to the database before giving this faculty member an advisee." << endl;
        cout << "\n";
      }
      else if (m_current_faculty_tree.contains(f2) == true)
      {
        //yes they do - let's do some switching!
        cout << "\n";
        cout << "Great! It looks like we have everything set. We will change the student's faculty advisor now." << endl;
        cout << "\n";
        //if so, then update!
        //change student's advisor
        m_current_student_tree.getNode(s)->key.setStudentAdvisorID(facultyID);
        //remove student from old faculty member's advisee list
        m_current_faculty_tree.getNode(f1)->key.removeFacultyAdviseeID(studentID);
        //insert student into new faculty member advisee list
        m_current_faculty_tree.getNode(f2)->key.addFacultyAdviseeID(studentID);
        //trees are updated for rollback
        Update();
      }
    }
  }
}

void Logger::RemoveAdvisee(int facultyID)
{
  Faculty f(facultyID,"","","");
  //check if faculty member is in the tree
  if (!m_current_faculty_tree.contains(f))
  {
    //if no, let the user know
    cout << "\n";
    cout << "It looks like the faculty member that you want to remove an advisee from is not in our database! Therefore, we can't do anything for you." << endl;
    cout << "\n";
  }
  else if (m_current_faculty_tree.contains(f))
  {
    //if yes, continue
    //prompt for student id and check if faculty member has this student
    cout << "Please provide the ID of the student that you want to remove from this faculty member: ";
    int studentID;
    cin >> studentID;
    //check for advisee
    if (m_current_faculty_tree.getNode(f)->key.hasStudents() == false)
    {
      //faculty has no advisees so we don't do anything
      cout << "\n";
      cout << "This faculty member has no student advisees! Therefore, we can't do anything for you." << endl;
      cout << "\n";
    }
    else if (m_current_faculty_tree.getNode(f)->key.hasStudent(studentID) == false)
    {
      //faculty does not have this student
      cout << "\n";
      cout << "This faculty member is not advising the student for which you provided an ID for! Therefore, we can't do anything for you." << endl;
      cout << "\n";
    }
    else if (m_current_faculty_tree.getNode(f)->key.hasStudent(studentID) == true)
    {
      //faculty has student -> continue
      Student s0(studentID, "", "", "", 1.00, 0);
      //is the student contained in the tree?
      if (m_current_student_tree.isEmpty() == true)
      {
        //will never happen because of how the program is written
        cout << "\n";
        cout << "There are no students in our database! That's odd..." << endl;
        cout << "\n";
      }
      else if (!m_current_student_tree.contains(s0))
      {
        //will never happen because of how the program is written
        cout << "\n";
        cout << "This student is not in our database! That's odd..." << endl;
        cout << "\n";
      }
      else if(m_current_student_tree.contains(s0))
      {
        //if yes, do 11 with known student ID
        //1 is used to customize output
        ChangeAdvisor(studentID,1);
      }
    }
  }
}

//update function is only called when a change has occured in the trees
void Logger::Update()
{
  //assuming that current trees have been updated.
  if (m_number_of_changes == 0)
  {
    //take a snapshot of the trees
    m_faculty_tree_4.clear();
    m_faculty_tree_4 = m_current_faculty_tree;
    m_student_tree_4.clear();
    m_student_tree_4 = m_current_student_tree;
    // a change has happened so we increase
    m_number_of_changes++;
    //bool will help us with rollback output
    m_has_made_change = true;
  }
  else if (m_number_of_changes == 1)
  {
    //take a snapshot of the trees
    m_faculty_tree_3.clear();
    m_faculty_tree_3 = m_current_faculty_tree;
    m_student_tree_3.clear();
    m_student_tree_3 = m_current_student_tree;
    m_number_of_changes++;
  }
  else if (m_number_of_changes == 2)
  {
    //take a snapshot of the trees
    m_faculty_tree_2.clear();
    m_faculty_tree_2 = m_current_faculty_tree;
    m_student_tree_2.clear();
    m_student_tree_2 = m_current_student_tree;
    m_number_of_changes++;
  }
  else if (m_number_of_changes == 3)
  {
    //take a snapshot of the trees
    m_faculty_tree_1.clear();
    m_faculty_tree_1 = m_current_faculty_tree;
    m_student_tree_1.clear();
    m_student_tree_1 = m_current_student_tree;
    m_number_of_changes++;
  }
  else if (m_number_of_changes == 4)
  {
    //take a snapshot but we will also replace trees to make sure we have the 5 latest trees for history.
    m_faculty_tree_5.clear();
    m_faculty_tree_5 = m_faculty_tree_4;
    m_faculty_tree_4.clear();
    m_faculty_tree_4 = m_faculty_tree_3;
    m_faculty_tree_3.clear();
    m_faculty_tree_3 = m_faculty_tree_2;
    m_faculty_tree_2.clear();
    m_faculty_tree_2 = m_faculty_tree_1;
    m_faculty_tree_1.clear();
    m_faculty_tree_1 = m_current_faculty_tree;
    m_student_tree_5.clear();
    m_student_tree_5 = m_student_tree_4;
    m_student_tree_4.clear();
    m_student_tree_4 = m_student_tree_3;
    m_student_tree_3.clear();
    m_student_tree_3 = m_student_tree_2;
    m_student_tree_2.clear();
    m_student_tree_2 = m_student_tree_1;
    m_student_tree_1.clear();
    m_student_tree_1 = m_current_student_tree;
  }
}

void Logger::Rollback()
{
  //no changes so no rollback
  if (m_number_of_changes == 0 && m_has_made_change == false)
  {
    cout << "Since you have not changed the database, we cannot rollback!" << endl;
  }
  //max number of rollback changes
  else if (m_number_of_changes == 0 && m_has_made_change == true)
  {
    cout << "You cannot rollback any further! We only allow the last 5 steps." << endl;
  }
  else if (m_number_of_changes == 1)
  {
    //only one change so we move back
    m_current_faculty_tree.clear();
    m_current_faculty_tree = m_faculty_tree_5;
    m_current_student_tree.clear();
    m_current_student_tree = m_student_tree_5;
    m_number_of_changes--;
    cout << "Your rollback was successful!" << endl;
  }
  else if (m_number_of_changes == 2)
  {
    //move back trees for 2 changes
    m_current_faculty_tree.clear();
    m_current_faculty_tree = m_faculty_tree_4;
    m_current_student_tree.clear();
    m_current_student_tree = m_student_tree_4;
    m_number_of_changes--;
    cout << "Your rollback was successful!" << endl;
  }
  else if (m_number_of_changes == 3)
  {
    //move back trees for 3 changes
    m_current_faculty_tree.clear();
    m_current_faculty_tree = m_faculty_tree_3;
    m_current_student_tree.clear();
    m_current_student_tree = m_student_tree_3;
    m_number_of_changes--;
    cout << "Your rollback was successful!" << endl;
  }
  else if (m_number_of_changes == 4)
  {
    //move back trees for 4+ changes. We did not do more than 4 because we would get rollback errors
    m_current_faculty_tree.clear();
    m_current_faculty_tree = m_faculty_tree_2;
    m_current_student_tree.clear();
    m_current_student_tree = m_student_tree_2;
    m_number_of_changes--;
    cout << "Your rollback was successful!" << endl;
  }
}

void Logger::In()
{
  m_input_stream.open("studentTable.txt");
  if (m_input_stream.fail())
  {
    cout << "\n";
    cout << "It looks like there was no previous student database. We will create one after this program finishes!" << endl;
  }
  else
  {
    int numberOfStudents;
    m_input_stream >> numberOfStudents;
    if (numberOfStudents == 0)
    {
      //we can't read anything because there are no students
    }
    else
    {
      int studentID;
      string studentName;
      string studentLevel;
      string studentMajor;
      double studentGPA;
      int studentAdvisorID;
      for (int i = 0; i < numberOfStudents; ++i)
      {
        //read students and insert them into the BST
        m_input_stream >> studentID;
        m_input_stream.ignore();
        getline(m_input_stream,studentName);
        getline(m_input_stream,studentLevel);
        getline(m_input_stream,studentMajor);
        m_input_stream >> studentGPA;
        m_input_stream >> studentAdvisorID;
        Student S(studentID, studentName, studentLevel, studentMajor, studentGPA, studentAdvisorID);
        //add to tree
        m_current_student_tree.insert(S);
        //add to list
        m_student_IDs.insertBack(studentID);
      }
    }
    cout << "\n";
    cout << "The previous student database has been loaded!" << endl;
  }
  m_student_tree_5 = m_current_student_tree;
  m_input_stream.close();

  m_input_stream.open("facultyTable.txt");
  if (m_input_stream.fail())
  {
    cout << "It looks like there was no previous faculty database. We will create one after this program finishes!" << endl;
    cout << "\n";
  }
  else
  {
    int numberOfFaculty;
    m_input_stream >> numberOfFaculty;
    if (numberOfFaculty == 0)
    {
      //we can't read anything because there are no faculty members
    }
    else
    {
      int facultyID;
      string facultyName;
      string facultyLevel;
      string facultyDepartment;
      int numberOfFacultyAdvisees;
      int adviseeID;
      for (int i = 0; i < numberOfFaculty; ++i)
      {
        m_input_stream >> facultyID;
        m_input_stream.ignore();
        getline(m_input_stream,facultyName);
        getline(m_input_stream,facultyLevel);
        getline(m_input_stream,facultyDepartment);
        Faculty F(facultyID,facultyName,facultyLevel,facultyDepartment);
        m_input_stream >> numberOfFacultyAdvisees;
        if (numberOfFacultyAdvisees == 0)
        {
          //no student ID's - the next number will be the next faculty's ID number
        }
        else
        {
          //add all the ID's of the student advisees
          for (int j = 0; j < numberOfFacultyAdvisees; ++j)
          {
            m_input_stream >> adviseeID;
            F.addFacultyAdviseeID(adviseeID);
          }
        }
        //add to tree
        m_current_faculty_tree.insert(F);
        //add to list
        m_faculty_IDs.insertBack(facultyID);
      }
    }
    cout << "The previous faculty database has been loaded!" << endl;
    cout << "\n";
  }
  m_faculty_tree_5 = m_current_faculty_tree;
  m_input_stream.close();
}

void Logger::Out()
{
  //need to know size of BST's and size of faculty LL's
    //solved with LinkedList

  //first write studentFile
  //studentTable.txt
  m_output_stream.open("studentTable.txt");
  m_output_stream << m_current_student_tree.getSize() << endl;
  if (m_current_student_tree.isEmpty() == true)
  {
    //this is an empty tree so we don't want to write anything else
  }
  else if (m_current_student_tree.isEmpty() == false)
  {
    DoublyListNode<int>* curr1 = m_student_IDs.getFront();
    int currentStudentID;
    //size must be dependent on BST because it is just too hard to keep track of size when rollback is taken into account
    for (int i = 0; i < m_current_student_tree.getSize(); ++i)
    {
      //get ID from LinkedList
      currentStudentID = curr1->m_data;
      Student S(currentStudentID, "", "", "", 1.00, 1);
      //search for student in BST from LinkedList
      //print everything for them
      m_output_stream << m_current_student_tree.getNode(S)->key.getStudentID() << endl;
      m_output_stream << m_current_student_tree.getNode(S)->key.getStudentName() << endl;
      m_output_stream << m_current_student_tree.getNode(S)->key.getStudentLevel() << endl;
      m_output_stream << m_current_student_tree.getNode(S)->key.getStudentMajor() << endl;
      m_output_stream << m_current_student_tree.getNode(S)->key.getStudentGPA() << endl;
      m_output_stream << m_current_student_tree.getNode(S)->key.getStudentAdvisorID() << endl;
      curr1 = curr1->next;
    }
  }
  m_output_stream.close();

  //then write facultyFile
  //facultyTable.txt
  m_output_stream.open("facultyTable.txt");
  m_output_stream << m_current_faculty_tree.getSize() << endl;
  if (m_current_faculty_tree.isEmpty() == true)
  {
    //this is an empty tree so we don't want to write anything else
  }
  else if (m_current_faculty_tree.isEmpty() == false)
  {
    DoublyListNode<int>* curr2 = m_faculty_IDs.getFront();
    int currentFacultyID;
    //size must be dependent on BST because it is just too hard to keep track of size when rollback is taken into account
    for (int i = 0; i < m_current_faculty_tree.getSize(); ++i)
    {
      //get ID from LinkedList
      currentFacultyID = curr2->m_data;
      Faculty F(currentFacultyID, "", "", "");
      //search for faculty in BST from LinkedList
      //print everything for them
      m_output_stream << m_current_faculty_tree.getNode(F)->key.getFacultyID() << endl;
      m_output_stream << m_current_faculty_tree.getNode(F)->key.getFacultyName() << endl;
      m_output_stream << m_current_faculty_tree.getNode(F)->key.getFacultyLevel() << endl;
      m_output_stream << m_current_faculty_tree.getNode(F)->key.getFacultyDepartment() << endl;
      m_output_stream << m_current_faculty_tree.getNode(F)->key.getNumberOfFacultyAdvisees() << endl;
      if (m_current_faculty_tree.getNode(F)->key.getNumberOfFacultyAdvisees() == 0)
      {
        //do nothing
      }
      else
      {
        //write all their students' id's
        DoublyListNode<int> *curr3 = m_current_faculty_tree.getNode(F)->key.getFacultyAdviseeIDFront();
        for (int j = 0; j < m_current_faculty_tree.getNode(F)->key.getNumberOfFacultyAdvisees(); ++j)
        {
          m_output_stream << curr3->m_data << endl;
          curr3 = curr3->next;
        }
      }
      curr2 = curr2->next;
    }
  }
  m_output_stream.close();
}

//The Bonus methods all adopt the same structure as the RecursiveFacultyPrint and RecursiveStudentPrint methods along with the StudentTreePrint and FacultyTreePrint methods.
//The only difference is that these bonus methods have if statements to ensure we're only printing out students/faculty with the parameters we want

void Logger::RecursiveStudentPrintName(TreeNode<Student>* node, string name)
{
  if(node == NULL)
  {
    return;
  }
  RecursiveStudentPrintName(node->left, name);
  if (node->key.getStudentName() == name)
  {
    node->key.PrintStudentInfo();
    m_students_printed++;
    cout << "\n";
  }
  RecursiveStudentPrintName(node->right, name);
}

void Logger::StudentPrintName(string name)
{
  m_students_printed = 0;
  RecursiveStudentPrintName(m_current_student_tree.getRoot(), name);
  if (m_students_printed == 0)
  {
    cout << "It looks like there were no students in our data base with the name " << name << "!" << endl;
    cout << "\n";
  }
}

void Logger::RecursiveStudentPrintLevel(TreeNode<Student>* node, string level)
{
  if(node == NULL)
  {
    return;
  }
  RecursiveStudentPrintLevel(node->left, level);
  if (node->key.getStudentLevel() == level)
  {
    node->key.PrintStudentInfo();
    m_students_printed++;
    cout << "\n";
  }
  RecursiveStudentPrintLevel(node->right, level);
}

void Logger::StudentPrintLevel(string level)
{
  m_students_printed = 0;
  RecursiveStudentPrintLevel(m_current_student_tree.getRoot(), level);
  if (m_students_printed == 0)
  {
    cout << "It looks like there were no students in our data base with the academic level of " << level << "!" << endl;
    cout << "\n";
  }
}

void Logger::RecursiveStudentPrintMajor(TreeNode<Student>* node, string major)
{
  if(node == NULL)
  {
    return;
  }
  RecursiveStudentPrintMajor(node->left, major);
  if (node->key.getStudentMajor() == major)
  {
    node->key.PrintStudentInfo();
    m_students_printed++;
    cout << "\n";
  }
  RecursiveStudentPrintMajor(node->right, major);
}

void Logger::StudentPrintMajor(string major)
{
  m_students_printed = 0;
  RecursiveStudentPrintMajor(m_current_student_tree.getRoot(), major);
  if (m_students_printed == 0)
  {
    cout << "It looks like there were no students in our data base with the " << major << " major!" << endl;
    cout << "\n";
  }
}

void Logger::RecursiveStudentPrintGPA(TreeNode<Student>* node, double GPA)
{
  if(node == NULL)
  {
    return;
  }
  RecursiveStudentPrintGPA(node->left, GPA);
  if (node->key.getStudentGPA() == GPA)
  {
    node->key.PrintStudentInfo();
    m_students_printed++;
    cout << "\n";
  }
  RecursiveStudentPrintGPA(node->right, GPA);
}

void Logger::StudentPrintGPA(double GPA)
{
  m_students_printed = 0;
  RecursiveStudentPrintGPA(m_current_student_tree.getRoot(), GPA);
  if (m_students_printed == 0)
  {
    cout << "It looks like there were no students in our data base with a GPA of " << GPA << "!" << endl;
    cout << "\n";
  }
}

void Logger::RecursiveStudentPrintAdvisor(TreeNode<Student>* node, int advisor)
{
  if(node == NULL)
  {
    return;
  }
  RecursiveStudentPrintAdvisor(node->left, advisor);
  if (node->key.getStudentAdvisorID() == advisor)
  {
    node->key.PrintStudentInfo();
    m_students_printed++;
    cout << "\n";
  }
  RecursiveStudentPrintAdvisor(node->right, advisor);
}

void Logger::StudentPrintAdvisor(int advisor)
{
  m_students_printed = 0;
  RecursiveStudentPrintAdvisor(m_current_student_tree.getRoot(), advisor);
  if (m_students_printed == 0)
  {
    cout << "It looks like there were no students in our data base with an advisor with an ID " << advisor << "!" << endl;
    cout << "\n";
  }
}

void Logger::RecursiveFacultyPrintName(TreeNode<Faculty>* node, string name)
{
  if(node == NULL)
  {
    return;
  }
  RecursiveFacultyPrintName(node->left, name);
  if (node->key.getFacultyName() == name)
  {
    node->key.PrintFacultyInfo();
    m_faculty_printed++;
    cout << "\n";
  }
  RecursiveFacultyPrintName(node->right, name);
}

void Logger::FacultyPrintName(string name)
{
  m_faculty_printed = 0;
  RecursiveFacultyPrintName(m_current_faculty_tree.getRoot(),name);
  if (m_faculty_printed == 0)
  {
    cout << "It looks like there were no faculty in our data base with the name " << name << "!" << endl;
    cout << "\n";
  }
}

void Logger::RecursiveFacultyPrintLevel(TreeNode<Faculty>* node, string level)
{
  if(node == NULL)
  {
    return;
  }
  RecursiveFacultyPrintLevel(node->left, level);
  if (node->key.getFacultyLevel() == level)
  {
    node->key.PrintFacultyInfo();
    m_faculty_printed++;
    cout << "\n";
  }
  RecursiveFacultyPrintLevel(node->right, level);
}

void Logger::FacultyPrintLevel(string level)
{
  m_faculty_printed = 0;
  RecursiveFacultyPrintLevel(m_current_faculty_tree.getRoot(),level);
  if (m_faculty_printed == 0)
  {
    cout << "It looks like there were no faculty in our data base with the academic level of " << level << "!" << endl;
    cout << "\n";
  }
}

void Logger::RecursiveFacultyPrintDepartment(TreeNode<Faculty>* node, string department)
{
  if(node == NULL)
  {
    return;
  }
  RecursiveFacultyPrintDepartment(node->left, department);
  if (node->key.getFacultyDepartment() == department)
  {
    node->key.PrintFacultyInfo();
    m_faculty_printed++;
    cout << "\n";
  }
  RecursiveFacultyPrintDepartment(node->right, department);
}

void Logger::FacultyPrintDepartment(string department)
{
  m_faculty_printed = 0;
  RecursiveFacultyPrintDepartment(m_current_faculty_tree.getRoot(),department);
  if (m_faculty_printed == 0)
  {
    cout << "It looks like there were no faculty in our data base associated with the " << department << " department!" << endl;
    cout << "\n";
  }
}
