// Copyright © 2017-2020 Trust Wallet.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#include "../interface/TWTestUtilities.h"
#include "HexCoding.h"
#include "Data.h"
#include <PPTrustWalletCore/TWPrivateKey.h>
#include <PPTrustWalletCore/TWCoinType.h>

#include <gtest/gtest.h>

using namespace TW;

TEST(ZilliqaSignature, Signing) {
    auto keyData = WRAPD(TWDataCreateWithHexString(STRING("0xafeefca74d9a325cf1d6b6911d61a65c32afa8e02bd5e78e2e4ac2910bab45f5").get()));
    auto privateKey = WRAP(TWPrivateKey, TWPrivateKeyCreateWithData(keyData.get()));
    auto pubKey = TWPrivateKeyGetPublicKeySecp256k1(privateKey.get(), true);

    auto message = "hello schnorr";
    auto messageData = WRAPD(TWDataCreateWithBytes((uint8_t *)message, strnlen(message, 13)));
    auto signatureData = WRAPD(TWPrivateKeySignSchnorr(privateKey.get(), messageData.get(), TWCurveSECP256k1));
    auto signature = data(TWDataBytes(signatureData.get()), TWDataSize(signatureData.get()));

    ASSERT_TRUE(TWPublicKeyVerifySchnorr(pubKey, signatureData.get(), messageData.get()));
    EXPECT_EQ(hex(signature), "d166b1ae7892c5ef541461dc12a50214d0681b63d8037cda29a3fe6af8bb973e4ea94624d85bc0010bdc1b38d05198328fae21254adc2bf5feaf2804d54dba55");
}
