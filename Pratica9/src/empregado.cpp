#include "./include/empregado.hpp"

Empregado::Empregado(const std::string& nome, int idade, double salario): Pessoa(nome, idade, cpf), salario(salario) {}

Empregado::~Empregado() {
    std::cout << "Destruindo Empregado " << std::endl;
}