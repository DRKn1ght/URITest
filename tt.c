#include <stdio.h>
#include <string.h>
int qnt = -1, qntp = -1, run = 1;
int compras[30][30], codCProd, codCompra, qntCompra, parcCompra, codCompra = 0, i = 0, j = 1;
void registrarProd();
void registrarCompra();
float saldoDevedor();
float prodParcNPagos();
void listarMatrix();

struct Produtos
{
    int cod;
    float preco;
    char desc[100];
};
struct Produtos prods[30];

int main()
{
    
    int opcao = 0, cod;
    float preco;
    char desc[100];
    while (run == 1){
        printf("\nDigite sua opcao:\n"
               "[1]. Cadastrar produto\n"
               "[2]. Registrar compra\n"
               "[3]. Saldo devedor\n"
               "[4]. Listar produtos parcelados nao pagos\n"
               "[5]. Listar matriz completa\n"
               "[6]. Sair\n"
               "-> ");
        scanf("%i", &opcao);
        getchar();
        switch (opcao){
            case 1:
            registrarProd();
            break;

            case 2:
            registrarCompra();
            break;

            case 3:
            printf("\nDivida: %f", saldoDevedor());
            break;

            case 4:
            printf("\nDivida: %f", prodParcNPagos());
            break;

            case 5:
            listarMatrix();
            break;

            case 6:
            run = 0;
            break;
    }
    }
    return 0;
}
void registrarProd()
{
    int cod;
    float preco;
    char desc[100];
    printf("Digite o codigo do produto: ");
    scanf("%i", &cod);
    getchar();
    printf("Digite a descricao do produto: ");
    gets(desc);
    printf("Digite o preco do produto: ");
    scanf("%f", &preco);
    qntp++;

    struct Produtos produto;
    produto.cod = cod;
    produto.preco = preco;
    strcpy(produto.desc, desc);
    prods[qntp] = produto;
    printf("\n %i - %0.2f - %s", prods[qntp].cod, prods[qntp].preco, prods[qntp].desc);

}

void registrarCompra()
{
    printf("Digite o codigo do produto: ");
    scanf("%i", &codCProd);
    printf("Digite a quantidade: ");
    scanf("%i", &qntCompra);
    printf("Digite o numero de parcelas: ");
    scanf("%i", &parcCompra);


    codCompra++;
    qnt++;
    i++;
    compras[i][j] = codCompra;
    compras[i][j+1] = codCProd;
    compras[i][j+2] = qntCompra;
    compras[i][j+3] = parcCompra;
    for (int ii = 1; ii < i+1; ii++)
    {
        for(int jj = 1; jj <= j+3; jj++)
        {
            printf("%i ", compras[ii][jj]);
        }
        printf("\n");
    }
    
}

float saldoDevedor()
{
    float divida = 0;
    for (int i = 1; i <= qnt+1; i++)
    {
        for (int j = 0; j <= qntp; j++){
            int codCompra = compras[i][2], QntCompra = compras[i][3];
            if (codCompra == prods[j].cod)
            {
                divida += QntCompra * prods[j].preco;
                printf("%s comprado.\n", prods[j].desc);
            }
        }
    }
    return (divida);
}

float prodParcNPagos()
{
    float divida = 0;
    for (int i = 1; i <= qnt+1; i++)
    {
        for (int j = 0; j <= qntp; j++){
            int codCompra = compras[i][2], parcCompra = compras[i][4];
            if (codCompra == prods[j].cod && parcCompra > 1)
            {
                divida += compras[i][3] * prods[j].preco;
                printf("%i %s %f", prods[j].cod, prods[j].desc, prods[j].preco);
            }
        }
        printf("\n");
    }
    return (divida);
}

void listarMatrix()
{
    for (int ii = 1; ii < i+1; ii++)
    {
        for(int jj = 1; jj <= j+3; jj++)
        {
            printf("%i ", compras[ii][jj]);
        }
        printf("\n");
    }
}