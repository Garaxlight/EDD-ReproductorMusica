# MIRAI-PLAYER

> Reproductor de música por consola desarrollado en C++ con estructuras de datos personalizadas.

---

## Integrantes

Ramiro Alvarado Durán ||
Patricio Alvarado Durán 

---

## Descripción

MIRAI-PLAYER es un reproductor de música por consola desarrollado en C++.
Simula la reproducción y gestión de canciones desde un archivo local, implementando estructuras de datos como linkedlist, pilas y colas. Se incluyen funciones como reproducción/pausa, shuffle, repetición y gestión de lista de reproducción. Se cargan las canciones desde el archivo "music_source.txt" y el programa guarda el estado de la sesión en otro archivo, "status.cfg", para retomar cuando se abra otra vez el programa.

---

## Diagrama de Clases

- Pendiente

---

### Requisitos
- Compilador compatible con **C++14** o superior (GCC, MinGW, Cygwin)

---

## Instrucciones de Ejecución

```bash
# Windows
mirai-player.exe
```

---

## Funcionalidades

| Tecla | Acción |
|---|---|
| `W` | Reproducir / Pausar |
| `Q` | Pista anterior |
| `E` | Pista siguiente |
| `S` | Activar / Desactivar modo shuffle |
| `R` | Repetición (Desactivado / Repetir una / Repetir todas) |
| `A` | Ver lista de reproducción actual |
| `L` | Listado de canciones |
| `X` | Salir |

---

## Estructura del Proyecto

```
├── miraiPlayer/
│   ├── clases/
│   │   ├── Player.hpp / .cpp
│   │   ├── Playlist.hpp
│   │   └── Song.hpp / .cpp
│   ├── estructuras/
│   │   ├── LinkedList.hpp
│   │   ├── Node.hpp
│   │   ├── Queue.hpp
│   │   ├── Stack.hpp
│   │   └── Status.hpp
│   └── nucleo/
│       ├── FileManager.hpp
│       └── SongMenu.cpp
├── main.cpp
├── README.md
└── .gitignore
```
trabajo en progreso
---

*Taller 1 – Estructuras de Datos, Primer Semestre 2026 | Universidad Católica del Norte*
