#pragma once

#include "../../Utilitarios/Data/Data.h"
#include "../../Utilitarios/Endereco/Endereco.h"

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

using namespace std;

class GerenciamentoFuncionarios
{
public:
    GerenciamentoFuncionarios();

    void cadastrarFuncionarios();
    void EscreverArquivoCadastroFuncionario();
    void listarFuncionarios();      //arquivo
    void listarFuncionariosTipo();  
    void alterarRegistroFuncionario();
    void excluirRegistroFuncionario();
    void excluirRegistroFuncionario(int codigo);
    void exibirMenuBusca();

    void buscarFuncionario();
    void buscarFuncionarioNome();
    void buscarFuncionarioEndereco();
    void buscarFuncionarioCep();
    void parseCEP();
    void buscarFuncionarioDataIngresso();

    void gerarHorasAleatorias();
    void calcularFolhaSalarial();
    void calcularFolhaSalarialFuncionario();
    void imprimirFolhaSalarialEmpresa();    //arquivo
    
    void descontosImpostoRenda();
    void descontosPrevidenciaSocial();

protected:
    //lista de funcionarios
    vector <Funcionario *> funcionarios;
    int folhaSalarial[12] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
};