#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "harryio.h"

typedef struct
{
    char nombre[20];
    char tipo[20];
    char raza[20];
    int edad;
    float peso;
    char sexo;
    int estado;
    int idMascota;
    int idCliente;
    char nombreCliente[20];
}sMascota;

/** \brief inicializa valores del el array como el estado y la ID de cada estructura
 *
 * \param sMascota mascota[] Array de estructuras sMascota
 * \param int tam tamaño del array
 * \param int libre valor de estado
 * \return void
 *
 */
void inicializarMascota(sMascota mascota[],int tam ,int libre);

/** \brief hardcodea valores en el array
 *
 * \param sMascota mascota[] Array de estructuras sMascota
 * \param int tam tamaño del array
 * \return void
 *
 */
void hardcodearMascota(sMascota mascota[],int tam);

/** \brief muestra las estructuras del array mientras esten activas (estado=ocupado)
 *
 * \param sMascota mascota[] Array de estructuras sMascota
 * \param int tam tamaño del array
 * \param int ocupado valor de estado
 * \return void
 *
 */
void mostrarMascota(sMascota mascota[],int tam, int ocupado);

/** \brief busca un a estructura libre(estado=libre) y permite ingresar datos en la misma y marcarla como activa(estado=ocupado)
 *
 * \param sMascota mascota[] Array de estructuras sMascota
 * \param int tam tamaño del array
 * \param int ocupado valor de estado
 * \return int devuelve -1 si no hay estructuras libres o la posicion en el array de la estructura en la que se ingresaron los datos
 *
 */
int altaMascota(sMascota mascota[],int tam, int libre, int ocupado);

/** \brief busca un a estructura activa(estad=ocupado) por ID y la marca como libre o inactiva(estado=libre)
 *
 * \param sMascota mascota[] Array de estructuras sMascota
 * \param int tam tamaño del array
 * \param int libre valor de estado
 * \param int ocupado valor de estado
 * \return int devuelve -1 si no hay coincidencias o la posicion en el array de la estructura que se elimino
 *
 */
int bajaMascota(sMascota mascota[], int tam, int ocupado,int libre);

/** \brief busca un a estructura activa(estad=ocupado) por id y permite modificar sus valores
 *
 * \param sMascota mascota[] Array de estructuras sMascota
 * \param int tam tamaño del array
 * \param int ocupado valor de estado
 * \return int devuelve -1 si no hay coincidencias o la posicion en el array de la estructura que se modifico
 *
 */
int modificarMascota(sMascota mascota[], int tam, int ocupado);

/** \brief busca una estructura libre(estado=libre) y devuelve la posicion de la misma en el array
 *
 * \param sMascota mascota[] Array de estructuras sMascota
 * \param int tam tamaño del array
 * \param int ocupado valor de estado
 * \return int devuelve -1 si no hay estructuras libres o la posicion en el array de la estructura que se encontro
 *
 */
int buscarMascotaLibre(sMascota mascota[], int tam, int libre);

/** \brief genera una ID sumandole 1 a la ID mas grande que encuentre entre las estructuras del array
 *
 * \param sMascota mascota[] Array de estructuras sMascota
 * \param int tam tamaño del array
 * \return int devuelve la ID mas grande +1
 *
 */
int generarIDMascota(sMascota mascota[],int tam);

/** \brief busca un a estructura activa(estad=ocupado) por id y devuelve su posicion en el array
 *
 * \param sMascota mascota[] Array de estructuras sMascota
 * \param int tam tamaño del array
 * \param int ocupado valor de estado
 * \return int devuelve -1 si no hay coincidencias o la posicion en el array de la estructura encontrada
 *
 */
int buscarMascota(sMascota mascota[],int tam,int ocupado);

/** \brief ordena el array alfabeticamente mediante el valor de tipo
 *
 * \param sMascota mascota[] Array de estructuras sMascota
 * \param int tam tamaño del array
 * \param int ocupado valor de estado
 * \return void
 *
 */
void ordenarMascotasPorTipo(sMascota mascota[],int tam, int ocupado);

/** \brief muestra la estructura en la posicion del array coincidente al parametro index
 *
 * \param sMascota mascota[] Array de estructuras sMascota
 * \param int tam tamaño del array
 * \param int index posicion del array
 * \return void
 *
 */
void mostrarUnaMascota(sMascota mascota[],int tam, int index);

/** \brief muestra todas las estructuras activas cuyo valor edad sea mayor a 3
 *
 * \param sMascota mascota[] Array de estructuras sMascota
 * \param int tam tamaño del array
 * \param int ocupado valor de estado
 * \return void
 *
 */
void mascotasMayoresA3(sMascota mascota[],int tam, int ocupado);

/** \brief muestra las estructuras dependiendo del valor tipo elegido
 *
 * \param sMascota mascota[] Array de estructuras sMascota
 * \param int tam tamaño del array
 * \param int ocupado valor de estado
 * \return void
 *
 */
void mostrarMascotaPorTipo(sMascota mascota[],int tam, int ocupado);

/** \brief si el parametro Modo = 0 calcula y muestra el promedio del valor edad de todas las estructuras activas
 *         si el parametro modo = 1 pregunta que promedio de edad quiere calcularse segun su valor tipo y lo muestra
 *
 * \param sMascota mascota[] Array de estructuras sMascota
 * \param int tam tamaño del array
 * \param int ocupado valor de estado
 * \param int modo flag de modalidad
 * \return int devuelve el promedio segun la modalidad y opcion elegida
 *
 */
int promedioEdadMascotas(sMascota mascota[],int tam,int ocupado, int modo);

/** \brief cuenta la cantidad de estructuras activas (estado=ocupado) en el array
 *
 * \param sMascota mascota[] Array de estructuras sMascota
 * \param int tam tamaño del array cliente
 * \param int ocupado valor de estado
 * \return int devuelve la cantidad de estructuras activas
 *
 */
int cantMascotas(sMascota mascota[],int tam, int ocupado);
