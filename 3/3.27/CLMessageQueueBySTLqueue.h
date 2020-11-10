 #ifndef CLMessageQueueBySTLqueue_H
#define CLMessageQueueBySTLqueue_H

#include <queue>
#include "CLStatus.h"
#include "CLMutex.h"
#include "CLEvent.h"

class CLMessage;

class CLMessageQueueBySTLqueue
{
public:

	CLMessageQueueBySTLqueue();
	virtual ~CLMessageQueueBySTLqueue();

public:
	CLStatus PushMessage(CLMessage * pMessage);
	CLMessage* GetMessage();

private:
	CLStatus Push(CLMessage * pMessage);
	CLMessage* Pop();

private:
	CLMessageQueueBySTLqueue(const CLMessageQueueBySTLqueue&);
	CLMessageQueueBySTLqueue& operator=(const CLMessageQueueBySTLqueue&);

private:
	std::queue<CLMessage*> m_MessageQueue; //队列消息放到了容器里
	CLMutex m_Mutex; //互斥	
	CLEvent m_Event; //同步
};

#endif