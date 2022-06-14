#include "Presidente.h"

//construtores
Presidente::Presidente()
{

}
Presidente::Presidente(int codigo,string nome,Endereco endereco,string telefone,Data dataIngresso,string designacao,
    double salario,string formacaoAcademicaPresidente,string areaFormacaoPresidente):Funcionario(codigo,nome,endereco,telefone,dataIngresso,designacao,salario)
{
    this->formacaoAcademicaPresidente = formacaoAcademicaPresidente;
    this->areaFormacaoPresidente = areaFormacaoPresidente;
}

//getters
string Presidente::getFormacaoAcademicaPresidente()
{
    return this->formacaoAcademicaPresidente;
}
string Presidente::getAreaFormacaoPresidente()
{
    return this->areaFormacaoPresidente;
}

//setters
void Presidente::setFormacaoAcademicaPresidente(string formacaoAcademicaPresidente)
{
    this->formacaoAcademicaPresidente = formacaoAcademicaPresidente;
}
void Presidente::setAreaFormacaoPresidente(string areaFormacaoPresidente)
{
    this->areaFormacaoPresidente = areaFormacaoPresidente;
}

void Presidente::exibirDadosPresidente()
{   
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
    cout << "Formação acadêmica do Presidente: " << getFormacaoAcademicaPresidente() << endl;
    cout << "Área de formação do Presidente: " << getAreaFormacaoPresidente() << endl;

}

double Presidente::taxaAumento()
{
    double taxaAumento = 0.3;

    return taxaAumento;
}