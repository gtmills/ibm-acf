
#include <CeLogin.h>

#include <string>
#include <vector>

#ifndef _CELOGINV1_H
#define _CELOGINV1_H

namespace CeLogin
{
enum ProcessorGeneration
{
    Invalid = 0,
    P10 = 10,
};

struct Machine
{
    std::string mSerialNumber;
    CeLogin::ServiceAuthority mAuth;
    ProcessorGeneration mProc;
};

struct DecodedMachine
{
    std::string mSerialNumber;
    std::string mFrameworkEc;
};

struct CeLoginCreateHsfArgsV1
{
    std::string mSourceFileName;
    std::vector<CeLogin::Machine> mMachines;
    std::string mExpirationDate;
    std::string mRequestId;
    std::vector<uint8_t> mPassword;
    std::vector<uint8_t> mPrivateKey;
};

struct CeLoginDecryptedHsfArgsV1
{
    std::string mProcessingType;
    std::string mSourceFileName;
    std::vector<DecodedMachine> mMachines;
    std::string mExpirationDate;
    std::string mRequestId;
    std::string mPasswordHash;
};

CeLoginRc createCeLoginAcfV1(const CeLoginCreateHsfArgsV1& argsParm,
                             std::vector<uint8_t>& generatedAcfParm);

CeLoginRc
    decodeAndVerifyCeLoginHsfV1(const std::vector<uint8_t>& hsfParm,
                                const std::vector<uint8_t>& publicKeyParm,
                                CeLoginDecryptedHsfArgsV1& decodedHsfParm);

}; // namespace CeLogin

#endif