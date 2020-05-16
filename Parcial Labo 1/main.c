#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "harryio.h"
#include "mascota_cliente.h"
#define LIBRE 0
#define OCUPADO 1
#define CLIENTES 10
#define MASCOTAS 20
int main()
{
int eleccion;
int eleccionCliente;
int eleccionMascota;
sCliente cliente[10];
sMascota mascota[20];
inicializarCliente(cliente,CLIENTES,LIBRE);
inicializarMascota(mascota,MASCOTAS,LIBRE);
//hardcodearCliente(cliente,CLIENTES);
//hardcodearMascota(mascota,MASCOTAS);
printf("------|| Menu de la veterinaria ||------\n");
do
    {
    printf("1.Opciones de Clientes\n");
    printf("2.Opciones de Mascotas\n");
    printf("3.Salir\n");
    fflush(stdin);
    eleccion=getInt("Ingrese la opcion: ","Elija una opcion valida: ",1,3,1);
    system("cls");
    switch(eleccion)
        {
        case 1:
            {
            do
                {
                calcularMascotasPorCliente(mascota,MASCOTAS,cliente,CLIENTES,OCUPADO);
                printf("1.Ingresar Cliente\n");
                printf("2.Modificar Cliente\n");
                printf("3.Eliminar Cliente y sus Mascotas\n");
                printf("4.Mostrar Clientes\n");
                printf("5.Mostrar Clientes con sus Mascotas\n");
                printf("6.Mostrar Clientes con mas de dos Mascotas\n");
                printf("7.Mostrar Clientes ordenados por cantidad de mascotas\n");
                printf("8.Mostrar Clientes ordenados por cantidad de mascotas y nombre\n");
                printf("9.Mostrar cantidad de Clientes y Porcentajes de Sexos\n");
                printf("10.Volver al menu principal\n");
                fflush(stdin);
                eleccionCliente=getInt("Ingrese la opcion: ","Elija una opcion valida: ",1,19,1);
                system("cls");
                if(cantClientes(cliente,CLIENTES,OCUPADO)==0&&eleccionCliente!=1)
                    {
                    printf("No hay ningun Cliente ingresado, para seguir ingrese uno a continuacion\n");
                    eleccionCliente=1;
                    }
                switch(eleccionCliente)
                    {
                    case 1:
                        {
                        altaCliente(cliente,CLIENTES,LIBRE,OCUPADO);
                        break;
                        }
                    case 2:
                        {
                        modificarCliente(cliente,CLIENTES,OCUPADO);
                        break;
                        }
                    case 3:
                        {
                        eliminarClienteYSusMascotas(mascota,MASCOTAS,cliente,CLIENTES,OCUPADO,LIBRE);
                        break;
                        }
                    case 4:
                        {
                        mostrarCliente(cliente,CLIENTES,OCUPADO);
                        break;
                        }
                    case 5:
                        {
                        mostrarClienteConSusMascotas(mascota,MASCOTAS,cliente,CLIENTES,OCUPADO);
                        break;
                        }
                    case 6:
                        {
                        calcularMascotasPorCliente(mascota,MASCOTAS,cliente,CLIENTES,OCUPADO);
                        mostrarClientesConMasDeUnaMascota(cliente,CLIENTES,OCUPADO);
                        break;
                        }
                    case 7:
                        {
                        ordenarClientePorCantMascotas(cliente,CLIENTES,OCUPADO);
                        mostrarCliente(cliente,CLIENTES,OCUPADO);
                        break;
                        }
                    case 8:
                        {
                        ordenarClientePorCantMascotasYNombre(cliente,CLIENTES,OCUPADO);
                        mostrarCliente(cliente,CLIENTES,OCUPADO);
                        break;
                        }
                    case 9:
                        {
                        porcentajeDeHombresYMujeres(cliente,CLIENTES,OCUPADO);
                        break;
                        }
                    case 10:
                        {
                        printf("Vuelta al Menu principal\n");
                        }
                    }
                }while(eleccionCliente!=10);
            break;
            }
        case 2:
            {
            if(cantClientes(cliente,CLIENTES,OCUPADO)==0)
                {
                printf("No hay ningun cliente y por lo tanto ninguna mascota, para continuar con estas opciones ingrese un cliente primero\n");
                }
            else
                {
                    do
                    {
                    vincluarClienteAMascota(mascota,MASCOTAS,cliente,CLIENTES,OCUPADO);
                    printf("1.Ingresar Mascotas\n");
                    printf("2.Modificar Mascotas\n");
                    printf("3.Eliminar Mascotas\n");
                    printf("4.Mostrar Mascotas\n");
                    printf("5.Mostrar Mascotas ordenadas por tipo\n");
                    printf("6.Mostrar Mascotas mayores de 3 a�os\n");
                    printf("7.Mostrar Mascotas por tipos\n");
                    printf("8.Mostrar promedio de edad de las Mascotas\n");
                    printf("9.Mostrar promedio de edad de las Mascotas por tipo\n");
                    printf("10.Volver al menu principal\n");
                    fflush(stdin);
                    eleccionMascota=getInt("Ingrese la opcion: ","Elija una opcion valida: ",1,10,1);
                    system("cls");
                    if(cantMascotas(mascota,MASCOTAS,OCUPADO)==0 && eleccionMascota!=1)
                        {
                        printf("No hay ninguna Mascota ingresada, para seguir ingrese una a continuacion\n");
                        eleccionMascota=1;
                        }
                    switch(eleccionMascota)
                        {
                        case 1:
                            {
                            printf("Clientes Actuales\n");
                            mostrarCliente(cliente,CLIENTES,OCUPADO);
                            altaMascota(mascota,MASCOTAS,LIBRE,OCUPADO);
                            break;
                            }
                        case 2:
                            {
                            modificarMascota(mascota,MASCOTAS,OCUPADO);
                            break;
                            }
                        case 3:
                            {
                            bajaMascota(mascota,MASCOTAS,OCUPADO,LIBRE);
                            break;
                            }
                        case 4:
                            {
                            mostrarMascota(mascota,MASCOTAS,OCUPADO);
                            break;
                            }
                        case 5:
                            {
                            ordenarMascotasPorTipo(mascota,MASCOTAS,OCUPADO);
                            mostrarMascota(mascota,MASCOTAS,OCUPADO);
                            break;
                            }
                        case 6:
                            {
                            mascotasMayoresA3(mascota,MASCOTAS,OCUPADO);
                            break;
                            }
                        case 7:
                            {
                            mostrarMascotaPorTipo(mascota,MASCOTAS,OCUPADO);
                            break;
                            }
                        case 8:
                            {
                            promedioEdadMascotas(mascota,MASCOTAS,OCUPADO,0);
                            break;
                            }
                        case 9:
                            {
                            promedioEdadMascotas(mascota,MASCOTAS,OCUPADO,1);
                            break;
                            }
                        case 10:
                            {
                            printf("Vuelta al Menu principal\n");
                            break;
                            }
                        }
                    }while(eleccionMascota!=10);
                }
            break;
            }
        case 3:
            {
            printf("Adios!");
            break;
            }
        }
    }while(eleccion!=3);
return 0;
}
