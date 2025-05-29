#include "./include/pessoa.hpp"

Pessoa::Pessoa(const std::string& nome, int idade, int cpf) : nome(nome), idade(idade), cpf(cpf) {}

const std::string& Pessoa::pega_nome() {
    return nome;
}

Pessoa::~Pessoa() {
    std::cout << "Destruindo Pessoa: " << nome << std::endl;
}