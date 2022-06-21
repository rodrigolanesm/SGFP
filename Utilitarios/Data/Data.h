#pragma once

#include <iostream>
#include <string>

class Data
{
private:
    //atributos
    int dia;
    int mes;
    int ano;  

public:
    //construtor padrão
    Data();
    Data(int dia, int mes, int ano);
    ~Data();

    //getters da classe Data
    int getDia();
    int getMes();
    int getAno();

    //setters da classe Data
    void setDia(int newDia);
    void setMes(int newMes);
    void setAno(int newAno);

    //método para imprimir a data formatada
    void lerData();
    void printData();
};