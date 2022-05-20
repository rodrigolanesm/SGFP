#include "Diretor.h"

Diretor::Diretor()
{

}

void Diretor::setAreaSupervisaoDiretor(string areaSupervisaoDiretor)
{
    this->areaSupervisaoDiretor = areaSupervisaoDiretor;
}

void Diretor::setAreaFormacao(string areaFormacao)
{
    this->areaFormacao = areaFormacao;
}

string Diretor::getAreaSupervisaoDiretor()
{
    return areaSupervisaoDiretor;
}

string Diretor::getAreaFormacao()
{
    return areaFormacao;
}

void Diretor::lerDadosDiretor()
{
    cout << "Digite a área de supervisão do diretor: " << endl;
    getline(cin, areaSupervisaoDiretor);
    cout << "Digite a área de formação do diretor: " << endl;
    getline(cin, areaFormacao);
}