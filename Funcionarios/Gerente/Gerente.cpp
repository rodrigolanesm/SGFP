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
    cout << "A área de supervisão do gerente é: " << getAreaSupervisaoGerente() << " " << endl;
};

double Gerente::calcularSalarioMensal(){

    double precoHoraNormal, precoHoraExtra;

    precoHoraNormal = this->getSalario()/ this->getHorasNormais();
    precoHoraExtra = this->getSalario()/ this->getHorasExtras();

    return this->getSalario() * precoHoraNormal + this->getHorasExtras() * precoHoraExtra;
};