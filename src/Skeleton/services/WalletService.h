#ifndef SRC_SKELETON_SERVICES_WALLETSERVICE_H__
#define SRC_SKELETON_SERVICES_WALLETSERVICE_H__
#include <uuid/uuid.h>

#include <string>

#include "../models/Currency.h"
class WalletService {
 public:
  virtual std::string createNewWallet(const Currency& currency,
                                      const std::string& walletType) = 0;
  virtual std::string getMyWallets() = 0;
  virtual std::string deposit(const uuid_t& walletId, const double amount) = 0;
  virtual std::string transfer(const uuid_t& walletId,
                               const std::string& receiverUserName,
                               const double amount) = 0;
  virtual std::string changeWalletStatus(const std::string& walletId,
                                         const std::string& newStatus);
  ~WalletService() = default;
};
#endif  // SRC_SKELETON_SERVICES_WALLETSERVICE_H__
