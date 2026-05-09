#include "Player.hpp"
#include <iostream>

using namespace std;

void Player::playPause(){
    if (song.id == -1 && queue.isEmpty()){
        cout << "No hay canciones en la cola" << endl;
        return;
    }
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

        if (repeatMode == 2){

            if (song.id != -1){
                history.push(song);
            }
            
            while(!history.isEmpty()){
                queue.pushFront(history.top());
                history.pop();
            }
        }else{

        
        cout << "La cola de reproduccion esta vacia" << endl;
        return;
        }
    }
    if(song.id != -1){
        history.push(song);
    }

    song = queue.front();

    queue.dequeue();

    isPlaying = true;  
}

void Player::prevTrack() {

    if (history.isEmpty()){
        cout << "No hay historial." << endl;
        return;
    } 
    if (song.id != -1){
        queue.pushFront(song);
    }

    song = history.top();

    history.pop();

    isPlaying = true;
}