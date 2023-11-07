#pragma once
#include <vector>
#include <queue>
#include <memory>
#include <atomic>
#include <mutex>
#include <condition_variable>
enum class PoolMode
{
	MODE_FIXED,
	MODE_CACHE,
};
class Task {
public:
	virtual void run() = 0;
};
class Thread {
public:
private:

};
class ThreadPool {
public:
private:
	std::vector<Thread*> threads_;
	size_t initThreadSize_;

	std::queue<std::shared_ptr<Task>> taskQue_;
	std::atomic_int taskSize_;//任务数量
	int taskQueMaxThreshHold_;//任务阈值

	std::mutex taskQueMtx_;
	std::condition_variable notFall_;
	std::condition_variable notEmpty_;
};