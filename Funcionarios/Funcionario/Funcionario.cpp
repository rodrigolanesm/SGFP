#include "../../Funcionarios/Funcionario/Funcionario.h"
#include "../../Utilitarios/Endereco/Endereco.h"
#include "../../Utilitarios/Data/Data.h"

#include <iostream>

using namespace std;

Funcionario::Funcionario()
{

}

Funcionario::Funcionario(int codigo,
                        string nome,
                        Endereco endereco,
                        string telefone,
                        Data dataIngresso,
                        string designacao,
                        double salario)
{
    this->codigo = codigo;
    this->nome = nome;
    this->endereco = endereco;
    this->telefone = telefone;
    this->dataIngresso = dataIngresso;
    this->designacao = designacao;
    this->salario = salario;
}

//setters

void Funcionario::setCodigo(int codigo)
{
    this->codigo = codigo;
}

void Funcionario::setNome(string nome)
{
    this->nome = nome;
}

void Funcionario::setEndereco(Endereco endereco)
{
    this->endereco = endereco;
}

void Funcionario::setTelefone(string telefone)
{
    this->telefone = telefone;
}

void Funcionario::setDataIngresso(Data dataIngresso)
{
    this->dataIngresso = dataIngresso;
}

void Funcionario::setDesignacao(string designacao)
{
    this->designacao = designacao;
}

void Funcionario::setSalario(double salario)
{
    this->salario = salario;   
}

void Funcionario::setHorasNormais(int horasNormais)
{
    this->horasNormais = horasNormais;
}

void Funcionario::setHorasExtras(int horasExtras)
{
    this->horasExtras = horasExtras;
}
    
// getters

int Funcionario::getCodigo()
{
    return codigo;
}

string Funcionario::getNome()
{
    return nome;
}

Endereco Funcionario::getEndereco()
{
    return endereco;
}

string Funcionario::getTelefone()
{
    return telefone;
}

Data Funcionario::getDataIngresso()
{
    return dataIngresso;
}

string Funcionario::getDesignacao()
{
    return designacao;
}

double Funcionario::getSalario()
{
    return salario;
}

int Funcionario::getHorasNormais()
{
    return horasNormais;
}

int Funcionario::getHorasExtras()
{
    return horasExtras;
}

void Funcionario::exibirRegistroFuncionario()
{
    cout << "Codigo: " << codigo << endl;
    
    cout << "Nome: " << nome << endl;

    cout << "Endereco: ";
    endereco.exibirEndereco();

    cout << "Telefone: " << telefone << endl;

    cout << "Data de Ingresso: ";
    dataIngresso.printData();

    cout << "Designacao: " << designacao << endl;
    
    cout << "Salario: " << salario << endl;
}

double Funcionario::calcularSalarioMensal()
{
    //Considerando que a jornada de trabalho será de 44 horas semanais e que um mês tem 4 semanas, podemos calcular o salário mensal
    double precoHoraNormal, precoHoraExtra;

    precoHoraNormal = this->getSalario() / (44.0 * 4);
    precoHoraExtra = 2 * precoHoraNormal;
    
    /* cout << "Horas Normais: " << getHorasNormais() << endl
         << "Horas Extras: " << getHorasExtras() << endl; */

    double salarioMensal = (this->getHorasNormais() * precoHoraNormal) + (this->getHorasExtras() * precoHoraExtra);

    return salarioMensal;
};

double Funcionario::descontosImpostoRenda(){
    // o imposto de renda é calculado por faixas de renda
    // Basta fazer o seguinte cálculo: (salário após descontos do INSS x percentual de alíquota) - valor a ser deduzido
    /* 
    faixa 1: R$ 0,00 a R$ 1903,98 | IR: isento | deduções: 0
    faixa 2: R$ 1903,99 a R$ 2826,65 | IR: 7,5% | deduções: R$ 142,80
    faixa 3: R$ 2826,66 a R$ 3751,05 | IR: 15% | deduções: R$ 354,80
    faixa 4: R$ 3751,06 a R$ 4664,68 | IR: 22,5% | deduções: R$ 636,13
    faixa 5: R$ 4664,69 a R$ 5541,59 | IR: 27,5% | deduções: R$ 869,36    
    */

    if (this->getSalario() <= 1903.98)
    {
        return 0;
    }
    else if (this->getSalario() >= 1903.99 && this->getSalario() <= 2826.65)
    {
        return (this->getSalario() - this->descontosPrevidenciaSocial()) * 0.075 - 142.8;
    }
    else if (this->getSalario() >= 2826.66 && this->getSalario() <= 3751.05)
    {
        return (this->getSalario() - this->descontosPrevidenciaSocial()) * 0.15 - 354.80;
    }
    else if (this->getSalario() >= 3751.06  && this->getSalario() <= 4664.68)
    {
        return (this->getSalario() - this->descontosPrevidenciaSocial()) * 0.225 - 636.13;
    }
    else
    {
        return (this->getSalario() - this->descontosPrevidenciaSocial()) * 0.275 - 869.36;
    }
}

double Funcionario::descontosPrevidenciaSocial(){
    //tabela de descontos de previdencia social/INSS
    /* 
    salario bruto : 0.00 - 1212.00 | desconto : 7.5%
    salario bruto : 1212.01 - 2427.35 | desconto : 9%
    salario bruto : 2427.36 - 3641.03 | desconto : 12%
    salario bruto : 3641.04 - 7087.22 | desconto : 14%
    */

    if (this->getSalario() <= 1212)
    {
        return this->getSalario() * 0.075;
    }
    else if (this->getSalario() >  1212 && this->getSalario() <= 2427.35)
    {
        return this->getSalario() * 0.09;
    }
    else if (this->getSalario() >=  2427.36 && this->getSalario() <= 3641.03 )
    {
        return this->getSalario() * 0.12;
    }
    else if (this->getSalario() >=  3641.03  && this->getSalario() <= 7087.22)
    {
        return this->getSalario() * 0.14;
    }
    else
    {
        return -1;
    }
}