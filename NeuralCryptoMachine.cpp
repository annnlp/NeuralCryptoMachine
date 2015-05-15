// 本项目的所有运行流程可在程序员记(http://www.progbbs.com/viewforum.php?f=9)查看
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "TreeParityMachine.h"

int main(int argc, char* argv[])
{
	srand(time(NULL));

	char acKeyChars[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ_0123456789";
	CTreeParityMachine TreeParityMachine1(8, 12, 4);
	CTreeParityMachine TreeParityMachine2(8, 12, 4);
	int nMaxTime = (4 * 4 * 4 * 4) * 12 * 8;
	int iSum = 0;

	for( int nTime = 0; nTime < nMaxTime; nTime++ )
	{
		CInputVector InputVector(8 * 12);
		int iOutputValue = TreeParityMachine1.CountOutput(InputVector);

		if( TreeParityMachine2.CountOutput(InputVector) == iOutputValue )
		{
			TreeParityMachine1.UpdateWeight(InputVector, iOutputValue);
			TreeParityMachine2.UpdateWeight(InputVector, iOutputValue);
			iSum = 0;
			for( int nInputNeuron = 0; nInputNeuron < 8 * 12; nInputNeuron++ )
				iSum += abs(TreeParityMachine1[nInputNeuron] - TreeParityMachine2[nInputNeuron]);
			if( iSum == 0 )
				break;
		}
	}
	if( iSum == 0 )
	{
		int iKeySize = strlen(acKeyChars) / (4 * 2 + 1);
		int iKeyLength = 8 * 12 / iKeySize;
		char* pszKey = (char*)malloc(iKeyLength + 1);

		for( int i = 0; i < iKeyLength; i++ )
		{
			int iKeyChar = 1;

			for( int j = i * iKeySize; j < (i + 1) * iKeySize; j++ )
				iKeyChar += TreeParityMachine1[j] + 4;
			pszKey[i] = acKeyChars[iKeyChar];
		}
		pszKey[i] = '\0';
		printf("SUCCESS(%d times) : %s\n", nTime, pszKey);
		free(pszKey);
	}
	else
		printf("FAILED\n");
	return 0;
}
