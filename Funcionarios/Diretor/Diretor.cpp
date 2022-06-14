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
    cout << "Endereço: ";
    endereco.exibirEndereco();
    cout << "Telefone: " << telefone << endl;
    //cout << "Data de Ingresso: " << dataIngresso.getDia() << "/" << dataIngresso.getMes() << "/" << dataIngresso.getAno() << endl;
    cout << "Data de Ingresso: ";
    dataIngresso.printData();
    cout << "Designação: " << designacao << endl;
    cout << "Salário: " << salario << endl;
    cout << "Área de supervisão do diretor: " << getAreaSupervisaoDiretor() << endl;
    cout << "Área de formação do diretor: " << getAreaFormacao() << endl;

}

double Diretor::taxaAumento()
{
    double taxaAumento = 0.2;

    return taxaAumento;
}

string Diretor::toString(){
  string result =  codigo + "\n"
  result += nome + "\n";
  
  result += this->getAreaSupervisaoDiretor();

} 