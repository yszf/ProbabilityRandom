#include "round_table.h"
#include <ctime>

#include <vector>

using namespace std;

int main() {
	vector<pair<UINT32, UINT32>> key_rate;
	key_rate.emplace_back(make_pair(1, 100));
	key_rate.emplace_back(make_pair(2, 200));	
	key_rate.emplace_back(make_pair(3, 300));
	key_rate.emplace_back(make_pair(4, 400));
	key_rate.emplace_back(make_pair(5, 500));

	CRoundTable crt;
	for (const auto& elem : key_rate) {
		crt.AddNode(elem.first, elem.second);
	}
	
	for (size_t i = 0; i < 100; ++i) {
		UINT32 key = crt.Roll();
		cout << "index = " << i << ", get random key = " << key << endl;
	}

	return 0;
}