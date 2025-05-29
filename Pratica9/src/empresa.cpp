#include "./include/empresa.hpp"

Empresa::Empresa(int cnpj) : cnpj(cnpj) {}

void Empresa::paga(Pessoa& pes) {
    std::cout << "Pagando a pessoa: " << pes.pega_nome() << std::endl;
}

void Empresa::contrata(Empregado& emp) {
    std::cout << "Contratando empregado: " << emp.pega_nome() << std::endl;
}

Empresa::~Empresa() {
    std::cout << "Destruindo Empresa:" << cnpj << std::endl;
}