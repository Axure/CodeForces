#include <stdio.h>

typedef struct card {
  int attack, heal;
} card;

//typedef struct node {
//  card* p_card;
//  struct node * p_next;
//} node;

int main(int argc, char *argv[]) {

  int T;
  scanf("%d", &T);
  for (int i = 0; i < T; ++i) {

    /**
     * N is the initial number of cards.
     * M is the number of rounds.
     * K is the critical index.
     */
    int N, M, K;
    card cards[7];

    scanf("%d %d %d", &N, &M, &K);
    getchar();

    int a, b;
    for (int j = 0; j < N; ++j) {
      scanf("[%d,%d]", &a, &b);

      cards[j].attack = a;
      cards[j].heal = b;
    }

    int current_number_of_zhuaghan = 0;
    int current_index_of_critical = K - 1;
    int current_number_of_cards = N;
    int critical_has_died = 0;

    for (int j = 0; j < M; ++j) {
      /**
       * Summon and increase the attacks.
       * Rearrange the array.
       */
      for (int k = 1; k <= current_number_of_zhuaghan; ++k) {
        cards[current_index_of_critical + k].attack += 2;
      }

//      printf("Current number of cards %d.\n", current_number_of_cards);
      if (current_number_of_cards < 7 && critical_has_died == 0) {
        for (int k = current_number_of_cards; k > current_index_of_critical + 1; --k) {
          cards[k].attack = cards[k - 1].attack;
          cards[k].heal = cards[k - 1].heal;
        }

        cards[current_index_of_critical + 1].attack = 3;
        cards[current_index_of_critical + 1].heal = 5;
        current_number_of_cards += 1;
        current_number_of_zhuaghan += 1;
      }

      int S, x, y;
      /**
       * Read the attacks.
       * Fire the attack.
       */
      scanf("%d", &S);
//      printf("Attacking!\n");
      for (int l = 0; l < S; ++l) {
        scanf("%d %d", &x, &y);
        cards[x - 1].heal -= y;
//        printf("Index %d has received damage %d.\n", x - 1, y);
      }

      card new_cards[7];
      int current_new_index = 0;
      int new_index_of_critical = current_index_of_critical;
      /**
       * Rearrange the array
       */
      for (int m = 0; m < current_number_of_cards; ++m) {
        if (cards[m].heal <= 0) { // If the card dies, don't increase the index, just skip it.
//          printf("%d has died.\n", m);
          if (critical_has_died == 0) {
//            printf("Index of critical is %d.\n", current_index_of_critical);
          }
          if (m < current_index_of_critical) {
            new_index_of_critical -= 1;
          } else {
            if (m == current_index_of_critical) {
              if (critical_has_died == 0) {
                critical_has_died = 1;
              }
            }
            if (m >current_index_of_critical && m <= current_index_of_critical + current_number_of_zhuaghan) {
              current_number_of_zhuaghan -= 1;
            }
          };
        } else {
          new_cards[current_new_index].attack = cards[m].attack;
          new_cards[current_new_index].heal = cards[m].heal;
          current_new_index += 1;
        }
//        printf("Current number of zhuanghan %d.\n", current_number_of_zhuaghan);
      }
      current_number_of_cards = current_new_index;
      current_index_of_critical = new_index_of_critical;
      for (int n = 0; n < current_number_of_cards; ++n) {
        cards[n].attack = new_cards[n].attack;
        cards[n].heal = new_cards[n].heal;
      }
      for (int m = 0; m < current_number_of_cards; ++m) {
//        printf("[%d,%d]", cards[m].attack, cards[m].heal);
      }
//      printf("\n");

    }
    /**
     * Output the result.
     */
    printf("%d\n", current_number_of_cards);
    for (int m = 0; m < current_number_of_cards; ++m) {
      printf("[%d,%d]", cards[m].attack, cards[m].heal);
    }
    printf("\n");

  }

  return 0;
}