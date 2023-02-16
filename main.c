/** EL2208 Praktikum Pemecahan Masalah dengan C 2022/2023
 *   Modul               : 
 *   Hari dan Tanggal    :
 *   Nama (NIM)          :
 *   Nama File           : main.c
 *   Deskripsi           :
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROW 200
#define STRING_SIZE 200

int N; //variabel untuk menyimpan banyak row

/*function declaration*/
void readFile(char *filename, char array[MAX_ROW][STRING_SIZE]); 
void printSubstring(char array[STRING_SIZE],int awal, int akhir);
int cekState(char c);

int main() {
    //inisialisasi variabel
    char filename[20];
    scanf("%s",filename);
    char array[MAX_ROW][STRING_SIZE]; 

    int prev_state, curr_state;
    int count,max_count;
    int awal,akhir;
    int length;

    readFile(filename, array);
    for(int i=0;i<N;i++) {
        awal=0;
        akhir=0;
        max_count=-1;
        count=1;
        prev_state=-1;
        length=strlen(array[i]);
        for(int j=0;j<length;j++) {
            curr_state = cekState(array[i][j]);
            if(curr_state==prev_state) {
                count++;
            }
            else{
                if(count>max_count) {
                    max_count=count;
                    akhir=j-1;
                    awal=j-count;
					
                }
                count=1;
            }
            prev_state=curr_state;
        }
        //setelah keluar dari loop, cek lagi
        if(count>max_count) {
            max_count=count;
            akhir=length-1;
            awal=akhir-count+1;
        }
        printSubstring(array[i],awal,akhir);
    }
}

void readFile(char *filename, char array[MAX_ROW][STRING_SIZE]) {

    FILE *fp = fopen(filename, "r");
    char* token;

    //kasus file kosong
    if (fp ==NULL) {
        printf("Error : file tidak ada\n");
        return;    
    }

    char line[STRING_SIZE]; // Variabel penyimpan baris dari file sementara  

    //baca banyak testcase
    fgets(line,STRING_SIZE,fp);
    N=atoi(line);

    //baca matriks
    for(int i=0;i<N;i++) {
        fgets(line,STRING_SIZE,fp);
        token=strtok(line,"\n");
        strcpy(array[i],token);
    }
}

int cekState(char c) {
    if(c<=122 && c>=97 ) {return 1;}
    else if(c<=90 && c>=65 ) {return 2;}
    else if(c<=57 && c>=48 ) {return 3;}
	else {return 0;}
}

void printSubstring(char array[STRING_SIZE],int awal,int akhir) {
    for(int j=awal;j<=akhir;j++) {
        printf("%c",array[j]);
    }
    printf("\n");
    return;
}
