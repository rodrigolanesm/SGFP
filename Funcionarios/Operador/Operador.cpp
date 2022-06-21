#include "Operador.h"

Operador::Operador()
{

}

Operador::~Operador()
{

}

Operador::Operador(int codigo,string nome,Endereco endereco,string telefone,Data dataIngresso,string designacao,
        double salario) : Funcionario(codigo,nome,endereco,telefone,dataIngresso,designacao,salario)
{

}

void Operador::exibirRegistroFuncionario()
{
    Funcionario::exibirRegistroFuncionario();
}

double Operador::taxaAumento()
{
    double taxaAumento = 0.05;

    return taxaAumento;
}

string Operador::toString()
{
    string str = Funcionario::toString();
    return str;
}

string Operador::AtributosEspecificos()
{
    return "";
}