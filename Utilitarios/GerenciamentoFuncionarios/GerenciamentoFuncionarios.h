#pragma once

#include "../../Utilitarios/Data/Data.h"
#include "../../Utilitarios/Endereco/Endereco.h"

#include "../../Funcionarios/Funcionario/Funcionario.h"
#include "../../Funcionarios/Operador/Operador.h"
#include "../../Funcionarios/Gerente/Gerente.h"
#include "../../Funcionarios/Diretor/Diretor.h"
#include "../../Funcionarios/Presidente/Presidente.h"

#include <iostream>
#include <string>
#include <vector>
#include <list>

using namespace std;

class GerenciamentoFuncionarios
{
public:
    GerenciamentoFuncionarios();

    void cadastrarFuncionarios();
    void listarFuncionarios(); 
    void listarFuncionariosTipo();
    void alterarRegistroFuncionario();
    void excluirRegistroFuncionario();
    void exibirMenuBusca();
    void buscarFuncionario();
    void buscarFuncionarioNome();
    void buscarFuncionarioEndereco();
    void buscarFuncionarioDataIngresso();

protected:
    //lista de funcionarios
    vector <Funcionario*> funcionarios;

    Funcionario *func;

};