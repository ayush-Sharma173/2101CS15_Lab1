#include <stdio.h>

int n, array[1000], c, d, t, flag = 0, position;
int re=1;

void insertion_sort()
{
    for (c = 1 ; c <= n - 1; c++) 
    {
        t = array[c];

        for (d = c - 1 ; d >= 0; d--) 
        {
            if (array[d] > t) 
            {
                array[d+1] = array[d];
                flag = 1;
            }
            else
                break;
        }

        if (flag)
        array[d+1] = t;
    }
}

void selection_sort()
{
    for (c = 0; c < (n - 1); c++) // finding minimum element (n-1) times
  {
    position = c;

    for (d = c + 1; d < n; d++)
    {
      if (array[position] > array[d])
        position = d;
    }
    if (position != c)
    {
      t = array[c];
      array[c] = array[position];
      array[position] = t;
    }
  }
}

int main()
{
    while (re)
    {
        printf("Enter number of elements\n");
        scanf("%d", &n);

        printf("Enter %d integers\n", n);

        for (c = 0; c < n; c++)
            scanf("%d", &array[c]);

        printf("Which sorting algotithm you want to apply ?\n");
        printf("\nPress 1 for insertion sort");
        printf("\nPress 2 for selection sort");
            printf("\n\n");
            int algo;

            scanf("%d",&algo);

            if(algo==1)
            {
                insertion_sort();
                printf("Sorted list in ascending order (using insertion sort):\n");
            }
            
            if(algo==2)
            {
                selection_sort();
                printf("Sorted list in ascending order (using selection sort):\n");
            }
            


        for (c = 0; c <= n - 1; c++) {
            printf("%d\n", array[c]);
        }
            
            printf("Press 0 to exit and 1 to sort again using diffrent algorithm : ");

            scanf("%d",&re);
    }
  return 0;
}