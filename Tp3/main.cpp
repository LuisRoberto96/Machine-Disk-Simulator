/*
 * main.cpp
 *
 *  Created on: 5 de fev de 2018
 *      Author: luisf
 */
#include "geral.hpp"
#include"functions.hpp"

int main(){
	Instrucao operacao[TAM_INSTRUCAO];
	int pc=0,hit1=0,hit2=0,hit3=0,hit4=0,miss1=0,miss2=0,miss3=0,miss4=0;
	int interruption,parar_interrupcao=0;
	double custo=0.0;
	long int custo2=0;
	Linha *cache1=new Linha[TC1], *cache2=new Linha[TC2], *cache3=new Linha[TC3],*ram= new Linha[TAM_RAM];
	zera_cache(cache1, TC1);
	zera_cache(cache2, TC2);
	zera_cache(cache3, TC2);
	zera_cache(ram,TAM_RAM);
	cria_arquivo();

	ifstream ler;
		ler.open("instrucoes.txt");
		for (int i=0;i<TAM_INSTRUCAO;i++) {
				ler >> operacao[i].opcode;
			     ler>> operacao[i].endereco1.endBloco;
				 ler>> operacao[i].endereco1.endPalavra;
				 ler>> operacao[i].endereco2.endBloco;
				ler>> operacao[i].endereco2.endPalavra;
		}
		ler.close();

	while (operacao[pc].opcode != -1){
		interrupcao(interruption,parar_interrupcao,miss1,miss2,miss3,hit1,hit2,hit3,TC1,TC2,TC3,cache1,cache2,cache3,ram,miss4,hit4,TAM_RAM);
		//int	ValorUm=MMU(operacao[pc].endereco1,miss1,miss2,miss3,hit1,hit2,hit3,TC1,TC2,TC3,cache1,cache2,cache3,ram,miss4,hit4,TAM_RAM);
		//int	ValorDois=MMU(operacao[pc].endereco2,miss1,miss2,miss3,hit1,hit2,hit3,TC1,TC2,TC3,cache1,cache2,cache3,ram,miss4,hit4,TAM_RAM);

		Maquina(operacao, pc,miss1,miss2,miss3,hit1,hit2,hit3, TC1, TC2, TC3, cache1, cache2, cache3, ram,miss4,hit4,TAM_RAM);

		pc++;
	}
		Maquina(operacao,pc,miss1,miss2,miss3,hit1,hit2,hit3,TC1,TC2,TC3,cache1,cache2,cache3,ram,miss4,hit4,TAM_RAM);

	cout<<"CACHE HIT L1:"<<hit1<<endl;
	cout<<"CACHE MISS L1:"<<miss1<<endl;
	custo=hit1*100/(hit1+hit2+hit3+hit4+miss4);
	cout<<"Porcentagem:"<<custo<<endl;
	custo2=((TAM_INSTRUCAO*custo)/100)*10;
	cout<<"Custo cache 1:"<<custo2<< " de memoria"<<endl<<endl;

	cout<<"CACHE HIT L2:"<<hit2<<endl;
	cout<<"CACHE MISS L2:"<<miss2<<endl;
	custo=hit2*100/(hit1+hit2+hit3+hit4+miss4);
	cout<<"Porcentagem:"<<custo<<endl;
	custo2=((TAM_INSTRUCAO*custo)/100)*100;
	cout<<"Custo cache 2:"<<custo2<< " de memoria"<<endl<<endl;

	cout<<"CACHE HIT L3:"<<hit3<<endl;
	cout<<"CACHE MISS L3:"<<miss3<<endl;
	custo=hit3*100/(hit1+hit2+hit3+hit4+miss4);
	cout<<"Porcentagem:"<<custo<<endl;
	custo2=((TAM_INSTRUCAO*custo)/100)*1000;
	cout<<"Custo cache 3:"<<custo2<< " de memoria"<<endl<<endl;

	cout<<"RAM:"<<hit4<<endl;
	custo=hit4*100/(hit1+hit2+hit3+hit4+miss4);
	cout<<"Porcentagem:"<<custo<<endl;
	custo2=((TAM_INSTRUCAO*custo)/100)*10000;
	cout<<"Custo na Ram:"<<custo2<< " de memoria"<<endl<<endl;

	cout<<"DISCO:"<<miss4<<endl;
	custo=miss4*100/(hit1+hit2+hit3+hit4+miss4);
	cout<<"Porcentagem:"<<custo<<endl;
	custo2=((TAM_INSTRUCAO*custo)/100)*100000;
	cout<<"Custo no Disco:"<<custo2<< " de memoria"<<endl<<endl;
	cout<<endl;

	return 0;
}
