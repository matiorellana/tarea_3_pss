#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define INT_MAX 2147483647

void extraer(char* nombre){
    FILE *archivo;
    archivo = fopen(nombre, "r");
    char buf_1[11];
    char buf_2[17];
    char s[6];
    char d[7];
    fread(s, 1, 5, archivo);
    int n = atoi(s);
    int prioridad = INT_MAX;
    int k;
    int fila;
    for(int i=0; i < n; i++){
        fseek(archivo, 5 + i*17 + 10, SEEK_SET);
        if(i == n-1){
          fread(buf_2, 1, 17, archivo);
        }
        fread(d, 1, 7, archivo);
        k = atoi(d);
        if(k < prioridad){
          prioridad = k;
          fila = i;
        }
    }
    fseek(archivo, 5 + fila*17, SEEK_SET);
    fread(buf_1, 1, 10, archivo);
    buf_1[11] = 0;
    printf("%s\n", buf_1);
    fseek(archivo, 0, SEEK_SET);
    n-=1;
    sprintf(s, "%-4d\n", n);
    fclose(archivo);
    archivo = fopen(nombre, "w");
    fwrite(s, 1, 5, archivo);
    fseek(archivo, 5 + fila*17, SEEK_SET);
    fwrite(buf_2, 1, 17, archivo);
    fclose(archivo);
}
