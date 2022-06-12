#pragma once

#include "../../Utilitarios/Data/Data.h"
#include "../../Utilitarios/Endereco/Endereco.h"
#include "../../Utilitarios/GerenciamentoFuncionarios/GerenciamentoFuncionarios.h"

#include "../../Funcionarios/Funcionario/Funcionario.h"
#include "../../Funcionarios/Operador/Operador.h"
#include "../../Funcionarios/Gerente/Gerente.h"
#include "../../Funcionarios/Diretor/Diretor.h"
#include "../../Funcionarios/Presidente/Presidente.h"

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <time.h>
#include <algorithm>
#include <dos.h>

class Salarios : public GerenciamentoFuncionarios
{
public:
    Salarios();
    ~Salarios();

    void gerarHorasAleatorias();
    void calcularFolhaSalarial();
    void calcularFolhaSalarialFuncionario();
    void imprimirFolhaSalarialEmpresa();    //arquivo
    
    void descontosImpostoRenda();
    void descontosPrevidenciaSocial();
private:
    int folhaSalarial[12] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
};