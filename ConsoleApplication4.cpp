#include <iostream>

using namespace std;

class SortedList {
private:
    double List[1000];
    int n;
public:
    SortedList() {
        n = 0;
    }
    ~SortedList() {
        for (int i = 0; i < n; i++) {
            cout << "list item : " << List[i] << " - ";
        }
        cout << endl;
    }
    void insert (double x) {
        int i;
        for (i = n - 1 ; i >= 0 && x < List[i] ; i++) {
            List[i + 1] = List[i];
        }
        List[i + 1] = x;
        n++;
    }
    int search(double x) {
        for (int i = 0; i < n; i++) {
            if (List[i] == x) {
                return i;
            }
        }
        return -1;
    }
    friend ostream& operator << (ostream& out, const SortedList& L) {
        out << "{";
        for (int i = 0; i < L.n; i++) {
            if (i > 0) out << ",";
            out << L.List[i];
        }
        out << "}";
        return out;
    }

    bool operator == (const SortedList& L) const {
        if (n != L.n) {
            return false;
        }
        for (int i = 0; i < n; i++) {
            if (List[i] != L.List[i]) {
                return false;
            }
        }
        return true;
    }

    friend SortedList operator + (const SortedList& L1, const SortedList& L2) {
        SortedList resault;
        int i = 0;
        int j = 0;
        
        for (; i < L1.n && j < L2.n;) {
            if (L1.List[i] < L2.List[j]) {
                resault.insert(L1.List[i++]);
            }
            else {
                resault.insert(L2.List[j++]);
            }
        }

        for (; i < L1.n; i++) {
            resault.insert(L1.List[i]);
        }
        for (; j < L2.n; j++) {
            resault.insert(L2.List[j]);
        }
        return resault;
    }

};



int main()
{
    SortedList L1, L2;
    L1.insert(2.3);
    L1.insert(1.2);
    L1.insert(3.5);
    L2.insert(1.7);
    L2.insert(5.6);
    cout << L1 << " - " << L2 << " - " << L1.search(1.7) << " - " << L2.search(1.7);
    if (L1 == L2) cout << "Equal";
    else cout << "Not Equal";
    L2 = L1 + L2;

/*    توضیح خروجی خط به خط :
    L1 <<
        L1 محتویات : [1.2, 2.3, 3.5]
        L2 <<
        L2 محتویات : [1.7, 5.6]
        L1.search(1.7)
        چون 1.7 در L1 نیست، خروجی : -1
        L2.search(1.7)
        چون 1.7 در L2 هست، خروجی : 0
        چون L1 و L2 برابر نیستند، خروجی : Not Equal
        در پایان برنامه، دِستراکتور هر دو شیء فراخوانی می‌شود و مقادیر لیست را چاپ می‌کند(به صورت list item : ... - ).
  */  
}

