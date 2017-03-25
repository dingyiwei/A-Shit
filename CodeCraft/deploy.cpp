#include "deploy.h"
#include "graph.h"
#include "GenerateIntialSolutions.h"
#include "GeneticAlgorithm.h"
#include <stdio.h>

//��Ҫ��ɵĹ��������
void deploy_server(char * topo[MAX_EDGE_NUM], int line_num, char * filename)
{
	Graph graph(topo);
	std::vector<BoolTable> intialSolutions(GenerateIntialSolutions::getIntialSolutions(graph));
	Solution solution(GeneticAlgorithm::generateSolution(std::move(intialSolutions), graph));
	std::string solution_str(solution.to_string());

	// ֱ�ӵ�������ļ��ķ��������ָ���ļ���(ps��ע���ʽ����ȷ�ԣ�����н⣬��һ��ֻ��һ�����ݣ��ڶ���Ϊ�գ������п�ʼ���Ǿ�������ݣ�����֮����һ���ո�ָ���)
	write_result(solution_str.c_str(), filename);
}