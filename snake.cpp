#include <iostream>
#include <conio.h>
#include <cstdlib>
#include<windows.h>

bool gameOver; 
const int width = 20; //MAPA 20X20
const int height = 20;

int x, y, frutaX, frutaY, score; //coordenadas cobra e fruta e score do jogo

enum Direction {
    STOP = 0, LEFT, RIGHT, UP, DOWN //enumera,nesse caso, parar é 0, esquerda é 1 e assim vai
};
Direction dir; //variavel das direcoes

void setup() {
gameOver = false;
dir = STOP; //a cobra nao vai se mexer ate comecarmos a mexê-la
x = width/2;
y = height/2; //cobra no meio do mapa
frutaX = rand() % width; //Fruta em algum lugar aleatorio das dependencias do mapa
frutaY = rand() % height;
score = 0;
}

void draw() { //desenhar os componentes do jogo
    system("cls"); //limpa a tela

    for (int i=0; i < width+2; i++) {
        std::cout<<"#"; //imprime a parede de cima
    }
std::cout<<std::endl;

    for (int j = 0; j < height; j++) {
        for (int i = 0; i < width; i++) {
        if (i == 0) {
               std::cout<<"#"; //se o width for igual a 0 (local onde deve estar a parede) imprimirá um # (demarcacao da parede)
        }

        if (j == y && i == x) { //Se a altura for igual a coor y E a largura igual a coor x, imprime a cabeca
                std::cout<<"O"; //CABECA DA COBRA
        }
        else if (j == frutaY && i == frutaX) { //Mesma coisa, mas agora com a fruta
                std::cout<<"F"; 
        }
        else {
                std::cout<<" "; //area em branco do mapa

        }
        
        if (i == width-1) {
            std::cout<<"#"; //parede no outro canto do mapa
        }
        } 
        std::cout<<std::endl;
    }

    for (int i=0; i < width+2; i++) {
        std::cout<<"#"; //imprime a parede de cima
    }
std::cout<<std::endl;

std::cout<<"Score: " << score << std::endl;
}

void input() {

    //CONTROLES DO JOGO
    if (_kbhit()) { //se alguma tecla do teclado estiver pressionada, retorna 1; se nao, retorna 0

        switch (_getch()) { //o getch le um caractere do teclado, e o switch é um comando de selecao multipla, ou seja, captura mais de uma tecla pressionada no teclado.
            
            case 'a': //case é um valor da estrutura switch que define um valor constante.
            dir = LEFT;
            break;
            case 'd':
            dir = RIGHT;
            break;
            case 'w':
            dir = UP;
            break;
            case 's':
            dir = DOWN;
            break;
        case 'x': //terminar o jogo
            gameOver=true;
            break;

        }

    }

}

void logic() {
    switch (dir) {
        case LEFT: //segue o raciocinio do plano cartesiano.
        x--;
        break;
        case RIGHT: 
        x++;
        break;
        case UP: 
        y--;
        break;
        case DOWN: 
        y++ ;
        break;
        default:
        break;

    }

    if (x > width || x < 0 || y > height || y < 0) { //se a cobrinha bater na parede o jogo encerra.
        gameOver = true;
    }

        if (x == frutaX && y == frutaY) { //checar se comeu a fruta
        score += 10; //score acumula 10 pontos se comeu a fruta

        frutaX = rand() % width; //Fruta reespawna no mapa apos ser comida
        frutaY = rand() % height;
    }
}

int main () {

setup(); //chama a funcao de setup



 while (!gameOver) { //Enquanto nao for game over, nesse caso game over = 1
    draw();
    if (dir == LEFT || dir == RIGHT)
 {
  Sleep(5);
 }

Sleep(100); //faz a cobrinha se mexer mais devagar 

if (dir == UP || dir == DOWN)
 {
  Sleep(60);
 }
    input();
    logic();
 }

    return 0;
}