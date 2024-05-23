#ifndef ANIMAO_H
#define ANIMAO_H
#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include "animain.h"
#include "aniloja.h"

void escolhe_loja(tp_compra mao[], int vidajogador){
	
	int esc=0, subloja, submao, i, j, boolid;
	int dinheiro = 10;
	tp_loja *loja;
	tp_animal troca;
	loja = inicializa_loja();
	faz_loja(&loja);
	
	for(i=0;i<5;i++){
		if(mao[i].carta[0].id == 19){
			if(mao[i].carta[0].lvl == 1)
				dinheiro += 1;
			else if(mao[i].carta[0].lvl == 2)
				dinheiro += 3;
			else if(mao[i].carta[0].lvl == 3)
				dinheiro += 8;
			}
		
		if(mao[i].carta[0].id == 23){
			if(mao[i].carta[0].lvl == 1)
				dinheiro += 2;
			else if(mao[i].carta[0].lvl == 2)
				dinheiro += 4;
			else if(mao[i].carta[0].lvl == 3)
				dinheiro += 6;
		}
		
	}
	
	while(esc != 6){
		
	//define o nivel caso bata o exp
	for(i=0;i<5;i++){
		if(mao[i].carta[0].lvl != 3){
			if(mao[i].carta[0].lvl == 1 && mao[i].carta[0].exp >= 2){
				mao[i].carta[1].exp = (mao[i].carta[0].exp - 2);
				mao[i].carta[0]= mao[i].carta[1];
				}
			if(mao[i].carta[0].lvl == 2 && mao[i].carta[0].exp >= 3){
				mao[i].carta[0]= mao[submao-1].carta[2];
				}
			}
	}
	
	
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	
	for(i=0;i<5;i++){
		if(mao[i].carta[0].id == 0)
			strcpy(mao[i].carta[0].nome, "_____");
	}
	

	if(esc == 2){
			printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nLOJA:\n\n");
			faz_esc2_loja(loja);
			
			printf("\n\n\n\nDECK:\n\n");
			for(i=0;i<5;i++){
			if(mao[i].carta[0].id != 0 && mao[i].carta[0].lvl == 1){
				puts(mao[i].carta[0].descricao);
				printf("DANO: %d , VIDA: %d, exp: %d/2 \n\n", mao[i].carta[0].dano, mao[i].carta[0].vida, mao[i].carta[0].exp);
			}
				else if(mao[i].carta[0].id != 0 && mao[i].carta[0].lvl == 2){
					puts(mao[i].carta[0].descricao);
					printf("DANO: %d , VIDA: %d, EXP: %d/3 \n\n", mao[i].carta[0].dano, mao[i].carta[0].vida, mao[i].carta[0].exp);
				}
				else if(mao[i].carta[0].id != 0 && mao[i].carta[0].lvl == 3){
					puts(mao[i].carta[0].descricao);
					printf("DANO: %d , VIDA: %d\n\n", mao[i].carta[0].dano, mao[i].carta[0].vida);
				}
			}
			printf("\n\n\n\n\n\n");
	}
				
	printf("Dinheiro: %d                                                 Vida: %d\n\n", dinheiro, vidajogador);
	printf("              %s   %s   %s   %s   %s \n\n", mao[4].carta[0].nome, mao[3].carta[0].nome, mao[2].carta[0].nome, mao[1].carta[0].nome, mao[0].carta[0].nome);
	imprime_loja(loja);
	
	printf("1 para contratar, 2 para ler a descricao, 3 rerolar, 4 para vender, 5 para reposicionar, 6 para batalhar: ");
	scanf("%d", &esc);
	if(esc == 1 && dinheiro >= 3){
		printf("digite qual voce quer contratar: ");
		scanf("%d", &subloja);
		if(subloja <= (tamanho_loja(loja)) && subloja > 0){
			printf("a posicao que voce quer colocar: ");
			scanf("%d", &submao);
			boolid = busca_loja_id(loja, subloja);
			if(submao < 6 && submao > 0 && mao[submao-1].carta[0].id == 0){
				troca_loja(&loja, subloja, &mao[submao-1]);
				dinheiro-=3;
			}
			else if(submao < 6 && submao > 0 && mao[submao-1].carta[0].id == boolid && mao[submao-1].carta[0].lvl != 3){
				mao[submao-1].carta[0].exp += 1;
				remove_loja(&loja, subloja);
				dinheiro-=3;
			}
		}
	}
	
	if(esc == 3 && dinheiro >=1){
		faz_loja(&loja);
	//	dinheiro -= 1;
	}
	
	if(esc == 4){
		printf("digite qual voce quer vender: ");
		scanf("%d", &subloja);
		if (mao[subloja-1].carta[0].id != 0 && subloja>=1 && subloja<=5){
			if(mao[subloja-1].carta[0].id == 21 && mao[subloja-1].carta[0].lvl == 1){
				dinheiro += 6;
				mao[subloja-1].carta[0].id = 0;}
			else if (mao[subloja-1].carta[0].id == 21 && mao[subloja-1].carta[0].lvl == 2){
				dinheiro += 11;
				mao[subloja-1].carta[0].id = 0;}
			else if (mao[subloja-1].carta[0].id == 21 && mao[subloja-1].carta[0].lvl == 3){
				dinheiro += 21;
				mao[subloja-1].carta[0].id = 0;}
			else{
				dinheiro += 1;
				mao[subloja-1].carta[0].id = 0;}
			}
		}
		
	if(esc == 5){
		printf("digite quais posicoes voce quer trocar: ");
		scanf("%d %d", &subloja , &submao);
		if (mao[subloja-1].carta[0].id == mao[submao-1].carta[0].id && subloja != submao && subloja > 0 && submao > 0 && subloja < 6 && subloja < 6){
			mao[submao-1].carta[0].exp += (1+mao[subloja-1].carta[0].exp);
			mao[subloja-1].carta[0].id = 0;
		}
		else if (subloja != submao && subloja > 0 && submao > 0 && subloja < 6 && subloja < 6){
			troca = mao[subloja-1].carta[0];
			mao[subloja-1].carta[0] = mao[submao-1].carta[0];
			mao[submao-1].carta[0] = troca;
		}	
		
	}
	}
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	destroi_loja(&loja);
}



void limpa_mao(tp_compra mao[]){
	int i;
	for(i=0;i<5;i++){
		mao[i].carta[0].id = 0;
		mao[i].carta[1].id = 0;
		mao[i].carta[2].id = 0;
	}
}

#endif
