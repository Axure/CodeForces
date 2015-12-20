#include <iostream>

using namespace std;
/**
 * 1 9 J 111 P 110 C 101 Q 100 Z 011 A 010 X 001 B 0001 W 0000 10000010000011111001110101010001
 * 1 9 I 111 K 110 H 101 R 100 A 011 X 010 Y 001 C 0001 T 0000 00010111011000000001111010110001
 */
class node {
 private:
 public:
  char value;
  node * p_left, * p_right;

  node() {
    this->value = 0;
    this->p_left = NULL;
    this->p_right = NULL;
  }

  node(char value_) {
    this->value = value_;
    this->p_left = NULL;
    this->p_right = NULL;
  }
};

int main(int argc, char *argv[]) {

  int T, N;
  string S; int S_length;
  char C;
  string input;
  int input_length;

  cin >> T;
  /**
   * Starts a loop.
   */
  for (int i = 0; i < T; ++i) {
    cin >> N;
    node root;
    root.p_left = NULL; root.p_right = NULL;

    /**
     * Read all the data.
     * Build the tree.
     */
    for (int j = 0; j < N; ++j) {
      cin >> C >> S;

      /**
       * Build the nodes.
       */
      node *p_current = &root;
      S_length = S.length();
      /**
       * Iterate through each position of an encoding.
       */
      for (int k = 0; k < S_length; ++k) {
        if (S.at(k) == '0') { // If it starts with 0, go left.
          if (p_current->p_left == NULL) { // If its left does not exist, create it.
            p_current->p_left = new node();
          }
          p_current = p_current->p_left;
        } else { // Else it starts with 1, so go right.
          if (p_current->p_right == NULL) { // If its right does not exist, create it.
            p_current->p_right = new node();
          }
          p_current = p_current->p_right;
        }
      }
      p_current->value = C;

    }

    cin >> input;
    input_length = input.length();
    node *p_current = &root;
    /**
     * Iterate through the input.
     */
    for (int k = 0; k <input_length; ++k) {
      if (input.at(k) == '0') { // If it starts with 0, go left.
        if (p_current->p_left == NULL) { // If its left does not exist, create it.
          p_current->p_left = new node();
        }
        p_current = p_current->p_left;
      } else { // Else it starts with 1, so go right.
        if (p_current->p_right == NULL) { // If its right does not exist, create it.
          p_current->p_right = new node();
        }
        p_current = p_current->p_right;
      }
      if (p_current->value != 0) { // If there is a value, output it and go back to the root.
        cout << p_current->value;
        p_current = &root;
      }
    }


  }

  return 0;
}