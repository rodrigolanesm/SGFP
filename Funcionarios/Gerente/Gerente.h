#pragma once

#include "../Funcionario/Funcionario.h"

#include <iostream>
#include <vector>

using namespace std;

class Gerente : public Funcionario
{
public:
    Gerente();
    Gerente(int codigo,string nome,Endereco endereco,string telefone,Data dataIngresso,string designacao,
        double salario,string areaSupervisaoGerente);

    void setAreaSupervisaoGerente(string areaSupervisaoGerente);

    string getAreaSupervisaoGerente();

    void exibirDadosGerente();

    double taxaAumento();

protected:

    string areaSupervisaoGerente;
    
};