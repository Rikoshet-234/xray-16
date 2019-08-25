#pragma once

#include "xrCore/Threading/TaskManager.hpp"

class IGameFont;
class IPerformanceAlert;

class TaskManager : public TaskManagerBase
{
    Lock statisticsLock;
    std::atomic<u32> spawnedTasks;
    xr_vector<float> statistics;

    void SpawnTask(Task* task, bool shortcut = false) override;
    void TaskDone(Task* task, u64 executionTime) override;

public:
    void DumpStatistics(class IGameFont& font, class IPerformanceAlert* alert) override;
};
