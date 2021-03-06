/*
  Stefano Maggiolo

  Per ogni k < N dal piu` piccolo, controlla se la stringa e`
  periodica di periodo k, creando una nuova stringa e confrontandole.
*/

#include <cstdio>
#include <cassert>

#define MAXN 10000

using namespace std;

int N;
int s[MAXN+1];
int t[MAXN+1];

int
main(void)
{
    FILE * fin, *fout;
#if !defined(EVAL)
    fin = stdin; fout = stdout;
#else
    fin = fopen("input.txt", "r");
    fout = fopen("output.txt", "w");
#endif
    assert(fscanf(fin, "%d", &N) == 1);
    assert(2 <= N && N <= 10000);
    
    for (int i = 0; i < N; ++i)
      {
        assert(fscanf(fin, "%d", s+i) == 1);
        assert(s[i] == 0 || s[i] == 1);
      }

    for (int i = 1; i < N; ++i)
      {
        for (int j = 0; j < N; ++j)
          t[j] = s[j % i];
        bool p = true;
        for (int j = 0; j < N; ++j)
          if (s[j] != t[j])
            p = false;
        if (p == true)
          {
            fprintf(fout, "%d\n", i);
            return 0;
          }
      }
    fprintf(fout, "-1\n");
    return 0;
}
