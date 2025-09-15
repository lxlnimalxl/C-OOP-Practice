#include <iostream>
#include <string>

using namespace std;


class ParcelPost {
protected:
    string SenderAdr;
    string RecipientAdr;
    double Weight;
public:
    ParcelPost(string s = "SenderAdr" , string r = "RecipientAdr" , double w = 0) : SenderAdr(s) , RecipientAdr(r) , Weight(w) {}
    virtual void display() {
        cout << "SenderAdr : " << SenderAdr << endl;
        cout << "RecipientAdr : " << RecipientAdr << endl;
    }
    virtual int getPostCost() = 0;
};

class RegularPost : public ParcelPost {
private:
    int Cost;
public:
    RegularPost(string s = "SenderAdr", string r = "RecipientAdr", double w = 0, int c = 0) : ParcelPost(s, r, w), Cost(c){}
    void display() override {
        cout << "RegularPost:" << endl;
        cout << "SenderAdr : " << SenderAdr << endl;
        cout << "RecipientAdr : " << RecipientAdr << endl;
    }
    int getPostCost() override {
        cout << "Cost : ";
        return Cost = Weight * Cost;
    }
};

class ExpressPost : public ParcelPost {
private:
    int TrackingNO;
public:
    ExpressPost(string s = "SenderAdr", string r = "RecipientAdr", double w = 0, int t = 0) :ParcelPost(s, r, w), TrackingNO(t){}
    void display() override {
        cout << "Express:" << endl;
        cout << "SenderAdr : " << SenderAdr << endl;
        cout << "RecipientAdr : " << RecipientAdr << endl;
    }
    int getPostCost() override {
        if (Weight < 0.5) {
            return 100000;
        }
        else if (Weight > 0.5 && Weight < 1) {
            return 150000;
        }
        else if (Weight > 1 && Weight < 3) {
            return 200000;
        }
        else {
            return 400000;
        }
    }
};

int main()
{
    ParcelPost* pointer;
    RegularPost a("birjand", "tehran", 1.5, 50000);
    ExpressPost b("birjand", "mashad", 2.5, 45173);
    pointer = &a;
    pointer->display();
    cout << "Cost = " << pointer->getPostCost() << endl;
    pointer = &b;
    pointer->display();
    cout << "Cost = " << pointer->getPostCost() << endl;
    return 0;
}

