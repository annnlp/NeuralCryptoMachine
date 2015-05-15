// 本项目的所有运行流程可在程序员记(http://www.progbbs.com/viewforum.php?f=9)查看
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_INPUTVECTOR_H__385942D1_19CD_418E_82A2_D23CDF5346E5__INCLUDED_)
#define AFX_INPUTVECTOR_H__385942D1_19CD_418E_82A2_D23CDF5346E5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CInputVector  
{
public:
	CInputVector(int cInputValues);
	virtual ~CInputVector();

	int operator [](size_t nValue) const;

protected:
	int m_cInputValues;

	std::vector<int> m_viInputValues;

private:
	inline int _RandomBit() const;
};

#endif // !defined(AFX_INPUTVECTOR_H__385942D1_19CD_418E_82A2_D23CDF5346E5__INCLUDED_)
