#ifndef EMPREGADO_HPP
#define EMPREGADO_HPP

#include "pessoa.hpp"

class Empregado : public Pessoa {
private:
    double salario;

public:
    Empregado(const std::string& nome, int idade, double salario);
    virtual ~Empregado();
};

#endif /* EMPREGADO_HPP */