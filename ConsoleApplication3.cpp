#include <iostream>

using namespace std;

class IntegerSet {
private:
    int Elements[100];
public:
    IntegerSet(int e = 0) {
        for (int i = 0; i < 100; i++) {
            if (i > 0 && i < e) {
                Elements[i] = 1;
            }
            else {
                Elements[i] = 0;
            }
        }
    }
    ~IntegerSet() {
        bool first = true;
        for (int i = 0; i < 100; i++) {
            if (Elements[i]) {
                if (!first) {
                    cout << ",";
                }
                cout << i;
                first = false;
            }
        }
        cout << endl;
    }

    void InsertElement(int x) {
        if (x >= 0 && x < 100) {
            Elements[x] = 1;
        }
    }

    bool IsElement(int x) {
        if (x >= 0 && x < 100) {
            return Elements[x] == 1;
        }
        return false;
    }

    friend ostream& operator << (ostream& out, const IntegerSet& in) {
        out << "{";
        bool first = true;
        for (int i = 0; i < 100; i++) {
            if (in.Elements[i]) {
                if (!first) {
                    out << ",";
                }
                out << i;
                first = false;
            }
        }
        out << "}";
        return out;
    }

    friend bool operator == (const IntegerSet& in1, const IntegerSet& in2) {
        for (int i = 0; i < 100; i++) {
            if (in1.Elements[i] != in2.Elements[i]) {
                return false;
            }
        }
        return true;
    }

    friend IntegerSet operator + (const IntegerSet& in1, const IntegerSet& in2) {
        IntegerSet resualt;
        for (int i = 0; i < 100; i++) {
            resualt.Elements[i] = in1.Elements[i] || in2.Elements[i];
        }
        return resualt;
    }

    friend IntegerSet operator * (const IntegerSet& in1, const IntegerSet& in2) {
        IntegerSet resualt;
        for (int i = 0; i < 100; i++) {
            resualt.Elements[i] = in1.Elements[i] && in2.Elements[i];
        }
        return resualt;
    }
};









int main()
{
    IntegerSet S1, S2(10);
    S1.InsertElement(7);  S1.InsertElement(50);   S1.InsertElement(200);
    S2.InsertElement(20);
    cout << S1 << endl << S2 << endl << S1 + S2 << endl << S1 * S2 << endl;
    if (S1 == S2) cout << "Equal" << endl;
    else cout << "Not Equal" << endl;
    if ((S1 * S2).IsElement(7)) cout << "YES" << endl;
    else cout << "NO" << endl;
}

