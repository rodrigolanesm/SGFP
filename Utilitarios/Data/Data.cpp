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

Data::Data(int dia, int mes, int ano)
{
    this->dia = dia;
    this->mes = mes;
    this->ano = ano;
}

//getters
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

//setters
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

//métodos
void Data::lerData()
{
    do{
        cout << "\tDigite o dia: ";
        cin >> dia;
        if (dia < 1 || dia > 31)
        {
            cout << "Dia inválido!" << endl;
        }
    }
    while (dia < 1 || dia > 31);

    do{
        cout << "\tDigite o mês: ";
        cin >> mes;
        if (mes < 1 || mes > 12)
        {
            cout << "Mês inválido!" << endl;
        }
    }
    while (mes < 1 || mes > 12);
    
    cout << "\tDigite o ano: ";
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