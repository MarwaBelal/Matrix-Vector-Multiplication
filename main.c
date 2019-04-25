#include <stdio.h>
#include <omp.h>

int main()
{
    int n,m,o;
    printf("Enter the number of columns in matrix A: ");
    scanf("%d",&n);
    printf("Enter the number of rows in matrix A: ");
    scanf("%d",&m);
    printf("Enter the number of rows in vector X: ");
    scanf("%d",&o);

    if (n!=o)
    {
        printf("Invalid Multiplication.");
        return 0;
    }
    int i,j;
    int A[m][n];
    int X[o];

    printf("Enter numbers of the matrix:  ");
    for(i=0; i<m; i++)
    {
        for(j=0; j<n; j++)
        {
            scanf("%d",&A[i][j]);
        }
    }

    printf("Enter numbers of the vector:  ");
    for(i=0; i<o; i++)
    {
        scanf("%d",&X[i]);
    }

    int Ax[m];

    #pragma omp parallel for
    for (i=0; i<m; i++)
    {
        Ax[i]=0;
        for (j=0; j<n; j++)
        {
            Ax[i]+=A[i][j]*X[j];
        }
    }

    for (i=0; i<m; i++)
    {
        printf("Ax[%i]=%d \n",i,Ax[i]);
    }

    return 0;
}
