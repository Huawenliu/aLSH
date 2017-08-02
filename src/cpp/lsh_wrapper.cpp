#include "lsh_wrapper.h"

LshWrapper::LshWrapper() {
}

LshWrapper::~LshWrapper() {
}

int LshWrapper::init(LshType type, int d, float r , int k, int L) {
	type_ = type;
	d_ = d;
	r_ = r;
	k_ = k;
	L_ = L;

	create_hash();

	for (int i = 0; i < L; ++i) {
		std::multimap<std::string, long> *m = new std::multimap<std::string, long>();
		hash_map_.push_back(m);
	}

	return 0;
}

int LshWrapper::create_hash() {
	for (int i = 0; i < L_; ++i) {
		std::vector<Hash *> h_vec;
		for (int j = 0; j < k_; ++j) {
			Hash *h = NULL;
			if (type_ == L2_LSH) {
				h = new L2Lsh();
				h->init(r_, d_);
			}
			else {
				h = new ConsineLsh();
				h->init(r_, d_);
			}
			h_vec.push_back(h);
		}
		hashes_func_.push_back(h_vec);
	}
	return 0;
}

int LshWrapper::resize(int L) {
	return 0;
}

std::string LshWrapper::hash(const std::vector<Hash *> &hash_vec, const VectorXd &data) {
  std::vector<float> hash_val;
	int vec_size = hash_vec.size();
	for (int i = 0; i < vec_size; ++i) {
		hash_val.push_back(hash_vec[i]->hash(data));
	}
	return hash_combine(hash_val);
}

int LshWrapper::index(const MatrixXd &datas) {
	this->datas = datas;
	std::vector<std::vector<Hash *> >::const_iterator hash_iter;
	std::vector<std::multimap<std::string, long> * >::const_iterator vec_iter;
	for (hash_iter = hashes_func_.begin(), vec_iter = hash_map_.begin();
			hash_iter != hashes_func_.end() && vec_iter != hash_map_.end();
			vec_iter++, hash_iter++) {
		int row_size = datas.rows();
		for (int i = 0; i < row_size; ++i) {
			std::multimap<std::string, int> *cur_map = *vec_iter;
			cur_map->insert(
											std::pair<std::string, int>(
													this->hash(*hash_iter, datas.row(i)),
													i)
										 );
		}
	}

	tot_touched_ = 0.0;
	num_queries_ = 0;
	return 0;
}

VectorXd LshWrapper::query(const VectorXd &q, metric_func metric, int max_result) {
	VectorXd ret_v(max_result);
	/*
    triple_l = 3 * self.L
    if max_results > triple_l:
        max_results = triple_l
    elif
    */
   
    if (0 == max_results) 
    	max_results = 1;
    // find the max_results closest indexed datas to q according to the supplied metric
    multimap<double,long> candidates;  //double:distance    long:index
	std::vector<std::vector<Hash *> >::const_iterator hash_iter;
	std::vector<std::multimap<std::string, long> * >::const_iterator vec_iter;
	typedef multimap<string, long>::iterator multi_iter;
	pair<multi_iter, multi_iter> iter;
	string footprint_q;
	double distance;
	for (hash_iter = hashes_func_.begin(), vec_iter = hash_map_.begin();
			hash_iter != hashes_func_.end() && vec_iter != hash_map_.end();
			vec_iter++, hash_iter++) {
		footprint_q = this->hash(*hash_iter, q);
		std::multimap<std::string, int> *cur_map = *vec_iter;
		iter = cur_map->equal_range(footprint_q);
		for(multi_iter k = iter.first; k != iter.second; k++) {
			distance = metric(q, datas[k->second]);
			candidates.insert(pair<double,long>(distance,k->second));
     	}  
	}
	// update stats
	tot_touched += candidates.size();
	num_queries += 1;

	for(int i=0, multimap<double,long>::iterator iter=candidates.begin();i<max_result;i++,iter++)
		ret_v(i) = iter->second;
    return ret_v;
}

double LshWrapper::get_avg_touched() {
	return double(tot_touched / self.num_queries);
}