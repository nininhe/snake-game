#include <iostream>
bool gameOver; 
void setup() {
gameOver = false;
}

void draw() {

}

void input() {

}

void logic() {

}

int main () {

setup(); //chama a funcao de setup

 while (!gameOver) { //Enquanto nao for game over, nesse caso game over = 1
    draw();
    input();
    logic();
 }
    return 0;
}