#include <iostream>
#include <string>


using namespace std;

class Item {
private:
    string name;
    int price;
public:
    Item(string n = "", int p = 0) : name(n), price(p){}
    void setName(string n) {
        name = n;
    }
    void setPrice(int p) {
        price = p;
    }
    string getName() const{
        return name;
    }
    int getPrice() const {
        return price;
    }
};

class Factor {
private:
    Item list[100];
    int itemNo;
    int discount;
    static int tax;
public:
    Factor();
    void setDiscount(int d);
    int getDiscount() const;
    static void setTax(int t);
    static int getTax();
    void input();
    int getFactorAmount() const;
    friend ostream& operator<< (ostream& out, const Factor& f);
    friend Factor operator+ (const Factor& f1, const Factor& f2);
};

Factor::Factor() : itemNo(0), discount(0) {};

void Factor::setDiscount(int d) {
    if (d >= 0 && d <= 100) {
        discount = d;
    }
    else {
        discount = 0;
    }
};

int Factor::getDiscount() const {
    return discount;
}

void Factor::setTax(int t) {
    tax = t;
};

int Factor::getTax(){
    return tax;
}


void Factor::input() {
    cout << "itemNo number : " << endl;
    cin >> itemNo;
    if (itemNo > 100) {
        itemNo = 100;
    }
    for (int i = 0; i < itemNo; i++) {
        cout << "item name :" << endl;
        string n;
        cin >> n;
        cout << "item price : " << endl;
        int p;
        cin >> p;
        list[i].setName(n);
        list[i].setPrice(p);
    }
    cout << "discount number :" << endl;
    int d;
    cin >> d;
    setDiscount(d);
}


int Factor::getFactorAmount() const {
    int amount = 0;
    for (int i = 0; i < itemNo; i++) {
        amount += list[i].getPrice();
    }
    amount -= amount * discount / 100;
    amount += amount * tax / 100;
    return amount;
}

ostream& operator << (ostream& out, const Factor& f) {
    out << "List Item " << endl;
    for (int i = 0; i < f.itemNo; i++) {
        out << "- " << f.list[i].getName() << " = " << f.list[i].getPrice() << endl;
    }
    out << "total amount + tax : " << f.getFactorAmount() << endl;
    return out;
}


Factor operator+ (const Factor& f1 , const Factor& f2) {
    Factor result;
    result.itemNo = f1.itemNo + f2.itemNo;

    for (int i = 0; i < f1.itemNo; i++) {
        result.list[i] = f1.list[i];
    }
    for (int i = 0; i < f2.itemNo && (f1.itemNo + i) < 100; i++) {
        result.list[f1.itemNo + i] = f2.list[i];
    }
    if (f1.discount > f2.discount) {
        result.discount = f1.discount;
    }
    else {
        result.discount = f2.discount;
    }
    return result;
}
int Factor::tax = 9;

int main()
{
    Factor f;
    f.input();
    cout << f;
    return 0;
}

