#pragma once

#include "../../Utilitarios/Data/Data.h"
#include "../../Utilitarios/Endereco/Endereco.h"

#include "../../Funcionarios/Funcionario/Funcionario.h"
#include "../../Funcionarios/Operador/Operador.h"
#include "../../Funcionarios/Gerente/Gerente.h"
#include "../../Funcionarios/Diretor/Diretor.h"
#include "../../Funcionarios/Presidente/Presidente.h"

#include <algorithm>
#include <exception>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <stdlib.h>
#include <string>
#include <time.h>
#include <vector>

using namespace std;

class GerenciamentoFuncionarios
{
public:
    GerenciamentoFuncionarios();
    ~GerenciamentoFuncionarios();
    void cadastrarFuncionarios();   // cadastro manual dos funcionários
    void lerArquivoCadastroFuncionario();    // cadastro automático dos funcionarios, feito a partir de um arquivo
    void EscreverArquivoCadastroFuncionario();
    void listarFuncionarios(); // aqui está a opção de salvar os registros dos funcionarios em arquivo
    void listarFuncionariosTipo(); 
    void exibirRegistroFuncionario(); 
    void alterarRegistroFuncionario();
    void excluirRegistroFuncionario();
    void excluirRegistroFuncionario(int codigo);
    void exibirMenuBusca();
    void buscarFuncionario();
    void buscarFuncionarioNome();
    void buscarFuncionarioEndereco();
    void buscarFuncionarioCep(int i);
    void parseCEP();
    void buscarFuncionarioDataIngresso();

protected:
    //lista de funcionarios
    vector <Funcionario *> funcionarios;
    double folhaSalarial[12] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    double folhaSalarialComImp[12] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
};