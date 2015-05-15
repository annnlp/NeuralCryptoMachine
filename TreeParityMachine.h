// 本项目的所有运行流程可在程序员记(http://www.progbbs.com/viewforum.php?f=9)查看
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_TREEPARITYMACHINE_H__404F38FF_E078_4C59_B988_A3CD1F3C62C3__INCLUDED_)
#define AFX_TREEPARITYMACHINE_H__404F38FF_E078_4C59_B988_A3CD1F3C62C3__INCLUDED_

#include "InputVector.h"
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CTreeParityMachine  
{
public:
	CTreeParityMachine(int cHiddenNeurons, int cInputNeuronsPerHiddenNeuron, int iMaxWeight);
	virtual ~CTreeParityMachine();

	int operator [](size_t nInputNeuron) const;

	int CountOutput(const CInputVector& InputVector);
	void UpdateWeight(const CInputVector& InputVector, int iOutputValue);

protected:
	int m_cHiddenNeurons;
	int m_cInputNeuronsPerHiddenNeuron;
	int m_iMaxWeight;
	std::vector<int> m_viHiddenNeurons;
	std::vector<int> m_viInputNeurons;

private:
	inline int _Segma(int iInput) const;
	inline int _Equal(int i, int j) const;
};

#endif // !defined(AFX_TREEPARITYMACHINE_H__404F38FF_E078_4C59_B988_A3CD1F3C62C3__INCLUDED_)
