#ifndef SRC_SKELETON_SERVICES_IMPL_WALLETSERVICEIMPL_H_
#define SRC_SKELETON_SERVICES_IMPL_WALLETSERVICEIMPL_H_
#include <uuid/uuid.h>

#include <string>

#include "Skeleton/services/WalletService.h"

class WalletServiceImpl : public WalletService {
 public:
  std::string createNewWallet(const Currency& currency,
                              const std::string& walletType) override {
    return "";
  }
  std::string getMyWallets() override { return ""; }
  std::string deposit(const uuid_t& walletId, const double amount) override {
    return "";
  }
  std::string transfer(const uuid_t& walletId,
                       const std::string& receiverUserName,
                       const double amount) override {
    return "";
  }
  std::string changeWalletStatus(const std::string& walletId,
                                 const std::string& newStatus) override {
    return "";
  }
  virtual ~WalletServiceImpl() = delete;
};
#endif  // SRC_SKELETON_SERVICES_IMPL_WALLETSERVICEIMPL_H_
