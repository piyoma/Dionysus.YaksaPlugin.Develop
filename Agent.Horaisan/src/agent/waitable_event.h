#ifndef __WAITABLE_EVENT_H__
#define __WAITABLE_EVENT_H__

#include <condition_variable>
#include <mutex>

namespace Yaksa {

  class WaitableEvent {
  public:

    enum class ResetPolicy {
      kManual,
      kAutomatic,
    };

    enum class InitialState {
      kSignaled,
      kNotSignaled,
    };

    explicit WaitableEvent(
        ResetPolicy reset_policy = ResetPolicy::kManual,
        InitialState initial_state = InitialState::kNotSignaled);
    ~WaitableEvent();

    void Reset();

    void Signal();

    bool IsSignaled();

    void Wait();

  private:
    void ResetLocked();
    bool IsSignaledLocked();

    const ResetPolicy reset_policy_;
    bool is_signaled_;
    std::mutex mutex_;
    std::condition_variable cond_var_;
  };

}  // namespace Yaksa

#endif //__WAITABLE_EVENT_H__