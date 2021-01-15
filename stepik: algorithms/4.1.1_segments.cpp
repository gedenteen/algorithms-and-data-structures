#include <iostream>
#include <utility>
#include <vector>
#include <bits/stdc++.h>

typedef std::pair <int, int> Segment;

std::vector <int> get_covering_set(std::vector <Segment> segments) {
  std::vector <int> result;

  // fix this function
  int seg_rig = segments[0].second;
  result.push_back(seg_rig);
  for (std::size_t i = 1; i < segments.size(); i++) {
    if (segments[i].first <= seg_rig)
        continue;
    else
    {
        seg_rig = segments[i].second;
        result.push_back(segments[i].second);
    }

  }

  return result;
}

int main(void) {
  int segments_count;
  std::cin >> segments_count; //кол-во точек
  std::vector <Segment> segments(segments_count); //вектор - динамический массив
  for (int i = 0; i < segments_count; i++) {
    std::cin >> segments[i].first >> segments[i].second; //начало и конец отрезка
  }

  //std::cout << "start sort \n";
  for (int i = 0; i < segments_count; i++)
  {
      int min_ = i;
      for (int u = i + 1; u < segments_count; u++)
      {
        if (segments[u].second < segments[min_].second)
            min_ = u;
      }
      if (min_ != i)
      {
          std::pair <int, int> temp;
          temp = segments[i];
          segments[i] = segments[min_];
          segments[min_] = temp;
      }
  }
  /*for (int i = 0; i < segments_count; i++) {
    std::cout << segments[i].first << " " << segments[i].second
        << "\n";
  }
  std::cout << "end sort \n";*/

  std::vector <int> points = get_covering_set(segments);
  std::cout << points.size() << std::endl;
  for (std::size_t i = 0; i < points.size(); i++) {
    std::cout << points[i] << " ";
  }
  std::cout << std::endl;
}
