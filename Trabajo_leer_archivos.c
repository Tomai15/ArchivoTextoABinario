#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char** argv)
{
    if((argc - 1) % 2 != 0 || argc == 0)
    {
        printf("Pa no me pasaste rutas de archivos, que flashas");
        return 1;
    }
    FILE *archivoTexto;
    FILE *archivoBinario;
    char *lineasDelArchivo = malloc(sizeof(char)*10000);
    char *caracterBuscado;
    printf("Se ingresaron %d archivos\n",argc-1);
    printf("Los archivos son %s %s\n",argv[1],argv[2]);
    for(int i=1;i <= (argc-1)/2;i++)
    {
       lineasDelArchivo = malloc(sizeof(char)*10000);
       archivoTexto = fopen(argv[i],"r");
       archivoBinario = fopen(argv[i+1], "rb+");
       if(archivoTexto == NULL)
       {
            printf("Pa no puedo abrir el archivo de texto que me pediste");
            return 1;
       }
       if(archivoBinario == NULL)
       {
            printf("Pa no puedo abrir el archivo binario que me pediste");
            return 1;
       }
        
        while(fgets(lineasDelArchivo,10000,archivoTexto))
        {
            printf("La linea del archivo es : %s\n",lineasDelArchivo);
            caracterBuscado = strchr(lineasDelArchivo,'\n');
            fwrite(lineasDelArchivo, caracterBuscado-lineasDelArchivo ,1,archivoBinario);
        }
        fclose(archivoBinario);
        fclose(archivoTexto);
        free(lineasDelArchivo);
    }
    printf("Termine de copiar los archivos\n");
    return 0;

}