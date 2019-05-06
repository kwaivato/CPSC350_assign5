# CPSC350_assign5

(Header) Name: Vidal Arroyo, ID: 2253413, Email: arroy118@mail.chapman.edu, Class: CPSC 350-01, Assignment: Assignment 5

(Brief Overview)
i. BST.cpp: a node-based binary search tree (BST) class, supplemented with additional variables and methods for improved functionality.
ii. DoublyList.cpp: a node-based doubly-linked list class, supplemented with additional variables and methods for improved functionality.
iii. Faculty.cpp: an implemented faculty class that will be used to manage a database of students and faculty.
iv. Faculty.h: a declared faculty class that will be used to manage a database of students and faculty.
v. ListEmpty.cpp: an error class used to handle cases of an empty list.
vi. Logger.cpp: an implemented Logger class that will be used to manage a database of students and faculty.
vii. Logger.h: a declared Logger class that will be used to manage a database of students and faculty.
viii. main.cpp: main function for a student/faculty a database.
ix. Menu.cpp: an implemented menu class that will be used to manage a database of students and faculty.
x. Menu.h: a declared menu class that will be used to manage a database of students and faculty.
xi. RuntimeException.cpp: a parent error class that can be implemented for a given need.
xii. Student.cpp: an implemented Student class that will be used to manage a database of students and faculty.
xiii. Student.h: a declared Student class that will be used to manage a database of students and faculty.

(Inline Comments) To run the programs in Docker using g++, type the following commands: 1) g++ *.cpp -o assign5 2) ./assign5 [FileName]

(EASTER EGG) To see the Easter egg I wrote in the program, try to delete the last faculty member in the database WHILE that last faculty member has at least one advisee in the student tree.

(Other Notes) I used inspiration from the following sources for the following topics:
1) BST destructor: https://stackoverflow.com/questions/34170164/destructor-for-binary-search-tree
2) Formatting cout output: https://www.youtube.com/watch?v=6MsGZw_2hjs
3) Const functions: https://stackoverflow.com/questions/5973427/error-passing-xxx-as-this-argument-of-xxx-discards-qualifiers
4) Taking input w/ multiple strings: https://stackoverflow.com/questions/16029829/entering-multiple-strings-c
5) Clearinng the cin buffer: http://www.cplusplus.com/forum/beginner/88917/
