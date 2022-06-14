#pragma once

#include "../Funcionario/Funcionario.h"

#include <iostream>

using namespace std;

class Diretor : public Funcionario
{
public:
    Diretor();
    Diretor(int codigo,string nome,Endereco endereco,string telefone,Data dataIngresso,string designacao,
        double salario,string areaSupervisaoDiretor, string areaFormacao);

    void setAreaSupervisaoDiretor(string areaSupervisaoDiretor);
    void setAreaFormacao(string areaFormacao);
    
    string getAreaSupervisaoDiretor();
    string getAreaFormacao();
    void exibirDadosDiretor();

    double taxaAumento();
    
    string toString();

private:

    string areaSupervisaoDiretor;
    string areaFormacao;
    
};