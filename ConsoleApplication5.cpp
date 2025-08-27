#include <iostream>
#include <string>

using namespace std;

class Course {
private:
    static const int MaxSize = 60;
    string name;
    int size;
    string studentNames[MaxSize];
    float examGrades[MaxSize];
    float homeworkGrades[MaxSize];
    float homeworkWheight;
public:
    Course(string n, float hw);

    void setHomeworkWeight(float hw);

    float getHomeworkWeight() const;

    void Insert(string studentName, float hg, float eg);

    float getFinalGrade(string studentName) const;

    Course operator ++ (int);

    friend ostream& operator << (ostream& out, const Course& c);

    static int getMaxSize();
};

Course::Course(string n, float hw) {
    name = n;
    if (hw >= 0 && hw <= 1) {
        homeworkWheight = hw;
    }
    else {
        homeworkWheight = 0;
    }
    size = 0;
}

void Course::setHomeworkWeight(float hw) {
    if (hw >= 0 && hw <= 1) {
        homeworkWheight = hw;
    }
    else {
        homeworkWheight = 0;
    }
}

float Course::getHomeworkWeight() const {
    return homeworkWheight;
}

void Course::Insert(string studentName, float hg, float eg) {
    if (size < MaxSize) {
        studentNames[size] = studentName;
        homeworkGrades[size] = hg;
        examGrades[size] = eg;
        size++;
    }
}

float Course::getFinalGrade(string studentName) const {
    for (int i = 0; i < size; i++) {
        if (studentNames[i] == studentName) {
            float finalGrade = (homeworkGrades[i] * homeworkWheight) + (examGrades[i] * (1 - homeworkWheight));
            return finalGrade;
        }
    }
    return -1;
}


Course Course::operator ++ (int) {
    Course onePlus = *this;
    for (int i = 0; i < size; i++) {
        if (examGrades[i] < 20) {
            examGrades[i] += 1;
        }
    }
    return onePlus;
}


ostream& operator << (ostream& out, const Course& c) {
    for (int i = 0; i < c.size; i++) {
        float finalGrade = (c.homeworkGrades[i] * c.homeworkWheight) + (c.examGrades[i] * (1 - c.homeworkWheight));
            out << "studentName : " << c.studentNames[i] << " = " << finalGrade << endl;
    }
    return out;
}

int Course::getMaxSize() {
    return MaxSize;
}

int main() {
  
    Course cppCourse("C++ Programming", 0.4);

    string name;
    float hw, exam;

    
    for (int i = 0; i < 40; i++) {
        cout << "Enter name, homework grade, exam grade for student " << i + 1 << ": ";
        cin >> name >> hw >> exam;
        cppCourse.Insert(name, hw, exam);
    }

    
    cppCourse++;

    
    cout << cppCourse;

    return 0;
}


