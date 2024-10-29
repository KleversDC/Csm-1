#include <iostream>
using namespace std;

class Fraction {
private:
    int numerator;
    int denominator;

    int gcd(int a, int b) const {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    void reduce() {
        int gcdValue = gcd(numerator, denominator);
        numerator /= gcdValue;
        denominator /= gcdValue;
    }

public:
    Fraction(int num = 0, int denom = 1) : numerator(num), denominator(denom) {
        if (denominator == 0) {
            cout << "Error: Denominator cannot be zero. Setting to 1 by default." << endl;
            denominator = 1;
        }
        reduce();
    }
    void input() {
        cout << "Enter numerator: ";
        cin >> numerator;
        cout << "Enter denominator: ";
        cin >> denominator;
        if (denominator == 0) {
            cout << "Error: Denominator cannot be zero. Setting to 1 by default." << endl;
            denominator = 1;
        }
        reduce();
    }
    void display() const {
        cout << numerator << "/" << denominator << endl;
    }
    Fraction add(const Fraction& other) const {
        int num = numerator * other.denominator + other.numerator * denominator;
        int denom = denominator * other.denominator;
        return Fraction(num, denom);
    }
    Fraction subtract(const Fraction& other) const {
        int num = numerator * other.denominator - other.numerator * denominator;
        int denom = denominator * other.denominator;
        return Fraction(num, denom);
    }
    Fraction multiply(const Fraction& other) const {
        int num = numerator * other.numerator;
        int denom = denominator * other.denominator;
        return Fraction(num, denom);
    }
    Fraction divide(const Fraction& other) const {
        int num = numerator * other.denominator;
        int denom = denominator * other.numerator;
        return Fraction(num, denom);
    }
};

int main() {
    Fraction fraction1, fraction2;
    cout << "Enter the first fraction:" << endl;
    fraction1.input();

    cout << "Enter the second fraction:" << endl;
    fraction2.input();

    Fraction result;
    result = fraction1.add(fraction2);
    cout << "Addition result: ";
    result.display();

    result = fraction1.subtract(fraction2);
    cout << "Subtraction result: ";
    result.display();

    result = fraction1.multiply(fraction2);
    cout << "Multiplication result: ";
    result.display();

    result = fraction1.divide(fraction2);
    cout << "Division result: ";
    result.display();
}
