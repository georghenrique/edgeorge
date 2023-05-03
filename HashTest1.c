#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Hash.h"
#include "log.h"
#define MAX 10

bool comparaChaves(void *data1, void *data2) {
    char *d1 = (char*)data1;
    char *d2 = (char*)data2;

     /*if(strcmp(d1,d2)==0){
        log_debug("Os dados são iguais! String1: %s, String2: %s", d1, d2);
        return true;

    }
    else{
        log_debug("Os dados NÃO são iguais! String1: %s, String2: %s", d1, d2);
        return false;
    }*/
    return strcmp(d1,d2)==0?:false;
}
//typedef char WORD[MAX];


int main() {
    log_info("Criação da var hashes do tipo HashStruct");
    HashStruct has;
    log_info("Chamada a função initHash");
    initHash(&has);

    char palavra[MAX];
    
    log_info("");

    log_info("Abertura do arquivo ListaDePalavras no modo leitura:");
    FILE *file = fopen("ListaDePalavrasPT.txt", "r");
    if(file == NULL){
        log_error("ERRO** o arquivo Ñ foi aberto!");
        return -3;
    }
    log_info("Chamada de while para percorrer todas as palavras contidas no arquivo");
     while(fscanf(file, "%[^\n]%*c\n",palavra)!=EOF){
        log_debug("String: %s", palavra);
        put(&has, palavra, palavra, comparaChaves);
     }
     fclose(file);

    
    
    /*
    log_info("Calculo do maior numero de colisoes:");
    int cont,i = 0;
    HashStruct * a = &has;
    while(i<MAX){
        log_trace("while <-");
        if(cont<a->hashes[i].size){
            log_trace("if <-");
            log_debug("valor de size na posicao %d é: %d", i, a->hashes[i].size);
            cont = a->hashes[i].size;
            log_debug("contador de colisoes recebe size: %d", cont);
        }
        log_trace("if ->");
        i++;
    }
    log_trace("while ->");*/
    
    /*
    //inplementação antigas com problemas
    log_info("Calculo do maior numero de colisoes:");
    int cont,i = 0;
    HashStruct * a = &has;
    Node *aux = &a->hashes[i].first->next;
    int teste = a->hashes[i].size;
    log_info("aux recebeu o endereco de memoria de HashStruct na 1 posicao");
    while((aux != a->hashes[i].first)==true && i<MAX){
        log_trace("while <-");
        if(cont<a->hashes[i].size){
            log_debug("size na posicao %d, valor de cont: %d", i, a->hashes[i].size);

            log_trace("if <-");
            cont = a->hashes[i].size;
            log_debug("valor do contador de colisoes: %d", cont);
        }
        log_trace("if ->");
        aux = a->hashes[i].first->next;
        log_trace("aux = receber next");
        i++;
    }
    log_trace("while ->");
    log_debug("maior colisao encontrada: %d", cont);*/




    /*
    const int dimx = 5, dimy = 5;//Dimensão da matriz
    int k, j;
    
    FILE *grafico = fopen("graficoEspalhamento.ppm", "w");
    //Descrição do arquivo
    fprintf(grafico, "P6\n%d %d\n255\n", dimx, dimy);
    //Varre a matriz em coloca uma cor na posição
    
    int count=0;
    for (j = 0; j < dimy; ++j)
    {
        for (k = 0; k < dimx; ++k)
        {
            while((aux != has.hashes[i].first)==true && i<MAX){
            if(has.hashes[count].size<250){
                //tente trocar o unsigned char por outros tipos
                //Verifique o que significa unsigned char
                static unsigned char color[3];
                color[0] = 0;  // red
                color[1] = 250-has.hashes[count].size; // green
                log_debug("oq esta caontcendo: %d", has.hashes[count].size);
                color[2] = 0;  //blue
                fwrite(color, 1, 3, grafico);//Escreve no arquivo a cor
            }else{
                //tente trocar o unsigned char por outros tipos
                //Verifique o que significa unsigned char
                static unsigned char color[3];
                color[0] = 0;  // red
                color[1] = 0;  // green
                color[2] = 0;  // blue
                fwrite(color, 1, 3, grafico);//Escreve no arquivo a cor
                count++;
            }
        aux = a->hashes[i].first->next;
        log_trace("aux = receber next");
        i++;
        }
        }
    }
    fclose(grafico);//Salva o arquivo*/
    
    
    
    const int dimx = 5, dimy = 5;//Dimensão da matriz
    int k, j;
    
    FILE *grafico = fopen("graficoEspalhamento.ppm", "w");
    //Descrição do arquivo
    fprintf(grafico, "P6\n%d %d\n255\n", dimx, dimy);
    //Varre a matriz em coloca uma cor na posição
    
    int count, f, valorMax =0;
    valorMax = 255/3;
    for (j = 0; j < dimy; ++j)
    {
        for (k = 0; k < dimx; ++k){
            while(f<MAX){
                log_trace("while <-");          
                log_debug("posição do size: %d valor dos size: %d", f, has.hashes[f].size);
                static unsigned char color[3];
                if(has.hashes[f].size==0){
                    log_debug("SIZE É ZERO: %d ", has.hashes[f].size);
                    static unsigned char color[3];
                color[0] = 0;  // red
                color[1] = 0;  // green
                color[2] = 0;  // blue
                fwrite(color, 1, 3, grafico);//Escreve no arquivo a cor

                }
                else{
                    color[0] = 0;  // red            
                    color[1] = 3/has.hashes[f].size;
                    color[2] = 0;  //blue

                    log_debug("valor do ppm: %d ", color[1]);
                    fwrite(color, 1, 3, grafico);//Escreve no arquivo a cor
                    
                }
                f++;
                

            }
            log_trace("while ->");          
            
        }
    }
    fclose(grafico);


   
    return 0;
}