#ifndef __MATH_FUNC_H_2021_2_7__
#define __MATH_FUNC_H_2021_2_7__

#include <cstdlib>
#include "common_type.h"
#include <random>
#include <ctime>

UINT32 Random(UINT32 range) {
	if (range <= 0) return 0;
	int res = rand();
	return res % range;
}

template<typename T>
T GetRandom(T min, T max) {
	static std::default_random_engine engine(static_cast<UINT32>(time(NULL)));
	if (min < max) {
		std::uniform_int_distribution<T> dis(min, max);
		return dis(engine);
	}
	else {
		std::uniform_int_distribution<T> dis(max, min);
		return dis(engine);
	}
}

template<typename T>
void RandomOrder(std::vector<T>& data) {
	size_t index = 0;
	T temp;
	for (size_t i = 0; i < data.size(); ++i) {
		index = GetRandom<size_t>(0, data.size() - 1);
		if (index < data.size() && index != i) {
			temp = data[i];
			data[i] = data[index];
			data[index] = temp;
		}
	}
}

#endif