#include <iostream>
#include <string>
using namespace std;

class Date {
    friend ostream& operator<<(ostream&, const Date&);
    friend istream& operator>>(istream&, Date&);
public:
    Date(int d = 20, int m = 2, int y = 1404) : day(d), month(m), year(y) {}
    void setDate(int d, int m, int y) { day = d; month = m; year = y; }
    int getDay() const { return day; }
    int getMonth() const { return month; }
    int getYear() const { return year; }
    void print() const { cout << day << "/" << month << "/" << year; }
    Date operator++();         
    Date operator++(int);      
    Date operator+=(int);      
    bool operator==(const Date&) const;
    bool operator<(const Date&) const;
    bool operator>(const Date&) const;
private:
    int day, month, year;
    static int DaysofMonth[12];
};

int Date::DaysofMonth[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

Date Date::operator++() {
    day++;
    if (day > DaysofMonth[month - 1]) {
        day = 1;
        month++;
        if (month > 12) {
            month = 1;
            year++;
        }
    }
    return *this;
}

Date Date::operator++(int) {
    Date temp = *this;
    ++(*this);
    return temp;
}

Date Date::operator+=(int days) {
    while (days--) ++(*this);
    return *this;
}

bool Date::operator==(const Date& d) const {
    return day == d.day && month == d.month && year == d.year;
}

bool Date::operator<(const Date& d) const {
    if (year != d.year) return year < d.year;
    if (month != d.month) return month < d.month;
    return day < d.day;
}

bool Date::operator>(const Date& d) const {
    return d < *this;
}

ostream& operator<<(ostream& out, const Date& d) {
    out << d.day << "/" << d.month << "/" << d.year;
    return out;
}

istream& operator>>(istream& in, Date& d) {
    in >> d.day >> d.month >> d.year;
    return in;
}


class FoodItem {
private:

    string Name;
    double Price;
    Date PDate;
    int SLife;

public:
    FoodItem(string name = "food", double price = 0, Date pDate = Date(), int sLife = 1);
    void setPrice(double price);
    double getPrice() const;
    Date getExpDate() const;
    friend istream& operator>> (istream& in, FoodItem& f);
    friend ostream& operator<< (ostream& out, const FoodItem& f);
    friend bool operator< (const FoodItem& f , const Date& d);
};

FoodItem::FoodItem(string name, double price, Date pDate, int sLife)
    : Name(name), Price(price), PDate(pDate), SLife(sLife) {
}

void FoodItem::setPrice(double price){
    if (price >= 0) {
        Price = price;
    }
}

double FoodItem::getPrice() const {
    return Price;
}

Date FoodItem::getExpDate() const {
    Date exp = PDate;
    exp += (SLife * 30);
    return exp;
}

istream& operator>> (istream& in, FoodItem& f) {
    cout << "Enter Name: ";
    in >> f.Name;
    cout << "Enter Price: ";
    in >> f.Price;
    cout << "Enter Production Date (day month year): ";
    in >> f.PDate;
    cout << "Enter Shelf Life (months): ";
    in >> f.SLife;
    return in;
};

ostream& operator<< (ostream& out, const FoodItem& f) {
    out << "Name = " << f.Name
        << "Price = " << f.Price
        << " Production Date = " << f.PDate
        << " Expired Date = " << f.getExpDate();
    return out;
}

bool operator < (const FoodItem& f, const Date& d) {
    return f.getExpDate() < d;
}

int main()
{
    const int size = 100;
    FoodItem item[size];
    Date today;
    cout << "Enter today's date (day month year): ";
    cin >> today;
    for (int i = 0; i < size; i++) {
        cout << "Enter info for item " << i + 1 << " (Name Price Day Month Year SLife): ";
        cin >> item[i];
    }

    cout << "\nExpired items:\n";

    for (int i = 0; i < size; i++) {
        if (item[i] < today) {
            cout << item[i] << endl;
        }
    }
    return 0;
}

