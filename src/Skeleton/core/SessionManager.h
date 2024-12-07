#ifndef SRC_SKELETON_CORE_SESSIONMANAGER_H__
#define SRC_SKELETON_CORE_SESSIONMANAGER_H__
#include <string>
#include <unordered_map>

template <typename T>
class SessionManager {
 public:
  virtual ~SessionManager() = default;
  virtual T& getActiveSession() = 0;
  virtual void setActiveSession(const T& user) = 0;
  virtual bool hasActiveSession() = 0;
  virtual void terminateActiveSession() = 0;
};

#endif  // SRC_SKELETON_CORE_SESSIONMANAGER_H__
