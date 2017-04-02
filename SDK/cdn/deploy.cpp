#include "deploy.h"
#include "graph.h"
#include "GenerateIntialSolutions.h"
#include "GeneticAlgorithm.h"
#include <stdio.h>

//��Ҫ��ɵĹ��������
void deploy_server(char * topo[MAX_EDGE_NUM], int line_num, char * filename)
{
	timeb startTime;
	ftime(&startTime);
	unsigned int interval_ms(GeneticAlgorithm::SubFun::timeb2ms(startTime));
	Graph graph(topo);
	std::vector<BoolTable> intialSolutions(GenerateIntialSolutions::getIntialSolutions(graph));
	ftime(&startTime);
	interval_ms += GeneticAlgorithm::SubFun::timeb2ms(startTime);
	Solution solution(GeneticAlgorithm::generateSolution(intialSolutions, interval_ms, graph));
	/*Solution solution{ SmallestCostFlow::getSmallestCostFlow(intialSolutions[0], graph) };
	for (unsigned int i(0), j(intialSolutions[0].size()); i != j; ++i)
	{
		if (intialSolutions[0][i])
			solution.servers.push_back(i);
	}*/
	std::string solution_str(solution.to_string(graph));

	// ֱ�ӵ�������ļ��ķ��������ָ���ļ���(ps��ע���ʽ����ȷ�ԣ�����н⣬��һ��ֻ��һ�����ݣ��ڶ���Ϊ�գ������п�ʼ���Ǿ�������ݣ�����֮����һ���ո�ָ���)
	write_result(solution_str.c_str(), filename);
}
