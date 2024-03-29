#include <stdio.h>
#include <stdlib.h>

void quickSort(int A[], int low, int high);
int partition (int A[], int low, int high);

void dualSortedSearch (int[],int, int, int[]);

int main()
{
    int i,size,K;
    int* A;
    int index[2] = {-1,-1};

    //Search key
    scanf("%d",&K);

    //create an array
    scanf("%d",&size);
    A=(int *)malloc(sizeof(int)*size);
    for(i=0; i<size; i++)
    {
        scanf("%d",&A[i]);
    }

    quickSort(A,0,size-1);
    dualSortedSearch(A,size,K,index);

    if(index[0]!=-1)
        printf("%d %d\n",index[0], index[1]);
    else
        printf("Not found");

    free(A);
    return 0;
    system ("pause");
}
/*
ALGORITHM EXPLANATION
1. double pointers -> 1 at the start of array and 1 at the end of the array
2. if sum of these 2 pointers is lower than k  -> move 1st pointer up
3. if its larger than k -> move 2nd pointer down
4. once we found the pair == k , we populate it into dualIndex
5. o(n) approach since we are just moving 2 pointers max n times
*/
void dualSortedSearch(int A[], int size, int K, int dualIndex[])
{
    int i = 0;
    int j = size-1;

    while(i <= j)
    {
        //if sum == k -> we found the pair
        if (A[i] + A[j] == K)
            {
                dualIndex[0] = A[i];
                dualIndex[1] = A[j];
                break;
            }
        //if sum < k -> we need to move first pointer up
        else if (A[i] + A[j] < K)
                i++;
        
        else if (A[i] + A[j] > K)
                j--;
    }


}

int partition (int A[], int low, int high)
{
    int pivot = A[high];
    int i = (low - 1);

    int temp;
    for (int j = low; j <= high- 1; j++)
    {
        if (A[j] < pivot)
        {
            i++;

            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
    }

    temp = A[i+1];
    A[i+1]= A[high];
    A[high] = temp;
    return (i + 1);
}

void quickSort(int A[], int low, int high)
{
    if (low < high)
    {
        int pivot = partition(A, low, high);

        quickSort(A, low, pivot - 1);
        quickSort(A, pivot + 1, high);
    }
}
