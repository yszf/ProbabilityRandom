#ifndef __ROUND_TABLE_H_2021_2_7__
#define __ROUND_TABLE_H_2021_2_7__

#include "common_type.h"

#define MAX_TABLE_NODES 512

class CRoundTable {
public:
	CRoundTable();

	void Init(INT32 default_key);

	BOOL AddNode(INT32 key, INT32 rate);

	INT32 Roll();
private:
	struct TableNode {
		INT32 node_key;
		INT32 min;
		INT32 max;
	};

	INT32 total_rate_;
	INT32 default_key_;
	INT32 node_count_;
	TableNode nodes_[MAX_TABLE_NODES];
};


#endif