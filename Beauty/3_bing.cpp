#include <iostream>
#include <assert.h>
using namespace std;
class CPrefixSorting{
public:
	//���캯��
	CPrefixSorting(){
		m_nCakeCnt = 0;
		m_nMaxSwap = 0;
	}
	//��������
	~CPrefixSorting(){
		if (m_CakeArray != NULL)
			delete m_CakeArray;
		if (m_SwapArray != NULL)
			delete m_SwapArray;
		if (m_ReverseCakeArray != NULL)
			delete m_ReverseCakeArray;
		if (m_ReverseCakeArraySwap != NULL)
			delete m_ReverseCakeArraySwap;
	}

	// �����ӱ���ת��Ϣ
	// @param
	// pCakeArray	�洢�ӱ���������
	// nCakeCnt		�ӱ�����
	void Run(int * pCakeArray, int nCakeCnt){
		Init(pCakeArray, nCakeCnt);
		m_nSearch = 0;
		Search(0);
	}

	//����ӱ����巭ת�Ĵ���
	void Output(){
		for (int i = 0; i<m_nMaxSwap; i++)
			cout << m_SwapArray[i] << " ";

		cout << "Search Time | :" << m_nSearch << endl;
		cout << "Total Swap time:" << m_nMaxSwap << endl;

	}
private:
	void Init(int* pCakeArray, int nCakeCnt){
		assert(pCakeArray != NULL);
		assert(nCakeCnt>0);
		m_nCakeCnt = nCakeCnt;
		m_CakeArray = new int[m_nCakeCnt + 1];
		assert(m_CakeArray != NULL);
		for (int i = 0; i<m_nCakeCnt; i++)
			m_CakeArray[i] = pCakeArray[i];
		m_nMaxSwap = UpperBound(m_nCakeCnt);
		m_SwapArray = new int[m_nMaxSwap + 1];
		assert(m_SwapArray != NULL);

		m_ReverseCakeArray = new int[m_nCakeCnt + 1];
		for (int i = 0; i<m_nCakeCnt; i++)
			m_ReverseCakeArray[i] = m_CakeArray[i];
		m_ReverseCakeArraySwap = new int[m_nMaxSwap + 1];

	}
	// Ѱ�ҵ�ǰ��ת���Ͻ�
	int UpperBound(int nCakeCnt){
		return 2 * nCakeCnt;
	}

	// Ѱ���½�
	int LowerBound(int* pCakeArray, int nCakeCnt){
		int t, ret = 0;
		for (int i = 1; i<nCakeCnt; i++){
			t = pCakeArray[i] - pCakeArray[i - 1];
			if ((t == 1) || (t == -1))
				continue;
			ret++;
		}
		return ret;
	}

	void Search(int step){
		int i, nEstimate;
		m_nSearch++;

		nEstimate = LowerBound(m_ReverseCakeArray, m_nCakeCnt);
		if (step + nEstimate>m_nMaxSwap)
			return;
		if (IsSorted(m_ReverseCakeArray, m_nCakeCnt)){
			if (step<m_nMaxSwap){
				m_nMaxSwap = step;
				for (i = 0; i<m_nMaxSwap; i++)
					m_SwapArray[i] = m_ReverseCakeArraySwap[i];
			}
			return;
		}

		// �ݹ���з�ת
		for (i = 1; i<m_nCakeCnt; i++){
			Reverse(0, i);
			m_ReverseCakeArraySwap[step] = i;
			Search(step + 1);
			Reverse(0, i);
		}
	}

	bool IsSorted(int* pCakeArray, int nCakeCnt){
		for (int i = 1; i<nCakeCnt; i++)
			if (pCakeArray[i - 1]>pCakeArray[i])
				return false;
		return true;
	}

	void Reverse(int nBegin, int nEnd){
		assert(nEnd>nBegin);
		int i, j, t;
		for (i = nBegin, j = nEnd; i<j; i++, j--){
			t = m_ReverseCakeArray[i];
			m_ReverseCakeArray[i] = m_ReverseCakeArray[j];
			m_ReverseCakeArray[j] = t;
		}
	}

private:
	int* m_CakeArray;
	int m_nCakeCnt;
	int m_nMaxSwap;
	int* m_SwapArray;
	int* m_ReverseCakeArray;
	int* m_ReverseCakeArraySwap;
	int m_nSearch;
};

int main(){
	CPrefixSorting test;
	int a[] = { 3, 2, 1, 6, 5, 4, 9, 8, 7, 0 };
	test.Run(a, 10);
	test.Output();
	return 0;
}