#ifndef HEADERS_H
#define HEADERS_H

#include <algorithm>
#include <iostream>
#include <limits>
#include <list>
#include <tuple>
#include <vector>
#include <queue>

using namespace std;

#define INF numeric_limits<int>::max() >> 1

// fila de prioridade inversamente ordenada
typedef priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> filaPrioridade;

#endif  // HEADERS_H