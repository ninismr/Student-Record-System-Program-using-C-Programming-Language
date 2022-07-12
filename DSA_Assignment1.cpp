// C++ Student Record System Program
#include <bits/stdc++.h>
using namespace std;

// Student Struct
struct Student {
    int ID;
    string Name;
    string Subject;
    unsigned int Semester;
    float Score;
    Student* next;
};

// Stores the head of the linked list
Student* head = new Student();

// Check function to check that if student record already exist or not
bool check(int x)
{
    // Base case
    if (head == NULL)
        return false;

    Student* t = new Student;
    t = head;

    // Traverse the linked list 
    while (t != NULL) {
        if (t->ID == x)
            return true;
        t = t->next;
    }

    return false;
}

// Function to insert the student record
void Insert_Record(int ID, string Name, string Subject,
                    unsigned int Semester, float Score)
{
    // If record already exist
    if (check(ID)) {
        cout << "Student with this " 
             << "ID Already Exists\n";
        return;
    }

    // Create new Student (Node) to insert record
    Student* t = new Student();
    t->ID = ID;
    t->Name = Name;
    t->Subject = Subject;
    t->Semester = Semester;
    t->Score = Score;
    t->next = NULL;

    // Insert at the beginning
    if (head == NULL
        || (head->Score >= t->Score)) {
        t->next = head;
        head = t;
    }

    // Insert at the middle or End
    else {
        Student* c = head;
        while (c->next != NULL
                && c->next->Score < t->Score) {
            c = c->next;
        }
        t->next = c->next;
        c->next = t;
    }

    cout << "Student's Record Inserted "
         << "Successfully\n";
}

// Function to search record for any students record with the student's ID
void Search_Record(int ID)
{
    // If head is NULL
    if (!head) {
        cout << "No Student's Record "
             << "is Available\n";
        return;
    }

    // Otherwise
    else {
        Student* p = head;
        while (p) {
            if (p->ID == ID) {
                cout << "ID\t\t"
                     << p->ID << endl;
                cout << "Name\t\t"
                     << p->Name << endl;
                cout << "Subject\t\t"
                     << p->Subject << endl;
                cout << "Semester\t"
                     << p->Semester << endl;
                cout << "Score\t\t"
                     << p->Score << endl;
                return;
            }
            p = p->next;

        }

        if (p == NULL)
            cout << "No Student's Record "
                 << "is Available\n";
    }
}

// Function to delete students record with given student's ID if it exist
int Delete_Record(int ID)
{
    Student* t = head;
    Student* p = NULL;

    // Deletion at the beginning
    if (t != NULL
        && t->ID == ID) {
        head = t->next;
        delete t;

        cout << "Student's Record Deleted "
             << "Successfully\n";
        return 0;
    }

    // Deletion other than at the beginning
    while (t != NULL && t->ID != ID) {
        p = t;
        t = t->next;
    }
    if (t == NULL) {
        cout << "Student's Record does not Exist\n";
        return -1;
        p->next = t->next;

        delete t;
        cout << "Student's Record Deleted "
             << "Successfully\n";

        return 0;
    }
}

// Function to display the student's record
void Show_Record()
{
    Student* p = head;
    if (p == NULL) {
        cout << "No Student's Record "
             << "is Available\n";
    }
    else {
        cout << "ID\t\tName\t\tSubject\t\tSemester "
             << "\tScore\n";

        // Until p is not NULL
        while (p != NULL) {
            cout << p->ID << "\t"
                 << p->Name << "\t\t"
                 << p->Subject << "\t\t"
                 << p->Semester << "\t\t"
                 << p->Score << endl;
            p = p->next;
        }
    }
}

// Driver code
int main()
{
    head = NULL;
    int ID;
    string Name, Subject;
    unsigned int Semester;
    float Score;

    //Menu-driven program
    while (true) {
        cout << "\n\t\tStudent Record System"
                "\n\n\tPress"
                "\n\t1 to Create a New Student's Record"
                "\n\t2 to Delete a Student's Record"
                "\n\t3 to Search a Student's Record"
                "\n\t4 to View all Students' Record"
                "\n\t5 to Exit\n";
        cout << "\nEnter your Choice\n";
        int Choice;

        // Enter Choice
        cin >> Choice;
        if (Choice == 1) {
            cout << "Enter the ID of Student\n";
            cin >> ID;
            cout << "Enter the Name of Student\n";
            cin >> Name;
            cout << "Enter the Course Subject of Student\n";
            cin >> Subject;
            cout << "Enter the Semester of Student\n";
            cin >> Semester;
            cout << "Enter the Total Score of Student\n";
            cin >> Score;
            Insert_Record(ID, Name, Subject, Semester, Score);
        }
        else if (Choice == 2) {
            cout << "Enter Student ID of the Student whose Record is to be Deleted\n";
            cin >> ID;
            Delete_Record(ID);
        }
        else if (Choice == 3) {
            cout << "Enter Student ID of the Student whose Record you Want to Search\n";
            cin >> ID;
            Search_Record(ID);
        }
        else if (Choice == 4) {
            Show_Record();
        }
        else if (Choice == 5) {
            exit(0);
        }
        else {
            cout << "Invalid Choice"
                 << "Try Again\n";
        }
    }
    return 0;
}