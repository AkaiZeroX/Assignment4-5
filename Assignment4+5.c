#include <stdio.h>
#include <string.h>

enum ProductType { CLOTHING, FOOTWEAR, ELECTRONICS };

union ProductInfo {
    int size;       // Clothing and footwear
    float weight;   // Electronics
};

struct Product {
    char name[50];
    float price;
    enum ProductType type;
    union ProductInfo info;
};

int main() {
    int numProducts;

    printf("Enter the number of products: ");
    scanf("%d", &numProducts);

    struct Product products[numProducts];

    for (int i = 0; i < numProducts; i++) {
        printf("\nEnter information for product %d:\n", i + 1);
        printf("Name: ");
        scanf("%s", products[i].name);
        printf("Price: ");
        scanf("%f", &products[i].price);
        printf("Type (0: Clothing, 1: Footwear, 2: Electronics): ");
        scanf("%d", (int *)&products[i].type);

        if (products[i].type == CLOTHING || products[i].type == FOOTWEAR) {
            printf("Size: ");
            scanf("%d", &products[i].info.size);
        } else if (products[i].type == ELECTRONICS) {
            printf("Weight: ");
            scanf("%f", &products[i].info.weight);
        }
    }

    char searchName[50];
    printf("\nEnter the name of the product to retrieve information: ");
    scanf("%s", searchName);

    int found = 0;
    for (int i = 0; i < numProducts; i++) {
        if (strcmp(searchName, products[i].name) == 0) {
            printf("\nProduct Information:\n");
            printf("Name: %s\n", products[i].name);
            printf("Price: %.2f\n", products[i].price);
            printf("Type: %s\n",
                   products[i].type == CLOTHING ? "Clothing" : (products[i].type == FOOTWEAR ? "Footwear" : "Electronics"));
            if (products[i].type == CLOTHING || products[i].type == FOOTWEAR) {
                printf("Size: %d\n", products[i].info.size);
            } else if (products[i].type == ELECTRONICS) {
                printf("Weight: %.2f\n", products[i].info.weight);
            }
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("\nProduct not found.\n");
    }

    return 0;
}
