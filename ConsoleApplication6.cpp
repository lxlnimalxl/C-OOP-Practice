#include <iostream>
#include <string>
using namespace std;

class HugeInt {
private:
    int number[50];
    static const short int MaxDigits = 50;

public:
    HugeInt();
    explicit HugeInt(const string& s);
    ~HugeInt();

    int Digit() const;
    static short int MaxAllowedDigits();

    HugeInt operator+(const HugeInt& rhs) const;
    HugeInt operator++(int);

    friend ostream& operator<<(ostream& os, const HugeInt& h);
};

HugeInt::HugeInt() {
    for (int i = 0; i < MaxDigits; ++i) number[i] = 0;
}

HugeInt::HugeInt(const string& s) {
    for (int i = 0; i < MaxDigits; ++i) number[i] = 0;

    string digits;
    for (size_t i = 0; i < s.size(); ++i) {
        char ch = s[i];
        if (ch >= '0' && ch <= '9')
            digits.push_back(ch);
    }

    if (digits.empty()) return;

    if (digits.size() > static_cast<size_t>(MaxDigits))
        digits = digits.substr(digits.size() - MaxDigits);

    int offset = MaxDigits - static_cast<int>(digits.size());
    for (size_t i = 0; i < digits.size(); ++i) {
        number[offset + static_cast<int>(i)] = digits[i] - '0';
    }
}

HugeInt::~HugeInt() {
    cout << "!number is destructed" << endl;
}

int HugeInt::Digit() const {
    int i = 0;
    while (i < MaxDigits&& number[i] == 0) ++i;
    int d = MaxDigits - i;
    return d > 0 ? d : 1;
}

short int HugeInt::MaxAllowedDigits() {
    return MaxDigits;
}

HugeInt HugeInt::operator+(const HugeInt& rhs) const {
    HugeInt res;
    int carry = 0;
    for (int i = MaxDigits - 1; i >= 0; --i) {
        int sum = number[i] + rhs.number[i] + carry;
        res.number[i] = sum % 10;
        carry = sum / 10;
    }
    return res;
}

HugeInt HugeInt::operator++(int) {
    HugeInt old = *this;
    int carry = 1;
    for (int i = MaxDigits - 1; i >= 0 && carry; --i) {
        int sum = number[i] + carry;
        number[i] = sum % 10;
        carry = sum / 10;
    }
    return old;
}

ostream& operator<<(ostream& os, const HugeInt& h) {
    int i = 0;
    while (i < HugeInt::MaxDigits && h.number[i] == 0) ++i;
    if (i == HugeInt::MaxDigits) {
        os << '0';
        return os;
    }
    for (; i < HugeInt::MaxDigits; ++i) os << h.number[i];
    return os;
}


int main()
{
    HugeInt num1("456360000"), num2("999999999"), num3;
    num3 = num1 + num2;
    cout << num1 << "-" << num2++ << "-" << num3;
}
