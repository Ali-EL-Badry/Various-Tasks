
#include "gemini.h"

// Constructors
Polynomial_gemini::Polynomial_gemini() {
    coeffs = {0.0};
}

Polynomial_gemini::Polynomial_gemini(const vector<double>& coefficients) {
    coeffs = coefficients;
    // Remove leading zeros
    // while (!coeffs.empty() && coeffs.empty() == 0.0) {
    //     coeffs.erase(coeffs.begin());
    // }
}

Polynomial_gemini::Polynomial_gemini(const Polynomial_gemini& other) {
    coeffs = other.coeffs;
}

// Destructor
Polynomial_gemini::~Polynomial_gemini() {}

// Assignment operator
Polynomial_gemini& Polynomial_gemini::operator=(const Polynomial_gemini& other) {
    coeffs = other.coeffs;
    return *this;
}

// Arithmetic operators
Polynomial_gemini Polynomial_gemini::operator+(const Polynomial_gemini& other) const {
    int maxDegree = max(degree(), other.degree());
    vector<double> result(maxDegree + 1, 0.0);

    for (int i = 0; i <= degree(); ++i) {
        result[i] += coeffs[i];
    }

    for (int i = 0; i <= other.degree(); ++i) {
        result[i] += other.coeffs[i];
    }

    return Polynomial_gemini(result);
}

Polynomial_gemini Polynomial_gemini::operator-(const Polynomial_gemini& other) const {
    int maxDegree = max(degree(), other.degree());
    vector<double> result(maxDegree + 1, 0.0);

    for (int i = 0; i <= degree(); ++i) {
        result[i] += coeffs[i];
    }

    for (int i = 0; i <= other.degree(); ++i) {
        result[i] -= other.coeffs[i];
    }

    return Polynomial_gemini(result);
}
Polynomial_gemini Polynomial_gemini::operator*(const Polynomial_gemini& other) const {
    int newDegree = degree() + other.degree();
    vector<double> result(newDegree + 1, 0.0);

    for (int i = 0; i <= degree(); ++i) {
        for (int j = 0; j <= other.degree(); ++j) {
            result[i + j] += coeffs[i] * other.coeffs[j];
        }
    }

    return Polynomial_gemini(result);
}

// Equality operator
bool Polynomial_gemini::operator==(const Polynomial_gemini& other) const {
    return coeffs == other.coeffs;
}

// Output operator
ostream& operator<<(ostream& out, const Polynomial_gemini& poly) {
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
int Polynomial_gemini::degree() const {
    return coeffs.size() - 1;
}

double Polynomial_gemini::evaluate(double x) const {
    double result = 0.0;
    for (int i = 0; i <= degree(); ++i) {
        result += coeffs[i] * pow(x, i);
    }
    return result;
}

Polynomial_gemini Polynomial_gemini::compose(const Polynomial_gemini& q) const {
    Polynomial_gemini result(vector<double>(degree() * q.degree() + 1, 0.0));

    for (int i = 0; i <= degree(); ++i) {
        for (int j = 0; j <= q.degree(); ++j) {
            result.coeffs[i * j] += coeffs[i] * q.coeffs[j];
        }
    }
    return result;
}

Polynomial_gemini Polynomial_gemini::derivative() const {
    if (degree() == 0) {
        return Polynomial_gemini({0.0});
    }
    vector<double> result(degree(), 0.0);
    for (int i = 1; i <= degree(); ++i) {
        result[i - 1] = i * coeffs[i];
    }
    return Polynomial_gemini(result);
}

Polynomial_gemini Polynomial_gemini::integral() const {
    int newDegree = degree() + 1;
    vector<double> result(newDegree + 1, 0.0);
    result[0] = 0.0; // Constant term of integration
    for (int i = 1; i <= newDegree; ++i) {
        result[i] = coeffs[i - 1] / i;
    }
    return Polynomial_gemini(result);
}

double Polynomial_gemini::integral(double x1, double x2) const {
    return integral().evaluate(x2) - integral().evaluate(x1);
}

double Polynomial_gemini::getRoot(double guess, double tolerance, int maxIter) {
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

void Polynomial_gemini::setCoefficients(const vector<double>& coefficients) {
    coeffs = coefficients;
}

double Polynomial_gemini::getCoefficient(int degree) const {
    if (degree < 0 || degree > this->degree()) {
        return 0.0;
    }
    return coeffs[degree];
}
