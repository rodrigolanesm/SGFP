#pragma once

#include "../Funcionario/Funcionario.h"

#include <iostream>

using namespace std;

class Gerente : public Funcionario
{
public:
    Gerente();
    Gerente(string areaSupervisaoGerente);

    void setAreaSupervisaoGerente(string areaSupervisaoGerente);

    string getAreaSupervisaoGerente();
    

private:

    string areaSupervisaoGerente;
    
};