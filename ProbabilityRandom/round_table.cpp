#include "round_table.h"
#include "math_func.h"
#include <ctime>

CRoundTable::CRoundTable() {
	total_rate_ = 0;
	node_count_ = 0;
	default_key_ = 0;
	memset(&nodes_, 0, sizeof(nodes_));
	srand((UINT32)time(nullptr));
}

void CRoundTable::Init(INT32 default_key) {
	total_rate_ = 0;
	node_count_ = 0;
	default_key_ = default_key;
	memset(&nodes_, 0, sizeof(nodes_));
	srand((UINT32)time(nullptr));
}

BOOL CRoundTable::AddNode(INT32 key, INT32 rate) {
	if (MAX_TABLE_NODES <= node_count_ || 0 >= rate) {
		return FALSE;
	}

	nodes_[node_count_].node_key = key;
	nodes_[node_count_].min = total_rate_;
	nodes_[node_count_].max = total_rate_ + rate - 1;

	total_rate_ += rate;
	node_count_++;

	return TRUE;
}

INT32 CRoundTable::Roll() {
//	INT32 rand = Random(total_rate_);
	INT32 rand = GetRandom<INT32>(0, total_rate_);
	for (INT32 i = 0; i < node_count_; ++i) {
		if (rand >= nodes_[i].min && rand <= nodes_[i].max) {
			return nodes_[i].node_key;
		}
	}
	return default_key_;
}