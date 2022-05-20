#include "Gerente.h"

Gerente::Gerente()
{

}

void Gerente::setAreaSupervisaoGerente(string areaSupervisaoGerente)
{
    this->areaSupervisaoGerente = areaSupervisaoGerente;
}

string Gerente::getAreaSupervisaoGerente()
{
    return areaSupervisaoGerente;
}

void Gerente::lerDadosGerente()
{
    cout << "Digite a área de supervisão do gerente: " << endl;
    getline(cin, areaSupervisaoGerente);
}
