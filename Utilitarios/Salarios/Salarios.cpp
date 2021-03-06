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
        //gerar semente para achar valor aleatório
        srand(time(NULL));

        int qtdMaxHorasMensais = rand() % (176 + 88);    //176 horas normais + 88 horas extras

        if(qtdMaxHorasMensais >= 0 && qtdMaxHorasMensais <= 176)
        {
            normais = qtdMaxHorasMensais;
            funcionarios[i]->setHorasNormais(normais);
            extras = 0;
            funcionarios[i]->setHorasExtras(extras);
        }
        else if (qtdMaxHorasMensais > 176)
        {
            normais = 176;
            funcionarios[i]->setHorasNormais(normais);
            extras = qtdMaxHorasMensais - 176;
            funcionarios[i]->setHorasExtras(extras);
            extras = 0;
        }

        Sleep(256);
    }
}

void Salarios::calcularFolhaSalarial()
{   
    int mes;

    do
    {
        cout << "Escolha um mês para calcular a folha salarial de 2022." << endl
             << "Número do mês escolhido: ";
        cin >> mes;
        cin.ignore();

        cout << endl << endl;
        if (mes < 1 || mes > 12 ) 
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
                 << " - Salário base: " << fixed << setprecision(2) << funcionarios[i]->getSalario() << endl << endl;

            //atribuir a quantidade de horas trabalhadas no mês com a função de gerar horas aleatórias
            cout << "Aguarde um pouco, estamos gerando o salário de " << funcionarios[i]->getNome() << "..." << endl;
            if((funcionarios[i]->getDataIngresso().getAno() == 2022 && funcionarios[i]->getDataIngresso().getMes() <= mes+1)
                || funcionarios[i]->getDataIngresso().getAno() < 2022)
            {
                gerarHorasAleatorias();
            }
            else
            {
                cout << "O funcionário entrou na empresa após o mês cuja folha está sendo calculada" << endl << endl;
                funcionarios[i]->setHorasNormais(0);
                funcionarios[i]->setHorasExtras(0);
            }
            funcionarios[i]->setSalarioMensal(funcionarios[i]->calcularSalarioMensal());
            double salarioAuxiliar = funcionarios[i]->getSalarioMensal();
            double salarioLiquido = salarioAuxiliar - funcionarios[i]->descontosImpostoRenda(salarioAuxiliar) - funcionarios[i]->descontosPrevidenciaSocial(salarioAuxiliar);
            
            cout << "Horas normais trabalhadas: " << funcionarios[i]->getHorasNormais() << endl
                << "Horas extras trabalhadas: " << funcionarios[i]->getHorasExtras() << endl
                << "Salário mensal: " << fixed << setprecision(2) << salarioAuxiliar << endl
                << "Descontos imposto de renda: " << fixed << setprecision(2) << funcionarios[i]->descontosImpostoRenda(salarioAuxiliar) << endl
                << "Descontos previdência social: " << fixed << setprecision(2) << funcionarios[i]->descontosPrevidenciaSocial(salarioAuxiliar) << endl
                << "Salário líquido: " << fixed << setprecision(2) << salarioLiquido << endl << endl;
            
            folhaSalarial[mes - 1] += salarioAuxiliar - funcionarios[i]->descontosImpostoRenda(salarioAuxiliar) - funcionarios[i]->descontosPrevidenciaSocial(salarioAuxiliar);
            folhaSalarialComImp[mes - 1] += salarioAuxiliar;
        }
    }

    cout << "O valor total da folha salarial deduzidos os impostos é de R$ " << fixed << setprecision(2) << folhaSalarial[mes - 1] << endl
         << "O valor total da folha salarial com os impostos é de R$ " << fixed << setprecision(2) << folhaSalarialComImp[mes - 1] << endl << endl;
    
    cout << "Pressione ENTER para continuar" << endl;
    getchar();
    system(CLEAR);
}

void Salarios::calcularFolhaSalarialFuncionario()
{

    string nome, nomeLow;
    int cod=0, codTeste;
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
        transform(nome.begin(), nome.end(), nome.begin(), ::tolower);
        codTeste = 0;
    }
    else if (opcao == 2)
    {
        cout << "Digite o código do funcionário que deseja buscar: ";
        cin >> codTeste;
        nome = "0";
    }

    for (int i = 0; i < funcionarios.size(); i++)
    {
        nomeLow = funcionarios[i]->getNome();
        transform(nomeLow.begin(), nomeLow.end(), nomeLow.begin(), ::tolower);
        cod = funcionarios[i]->getCodigo();

        if (nomeLow.find(nome) != -1 || cod == codTeste)
        {
            cout << "Funcionário encontrado." << endl;
            Sleep(529);
            cout << "Aguarde um pouco, estamos gerando o salário de " << funcionarios[i]->getNome() << "..." << endl;
            gerarHorasAleatorias();
            this->funcionarios[i]->setSalarioMensal(this->funcionarios[i]->calcularSalarioMensal());

            cout << "Folha salarial do funcionário " << funcionarios[i]->getNome() << ":" << endl << endl;

            cout << "Horas normais trabalhadas: " << funcionarios[i]->getHorasNormais() << endl
                 << "Horas extras trabalhadas: " << funcionarios[i]->getHorasExtras() << endl
                 << "Salário base: R$ " << fixed << setprecision(2) << funcionarios[i]->getSalario() << endl
                 << "Salário mensal: R$ " << fixed << setprecision(2) << funcionarios[i]->getSalarioMensal() << endl
                 << "Desconto referente ao imposto de renda: R$ " << fixed << setprecision(2) << funcionarios[i]->descontosImpostoRenda(funcionarios[i]->getSalarioMensal()) << endl
                 << "Desconto referente a previdência social: R$ " << fixed << setprecision(2) << funcionarios[i]->descontosPrevidenciaSocial(funcionarios[i]->getSalarioMensal()) << endl
                 << "Desconto salarial total : R$ " << fixed << setprecision(2) << funcionarios[i]->descontosImpostoRenda(funcionarios[i]->getSalarioMensal()) + funcionarios[i]->descontosPrevidenciaSocial(funcionarios[i]->getSalarioMensal()) << endl
                 << "Salário líquido: R$ " << fixed << setprecision(2) << funcionarios[i]->getSalarioMensal() - funcionarios[i]->descontosImpostoRenda(funcionarios[i]->getSalarioMensal()) - funcionarios[i]->descontosPrevidenciaSocial(funcionarios[i]->getSalarioMensal()) << endl;
        }
    }

    cout << "Pressione ENTER para continuar" << endl;
    getchar();
    getchar();
    system(CLEAR);
}

void Salarios::imprimirFolhaSalarialEmpresa()
{
    int opcao;
    double folha = 0, folhaComImp = 0;
    bool salvarArquivo = false;

    do
    {
        cout << "Qual folha salarial deseja buscar?" << endl << endl
            << " 1 - Anual " << endl
            << " 2 - Mensal " << endl
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
            int j;

            cout << "Aguarde um pouco, por favor. Estamos gerando a folha de salário anual. Deve demorar um pouco..." << endl;
            for (int j = 0; j < 12; j++)
            {
                for (int i = 0; i < funcionarios.size(); i++)
                {  
                    //atribuir a quantidade de horas trabalhadas no mês com a função de gerar horas aleatórias
                    if((funcionarios[i]->getDataIngresso().getAno() == 2022 && funcionarios[i]->getDataIngresso().getMes() <= j+1)
                        || funcionarios[i]->getDataIngresso().getAno() < 2022)
                    {
                        gerarHorasAleatorias();
                    }
                    else
                    {
                        cout << endl << "O funcionário " << funcionarios[i]->getNome() << " entrou na empresa após o mês " << j+1 << endl;
                        funcionarios[i]->setHorasNormais(0);
                        funcionarios[i]->setHorasExtras(0);
                    }
                    funcionarios[i]->setSalarioMensal(funcionarios[i]->calcularSalarioMensal());

                    double salarioLiquido = funcionarios[i]->getSalarioMensal() - funcionarios[i]->descontosImpostoRenda(funcionarios[i]->getSalarioMensal()) - funcionarios[i]->descontosPrevidenciaSocial(funcionarios[i]->getSalarioMensal());
                    
                    folhaSalarial[j - 1] += funcionarios[i]->getSalarioMensal() - funcionarios[i]->descontosImpostoRenda(funcionarios[i]->getSalarioMensal()) - funcionarios[i]->descontosPrevidenciaSocial(funcionarios[i]->getSalarioMensal());
                    folhaSalarialComImp[j - 1] += funcionarios[i]->getSalarioMensal();
                    
                    folha += folhaSalarial[j-1];
                    folhaComImp += folhaSalarial[j-1];
                }
            }
    
            cout << "O valor total da folha salarial deduzidos os impostos é de R$ " << fixed << setprecision(2) << folha << endl
                 << "O valor total da folha salarial com os impostos é de R$ " << fixed << setprecision(2) << folhaComImp << endl << endl;

            cout << "Desja salvar o arquivo da folha salarial anual?" << endl;
            cout << "\t1 - Sim" << endl
                 << "\t0 - Não" << endl;
            cin >> salvarArquivo;
            cin.ignore();

            if(salvarArquivo)
            {
                EscreverArquivoFolhaSalarial();
                cout << "Arquivo de folha salarial anual salvo com sucesso!" << endl << endl;
            }

            break;
        case 2:
            calcularFolhaSalarial();
            break;
            
        default:
            break;
    }
    cout << "Pressione ENTER para continuar" << endl;
    getchar();
    system(CLEAR);
}

void Salarios::concederAumentoSalarial()
{

    string tipoComparacao;
    double valorAumento;

    for (int i = 0; i < funcionarios.size(); i++)
    {
        tipoComparacao = funcionarios[i]->getDesignacao();
        transform(tipoComparacao.begin(), tipoComparacao.end(), tipoComparacao.begin(), ::tolower);

        if (tipoComparacao == "operador")
        {
            valorAumento = ((Operador*)funcionarios[i])->taxaAumento() * funcionarios[i]->getSalario();
            funcionarios[i]->setSalario(valorAumento + funcionarios[i]->getSalario());
            cout << "Concedido aumento de 5% para Operador!" << endl;
        }
        
        else if (tipoComparacao == "gerente")
        {
            valorAumento = ((Gerente*)funcionarios[i])->taxaAumento() * funcionarios[i]->getSalario();
            funcionarios[i]->setSalario(valorAumento + funcionarios[i]->getSalario());
            cout << "Concedido aumento de 10% para Gerente!" << endl;
        }
        
        else if (tipoComparacao == "diretor")
        {
            valorAumento = ((Diretor*)funcionarios[i])->taxaAumento() * funcionarios[i]->getSalario(); 
            funcionarios[i]->setSalario(valorAumento + funcionarios[i]->getSalario());
            cout << "Concedido aumento de 20% para Diretor!" << endl;
        }
        
        else if (tipoComparacao == "presidente")
        {
            valorAumento = ((Presidente*)funcionarios[i])->taxaAumento() * funcionarios[i]->getSalario();
            funcionarios[i]->setSalario(valorAumento + funcionarios[i]->getSalario());
            cout << "Concedido aumento de 30% para Presidente!" << endl;
        }
        
    }
    cout << endl;
    cout << "Aumento salarial concedido aos funcionários com sucesso." << endl;
    cout << "Pressione ENTER para continuar" << endl;
    getchar();
    system(CLEAR);
}

void Salarios::EscreverArquivoFolhaSalarial()
{
    fstream arq;
    double folha = 0, folhaComImp = 0;

    arq.open("Arquivos/FolhaSalarialAnual.txt", ios::out);
    if (arq.is_open())
    {
        //escrever no arquivo todas as folhas salariais do ano em análise
       for (int j = 0; j < 12; j++)
        {
            for (int i = 0; i < funcionarios.size(); i++)
            {  
                //atribuir a quantidade de horas trabalhadas no mês com a função de gerar horas aleatórias
                if((funcionarios[i]->getDataIngresso().getAno() == 2022 && funcionarios[i]->getDataIngresso().getMes() <= j+1)
                    || funcionarios[i]->getDataIngresso().getAno() < 2022)
                {
                    gerarHorasAleatorias();
                    arq << "Folha salarial do funcionário " << funcionarios[i]->getNome() << ", mês " << j+1 << ":" << endl << endl;

                    arq << "Horas normais trabalhadas: " << funcionarios[i]->getHorasNormais() << endl
                        << "Horas extras trabalhadas: " << funcionarios[i]->getHorasExtras() << endl
                        << "Salário base: R$ " << fixed << setprecision(2) << funcionarios[i]->getSalario() << endl
                        << "Salário mensal: R$ " << fixed << setprecision(2) << funcionarios[i]->getSalarioMensal() << endl
                        << "Desconto referente ao imposto de renda: R$ " << fixed << setprecision(2) << funcionarios[i]->descontosImpostoRenda(funcionarios[i]->getSalarioMensal()) << endl
                        << "Desconto referente a previdência social: R$ " << fixed << setprecision(2) << funcionarios[i]->descontosPrevidenciaSocial(funcionarios[i]->getSalarioMensal()) << endl
                        << "Desconto salarial total : R$ " << fixed << setprecision(2) << funcionarios[i]->descontosImpostoRenda(funcionarios[i]->getSalarioMensal()) + funcionarios[i]->descontosPrevidenciaSocial(funcionarios[i]->getSalarioMensal()) << endl
                        << "Salário líquido: R$ " << fixed << setprecision(2) << funcionarios[i]->getSalarioMensal() - funcionarios[i]->descontosImpostoRenda(funcionarios[i]->getSalarioMensal()) - funcionarios[i]->descontosPrevidenciaSocial(funcionarios[i]->getSalarioMensal()) << endl << endl;
                }
                else
                {
                    arq << endl;
                    arq << "OBS: O funcionário " << funcionarios[i]->getNome() << " entrou na empresa após o mês "<< j+1 << endl << endl;
                    funcionarios[i]->setHorasNormais(0);
                    funcionarios[i]->setHorasExtras(0);
                }

                funcionarios[i]->setSalarioMensal(funcionarios[i]->calcularSalarioMensal());

                double salarioLiquido = funcionarios[i]->getSalarioMensal() - funcionarios[i]->descontosImpostoRenda(funcionarios[i]->getSalarioMensal()) - funcionarios[i]->descontosPrevidenciaSocial(funcionarios[i]->getSalarioMensal());
                
                folhaSalarial[j - 1] += funcionarios[i]->getSalarioMensal() - funcionarios[i]->descontosImpostoRenda(funcionarios[i]->getSalarioMensal()) - funcionarios[i]->descontosPrevidenciaSocial(funcionarios[i]->getSalarioMensal());
                folhaSalarialComImp[j - 1] += funcionarios[i]->getSalarioMensal();
                
                folha += folhaSalarial[j-1];
                folhaComImp += folhaSalarial[j-1];
            }
        }
        arq << endl;
        arq << "O valor total da folha salarial deduzidos os impostos é de R$ " << fixed << setprecision(2) << folha << endl
            << "O valor total da folha salarial com os impostos é de R$ " << fixed << setprecision(2) << folhaComImp << endl << endl;
    }
    arq.close();
}