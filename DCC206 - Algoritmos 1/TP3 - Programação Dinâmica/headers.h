#ifndef HEADERS_H
#define HEADERS_H

#ifdef DEBUG
#define DEBUG_MSG(str)    \
	do {                  \
		std::cout << str; \
	} while (false)
#else
#define DEBUG_MSG(str) \
	do {               \
	} while (false)
#endif

#include <bits/stdc++.h>

#include <algorithm>
#include <cassert>
#include <cmath>
#include <iostream>
#include <limits>
#include <list>
#include <queue>
#include <tuple>
#include <unordered_map>
#include <vector>

using namespace std;

#define INF numeric_limits<int>::max() >> 1

#endif  // HEADERS_H