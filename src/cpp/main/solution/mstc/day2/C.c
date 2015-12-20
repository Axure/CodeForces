#include <stdio.h>

int main(int argc, char *argv[]) {
  const int N = 22;
  int T;
  double Z_1, A_1, B_1;
  double Z_2, A_2, B_2;
  scanf ("%d", &T);
  getchar();
  int animtation_1, dvd_1, garage_kit_1, console_1, book_1;
  int animtation_2, dvd_2, garage_kit_2, console_2, book_2;

  for (int i = 0; i < T; ++i) {
    scanf("%d %d %d %d %d", &animtation_1, &dvd_1, &garage_kit_1, &console_1, &book_1);
    scanf("%d %d %d %d %d", &animtation_2, &dvd_2, &garage_kit_2, &console_2, &book_2);

    A_1 = animtation_1 + dvd_1 + garage_kit_1 + console_1;
    B_1 = book_1/10.0;
    Z_1 = (A_1 + B_1) / N;

    A_2 = animtation_2 + dvd_2 + garage_kit_2 + console_2;
    B_2 = book_2/10.0;
    Z_2 = (A_2 + B_2) / N;

//    printf("1: %lf, %lf, %lf, 2: %lf, %lf, %lf\n", A_1, B_1, Z_1, A_2, B_2, Z_2);
    if (Z_1 <= 1 && Z_2 <= 1) {
      printf("NiMenZheXieXianChong!\n");
    } else {
      if (Z_1 > Z_2) {
        printf("MiaoMiaoMiao!\n");
      } else if (Z_1 < Z_2) {
        printf("WangWangWang!\n");
      } else {
        printf("MaiMaiMai!\n");
      }
    }
  }


  return 0;
}