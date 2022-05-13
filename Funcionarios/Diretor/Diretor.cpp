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