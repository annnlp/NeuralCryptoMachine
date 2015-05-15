// 本项目的所有运行流程可在程序员记(http://www.progbbs.com/viewforum.php?f=9)查看
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "InputVector.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CInputVector::CInputVector(int cInputValues) :
	m_cInputValues(cInputValues)
{
	m_cInputValues = max(4 * 4, min(30 * 30, m_cInputValues));

	m_viInputValues.resize(m_cInputValues);

	for( int nInputValue = 0; nInputValue < m_cInputValues; nInputValue++ )
	{
		m_viInputValues[nInputValue] = _RandomBit();
	}

}

CInputVector::~CInputVector()
{

}

int CInputVector::operator [](size_t nValue) const
{
	if( nValue < m_cInputValues )
		return m_viInputValues[nValue];
	return 0;
}

inline int CInputVector::_RandomBit() const
{
	if( rand() % 2 )
		return 1;
	return -1;

}
