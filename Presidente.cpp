#include "Presidente.h"

//construtores
Presidente::Presidente(){

}
Presidente::Presidente(string formacaoAcademica, string areaFormacao){
    this->formacaoAcademica = formacaoAcademica;
    this->areaFormacao = areaFormacao;
}

//getters
string Presidente::getFormacaoAcademica(){
    return this->formacaoAcademica;
}
string Presidente::getAreaFormacao(){
    return this->areaFormacao;
}

//setters
void Presidente::setFormacaoAcademica(string formacaoAcademica){
    this->formacaoAcademica = formacaoAcademica;
}
void Presidente::setAreaFormacao(string areaFormacao){
    this->areaFormacao = areaFormacao;
}