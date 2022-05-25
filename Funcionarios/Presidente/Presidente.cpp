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
    cout << "A formacao academica do Presidente: " << getFormacaoAcademicaPresidente() << endl;
    cout << "Digite a area de formacao do Presidente: " << getAreaFormacaoPresidente() << endl;

}

double Presidente::calcularSalarioMensal(){

    double precoHoraNormal, precoHoraExtra;

    precoHoraNormal = this->getSalario() / this->getHorasNormais();
    precoHoraExtra = this->getSalario() / this->getHorasExtras();

    return ((this->getSalario() * precoHoraNormal) + (this->getHorasExtras() * precoHoraExtra));
};