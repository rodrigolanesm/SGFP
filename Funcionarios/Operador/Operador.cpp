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
    cout << "Codigo: " << codigo << endl;
    cout << "Nome: " << nome << endl;
    cout << "Endereco: ";
    endereco.exibirEndereco();
    cout << "Telefone: " << telefone << endl;
    //cout << "Data de Ingresso: " << dataIngresso.getDia() << "/" << dataIngresso.getMes() << "/" << dataIngresso.getAno() << endl;
    cout << "Data de Ingresso: ";
    dataIngresso.printData();
    cout << "Designacao: " << designacao << endl;
    cout << "Salario: " << salario << endl;
}