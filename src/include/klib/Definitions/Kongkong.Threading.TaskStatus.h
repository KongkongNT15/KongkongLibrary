#ifndef KONGKONG_THREADING_TASK_STATUS_H
#define KONGKONG_THREADING_TASK_STATUS_H

#include "Base.h"

namespace KONGKONG_NAMESPACE::Threading
{
    enum struct TaskStatus {
        Canceled,  //使われていないよ！
        Completed, //
        Faulted,   //
        Running,   //
        Waiting,   //使われていないよ！
    };
}

#endif //!KONGKONG_THREADING_TASK_STATUS_H
