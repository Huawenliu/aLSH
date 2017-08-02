#ifndef LSH_MIPS_SRC_CPP_LSH_WRAPER_H
#define LSH_MIPS_SRC_CPP_LSH_WRAPER_H

#include <vector>
#include <map>
#include "lsh.h"

enum LshType {
	L2_LSH = 0,
	CONSINE_LSH
};

typedef float (*hash_func)(const VectorXd &vec);
typedef double (*metric_func)(const VectorXd &u, const VectorXd &v);

//typedef struct buckets { //footprint是多个hash函数的hash值合并结果，indexs是该合并hash值对应的节点索引
//	string footprint;
//	vector<long> indexs;
//} buckets;

class LshWrapper {
public:
	LshWrapper();
	~LshWrapper();
	int init(LshType tpye, int d, float r, int k, int L);

	int resize(int L);

	int create_hash();

	std::string hash(const std::vector<Hash *> &hash_vec, const VectorXd &data);

	int index(const MatrixXd &datas);

	VectorXd query(const VectorXd &q, metric_func megtric, int max_result = 1);

	double get_avg_touched();

private:
	LshType type_;
	int d_;
	float r_;
	int k_;
	int L_;
	std::vector<std::vector<Hash *> > hashes_func_;
	std::vector<std::multimap<string, long> *> hash_map_;   

	float tot_touched_;
	int num_queries_;

	MatrixXd datas;
};

#endif
