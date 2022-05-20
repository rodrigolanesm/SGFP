#pragma once

#include "../Funcionario/Funcionario.h"

#include <iostream>

using namespace std;

class Diretor : public Funcionario
{
public:
    Diretor();

    void setAreaSupervisaoDiretor(string areaSupervisaoDiretor);
    void setAreaFormacao(string areaFormacao);
    
    string getAreaSupervisaoDiretor();
    string getAreaFormacao();
    void lerDadosDiretor();

private:

    string areaSupervisaoDiretor;
    string areaFormacao;
    
};