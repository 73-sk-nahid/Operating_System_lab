#include <stdio.h>
#define max 25
int main() {
    int nb, nf, i, b[max], f[max], j, temp, highest=0 , frag[max] ;
    static int bf[max], ff[max];
    printf("Enter the number of block: ");
    scanf("%d", &nb);
    
    printf("Enter the number of files: ");
    scanf("%d", &nf);
    printf("Enter the size of the blocks: \n");
    for (i=1; i<=nb; i++)
    {
        printf("For block %d: ", i);
        scanf("%d", &b[i]);
    }
    printf("Enter the size of the files:\n");
    for (i=1; i<=nf; i++)
    {
        printf("For file %d: ", i);
        scanf("%d", &f[i]);
    }
    for(i=1; i<=nf; i++)
    {
        for(j=1; j<=nb; j++)
        {
            if(bf[j] != 1)
            {
                temp = b[j] - f[i];
                if(temp>= 0)
                    if(highest<temp)
                    {
                        ff[i] = j;
                        highest = temp;
                    }
            }
        }
        frag[i]= highest;
        bf[ff[i]] = 1;
        highest = 0;
    }
    printf("File No \tFile Size \tBlock No \tBlock Size \tFragment\n");
    for(i=1; i<=nf; i++)
        printf("\t %d \t\t\t %d \t\t\t %d \t\t\t %d \t\t\t %d \n", i, f[i], ff[i], b[ff[i]], frag[i]);

    return 0;
}