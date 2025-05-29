#ifndef PESSOA_HPP
#define PESSOA_HPP

#include <iostream>
#include <string>

class Pessoa {
protected:
    std::string nome;
    int idade;
    int cpf;

public:
    Pessoa(const std::string& nome, int idade, int cpf);
    const std::string& pega_nome();
    virtual ~Pessoa();
};

#endif /* PESSOA_HPP */