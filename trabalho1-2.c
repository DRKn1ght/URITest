/* 
Guilherme Panobianco Ferrari
RA: 112679

Problemas encontrados apenas com manipulação de strings, para enviar como paramêtro e utilizar no Struct.
*/
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
            printf("\n"
               "[0]. Mostrar o menu novamente\n"
               "[1]. Cadastrar produto\n"
               "[2]. Registrar compra\n"
               "[3]. Saldo devedor\n"
               "[4]. Listar produtos parcelados nao pagos\n"
               "[5]. Listar matriz completa\n"
               "[6]. Sair");
    while (run == 1){
        
        printf("\nDigite sua opcao:\n-> ");
        scanf("%i", &opcao);
        getchar();
        switch (opcao){
            case 0:
            printf("\n"
               "[0]. Mostrar o menu novamente\n"
               "[1]. Cadastrar produto\n"
               "[2]. Registrar compra\n"
               "[3]. Saldo devedor\n"
               "[4]. Listar produtos parcelados nao pagos\n"
               "[5]. Listar matriz completa\n"
               "[6]. Sair");
            break;
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
    qntp++;
    if (qntp == 31)
    {
        printf("O limite maximo de produtos cadastrados foi atingido\n");
        return;
    }
    printf("Digite o codigo do produto: ");
    scanf("%i", &cod);
    getchar();
    printf("Digite a descricao do produto: ");
    scanf("%[^\n]s", desc);
    printf("Digite o preco do produto: ");
    scanf("%f", &preco);

    struct Produtos produto;
    produto.cod = cod;
    produto.preco = preco;
    strcpy(produto.desc, desc);
    prods[qntp] = produto;
    printf("\nO produto foi registrado com sucesso.");

}

void registrarCompra()
{
    int sucesso = 0;
    printf("Digite o codigo do produto: ");
    scanf("%i", &codCProd);
    printf("Digite a quantidade: ");
    scanf("%i", &qntCompra);
    printf("Digite o numero de parcelas: ");
    scanf("%i", &parcCompra);
    if (parcCompra <= 0){
        printf("Erro: A parcela devera ser maior que 1.\n");
        return;
    }
     for (int ii = 1; ii <= qnt+2; ii++)
    {
        for (int jj = 0; jj <= qntp; jj++){
            int codCompra = codCProd;
            if (codCompra == prods[jj].cod)
            {
                sucesso = 1;
            }
        }
    }
    if (sucesso == 0){
        printf("\nO codigo nao esta cadastrado\n");
    }else{
        codCompra++;
        qnt++;
        i++;
        compras[i][j] = codCompra;
        compras[i][j+1] = codCProd;
        compras[i][j+2] = qntCompra;
        compras[i][j+3] = parcCompra;
        printf("\nitem comprado\n");
    }
}

float saldoDevedor()
{
    float divida = 0, pago[30], totalpago = 0, divida2 = 0;
    for (int i = 1; i <= qnt+1; i++)
    {
        for (int j = 0; j <= qntp; j++){
            int codCompra = compras[i][2], QntCompra = compras[i][3];
            if (codCompra == prods[j].cod)
            {
                divida += QntCompra * prods[j].preco;
                divida2 = QntCompra * prods[j].preco;
                pago[j] = divida2 / compras[i][4];
                totalpago += pago[j];
                printf("Pago = %f\n", pago[j]);
                printf("%s comprado.\n", prods[j].desc);
            }
        }
    }
     printf("Total Pago = %f\n", totalpago);
    return (divida - totalpago);
}

float prodParcNPagos()
{
    float divida = 0;
    printf("Produto - descricao - valor\n");
    for (int i = 1; i <= qnt+1; i++)
    {
        for (int j = 0; j <= qntp; j++){
            int codCompra = compras[i][2], parcCompra = compras[i][4];
            if (codCompra == prods[j].cod && parcCompra > 1)
            {
                divida += compras[i][3] * prods[j].preco;
                printf("|  %i  |  %s  |  %f  |", prods[j].cod, prods[j].desc, prods[j].preco);
            }
        }
        printf("\n");
    }
    return (divida);
}

void listarMatrix()
{
    float divida = 0, pago[30], totalpago = 0, divida2 = 0, MatrixC[30][30], info[30][30];

int x = 1;
    for (int i = 1; i <= qnt+1; i++)
    {
        for (int j = 0; j <= qntp; j++){
            int codCompra = compras[i][2], QntCompra = compras[i][3];
            if (codCompra == prods[j].cod)
            {
                divida += QntCompra * prods[j].preco;
                divida2 = QntCompra * prods[j].preco;
                pago[j] = divida2 / compras[i][4];
                totalpago += pago[j];
                info[i][x] = divida2;
                info[i][x+1] = totalpago;
                printf("x == %i == %f", x, info[i][x]);
                printf("Pago = %f\n", pago[j]);
                printf("%s comprado.\n", prods[j].desc);
            }
        }
    }
    printf("Codigo da compra - Codigo do produto - quantidade - parcelas\n");
    for (int ii = 1; ii < i+1; ii++)
    {
        for(int jj = 1; jj <= j+5; jj++)
        {
            if (jj <= j+3){
            MatrixC[ii][jj] = compras[ii][jj];
            }else if (jj == 4){
                MatrixC[ii][jj] = divida;
            }else if (jj == 5){
                MatrixC[ii][jj] = pago[x];
                x++;
            }
        printf("|      %.0f      | ", MatrixC[ii][jj]);
        }
        printf("\n");
    }
}