#pragma once

#include "../Funcionario/Funcionario.h"

#include <iostream>

using namespace std;

class Operador : public Funcionario
{
public:
    Operador();
    Operador(int codigo,string nome,Endereco endereco,string telefone,Data dataIngresso,string designacao,
        double salario);

    void exibirDadosOperador();    

    double taxaAumento(); 

    string toString();
    string AtributosEspecificos();

private:
    
};