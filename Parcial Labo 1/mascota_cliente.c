#include "mascota_cliente.h"

void mostrarClienteConSusMascotas(sMascota mascota[], int tamMascota,sCliente cliente[],int tamCliente,int ocupado)
{
int i,j;
int flag;
char space=' ';
for(i=0;i<tamCliente;i++)
    {
    if(cliente[i].estado==ocupado)
        {
        printf("|%8cCLIENTE|%7cAPELLIDO|%6cLOCALIDAD|%8cTELEFONO|\n",space,space,space,space);
        printf("|%15s",cliente[i].nombre);
        printf("|%15s",cliente[i].apellido);
        printf("|%15s",cliente[i].localidad);
        printf("|%16s|",cliente[i].telefono);
        printf("\n\n");
        printf("| NOMBRE MASCOTA|%11cTIPO|%11cRAZA|EDAD|%2cPESO|SEXO|\n",space,space,space,space);
        flag=0;
        for(j=0;j<tamMascota;j++)
            {
            if(mascota[j].estado==ocupado && cliente[i].idCliente==mascota[j].idCliente)
                {
                printf("|%15s",mascota[j].nombre);
                printf("|%15s",mascota[j].tipo);
                printf("|%15s",mascota[j].raza);
                printf("|%4d",mascota[j].edad);
                printf("|%6.2f",mascota[j].peso);
                printf("|%4c|",mascota[j].sexo);
                printf("\n");
                flag=1;
                }
            }
        if(flag==0)
            {
            printf("Este cliente no tiene mascotas\n");
            }
        printf("\n");
        }
    }
}

void vincluarClienteAMascota(sMascota mascota[], int tamMascota,sCliente cliente[],int tamCliente,int ocupado)
{
int i,j;
int flag;
for(i=0;i<tamCliente;i++)
    {
    if(cliente[i].estado==ocupado)
        {
        for(j=0;j<tamMascota;j++)
            {
            if(mascota[j].estado==ocupado && cliente[i].idCliente==mascota[j].idCliente)
                {
                strcpy(mascota[j].nombreCliente,cliente[i].nombre);
                }
            }
        }
    }
}

void eliminarClienteYSusMascotas(sMascota mascota[], int tamMascota,sCliente cliente[],int tamCliente,int ocupado,int libre)
{
int i;
int aux=buscarCliente(cliente,tamCliente,ocupado,0,0);
int retorno=-1;
if(aux!=-1)
    {
        {
        for(i=0;i<tamMascota;i++)
            {
            if(mascota[i].estado==ocupado && cliente[aux].idCliente==mascota[i].idCliente)
                {
                mascota[i].estado=libre;
                }
            }
        cliente[aux].estado=libre;
        }
    system("color 2F");
    printf("Eliminados exitosamente\n");
    retorno=aux;
    }
else
    {
    printf("No hay ningun clinete con esa ID\n");
    }
return retorno;
}

void calcularMascotasPorCliente(sMascota mascota[],int tamMascota,sCliente cliente[],int tamCliente,int ocupado)
{
int i,j;
int flag;
for(i=0;i<tamCliente;i++)
    {
    if(cliente[i].estado==ocupado)
        {
        cliente[i].cantMascotas=0;
        for(j=0;j<tamMascota;j++)
            {
            if(mascota[j].estado==ocupado && cliente[i].idCliente==mascota[j].idCliente)
                {
                cliente[i].cantMascotas++;
                }
            }
        }
    }
}

int altaMascota(sMascota mascota[],int tamMascota,sCliente cliente[] ,int tamCliente ,int libre ,int ocupado)
{
int aux;
aux=buscarMascotaLibre(mascota,tamMascota,libre);
int retorno=-1;
if(aux!=-1)
    {
    getString(mascota[aux].nombre,"Ingrese el Nombre: ");
    do
    {
    getString(mascota[aux].tipo,"Ingrese el Tipo (Perro,Gato o Raro): ");
    }while((strcmpi(mascota[aux].tipo,"Perro")==0||strcmpi(mascota[aux].tipo,"Gato")==0||strcmpi(mascota[aux].tipo,"Raro")==0)!=1);
    getString(mascota[aux].raza,"Ingrese la Raza: ");
    mascota[aux].edad=getInt("Ingrese Edad: ","",0,0,0);
    mascota[aux].peso=getFloat("Ingrese Peso: ","",0,0,0);
    do
        {
        mascota[aux].sexo=getChar("Ingrese sexo ('M'o'H'): ","",0,0,0);
        }while((mascota[aux].sexo=='M'||mascota[aux].sexo=='H')!=1);
    mascota[aux].idCliente=getInt("Ingrese ID del dueño: ","",0,0,0);
    while(buscarCliente(cliente,tamCliente,ocupado,1,mascota[aux].idCliente)==-1)
        {
        system("color 4F");
        mascota[aux].idCliente=getInt("No hay ningun cliente con esa ID, ingrese otra ID: ","",0,0,0);
        }
    mascota[aux].idMascota=generarIDMascota(mascota,tamMascota);
    mascota[aux].estado=ocupado;
    system("color 2F");
    printf("Agregado exitosamente\n");
    retorno=aux;
    }
return retorno;
}


