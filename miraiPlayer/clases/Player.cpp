#include "Player.hpp"

void Player::playPause(){
    isPlaying = !isPlaying;
}

void Player::toggleShuffle(){
    isShuffle = !isShuffle;
}

void Player::toggleRepeat(){
    switch(repeatMode){

        case 0:
            repeatMode = 1;
            break;

            case 1:
            repeatMode = 2;
            break;

            case 2:
            repeatMode = 0;
    }
    
}

void Player::nextTrack(){

    //luego tengo que hacer el caso de si la cola esta vacia al llamar la funcion.

    history.push(song);
    song = queue.front();
    queue.dequeue();
    isPlaying = true;  
}

void Player::prevTrack() {

    queue.pushFront(song); //tengo que agregar luego un metodo mas a queue para manejar el orden, un pushFront, sino se añadira
    // en el lugar incorrecto de la cola
    song = history.top();
    history.pop();
    isPlaying = true;
}