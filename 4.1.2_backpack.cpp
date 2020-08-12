#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

int min(int a, int b)
{
    if (a <= b)
        return a;
    else
        return b;
}

int main() {
  int n, W, i, u;
  cin >> n >> W;
  vector<int> cost(n);
  vector<int> weight(n);
  vector<double> cw(n);
  for (i = 0; i < n; i++)
  {
      cin >> cost[i] >> weight[i];
      cw[i] = double(cost[i]) / weight[i];
  }
  ///сортировка
  for (int i = 0; i < n; i++)
  {
      int max_ = i;
      for (int u = i + 1; u < n; u++)
      {
        if (cw[u] >= cw[max_])
            max_ = u;
      }
      if (max_ != i)
      {
          int temp;
          temp = cost[i];
          cost[i] = cost[max_];
          cost[max_] = temp;
          temp = weight[i];
          weight[i] = weight[max_];
          weight[max_] = temp;
          double dtemp;
          dtemp = cw[i];
          cw[i] = cw[max_];
          cw[max_] = dtemp;
      }
  }
  ///конец сортировки
  double answ = 0;
  for (i = 0; i < n; i++)
  {
      //printf("--- %d %d %f --- \n", cost[i], weight[i], cw[i]);
      answ += min(W, weight[i]) * cw[i];
      W -= min(W, weight[i]);
      if (W == 0)
      {
          printf("%.3f", answ);
          return 0;
      }

  }
  printf("%.3f", answ);
  return 0;
}
