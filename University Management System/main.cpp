#include <fstream>
#include <iostream>
#include <cstdlib>
#include <iomanip>


using namespace std;

// --------------------------------------------------
// COLOR FUNCTION
// --------------------------------------------------
void setColor(int color) {
  if (color == 7)       cout << "\033[0m";   // Default
  else if (color == 3)  cout << "\033[36m";  // Cyan
  else if (color == 10) cout << "\033[32m";  // Green
  else if (color == 12) cout << "\033[31m";  // Red
  else if (color == 14) cout << "\033[33m";  // Yellow
  else cout << "\033[0m";
}
// --------------------------------------------------
// FILE HANDLING
// --------------------------------------------------

void saveUser(string uN, string uP, string uR) {
  fstream file;
  file.open("Users.txt", ios::app);
  if (file.is_open()) {
    file << uN << " " << uP << " " << uR << endl; // Storing in File
    file.close();
  }
}
void loadUsers(string userName[], string userPassword[], string userRole[],
               int &userCount) {
  fstream file;
  file.open("Users.txt", ios::in);
  if (file.is_open()) {
    userCount = 0;
    string uN, uP, uR;
    while (file >> uN >> uP >> uR) // Loading from File
    {
      userName[userCount] = uN;
      userPassword[userCount] = uP;
      userRole[userCount] = uR;
      userCount++;
    }
    file.close(); // Closing file
  }
}

void rewriteUsers(string userName[], string userPassword[], string userRole[],
                  int userCount) {
  fstream file;
  file.open("Users.txt", ios::out);
  if (file.is_open()) {
    for (int i = 0; i < userCount; i++) {
      file << userName[i] << " " << userPassword[i] << " " << userRole[i] << endl;
    }
    file.close();
  }
}

void saveStudent(string studentName, int studentRoll, string studentDepartment,
                 string studentClass, int studentFeeAmount, bool studentFeePaid,
                 bool studentHostelrequired, string HostelName, int hostelRoom,
                 string studentUserName, string temppassword) {

  fstream file;
  file.open("Students.txt", ios::app);
  if (file.is_open()) {
    file << studentUserName << " " << temppassword << " " << studentName << " "
         << studentRoll << " " << studentDepartment << " " << studentClass
         << " " << studentFeePaid << " " << studentFeeAmount << " "
         << studentHostelrequired << " "; // Storing

    if (studentHostelrequired) {
      file << HostelName << " " << hostelRoom;
    }

    file << endl;
    file.close();
  }
}
void loadStudents(string studentName[], int studentRoll[],
                  string studentDepartment[], string studentClass[],
                  int studentFeeAmount[], bool studentFeePaid[],
                  bool studentHostelRequired[], string HostelName[],
                  int hostelRoom[], bool hostelAllocated[],
                  string studentUserName[], int &studentCount,
                  string temppassword[]) {

  fstream file;
  file.open("Students.txt", ios::in); // Read mode
  if (file.is_open()) {
    studentCount = 0;
    while (file >> studentUserName[studentCount] >>
           temppassword[studentCount] >> studentName[studentCount] >>
           studentRoll[studentCount] >> studentDepartment[studentCount] >>
           studentClass[studentCount] >> studentFeePaid[studentCount] >>
           studentFeeAmount[studentCount] >>
           studentHostelRequired[studentCount]) // Loading
    {
      if (studentHostelRequired[studentCount]) {
        file >> HostelName[studentCount] >> hostelRoom[studentCount];
        hostelAllocated[studentCount] = true;
      } else {
        HostelName[studentCount] = "N/A";
        hostelRoom[studentCount] = -1;
        hostelAllocated[studentCount] = false;
      }

      studentCount++;
    }
  }
}

void saveFeedback(string fb) {
  fstream file;
  file.open("Feedback.txt", ios::app);
  if (file.is_open()) {
    file << fb << endl;
    file.close();
  }
}

void loadFeedback(string feedback[], int &feedbackCount) {
  fstream file;
  file.open("Feedback.txt", ios::in);
  if (file.is_open()) {
    feedbackCount = 0;
    while (getline(file, feedback[feedbackCount])) {
      feedbackCount++;
    }
    file.close();
  }
}

void saveGrade(string username, string subject, int creditHours, float gradePoint) {
  fstream file;
  file.open("Grades.txt", ios::app);
  if (file.is_open()) {
    file << username << " " << subject << " " << creditHours << " " << gradePoint << endl;
    file.close();
  }
}

void loadGrades(string gradeUsername[], string gradeSubject[],
                int gradeCreditHours[], float gradePoint[], int &gradeCount) {
  fstream file;
  file.open("Grades.txt", ios::in);
  if (file.is_open()) {
    gradeCount = 0;
    while (file >> gradeUsername[gradeCount] >> gradeSubject[gradeCount] >>
           gradeCreditHours[gradeCount] >> gradePoint[gradeCount]) {
      gradeCount++;
    }
    file.close();
  }
}

void saveExam(string subject, string date) {
  fstream file;
  file.open("Exams.txt", ios::app);
  if (file.is_open()) {
    file << subject << " " << date << endl;
    file.close();
  }
}

void loadExams(string examSubject[], string examDate[], int &examCount) {
  fstream file;
  file.open("Exams.txt", ios::in);
  if (file.is_open()) {
    examCount = 0;
    while (file >> examSubject[examCount] >> examDate[examCount]) {
      examCount++;
    }
    file.close();
  }
}

void saveNotice(string notice) {
  fstream file;
  file.open("Notices.txt", ios::app);
  if (file.is_open()) {
    file << notice << endl;
    file.close();
  }
}

void loadNotices(string notices[], int &noticeCount) {
  fstream file;
  file.open("Notices.txt", ios::in);
  if (file.is_open()) {
    noticeCount = 0;
    while (getline(file, notices[noticeCount])) {
      noticeCount++;
    }
    file.close();
  }
}

// -------------------------------------------------
// HEADER & DISPLAY FUNCTIONS
// --------------------------------------------------
void printLine(char ch, int len) {
  for (int i = 0; i < len; i++) cout << ch;
  cout << endl;
}

void printCentered(string text, int width) {
  int padding = (width - text.length()) / 2;
  if (padding < 0) padding = 0;
  for (int i = 0; i < padding; i++) cout << " ";
  cout << text << endl;
}

void printheader() {
  system("clear");
  setColor(10);
  cout << "    +================================================+" << endl;
  cout << "    |                                                |" << endl;
  cout << "    |        UNIVERSITY MANAGEMENT SYSTEM            |" << endl;
  cout << "    |                                                |" << endl;
  cout << "    +================================================+" << endl;
  setColor(7);
  cout << endl;
}

void printMenuHeader(string main, string sub) {
  setColor(3);
  cout << "    +------------------------------------------------+" << endl;
  string nav = "  " + main + "  >  " + sub;
  cout << "    |" << left << setw(48) << nav << "|" << endl;
  cout << "    +------------------------------------------------+" << endl;
  setColor(7);
  cout << endl;
}

void printSectionTitle(string title) {
  setColor(14);
  cout << "    -- " << title << " ";
  for (int i = 0; i < (int)(40 - title.length()); i++) cout << "-";
  cout << endl;
  setColor(7);
}

void clearScreen() {
  cout << "\nPress Enter to continue...";
  cin.ignore();
  cin.get();
  system("clear");
}

// --------------------------------------------------
// AUTHENTICATION
// --------------------------------------------------
// Modified signUp function - prevents multiple admins
bool signUp(string userName[], string userPassword[], string userRole[],
            int &userCount, string uN, string uP, string uR) {
  // Check if username already exists
  for (int i = 0; i < userCount; i++) {
    if (userName[i] == uN) {
      return false;
    }
  }

  // Prevent creating multiple admin accounts
  if (uR == "Admin") {
    for (int i = 0; i < userCount; i++) {
      if (userRole[i] == "Admin") {
        cout << "\nAdmin already exists! Only one admin is allowed.\n";
        return false;
      }
    }
  }

  userName[userCount] = uN;
  userPassword[userCount] = uP;
  userRole[userCount] = uR;
  userCount++;

  saveUser(uN, uP, uR);
  return true;
}

void initializeDefaultAdmin(string userName[], string userPassword[],
                            string userRole[], int &userCount) {
  // Check if admin already exists
  bool adminExists = false;
  for (int i = 0; i < userCount; i++) {
    if (userRole[i] == "Admin") {
      adminExists = true;
      break;
    }
  }

  // If no admin exists, prompt admin to sign up
  if (!adminExists) {
    printheader();
    setColor(14);
    cout << "    +================================================+" << endl;
    cout << "    |       FIRST TIME SETUP - ADMIN SIGNUP          |" << endl;
    cout << "    +================================================+" << endl;
    setColor(7);
    cout << endl;
    cout << "    No admin account found. Please create one." << endl;
    cout << endl;

    string adminUser, adminPass, adminPassConfirm;

    cout << "    Enter Admin Username : ";
    cin >> adminUser;
    cout << "    Enter Admin Password : ";
    cin >> adminPass;
    cout << "    Confirm Password     : ";
    cin >> adminPassConfirm;

    while (adminPass != adminPassConfirm) {
      setColor(12);
      cout << "\n    Passwords do not match! Try again.\n" << endl;
      setColor(7);
      cout << "    Enter Admin Password : ";
      cin >> adminPass;
      cout << "    Confirm Password     : ";
      cin >> adminPassConfirm;
    }

    userName[userCount] = adminUser;
    userPassword[userCount] = adminPass;
    userRole[userCount] = "Admin";
    saveUser(adminUser, adminPass, "Admin");
    userCount++;

    setColor(10);
    cout << endl;
    cout << "    [*] Admin account created successfully!" << endl;
    cout << "    Username: " << adminUser << endl;
    setColor(7);
    cout << "\n    Press Enter to continue...";
    cin.ignore();
    cin.get();
  }
}
string signInAdmin(string userName[], string userPassword[], string userRole[],
                   int userCount, string uN, string uP) {
  for (int i = 0; i < userCount; i++) {
    if (userName[i] == uN && userPassword[i] == uP && userRole[i] == "Admin") {
      return "Admin";
    }
  }
  return "Invalid";
}

string signInStudent(string userName[], string userPassword[],
                     string userRole[], int userCount, string uN, string uP) {
  for (int i = 0; i < userCount; i++) {
    if (userName[i] == uN && userPassword[i] == uP &&
        userRole[i] == "Student") {
      return "Student";
    }
  }
  return "Invalid";
}

// --------------------------------------------------
// STUDENT HELPERS
// --------------------------------------------------
int findStudent(string studentUserName[], int studentCount, string username) {
  for (int i = 0; i < studentCount; i++) {
    if (studentUserName[i] == username) // Check if current Username matches
    {
      return i;
    }
  }
  return -1;
}

// --------------------------------------------------
// STUDENT MANAGEMENT FUNCTIONS
// --------------------------------------------------
void addStudent(string studentName[], int studentRoll[],
                string studentDepartment[], string studentClass[],
                int studentFeeAmount[], bool studentFeePaid[],
                bool studentHostelRequired[], string HostelName[],
                int hostelRoom[], bool hostelAllocated[],
                string studentUserName[], int &studentCount, string userName[],
                string userPassword[], string userRole[], int &userCount) {
  int i = studentCount;
  cout << "Enter Username: ";
  getline(cin >> ws, studentUserName[i]);
  string temppassword;
  cin.ignore();
  cout << "\nEnter the Name of Student : ";
  getline(cin, studentName[i]);

  cout << "Enter the password for student : ";
  getline(cin >> ws, temppassword);

  userName[userCount] = studentUserName[i];
  userPassword[userCount] = temppassword;
  userRole[userCount] = "Student";

  saveUser(studentUserName[i], temppassword, "Student");
  userCount++;

  cout << "Enter Roll No of Student : ";
  cin >> studentRoll[i];

  cout << "Enter Department of Student : ";
  cin >> studentDepartment[i];

  cout << "Enter Class of Student : ";
  cin >> studentClass[i];

  cout << "Fee Paid (1 for Yes and 0 for No): ";
  cin >> studentFeePaid[i];

  cout << "Enter the Fee Amount: ";
  cin >> studentFeeAmount[i];

  cout << "Hostel Required (1 for Yes and 0 for No): ";
  cin >> studentHostelRequired[i];

  if (studentHostelRequired[i] == true) {
    cin.ignore();
    cout << "Enter Hostel Name: ";
    getline(cin, HostelName[i]);

    cout << "Enter the Room No: ";
    cin >> hostelRoom[i];
    hostelAllocated[i] = true;
  } else {
    HostelName[i] = "N/A";
    hostelRoom[i] = -1;
    hostelAllocated[i] = false;
  }

  cout << "\nStudent Added Successfully\n";
  saveStudent(studentName[i], studentRoll[i], studentDepartment[i],
              studentClass[i], studentFeeAmount[i], studentFeePaid[i],
              studentHostelRequired[i], HostelName[i], hostelRoom[i],
              studentUserName[i], temppassword);
  studentCount++;
}

void viewStudents(string studentName[], int studentRoll[],
                  string studentDepartment[], string studentClass[],
                  int totalClasses[], int attendedClasses[], int studentCount) {
  for (int i = 0; i < studentCount; i++) {
    float percentage = 0;
    if (totalClasses[i] > 0) {
      percentage = (attendedClasses[i] * 100.0) / totalClasses[i];
    }
    cout << "\n-----------------------------------\n";
    cout << "Name       : " << studentName[i] << endl;
    cout << "Roll No    : " << studentRoll[i] << endl;
    cout << "Department : " << studentDepartment[i] << endl;
    cout << "Class      : " << studentClass[i] << endl;
    cout << "Attendance : " << percentage << "%\n";
  }
}

void updateStudent(string studentName[], int studentRoll[],
                   string studentDepartment[], string studentClass[],
                   int studentFeeAmount[], bool studentFeePaid[],
                   bool studentHostelRequired[], string HostelName[],
                   int hostelRoom[], bool hostelAllocated[], int studentCount) {
  int roll;
  bool found = false;
  cout << "Enter Roll No to Update: ";
  cin >> roll;

  for (int i = 0; i < studentCount; i++) {
    if (studentRoll[i] == roll) {
      found = true;

      cin.ignore();

      cout << "Enter Name of new Student : ";
      getline(cin, studentName[i]);

      cout << "Enter the Department of student : ";
      getline(cin, studentDepartment[i]);

      cout << "Enter the Class of Student : ";
      getline(cin, studentClass[i]);
      cout << "Fee Paid (1 for Yes and 0 for No): ";
      cin >> studentFeePaid[i];

      cout << "Enter the Fee Amount: ";
      cin >> studentFeeAmount[i];

      cout << "Hostel Required (1 for Yes and 0 for No): ";
      cin >> studentHostelRequired[i];

      if (studentHostelRequired[i] == true) {
        cin.ignore();

        cout << "Enter the Hostel Name: ";
        getline(cin, HostelName[i]);
        cout << "Room No: ";
        cin >> hostelRoom[i];
        hostelAllocated[i] = true;
      } else {
        HostelName[i] = "N/A";
        hostelRoom[i] = -1;
        hostelAllocated[i] = false;
      }

      cout << "\nStudent Updated Successfully\n";
      break;
    }
  }

  if (!found) {
    cout << "\nStudent Not Found\n";
  }
}

void deleteStudent(string studentName[], int studentRoll[],
                   string studentDepartment[], string studentClass[],
                   int studentFeeAmount[], bool studentFeePaid[],
                   bool studentHostelRequired[], string HostelName[],
                   int hostelRoom[], bool hostelAllocated[],
                   string studentUserName[], int &studentCount) {
  int roll;
  bool found = false;
  cout << "Enter Roll No to Delete: ";
  cin >> roll;

  for (int i = 0; i < studentCount; i++) {
    if (studentRoll[i] == roll) {
      found = true;
      for (int j = i; j < studentCount - 1; j++) {
        studentName[j] = studentName[j + 1];
        studentRoll[j] = studentRoll[j + 1];
        studentDepartment[j] = studentDepartment[j + 1];
        studentClass[j] = studentClass[j + 1];
        studentFeeAmount[j] = studentFeeAmount[j + 1];
        studentFeePaid[j] = studentFeePaid[j + 1];
        studentHostelRequired[j] = studentHostelRequired[j + 1];
        HostelName[j] = HostelName[j + 1];
        hostelRoom[j] = hostelRoom[j + 1];
        hostelAllocated[j] = hostelAllocated[j + 1];
        studentUserName[j] = studentUserName[j + 1];
      }
      studentCount--;
      cout << "\nStudent Deleted Successfully\n";
      break;
    }
  }

  if (!found) {
    cout << "\nStudent Not Found\n";
  }
}

// --------------------------------------------------
// SEARCH STUDENT
// --------------------------------------------------
void searchStudent(string studentName[], int studentRoll[],
                   string studentDepartment[], string studentClass[],
                   int studentCount) {
  int searchChoice;
  cout << "Search by:\n";
  cout << "1. Roll No\n";
  cout << "2. Name\n";
  cout << "Enter choice: ";
  cin >> searchChoice;

  if (searchChoice == 1) {
    int roll;
    cout << "Enter Roll No: ";
    cin >> roll;
    bool found = false;
    for (int i = 0; i < studentCount; i++) {
      if (studentRoll[i] == roll) {
        found = true;
        cout << "\n------- Student Found -------\n";
        cout << "Name       : " << studentName[i] << endl;
        cout << "Roll No    : " << studentRoll[i] << endl;
        cout << "Department : " << studentDepartment[i] << endl;
        cout << "Class      : " << studentClass[i] << endl;
        break;
      }
    }
    if (!found) cout << "\nStudent Not Found\n";
  } else if (searchChoice == 2) {
    string name;
    cout << "Enter Name: ";
    cin >> name;
    bool found = false;
    for (int i = 0; i < studentCount; i++) {
      if (studentName[i] == name) {
        found = true;
        cout << "\n------- Student Found -------\n";
        cout << "Name       : " << studentName[i] << endl;
        cout << "Roll No    : " << studentRoll[i] << endl;
        cout << "Department : " << studentDepartment[i] << endl;
        cout << "Class      : " << studentClass[i] << endl;
      }
    }
    if (!found) cout << "\nStudent Not Found\n";
  } else {
    cout << "\nInvalid Choice\n";
  }
}

// --------------------------------------------------
// ATTENDANCE & FEEDBACK
// --------------------------------------------------
void markAttendance(int studentRoll[], int totalClasses[],
                    int attendedClasses[], int studentCount) {
  int roll;
  cout << "Enter Roll No: ";
  cin >> roll;

  for (int i = 0; i < studentCount; i++) {
    if (studentRoll[i] == roll) {
      int choice;
      cout << "1. Press 1 to mark as Present\n";
      cout << "2. Press 2 to mark as Absent\n";
      cin >> choice;

      totalClasses[i]++;
      if (choice == 1)
        attendedClasses[i]++;
      cout << "Attendance Marked\n";
      return;
    }
  }
  cout << "Student Not Found\n";
}

void submitFeedback(string feedback[], int &feedbackCount, string user) {
  cin.ignore();
  cout << "Enter Feedback: ";
  getline(cin, feedback[feedbackCount]);

  feedback[feedbackCount] = user + " : " + feedback[feedbackCount];

  saveFeedback(feedback[feedbackCount]);
  feedbackCount++;

  cout << "Feedback Submitted\n";
}

void viewFeedback(string feedback[], int feedbackCount) {
  if (feedbackCount == 0) {
    cout << "No feedback available.\n";
    return;
  }
  for (int i = 0; i < feedbackCount; i++) {
    cout << i + 1 << ". " << feedback[i] << endl;
  }
}

// --------------------------------------------------
// CLEAR FEEDBACK
// --------------------------------------------------
void clearFeedback(string feedback[], int &feedbackCount) {
  fstream file;
  file.open("Feedback.txt", ios::out);
  if (file.is_open()) {
    file.close();
  }
  feedbackCount = 0;
  setColor(14);
  cout << "\nAll feedback has been cleared!\n";
  setColor(7);
}

// --------------------------------------------------
// CGPA FUNCTIONS
// --------------------------------------------------
float gradeToPoint(char grade) {
  if (grade == 'A' || grade == 'a') return 4.0;
  if (grade == 'B' || grade == 'b') return 3.0;
  if (grade == 'C' || grade == 'c') return 2.0;
  if (grade == 'D' || grade == 'd') return 1.0;
  return 0.0; // F or invalid
}

void addGrade(int studentRoll[], string studentUserName[], int studentCount,
              string gradeUsername[], string gradeSubject[],
              int gradeCreditHours[], float gradePoint[], int &gradeCount) {
  int roll;
  cout << "Enter Roll No of Student: ";
  cin >> roll;

  int idx = -1;
  for (int i = 0; i < studentCount; i++) {
    if (studentRoll[i] == roll) {
      idx = i;
      break;
    }
  }

  if (idx == -1) {
    cout << "\nStudent Not Found\n";
    return;
  }

  string subject;
  int credits;
  char grade;

  cout << "Enter Subject Name: ";
  cin >> subject;
  cout << "Enter Credit Hours: ";
  cin >> credits;
  cout << "Enter Grade (A/B/C/D/F): ";
  cin >> grade;

  float gp = gradeToPoint(grade);

  gradeUsername[gradeCount] = studentUserName[idx];
  gradeSubject[gradeCount] = subject;
  gradeCreditHours[gradeCount] = credits;
  gradePoint[gradeCount] = gp;

  saveGrade(studentUserName[idx], subject, credits, gp);
  gradeCount++;

  cout << "\nGrade Added Successfully! (" << grade << " = " << gp << " points)\n";
}

void viewCGPA(string gradeUsername[], string gradeSubject[],
              int gradeCreditHours[], float gradePoint[], int gradeCount,
              string username) {
  float totalPoints = 0;
  int totalCredits = 0;
  int subjectCount = 0;

  cout << "\n---------- Grade Report ----------\n";
  for (int i = 0; i < gradeCount; i++) {
    if (gradeUsername[i] == username) {
      cout << gradeSubject[i] << "  |  Credits: " << gradeCreditHours[i]
           << "  |  Grade Point: " << gradePoint[i] << endl;
      totalPoints += gradePoint[i] * gradeCreditHours[i];
      totalCredits += gradeCreditHours[i];
      subjectCount++;
    }
  }

  if (subjectCount == 0) {
    cout << "No grades found.\n";
  } else {
    float cgpa = totalPoints / totalCredits;
    cout << "----------------------------------\n";
    cout << "Total Subjects : " << subjectCount << endl;
    cout << "Total Credits  : " << totalCredits << endl;
    setColor(14);
    cout << "CGPA           : " << cgpa << " / 4.0\n";
    setColor(7);
  }
}

// --------------------------------------------------
// VIEW STUDENT GRADES (ADMIN - by roll)
// --------------------------------------------------
void viewStudentGrades(int studentRoll[], string studentUserName[],
                       int studentCount, string gradeUsername[],
                       string gradeSubject[], int gradeCreditHours[],
                       float gradePoint[], int gradeCount) {
  int roll;
  cout << "Enter Roll No of Student: ";
  cin >> roll;

  int idx = -1;
  for (int i = 0; i < studentCount; i++) {
    if (studentRoll[i] == roll) {
      idx = i;
      break;
    }
  }

  if (idx == -1) {
    cout << "\nStudent Not Found\n";
    return;
  }

  viewCGPA(gradeUsername, gradeSubject, gradeCreditHours, gradePoint,
           gradeCount, studentUserName[idx]);
}

// --------------------------------------------------
// ATTENDANCE WARNING
// --------------------------------------------------
void viewAttendanceWithWarning(int totalClasses[], int attendedClasses[],
                               int idx) {
  float percentage = 0;
  if (totalClasses[idx] > 0)
    percentage = (attendedClasses[idx] * 100.0) / totalClasses[idx];

  cout << "Total Classes    : " << totalClasses[idx] << endl;
  cout << "Classes Attended : " << attendedClasses[idx] << endl;
  cout << "Attendance       : " << percentage << "%\n";

  if (totalClasses[idx] > 0 && percentage < 75.0) {
    setColor(12); // Red
    cout << "\n** WARNING: Your attendance is below 75%! **\n";
    cout << "** You may not be allowed to sit in exams. **\n";
    setColor(7);
  } else if (totalClasses[idx] > 0) {
    setColor(10); // Green
    cout << "\nAttendance is satisfactory.\n";
    setColor(7);
  }
}

// --------------------------------------------------
// FEE RECEIPT
// --------------------------------------------------
void viewFeeReceipt(string studentName[], int studentRoll[],
                    string studentDepartment[], int studentFeeAmount[],
                    bool studentFeePaid[], int idx) {
  cout << "\n============================================\n";
  setColor(14);
  cout << "          UNIVERSITY FEE RECEIPT\n";
  setColor(7);
  cout << "============================================\n";
  cout << "  Name       : " << studentName[idx] << endl;
  cout << "  Roll No    : " << studentRoll[idx] << endl;
  cout << "  Department : " << studentDepartment[idx] << endl;
  cout << "  Fee Amount : Rs. " << studentFeeAmount[idx] << endl;
  cout << "--------------------------------------------\n";
  if (studentFeePaid[idx]) {
    setColor(10);
    cout << "  Status     : ** PAID **\n";
  } else {
    setColor(12);
    cout << "  Status     : ** UNPAID **\n";
  }
  setColor(7);
  cout << "============================================\n";
}

// --------------------------------------------------
// EXAM SCHEDULE
// --------------------------------------------------
void addExam(string examSubject[], string examDate[], int &examCount) {
  cout << "Enter Subject Name: ";
  cin >> examSubject[examCount];
  cout << "Enter Exam Date (DD/MM/YYYY): ";
  cin >> examDate[examCount];

  saveExam(examSubject[examCount], examDate[examCount]);
  examCount++;

  cout << "\nExam Schedule Added Successfully!\n";
}

void viewExamSchedule(string examSubject[], string examDate[], int examCount) {
  if (examCount == 0) {
    cout << "No exam schedule available.\n";
    return;
  }
  cout << "\n---------- Exam Schedule ----------\n";
  for (int i = 0; i < examCount; i++) {
    cout << i + 1 << ". " << examSubject[i] << "  |  Date: " << examDate[i] << endl;
  }
  cout << "-----------------------------------\n";
}

// --------------------------------------------------
// ANNOUNCEMENTS / NOTICES
// --------------------------------------------------
void postNotice(string notices[], int &noticeCount) {
  cin.ignore();
  cout << "Enter Announcement: ";
  getline(cin, notices[noticeCount]);

  saveNotice(notices[noticeCount]);
  noticeCount++;

  cout << "\nAnnouncement Posted Successfully!\n";
}

void viewNotices(string notices[], int noticeCount) {
  if (noticeCount == 0) {
    cout << "No announcements available.\n";
    return;
  }
  setColor(14);
  cout << "\n========== ANNOUNCEMENTS ==========\n";
  setColor(7);
  for (int i = noticeCount - 1; i >= 0; i--) {
    cout << "  " << noticeCount - i << ". " << notices[i] << endl;
  }
  cout << "===================================\n";
}

// --------------------------------------------------
// MERIT LIST (sorted by CGPA)
// --------------------------------------------------
void viewMeritList(string studentName[], int studentRoll[],
                   string studentUserName[], int studentCount,
                   string gradeUsername[], int gradeCreditHours[],
                   float gradePoint[], int gradeCount) {
  if (studentCount == 0) {
    cout << "No students available.\n";
    return;
  }

  // Calculate CGPA for each student
  float cgpaList[100];
  for (int i = 0; i < studentCount; i++) {
    float totalPoints = 0;
    int totalCredits = 0;
    for (int j = 0; j < gradeCount; j++) {
      if (gradeUsername[j] == studentUserName[i]) {
        totalPoints += gradePoint[j] * gradeCreditHours[j];
        totalCredits += gradeCreditHours[j];
      }
    }
    if (totalCredits > 0)
      cgpaList[i] = totalPoints / totalCredits;
    else
      cgpaList[i] = 0.0;
  }

  // Create index array for sorting (don't modify original)
  int sortedIdx[100];
  for (int i = 0; i < studentCount; i++) sortedIdx[i] = i;

  // Bubble sort by CGPA (descending)
  for (int i = 0; i < studentCount - 1; i++) {
    for (int j = 0; j < studentCount - i - 1; j++) {
      if (cgpaList[sortedIdx[j]] < cgpaList[sortedIdx[j + 1]]) {
        int temp = sortedIdx[j];
        sortedIdx[j] = sortedIdx[j + 1];
        sortedIdx[j + 1] = temp;
      }
    }
  }

  setColor(14);
  cout << "\n============ MERIT LIST ============\n";
  setColor(7);
  cout << "Rank  Name            Roll   CGPA\n";
  cout << "------------------------------------\n";
  for (int i = 0; i < studentCount; i++) {
    int s = sortedIdx[i];
    cout << " " << i + 1 << ".    " << studentName[s]
         << "\t\t" << studentRoll[s] << "\t" << cgpaList[s] << endl;
  }
  cout << "====================================\n";
}

// --------------------------------------------------
// DEPARTMENT-WISE STUDENT COUNT
// --------------------------------------------------
void viewDepartmentCount(string studentDepartment[], int studentCount) {
  if (studentCount == 0) {
    cout << "No students available.\n";
    return;
  }

  string departments[100];
  int deptCount[100] = {0};
  int totalDepts = 0;

  for (int i = 0; i < studentCount; i++) {
    bool found = false;
    for (int j = 0; j < totalDepts; j++) {
      if (departments[j] == studentDepartment[i]) {
        deptCount[j]++;
        found = true;
        break;
      }
    }
    if (!found) {
      departments[totalDepts] = studentDepartment[i];
      deptCount[totalDepts] = 1;
      totalDepts++;
    }
  }

  setColor(14);
  cout << "\n===== Department-wise Student Count =====\n";
  setColor(7);
  for (int i = 0; i < totalDepts; i++) {
    cout << "  " << departments[i] << " : " << deptCount[i] << " students\n";
  }
  cout << "  --------------------------\n";
  cout << "  Total : " << studentCount << " students\n";
  cout << "=========================================\n";
}

// --------------------------------------------------
// CHANGE PASSWORD
// --------------------------------------------------
void changePassword(string userName[], string userPassword[], string userRole[],
                    int userCount, string currentUser) {
  string oldPass, newPass, confirmPass;

  cout << "Enter Current Password: ";
  cin >> oldPass;

  int idx = -1;
  for (int i = 0; i < userCount; i++) {
    if (userName[i] == currentUser) {
      idx = i;
      break;
    }
  }

  if (idx == -1) {
    cout << "\nUser not found!\n";
    return;
  }

  if (userPassword[idx] != oldPass) {
    setColor(12);
    cout << "\nIncorrect current password!\n";
    setColor(7);
    return;
  }

  cout << "Enter New Password: ";
  cin >> newPass;
  cout << "Confirm New Password: ";
  cin >> confirmPass;

  if (newPass != confirmPass) {
    setColor(12);
    cout << "\nPasswords do not match!\n";
    setColor(7);
    return;
  }

  userPassword[idx] = newPass;
  rewriteUsers(userName, userPassword, userRole, userCount);

  setColor(10);
  cout << "\nPassword Changed Successfully!\n";
  setColor(7);
}

// --------------------------------------------------
// MENUS
// --------------------------------------------------
int adminMenu() {
  int op;
  cout << "    +================================================+" << endl;
  cout << "    |            ADMIN CONTROL PANEL                  |" << endl;
  cout << "    +================================================+" << endl;
  cout << "    |                                                 |" << endl;
  setColor(3);
  cout << "    |   STUDENT MANAGEMENT                            |" << endl;
  setColor(7);
  cout << "    |    1.  Add New Student                          |" << endl;
  cout << "    |    2.  View All Students                        |" << endl;
  cout << "    |    3.  Search Student                           |" << endl;
  cout << "    |    4.  Update Student                           |" << endl;
  cout << "    |    5.  Delete Student                           |" << endl;
  cout << "    |                                                 |" << endl;
  setColor(3);
  cout << "    |   ACADEMICS                                     |" << endl;
  setColor(7);
  cout << "    |    6.  Mark Attendance                          |" << endl;
  cout << "    |    7.  Add Student Grade                        |" << endl;
  cout << "    |    8.  View Student Grades                      |" << endl;
  cout << "    |    9.  Merit List                               |" << endl;
  cout << "    |    10. Department-wise Count                    |" << endl;
  cout << "    |    11. Add Exam Schedule                        |" << endl;
  cout << "    |                                                 |" << endl;
  setColor(3);
  cout << "    |   COMMUNICATION                                 |" << endl;
  setColor(7);
  cout << "    |    12. Post Announcement                        |" << endl;
  cout << "    |    13. View Feedback                            |" << endl;
  cout << "    |    14. Clear All Feedback                       |" << endl;
  cout << "    |                                                 |" << endl;
  setColor(3);
  cout << "    |   ACCOUNT                                       |" << endl;
  setColor(7);
  cout << "    |    15. Change Password                          |" << endl;
  setColor(12);
  cout << "    |    16. Logout                                   |" << endl;
  setColor(7);
  cout << "    |                                                 |" << endl;
  cout << "    +================================================+" << endl;
  cout << endl;
  cout << "    Enter Option : ";
  cin >> op;
  return op;
}

int studentMenu() {
  int op;
  cout << "    +================================================+" << endl;
  cout << "    |             STUDENT DASHBOARD                   |" << endl;
  cout << "    +================================================+" << endl;
  cout << "    |                                                 |" << endl;
  setColor(3);
  cout << "    |   MY INFO                                       |" << endl;
  setColor(7);
  cout << "    |    1.  View Profile                             |" << endl;
  cout << "    |    2.  View Attendance                          |" << endl;
  cout << "    |    3.  Fee Receipt                              |" << endl;
  cout << "    |    4.  Hostel Information                       |" << endl;
  cout << "    |    5.  View CGPA                                |" << endl;
  cout << "    |                                                 |" << endl;
  setColor(3);
  cout << "    |   UNIVERSITY                                    |" << endl;
  setColor(7);
  cout << "    |    6.  View Exam Schedule                       |" << endl;
  cout << "    |    7.  View Announcements                       |" << endl;
  cout << "    |    8.  Submit Feedback                          |" << endl;
  cout << "    |                                                 |" << endl;
  setColor(3);
  cout << "    |   ACCOUNT                                       |" << endl;
  setColor(7);
  cout << "    |    9.  Change Password                          |" << endl;
  setColor(12);
  cout << "    |    10. Logout                                   |" << endl;
  setColor(7);
  cout << "    |                                                 |" << endl;
  cout << "    +================================================+" << endl;
  cout << endl;
  cout << "    Enter Option : ";
  cin >> op;
  return op;
}

// --------------------------------------------------
// ADMIN INTERFACE
// --------------------------------------------------
void adminInterface(string studentName[], int studentRoll[],
                    string studentDepartment[], string studentClass[],
                    int studentFeeAmount[], bool studentFeePaid[],
                    bool studentHostelRequired[], string HostelName[],
                    int hostelRoom[], bool hostelAllocated[],
                    string studentUserName[], int &studentCount,
                    string userName[], string userPassword[], string userRole[],
                    int &userCount, int totalClasses[], int attendedClasses[],
                    string feedback[], int &feedbackCount,
                    string gradeUsername[], string gradeSubject[],
                    int gradeCreditHours[], float gradePoint[], int &gradeCount,
                    string examSubject[], string examDate[], int &examCount,
                    string notices[], int &noticeCount,
                    string currentUser) {
  int option = 0;
  while (option != 16) {
    printheader();
    printMenuHeader("Admin Panel", "Dashboard");
    option = adminMenu();

    if (option == 1) {
      addStudent(studentName, studentRoll, studentDepartment, studentClass,
                 studentFeeAmount, studentFeePaid, studentHostelRequired,
                 HostelName, hostelRoom, hostelAllocated, studentUserName,
                 studentCount, userName, userPassword, userRole, userCount);
    } else if (option == 2) {
      viewStudents(studentName, studentRoll, studentDepartment, studentClass,
                   totalClasses, attendedClasses, studentCount);
    } else if (option == 3) {
      searchStudent(studentName, studentRoll, studentDepartment, studentClass,
                    studentCount);
    } else if (option == 4) {
      updateStudent(studentName, studentRoll, studentDepartment, studentClass,
                    studentFeeAmount, studentFeePaid, studentHostelRequired,
                    HostelName, hostelRoom, hostelAllocated, studentCount);
    } else if (option == 5) {
      deleteStudent(studentName, studentRoll, studentDepartment, studentClass,
                    studentFeeAmount, studentFeePaid, studentHostelRequired,
                    HostelName, hostelRoom, hostelAllocated, studentUserName,
                    studentCount);
    } else if (option == 6) {
      markAttendance(studentRoll, totalClasses, attendedClasses, studentCount);
    } else if (option == 7) {
      addGrade(studentRoll, studentUserName, studentCount, gradeUsername,
               gradeSubject, gradeCreditHours, gradePoint, gradeCount);
    } else if (option == 8) {
      viewStudentGrades(studentRoll, studentUserName, studentCount,
                        gradeUsername, gradeSubject, gradeCreditHours,
                        gradePoint, gradeCount);
    } else if (option == 9) {
      viewMeritList(studentName, studentRoll, studentUserName, studentCount,
                    gradeUsername, gradeCreditHours, gradePoint, gradeCount);
    } else if (option == 10) {
      viewDepartmentCount(studentDepartment, studentCount);
    } else if (option == 11) {
      addExam(examSubject, examDate, examCount);
    } else if (option == 12) {
      postNotice(notices, noticeCount);
    } else if (option == 13) {
      viewFeedback(feedback, feedbackCount);
    } else if (option == 14) {
      clearFeedback(feedback, feedbackCount);
    } else if (option == 15) {
      changePassword(userName, userPassword, userRole, userCount, currentUser);
    }
    clearScreen();
  }
}

// --------------------------------------------------
// STUDENT INTERFACE
// --------------------------------------------------
void studentInterface(string studentName[], int studentRoll[],
                      string studentDepartment[], string studentClass[],
                      int studentFeeAmount[], bool studentFeePaid[],
                      bool studentHostelRequired[], string HostelName[],
                      int hostelRoom[], bool hostelAllocated[],
                      string studentUserName[], int &studentCount,
                      int totalClasses[], int attendedClasses[],
                      string feedback[], int &feedbackCount,
                      string currentUser,
                      string gradeUsername[], string gradeSubject[],
                      int gradeCreditHours[], float gradePoint[], int gradeCount,
                      string examSubject[], string examDate[], int examCount,
                      string notices[], int noticeCount,
                      string userName[], string userPassword[], string userRole[], int userCount) {
  int option = 0;
  int idx = findStudent(studentUserName, studentCount, currentUser);
  if (idx == -1) {
    cout << "\nNo Student Found...";
    clearScreen();
    return;
  }

  // Show announcements on login
  if (noticeCount > 0) {
    setColor(14);
    cout << "\n** New Announcements Available! Check option 7. **\n";
    setColor(7);
  }

  while (option != 10) {
    printheader();
    printMenuHeader("Student Panel", currentUser);
    option = studentMenu();

    if (option == 1) {
      cout << "Name       : " << studentName[idx] << endl;
      cout << "Roll No    : " << studentRoll[idx] << endl;
      cout << "Department : " << studentDepartment[idx] << endl;
      cout << "Class      : " << studentClass[idx] << endl;
    } else if (option == 2) {
      viewAttendanceWithWarning(totalClasses, attendedClasses, idx);
    } else if (option == 3) {
      viewFeeReceipt(studentName, studentRoll, studentDepartment,
                     studentFeeAmount, studentFeePaid, idx);
    } else if (option == 4) {
      if (studentHostelRequired[idx] == true) {
        cout << "Hostel Name : " << HostelName[idx] << endl;
        cout << "Room No     : " << hostelRoom[idx] << endl;
      } else {
        cout << "No Hostel Allocated\n";
      }
    } else if (option == 5) {
      viewCGPA(gradeUsername, gradeSubject, gradeCreditHours, gradePoint,
               gradeCount, currentUser);
    } else if (option == 6) {
      viewExamSchedule(examSubject, examDate, examCount);
    } else if (option == 7) {
      viewNotices(notices, noticeCount);
    } else if (option == 8) {
      submitFeedback(feedback, feedbackCount, currentUser);
    } else if (option == 9) {
      changePassword(userName, userPassword, userRole, userCount, currentUser);
    }
    clearScreen();
  }
}

// --------------------------------------------------
// MAIN FUNCTION
// --------------------------------------------------
int main() {
  // LOCAL ARRAYS --->

  string studentName[100], studentDepartment[100], studentClass[100],
      studentUserName[100], HostelName[100], temppassword[100];
  int studentRoll[100], studentFeeAmount[100], hostelRoom[100],
      totalClasses[100] = {0}, attendedClasses[100] = {0};
  bool studentFeePaid[100], studentHostelRequired[100], hostelAllocated[100];
  int studentCount = 0;

  string feedback[100];
  int feedbackCount = 0;

  string userName[100], userPassword[100], userRole[100];
  int userCount = 0;

  string gradeUsername[500], gradeSubject[500];
  int gradeCreditHours[500];
  float gradePoint[500];
  int gradeCount = 0;

  string examSubject[100], examDate[100];
  int examCount = 0;

  string notices[100];
  int noticeCount = 0;

  // LOADING DATA FROM FILES --->

  loadUsers(userName, userPassword, userRole, userCount);
  loadStudents(studentName, studentRoll, studentDepartment, studentClass,
               studentFeeAmount, studentFeePaid, studentHostelRequired,
               HostelName, hostelRoom, hostelAllocated, studentUserName,
               studentCount, temppassword);
  loadFeedback(feedback, feedbackCount);
  loadGrades(gradeUsername, gradeSubject, gradeCreditHours, gradePoint, gradeCount);
  loadExams(examSubject, examDate, examCount);
  loadNotices(notices, noticeCount);

  initializeDefaultAdmin(userName, userPassword, userRole, userCount);

  int choice = 0;
  while (choice != 3) {
    printheader();
    printMenuHeader("Main Menu", "Login");
    cout << "    +================================================+" << endl;
    cout << "    |                 LOGIN MENU                     |" << endl;
    cout << "    +================================================+" << endl;
    cout << "    |                                                 |" << endl;
    cout << "    |    1.  Sign In as Admin                         |" << endl;
    cout << "    |    2.  Sign In as Student                       |" << endl;
    setColor(12);
    cout << "    |    3.  Exit                                     |" << endl;
    setColor(7);
    cout << "    |                                                 |" << endl;
    cout << "    +================================================+" << endl;
    cout << endl;
    cout << "    Enter Choice : ";
    cin >> choice;

    if (choice == 1) {
      string u, p;
      cout << "Enter Admin Username: ";
      cin >> u;
      cout << "Enter Admin Password: ";
      cin >> p;
      if (signInAdmin(userName, userPassword, userRole, userCount, u, p) ==
          "Admin") {
        cout << "Admin Login Successfull\n";
        clearScreen();
        adminInterface(studentName, studentRoll, studentDepartment,
                       studentClass, studentFeeAmount, studentFeePaid,
                       studentHostelRequired, HostelName, hostelRoom,
                       hostelAllocated, studentUserName, studentCount, userName,
                       userPassword, userRole, userCount, totalClasses,
                       attendedClasses, feedback, feedbackCount,
                       gradeUsername, gradeSubject, gradeCreditHours,
                       gradePoint, gradeCount,
                       examSubject, examDate, examCount,
                       notices, noticeCount, u);
      } else {
        cout << "Invalid Admin Credentials\n";
        clearScreen();
      }
    } else if (choice == 2) {
      string u, p;
      cout << "Enter Student Username: ";
      cin >> u;
      cout << "\nEnter Student Password: ";
      cin >> p;
      if (signInStudent(userName, userPassword, userRole, userCount, u, p) ==
          "Student") {
        cout << "Student Login Successfull\n";
        clearScreen();
        studentInterface(
            studentName, studentRoll, studentDepartment, studentClass,
            studentFeeAmount, studentFeePaid, studentHostelRequired, HostelName,
            hostelRoom, hostelAllocated, studentUserName, studentCount,
            totalClasses, attendedClasses, feedback, feedbackCount, u,
            gradeUsername, gradeSubject, gradeCreditHours, gradePoint,
            gradeCount,
            examSubject, examDate, examCount,
            notices, noticeCount,
            userName, userPassword, userRole, userCount);
      } else {
        cout << "Invalid Student Credentials\n";
        clearScreen();
      }
    } else if (choice == 3) {
      cout << "THANKS FOR USING OUR SOFTWARE!!\n";
      return 0;
    }
  }
}
