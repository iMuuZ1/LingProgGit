#include "./include/pessoa.hpp"
#include "./include/empregado.hpp"
#include "./include/empresa.hpp"
#include "./include/microempreendedor.hpp"

int main() {
    Pessoa* p = new Pessoa("Lucas", 30, 1182345678);
    Empregado* e = new Empregado("Luis", 23, 1500.00);
    Pessoa* p2 = e;

    Empresa empresa(2905700001);
    empresa.paga(*e);
    empresa.contrata(*(static_cast<Empregado*>(p2))); 

    MicroEmpreendedor me("Carlos", 35, 123456789, 987654321);
    me.exibe_cpf();
    me.exibe_cnpj();

    delete p;
    delete e;
    return 0;
}
