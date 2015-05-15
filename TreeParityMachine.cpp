// 本项目的所有运行流程可在程序员记(http://www.progbbs.com/viewforum.php?f=9)查看
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "TreeParityMachine.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CTreeParityMachine::CTreeParityMachine(int cHiddenNeurons, int cInputNeuronsPerHiddenNeuron, int iMaxWeight) :
	m_cHiddenNeurons(cHiddenNeurons),
	m_cInputNeuronsPerHiddenNeuron(cInputNeuronsPerHiddenNeuron),
	m_iMaxWeight(iMaxWeight)
{
	m_cHiddenNeurons = max(4, min(30, m_cHiddenNeurons));
	m_cInputNeuronsPerHiddenNeuron = max(4, min(30, m_cInputNeuronsPerHiddenNeuron));
	m_iMaxWeight = max(3, min(6, m_iMaxWeight));

	m_viHiddenNeurons.resize(m_cHiddenNeurons);
	m_viInputNeurons.resize(m_cHiddenNeurons * m_cInputNeuronsPerHiddenNeuron);

	for( int nInputNeuron = 0; nInputNeuron < m_cHiddenNeurons * m_cInputNeuronsPerHiddenNeuron; nInputNeuron++ )
	{
		m_viInputNeurons[nInputNeuron] = m_iMaxWeight - rand() % (2 * m_iMaxWeight + 1);
	}

}

CTreeParityMachine::~CTreeParityMachine()
{

}

int CTreeParityMachine::operator [](size_t nInputNeuron) const
{
	if( nInputNeuron < m_cHiddenNeurons * m_cInputNeuronsPerHiddenNeuron )
		return m_viInputNeurons[nInputNeuron];
	return 0;
}

int CTreeParityMachine::CountOutput(const CInputVector &InputVector)
{
	int iOutputValue = 1;

	for( int nHiddenNeuron = 0; nHiddenNeuron < m_cHiddenNeurons; nHiddenNeuron++ )
	{
		int iSum = 0;

		for( int nInputNeuron = 0; nInputNeuron < m_cInputNeuronsPerHiddenNeuron; nInputNeuron++ )
			iSum += m_viInputNeurons[nHiddenNeuron * m_cInputNeuronsPerHiddenNeuron + nInputNeuron] *
				InputVector[nHiddenNeuron * m_cInputNeuronsPerHiddenNeuron + nInputNeuron];

		int iOutput = _Segma(iSum);

		m_viHiddenNeurons[nHiddenNeuron] = iOutput;
		iOutputValue *= iOutput;
	}
	return iOutputValue;

}

void CTreeParityMachine::UpdateWeight(const CInputVector &InputVector, int iOutputValue)
{
	for( int nHiddenNeuron = 0; nHiddenNeuron < m_cHiddenNeurons; nHiddenNeuron++ )
	{
		for( int nInputNeuron = 0; nInputNeuron < m_cInputNeuronsPerHiddenNeuron; nInputNeuron++ )
		{
			int iNewWeight = m_viInputNeurons[nHiddenNeuron * m_cInputNeuronsPerHiddenNeuron + nInputNeuron];

			iNewWeight += InputVector[nHiddenNeuron * m_cInputNeuronsPerHiddenNeuron + nInputNeuron] *
				iOutputValue * _Equal(iOutputValue, m_viHiddenNeurons[nHiddenNeuron]) *
				_Equal(iOutputValue, iOutputValue);
			iNewWeight = max(-m_iMaxWeight, min(m_iMaxWeight, iNewWeight));
			m_viInputNeurons[nHiddenNeuron * m_cInputNeuronsPerHiddenNeuron + nInputNeuron] = iNewWeight;
		}
	}

}

inline int CTreeParityMachine::_Segma(int iInput) const
{
	if( iInput > 0 )
		return 1;
	return -1;

}

inline int CTreeParityMachine::_Equal(int i, int j) const
{
	if( i == j )
		return 1;
	return 0;

}
