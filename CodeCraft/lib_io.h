#pragma once

#define MAX_EDGE_NUM    (2000 * 20)

//��ȡ�ļ������������buff��
//buffΪһ��ָ�����飬ÿһ��Ԫ����һ���ַ�ָ�룬��Ӧ�ļ���һ�е����ݡ�
//specΪ������������������
int read_file(char ** const buff, const unsigned int spec, const char * const filename);

//��result�������е�����д���ļ���д�뷽ʽΪ����д��
void write_result(const char * const buff, const char * const filename);

//�ͷŶ��ļ��Ļ�����
void release_buff(char ** const buff, const int valid_item_num);