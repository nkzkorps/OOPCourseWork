//
// Created by Anna on 28.05.2024.
//

#ifndef COURSACHOOP_FUNCTIONS_H
#define COURSACHOOP_FUNCTIONS_H


#include <vector>
#include <memory>

// Интерфейс функции
class Function {
public:
    virtual double evaluate(double x) const = 0;

    virtual void setCoefficients(const std::vector<double> &coeffs) = 0;

    virtual ~Function() = default;
};

// Реализация многочлена
class Polynomial : public Function {
    std::vector<double> coefficients;
public:
    Polynomial(const std::vector<double> &coeffs);

    double evaluate(double x) const override;

    void setCoefficients(const std::vector<double> &coeffs) override;
};

// Реализация синуса
class Sine : public Function {
    double amplitude;
    double frequency;
public:
    Sine(double a = 1.0, double f = 1.0);

    double evaluate(double x) const override;

    void setCoefficients(const std::vector<double> &coeffs) override;
};

// Реализация косинуса
class Cosine : public Function {
    double amplitude;
    double frequency;
public:
    Cosine(double a = 1.0, double f = 1.0);

    double evaluate(double x) const override;

    void setCoefficients(const std::vector<double> &coeffs) override;
};

// Реализация экспоненты
class Exponential : public Function {
    double base;
public:
    Exponential(double b = 2.718281828459);

    double evaluate(double x) const override;

    void setCoefficients(const std::vector<double> &coeffs) override;
};

// Фабрика функций
class FunctionFactory {
public:
    enum FunctionType {
        POLYNOMIAL, SINE, COSINE, EXPONENTIAL
    };

    static std::unique_ptr<Function> createFunction(FunctionType type, const std::vector<double> &coeffs);
};

#endif //COURSACHOOP_FUNCTIONS_H
