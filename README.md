# Quiz Interativo em C++
Feito com base no exercício [Quiz Interativo em C++](https://neps.academy/br/project/21), do [Neps Academy](https://neps.academy). Este projeto consiste em um jogo de perguntas e respostas no terminal, onde o usuário responde questões com quatro alternativas. Ao final do quiz, a pontuação é apresentada e registrada em um ranking.

## Demonstração 
Durante a execução, o terminal exibe perguntas formatadas com quatro opções: ** As perguntas podem ser alteradas, essa é somente um exemplo 
```
Pergunta 1:
Qual é a capital do Brasil?

A) São Paulo  
B) Brasília  
C) Rio de Janeiro  
D) Belo Horizonte  

Digite sua resposta (A-D): B
 
```
Depois do usuário responder as questões, é mostrado a nota que ele obteve e o ranking vai ser atualizado.
```
Quiz finalizado!
Você acertou 8 de 10 perguntas.

Digite seu primeiro nome: João
```
## Instalação e Pré-requisitos
Para compilar e executar o quiz interativo em C++, é necessário ter o compilador GCC (GNU Compiler Collection) instalado em seu sistema. Abaixo, estão as instruções resumidas para os principais sistemas operacionais:
- **Windows**
  - Baixe o MinGW-w64:
  Acesse a página oficial do MinGW-w64 e baixe o instalador apropriado para o seu sistema: [MinGW-w64](https://www.mingw-w64.org)
  Abra o prompt de comando e digite `g++ --version` para verificar se o compilador GCC está instalado corretamente.
- **Linux**
  - Abra um terminal e execute os seguintes comandos:
```
// Para Debian/Ubuntu, com o apt:
sudo apt-get update
sudo apt-get install g++

// Para Arch Linux:
sudo pacman -S g++
```
## Estrutura do Projeto
Este projeto possui a seguinte estrutura:   

```
    Quiz/  
    │── quiz interativoc/
    │   └── main.c
    │   └── ranking.txt
    │   └── perguntas.txt
    │── LICENSE 
    │── README.md  
    
```
* `controledeestoqueemc` contém a `main.c` que contém o código fonte do quiz, além de ter:
  *  O arquivo `ranking.txt` armazena os nomes dos jogadores e suas maiores pontuações.
  *  O arquivo `perguntas.txt` arquivo com perguntas, opções e gabaritos. Cada questão ocupa 6 linhas e é separada por uma linha em branco.
* Este arquivo é o próprio `README.md`. Ele tem informações sobre o projeto.
* `LICENSE` contém toda a licença do projeto.
## Licença
Esse projeto está licenciado sob a licença MIT. Para mais detalhes, acesse o arquivo [LICENSE](https://github.com/maaluuzete/Controle-de-Estoques-em-C?tab=MIT-1-ov-file) desse repositório.
