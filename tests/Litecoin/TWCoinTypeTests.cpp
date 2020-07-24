// Copyright © 2017-2020 Trust Wallet.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.
//
// This is a GENERATED FILE, changes made here MAY BE LOST.
// Generated one-time (codegen/bin/cointests)
//

#include "../interface/TWTestUtilities.h"
#include <PPTrustWalletCore/TWCoinTypeConfiguration.h>
#include <gtest/gtest.h>


TEST(TWLitecoinCoinType, TWCoinType) {
    auto symbol = WRAPS(TWCoinTypeConfigurationGetSymbol(TWCoinTypeLitecoin44));
    auto txId = TWStringCreateWithUTF8Bytes("t123");
    auto txUrl = WRAPS(TWCoinTypeConfigurationGetTransactionURL(TWCoinTypeLitecoin44, txId));
    auto accId = TWStringCreateWithUTF8Bytes("a12");
    auto accUrl = WRAPS(TWCoinTypeConfigurationGetAccountURL(TWCoinTypeLitecoin44, accId));
    auto id = WRAPS(TWCoinTypeConfigurationGetID(TWCoinTypeLitecoin44));
    auto name = WRAPS(TWCoinTypeConfigurationGetName(TWCoinTypeLitecoin44));

    ASSERT_EQ(TWCoinTypeConfigurationGetDecimals(TWCoinTypeLitecoin44), 8);
    ASSERT_EQ(TWBlockchainBitcoin, TWCoinTypeBlockchain(TWCoinTypeLitecoin44));
    ASSERT_EQ(0x32, TWCoinTypeP2shPrefix(TWCoinTypeLitecoin44));
    ASSERT_EQ(0x0, TWCoinTypeStaticPrefix(TWCoinTypeLitecoin44));
    assertStringsEqual(symbol, "LTC");
    assertStringsEqual(txUrl, "https://blockchair.com/litecoin/transaction/t123");
    assertStringsEqual(accUrl, "https://blockchair.com/litecoin/address/a12");
    assertStringsEqual(id, "litecoin44");
    assertStringsEqual(name, "Litecoin44");
}
