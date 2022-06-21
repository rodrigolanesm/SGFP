#include "Gerente.h"

Gerente::Gerente()
{

}

Gerente::~Gerente()
{

}

Gerente::Gerente (int codigo, 
                 string nome, 
                 Endereco endereco, 
                 string telefone, 
                 Data dataIngresso, 
                 string designacao, 
                 double salario, 
                 string areaSupervisaoGerente) 
                 : Funcionario (codigo, 
                                nome, 
                                endereco, 
                                telefone, 
                                dataIngresso, 
                                designacao, 
                                salario)
{
    this->areaSupervisaoGerente = areaSupervisaoGerente;
}

void Gerente::setAreaSupervisaoGerente(string areaSupervisaoGerente)
{
    this->areaSupervisaoGerente = areaSupervisaoGerente;
}

string Gerente::getAreaSupervisaoGerente()
{
    return areaSupervisaoGerente;
}

void Gerente::exibirRegistroFuncionario()
{
    Funcionario::exibirRegistroFuncionario();
    cout << "Área de supervisão do gerente: " << getAreaSupervisaoGerente() << " " << endl;
}

double Gerente::taxaAumento()
{
    double taxaAumento = 0.1;

    return taxaAumento;
}

string Gerente::toString()
{
    string str = Funcionario::toString();
    return str;
}

string Gerente::AtributosEspecificos()
{
    string str = getAreaSupervisaoGerente() + "\n";
    return str;
}