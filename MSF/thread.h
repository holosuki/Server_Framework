#ifndef __MSF_THREAD_H__
#define __MSF_THREAD_H__

#include <thread>
#include <functional> //用这个写更灵活
#include <memory>
#include <pthread.h>

namespace MSF {
class Thread {
public:
	typedef std::shared_ptr<Thread> ptr;
	Thread(std::function<void()> cb, const std::string& name);
	~Thread();

	pid_t getId() const { return m_id;}
	const std::string& getName() const { return m_name;}

	void join();

	static Thread* GetThis();//获取当前线程
	static const std::string& GetName();//配合写日志，直接获取线程名称
	static void SetName(const std::string& name);
private:
	//以下三行禁止默认拷贝，c++11的写法
	Thread(const Thread&) = delete;
	Thread(const Thread&&) = delete;
	Thread& operator=(const Thread&) = delete;

	static void* run(void* arg);
private:
	pid_t m_id = -1;
	pthread_t m_thread = 0;
	std::function<void()> m_cb;
	std::string m_name;
	//Semaphore m_semaphore;
};

}

#endif
