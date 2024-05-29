#include "Functions.h"
#include <cmath>

// Polynomial
Polynomial::Polynomial(const std::vector<double> &coeffs) : coefficients(coeffs) {}

double Polynomial::evaluate(double x) const {
    double result = 0;
    for (size_t i = 0; i < coefficients.size(); ++i) {
        result += coefficients[i] * std::pow(x, i);
    }
    return result;
}

void Polynomial::setCoefficients(const std::vector<double> &coeffs) {
    coefficients = coeffs;
}

// Sine
Sine::Sine(double a, double f) : amplitude(a), frequency(f) {}

double Sine::evaluate(double x) const {
    return amplitude * std::sin(frequency * x);
}

void Sine::setCoefficients(const std::vector<double> &coeffs) {
    if (coeffs.size() >= 2) {
        amplitude = coeffs[0];
        frequency = coeffs[1];
    }
}

// Cosine
Cosine::Cosine(double a, double f) : amplitude(a), frequency(f) {}

double Cosine::evaluate(double x) const {
    return amplitude * std::cos(frequency * x);
}

void Cosine::setCoefficients(const std::vector<double> &coeffs) {
    if (coeffs.size() >= 2) {
        amplitude = coeffs[0];
        frequency = coeffs[1];
    }
}

// Exponential
Exponential::Exponential(double b) : base(b) {}

double Exponential::evaluate(double x) const {
    return std::pow(base, x);
}

void Exponential::setCoefficients(const std::vector<double> &coeffs) {
    if (!coeffs.empty()) {
        base = coeffs[0];
    }
}

// FunctionFactory
std::unique_ptr<Function> FunctionFactory::createFunction(FunctionType type, const std::vector<double> &coeffs) {
    switch (type) {
        case POLYNOMIAL:
            return std::make_unique<Polynomial>(coeffs);
        case SINE:
            return std::make_unique<Sine>(coeffs[0], coeffs[1]);
        case COSINE:
            return std::make_unique<Cosine>(coeffs[0], coeffs[1]);
        case EXPONENTIAL:
            return std::make_unique<Exponential>(coeffs[0]);
        default:
            return nullptr;
    }
}
