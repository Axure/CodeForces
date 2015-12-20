#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
 * 1 9 J 111 P 110 C 101 Q 100 Z 011 A 010 X 001 B 0001 W 0000 10000010000011111001110101010001
 * 1 9 I 111 K 110 H 101 R 100 A 011 X 010 Y 001 C 0001 T 0000 00010111011000000001111010110001
 */
typedef struct node {
  char value;
  struct node * p_left, * p_right;
} node;

int main(int argc, char *argv[]) {

  int T, N;
  char S[10]; int S_length;
  char C;
  char input[1000];
  int input_length;

  scanf("%d", &T);
  getchar();
  /**
   * Starts a loop.
   */
  for (int i = 0; i < T; ++i) {
    scanf("%d", &N);
    getchar();
    node root;
    root.p_left = NULL; root.p_right = NULL;

    /**
     * Read all the data.
     * Build the tree.
     */
    for (int j = 0; j < N; ++j) {
      scanf("%c %s", &C, S);
      getchar();

      /**
       * Build the nodes.
       */
      node *p_current = &root;
      S_length = strlen(S);
      /**
       * Iterate through each position of an encoding.
       */
      for (int k = 0; k < S_length; ++k) {
        if (S[k] == '0') { // If it starts with 0, go left.
          if (p_current->p_left == NULL) { // If its left does not exist, create it.
            p_current->p_left = (node*)malloc(sizeof(node));
            p_current->p_left->p_left = NULL;
            p_current->p_left->p_right = NULL;
          }
          p_current = p_current->p_left;
        } else { // Else it starts with 1, so go right.
          if (p_current->p_right == NULL) { // If its right does not exist, create it.
            p_current->p_right = (node*)malloc(sizeof(node));
            p_current->p_right->p_left = NULL;
            p_current->p_right->p_right = NULL;
          }
          p_current = p_current->p_right;
        }
      }
      p_current->value = C;
    }

    scanf("%s", input);
    getchar();
    input_length = strlen(input);
    node *p_current = &root;
    /**
     * Iterate through the input.
     */
    for (int k = 0; k <input_length; ++k) {
      if (input[k] == '0') { // If it starts with 0, go left.
        p_current = p_current->p_left;
      } else { // Else it starts with 1, so go right.
        p_current = p_current->p_right;
      }
      if (p_current->value != 0) { // If there is a value, output it and go back to the root.
        printf("%c", p_current->value);
        p_current = &root;
      }
    }
    printf("\n");


  }

  return 0;
}