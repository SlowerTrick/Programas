#include <stdio.h>

typedef struct
{
    int codigo;
    float preco;
    int estoque;
}
tProduto;

tProduto produto;
tProduto produtoanterior;
tProduto menor;
tProduto maior;

tProduto LeProduto();
int EhProduto1MaiorQ2(tProduto p1, tProduto p2);
int EhProduto1MenorQ2(tProduto p1, tProduto p2);
int TemProdutoEmEstoque(tProduto p);
void ImprimeProduto(tProduto p);

int main (void)
{
    int totalprodutos = 0, i = 0, maiorpreco = 0, menorpreco = 0;
    scanf ("%i", &totalprodutos);

    for (i = 0; i < totalprodutos; i++)
    {
        if (i > 0)
        {
            produtoanterior = produto;
        }
        produto = LeProduto();
        if (!TemProdutoEmEstoque(produto))
        {
            printf ("FALTA:COD %i, PRE %.2f, QTD 0\n", produto.codigo, produto.preco);
        }
        if (i > 0)
        {
            maior.preco = EhProduto1MaiorQ2(produto, produtoanterior);
            menor.preco = EhProduto1MenorQ2(produto, produtoanterior);
        }
    }
    printf ("MAIOR:COD %i, PRE %.2f, QTD %i\n", maior.codigo, maior.preco, maior.codigo);
    printf ("MENOR:COD %i, PRE %.2f, QTD %i\n", menor.codigo, menor.preco, menor.codigo);
    return 0;
}

tProduto LeProduto()
{
    tProduto produto;
    scanf("%i;%f;%i", &produto.codigo, &produto.preco, &produto.estoque);
    return produto;
}

int TemProdutoEmEstoque(tProduto p)
{
    if (p.estoque == 0)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

int EhProduto1MaiorQ2(tProduto p1, tProduto p2)
{
    if (p1.preco > p2.preco)
    {
        maior = p1;
        return p1.preco;
    }
    else
    {
        maior = p2;
        return p2.preco;
    }
}

int EhProduto1MenorQ2(tProduto p1, tProduto p2)
{
    if (p1.preco < p2.preco)
    {
        menor = p1;
        return p1.preco;
    }
    else
    {
        menor = p2;
        return p2.preco;
    }
}