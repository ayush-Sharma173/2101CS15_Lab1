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


void merge(int p, int q, int r) {

  // Create L ← A[p..q] and M ← A[q+1..r]
  int n1 = q - p + 1;
  int n2 = r - q;

  int L[n1], M[n2];

  for (int i = 0; i < n1; i++)
    L[i] = array[p + i];
  for (int j = 0; j < n2; j++)
    M[j] = array[q + 1 + j];

  // Maintain current index of sub-arrays and main array
  int i, j, k;
  i = 0;
  j = 0;
  k = p;

  // Until we reach either end of either L or M, pick larger among
  // elements L and M and place them in the correct position at A[p..r]
  while (i < n1 && j < n2) {
    if (L[i] <= M[j]) {
      array[k] = L[i];
      i++;
    } else {
      array[k] = M[j];
      j++;
    }
    k++;
  }

  // When we run out of elements in either L or M,
  // pick up the remaining elements and put in A[p..r]
  while (i < n1) {
    array[k] = L[i];
    i++;
    k++;
  }

  while (j < n2) {
    array[k] = M[j];
    j++;
    k++;
  }
}

// Divide the array into two subarrays, sort them and merge them
void mergeSort(int l, int r) {
  if (l < r) {

    // m is the point where the array is divided into two subarrays
    int m = l + (r - l) / 2;

    mergeSort(l, m);
    mergeSort(m + 1, r);

    // Merge the sorted subarrays
    merge(l, m, r);
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


void bubble_sort()
{
    int swap;
    for (c = 0 ; c < n - 1; c++)
    {
        for (d = 0 ; d < n - c - 1; d++)
        {
            if (array[d] > array[d+1]) /* For decreasing order use '<' instead of '>' */
            {
                swap       = array[d];
                array[d]   = array[d+1];
                array[d+1] = swap;
            }
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
        printf("\nPress 3 for bubble sort");
        printf("\nPress 4 for merge sort");
            printf("\n\n");
            int algo;

            scanf("%d",&algo);

            printf("\n");

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
            
            if(algo==3)
            {
                bubble_sort();
                printf("Sorted list in ascending order (using bubble sort):\n");
            }

            if(algo==4)
            {
                mergeSort(0,n-1);
                printf("Sorted list in ascending order (using merge sort):\n");
            }

        for (c = 0; c <= n - 1; c++) {
            printf("%d\n", array[c]);
        }
            
            printf("Press 0 to exit and 1 to sort again using diffrent algorithm : ");

            scanf("%d",&re);
    }
  return 0;
}