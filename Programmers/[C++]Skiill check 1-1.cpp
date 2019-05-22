/*
���� ����
����� ������ ��� ���� ũ�Ⱑ ���� �� ����� ���� ��, ���� ���� ���� ���� ���� ����� �˴ϴ�. 2���� ��� arr1�� arr2�� �Է¹޾�, ��� ������ ����� ��ȯ�ϴ� �Լ�, solution�� �ϼ����ּ���.

���� ����
��� arr1, arr2�� ��� ���� ���̴� 500�� ���� �ʽ��ϴ�


����� ��
arr1	         arr2	        return
[[1,2],[2,3]]	[[3,4],[5,6]]	[[4,6],[7,9]]
[[1],[2]]	      [[3],[4]]	      [[4],[6]]
*/

#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
	for (int i = 0; i<arr1.size(); i++) {
		for (int j = 0; j<arr1[i].size(); j++) {
			arr1[i][j] += arr2[i][j];
		}
	}
	return arr1;
}