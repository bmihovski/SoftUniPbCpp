#ifndef SRC_ENTITIES_REPOSITORIES_REPOSITORY_H_
#define SRC_ENTITIES_REPOSITORIES_REPOSITORY_H_

#include <memory>
#include <optional>
#include <string>
#include <vector>

template <typename T>
class Repository
{
public:
    virtual ~Repository()                                           = default;
    virtual void              Add(std::unique_ptr<T> destination)   = 0;
    virtual std::vector<T*>   GetCollection() const                 = 0;
    virtual bool              Remove(const T& destination)          = 0;
    virtual std::optional<T*> ByName(const std::string& name) const = 0;
};

#endif // SRC_ENTITIES_REPOSITORIES_REPOSITORY_H_
