#include "lsh_tester.h"
#include <iostream>

void lsh_test(MatrixXd datas, MatrixXd queries, int rand_num, int num_neighbours, mips = False) {
	/*
	type = 'l2'
    tester = LshTesterFactory.createTester(type, mips, datas, queries, rand_num, num_neighbours)
    args = {
                'type':      type,
                'k_vec':     [1, 2, 4, 8],
                #'k_vec':    [2],
                'l_vec':     [2, 4, 8, 16, 32]
                #'l_vec':    [3]
            }
    tester.run(**args)

    type = 'cosine'
    tester = LshTesterFactory.createTester(type, mips, datas, queries, rand_num, num_neighbours)

    args = {
                'type':      type,
                'k_vec':    [1, 2, 4, 8],
                #'k_vec':     [2],
                'l_vec':    [2, 4, 8, 16, 32]
                #'l_vec':     [3]
            }
    tester.run(**args)
	 */
	
	string type = "simple";
    LshTester *tester = LshTesterFactory::createTester(type, mips, datas, queries, rand_num, num_neighbours);

    //'k_vec': [2], 'l_vec': [3]
    vector<int> k_vec = {1, 2, 4, 8}, l_vec = {2, 4, 8, 16, 32};
    tester->run(type, k_vec, l_vec);
}

int main(int argc, char ** argv) {
	/*
	srand((unsigned int) time(0));
	ConsineLsh lsh;
	int d = 10;
	VectorXd vec = VectorXd::Random(d);
	std::cout << vec << std::endl << std::endl;
	lsh.init(0, d);
	std::cout << "hash: " << lsh.hash(vec) << std::endl;

	L2Lsh l2lsh;
	float r = 0.8;
	l2lsh.init(r, d);
	std::cout << "l2lsh: " << l2lsh.hash(vec) << std::endl;
	*/

	// create a test dataset of vectors of non-negative integers
    int num_neighbours = 1;
    double radius = 0.3;
    int r_range = 10 * radius;

    int d = 100;
    int xmin = 0;
    int xmax = 10;
    int num_datas = 1000;
    int num_queries = num_datas / 10;
    datas = [[random.randint(xmin, xmax) for i in xrange(d)] for j in xrange(num_datas)]
    

    /*
    queries = []
    for point in datas[:num_queries]:
        queries.append([x + random.uniform(-radius, radius) for x in point])
    */

    //lsh_test(datas, queries, r_range, num_neighbours)

    // MIPS
    lsh_test(datas, queries, r_range, num_neighbours, true);

	return 0;
}
