#include <bits/stdc++.h>
using namespace std;
struct Term {
    int coefficient;
    int exponent;
};
int evaluatePolynomial(const list<Term>& polynomial, int x) {
    int result = 0;
    for (const Term& term : polynomial) {
        result += term.coefficient * pow(x, term.exponent);
    }
    return result;
}
void displayPolynomial(const list<Term>& polynomial) {
    for (auto it = polynomial.begin(); it != polynomial.end(); ++it) {
        cout << it->coefficient << "x^" << it->exponent;
        if (next(it) != polynomial.end()) {
            cout << " + ";
        }
    }
    cout << endl;
}

int main() {
    list<Term> polynomial1, polynomial2;
    int n, coefficient, exponent;
    cout << "Enter the number of terms in polynomial 1: ";
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cout << "Enter coefficient and exponent of term " << i + 1 << " in polynomial 1: ";
        cin >> coefficient >> exponent;
        polynomial1.push_back({coefficient, exponent});
    }
    cout << "Enter the number of terms in polynomial 2: ";
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cout << "Enter coefficient and exponent of term " << i + 1 << " in polynomial 2: ";
        cin >> coefficient >> exponent;
        polynomial2.push_back({coefficient, exponent});
    }
    int x;
    cout << "Enter the value of x for evaluation: ";
    cin >> x;
    cout << "Polynomial 1: ";
    displayPolynomial(polynomial1);
    cout << "Polynomial 2: ";
    displayPolynomial(polynomial2);
    int result1 = evaluatePolynomial(polynomial1, x);
    int result2 = evaluatePolynomial(polynomial2, x);
    cout << "Evaluation of polynomial 1 at x = " << x << ": " << result1 << endl;
    cout << "Evaluation of polynomial 2 at x = " << x << ": " << result2 << endl;

    return 0;
}
