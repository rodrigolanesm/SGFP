#include "Gerente.h"

Gerente::Gerente()
{

}

Gerente::Gerente(int codigo,string nome,Endereco endereco,string telefone,Data dataIngresso,
string designacao,double salario,string areaSupervisaoGerente): Funcionario( codigo,nome,endereco,telefone,dataIngresso,designacao,salario)
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

void Gerente::exibirDadosGerente(){

    cout << "Código: " << codigo << endl;
    cout << "Nome: " << nome << endl;
    cout << "Endereço: ";
    endereco.exibirEndereco();
    cout << "Telefone: " << telefone << endl;
    //cout << "Data de Ingresso: " << dataIngresso.getDia() << "/" << dataIngresso.getMes() << "/" << dataIngresso.getAno() << endl;
    cout << "Data de Ingresso: ";
    dataIngresso.printData();
    cout << "Designação: " << designacao << endl;
    cout << "Salário: " << salario << endl;
    cout << "Área de supervisão do gerente: " << getAreaSupervisaoGerente() << " " << endl;
};