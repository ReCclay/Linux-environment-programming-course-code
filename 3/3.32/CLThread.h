#ifndef CLTHREAD_H
#define CLTHREAD_H

#include <pthread.h>
#include "CLExecutive.h"
#include "CLStatus.h"
#include "CLEvent.h"

class CLThread : public CLExecutive
{
public:
	explicit CLThread(CLExecutiveFunctionProvider *pExecutiveFunctionProvider);
	CLThread(CLExecutiveFunctionProvider *pExecutiveFunctionProvider, bool bWaitForDeath);
	virtual ~CLThread();

	virtual CLStatus Run(void *pContext = 0);

	virtual CLStatus WaitForDeath();

private:
	static void* StartFunctionOfThread(void *pContext);

private:
	void *m_pContext;
	pthread_t m_ThreadID; 

	bool m_bThreadCreated;
	bool m_bWaitForDeath;

	CLEvent m_EventForWaitingForNewThread;
	CLEvent m_EventForWaitingForOldThread;
};

#endif
