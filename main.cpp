#include <fstream>  // pra abrir e ler arquivos
#include <string>   // pra usar strings
#include <iostream> // pra usar cin, cout, etc

using namespace std;
struct perguntas {
    string enunciado; // a pergunta
    string A;         //A
    string B;         //B
    string C;         //C
    string D;         //D
    char resposta;    // resposta certa 
};

int main(){
    // Abre o arquivo chamado perguntas.txt
    ifstream arq("perguntas.txt");

    if (!arq.is_open()) {
        cout << "Erro ao abrir o arquivo." << endl;
        exit(1); 
    }
    else {
        cout << "Arquivo aberto" << endl;
    }

    perguntas lista[10];
    int total = 0; // vai contar quantas perguntas a gente leu

    // Aqui a gente vai começar a ler o arquivo linha por linha
    while (getline(arq, linha)) {

        if (linha.empty()) continue; // se a linha tiver vazia, a gente pula pra próxima

        // agora a gente preenche cada parte da struct com as linhas do arquivo
        lista[total].enunciado = linha;          
        getline(arq, lista[total].A);              
        getline(arq, lista[total].B);             
        getline(arq, lista[total].C);             
        getline(arq, lista[total].D);              
        getline(arq, linha);                       // 6 linha: resposta correta
        lista[total].resposta = linha[0];          // pega só a primeira letra da linha

        total++; // aumenta o número de perguntas lidas
        getline(arq, linha); // lê a linha em branco entre as perguntas (e ignora ela)
    }

    arq.close(); // fecha o arquivo quando termina de ler

    //  mostrar as perguntas pro usuário, uma por uma
    int acertos = 0; 

    for (int i = 0; i < total; i++) {
        cout << "\nPergunta " << i + 1 << ":" << endl;
        cout << lista[i].enunciado << endl;
        cout << lista[i].A << endl;
        cout << lista[i].B << endl;
        cout << lista[i].C << endl;
        cout << lista[i].D << endl;

        char respostaUsuario;
        cout << "Digite sua resposta (A, B, C ou D): ";
        cin >> respostaUsuario;

        // transforma pra maiúscula, caso o usuário digite minúscula, pra evitar que o programa erre
        if (respostaUsuario >= 'a' && respostaUsuario <= 'z') {
            respostaUsuario = respostaUsuario - 32; 
        }

        while (respostaUsuario != 'A' && respostaUsuario != 'B' && respostaUsuario != 'C' && respostaUsuario != 'D') {
            cout << "Opcao invalida. Digite novamente (A-D): ";
            cin >> respostaUsuario;

            // deixa maiúsculo de novo, se for necessário
            if (respostaUsuario >= 'a' && respostaUsuario <= 'z') {
                respostaUsuario = respostaUsuario - 32;
            }
        }

        // agora o cóigo vai comparar a resposta do usuário com a resposta certa
        if (respostaUsuario == lista[i].resposta) {
            cout << "Correto!\n";
            acertos++; // aumenta os acertos
        } else {
            cout << "Errado! Resposta correta: " << lista[i].resposta << endl;
        }
    }
    cout << "\nQuiz finalizado!\n";
    cout << "Voce acertou " << acertos << " de " << total << " perguntas.\n";
      string nomeUsuario;
    cout << "\nDigite seu nome para salvar no ranking: ";
    cin >> nomeUsuario;

  
    const int MAX_JOGADORES = 100;
    string nomes[MAX_JOGADORES];
    int pontos[MAX_JOGADORES];
    int qJogadores = 0;

    ifstream rankin("ranking.txt");
    if (rankin.is_open()) {
        while (rankin >> nomes[qJogadores] >> pontos[qJogadores]) {
            qJogadores++;
        }
        rankin.close();
    }

    // verifica se o nome já existe ou ñ
    bool achou = false;
    for (int i = 0; i < qJogadores; i++) {
        if (nomes[i] == nomeUsuario) {
            achou = true;
            if (acertos > pontos[i]) {
                pontos[i] = acertos; // atualiza se pontuação for maior
            }
            break;
        }
    }

    // se não achou, adiciona esse jogador
    if (!achou) {
        nomes[qJogadores] = nomeUsuario;
        pontos[qJogadores] = acertos;
        qJogadores++;
    }

    // Ordena o rank
    for (int i = 0; i < qJogadores - 1; i++) {
        for (int j = i + 1; j < qJogadores; j++) {
            if (pontos[i] < pontos[j]) {
                // troca os pontos
                int tempPontos = pontos[i];
                pontos[i] = pontos[j];
                pontos[j] = tempPontos;

                // troca os nomes junto
                string tempNome = nomes[i];
                nomes[i] = nomes[j];
                nomes[j] = tempNome;
            }
        }
    }

    ofstream salvar("ranking.txt");
    for (int i = 0; i < qJogadores; i++) {
        salvar << nomes[i] << " " << pontos[i] << endl;
    }
    salvar.close();

    cout << "\n===== RANKING =====" << endl;
    for (int i = 0; i < qJogadores; i++) {
        cout << i + 1 << ". " << nomes[i] << " - " << pontos[i] << " pontos" << endl;
    }

    return 0;
}
