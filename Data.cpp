#include <iostream>
#include <cstring>

#include "Data.h"

using namespace std;

Data::Data()
{
    //inicialização dos valores no construtor
    this->dia = 1;
    this->mes = 1;
    this->ano = 1;
}

//métodos get tornam os atributos private disponiveis em public

int Data::getDia()
{
    return dia;
}

int Data::getMes()
{
    return mes;
}

int Data::getAno()
{
    return ano;
}

//métodos set() recebem os novos valores, digitados na main.cpp e tornam private as entradas
void Data::setDia(int newDia)
{
    dia = newDia;
}

void Data::setMes(int newMes)
{
    mes = newMes;
}

void Data::setAno(int newAno)
{
    ano = newAno;
}  

void Data::lerData()
{
    cout << "\tDigite o dia de ingresso: ";
    cin >> dia;

    cout << "\tDigite o mês de ingresso: ";
    cin >> mes;

    cout << "\tDigite o ano de ingresso: ";
    cin >> ano;

    cin.ignore();
}

void Data::printData()
{
    string nomeDoMes;
    string nomeDosMeses[12] = { "Janeiro",
                                "Fevereiro", 
                                "Março",
                                "Abril", 
                                "Maio", 
                                "Junho",
                                "Julho", 
                                "Agosto", 
                                "Setembro",
                                "Outubro", 
                                "Novembro", 
                                "Dezembro"};

    //atribuir a cada numero de mês seu nome correspondente:
    nomeDoMes = nomeDosMeses[mes-1].c_str();

    //imprimir a data formatada no terminal:
    cout << dia << " de " << nomeDoMes << " de " << ano << endl;
}