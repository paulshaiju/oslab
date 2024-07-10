//PAGE REPLACEMENT ALGORITHM-OPTIMAL

#include <stdio.h>

int main() {
    int i, j, k, ref_str[20], frames[20],ref_length, frame_length, PF = 0, PH = 0,count=0;

    printf("Enter the length of the reference string: ");
    scanf("%d", &ref_length);

    printf("Enter the reference string: ");
    for (i = 0; i < ref_length; i++) {
        scanf("%d", &ref_str[i]);
    }

    printf("Enter the number of frames: ");
    scanf("%d", &frame_length);

    for (i = 0; i < frame_length; i++) {
        frames[i] = -1;
    }

    printf("\nThe Page Replacement process is \n");
    for (i = 0; i < ref_length; i++) {
        int found = 0;
        for (j = 0; j < frame_length; j++) {
            if (ref_str[i] == frames[j]) {
                found = 1;
                PH++;
                break;
            }
        }

        if (!found) {
            int replace = -1, farthest = -1;
             if(i<frame_length){
            replace=count;
            count++;}else{
            for (j = 0; j < frame_length; j++) {
                int next_use = -1;
                for (k = i + 1; k < ref_length; k++) {
                    if (frames[j] == ref_str[k]) {
                        next_use = k;
                        break;
                    }
                }
                if (next_use == -1) { // This frame is not used again
                    replace = j;
                    break;
                }
                if (next_use > farthest) {
                    farthest = next_use;
                    replace = j;
                }
            }
        }
            frames[replace] = ref_str[i];
            PF++;
        }

        for (j = 0; j < frame_length; j++) 
           printf("\t%d", frames[j]);

        if (found) printf("\tPH No. %d\n", PH);
        else printf("\tPF No. %d\n", PF);
    }
 printf("\nThe number of page faults using Optimal algorithm: %d\n", PF);
 printf("\nThe number of page hits using Optimal algorithm: %d\n",PH);}

/*OUTPUT
Enter the length of the reference string: 7
Enter the reference string: 7 0 1 2 0 3 1
Enter the number of frames: 3

The Page Replacement process is 
        7       -1      -1      PF No. 1
        7       0       -1      PF No. 2
        7       0       1       PF No. 3
        2       0       1       PF No. 4
        2       0       1       PH No. 1
        3       0       1       PF No. 5
        3       0       1       PH No. 2

The number of page faults using Optimal algorithm: 5

The number of page hits using Optimal algorithm: 2 */
