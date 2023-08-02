CC = gcc
CFLAGS = -Wall -Wextra
RM = del

all: Trabajo_leer_archivos

Trabajo_leer_archivos: Trabajo_leer_archivos.o
	$(CC) $(CFLAGS) -o Trabajo_leer_archivos Trabajo_leer_archivos.o

Trabajo_leer_archivos.o: Trabajo_leer_archivos.c
	$(CC) $(CFLAGS) -c Trabajo_leer_archivos.c

run:
	Trabajo_leer_archivos.exe C:\\Users\\tomas\\Desktop\\TrabajoPracticoSintaxis\\ArchivoDeTexto.txt C:\\Users\\tomas\\Desktop\\TrabajoPracticoSintaxis\\ArchivoBinario.dat

clean:
	-$(RM) Trabajo_leer_archivos.o
	-$(RM) Trabajo_leer_archivos.exe