#include "Chat_2.h"
#include <stdexcept>
#include <cmath>

// Default Constructor
Polynomial::Polynomial() : coeffs(1, 0.0) {}

// Constructor with coefficients
Polynomial::Polynomial(const vector<double>& coefficients) : coeffs(coefficients) {}

// Copy Constructor
Polynomial::Polynomial(const Polynomial& other) : coeffs(other.coeffs) {}

// Destructor
Polynomial::~Polynomial() {}

// Assignment Operator
Polynomial& Polynomial::operator=(const Polynomial& other) {
    if (this != &other) {
        coeffs = other.coeffs;
    }
    return *this;
}

// Addition Operator
Polynomial Polynomial::operator+(const Polynomial& other) const {
    size_t maxDegree = max(coeffs.size(), other.coeffs.size());
    vector<double> result(maxDegree, 0.0);

    for (size_t i = 0; i < maxDegree; ++i) {
        if (i < coeffs.size()) result[i] += coeffs[i];
        if (i < other.coeffs.size()) result[i] += other.coeffs[i];
    }
    return Polynomial(result);
}

// Subtraction Operator
Polynomial Polynomial::operator-(const Polynomial& other) const {
    size_t maxDegree = max(coeffs.size(), other.coeffs.size());
    vector<double> result(maxDegree, 0.0);

    for (size_t i = 0; i < maxDegree; ++i) {
        if (i < coeffs.size()) result[i] += coeffs[i];
        if (i < other.coeffs.size()) result[i] -= other.coeffs[i];
    }
    return Polynomial(result);
}

// Multiplication Operator
Polynomial Polynomial::operator*(const Polynomial& other) const {
    size_t resultDegree = coeffs.size() + other.coeffs.size() - 1;
    vector<double> result(resultDegree, 0.0);

    for (size_t i = 0; i < coeffs.size(); ++i) {
        for (size_t j = 0; j < other.coeffs.size(); ++j) {
            result[i + j] += coeffs[i] * other.coeffs[j];
        }
    }
    return Polynomial(result);
}

// Equality Operator
bool Polynomial::operator==(const Polynomial& other) const {
    return coeffs == other.coeffs;
}

// Degree function
int Polynomial::degree() const {
    return static_cast<int>(coeffs.size()) - 1;
}

// Evaluate the polynomial at x using Horner's method
double Polynomial::evaluate(double x) const {
    double result = 0.0;
    for (int i = coeffs.size() - 1; i >= 0; --i) {
        result = result * x + coeffs[i];
    }
    return result;
}

// Polynomial composition: this(p(x))
Polynomial Polynomial::compose(const Polynomial& q) const {
    Polynomial result; // Initialize with zero polynomial
    for (int i = coeffs.size() - 1; i >= 0; --i) {
        result = result * q + Polynomial({coeffs[i]});
    }
    return result;
}

// Derivative of the polynomial
Polynomial Polynomial::derivative() const {
    if (coeffs.size() <= 1) {
        return Polynomial({0.0});
    }

    vector<double> deriv(coeffs.size() - 1);
    for (size_t i = 1; i < coeffs.size(); ++i) {
        deriv[i - 1] = coeffs[i] * i;
    }
    return Polynomial(deriv);
}

// Indefinite integral of the polynomial
Polynomial Polynomial::integral() const {
    vector<double> integral(coeffs.size() + 1, 0.0);
    for (size_t i = 0; i < coeffs.size(); ++i) {
        integral[i + 1] = coeffs[i] / (i + 1);
    }
    return Polynomial(integral);
}

// Definite integral from x1 to x2
double Polynomial::integral(double x1, double x2) const {
    Polynomial indefIntegral = this->integral();
    return indefIntegral.evaluate(x2) - indefIntegral.evaluate(x1);
}



// Find root using Newton's method
double Polynomial::getRoot(double guess, double tolerance, int maxIter) {
    Polynomial deriv = this->derivative();
    double x = guess;
    for (int i = 0; i < maxIter; ++i) {
        double f_x = this->evaluate(x);
        double f_prime_x = deriv.evaluate(x);

        if (fabs(f_prime_x) < tolerance) {
            throw runtime_error("Derivative is too small, Newton's method failed.");
        }

        double next_x = x - f_x / f_prime_x;
        if (fabs(next_x - x) < tolerance) {
            return next_x;
        }
        x = next_x;
    }
    throw runtime_error("Max iterations exceeded, Newton's method failed.");
}



// Set coefficients
void Polynomial::setCoefficients(const vector<double>& coefficients) {
    coeffs = coefficients;
}

// Get coefficient of a specific degree
double Polynomial::getCoefficient(int degree) const {
    if (degree < 0 || degree >= static_cast<int>(coeffs.size())) {
        return 0.0;
    }
    return coeffs[degree];
}

/*// Output Operator
ostream& operator<<(ostream& out, const Polynomial& poly) {
    for (int i = poly.coeffs.size() - 1; i >= 0; --i) {
        if (poly.coeffs[i] != 0) {
            if (i != poly.coeffs.size() - 1 && poly.coeffs[i] > 0) out << " + ";
            else if (poly.coeffs[i] < 0) out << " - ";
            if (abs(poly.coeffs[i]) != 1 || i == 0) out << abs(poly.coeffs[i]);
            if (i > 0) out << "x";
            if (i > 1) out << "^" << i;
        }
    }
    return out;
}*/
/*std::ostream& operator<<(std::ostream& os, const Polynomial& poly) {
    bool hasTerms = false;

    // Handle the case where the polynomial is empty or all coefficients are zero
    for (int i = poly.degree(); i >= 0; --i) {
        double coeff = poly.safeAccess(i);  // Safely access coefficient at index i
        if (coeff != 0) {
            if (hasTerms) {
                os << (coeff > 0 ? " + " : " - ");
            } else if (coeff < 0) {
                os << "-";
            }
            os << std::abs(coeff);
            if (i > 0) {
                os << "x";
                if (i > 1) {
                    os << "^" << i;
                }
            }
            hasTerms = true;  // We found a non-zero term
        }
    }

    // If no terms were found, it means the polynomial is zero
    if (!hasTerms) {
        os << "0";
    }

    return os;
}*/
ostream& operator<<(ostream& out, const Polynomial& poly) {
    if (poly.coeffs.empty()) {
        out << "0";
        return out;
    }

    bool isFirst = true;
    for (int i = poly.coeffs.size() - 1; i >= 0; --i) {
        double coeff = poly.coeffs[i];
        if (coeff == 0) continue;

        // Print the coefficient
        if (!isFirst) {
            out << (coeff > 0 ? " + " : " - ");
            coeff = std::abs(coeff);
        }

        // Print the term
        if (i == 0) {
            out << coeff; // Constant term
        } else if (i == 1) {
            if (coeff == 1) out << "x";
            else out << coeff << "x";
        } else {
            if (coeff == 1) out << "x^" << i;
            else out << coeff << "x^" << i;
        }

        isFirst = false;
    }

    return out;
}






int main() {
   /* Polynomial p1({1, -2, 3}); // Represents 1 - 2x + 3x^2
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
    cout<<'\n';*/
    Polynomial p6({6,5,1});
    cout<<p6.getRoot()<<'\n';

    Polynomial p7({-25,0,1});
    cout<<p7.getRoot()<<'\n';

    /*Polynomial p9 ({1,1,3});
    cout<<p9<<'\n';*/
    return 0;
}










