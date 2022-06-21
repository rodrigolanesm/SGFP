#pragma once

#include "../Funcionario/Funcionario.h"

#include <iostream>

using namespace std;

class Diretor : public Funcionario
{
public:
    Diretor();
    ~Diretor();
    Diretor(int codigo, string nome, Endereco endereco, string telefone, Data dataIngresso, string designacao,
        double salario,string areaSupervisaoDiretor, string areaFormacao);

    void setAreaSupervisaoDiretor(string areaSupervisaoDiretor);
    void setAreaFormacao(string areaFormacao);
    
    string getAreaSupervisaoDiretor();
    string getAreaFormacao();
    void exibirRegistroFuncionario();

    double taxaAumento();
    
    string toString();
    string AtributosEspecificos();

private:

    string areaSupervisaoDiretor;
    string areaFormacao;
    
};