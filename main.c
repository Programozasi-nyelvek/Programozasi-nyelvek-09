#include <stdio.h>

struct user {
    char *username;
    int bday;
};

void array_nth(int a[], int x)
{
    int *p = &a[x];

    printf("%d\n", *p);

    printf("-4 5 kozotti szam: ");
    scanf("%d", &x);

    printf("%d\n", *p+x);
}

void sort (struct user *data, int n)
{
    struct user tmp[1];

    printf("Rendezes elott:\n");
    for (int i=0; i<n; i++)
        printf("%10s %4d\n",data[i].username, data[i].bday);

    for (int i=0; i<n-1; i++)
        for (int j=0; j<n-1; j++)
            if (data[j].bday>data[j+1].bday)
            {
                tmp[0]=data[j];
                data[j]=data[j+1];
                data[j+1]=tmp[0];
            }

    printf("Rendezes utan:\n");
    for (int i=0; i<n; i++)
        printf("%10s %4d\n",data[i].username, data[i].bday);
}

void find_adults(struct user *data, int n)
{
    int i=0;
    int year = 2019;

    printf("%d\n", year - data[0].bday);

    while ( (i<n) && (year - data[i].bday >= 18))
    {
        printf("%10s %4d\n", data[i].username, data[i].bday);
        i++;
    }
}



int main()
{
    // 1. Készíts egy 10 elemű, egész számokat tartalmazó tömböt értékekkel! Állíts be egy pointer a tömb ötödik elemére!
    // Kérj be egy -4, +5 közötti számot, ami kiírja a tömb megfelelő sorszámú elemét a pointerhez képest!
    int array[] = {0,1,2,3,4,5,6,7,8,9};
    //array_nth(array,5);

    // 2. Készíts struktúrát, ami egy felhasználó nevét és születési évét tárolja! Készíts egy 5 elemű tömböt belőle!
    struct user user[5] = {
        {"Gabor",1987},
        {"a",1998},
        {"b",2014},
        {"c",2007},
        {"d",1999}
    };

    //printf("%s %d\n", user[0].username, user[0].bday);

    // 3. Rendezd növekvő sorba az előző feladat tömbjét, a felhasználók születési éve szerint! Írasd ki az elemeket!
    sort(user,5);

    // 4. Készíts függvényt, ami a felhasználók tömbjéből kiválogatja azokat, akik nagykorúak (betöltötték a 18-at)!
    // A függvény térjen vissza az eredménytömb címével!
    find_adults(user,5);

    return 0;
}