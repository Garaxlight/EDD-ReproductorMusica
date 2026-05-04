#include <iostream>
#include <string>
#include "../estructuras/LinkedList.hpp"
#include "../estructuras/Queue.hpp"
#include "../estructuras/Stack.hpp"
#include "../clases/Song.hpp"
#include "../nucleo/FileManager.hpp"
#include "../estructuras/Status.hpp"
#include "../clases/Player.hpp"

using namespace std;

void mostrarMenu(){
    cout << "=== Reproductor de Música ===" << endl;
    cout << "W - Reproducir/Pausar" << endl;
    cout << "Q - Pista Anterior" << endl;
    cout << "E - Pista Siguiente" << endl;
    cout << "S - Modo Aleatorio" << endl;
    cout << "R - Repeticion" << endl;
    cout << "A - Ver lista actual" << endl;
    cout << "L - Lista de Canciones" << endl;
    cout << "X - Salir" << endl;
    cout << "============================" << endl;

    cout << "Ingrese una opción: ";
}

void SongMenu(LinkedList<Song>& lista, Player& player);
void mostrarCanciones(LinkedList<Song>& lista);
void menuCanciones(LinkedList<Song>& lista, Player& player);

int main(){
    // Estructura

    Player player;
    LinkedList<Song> listaCanciones;

    // Cargar datos
    FileManager::loadMusic("musicSource.txt", listaCanciones);
    Status status = FileManager::loadStatus("status.cfg");
    player.isShuffle = status.shuffle;
    player.repeatMode = status.repeatMode;
    Node<Song>* actual = listaCanciones.getHead();
    while(actual != nullptr){
        if(actual ->data.id == status.currentSongId){
            player.song = actual ->data;
            break;
        }
        actual = actual->next;
    }

    bool ejecutando = true;
    char opcion;

    while (ejecutando){
        mostrarMenu();
        cin >> opcion;

        switch (opcion){
            case 'W':
            case 'w':
                player.playPause();
                cout << (player.isPlaying ? "Reproduciendo: " : "En pausa: ") << player.song.nombre << endl;
                break;
            case 'Q':
            case 'q':
            if(player.history.isEmpty()){
                cout << "No hay pista anterior en el historial." << endl;

            } else {
                player.prevTrack();
                 cout << "Pista anterior: " << player.song.nombre << endl;
                }
                break;
            case 'E':
            case 'e':
                if(player.queue.isEmpty()) {
                    cout << "La cola de reproduccion esta vacia amix" << endl;
                } else {
                    player.nextTrack();
                    cout << "Siguiente pista: " << player.song.nombre << endl;
                }

                break;
            case 'S':
            case 's':
            player.toggleShuffle();
                cout << "Modo Aleatorio: " << (player.isShuffle ? "ON" : "OFF") << endl;
                break;
            case 'R':
            case 'r':
            player.toggleRepeat();
                 cout << "Modo de repetición: " << (player.repeatMode == 0 ? "OFF" : player.repeatMode == 1 ? "Repetir 1" : "Repetir todas") << endl;
                break;
            case 'A':
            case 'a':
                cout << "Ver lista actual..." << endl;
                SongMenu(listaCanciones, player);
                break;
            case 'L':
            case 'l':{
                mostrarCanciones(listaCanciones);
                menuCanciones(listaCanciones, player);
                break;
            }
            case 'X':
            case 'x':
                ejecutando = false;
                status.shuffle = player.isShuffle;
                status.repeatMode = player.repeatMode;  
                status.currentSongId = player.song.id;

                FileManager::saveStatus("status.cfg", status);
                cout << "Saliendo del reproductor..." << endl;
                break;
            default:
                cout << "Opción no válida. Intente nuevamente\n" << endl;
        }
    }

    return 0;
}