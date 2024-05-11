#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define K 2 // Número de clusters
#define MAX_ITERS 100 // Número máximo de iterações

// Estrutura para representar um ponto 2D
typedef struct Point {
    double x;
    double y;
} Point;

// Função para calcular a distância euclidiana entre dois pontos
double distance(Point a, Point b) {
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

// Função para atribuir cada ponto ao cluster mais próximo
void assignClusters(Point points[], Point centroids[], int clusters[], int n) {
    for (int i = 0; i < n; i++) {
        double minDist = distance(points[i], centroids[0]);
        clusters[i] = 0;
        for (int j = 1; j < K; j++) {
            double dist = distance(points[i], centroids[j]);
            if (dist < minDist) {
                minDist = dist;
                clusters[i] = j;
            }
        }
    }
}

// Função para atualizar os centróides de cada cluster
void updateCentroids(Point points[], Point centroids[], int clusters[], int n) {
    for (int i = 0; i < K; i++) {
        double sumX = 0, sumY = 0;
        int count = 0;
        for (int j = 0; j < n; j++) {
            if (clusters[j] == i) {
                sumX += points[j].x;
                sumY += points[j].y;
                count++;
            }
        }
        if (count > 0) {
            centroids[i].x = sumX / count;
            centroids[i].y = sumY / count;
        }
    }
}

int main() {
    Point points[] = {{1, 2}, {5, 8}, {1.5, 1.8}, {8, 8}, {1, 0.6}, {9, 11}};
    int n = sizeof(points) / sizeof(points[0]);

    Point centroids[K];
    centroids[0] = points[0]; // Inicializa os centróides com os primeiros pontos
    centroids[1] = points[1];

    int clusters[n];
    int iters = 0;

    while (iters < MAX_ITERS) {
        assignClusters(points, centroids, clusters, n);
        updateCentroids(points, centroids, clusters, n);
        iters++;
    }

    // Mostra os resultados
    printf("Labels dos clusters:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", clusters[i]);
    }
    printf("\n");

    printf("CentrÓides dos clusters:\n");
    for (int i = 0; i < K; i++) {
        printf("(%f, %f)\n", centroids[i].x, centroids[i].y);
    }

    return 0;
}
