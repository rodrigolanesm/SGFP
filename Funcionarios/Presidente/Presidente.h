#pragma once

#include "../Funcionario/Funcionario.h"

#include <iostream>

using namespace std;

class Presidente: public Funcionario
{

public:
    Presidente();
    ~Presidente();
    Presidente(int codigo,string nome,Endereco endereco,string telefone,Data dataIngresso,string designacao,
        double salario,string formacaoAcademicaPresidente,string areaFormacaoPresidente);

    void setFormacaoAcademicaPresidente(string formacaoAcademicaPresidente);
    void setAreaFormacaoPresidente(string areaFormacaoPresidente);           
    
    string getFormacaoAcademicaPresidente();
    string getAreaFormacaoPresidente();
    void exibirRegistroFuncionario();

    double taxaAumento();

    string toString();
    string AtributosEspecificos();

private:

    string formacaoAcademicaPresidente;
    string areaFormacaoPresidente;
    
};