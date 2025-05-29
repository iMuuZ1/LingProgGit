#ifndef EMPRESA_HPP
#define EMPRESA_HPP

#include "pessoa.hpp"
#include "empregado.hpp"

class Empresa {
    protected:
    int cnpj;
public:
    Empresa(int cnpj);
    void paga(Pessoa& pes);
    void contrata(Empregado& emp);
    virtual ~Empresa();
};

#endif /* EMPRESA_HPP */