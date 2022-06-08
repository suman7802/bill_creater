#include <stdio.h>
typedef struct product
{
    char name[15];
    float qty;
    float price;
} pr;
int main()
{
    int i, n;
    float t = 0;
    char c_name[15];
    FILE *ptr;
    char up1[] = "\t--------------------------------------\n";
    ptr = fopen("gorkha_department_store.txt", "w");

    printf("Name of customer: ");
    fflush(stdin);
    gets(c_name);
    printf("Product bill count : ");
    scanf("%d", &n);
    pr pr[n];

    for (i = 0; i < n; i++)
    {

        printf("Enter product no.%d name: ", i + 1);
        fflush(stdin);
        gets(pr[i].name);
        printf("Enter product no.%d quantity(pic/kg): ", i + 1);
        scanf("%f", &pr[i].qty);
        printf("Enter product no.%d price(in Rs.): ", i + 1);
        scanf("%f", &pr[i].price);
        printf("\n");
    }

    printf("%s\t\tGorkha Department Store\n%s", up1, up1);
    printf("\t\tCustomer Name: %s\n%s", c_name, up1);
    printf("\tProduct\t\tQty\tRate\tAmount\n\n");

    fprintf(ptr, "%s\t\t\tGorkha Department Store\n%s", up1, up1);
    fprintf(ptr, "\t\tCustomer Name: %s\n%s", c_name, up1);
    fprintf(ptr, "\t\tProduct\t\tQty\t\tRate\tAmount\n\n");

    for (i = 0; i < n; i++)
    {
        printf("\t%s\t\t%.1f\t%.2f\t%.2f", pr[i].name, pr[i].qty,
               pr[i].price, pr[i].price * pr[i].qty);
        printf("\n");

        fprintf(ptr, "\t\t%s\t\t%.1f\t\t%.2f\t%.2f", pr[i].name, pr[i].qty,
                pr[i].price, pr[i].price * pr[i].qty);
        fprintf(ptr, "\n");
    }

    for (size_t i = 0; i < n; i++)
    {

        float totel = pr[i].price * pr[i].qty;
        t = t + totel;
    }
    printf("\t\t\tTotel\t%.2f\n%s", t, up1);
    fprintf(ptr, "\t\t\t\t\t\tTotel\t%.2f\n%s", t, up1);

    fclose(ptr);

    return 0;
}