#include "classroom.h"
#include <cassert>
#include <cstdio>
#include <cstdlib>

int main() {
  int T;
  assert(1 == scanf("%d", &T));

  for (int t = 0; t < T; ++t) {
    int N, M;
    assert(2 == scanf("%d%d", &N, &M));

    std::vector<int> Q(N);
    for (int i = 0; i < N; ++i) {
      assert(1 == scanf("%d", &Q[i]));
    }

    std::vector<int> P(N);
    for (int i = 0; i < N; ++i) {
      assert(1 == scanf("%d", &P[i]));
    }

    std::vector<std::vector<int>> A(N, std::vector<int>());
    int C = 0;
    for (int R = 0; R < M; ++R) {
      std::vector<int> T;
      for (int i = 0; i < N; ++i) {
        if (Q[i] == R) {
          T.push_back(i);
        }
      }

      std::vector<std::vector<int>> B = process_step(N, M, R, T, A);
      int K = (int)B.size();
      std::vector<int> L(K);
      for (int i = 0; i < K; ++i) {
        L[i] = (int)B[i].size();
        C = std::max(C, L[i]);
      }

      printf("%d\n", K);
      for (int i = 0; i < K; ++i) {
        printf("%d", L[i]);
        for (int j = 0; j < L[i]; ++j) {
          printf(" %d", B[i][j]);
        }
        printf("\n");
      }
      printf("\n");

      assert(K == (int)P.size());

      for (int i = 0; i < N; ++i) {
        A[P[i]] = B[i];
      }
    }

    std::vector<int> D = determine_steps(N, M, A);
    int H = (int)D.size();

    printf("%d %d\n", C, H);
    for (int i = 0; i < H; ++i) {
      printf("%d%c", D[i], " \n"[i == H - 1]);
    }
  }
  fclose(stdout);

  return 0;
}
