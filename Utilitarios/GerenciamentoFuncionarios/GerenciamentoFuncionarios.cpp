#include "GerenciamentoFuncionarios.h"
#include "../../Menu/MainMenu.h"

#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

using namespace std;

GerenciamentoFuncionarios::GerenciamentoFuncionarios()
{ 

}

GerenciamentoFuncionarios::~GerenciamentoFuncionarios()
{ 

}

void GerenciamentoFuncionarios::cadastrarFuncionarios()
{
    //variáveis auxiliares para a criação de um funcionário
    int cod;
    string nome;
    Endereco end;
    string tel;
    Data dtIngr;
    string desig;
    double sal;
    Funcionario *func;

    bool sair = false;
    //criação de vários funcionários
    do
    {
        //leitura dos dados do funcionário
        cout << "Cadastro de Funcionário" << endl;
        do
        {
            cout << "Digite o código do funcionário. ";
            cout << "OBS.: São aceitos apenas códigos com números maiores que zero." << endl;
            cout << "Código: ";
            cin >> cod;
            cin.ignore();
            if (cod <= 0)
            {
                cout << "Desculpe o transtorno! O código precisa ser um número positivo." << endl << endl;
            }
            for (int i = 0; i < funcionarios.size(); i++)
            {
                if (cod == funcionarios[i]->getCodigo())
                {
                    cout << "Já existe um funcionário com esse código. Por favor, tente novamente!" << endl << endl;
                }
            }
        }
        while (cod <= 0);
        
        cout << endl;
        cout << "Digite o nome do funcionário: ";
        getline(cin, nome);

        cout << endl;
        end.lerEndereco();
        
        cout << endl << endl;
        cout << "Digite o telefone do funcionário: ";
        getline(cin, tel);

        cout << "\nSobre a data de ingresso do funcionário" << endl << endl;
        dtIngr.lerData();

        cout << endl;
        cout << "Digite a designação do funcionário: ";
        getline(cin, desig);
        transform(desig.begin(), desig.end(), desig.begin(), ::tolower);

        cout << "Digite o salário do funcionário: ";
        cin >> sal;
        cin.ignore();

        // casting
        if (desig == "operador")
        {
            Operador* func = new Operador();
            desig = "Operador";
            funcionarios.push_back(new Operador(cod, nome, end, tel, dtIngr, desig, sal));
        }

        else if (desig == "gerente")
        {
            Gerente* func = new Gerente();
            desig = "Gerente";
            string area;
            cout << "Digite a área de supervisão do gerente: ";
            getline(cin, area);
            func->setAreaSupervisaoGerente(area);
            funcionarios.push_back(new Gerente(cod, nome, end, tel, dtIngr, desig, sal, area));
        }

        else if (desig == "diretor")
        {
            Diretor* func = new Diretor();
            desig = "Diretor";
            string areaSupervisao;
            string areaFormacao;
            cout << "Digite a área de supervisão do diretor: ";
            getline(cin, areaSupervisao);
            func->setAreaSupervisaoDiretor(areaSupervisao);

            cout << "Digite a área de formação do diretor: ";
            getline(cin, areaFormacao);
            func->setAreaSupervisaoDiretor(areaFormacao);

            funcionarios.push_back(new Diretor(cod, nome, end, tel, dtIngr, desig, sal, areaSupervisao, areaFormacao));
        }

        else if (desig == "presidente")
        {
            Presidente* func = new Presidente();
            desig = "Presidente";
            string formacaoAcademica;
            string areaFormacao;

            cout << "Digite a formação acadêmica do presidente: ";

            getline(cin, formacaoAcademica);
            func->setFormacaoAcademicaPresidente(formacaoAcademica);

            cout << "Digite a área de formação do presidente: ";

            getline(cin, areaFormacao);
            func->setAreaFormacaoPresidente(areaFormacao);
            funcionarios.push_back(new Presidente(cod, nome, end, tel, dtIngr, desig, sal,formacaoAcademica,areaFormacao));
        }

        cout << endl << "Funcionário cadastrado com sucesso!" << endl;
        cout << endl << endl;

        cout << "Digite 1 para cadastrar um novo funcionário ou 0 para retornar ao menu principal." << endl;
        cout << "Deseja cadastrar outro funcionário? ";
        cin >> sair;
        cout << endl;
        cin.ignore();
    }   
    while(sair);
    system(CLEAR);
}

void GerenciamentoFuncionarios::lerArquivoCadastroFuncionario()
{
    // ler do arquivo "Arquivos/Cadastro de Funcionarios.txt" os funcionários já cadastrados manualmente
    fstream fs;

    fs.open("Arquivos/CadastroDeFuncionarios.txt", ios::in);
    if (fs.is_open())
    { 
        // variável auxiliar à leitura do arquivo
        string linha;

        // variáveis auxiliares para a criação de um funcionário
        int cod;
        string nome;
        Endereco end;
        string rua, numero, bairro, cidade, estado, cep;
        string tel;
        Data dtIngr;
        int dia, mes, ano;
        string desig;
        double sal;

        Funcionario *func;

        bool sair = false;
        // criação de vários funcionários
        do
        {
            try
            {
                // leitura dos dados do funcionários
                // CODIGO
                getline(fs, linha);
                istringstream(linha) >> cod;

                // NOME
                getline(fs, linha);
                nome = linha;

                // ENDEREÇO
                getline(fs, linha);
                rua = linha;
                getline(fs, linha);
                numero = linha;
                getline(fs, linha);
                bairro = linha;
                getline(fs, linha);
                cidade = linha;
                getline(fs, linha);
                estado = linha;
                getline(fs, linha);
                cep = linha;
                end = Endereco(rua, numero, bairro, cidade, estado, cep);

                // TELEFONE            
                getline(fs, linha);
                tel = linha;

                // DATA
                getline(fs, linha);
                istringstream(linha) >> dia;
                
                getline(fs, linha);
                istringstream(linha) >> mes;
                
                getline(fs, linha);
                istringstream(linha) >> ano;
                
                dtIngr = Data(dia, mes, ano);

                // DESIGNAÇÃO
                getline(fs, linha);
                desig = linha;
                transform(desig.begin(), desig.end(), desig.begin(), ::tolower);

                // SALÁRIO
                getline(fs, linha);
                istringstream(linha) >> sal;
                
            }
            catch(int x)
            {
                cout << "ERRO " << x << "." << endl;
                cout << "Não foi possível converter o tipo para string." << endl;
            }

            // casting
            if (desig == "operador")
            {
                Operador* func = new Operador();
                desig = "Operador";
                funcionarios.push_back(new Operador(cod, nome, end, tel, dtIngr, desig, sal));
            }

            else if (desig == "gerente")
            {
                Gerente* func = new Gerente();
                desig = "Gerente";
                string area;
                getline(fs, linha);
                area = linha;
                funcionarios.push_back(new Gerente(cod, nome, end, tel, dtIngr, desig, sal, area));
            }

            else if (desig == "diretor")
            {
                Diretor* func = new Diretor();
                desig = "Diretor";
                string areaSupervisao;
                string areaFormacao;
                getline(fs, linha);
                areaSupervisao = linha;

                getline(fs, linha);
                areaFormacao = linha;

                funcionarios.push_back(new Diretor(cod, nome, end, tel, dtIngr, desig, sal, areaSupervisao, areaFormacao));
            }

            else if (desig == "presidente")
            {
                Presidente* func = new Presidente();
                desig = "Presidente";
                string formacaoAcademica;
                string areaFormacao;

                getline(fs, linha);
                formacaoAcademica = linha;

                getline(fs, linha);
                areaFormacao = linha;

                funcionarios.push_back(new Presidente(cod, nome, end, tel, dtIngr, desig, sal, formacaoAcademica, areaFormacao));
            }

            cout << endl << "Funcionário(s) cadastrado(s) com sucesso!" << endl;
            cout << endl << endl;
        }
        while(!fs.eof());
    }
    else
    {
        cout << "Erro ao abrir arquivo" << endl;
    }
    fs.close();
}

void GerenciamentoFuncionarios::EscreverArquivoCadastroFuncionario()
{
    fstream arq;

    arq.open("Arquivos/CadastroDeFuncionarios.txt", ios::out);
    if (arq.is_open())
    {
        //escrever no arquivo todos os funcionarios cadastrados
        for (int i = 0; i < funcionarios.size(); i++)
        {
            arq << funcionarios[i]->toString();
        }
    }
    arq.close();
}

void GerenciamentoFuncionarios::listarFuncionarios()
{
    //exibir todos os funcionarios cadastrados
    for (int i = 0; i < funcionarios.size(); i++)
    {
        if (funcionarios[i]->getDesignacao() == "Operador")
        {
            ((Operador*)funcionarios[i])->exibirRegistroFuncionario();
            cout << endl;
        }
        
        else if (funcionarios[i]->getDesignacao() == "Gerente")
        {
            ((Gerente*)funcionarios[i])->exibirRegistroFuncionario();
            cout << endl;
        }

        else if (funcionarios[i]->getDesignacao() == "Diretor")
        {
            ((Diretor*)funcionarios[i])->exibirRegistroFuncionario();
            cout << endl;
        }

        else  if (funcionarios[i]->getDesignacao() == "Presidente")
        {
            ((Presidente*)funcionarios[i])->exibirRegistroFuncionario();
            cout << endl;
        }
        cout << endl;
    }

    //salvar todos os funcionarios cadastrados em um arquivo
    int salvar;
    do
    {
        cout << endl << "Deseja salvar os dados dos funcionarios em um arquivo?" << endl;
        cout << "Digite 1 para salvar os dados dos funcionarios ou 0 para retornar ao menu principal: ";
        cin >> salvar;
        cin.ignore();
        
        if (salvar == 1)
        {
            EscreverArquivoCadastroFuncionario();
            cout << endl << "Arquivo criado com sucesso!" << endl;
        }
    }
    while (salvar != 1 && salvar != 0);
    


    cout << "Pressione ENTER para continuar" << endl;
    getchar();
    system(CLEAR);
}

void GerenciamentoFuncionarios::listarFuncionariosTipo()
{
    // exibir todos os funcionarios cadastrados dependendo do tipo de funcionario especificado pelo usuario
    string tipoDesejado, tipoComparacao;

    cout << "Digite a designação de funcionário que deseja listar: ";
    // cin.ignore();
    getline(cin, tipoDesejado);
    transform(tipoDesejado.begin(), tipoDesejado.end(), tipoDesejado.begin(), ::tolower);

    for (int i = 0; i < funcionarios.size(); i++)
    {
        tipoComparacao = funcionarios[i]->getDesignacao();
        transform(tipoComparacao.begin(), tipoComparacao.end(), tipoComparacao.begin(), ::tolower);

        if (tipoComparacao == tipoDesejado && tipoDesejado == "operador")
        {
            ((Operador*)funcionarios[i])->exibirRegistroFuncionario();
        
        }
        
        else if (tipoComparacao == tipoDesejado && tipoDesejado == "gerente")
        {
            ((Gerente*)funcionarios[i])->exibirRegistroFuncionario();
        
        }
        
        else if (tipoComparacao == tipoDesejado && tipoDesejado == "diretor")
        {
            ((Diretor*)funcionarios[i])->exibirRegistroFuncionario();
        
        }
        
        else if (tipoComparacao == tipoDesejado && tipoDesejado == "presidente")
        {
            ((Presidente*)funcionarios[i])->exibirRegistroFuncionario();
        
        }
        cout << endl;
    }
    cout << endl;
    cout << "Pressione ENTER para continuar" << endl;
    getchar();
    system(CLEAR);
}

void GerenciamentoFuncionarios::exibirRegistroFuncionario()
{
    int codigoBuscado;
    cout << "Digite o código do funcionário a ser buscado: ";
    cin >> codigoBuscado;
    cin.ignore();

    for (int i = 0; i < funcionarios.size(); i++)
    {
        if (funcionarios[i]->getCodigo() == codigoBuscado)
        {
            funcionarios[i]->exibirRegistroFuncionario();
            cout << endl;
        }
    }
    
    cout << "Pressione ENTER para sair" << endl;
    getchar();
    system(CLEAR);
}

void GerenciamentoFuncionarios::alterarRegistroFuncionario()
{
    // variáveis auxiliares para a alteração de um funcionário
    int cod;
    string str;
    Endereco end;
    Data dt;
    double sal;

    // bool auxiliar
    bool novaAlteracao = true;
    bool sair = false;
    bool primeiraVez = true;
    do
    {
        // perguntar apenas se o usuário deseja fazer nova alteração
        if (novaAlteracao && primeiraVez) // != 0
        {
            // leitura do código do funcionário a ser alterado
            cout << "Digite o código do funcionário cujo registro deve ser alterado." << endl;
            cout << "Caso não queira alterar algum registro, digite 0." << endl;
            cout << "Código: ";
            cin >> cod;
            cin.ignore();
        }

        if (cod) // != 0
        {
            bool existeFuncionario = false;   //confirma se existe um funcionário com um código digitado pelo usuário
            for (int i = 0; i < funcionarios.size(); i++)
            {            
                // condição para alterar o funcionário: o código digitado pelo usuário ao código do funcionário a ser alterado
                if (cod == funcionarios[i]->getCodigo()) 
                {
                    existeFuncionario = true;
                    int opcao;
                    cout << "Digite a informação que deseja alterar: " << endl;
                    cout << "\t1 - Nome" << endl;
                    cout << "\t2 - Endereço" << endl;
                    cout << "\t3 - Telefone" << endl;
                    cout << "\t4 - Data de ingresso" << endl;
                    cout << "\t5 - Designação" << endl;
                    cout << "\t6 - Salário" << endl;
                    cout << "\t0 - Sair" << endl;
                    
                    cin >> opcao;
                    cin.ignore();

                    switch (opcao)
                    {
                        case 1:
                            cout << "Digite o novo nome: ";
                            getline(cin, str);
                            funcionarios[i]->setNome(str);
                            break;
                        case 2:
                            end.lerEndereco();
                            funcionarios[i]->setEndereco(end);
                            break;
                        case 3:
                            cout << "Digite o novo telefone: ";
                            getline(cin, str);
                            funcionarios[i]->setTelefone(str);
                            break;
                        case 4:
                            dt.lerData();
                            funcionarios[i]->setDataIngresso(dt);
                            break;
                        case 5:
                            if (funcionarios[i]->getDesignacao() == "Presidente" 
                                || funcionarios[i]->getDesignacao() == "Diretor")
                            {
                                cout << "Desculpe. Não podemos alterar a designação do " << funcionarios[i]->getDesignacao() << "." << endl;
                                break;
                            }
                            
                            cout << "Digite a nova designação: ";
                            getline(cin, str);
                            transform(str.begin(), str.end(), str.begin(), ::tolower);

                            // casting

                            if (str == "operador")
                            {
                                Operador* func = dynamic_cast<Operador*>(funcionarios[i]);
                                str = "Operador";
                                //Cria-se um novo funcionário com as novas informações
                                funcionarios.push_back(new Operador(funcionarios[i]->getCodigo(),
                                                                    funcionarios[i]->getNome(), 
                                                                    funcionarios[i]->getEndereco(), 
                                                                    funcionarios[i]->getTelefone(),
                                                                    funcionarios[i]->getDataIngresso(), 
                                                                    str, funcionarios[i]->getSalario()));

                                // Método para excluir os funcionários alterados
                                funcionarios[i]->setCodigo(0);
                                excluirRegistroFuncionario(0);
                                break;
                            }

                            else if (str == "gerente")
                            {
                                Gerente* func = dynamic_cast<Gerente*>(funcionarios[i]);
                                str = "Gerente";

                                string areaSupervisaoGerente;

                                cout << "Digite a área de supervisão do gerente: ";
                                getline(cin, areaSupervisaoGerente);
                                //Cria-se um novo funcionário com as novas informações
                                funcionarios.push_back(new Gerente(funcionarios[i]->getCodigo(),
                                                                    funcionarios[i]->getNome(), 
                                                                    funcionarios[i]->getEndereco(), 
                                                                    funcionarios[i]->getTelefone(),
                                                                    funcionarios[i]->getDataIngresso(),
                                                                    str, funcionarios[i]->getSalario(),
                                                                    areaSupervisaoGerente));
                                // Método para excluir os funcionários alterados
                                funcionarios[i]->setCodigo(0);
                                excluirRegistroFuncionario(0);
                                break;
                            }

                            else if (str == "diretor")
                            {
                                Diretor* func = dynamic_cast<Diretor*>(funcionarios[i]);
                                str = "Diretor";

                                string areaSupervisaoDiretor, areaFormacaoDiretor;
                                
                                cout << "Digite a área de supervisão do diretor: ";
                                getline(cin, areaSupervisaoDiretor);

                                cout << "Digite a área de formação do diretor: ";
                                getline(cin, areaFormacaoDiretor);
                                //Cria-se um novo funcionário com as novas informações
                                funcionarios.push_back(new Diretor( funcionarios[i]->getCodigo(),
                                                                    funcionarios[i]->getNome(), 
                                                                    funcionarios[i]->getEndereco(), 
                                                                    funcionarios[i]->getTelefone(),
                                                                    funcionarios[i]->getDataIngresso(),
                                                                    str, funcionarios[i]->getSalario(),
                                                                    areaSupervisaoDiretor, areaFormacaoDiretor));

                                // Método para excluir os funcionários alterados
                                funcionarios[i]->setCodigo(0);
                                excluirRegistroFuncionario(0);
                                break;
                            }

                            else if (str == "presidente")
                            {
                                Presidente* func = dynamic_cast<Presidente*>(funcionarios[i]);
                                str = "Presidente";

                                string formacaoAcademica;
                                string areaFormacaoPresidente;

                                cout << "Digite a formação acadêmica do presidente: ";
                                getline(cin, formacaoAcademica);

                                cout << "Digite a área de formação do presidente: ";
                                getline(cin, areaFormacaoPresidente);
                                //Cria-se um novo funcionário com as novas informações
                                funcionarios.push_back(new Presidente(funcionarios[i]->getCodigo(),
                                                                        funcionarios[i]->getNome(), 
                                                                        funcionarios[i]->getEndereco(), 
                                                                        funcionarios[i]->getTelefone(),
                                                                        funcionarios[i]->getDataIngresso(),
                                                                        str, funcionarios[i]->getSalario(),
                                                                        formacaoAcademica, areaFormacaoPresidente));

                                // Método para excluir os funcionários alterados
                                funcionarios[i]->setCodigo(0);
                                excluirRegistroFuncionario(0);
                                break;
                            }
                            
                            break;
                        case 6:
                            cout << "Digite o novo salário: ";
                            cin >> sal;
                            cin.ignore();
                            funcionarios[i]->setSalario(sal);
                            break;
                        case 0:
                            sair = true;
                            break;
                        default:
                            cout << "Opção inválida!" << endl;
                            break;
                    }
                }
                else if (i == funcionarios.size() - 1 && !existeFuncionario)
                {

                    cout << "Desculpe. Não encontramos um funcionário com esse código." << endl;
                    cout << "Quer tentar um outro código?" << endl
                         << "\t1 - Sim" << endl
                         << "\t0 - Não" << endl;
                    cout << "\tDigite aqui: ";

                    cin >> novaAlteracao;
                    cin.ignore();

                }
            }
            if (existeFuncionario && !sair) // se encontrou o funcionário do código buscado
            {
                cout << "Deseja fazer outra alteração?" << endl;
                cout << "\t1 - Sim" << endl;
                cout << "\t0 - Não" << endl;
                cin >> novaAlteracao;
                cin.ignore();
            }
        }
        else    // caso o código do funcionário seja igual a zero
        {
            break;
        }
        system(CLEAR);
        //novaAlteracao = 0;  //comando auxiliar para sair do loop caso o codigo digitado seja 0
    }
    while (novaAlteracao);

    cout << "Digite ENTER para continuar" << endl;
    getchar();
    system(CLEAR);
}

void GerenciamentoFuncionarios::excluirRegistroFuncionario()
{
    //excluir um funcionario, dado o seu código
    int cod;
    int opcao = 0;

    do
    {
        cout << "Digite o código do funcionário que deseja excluir."  << endl;
        cout << "Caso não queira excluir algum registro, digite 0." << endl;
        cout << "Código: ";
        cin >> cod;
        cin.ignore();
        
        if(cod)
        {
            for (int i = 0; i < funcionarios.size(); i++)
            {
                //verificar se o codigo digitado pertence a algum funcionario, caso contrário, exibe mensagem de erro
                if(i == (funcionarios.size() - 1) && funcionarios[i]->getCodigo() != cod)
                {
                    cout << "Não existe um funcionário com esse código!" << endl;
                    
                    //tentar novamente
                    cout << "Deseja tentar novamente?" << endl;
                    cout << "\t1 - Sim" << endl;
                    cout << "\t0 - Não" << endl;
                    cin >> opcao;
                    cin.ignore();
                    break;
                }

                if (funcionarios[i]->getCodigo() == cod)
                {
                    //Designações iguais a "presidente" e "diretor" não podem ser excluídas
                    if (funcionarios[i]->getDesignacao() == "Presidente")
                    {
                        cout << "Não é possível excluir o presidente!" << endl;
                        break;
                    }
                    else if (funcionarios[i]->getDesignacao() == "Diretor")
                    {
                        cout << "Não é possível excluir o diretor!" << endl;
                        break;
                    }
                    else
                    {
                        funcionarios.erase(funcionarios.begin() + i);
                        cout << "Funcionário excluído com sucesso!" << endl;
                        opcao = 0;
                        break;
                    }
                }
            }
        }
    }
    while(opcao);
    
    cout << "Pressione ENTER para continuar" << endl;
    getchar();
    system(CLEAR);
}

void GerenciamentoFuncionarios::excluirRegistroFuncionario(int codigo)
{
    //excluir um funcionario, dado o seu código
    int opcao = 0;

    do
    {

        if (!codigo)
        {
            for (int i = 0; i < funcionarios.size(); i++)
            {
                //verificar se o codigo digitado pertence a algum funcionario, caso contrário, exibe mensagem de erro
                if (i == (funcionarios.size() - 1) && funcionarios[i]->getCodigo() != codigo)
                {
                    cout << "Não existe um funcionário com esse código!" << endl;
                    
                    //tentar novamente
                    cout << "Deseja tentar novamente?" << endl;
                    cout << "\t1 - Sim" << endl;
                    cout << "\t0 - Não" << endl;
                    cin >> opcao;
                    cin.ignore();
                    break;
                }

                if (funcionarios[i]->getCodigo() == codigo)
                {
                    //Designações iguais a "presidente" e "diretor" não podem ser excluídas
                    if (funcionarios[i]->getDesignacao() == "Presidente")
                    {
                        cout << "Não é possível excluir o presidente!" << endl;
                        break;
                    }
                    else if (funcionarios[i]->getDesignacao() == "Diretor")
                    {
                        cout << "Não é possível excluir o diretor!" << endl;
                        break;
                    }
                    else
                    {
                        funcionarios.erase(funcionarios.begin() + i);
                        //cout << "Funcionário excluído com sucesso!" << endl;
                        opcao = 0;
                        break;
                    }
                }
            }
        }
    }
    while (opcao);
    
    //getchar();
    //system(CLEAR);
}

void GerenciamentoFuncionarios::exibirMenuBusca()
{
    cout << "Digite a opção de busca: " << endl;
    cout << "\t1 - Nome" << endl;
    cout << "\t2 - Endereço" << endl;
    cout << "\t3 - Data de ingresso" << endl;
    cout << "\t0 - Sair" << endl;
}

void GerenciamentoFuncionarios::buscarFuncionario()
{
    //buscar o registro de um funcionário dado parte de seu nome ou parte de seu endereço ou pelo intervalo de tempo que compreende a sua data de ingresso
    int opcao;
    do
    {
        exibirMenuBusca();
        
        cin >> opcao;
        cin.ignore();
        
        switch (opcao)
        {
            case 1:
                buscarFuncionarioNome();
                break;
            case 2:
                buscarFuncionarioEndereco();
                break;
            case 3:
                buscarFuncionarioDataIngresso();
                break;
            case 0:
                return;
            default:
                cout << "Opção inválida!" << endl;
                break;
        }
    }
    while (opcao);

    cout << "Pressione ENTER para continuar" << endl;
    getchar();
    system(CLEAR);
}

void GerenciamentoFuncionarios::buscarFuncionarioNome()
{
    //buscar um funcionário dado parte de seu nome
    string nome;
    cout << "Digite um nome (ou parte do nome) do funcionário que deseja buscar: ";
    getline(cin, nome);
    transform(nome.begin(), nome.end(), nome.begin(), ::tolower);

    string teste;
    for (int i = 0; i < funcionarios.size(); i++)
    {
        teste = funcionarios[i]->getNome();
        transform(teste.begin(), teste.end(), teste.begin(), ::tolower);
        if(teste.find(nome) != -1)
        {
            funcionarios[i]->exibirRegistroFuncionario();
            cout << endl;
        }
    }
    cout << "Pressione ENTER para continuar" << endl;
    getchar();
    system(CLEAR);
}

void GerenciamentoFuncionarios::buscarFuncionarioEndereco()
{
    //buscar um funcionário dado parte de seu endereço

    //endereco é a concatenação de todos os campos do endereço
    string endereco, enderecoDesejado, teste;

    cout << "Digite um endereço (ou parte do endereço) do funcionário que deseja buscar: ";
    getline(cin, enderecoDesejado);
    transform(enderecoDesejado.begin(), enderecoDesejado.end(), enderecoDesejado.begin(), ::tolower);

    for (int i = 0; i < funcionarios.size(); i++)
    {
        endereco = funcionarios[i]->getEndereco().getRua() + ", " + 
          (string) funcionarios[i]->getEndereco().getNumero() + ", " + 
                   funcionarios[i]->getEndereco().getBairro() + ", " + 
                   funcionarios[i]->getEndereco().getCidade() + ", " + 
                   funcionarios[i]->getEndereco().getEstado();
        
        teste = endereco;
        transform(teste.begin(), teste.end(), teste.begin(), ::tolower);

        if (teste.find(enderecoDesejado) != -1)
        {
            funcionarios[i]->exibirRegistroFuncionario();
            cout << endl;
        }
        
        //procurar pelo cep
        if (enderecoDesejado == funcionarios[i]->getEndereco().getCep())
        {
            buscarFuncionarioCep(i);
            cout << endl;
        }
    }
    cout << "Pressione ENTER para continuar" << endl;
    getchar();
    system(CLEAR);
}

void GerenciamentoFuncionarios::buscarFuncionarioCep(int i)
{
    string cep, url, command;

    /* cout << "Digite o cep: ";
    getline (cin, cep); */
    cep = funcionarios[i]->getEndereco().getCep();

    url = "viacep.com.br/ws/" + cep + "/json/";

    /* cout << "url: " << url << endl; */

    command = "wget -O cep.txt " + url + " -q";
    /* cout << "command: " << command << endl; */

    system(command.c_str()); // aqui ele entra num loop no codeblocks
    parseCEP();

    cout << endl;
    funcionarios[i]->exibirRegistroFuncionario();
    
}

void GerenciamentoFuncionarios::parseCEP()
{
    fstream fs;
    string linha, dado, rua, bairro, cidade, uf;
    fs.open("cep.txt", fstream::in);

    if (!fs.is_open())
    {
        cout << "Erro ao abrir arquivo" << endl;
        return;
    }

    int i = 0, pos2pt = 0;
    while(!fs.eof())
    {
        getline(fs, linha);
        if (i == 2 || i == 4 || i == 5 || i == 6)
        {
            pos2pt = linha.find(':');
            dado = linha.substr(pos2pt + 3, linha.size() - 2 - pos2pt - 3);

            // dado = sub.substr(0, dado.size() - 2); // outra alternativa
            // cout << linha << endl; // para teste
            cout << dado << endl;
            switch (i) // poderia ser if else, mas switch case deixa mais elegante
            {
                case 2:
                    rua = dado;
                    break;
                case 4:
                    bairro = dado;
                    break;
                case 5:
                    cidade = dado;
                    break;
                case 6:
                    uf = dado;
                    break;
                default:
                    break;
            }
        }
        i++;
    }
}

void GerenciamentoFuncionarios::buscarFuncionarioDataIngresso()
{
    //buscar um funcionário dado o intervalo de tempo que compreende a sua data de ingresso
    Data dtInicio, dtFim;
    cout << "Digite a data de início do intervalo: " << endl;
    dtInicio.lerData();
    cout << "Digite a data de fim do intervalo: " << endl;
    dtFim.lerData();

    for (int i = 0; i < funcionarios.size(); i++)
    {
        if (         funcionarios[i]->getDataIngresso().getDia()
            + 31*   (funcionarios[i]->getDataIngresso().getMes() - 1) 
            + 31*12*(funcionarios[i]->getDataIngresso().getAno()) >= 
                     dtInicio.getDia() 
            + 31*   (dtInicio.getMes() - 1) 
            + 31*12*(dtInicio.getAno() - 1) &&
                     funcionarios[i]->getDataIngresso().getDia() 
            + 31*   (funcionarios[i]->getDataIngresso().getMes() - 1) 
            + 31*12*(funcionarios[i]->getDataIngresso().getAno()) <=    
                     dtFim.getDia() 
            + 31*   (dtFim.getMes() - 1)  
            + 31*12*(dtFim.getAno()))
        {
            funcionarios[i]->exibirRegistroFuncionario();
            cout << endl;
        }
        else
        {
            cout << "Funcionário não encontrado!" << endl;
        }
    }
    cout << "Pressione ENTER para continuar" << endl;
    getchar();
    system(CLEAR);
}