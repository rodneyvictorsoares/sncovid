#include <iostream>
#include <string>
#include <fstream>
#include <ctime>

using namespace std;

int main()
{
    system("color 0c");
    //Variaveis para definição de tempo
    time_t t = time(nullptr);
    tm* now = localtime(&t); //20231006 T 21:34:25:25 25184782
    int anoAtual = now->tm_year + 1900;
    string anoStr;
    int anoNascimento;
    int idadePaciente;

    //variaveis para efetuar o cadastro do paciente
    string paciente_nome, paciente_cpf, Endereco, Cidade, Bairro, CEP, dataNascimento, dataDiagnostico, Comorbidade, ComorbidadeAux, Email;
    //bool perigo = false;
    int possuiComorbidade;
    //int indiceComorbidade;
    
    //Variaveis para registro de dados
    string nomeArquivo = "123456";
    string linhaArquivo;
    string IdPaciente;
    ifstream arq;
    //ofstream arquivoSave(nomeArquivo, ofstream::out);

    //Variáveis para evento de login no sistema
    int user = 123456;
    int password = 654321;

    int infoUsuario;
    int infoSenha;

    bool isLogin = false;

    //Variaveis para controle do menu
    int escolha;
    bool exitapp = false;

    do
    {
        cout << "Digite o seu codigo de usuario: ";
        cin >> infoUsuario;
        cout << "" << endl;
        cout << "Digite a sua senha: ";
        cin >> infoSenha;
        cout << "" << endl;

        if (infoUsuario == user)
        {
            if (infoSenha == password)
            {
                cout << "Usuario logado com sucesso!" << endl;
                isLogin = true;
                system("cls");
            }else
            {
                cout << "A senha digitada nao confere com o usuario." << endl;
                system("pause");
                system("cls");
            }
            
            
        }else
        {
            cout << "O Codigo de usuario esta incorreto." << endl;
            system("pause");
            system("cls");
        }
        
        
    } while (isLogin == false);

    do
    {
        system("cls");
        cout << "SISTEMA DE NOTIFICACOES DA COVID - 19" << endl;
        cout << "" << endl;
        cout << "1 - GRAVAR PACIENTE NA BASE" << endl;
        cout << "2 - ACESSAR DADOS DOS PACIENTES" << endl;
        cout << "0 - SAIR DO SISTEMA" << endl;
        cout << "" << endl;
        cout << "Informe a sua escolha: ";
        cin >> escolha;

        system("cls");
        
        //switch (escolha)
        //{
        //case 1:
        if(escolha == 1){
            cout << "INSERIR PACIENTE" << endl;
            cout << "";
            getline(cin, paciente_nome);

            cout << "Informe o Paciente: ";
            getline(cin, paciente_nome);

            cout << "Digite o paciente_cpf do Paciente: ";
            getline(cin, paciente_cpf);

            cout << "Digite o Endereco do Paciente: ";
            getline(cin, Endereco);

            cout << "Digite o Cidade do Paciente: ";
            getline(cin, Cidade);

            cout << "Digite o Bairro do Paciente: ";
            getline(cin, Bairro);

            cout << "Digite o CEP do Paciente: ";
            getline(cin, CEP);

            cout << "Digite a data de Nascimento do Paciente (no formato dd/mm/aaaa): ";
            getline(cin, dataNascimento);

            cout << "Digite a data de Diagnostico do Paciente (no formato dd/mm/aaaa): ";
            getline(cin, dataDiagnostico);

            cout << "Digite E-mail do Paciente: ";
            getline(cin, Email);

            cout << "O Paciente possui alguma comorbidade? (1 - Sim ou outros valores para nao): ";
            cin >> possuiComorbidade;

           
            if (possuiComorbidade == 1)
            {
                cout << "";
                getline(cin, Comorbidade);

                cout << "Informe a Comorbidade do Paciente: ";
                getline(cin, Comorbidade);
            }else
            {
                Comorbidade = "Nenhuma";
            }
            
           //Comorbidade = "";
           //indiceComorbidade = 0;

           //cout << "Tecle para informar comorbidades...";
           //getline(cin, ComorbidadeAux);

           /*while (possuiComorbidade == 1)
           {
                indiceComorbidade++;
                
                cout << "Informe a Comorbidade do Paciente: ";
                getline(cin, ComorbidadeAux);

                if (indiceComorbidade == 1)
                {
                    //Abestalhadice
                    Comorbidade = ComorbidadeAux;
                }else
                {
                    //Obesidade, Hipertensão, Doidice
                    Comorbidade = Comorbidade + ", " + ComorbidadeAux;
                }
                
                //cout << "";
                //cin >> possuiComorbidade;

                cout << "O Paciente possui mais alguma comorbidade? (1 - Sim ou outros valores para não): ";
                cin >> possuiComorbidade;
           
           }*/
           
            //15/10/2000
            anoStr = dataNascimento.substr(6,4);
            anoNascimento = stoi(anoStr);
            idadePaciente = anoAtual - anoNascimento;
            
            nomeArquivo = paciente_cpf + ".txt";
            

            ofstream arquivoSave(nomeArquivo, ofstream::out);
            arquivoSave << "Nome: " << paciente_nome << "\n" 
                        << "paciente_cpf: " << paciente_cpf << "\n"
                        << "Endereco: " << Endereco << "\n"
                        << "Cidade: " << Cidade << "\n"
                        << "Bairro: " << Bairro << "\n"
                        << "CEP: " << CEP << "\n"
                        << "Data de Nascimento: " << dataNascimento << "\n"
                        << "Data do Diagnostico: " << dataDiagnostico << "\n"
                        << "Idade: " << idadePaciente << "\n"
                        << "E-mail: " << Email << "\n"
                        << "Comorbidade(s): " << Comorbidade << "\n";
            arquivoSave.close();

            if ((idadePaciente >= 65)||(possuiComorbidade == 1))
            {
                 ofstream arquivoInfo("listaComorbidade.txt", ios_base::app);
                if (arquivoInfo.is_open())
                {
                    cout << "Adicionando dados a estatistica de comorbidades." << endl;
                    arquivoInfo << "CEP: " << CEP << ";Idade: " << idadePaciente << ";Comorbidade: " << Comorbidade << ". \n";
                    arquivoInfo.close();
                }else
                {
                    cout << "Nao foi possivel adicionar dados a estatistica de comorbidades." << endl;
                }
            }
            
            cout << "Os dados do paciente foram salvos com sucesso." << endl;
            system("pause");
            //break;
        }else if(escolha == 2){
        //case 2:
            cout << "ACESSAR CADASTRO DE PACIENTE" << endl;
            cout << "..." << endl;

            cout << "";
            getline(cin, paciente_cpf);

            cout << "Digite o paciente_cpf do Paciente (Nao use pontos ou tracos): ";
            getline(cin, paciente_cpf);

            nomeArquivo = paciente_cpf + ".txt";

            ifstream arquivoLeitura(nomeArquivo);
            if (arquivoLeitura.is_open())
            {
                while (getline(arquivoLeitura, linhaArquivo))
                {
                    cout << linhaArquivo << endl;
                }
                arquivoLeitura.close();
            }else
            {
                cout << "Nao foi possivel abrir o cadastro do paciente informado." << endl;
            }
            
            
            system("pause");
            //break;
        }else if(escolha == 0){
        //case 0:
            cout << "Obrigado por utilizar o nosso sistema!" << endl;
            exitapp = true;
            //break;
        }else{
        //default:
            cout << "Opcao digitada nao corresponde as disponiveis no menu!" << endl;
            system("pause");
            //break;
        }
        
    } while (!exitapp);
   
    return 0;
}