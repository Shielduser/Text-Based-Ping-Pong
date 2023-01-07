#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN_POWER 1
#define MAX_POWER 10

int main(void) {
  int player1_score = 0, player2_score = 0;
  char ball_direction = 'L';  // L for left, R for right
  int ball_power;
  int player_choice;

  srand(time(NULL));  // Seed the random number generator

  // The game continues until one player reaches 21 points
  while (player1_score < 21 && player2_score < 21) {
    printf("Player 1 score: %d   Player 2 score: %d\n", player1_score, player2_score);
    printf("%c turn to serve\n", (ball_direction == 'L' ? 'R' : 'L'));

    // Generate a random ball power between MIN_POWER and MAX_POWER
    ball_power = MIN_POWER + rand() % (MAX_POWER - MIN_POWER + 1);
    printf("Ball power: %d\n", ball_power);

    if (ball_direction == 'L') {
      // Player 1 serves
      printf("Player 1, enter your choice (0 for normal serve, 1 for power serve): ");
      scanf("%d", &player_choice);

      if (player_choice == 1) {
        ball_power += 3;
        printf("Player 1 served with power!\n");
      }

      if (ball_power > 8) {
        printf("Player 2 failed to hit the ball!\n");
        player1_score++;
      } else {
        ball_direction = 'R';
      }
    } else {
      // Player 2 serves
      printf("Player 2, enter your choice (0 for normal serve, 1 for power serve): ");
      scanf("%d", &player_choice);

      if (player_choice == 1) {
        ball_power += 3;
        printf("Player 2 served with power!\n");
      }

      if (ball_power > 8) {
        printf("Player 1 failed to hit the ball!\n");
        player2_score++;
      } else {
        ball_direction = 'L';
      }
    }
  }

  // Display the final scores
  printf("\nPlayer 1 score: %d   Player 2 score: %d\n", player1_score, player2_score);
  if (player1_score > player2_score) {
    printf("Player 1 wins!\n");
  } else {
    printf("Player 2 wins!\n");
  }

  return 0;
}

