#include "Data.h"
#include "Endereco.h"
#include "Funcionario.h"
#include "Operador.h"
#include "Gerente.h"
#include "Diretor.h"
#include "Presidente.h"

#include <iostream>
#include <string>
#include <list>

using namespace std;

int main(){

    //list <Funcionario> funcionarios;

    Funcionario funcionarios;

    //variáveis auxiliares
    string str;

    getline(cin, str);
    funcionarios.setNome(str);







    return 0;
}