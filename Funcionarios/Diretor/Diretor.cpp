#include "Diretor.h"

Diretor::Diretor()
{

}

Diretor::Diretor(int codigo,string nome,Endereco endereco,string telefone,Data dataIngresso,string designacao,
        double salario,string areaSupervisaoDiretor, string areaFormacao) : Funcionario(codigo,nome,endereco,telefone,dataIngresso,designacao,salario)
{
    this->areaFormacao = areaFormacao;
    this->areaSupervisaoDiretor = areaSupervisaoDiretor;
}

void Diretor::setAreaSupervisaoDiretor(string areaSupervisaoDiretor)
{
    this->areaSupervisaoDiretor = areaSupervisaoDiretor;
}

void Diretor::setAreaFormacao(string areaFormacao)
{
    this->areaFormacao = areaFormacao;
}

string Diretor::getAreaSupervisaoDiretor()
{
    return areaSupervisaoDiretor;
}

string Diretor::getAreaFormacao()
{
    return areaFormacao;
}

void Diretor::exibirDadosDiretor()
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
    cout << "Área de supervisão do diretor: " << getAreaSupervisaoDiretor() << endl;
    cout << "Área de formação do diretor: " << getAreaFormacao() << endl;

}

double Diretor::calcularSalarioMensal(){

    double precoHoraNormal, precoHoraExtra;

    precoHoraNormal = this->getSalario()/ this->getHorasNormais();
    precoHoraExtra = this->getSalario()/ this->getHorasExtras();

    return this->getSalario() * precoHoraNormal + this->getHorasExtras() * precoHoraExtra;
};