#include <stdio.h>
#include <stdlib.h>

struct Item {
    int weight;
    int value;
};

int compare(const void *a, const void *b) {
    struct Item *item1 = (struct Item *)a;
    struct Item *item2 = (struct Item *)b;
    double r1 = (double)item1->value / item1->weight;
    double r2 = (double)item2->value / item2->weight;
    if (r1 < r2) return 1;
    else if (r1 > r2) return -1;
    else return 0;
}

int discreteKnapsack(struct Item items[], int n, int capacity) {
    qsort(items, n, sizeof(struct Item), compare);
    int totalValue = 0;
    int currentWeight = 0;
    for (int i = 0; i < n; i++) {
        if (currentWeight + items[i].weight <= capacity) {
            currentWeight += items[i].weight;
            totalValue += items[i].value;
        }
    }
    return totalValue;
}

double continuousKnapsack(struct Item items[], int n, int capacity) {
    qsort(items, n, sizeof(struct Item), compare);
    double totalValue = 0.0;
    int currentWeight = 0;
    for (int i = 0; i < n; i++) {
        if (currentWeight + items[i].weight <= capacity) {
            currentWeight += items[i].weight;
            totalValue += items[i].value;
        } else {
            int remainingCapacity = capacity - currentWeight;
            totalValue += (double)items[i].value / items[i].weight * remainingCapacity;
            break;
        }
    }
    return totalValue;
}
int main() {
    int n, capacity;
    printf("Enter the number of items: ");
    scanf("%d", &n);
    printf("Enter the capacity of knapsack: ");
    scanf("%d", &capacity);
    struct Item items[n];
    printf("Enter the weight and value of each item:\n");
    for (int i = 0; i < n; i++) {
        printf("Item %d: ", i + 1);
        scanf("%d %d", &items[i].weight, &items[i].value);
    }
    int discreteResult = discreteKnapsack(items, n, capacity);
    printf("Maximum value for discrete knapsack: %d\n", discreteResult);
    double continuousResult = continuousKnapsack(items, n, capacity);
    printf("Maximum value for continuous knapsack: %.2f\n", continuousResult);
    return 0;
}
