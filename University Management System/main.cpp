#include <conio.h>
#include <fstream>
#include <iostream>
#include <windows.h>


using namespace std;

// --------------------------------------------------
// COLOR FUNCTION
// --------------------------------------------------
void setColor(int color) {
  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
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

// -------------------------------------------------
// HEADER FUNCTIONS
// --------------------------------------------------
void printheader() {
  system("cls");
  setColor(10);
  cout << "==============================================\n";
  cout << "||        UNIVERSITY MANAGEMENT SYSTEM      ||\n";
  cout << "==============================================\n";
  setColor(7);
}

void printMenuHeader(string main, string sub) {
  setColor(3);
  cout << "----------------------------------------------\n";
  cout << " " << main << "  >  " << sub << endl;
  cout << "----------------------------------------------\n\n";
  setColor(7);
}

void clearScreen() {
  cout << "\nPress any key to continue...";
  getch();
  system("cls");
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

  // If no admin exists, create default admin
  if (!adminExists) {
    userName[userCount] = "admin";
    userPassword[userCount] = "admin123";
    userRole[userCount] = "Admin";
    saveUser("admin", "admin123", "Admin");
    userCount++;
    cout << "Default Admin Created!\n";
    cout << "Username: admin\n";
    cout << "Password: admin123\n";
    cout << "Please change the password after first login.\n";
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
  for (int i = 0; i < feedbackCount; i++) {
    cout << i + 1 << ". " << feedback[i] << endl;
  }
}

// --------------------------------------------------
// MENUS
// --------------------------------------------------
int adminMenu() {
  int op;
  cout << "---------------------------------------------\n";
  cout << "|               ADMIN PANEL                 |\n";
  cout << "---------------------------------------------\n";
  cout << "|  1. Press 1 to Add New Student            |\n";
  cout << "|  2. Press 2 to View All Students          |\n";
  cout << "|  3. Press 3 to Update Student             |\n";
  cout << "|  4. Press 4 to Delete Student             |\n";
  cout << "|  5. Press 5 to mark Attendance            |\n";
  cout << "|  6. Press 6 to View Feedback              |\n";
  cout << "|  7. Press 7 to Logout                     |\n";
  cout << "---------------------------------------------\n";
  cout << "Enter Option : ";
  cin >> op;
  return op;
}

int studentMenu() {
  int op;
  cout << "----------------------------------------------\n";
  cout << "|            STUDENT DASHBOARD               |\n";
  cout << "----------------------------------------------\n";
  cout << "|  1. Press 1 to view Profile                |\n";
  cout << "|  2. Press 2 to View Attendance             |\n";
  cout << "|  3. Press 3 to Check Fee Status            |\n";
  cout << "|  4. Press 4 to Hostel Information          |\n";
  cout << "|  5. Press 5 to Submit Feedback             |\n";
  cout << "|  6. Press 6 to Logout                      |\n";
  cout << "----------------------------------------------\n";
  cout << "Enter Option : ";
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
                    string feedback[], int &feedbackCount) {
  int option = 0;
  while (option != 7) {
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
      updateStudent(studentName, studentRoll, studentDepartment, studentClass,
                    studentFeeAmount, studentFeePaid, studentHostelRequired,
                    HostelName, hostelRoom, hostelAllocated, studentCount);
    } else if (option == 4) {
      deleteStudent(studentName, studentRoll, studentDepartment, studentClass,
                    studentFeeAmount, studentFeePaid, studentHostelRequired,
                    HostelName, hostelRoom, hostelAllocated, studentUserName,
                    studentCount);
    } else if (option == 5) {
      markAttendance(studentRoll, totalClasses, attendedClasses, studentCount);
    } else if (option == 6) {
      viewFeedback(feedback, feedbackCount);
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
                      string currentUser) {
  int option = 0;
  int idx = findStudent(studentUserName, studentCount, currentUser);
  if (idx == -1) {
    cout << "\nNo Student Found...";
    clearScreen();
    return;
  }

  while (option != 6) {
    printheader();
    printMenuHeader("Student Panel", currentUser);
    option = studentMenu();

    if (option == 1) {
      cout << "Name       : " << studentName[idx] << endl;
      cout << "Roll No    : " << studentRoll[idx] << endl;
      cout << "Department : " << studentDepartment[idx] << endl;
      cout << "Class      : " << studentClass[idx] << endl;
    } else if (option == 2) {
      float percentage = 0;
      if (totalClasses[idx] > 0)
        percentage = (attendedClasses[idx] * 100.0) / totalClasses[idx];
      cout << "Attendance : " << percentage << "%\n";
    } else if (option == 3) {
      cout << "Fee Status : " << (studentFeePaid[idx] ? "Paid" : "Unpaid")
           << endl;
    } else if (option == 4) {
      if (studentHostelRequired[idx] == true) {
        cout << "Hostel Name : " << HostelName[idx] << endl;
        cout << "Room No     : " << hostelRoom[idx] << endl;
      } else {
        cout << "No Hostel Allocated\n";
      }
    } else if (option == 5) {
      submitFeedback(feedback, feedbackCount, currentUser);
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

  // LOADING DATA FROM FILES --->

  loadUsers(userName, userPassword, userRole, userCount);
  loadStudents(studentName, studentRoll, studentDepartment, studentClass,
               studentFeeAmount, studentFeePaid, studentHostelRequired,
               HostelName, hostelRoom, hostelAllocated, studentUserName,
               studentCount, temppassword);
  loadFeedback(feedback, feedbackCount);

  initializeDefaultAdmin(userName, userPassword, userRole, userCount);

  int choice = 0;
  while (choice != 3) {
    printheader();
    printMenuHeader("Main Menu", "Login");
    cout << "----------------------------------------------\n";
    cout << "|                LOGIN MENU                  |\n";
    cout << "----------------------------------------------\n";
    cout << "|  1. Press 1 to Sign In as Admin            |\n";
    cout << "|  2. Press 2 to Sign In as Student          |\n";
    cout << "|  3. Press 3 to Exit                        |\n";
    cout << "----------------------------------------------\n";
    cout << "Enter Choice : ";
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
                       attendedClasses, feedback, feedbackCount);
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
            totalClasses, attendedClasses, feedback, feedbackCount, u);
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
