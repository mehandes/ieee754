#include <gtest/gtest.h>
#include <math.h>

extern "C"
{
#include <fpc.h>
}

TEST(Hex2Dec, Nan)
{
    ULL n;

    EXPECT_TRUE(isnan(*dp_hex2dec(&(n = 0xFFFFFFFFFFFFFFFF))));
    EXPECT_TRUE(isnan(*dp_hex2dec(&(n = 0xFFF0000000000001))));
    EXPECT_TRUE(isnan(*dp_hex2dec(&(n = 0x7FF0000000000001))));
    EXPECT_TRUE(isnan(*dp_hex2dec(&(n = 0x7FFFFFFFFFFFFFFF))));
}

TEST(Hex2Dec, Inf)
{
    ULL n;

    EXPECT_TRUE(isinf(*dp_hex2dec(&(n = 0xFFF0000000000000))));
    EXPECT_TRUE(isinf(*dp_hex2dec(&(n = 0x7FF0000000000000))));
}

TEST(Hex2Dec, Normalized)
{
    ULL n;

    EXPECT_DOUBLE_EQ(*dp_hex2dec(&(n = 0xFFEFFFFFFFFFFFFF)), -1.797693134862315708e+308);
    EXPECT_DOUBLE_EQ(*dp_hex2dec(&(n = 0x8010000000000000)), -2.225073858507201383e-308);
    EXPECT_DOUBLE_EQ(*dp_hex2dec(&(n = 0x0010000000000000)), 2.225073858507201383e-308);
    EXPECT_DOUBLE_EQ(*dp_hex2dec(&(n = 0x7FEFFFFFFFFFFFFF)), 1.797693134862315708e+308);
}

TEST(Hex2Dec, Denormalized)
{
    ULL n;

    EXPECT_DOUBLE_EQ(*dp_hex2dec(&(n = 0x800FFFFFFFFFFFFF)), -2.225073858507200889e-308);
    EXPECT_DOUBLE_EQ(*dp_hex2dec(&(n = 0x8000000000000001)), -4.940656458412465441e-324);
    EXPECT_DOUBLE_EQ(*dp_hex2dec(&(n = 0x0000000000000001)), 4.940656458412465441e-324);
    EXPECT_DOUBLE_EQ(*dp_hex2dec(&(n = 0x000FFFFFFFFFFFFF)), 2.225073858507200889e-308);
}

TEST(Hex2Dec, Zero)
{
    ULL n;

    EXPECT_DOUBLE_EQ(*dp_hex2dec(&(n = 0x8000000000000000)), 0);
    EXPECT_DOUBLE_EQ(*dp_hex2dec(&(n = 0x0000000000000000)), 0);
}

TEST(Dec2Hex, Inf)
{
    double f;

    EXPECT_EQ(*dp_dec2hex(&(f = -1.797693134862315708e+309)), 0xFFF0000000000000);
    EXPECT_EQ(*dp_dec2hex(&(f = 1.797693134862315708e+309)), 0x7FF0000000000000);
}

TEST(Dec2Hex, Normalized)
{
    double f;

    EXPECT_EQ(*dp_dec2hex(&(f = -1.797693134862315708e+308)), 0xFFEFFFFFFFFFFFFF);
    EXPECT_EQ(*dp_dec2hex(&(f = -2.225073858507201383e-308)), 0x8010000000000000);
    EXPECT_EQ(*dp_dec2hex(&(f = 2.225073858507201383e-308)), 0x0010000000000000);
    EXPECT_EQ(*dp_dec2hex(&(f = 1.797693134862315708e+308)), 0x7FEFFFFFFFFFFFFF);
}

TEST(Dec2Hex, Denormalized)
{
    double f;

    EXPECT_EQ(*dp_dec2hex(&(f = -2.225073858507200889e-308)), 0x800FFFFFFFFFFFFF);
    EXPECT_EQ(*dp_dec2hex(&(f = -4.940656458412465441e-324)), 0x8000000000000001);
    EXPECT_EQ(*dp_dec2hex(&(f = 4.940656458412465441e-324)), 0x0000000000000001);
    EXPECT_EQ(*dp_dec2hex(&(f = 2.225073858507200889e-308)), 0x000FFFFFFFFFFFFF);
}

TEST(Dec2Hex, Zero)
{
    double f;

    EXPECT_EQ(*dp_dec2hex(&(f = 0)), 0x0000000000000000);
}

int main()
{
    testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}