#include "mascota.h"

void hardcodearMascota(sMascota mascota[],int tam)
{
    int i;
    int idMascota[20]={10,11,12,13,14,15,16,17,18,19,20};
    int idCliente[20]={1,1,2,2,2,3,3,4,5,5,5};
    char nombre[20][20]={"Michin","Michino","Bobby","Bobinho","Minino","Bonno","Keckleon","Bobifus","Michifus","Michifusino","Buu"};
    char tipo[20][20]={"Gato","Gato","Perro","Perro","Gato","Perro","Raro","Perro","Gato","Gato","Perro"};
    int raza[20][20]={1,2,3,4,5,6,1,2,3,4,5};
    int edad[20]={12,3,9,4,16,7,8,14,2,12,8};
    float peso[20]={12.3,13.2,14.33423,14.2,12.4,1.23,14.5,15.6,2.34,12.4,32.50};
    char sexo[20]={'F','F','M','M','M','M','F','M','M','M','M'};
    int estado[20]={1,1,1,1,1,1,1,1,1,1,1};

    for(i=0;i<tam;i++)
        {
        strcpy(mascota[i].tipo,tipo[i]);
        mascota[i].raza=raza[i];
        strcpy(mascota[i].nombre,nombre[i]);
        mascota[i].idMascota=idMascota[i];
        mascota[i].idCliente=idCliente[i];
        mascota[i].edad=edad[i];
        mascota[i].peso=peso[i];
        mascota[i].sexo=sexo[i];
        mascota[i].estado=estado[i];
        }
}

void hardcodearRaza(sRaza raza[], int tam)
{
char nombre[10][20]={"Persa","siames","labrador","pitbull","lagartija","ardilla"};
char tipo[10][20]={"Gato","Gato","Perro","Perro","Raro","Raro"};
char pais[10][20]={"Argentina","Chile","Brasil","Bolivia","Venezuela","Australia"};
int id[10]={1,2,3,4,5,6};
int estado[10]={1,1,1,1,1,1};
int i;
for(i=0;i<tam;i++)
{
strcpy(raza[i].nombre,nombre[i]);
strcpy(raza[i].tipo,tipo[i]);
strcpy(raza[i].pais,pais[i]);
raza[i].estado=estado[i];
raza[i].idRaza=id[i];
}
}

void inicializarMascota(sMascota mascota[],int tam ,int libre)
{
int i;
for(i=0;i<tam;i++)
    {
    mascota[i].estado=libre;
    mascota[i].idMascota=0;
    }
}

void inicializarRaza(sRaza raza[],int tam)
{
int i;
for(i=0;i<tam;i++)
    {
    raza[i].estado=0;
    raza[i].idRaza=0;
    }
}

int generarIDRaza(sRaza raza[],int tam)
{
int i;
int may=0;
for(i=0;i<tam;i++)
    {
    if(i==0 || raza[i].idRaza>may)
        {
        may=raza[i].idRaza;
        }
    }
}

int altaRaza(sRaza raza[],int tam, int libre, int ocupado)
{
int i;
int retorno=-1;
int aux=buscarRazaLibre(raza,tam,libre);
if(aux!=-1)
    {
    getString(raza[aux].nombre,"Ingrese el Nombre: ");
    getString(raza[aux].pais,"Ingrese el Pais: ");
    do
        {
        getString(raza[aux].tipo,"Ingrese el tipo de animal al que corresponde: ");
        }while((strcmpi(raza[aux].tipo,"Perro")==0||strcmpi(raza[aux].tipo,"Gato")==0||strcmpi(raza[aux].tipo,"Raro")==0)!=1);
    raza[aux].idRaza=generarIDRaza(raza,tam);
    raza[aux].estado=ocupado;
    printf("Ingresado exitosamente\n");
    system("color 2F");
    retorno=aux;
    }
else
    {
    printf("No hay espacios disponibles\n");
    }
return retorno;
}

int bajaRaza(sRaza raza[],int tam, int libre, int ocupado)
{
int aux;
int aux2=0;
int i;
int retorno=-1;
aux=getInt("Ingrese id de la raza que quiere eliminar: ","",0,0,0);
for(i=0;i<tam;i++)
    {
    if(raza[i].idRaza==aux && raza[i].estado==ocupado)
        {
        aux2=1;
        printf("Se encontro la raza, se dara de baja\n");
        raza[i].estado=libre;
        system("color 2F");
        retorno=i;
        }
    }
if(aux==0)
{
printf("no se encontro ninguna raza\n");
}
return retorno;
}

int modificarRaza(sRaza raza[],int tam, int ocupado)
{
 int aux;
int eleccion;
int retorno=-1;
aux=buscarRaza(raza,tam,ocupado,0,0);
    if(aux!=-1)
        {
        printf("Se encontro la raza, elija que modificara: \n");
        do
            {
            printf("1.Modificar Nombre\n");
            printf("2.Modificar Tipo\n");
            printf("3.Modificar Pais\n");
            printf("4.Salir\n");
            eleccion=getInt("Elija una opcion: ","Elija una opcion valida: ",1,4,1);
            system("cls");
            switch(eleccion)
                {
                case 1:
                    {
                    getString(raza[aux].nombre,"Ingrese el Nombre: ");
                    break;
                    }
                case 2:
                    {
                    do
                    {
                    getString(raza[aux].tipo,"Ingrese el Tipo (Perro,Gato o Raro): ");
                    }while((strcmpi(raza[aux].tipo,"Perro")==0||strcmpi(raza[aux].tipo,"Gato")==0||strcmpi(raza[aux].tipo,"Raro")==0)!=1);
                    break;
                    }
                case 3:
                    {
                     getString(raza[aux].pais,"Ingrese el Pais: ");
                    break;
                    }
                case 4:
                    {
                    printf("Menu anterior\n");
                    break;
                    }
                }
            }while(eleccion!=7);
        retorno=aux;
        }
return retorno;
}

int buscarRaza(sRaza raza[],int tam, int ocupado,int id, int opcion)
{
 int i;
int retorno = -1;
int aux;
if(opcion==0)
    {
    aux=getInt("Ingrese una ID: ","",0,0,0);
    }
else if(opcion==1)
    {
    aux=id;
    }
for(i=0;i<tam;i++)
    {
    if(raza[i].estado==ocupado && raza[i].idRaza==aux)
        {
        if(opcion==0)
        {
        printf("Se ha encontrado una coincidencia\n");
        }
        retorno = i;
        break;
        }
    }
return retorno;
}


void mostrarRaza(sRaza raza[],int tam, int ocupado)
{
int i;
char space=' ';
int aux=0;
printf("|%9cNOMBRE|%11cTIPO|%11cPAIS|%4cID|\n\n",space,space,space,space);
for(i=0;i<tam;i++)
    {
    if(raza[i].estado==ocupado)
        {
        aux=1;
        printf("|%15s",raza[i].nombre);
        printf("|%15s",raza[i].tipo);
        printf("|%15s",raza[i].pais);
        printf("|%6d",raza[i].idRaza);
        }
    }
if(aux=0)
    {
    printf("No se ha ingresado ninguna raza\n");
    }
}

int buscarRazaLibre(sRaza raza[],int tam, int libre)
{
int i;
int retorno = -1;
for(i=0;i<tam;i++)
    {
    if(raza[i].estado==libre)
        {
        retorno = i;
        break;
        }
    }
return retorno;
}

void mostrarMascota(sMascota mascota[],int tam, int ocupado)
{
int i;
char space=' ';
printf("|%9cNOMBRE|%11cTIPO|%11cRAZA| EDAD|%2cPESO| SEXO|%4cID|ID DEL DUEÑO|%4cNOMBRE DEL DUEÑO|\n\n",space,space,space,space,space,space);
for(i=0;i<tam;i++)
    {
    if(mascota[i].estado==ocupado)
        {
        printf("|%15s",mascota[i].nombre);
        printf("|%15s",mascota[i].tipo);
        printf("|%15s",mascota[i].raza);
        printf("|%5d",mascota[i].edad);
        printf("|%6.2f",mascota[i].peso);
        printf("|%5c",mascota[i].sexo);
        printf("|%6d",mascota[i].idMascota);
        printf("|%12d",mascota[i].idCliente);
        printf("|%20s|",mascota[i].nombreCliente);
        printf("\n");
        }
    }
printf("\n");
}

int buscarMascotaLibre(sMascota mascota[],int tam,int libre)
{
int i;
int retorno = -1;
for(i=0;i<tam;i++)
    {
    if(mascota[i].estado==libre)
        {
        retorno = i;
        break;
        }
    }
return retorno;
}

int generarIDMascota(sMascota mascota[],int tam)
{
int i;
int may=0;
for(i=0;i<tam;i++)
{
if(i==0 || mascota[i].idMascota>may)
    {
    may=mascota[i].idMascota;
    }
}
return may+1;
}

int bajaMascota(sMascota mascota[],int tam,int ocupado,int libre)
{
int aux;
int i;
int retorno=-1;
aux=getInt("Ingrese id de la mascota que quiere eliminar: ","",0,0,0);
for(i=0;i<tam;i++)
    {
    if(mascota[i].idMascota==aux && mascota[i].estado==ocupado)
        {
        printf("Se encontro la mascota, se dara de baja\n");
        mascota[i].estado=libre;
        system("color 2F");
        retorno=i;
        }
    }
return retorno;
}

int modificarMascota(sMascota mascota[],int tam,int ocupado)
{
int aux;
int eleccion;
int retorno=-1;
aux=buscarMascota(mascota,tam,ocupado,0,0);
    if(aux!=-1)
        {
        printf("Se encontro la mascota, elija que modificara: \n");
        do
            {
            printf("1.Modificar Nombre\n");
            printf("2.Modificar Tipo\n");
            printf("3.Modificar Raza\n");
            printf("4.Modificar Edad\n");
            printf("5.Modificar Peso\n");
            printf("6.Modificar Sexo\n");
            printf("7.Salir\n");
            eleccion=getInt("Elija una opcion: ","Elija una opcion valida: ",1,7,1);
            system("cls");
            switch(eleccion)
                {
                case 1:
                    {
                    getString(mascota[aux].nombre,"Ingrese el Nombre: ");
                    break;
                    }
                case 2:
                    {
                    do
                    {
                    getString(mascota[aux].tipo,"Ingrese el Tipo (Perro,Gato o Raro): ");
                    }while((strcmpi(mascota[aux].tipo,"Perro")==0||strcmpi(mascota[aux].tipo,"Gato")==0||strcmpi(mascota[aux].tipo,"Raro")==0)!=1);
                    break;
                    }
                case 3:
                    {
                     getString(mascota[aux].raza,"Ingrese la Raza: ");
                    break;
                    }
                case 4:
                    {
                    mascota[aux].edad=getInt("Ingrese Edad: ","",0,0,0);
                    break;
                    }
                case 5:
                    {
                    mascota[aux].peso=getFloat("Ingrese Peso: ","",0,0,0);
                    break;
                    }
                case 6:
                    {
                    do
                        {
                        mascota[aux].sexo=getChar("Ingrese sexo ('M'o?'H'): ","",0,0,0);
                        }while((mascota[aux].sexo=='M'||mascota[aux].sexo!='H')!=1);
                    break;
                    }
                case 7:
                    {
                    printf("Fuera del menu de Modificaciones\n");
                    break;
                    }
                }
            }while(eleccion!=7);
        retorno=aux;
        }
return retorno;
}

int buscarMascota(sMascota mascota[],int tam,int ocupado,int id, int opcion)
{
int i;
int retorno = -1;
int aux;
if(opcion==0)
    {
    aux=getInt("Ingrese una ID: ","",0,0,0);
    }
else if(opcion==1)
    {
    aux=id;
    }
for(i=0;i<tam;i++)
    {
    if(mascota[i].estado==ocupado && mascota[i].idCliente==aux)
        {
        if(opcion==0)
        {
        printf("Se ha encontrado una coincidencia\n");
        }
        retorno = i;
        break;
        }
    }
return retorno;
}

void ordenarMascotasPorTipo(sMascota mascota[],int tam, int ocupado)
{
int i,j;
sMascota aux;
for(i=0;i<tam-1;i++)
    {
    if(mascota[i].estado==ocupado)
        {
        for(j=i+1;j<tam;j++)
            {
            if(mascota[j].estado==ocupado && strcmpi(mascota[i].tipo,mascota[j].tipo)>0)
                {
                aux=mascota[i];
                mascota[i]=mascota[j];
                mascota[j]=aux;
                }
            }
        }
    }
}

void mostrarUnaMascota(sMascota mascota[],int tam, int index)
{
printf("|%15s|%15s|%15s|%5d|%6.2f|%5c|%6d|%12d|%20s|\n",mascota[index].nombre
                                                        ,mascota[index].tipo
                                                        ,mascota[index].raza
                                                        ,mascota[index].edad
                                                        ,mascota[index].peso
                                                        ,mascota[index].sexo
                                                        ,mascota[index].idMascota
                                                        ,mascota[index].idCliente
                                                        ,mascota[index].nombreCliente);
}

void mascotasMayoresA3(sMascota mascota[],int tam, int ocupado)
{
int i;
char space=' ';
printf("|%9cNOMBRE|%11cTIPO|%11cRAZA| EDAD|%2cPESO| SEXO|%4cID|ID DEL DUEÑO|%4cNOMBRE DEL DUEÑO|\n\n",space,space,space,space,space,space);
for(i=0;i<tam;i++)
    {
    if(mascota[i].estado==ocupado && mascota[i].edad>3)
        {
        mostrarUnaMascota(mascota,tam,i);
        }
    }
}

void mostrarMascotaPorTipo(sMascota mascota[],int tam, int ocupado)
{

int i;
char space=' ';
int tipo=getInt("Ingrese el tipo de mascota que quiere mostrar (1.Perro 2.Gato 3.Raro): ","Ingrese un valor valido: ",1,3,1);
printf("|%9cNOMBRE|%11cTIPO|%11cRAZA| EDAD|%2cPESO| SEXO|%4cID|ID DEL DUEÑO|%4cNOMBRE DEL DUEÑO|\n\n",space,space,space,space,space,space);
for(i=0;i<tam;i++)
    {
    switch(tipo)
        {
        case 1:
            {
            if(strcmpi(mascota[i].tipo,"Perro")==0)
                {
                mostrarUnaMascota(mascota,tam,i);
                }
            break;
            }
        case 2:
            {
            if(strcmpi(mascota[i].tipo,"Gato")==0)
                {
                mostrarUnaMascota(mascota,tam,i);
                }
            break;
            }
        case 3:
            {
            if(strcmpi(mascota[i].tipo,"Raro")==0)
                {
                mostrarUnaMascota(mascota,tam,i);
                }
            break;
            }
        }
    }
}

int promedioEdadMascotas(sMascota mascota[],int tam,int ocupado,int modo)
{
int i;
int contador=0;
float acumulador=0;
float promedio=0;
if(modo==0)
    {
    for(i=0;i<tam;i++)
        {
        if(mascota[i].estado==ocupado)
            {
            contador++;
            acumulador+=mascota[i].edad;
            }
        }
    promedio=acumulador/contador;
    printf("El promedio de edad de las mascotas es: %f\n",promedio);
    }
else if(modo==1)
    {
    int aux=getInt("Ingrese el tipo de animal cuyo promedio de edad quiere saber (1.Perro 2.Gato 3.Raro): ","Ingrese una opcion valida: ",1,3,1);
    switch(aux)
        {
        case 1:
            {
            for(i=0;i<tam;i++)
                {
                if(mascota[i].estado==ocupado&& strcmpi(mascota[i].tipo,"Perro")==0)
                    {
                    contador++;
                    acumulador+=mascota[i].edad;
                    }
                }
            if(contador>0 && acumulador>0)
                {
                promedio=acumulador/contador;
                printf("El promedio de edad de las mascotas del tipo 'Perro' es: %f\n",promedio);
                }
            else
                {
                printf("No hay ninguna mascota de este tipo\n");
                }
            break;
            }
        case 2:
            {
            for(i=0;i<tam;i++)
                {
                if(mascota[i].estado==ocupado&& strcmpi(mascota[i].tipo,"Gato")==0)
                    {
                    contador++;
                    acumulador+=mascota[i].edad;
                    }
                }
            if(contador>0 && acumulador>0)
                {
                promedio=acumulador/contador;
                printf("El promedio de edad de las mascotas del tipo 'Gato' es: %f\n",promedio);
                }
            else
                {
                printf("No hay ninguna mascota de este tipo\n");
                }
            break;
            }
        case 3:
            {
             for(i=0;i<tam;i++)
                {
                if(mascota[i].estado==ocupado&& strcmpi(mascota[i].tipo,"Raro")==0)
                    {
                    contador++;
                    acumulador+=mascota[i].edad;
                    }
                }
            if(contador>0 && acumulador>0)
                {
                promedio=acumulador/contador;
                printf("El promedio de edad de las mascotas del tipo 'Raro' es: %f\n",promedio);
                }
            else
                {
                printf("No hay ninguna mascota de este tipo\n");
                }
            break;
            }
        }
    }
return promedio;
}

int cantMascotas(sMascota mascota[],int tam, int ocupado)
{
int i;
int contMascotas=0;
for(i=0;i<tam;i++)
    {
    if(mascota[i].estado==ocupado)
        {
        contMascotas++;
        }
    }
return contMascotas;
}

