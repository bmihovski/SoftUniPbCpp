#ifndef SRC_SKELETON_CORE_IMPL_SESSIONMANAGERIMPL_H_
#define SRC_SKELETON_CORE_IMPL_SESSIONMANAGERIMPL_H_
#include "Skeleton/core/SessionManager.h"
#include "Skeleton/entities/user/User.h"

template <typename T>
class SessionManagerImpl : public SessionManager<T> {
 private:
  T activeSession;

 public:
  SessionManagerImpl() { this->activeSession = nullptr; }
  ~SessionManagerImpl() = default;
  T& getActiveSession() override { return this->activeSession; }
  void setActiveSession(const T& user) override { this->activeSession = user; }
  bool hasActiveSession() override { return this->activeSession != nullptr; }
  void terminateActiveSession() override { this->activeSession = nullptr; }
};

extern template class SessionManagerImpl<User>;
#endif  // SRC_SKELETON_CORE_IMPL_SESSIONMANAGERIMPL_H_
