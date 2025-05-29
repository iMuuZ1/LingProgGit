#include "./include/microempreendedor.hpp"
#include <iostream>

MicroEmpreendedor::MicroEmpreendedor(const std::string& nome, int idade, int cpf, int cnpj)
    : Pessoa(nome, idade, cpf), Empresa(cnpj) {
    std::cout << "MicroEmpreendedor criado." << std::endl;
}

void MicroEmpreendedor::exibe_cpf() {
    std::cout << "CPF: " << cpf << std::endl;
}

void MicroEmpreendedor::exibe_cnpj() {
    std::cout << "CNPJ: " << cnpj << std::endl;
}

MicroEmpreendedor::~MicroEmpreendedor() {
    std::cout << "Destruindo MicroEmpreendedor." << std::endl;
}
