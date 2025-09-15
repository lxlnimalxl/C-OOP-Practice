#include <iostream>
#include <string>
using namespace std;


class Publication {
protected:
    string title;
    double price;
public:
    Publication(string t = "title", double p = 0) : title(t), price(p) {}
    virtual void show() = 0;
    virtual double size() = 0;
};

class Book : public Publication {
private:
    int NumPage;
public:
    Book(string t = "title", double p = 0 , int n = 0) : Publication(t , p), NumPage(n) {}
    void show() override {
        cout << "Publication Title = " << title << " | Price = " << price << endl;
    }
    double size() override {
        cout << "Page Number = " << NumPage << endl;
        return NumPage;
    }
};

class AudioFile : public Publication {
private:
    int Duration;
public:
    AudioFile(string t = "title", double p = 0 , int d = 0) : Publication(t , p) , Duration(d) {}

    void show() override {
        cout << "Audio File: Title = " << title << " | Price = " << price << endl;
    }

    double size() override {
        cout << "Audio File Duration = " << Duration << endl;
        return Duration;
    }
};


int main()
{
    Publication *pointer;
    Book b("C++ programming", 100000, 500);
    AudioFile a("The Little Prince", 50000, 120);
    pointer = &b;
    pointer->show();
    pointer->size();
    pointer = &a;
    pointer->show();
    pointer->size();
    return 0;
}
