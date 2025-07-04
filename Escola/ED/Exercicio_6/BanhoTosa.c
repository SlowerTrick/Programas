//
//  BanhoTosa.h
//  BanhoTosaED
//
//  Created by Artur Vitor Cintra Bernardes on 04/06/25.
//

#include "BanhoTosa.h"
#include "Lista.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*Tipo que define a loja de banho e tosa (tipo opaco)
 *Cada loja deve ter os seguintes atributos:
 * * Nome da loja
 * * Uma lista de animais (gatos e cachorros) agressivos
 * * Uma lista de animais (gatos e cachorros) mansos
 * */
struct banhotosa
{
    char *nome;
    Lista *agressivos;
    Lista *mansos;
};


/* Cria uma loja de banho e tosa, ainda vazia, com duas listas de animais vazias
* inputs: nome da loja (char*). Esta função deve alocar dinamicamente o nome da loja.
* output: loja alocada e vazia, com listas de animais ainda vazias
* pre-condicao: nao tem
* pos-condicao: loja alocada e vazia, com listas de animais criadas e vazias  */
BanhoTosa* inicBanhoTosa(char* nome)
{
    BanhoTosa *b = malloc(sizeof(*b));
    b->nome = strdup(nome);
    b->agressivos = cria_lista();
    b->mansos = cria_lista();
    return b;
}

/* Insere o cachorro em uma das listas de animais, dependendo do seu nível de agressividade
* inputs: referência para a loja e a referência para o animal
* output: nenhum
* pre-condicao: loja alocada e animal alocado
* pos-condicao: loja contém o animal e uma de suas listas, dependendo do nível de agressividade do animal  */
void cadastraCachorro(BanhoTosa* loja, Cachorro* dog)
{
    int tipo = get_agressividade_cachorro(dog);
    tipo == MANSO ? adiciona_elemento_lista(loja->mansos, dog, tipo) : adiciona_elemento_lista(loja->agressivos, dog, tipo);
}

/* Insere o cachorro em uma das listas de animais, dependendo do seu nível de agressividade
* inputs: referência para a loja e a referência para o animal
* output: nenhum
* pre-condicao: loja alocada e animal alocado
* pos-condicao: loja contém o animal e uma de suas listas, dependendo do nível de agressividade do animal  */
void cadastraGato(BanhoTosa* loja, Gato* cat)
{
    int tipo = get_agressividade_gato(cat);
    tipo == MANSO ? adiciona_elemento_lista(loja->mansos, cat, tipo) : adiciona_elemento_lista(loja->agressivos, cat, tipo);
}


/* Essa função atualiza a situação de um gato na loja. Caso ele esteja na lista errada, ele é devidamente MOVIDO para a lista correta.
* inputs: referência para a loja e a referência para o animal
* output: nenhum
* pre-condicao: loja alocada e animal alocado
* pos-condicao: animal deve estar na lista correta, de acordo com seu nível de agressividade */
void atualizaSituacaoGato(BanhoTosa* loja, Gato* cat) {
    int tipo = get_agressividade_gato(cat);
    char *nome = get_nome_gato(cat);

    if (tipo == MANSO) 
    {
        if (recupera_elemento_lista(loja->agressivos, nome) != NULL) 
        {
            remove_elemento_lista(loja->agressivos, nome);
            adiciona_elemento_lista(loja->mansos, cat, tipo);
        }
    } 
    else 
    {
        if (recupera_elemento_lista(loja->mansos, nome) != NULL) {
            remove_elemento_lista(loja->mansos, nome);
            adiciona_elemento_lista(loja->agressivos, cat, tipo);
        }
    }
}


/* Essa função atualiza a situação de um cachorro na loja. Caso ele esteja na lista errada, ele é devidamente MOVIDO para a lista correta.
* inputs: referência para a loja e a referência para o animal
* output: nenhum
* pre-condicao: loja alocada e animal alocado
* pos-condicao: animal deve estar na lista correta, de acordo com seu nível de agressividade */
void atualizaSituacaoCachorro(BanhoTosa* loja, Cachorro* dog) 
{
    int tipo = get_agressividade_cachorro(dog);
    char *nome = get_nome_cachorro(dog);

    if (tipo == MANSO) 
    {
        if (recupera_elemento_lista(loja->agressivos, nome) != NULL) 
        {
            remove_elemento_lista(loja->agressivos, nome);
            adiciona_elemento_lista(loja->mansos, dog, tipo);
        }
    } 
    else 
    {
        if (recupera_elemento_lista(loja->mansos, nome) != NULL) 
        {
            remove_elemento_lista(loja->mansos, nome);
            adiciona_elemento_lista(loja->agressivos, dog, tipo);
        }
    }
}


/* Imprime os dados da Loja (nome, e conteúdo das listas)
* inputs: referencia para a loja
* output: nenhum
* pre-condicao: loja alocada
* pos-condicao: nenhuma alteração feita nos conteúdos das estruturas de dados */
void imprimeBanhoTosa(BanhoTosa* loja)
{
    printf("Nome da loja: %s\n", loja->nome);
    printf("Animais Agressivos:\n");
    imprime_lista(loja->agressivos);
    printf("Animais Mansos:\n");
    imprime_lista(loja->mansos);
}


/* Calcula o valor que a loja vai receber caso todos os animais tomem banho.
 Valor Gato: 30 reais, Valor Cachorro: 40 reais. Caso o animal seja agressivo, é cobrado uma taxa extra de 5 reais.
* inputs: referencia para a loja
* output: valor da receita
* pre-condicao: loja alocada
* pos-condicao: nenhuma alteração feita nos conteúdos das estruturas de dados */
float calculaReceita(BanhoTosa* loja)
{
    int total_agressivos = get_total_elementos_lista(loja->agressivos);
    int total_gatos = get_total_gatos_lista(loja->agressivos) + get_total_gatos_lista(loja->mansos);
    int total_cachorros = get_total_cachorros_lista(loja->agressivos) + get_total_cachorros_lista(loja->mansos);
    return (total_cachorros * 40) + (total_gatos * 30) + (total_agressivos * 5);
}


/* Libera toda a memória alocada
* inputs: referencia para a loja
* output: não tem
* pre-condicao: loja alocada
* pos-condicao: Toda a memória liberada, a não ser gatos e cachorros, que são responsabilidade do cliente. */
void liberaBanhoTosa(BanhoTosa* loja)
{
    if(loja)
    {
        free(loja->nome);
        libera_lista(loja->agressivos);
        libera_lista(loja->mansos);
        free(loja);
    }
}