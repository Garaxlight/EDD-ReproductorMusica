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

void SongMenu(LinkedList<Song>& lista, Queue<Song>& cola, Stack<Song>& pila);

int main(){
    // Estructura

    Player player;
    LinkedList<Song> listaCanciones;

    // Cargar datos
    FileManager::loadMusic("musicSource.txt", listaCanciones);
    Status status = FileManager::loadStatus("status.cfg");
    player.isShuffle = status.shuffle;
    player.repeatMode = status.repeatMode;

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
                SongMenu(listaCanciones, player.queue, player.history);
                break;
            case 'L':
            case 'l':{
                cout << "\n=== CANCIONES ===\n";

                Node<Song>* actual = listaCanciones.getHead();
                int i = 1;

                while (actual != nullptr){
                    cout << i << ". " << actual->data.nombre 
                    << " - " << actual->data.artista << endl;
                    actual = actual->next;
                    i++;
                }
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