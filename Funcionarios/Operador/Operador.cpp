#include "Operador.h"

Operador::Operador()
{

}

Operador::Operador(int codigo,string nome,Endereco endereco,string telefone,Data dataIngresso,string designacao,
        double salario) : Funcionario(codigo,nome,endereco,telefone,dataIngresso,designacao,salario)
{

}

void Operador::exibirDadosOperador()
{
    cout << "Código: " << codigo << endl;
    cout << "Nome: " << nome << endl;
    cout << "Endereço: ";
    endereco.exibirEndereco();
    cout << "Telefone: " << telefone << endl;
    cout << "Data de Ingresso: ";
    dataIngresso.printData();
    cout << "Designação: " << designacao << endl;
    cout << "Salário: " << salario << endl;
}