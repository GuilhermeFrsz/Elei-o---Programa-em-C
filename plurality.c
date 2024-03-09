#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

typedef struct {
    char name[50];
    int votes;
} candidates_t;

void vote(candidates_t candidates[], int num_candidates, char *name){
  for( int i = 0; i < num_candidates; i++){
        if(strcmp(candidates[i].name, name) == 0){
            candidates[i].votes++;
            return;
        }
    }
    printf("Error: Candidate '%s' not found.\n", name);
}

void print_winner(candidates_t candidates[], int num_candidates){
    int max_votes = 0;

    for(int i = 0; i < num_candidates; i++){
        if (candidates[i].votes > max_votes){
            max_votes = candidates[i].votes;
        }
    }

    int winners = 0;
     for(int i = 0; i < num_candidates; i++){
        if(candidates[i].votes == max_votes){
            winners++;
        }
     }

    if(winners > 1){
        printf("\n------SEGUNDO TURNO----\n");
        printf("candidatos: \n");
        for(int i = 0; i < num_candidates; i++){
            if(candidates[i].votes == max_votes){
                printf("%s\n", candidates[i].name);

            }
        }

    }
    else{
        printf("\n-------- GANHADOR------\n ");
        printf("Winner: ");
        for(int i = 0; i < num_candidates; i++){
            if(candidates[i].votes == max_votes) {
                printf("%s\n", candidates[i].name);
            }
        }
    }



}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <candidate1> <candidate2> <candidate3> ...\n", argv[0]);
        return 1;
    }

    int num_candidates = argc - 1;
    candidates_t candidates[num_candidates];

    for (int i = 0; i < num_candidates; i++) {
        strcpy(candidates[i].name, argv[i + 1]);
        candidates[i].votes = 0;
    }

    printf("\nCandidates:\n");
    for (int i = 0; i < num_candidates; i++) {
        printf("%d. %s\n", i + 1, candidates[i].name);
    }




    int amount = get_int("Number of voters: ");
    for(int i = 0; i < amount; i++){
         printf("\nVote: ");
         char name[50];
         scanf("%s", name);
         vote(candidates, num_candidates, name);
    }

    printf("\nVote registered successfully!\n");


    print_winner(candidates, num_candidates);


    return 0;
}
