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

    if (history.isEmpty()) return;
    queue.pushFront(song);
    song = history.top();
    history.pop();
    isPlaying = true;
}