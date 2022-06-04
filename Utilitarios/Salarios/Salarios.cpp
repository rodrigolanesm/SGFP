#include "Salarios.h"
#include "../../Menu/MainMenu.h"

Salarios::Salarios()
{

}

Salarios::~Salarios()
{

}

void Salarios::gerarHorasAleatorias()
{
    int normais = 0, extras = 0;

    for (int i = 0; i < funcionarios.size(); i++)
    {   
        //gerar valor aleatório
        srand(time(NULL));

        //44 horas por semana * 4 semanas por mês
        //além de 44h normais, o funcionário pode trabalhar 22h extras
        normais = rand() % (44 * 4);        
        funcionarios[i]->setHorasNormais(normais); 

        //só há hora extra se o funcionário trabalhar mais de 44 horas por semana
        if (funcionarios[i]->getHorasNormais() > 44)
        {
            extras = rand() % (22 * 4);
            funcionarios[i]->setHorasExtras(extras);
        }
        else
        {
            funcionarios[i]->setHorasExtras(0);
        }
    }
}

void Salarios::calcularFolhaSalarial()
{   
    int mes;

    do
    {
        cout << "Escolha um mês para calcular a folha salarial." << endl << endl;

        cout << "Número do mês escolhido: ";
        cin >> mes;
        cin.ignore();

        cout << endl << endl;

        if (mes < 1 || mes > 12) 
        {
            cout << "Mês inválido, tente novamente por favor." << endl;
        }

    }
    while (mes < 1 || mes > 12);
    
    if (folhaSalarial[mes - 1]) // != 0
    {
        cout << "Este mês já foi calculado." << endl;
    }
    else
    {   
        for (int i = 0; i < funcionarios.size(); i++)
        {  
            cout << "Código: " << funcionarios[i]->getCodigo() 
                 << " - Nome: " << funcionarios[i]->getNome() 
                 << " - Salário base:" << funcionarios[i]->getSalario() << endl << endl;

            //atribuir a quantidade de horas trabalhadas no mês com a função de gerar horas aleatórias
            gerarHorasAleatorias();
        
            //folhaSalarial[mes] += (funcionarios[i]->calcularSalarioMensal() - funcionarios[i]->descontosImpostoRenda() - funcionarios[i]->descontosPrevidenciaSocial());

            //exibir a quantidade de horas trabalhadas por cada funcionário
            cout << "Horas normais trabalhadas: " << funcionarios[i]->getHorasNormais() << endl;
            cout << "Horas extras trabalhadas: " << funcionarios[i]->getHorasExtras() << endl;
            cout << "Salário mensal: " << funcionarios[i]->calcularSalarioMensal() << endl;
            cout << "Descontos imposto de renda: " << funcionarios[i]->descontosImpostoRenda() << endl;
            cout << "Descontos previdência social: " << funcionarios[i]->descontosPrevidenciaSocial() << endl;
            cout << "Salário líquido: " << funcionarios[i]->calcularSalarioMensal() - funcionarios[i]->descontosImpostoRenda() - funcionarios[i]->descontosPrevidenciaSocial() << endl << endl;
            
        }
    }

    cout << "O valor total da folha salarial é de R$ " << folhaSalarial[mes - 1] << endl;

    cout << "Pressione qualquer tecla para continuar" << endl;
    getchar();
    system(CLEAR);
}

void Salarios::calcularFolhaSalarialFuncionario()
{

    string nome, nomeLow;
    int cod, codTeste;
    int opcao;

    //escolher entre pesquisar por código ou por nome
    do
    {    
        cout << "Deseja pesquisar o funcionário por nome ou código?" << endl
            << "\t1 - Nome (ou parte do nome)" << endl
            << "\t2 - Código" << endl;
        
        cout << "Digite: ";
        cin >> opcao;
        cin.ignore();

        if (opcao != 1 && opcao != 2)
        {
            cout << "Opção inválida!" << endl;
        }
    }
    while (opcao != 1 && opcao != 2);

    if (opcao == 1)
    {
        cout << "Digite o nome (ou parte do nome) do funcionário que deseja buscar: ";
        getline(cin, nome);
    }
    else if (opcao == 2)
    {
        cout << "Digite o código do funcionário que deseja buscar: ";
        cin >> codTeste;
    }

    for (int i = 0; i < funcionarios.size(); i++)
    {
        nomeLow = funcionarios[i]->getNome();
        transform(nomeLow.begin(), nomeLow.end(), nomeLow.begin(), ::tolower);
    
        cod = funcionarios[i]->getCodigo();

        if (nomeLow.find(nome) != -1 || cod == codTeste)
        {
            cout << "Folha salarial do funcionário " << funcionarios[i]->getNome() << ":" << endl << endl;

            cout << "Salário base: R$ " << funcionarios[i]->getSalario() << endl;
            cout << "Salário mensal: R$ " << funcionarios[i]->calcularSalarioMensal() << endl;
            cout << "Desconto referente ao imposto de renda: R$ " << funcionarios[i]->descontosImpostoRenda() << endl;
            cout << "Desconto referente a previdência social: R$ " << funcionarios[i]->descontosPrevidenciaSocial() << endl;
            cout << "Desconto salarial total : R$ " << funcionarios[i]->descontosImpostoRenda() + funcionarios[i]->descontosPrevidenciaSocial() << endl;
            cout << "Salário líquido: R$ " << funcionarios[i]->calcularSalarioMensal() - funcionarios[i]->descontosImpostoRenda() - funcionarios[i]->descontosPrevidenciaSocial() << endl;
        }
    }

    cout << "Pressione qualquer tecla para continuar" << endl;
    getchar();
    system(CLEAR);
}

void Salarios::imprimirFolhaSalarialEmpresa()
{

    int opcao;
    double folha = 0;

    do
    {

        cout << "Qual folha salarial deseja buscar?" << endl << endl
            << " 1 - Anual " << endl
            << " 2 - mensal " << endl
            << endl;
         
        cout << "opção: ";
        cin >> opcao;
        cin.ignore();  

        if (opcao > 2 || opcao < 1)
        {
            cout << "Opção inválida, por favor, tente novamente." << endl;
        }

    }
    while (opcao > 2 || opcao < 1);
    
    switch (opcao)
    {
        case 1:
            for (int i = 0; i < 12; i++)
            {
                folha += folhaSalarial[i];
            }
        
            break;
        case 2:
            do
            {
                cout << "Digite o mês o qual deseja buscar: ";
                cout << endl;

                cout << "opção: ";
                cin >> opcao;
                cin.ignore();

                if (opcao < 1 || opcao > 12)
                {
                    cout << "Opção inválida, por favor, tente novamente" << endl;
                }

            }
            while (opcao < 1 || opcao > 12);

            folha = folhaSalarial[opcao];
            
            break;
        default:
            break;
    }

    cout << "Total calculado: R$ " << folha << endl;
}