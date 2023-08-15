//PAGE REPLACEMENT ALGORITHM-OPTIMAL

#include <stdio.h>

int main() {
    int i, j, k, rs[25], m[10], flag[25] = {0}, n, f, pf = 0;

    printf("Enter the length of the reference string: ");
    scanf("%d", &n);
    printf("Enter the reference string: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &rs[i]);
    }
    printf("Enter the number of frames: ");
    scanf("%d", &f);

    printf("\nThe Page Replacement process is --\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < f; j++) {
            if (m[j] == rs[i]) {
                flag[i] = 1;
                break;
            }
        }

        if (flag[i] == 0) {
            int replaceIndex = -1;
            int farthestIndex = i + 1;

            for (j = 0; j < f; j++) {
                int pageFoundLater = 0;

                for (k = i + 1; k < n; k++) {
                    if (m[j] == rs[k]) {
                        pageFoundLater = 1;
                        if (k > farthestIndex) {
                            farthestIndex = k;
                            replaceIndex = j;
                        }
                        break;
                    }
                }

                if (!pageFoundLater) {
                    replaceIndex = j;
                    break;
                }
            }

            m[replaceIndex] = rs[i];
            pf++;
        }

        for (j = 0; j < f; j++) {
            printf("%d\t", m[j]);
        }

        if (flag[i] == 0) {
            printf("PF no. -- %d", pf);
        }

        printf("\n");
    }

    printf("\nThe number of page faults using Optimal algorithm: %d\n", pf);
 printf("\nThe number of page hits using Optimal algorithm: %d\n",n-pf);
 return 0;
}

/*OUTPUT
Enter the length of the reference string: 12
Enter the reference string: 2 3 2 1 5 2 4 5 3 2 5 2
Enter the number of frames: 3

The Page Replacement process is --
2       0       0       PF no. -- 1
2       3       0       PF no. -- 2
2       3       0
2       3       1       PF no. -- 3
2       3       5       PF no. -- 4
2       3       5
4       3       5       PF no. -- 5
4       3       5
4       3       5
2       3       5       PF no. -- 6
2       3       5
2       3       5

The number of page faults using Optimal algorithm: 6

The number of page hits using Optimal algorithm: 6 */
