#pragma once

#include "../Funcionario/Funcionario.h"

#include <iostream>
#include <vector>

using namespace std;

class Gerente : public Funcionario
{
public:
    Gerente();
    ~Gerente();
    Gerente(int codigo,string nome,Endereco endereco,string telefone,Data dataIngresso,string designacao,
        double salario,string areaSupervisaoGerente);

    void setAreaSupervisaoGerente(string areaSupervisaoGerente);

    string getAreaSupervisaoGerente();

    void exibirRegistroFuncionario();

    double taxaAumento();

    string toString();
    string AtributosEspecificos();

protected:

    string areaSupervisaoGerente;
    
};