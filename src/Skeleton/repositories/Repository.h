#ifndef SRC_SKELETON_REPOSITORIES_REPOSITORY_H__
#define SRC_SKELETON_REPOSITORIES_REPOSITORY_H__
#include <vector>
template <typename ID, typename T>
class Repository {
 public:
  virtual void save(const ID& id, const T& entity) = 0;
  virtual T& getById(const ID& id) = 0;
  virtual std::vector<T>& getAll() = 0;
  virtual ~Repository() = default;
};
#endif  // SRC_SKELETON_REPOSITORIES_REPOSITORY_H__
