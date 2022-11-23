#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(int argc, char **argv) {

    int menuOp;
    int i;
    int j;
    int k;
    int col;
    int lin;    
    int vmax;

    int media; // Variável para criar a imagem em Escala de Cinza
    int meiaColuna; 
    int meiaLinha;

    // Criação das variáveis e abertura das imagens
    FILE *origem = fopen(argv[1], "r");

    char buffer[250];
    fgets(buffer, 250, origem);
    fgets(buffer, 250, origem);
    fscanf(origem, "%d %d", &col, &lin);
    int matriz[lin][col][3];
    fscanf(origem, "%d", &vmax);
    for(i = 0; i < lin; i++) {

        for(j = 0; j < col; j++) {

            for(k = 0; k < 3; k++) {

                fscanf(origem, "%d", &matriz[i][j][k]);

            }

        }

    }

    do {

        printf("\t\t\nMenu de manipulacao de imagens\n");
        printf("0. Sair\n");
        printf("1. Converter uma imagem colorida para escala de cinza\n");
        printf("2. Espelhar uma imagem horizontalmente\n");
        printf("3. Espelhar uma imagem verticalmente\n");
        printf("4. Dividir uma imagem em dois arquivos (um arquivo com a metade esquerda, e outro arquivo com a metade direita)\n");
        printf("5. Dividir uma imagem em dois arquivos (um arquivo com a metade superior, e outro arquivo com a metade inferior)\n");
        printf("6. Colorir uma imagem artificialmente\n");
        printf("7. Rotacionar uma imagem 90 graus para a direita\n");
        printf("8. Rotacionar uma imagem 90 graus para a esquerda\n");
        printf("9. Gerar uma imagem copia da original, porem com uma parte da imagem em escala de cinza\n");
        printf("10. Gerar tres arquivos de saida. Um para cada camada (R, G e B)\n");
        printf("Opcao: ");
        scanf("%d", &menuOp);

        switch (menuOp) {

            case 0:
                
                printf("Saindo...\n");

            break;

            case 1:

                printf("");
                FILE *imagemEscalaDeCinza = fopen("imagemEscalaDeCinza.ppm", "w");

                fprintf(imagemEscalaDeCinza, "P3\n");
                fprintf(imagemEscalaDeCinza, "# Criado por Henrique\n");
                fprintf(imagemEscalaDeCinza, "%d %d\n", col, lin);
                fprintf(imagemEscalaDeCinza, "%d\n", vmax);
                for(i = 0; i < lin; i++) {

                    for(j = 0; j < col; j++) {

                        media = (matriz[i][j][0] + matriz[i][j][1] + matriz[i][j][3]) / 3;
                        fprintf(imagemEscalaDeCinza, "%d ", media);
                        fprintf(imagemEscalaDeCinza, "%d ", media);
                        fprintf(imagemEscalaDeCinza, "%d ", media);

                    }

                }

                fclose(imagemEscalaDeCinza);

            break;

            case 2:
                
                printf("");
                FILE *imagemEspelhadaHorizontal = fopen("imagemEspelhadaHorizontal.ppm", "w");

                fprintf(imagemEspelhadaHorizontal, "P3\n");
                fprintf(imagemEspelhadaHorizontal, "# Criado por Henrique\n");
                fprintf(imagemEspelhadaHorizontal, "%d %d\n", col, lin);
                fprintf(imagemEspelhadaHorizontal, "%d\n", vmax);
                for(i = 0; i < lin; i++) {

                    for(j = col-1; j >= 0; j--) {

                        for(k = 0; k < 3; k++) {

                            fprintf(imagemEspelhadaHorizontal, "%d ", matriz[i][j][k]);

                        }         

                    }

                }

                fclose(imagemEspelhadaHorizontal);

            break;

            case 3:
                
                printf("");
                FILE *imagemEspelhadaVertical = fopen("imagemEspelhadaVertical.ppm", "w");

                fprintf(imagemEspelhadaVertical, "P3\n");
                fprintf(imagemEspelhadaVertical, "# Criado por Henrique\n");
                fprintf(imagemEspelhadaVertical, "%d %d\n", col, lin);
                fprintf(imagemEspelhadaVertical, "%d\n", vmax);
                for(i = lin-1; i >= 0; i--) {

                    for(j = 0; j < col; j++) {

                        for(k = 0; k < 3; k++) {

                            fprintf(imagemEspelhadaVertical, "%d ", matriz[i][j][k]);

                        }         

                    }

                }

                fclose(imagemEspelhadaVertical);



            break;

            case 4:

                printf("");
                FILE *imagemMetadeEsquerda = fopen("imagemMetadeEsquerda.ppm", "w");
                FILE *imagemMetadeDireita = fopen("imagemMetadeDireita.ppm", "w");
                
                meiaColuna = col / 2;

                // Metade esquerda da imagem
                fprintf(imagemMetadeEsquerda, "P3\n");
                fprintf(imagemMetadeEsquerda, "# Criado por Henrique\n");
                fprintf(imagemMetadeEsquerda, "%d %d\n", meiaColuna, lin);
                fprintf(imagemMetadeEsquerda, "%d\n", vmax);            
                for(i = 0; i < lin; i++) {

                    for(j = 0; j < meiaColuna; j++) {

                        for(k = 0; k < 3; k++) {

                            fprintf(imagemMetadeEsquerda, "%d ", matriz[i][j][k]);

                        }

                    }

                }

                // Metade direita da imagem
                fprintf(imagemMetadeDireita, "P3\n");
                fprintf(imagemMetadeDireita, "# Criado por Henrique\n");
                fprintf(imagemMetadeDireita, "%d %d\n", meiaColuna, lin);
                fprintf(imagemMetadeDireita, "%d\n", vmax);
                for(i = 0; i < lin; i++) {

                    for(j = meiaColuna; j < col; j++) {

                        for(k = 0; k < 3; k++) {

                            fprintf(imagemMetadeDireita, "%d ", matriz[i][j][k]);

                        }
                        
                    }

                }

                fclose(imagemMetadeEsquerda);
                fclose(imagemMetadeDireita);

            break;

            case 5:

                printf("");
                FILE *imagemMetadeCima = fopen("imagemMetadeCima.ppm", "w");
                FILE *imagemMetadeBaixo = fopen("imagemMetadeBaixo.ppm", "w");


                meiaLinha = lin / 2;

                fprintf(imagemMetadeCima, "P3\n");
                fprintf(imagemMetadeCima, "# Criado por Henrique\n");
                fprintf(imagemMetadeCima, "%d %d\n", col, meiaLinha);
                fprintf(imagemMetadeCima, "%d\n", vmax);
                for(i = 0; i < meiaLinha; i++) {

                    for(j = 0; j < col; j++) {

                        for(k = 0; k < 3; k++) {

                            fprintf(imagemMetadeCima, "%d ", matriz[i][j][k]);

                        }          

                    }

                }

                fprintf(imagemMetadeBaixo, "P3\n");
                fprintf(imagemMetadeBaixo, "# Criado por Henrique\n");
                fprintf(imagemMetadeBaixo, "%d %d\n", col, meiaLinha);
                fprintf(imagemMetadeBaixo, "%d\n", vmax);
                for(i = meiaLinha; i < lin; i++) {

                    for(j = 0; j < col; j++) {

                        for(k = 0; k < 3; k++) {

                            fprintf(imagemMetadeBaixo, "%d ", matriz[i][j][k]);

                        }
                        
                    }

                }

                fclose(imagemMetadeCima);
                fclose(imagemMetadeBaixo);

            break;

            case 6:

                printf("");
                FILE *imagemEscalaDeCinza2 = fopen("imagemEscalaDeCinza2.ppm", "w");
                FILE *imagemColorida = fopen("imagemColorida.ppm", "w");


                fprintf(imagemEscalaDeCinza2, "P3\n");
                fprintf(imagemEscalaDeCinza2, "# Criado por Henrique\n");
                fprintf(imagemEscalaDeCinza2, "%d %d\n", col, lin);
                fprintf(imagemEscalaDeCinza2, "%d\n", vmax);
                for(i = 0; i < lin; i++) {

                    for(j = 0; j < col; j++) {

                        media = (matriz[i][j][0] + matriz[i][j][1] + matriz[i][j][3]) / 3;
                        fprintf(imagemEscalaDeCinza2, "%d ", media);
                        fprintf(imagemEscalaDeCinza2, "%d ", media);
                        fprintf(imagemEscalaDeCinza2, "%d ", media);

                    }

                }

                fprintf(imagemColorida, "P3\n");
                fprintf(imagemColorida, "# Criado por Henrique\n");
                fprintf(imagemColorida, "%d %d\n", col, lin);
                fprintf(imagemColorida, "%d\n", vmax);
                for(i = 0; i < lin; i++) {

                    for(j = 0; j < col; j++) {

                        if(matriz[i][j][0] <= 32) {

                            fprintf(imagemColorida, "245 57 10 ");

                        }
                        else if((matriz[i][j][0] > 32) && (matriz[i][j][0] <= 64)) {

                            fprintf(imagemColorida, "242 201 19 ");

                        }
                        else if((matriz[i][j][0] > 64) && (matriz[i][j][0] <= 96)) {

                            fprintf(imagemColorida, "28 227 25 ");

                        }
                        else if((matriz[i][j][0] > 96) && (matriz[i][j][0] <= 128)) {

                            fprintf(imagemColorida, "7 67 219 ");

                        }
                        else if((matriz[i][j][0] > 128) && (matriz[i][j][0] <= 160)) {

                            fprintf(imagemColorida, "230 11 226 ");

                        }
                        else if((matriz[i][j][0] > 160) && (matriz[i][j][0] <= 192)) {

                            fprintf(imagemColorida, "133 12 78 ");

                        }
                        else if((matriz[i][j][0] > 192) && (matriz[i][j][0] <= 224)) {

                            fprintf(imagemColorida, "122 47 4 ");

                        }
                        else if((matriz[i][j][0] > 224) && (matriz[i][j][0] <= 255)) {

                            fprintf(imagemColorida, "63 232 235 ");

                        }

                    }

                }
                
                fclose(imagemEscalaDeCinza2);
                fclose(imagemColorida);

            break;

            case 7:

                printf("");
                FILE *imagem90grausEsquerda = fopen("imagem90grausEsquerda.ppm", "w");

                fprintf(imagem90grausEsquerda, "P3\n");
                fprintf(imagem90grausEsquerda, "# Criado por Henrique\n");
                fprintf(imagem90grausEsquerda, "%d %d\n", lin, col);
                fprintf(imagem90grausEsquerda, "%d\n", vmax);
                for(i = 0; i < col; i++) {

                    for(j = 0; j < lin; j++) {

                        for(k = 0; k < 3; k++) {

                            fprintf(imagem90grausEsquerda, "%d ", matriz[j][i][k]);

                        }         

                    }

                }

                fclose(imagem90grausEsquerda);

            break;

            case 8:

                printf("");
                FILE *imagem90grausDireita = fopen("imagem90grausDireita.ppm", "w");

                fprintf(imagem90grausDireita, "P3\n");
                fprintf(imagem90grausDireita, "# Criado por Henrique\n");
                fprintf(imagem90grausDireita, "%d %d\n", lin, col);
                fprintf(imagem90grausDireita, "%d\n", vmax);
                for(i = 0; i < col; i++) {

                    for(j = 0; j < lin; j++) {

                        for(k = 0; k < 3; k++) {

                            fprintf(imagem90grausDireita, "%d ", matriz[j][i][k]);

                        }         

                    }

                }

                fclose(imagem90grausDireita);

            break;

            case 9:

                printf("");
                FILE *imagemCentroEscalaDeCinza = fopen("imagemCentroEscalaDeCinza.ppm", "w");

                int col2, col3, lin2, lin3;

                col2 = col / 4;
                lin2 = lin / 4;

                col3 = col - col2;
                lin3 = lin - lin2;

                printf("%d %d %d\n", col, col2, col3);
                printf("%d %d %d\n", lin, lin2, lin3);

                fprintf(imagemCentroEscalaDeCinza, "P3\n");
                fprintf(imagemCentroEscalaDeCinza, "# Criado por Henrique\n");
                fprintf(imagemCentroEscalaDeCinza, "%d %d\n", col, lin);
                fprintf(imagemCentroEscalaDeCinza, "%d\n", vmax);
                for(i = 0; i < lin; i++) {

                    for(j = 0; j < col; j++) {

                        for(k = 0; k < 3; k++) {

                            if((i >= lin2) && (i < lin3) && (j >= col2) && (j < col3)) {

                                media = (matriz[i][j][0] + matriz[i][j][1] + matriz[i][j][3]) / 3;
                                fprintf(imagemCentroEscalaDeCinza, "%d ", media);

                            }
                            else {

                                fprintf(imagemCentroEscalaDeCinza, "%d ", matriz[i][j][k]);

                            }

                        }          

                    }

                }

                fclose(imagemCentroEscalaDeCinza);

            break;

            case 10:
                
                printf("");
                FILE *imagemR = fopen("imagemR.ppm", "w");
                FILE *imagemG = fopen("imagemG.ppm", "w");
                FILE *imagemB = fopen("imagemB.ppm", "w");

                fprintf(imagemR, "P3\n");
                fprintf(imagemR, "# Criado por Henrique\n");
                fprintf(imagemR, "%d %d\n", col, lin);
                fprintf(imagemR, "%d\n", vmax);
                for(i = 0; i < lin; i++) {

                    for(j = 0; j < col; j++) {

                        fprintf(imagemR, "%d ", matriz[i][j][0]);
                        fprintf(imagemR, "%d ", 0);
                        fprintf(imagemR, "%d ", 0);

                    }

                }

                fprintf(imagemG, "P3\n");
                fprintf(imagemG, "# Criado por Henrique\n");
                fprintf(imagemG, "%d %d\n", col, lin);
                fprintf(imagemG, "%d\n", vmax);
                for(i = 0; i < lin; i++) {

                    for(j = 0; j < col; j++) {

                        fprintf(imagemG, "%d ", 0);
                        fprintf(imagemG, "%d ", matriz[i][j][0]);
                        fprintf(imagemG, "%d ", 0);

                    }

                }

                fprintf(imagemB, "P3\n");
                fprintf(imagemB, "# Criado por Henrique\n");
                fprintf(imagemB, "%d %d\n", col, lin);
                fprintf(imagemB, "%d\n", vmax);
                for(i = 0; i < lin; i++) {

                    for(j = 0; j < col; j++) {
                        
                        fprintf(imagemB, "%d ", 0);
                        fprintf(imagemB, "%d ", 0);
                        fprintf(imagemB, "%d ", matriz[i][j][0]);

                    }

                }

                fclose(imagemR);
                fclose(imagemG);
                fclose(imagemB);

            break;
            
            default:

                printf("Opcao Invalida!");

            break;
        }

    } while (menuOp);

    fclose(origem);

    return 0;
}