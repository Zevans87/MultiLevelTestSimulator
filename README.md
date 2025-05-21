# MultiLevelTestSimulator
Programming Fundamentals II – College Assignment

Project Overview - This C++ program was created to simulate a multi-level testing system for students. This was created while at UHV for Programming Fundamentals II.
This program incorporates dynamic memory management, file I/O, arrays, vectors, and functions. It uses text documents (provided by the professor) to evaluate
each students performance and track their progression across multiple test levels.

Objectives of the program - Simulate a series of tests by automatically generating random test keys and answers. These are then graded and based on predefined thresholds
the student will either advance to the next level or not. Finally, the results are stored and displayed.

Features of the program -
  * Reads student names frome the input file named "SP23_HW1.txt".
  * Four levels of testing : * Level 1: 10 questions - advance with greater or equal to 50%.
                             * Level 2: 40 questions - advance with greater or equal to 20%.
                             * Level 3: 100 questions - dynamically determines size of level 4.
                             * Level 4: Number of questions = 10% of the score from level 3.
  * Outputs the test results to the file named "SP23_HW1_GradeReport.txt".
  * Tracks and displays the students progression by using vectors.
  * Demonstrates the use of : * Dynamic Memory Allocation
                              * Random Number Generation
                              * Conditional Logic
                              * File Streams and Loops

Files - 
  * Main source code : ProgrammingAssignment1.cpp
  * Input file with the students names which is required to run the program : SP23_HW1.txt
  * Output file that is automatically generated to store the students results : SP23_HW1_GradeReport.txt

How to Run -
  * Ensure that the file "SP23_HW1.txt" exists in the same directory.
  * Use a C++ compiler to compile the program.
  * Follow the on-screen prompts to enter the number of students.
