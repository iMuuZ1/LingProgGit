#include "./include/pessoa.hpp"
#include "./include/empregado.hpp"
#include "./include/empresa.hpp"

int main() {
    Pessoa* p = new Pessoa("Lucas", 30, 1182345678);
    Empregado* e = new Empregado("Luis", 23, 1500.00);
    Pessoa* p2 = e;

    Empresa empresa(2905700001);
    // Ampliacao
    empresa.paga(*e);
    // Estreitamento
    empresa.contrata(*(static_cast<Empregado*> (p2))); 

    // Libera memoria
    delete p;
    delete e;
    return 0;
}