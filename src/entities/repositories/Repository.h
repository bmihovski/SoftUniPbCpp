#ifndef SRC_ENTITIES_REPOSITORIES_REPOSITORY_H_
#define SRC_ENTITIES_REPOSITORIES_REPOSITORY_H_
#include <vector>
#include <string>

template <typename T>
class Repository
{
public:
    virtual ~Repository()                                         = default;
    virtual void            add(const T& destination)             = 0;
    virtual std::vector<T>& getAll() const                        = 0;
    virtual bool            remove(const T& destination)          = 0;
    virtual T&              byName(const std::string& name) const = 0;
};

#endif // SRC_ENTITIES_REPOSITORIES_REPOSITORY_H_
