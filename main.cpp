#include "GerenciamentoFuncionarios/Data/Data.h"
#include "GerenciamentoFuncionarios/Endereco/Endereco.h"
#include "MainMenu/MainMenu.h"

#include "Funcionarios/Funcionario/Funcionario.h"
#include "Funcionarios/Operador/Operador.h"
#include "Funcionarios/Gerente/Gerente.h"
#include "Funcionarios/Diretor/Diretor.h"
#include "Funcionarios/Presidente/Presidente.h"

#define CLEAR "cls"

#include <iostream>
#include <string>
#include <list>
#include <locale.h>

using namespace std;

int main(void)
{
    system (CLEAR);
    setlocale(LC_ALL, "pt_BR.UTF-8");

    //exibir menu
    exibeMenu();
    escolherOpcaoMenu();

    return 0;
}