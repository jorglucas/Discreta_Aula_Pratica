#include <stdio.h>

int euclides(int a, int b, int i, int q[])
{
      if(a % b == 0)
      {
        ++i;
        q[i] = a / b;
        return --i;
      }

      else
      {
        q[i] = a / b;
        euclides(b, a % b, ++i, q);
      }
}

void ordenar(int q[], int st[], int t, int t1, int i)
{
    if(t < 0)
    {
        return;
    }
    else
    {
        st[t1] = q[t];
        ordenar(q, st, --t, ++t1, ++i);
    }
}

int main()
{
  int a,b, k, i = 1;
  scanf("%d %d", &a, &b);
  int q[999];
  int t = euclides(a, b, 0, q);
  int st[t - 1];
  ordenar(q, st, t - 1, 0, 0);
  int val[t];
  val[0] = 1;
  val[1] = st[0];
  for(k = 2; k < t + 1; ++k)
  {
      val[k] = (st[i] * val[i]) + val[i - 1];
      ++i;
  }
  if(i % 2 == 0)
  {
    printf("s = %d\nt = %d\n",val[t - 1] * - 1, val[t]); 
  }
  else
  {
    printf("s = %d\nt = %d\n",val[t - 1], val[t] * - 1);
  }
    return 0;
}