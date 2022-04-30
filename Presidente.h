#pragma once

#include "Funcionario.h"

#include <iostream>

using namespace std;

class Presidente: public Funcionario{

public:
    Presidente();
    Presidente(string formacaoAcademica,
               string areaFormacao);

    void setFormacaoAcademica(string formacaoAcademica);
    void setAreaFormacao(string areaFormacao);           
    
    string getFormacaoAcademica();
    string getAreaFormacao();

private:

    string formacaoAcademica;
    string areaFormacao;
    
};