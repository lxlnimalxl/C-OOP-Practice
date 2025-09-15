#include <iostream>
#include <string>
using namespace std;

class Course {
protected:
    string title;
    string Tname;
    int SessionCost;
    int SessionNo;
public:
    Course(string t = "title", string n = "Tname", int c = 0, int s = 0);
    void print();
    virtual int GetCost();
    virtual void addStudent(string) = 0;
    virtual ~Course() {};
};

Course::Course(string t, string n, int c, int s) : title(t) , Tname(n) , SessionCost(c) , SessionNo(s){}

void Course::print() {
    cout << "Title : " << title << " Teacher Name : " << Tname << endl;
}


int Course::GetCost() {
    return SessionCost * SessionNo;
}


class IndividualCourse : public Course {
private:
    string stdName;
public:
    IndividualCourse(string t = "title", string n = "Tname", int c = 0, int s = 0, string sn = "stdName");
    void print();
    void addStudent(string) override;
    ~IndividualCourse();
};


IndividualCourse::IndividualCourse(string t, string n, int c, int s, string sn) : Course(t, n, c, s), stdName(sn){}

void IndividualCourse::print() {
    cout << "Title : " << title << " Teacher Name : " << Tname << endl;
    cout << "stdName : " << stdName << endl;
}

void IndividualCourse::addStudent(string name) {
    stdName = name;
}

IndividualCourse::~IndividualCourse() {
    cout << "error course has expired" << endl;
}

class GroupCourse : public Course {
private:
    string students[30];
    int studentNo;
public:
    GroupCourse(string t = "title", string n = "Tname", int c = 0, int s = 0);
    void print();
    void addStudent(string) override;
    virtual ~GroupCourse();
};

GroupCourse::GroupCourse(string t, string n, int c, int s) : Course(t , n , c ,s) , studentNo(0){}

void GroupCourse::print() {
    cout << "Title : " << title << " Teacher Name : " << Tname << endl;
    cout << "stdsName : ";
    for (int i = 0; i < studentNo; i++) {
        cout << students[i] << " , ";
    }
    cout << endl;
}

void GroupCourse::addStudent(string name) {
    if (studentNo == 30) {
        cout << "class is full" << endl;
    }
    else {
        students[studentNo] = name;
        studentNo++;
    }
}

GroupCourse::~GroupCourse() {
    cout << "Group course has expired!" << endl;
}



void Input(Course* p) {
    string Name;
    cout << "enter name pls:" << endl;
    cin >> Name;
    p->addStudent(Name);
}

void display(Course* p) {
    p->print();
    cout << "Cost = " << p->GetCost() << endl;
}

int main()
{
    IndividualCourse a("Math", "Akbari", 500000, 10);
    GroupCourse b("Physics", "Rahimi", 2000000, 15);

    Input(&a);
    Input(&b);
    Input(&b);
    Input(&b);


    display(&a);
    display(&b);

    return 0;
}

