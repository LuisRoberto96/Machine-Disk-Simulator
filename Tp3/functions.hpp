/*
 * functions.hpp
 *
 *  Created on: 5 de fev de 2018
 *      Author: luisf
 */
#ifndef FUNCTIONS_HPP_
#define FUNCTIONS_HPP_

#define TC1 16
#define TC2 32
#define TC3 64
#define TAM_RAM 500
#define TAM_DISCO 5000
#define TAM_INSTRUCAO 40000
typedef struct tipo_endereco {
	int endBloco;
	int endPalavra;
}TEndereco;

typedef struct instrucao {
	int opcode;
	TEndereco endereco1;
	TEndereco endereco2;
}Instrucao;

typedef struct linha {
	int cachehit;
	int palavras[4];
	int endBloco;
	int atualiza;
}Linha;

void zera_cache(Linha *, int);
void atribui_cache(int,Linha*,int,TEndereco);
int busca_cache(TEndereco,Linha*, int,int,int &);
void Troca_Caches(Linha*,int,Linha*);
void pega_da_Cache(int,Linha *,int,Linha *,int);
void Maquina(Instrucao[],int,int&,int&,int&,int&,int&,int&,int,int,int,Linha*,Linha*,Linha*,Linha*,int&,int&,int);
void multiplica(Instrucao[],int,int&,int&,int&,int&,int&,int&,int,int,int,Linha*,Linha*,Linha*,Linha*,int&,int&,int);
int MMU(TEndereco,int&,int&,int&,int&,int&,int&,int,int,int,Linha*,Linha*,Linha*,Linha*,int&,int&,int);
void interrupcao(int& ,int&,int& ,int&,int&,int&,int&,int&,int,int,int,Linha*,Linha* ,Linha*,Linha*,int&,int&,int);
void cria_arquivo();
void pega_arquivo(TEndereco,Linha*,int);
void atualiza_arquivo(Linha*cache,int tam);

#endif /* FUNCTIONS_HPP_ */
