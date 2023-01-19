#include<stdio.h>
#include<windows.h>
int A[100];
int inputsize, n;
int swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int Heapsize;

/* Function to sort an array using insertion sort*/
void insertionSort(int A[], int inputsize)
{
	int i, key, j;
	for (i = 1; i < n; i++) {
		key = A[i];
		j = i - 1;
		while (j >= 0 && A[j] > key) {
			A[j + 1] = A[j];
			j = j - 1;
		}
		A[j + 1] = key;
	}

    for (i = 0; i < inputsize; i++)
    {
    printf("%d ", A[i]);
    }
	printf("\n");

}


//Partition function
int partition(int A[], int l, int h)
{
    int i, j,pivot;
    pivot = A[h];
    i = l-1;
    j = l;
    for( j=l; j<=h-1; j++)
    {
        if (A[j]<=pivot)
        {
            i++;
            swap(&A[i], &A[j]);
        }
    }
    swap(&A[i+1], &A[h]);
    return i+1;
}
//quicksort function

int Quicksort(int A[], int l, int h)
{
    int q ;
    if (l<h)
    {
         q = partition(A, l,h);
         Quicksort(A,l,q-1);
         Quicksort(A, q+1, h);
    }
}


int Left(int i)
{
    return i*2;
}
int Right(int i)
{
    return (i*2)+1;
}
void MaxHeapify(int a[],int i)
{
    int largest,temp;
    int l=Left(i);
    int r=Right(i);
    if(l<=Heapsize&&a[l]>a[i])
        largest=l;
    else
        largest=i;
    if(r<=Heapsize&&a[r]>a[largest])
        largest=r;
    if(largest!=i)
    {
        temp=a[i];
        a[i]=a[largest];
        a[largest]=temp;
        MaxHeapify(a,largest);
    }
}
void BuildMaxHeap(int a[])
{
    int i;
    Heapsize=inputsize;
    for(i=inputsize/2;i>=1;i--)
    {
        MaxHeapify(a,i);
    }
}
void HeapSort(int a[])
{
    int i,temp;
    BuildMaxHeap(a);
    for(i=inputsize;i>=2;i--)
    {
        temp=a[1];
        a[1]=a[i];
        a[i]=temp;
        Heapsize--;
        MaxHeapify(a,1);
    }
}

int shellSort(int A[], int inputsize)
{
    int i,j,interval,temp;
    for (interval=inputsize/2;interval>0;interval/=2)
    {
        for (i=interval;i<inputsize;i++)
        {
            temp = A[i];
            for (j=i;j>=interval&&A[j-interval]>temp;j-=interval)
            {
                A[j]=A[j-interval];
            }
            A[j]=temp;
        }
    }
}

int countingsort(int a[])
{
    int A[inputsize+1],k=A[1];
    int c[k];
    int b[inputsize+1];
    int i,j;
    for(i=0;i<inputsize;i++)
    {
        scanf("%d",&A[i]);
        if(k<A[i])
        {
            k=A[i];
        }
    }
    for( i=0;i<=k;i++)
    {
        c[i]=0;
    }
    for(j=1;j<=inputsize;j++)
    {
        c[a[j]]=c[a[j]]+1;
    }
    for(i=1;i<=k;i++)
    {
        c[i]=c[i]+c[i-1];
    }
    for(i=inputsize;i>0;i--)
    {
        b[c[a[i]]]=a[i];
        c[a[i]]=c[a[i]]-1;
    }

}


int main()
{

    system("COLOR 0B");
	while (1) {
        printf("\n\t\t\t===========================================================\n");
        printf("\t\t\t=                    =MULTIPLE SORTING=                     =\n");

        printf("\t\t\t=            Developed by MD. ASAD MONDALL(20CSE006)        =\n");
        printf("\t\t\t=============================================================\n");
        printf("\n\n");

       printf("\n\t\t\tEnter the inputsize :");
       scanf("%d",&inputsize);
       printf("\n\t\t\tEnter %d elements :",inputsize);
       for( int i= 0; i<inputsize; i++ )
       {
        scanf("%d", &A[i]);
       }
       insertionSort(A, inputsize);
        printf("\n\t\t\tTo perform sort, Enter your choice:\t");
		printf("\n\n\t\t\t");
		printf("\n\t\t\t1)INSERTION SORT\n");
		printf("\n\t\t\t2)QUICK SORT\n");
		printf("\n\t\t\t3)SHELL SORT\n");
        printf("\n\t\t\t4)COUNTING SORT\n");
		printf("\n\t\t\t5)MERGE SORT\n");
		printf("\n\t\t\t6)EXIT\n");
	    int i,s;

		scanf("%d", &s);
		//system("CLS");
		//switch (s) {
		    //case 1:{

	}

}
