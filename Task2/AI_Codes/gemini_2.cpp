#include "gemini_2.h"

// Constructors
Polynomial::Polynomial() {
    coeffs = {0.0};
}

Polynomial::Polynomial(const vector<double>& coefficients) {
    coeffs = coefficients;
    // Remove leading zeros
    while (!coeffs.empty() && coeffs.front() == 0.0) {
        coeffs.erase(coeffs.begin());
    }
}

Polynomial::Polynomial(const Polynomial& other) {
    coeffs = other.coeffs;
}

// Destructor
Polynomial::~Polynomial() {}

// Assignment operator
Polynomial& Polynomial::operator=(const Polynomial& other) {
    coeffs = other.coeffs;
    return *this;
}

// Arithmetic operators
Polynomial Polynomial::operator+(const Polynomial& other) const {
    int maxDegree = max(degree(), other.degree());
    vector<double> result(maxDegree + 1, 0.0);

    for (int i = 0; i <= degree(); ++i) {
        result[i] += coeffs[i];
    }

    for (int i = 0; i <= other.degree(); ++i) {
        result[i] += other.coeffs[i];
    }

    return Polynomial(result);
}

Polynomial Polynomial::operator-(const Polynomial& other) const {
    int maxDegree = max(degree(), other.degree());
    vector<double> result(maxDegree + 1, 0.0);

    for (int i = 0; i <= degree(); ++i) {
        result[i] += coeffs[i];
    }

    for (int i = 0; i <= other.degree(); ++i) {
        result[i] -= other.coeffs[i];
    }

    return Polynomial(result);
}
Polynomial Polynomial::operator*(const Polynomial& other) const {
    int newDegree = degree() + other.degree();
    vector<double> result(newDegree + 1, 0.0);

    for (int i = 0; i <= degree(); ++i) {
        for (int j = 0; j <= other.degree(); ++j) {
            result[i + j] += coeffs[i] * other.coeffs[j];
        }
    }

    return Polynomial(result);
}

// Equality operator
bool Polynomial::operator==(const Polynomial& other) const {
    return coeffs == other.coeffs;
}

// Output operator
ostream& operator<<(ostream& out, const Polynomial& poly) {
    bool firstTerm = true;
    for (int i = poly.degree(); i >= 0; --i) {
        if (poly.coeffs[i] != 0.0) {
            if (!firstTerm) {
                if (poly.coeffs[i] > 0) {
                    out << " + ";
                } else {
                    out << " - ";
                }
            }
            firstTerm = false;
            if (i == 0) {
                out << abs(poly.coeffs[i]);
            } else if (i == 1) {
                out << abs(poly.coeffs[i]) << "x";
            } else {
                out << abs(poly.coeffs[i]) << "x^" << i;
            }
        }
    }
    if (firstTerm) {
        out << "0";
    }
    return out;
}

// Utility functions
int Polynomial::degree() const {
    return coeffs.size() - 1;
}

double Polynomial::evaluate(double x) const {
    double result = 0.0;
    for (int i = 0; i <= degree(); ++i) {
        result += coeffs[i] * pow(x, i);
    }
    return result;
}

Polynomial Polynomial::compose(const Polynomial& q) const {
    Polynomial result(vector<double>(degree() * q.degree() + 1, 0.0));

    for (int i = 0; i <= degree(); ++i) {
        for (int j = 0; j <= q.degree(); ++j) {
            result.coeffs[i * j] += coeffs[i] * q.coeffs[j];
        }
    }
    return result;
}

Polynomial Polynomial::derivative() const {
    if (degree() == 0) {
        return Polynomial({0.0});
    }
    vector<double> result(degree(), 0.0);
    for (int i = 1; i <= degree(); ++i) {
        result[i - 1] = i * coeffs[i];
    }
    return Polynomial(result);
}

Polynomial Polynomial::integral() const {
    int newDegree = degree() + 1;
    vector<double> result(newDegree + 1, 0.0);
    result[0] = 0.0; // Constant term of integration
    for (int i = 1; i <= newDegree; ++i) {
        result[i] = coeffs[i - 1] / i;
    }
    return Polynomial(result);
}

double Polynomial::integral(double x1, double x2) const {
    return integral().evaluate(x2) - integral().evaluate(x1);
}

double Polynomial::getRoot(double guess, double tolerance, int maxIter) {
    for (int i = 0; i < maxIter; ++i) {
        double f = evaluate(guess);
        double df = derivative().evaluate(guess);
        if (abs(df) < tolerance) {
            // Derivative is too small, consider other methods
            return guess;
        }
        double newGuess = guess - f / df;
        if (abs(newGuess - guess) < tolerance) {
            return newGuess;
        }
        guess = newGuess;
    }
    // Maximum iterations reached, root not found
    return 0.0;
}

void Polynomial::setCoefficients(const vector<double>& coefficients) {
    coeffs = coefficients;
}

double Polynomial::getCoefficient(int degree) const {
    if (degree < 0 || degree > this->degree()) {
        return 0.0;
    }
    return coeffs[degree];
}

int main() {
    /*Polynomial p1({1, -2, 3}); // Represents 1 - 2x + 3x^2
    Polynomial p2({-1, 4}); // Represents -1 + 4x
    Polynomial sum = p1 + p2;
    Polynomial difference = p1 - p2;
    Polynomial product = p1 * p2;
    cout << "p1: " << p1 << endl;
    cout << "p2: " << p2 << endl;
    cout << "p1 + p2: " << sum << endl;
    cout << "p1 - p2: " << difference << endl;
    cout << "p1 * p2: " << product << endl;
    double x = 2.5;
    cout << "p1 evaluated at x = " << x << ": " << p1.evaluate(x) << endl;
    cout << "p2 evaluated at x = " << x << ": " << p2.evaluate(x) << endl;
    Polynomial p3({5,3,2});
    cout<<p3.evaluate(2.0)<<'\n';
    Polynomial p4 ({1,2,3});
    Polynomial p5 ({1,2,3});
    if(p4==p5)
        cout<<"They are equal";
    else
        cout<<"NO";
    cout<<'\n';
    Polynomial p6({6,5,1});
    cout<<p6.getRoot()<<'\n';

    Polynomial p7({-25,0,1});
    cout<<p7.getRoot()<<'\n';*/
    Polynomial p8({0,0,0,1});
    cout<<p8<<'\n';
    Polynomial p9 ({1,1,3});
    cout<<p9<<'\n';
    return 0;
}