//
// Copyright (c) 2014-2022 Simdsoft Limited - All Rights Reserved
//
#ifndef  _ENCRYPTMANAGER_H_
#define  _ENCRYPTMANAGER_H_
#include <string>
#include <stdint.h>
#include <unordered_map>
#include "yasio/cxx17/string_view.hpp"

class FileUtilsEncrypt;

class  EncryptManager final {
    friend class FileUtilsEncrypt;
public:
    enum ENCRYPT_FLAG
    {
        ENCF_NOFLAGS,
        ENCF_COMPRESS,
        ENCF_SIGNATURE = 2,
    };

    struct SignInfo
    {
        uint32_t mask = 0;
        uint32_t sigval = 0;
        union {
            uint8_t  reserved : 6;
            uint8_t  compressed : 2;
            uint8_t flags = 0;
        };
        int32_t original_size = -1;
    };

    static EncryptManager *getInstance();

    /*

    
    */
    
    /// <summary>
    /// Enable encryped filesystem
    /// </summary>
    /// <param name="bVal"></param>
    /// <param name="key"></param>
    /// <param name="ivec"></param>
    /// <param name="flags">The encrypt flags(compress, signature, signature roll), by default x-studio will compress data first before encrypt and 
    /// add encrypt signature for runtime to determine whether a file was encrypted by x-studio</param>
    /// <remarks>
    /// 
    /// </remarks
    void setEncryptEnabled(bool bVal, 
        cxx17::string_view key = "",
        cxx17::string_view ivec = "",
        int flags = ENCF_COMPRESS | ENCF_SIGNATURE | 5 << 16);
    bool isEncryptEnabled(void) const { return _encryptEnabled; }

    std::string decryptData(std::string data);

private:
    bool parseSignInfo(const char* data, size_t len, SignInfo* info) const;
protected:
    void setupHookFuncs();

private:
    bool _encryptEnabled = false;
    int _encryptFlags = ENCF_NOFLAGS;
    std::string _encryptKey;
    std::string _encryptIvec; // required by CBC mode.
    std::string _encryptSignKey;
};

#endif
