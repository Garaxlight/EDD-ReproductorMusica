#include "Player.hpp"
#include <iostream>

using namespace std;

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
    if (repeatMode == 1){
        isPlaying = true;
        return;
    }
    
    if (queue.isEmpty()){
        cout << "La cola de reproducción esta vacia" << endl;
        return;
    }

    history.push(song);

    song = queue.front();

    queue.dequeue();

    isPlaying = true;  
}

void Player::prevTrack() {

    if (history.isEmpty()){
        cout << "No hay historial." << endl;
        return;
    } 
    queue.pushFront(song);

    song = history.top();

    history.pop();

    isPlaying = true;
}