#include <gtest/gtest.h>
#include <math.h>

extern "C"
{
#include <fpc.h>
}

TEST(Hex2Dec, Nan)
{
    unsigned n;

    EXPECT_TRUE(isnan(*sp_hex2dec(&(n = 0xFFFFFFFF))));
    EXPECT_TRUE(isnan(*sp_hex2dec(&(n = 0xFF800001))));
    EXPECT_TRUE(isnan(*sp_hex2dec(&(n = 0x7F800001))));
    EXPECT_TRUE(isnan(*sp_hex2dec(&(n = 0x7FFFFFFF))));
}

TEST(Hex2Dec, Inf)
{
    unsigned n;

    EXPECT_TRUE(isinf(*sp_hex2dec(&(n = 0xFF800000))));
    EXPECT_TRUE(isinf(*sp_hex2dec(&(n = 0x7F800000))));
}

TEST(Hex2Dec, Normalized)
{
    unsigned n;

    EXPECT_FLOAT_EQ(*sp_hex2dec(&(n = 0xFF7FFFFF)), -3.40282347e+38);
    EXPECT_FLOAT_EQ(*sp_hex2dec(&(n = 0x80800000)), -1.17549435e-38);
    EXPECT_FLOAT_EQ(*sp_hex2dec(&(n = 0x00800000)), 1.17549435e-38);
    EXPECT_FLOAT_EQ(*sp_hex2dec(&(n = 0x7F7FFFFF)), 3.40282347e+38);
}

TEST(Hex2Dec, Denormalized)
{
    unsigned n;

    EXPECT_FLOAT_EQ(*sp_hex2dec(&(n = 0x807FFFFF)), -1.17549421e-38);
    EXPECT_FLOAT_EQ(*sp_hex2dec(&(n = 0x80000001)), -1.40129846e-45);
    EXPECT_FLOAT_EQ(*sp_hex2dec(&(n = 0x00000001)), 1.40129846e-45);
    EXPECT_FLOAT_EQ(*sp_hex2dec(&(n = 0x007FFFFF)), 1.17549421e-38);
}

TEST(Hex2Dec, Zero)
{
    unsigned n;

    EXPECT_FLOAT_EQ(*sp_hex2dec(&(n = 0x80000000)), 0);
    EXPECT_FLOAT_EQ(*sp_hex2dec(&(n = 0x00000000)), 0);
}

TEST(Dec2Hex, Inf)
{
    float f;

    EXPECT_EQ(*sp_dec2hex(&(f = -3.40282347e+50f)), 0xFF800000);
    EXPECT_EQ(*sp_dec2hex(&(f = 3.40282347e+50f)), 0x7F800000);
}

TEST(Dec2Hex, Normalized)
{
    float f;

    EXPECT_EQ(*sp_dec2hex(&(f = -3.40282347e+38f)), 0xFF7FFFFF);
    EXPECT_EQ(*sp_dec2hex(&(f = -1.17549435e-38f)), 0x80800000);
    EXPECT_EQ(*sp_dec2hex(&(f = 1.17549435e-38f)), 0x00800000);
    EXPECT_EQ(*sp_dec2hex(&(f = 3.40282347e+38f)), 0x7F7FFFFF);
}

TEST(Dec2Hex, Denormalized)
{
    float f;

    EXPECT_EQ(*sp_dec2hex(&(f = -1.17549421e-38f)), 0x807FFFFF);
    EXPECT_EQ(*sp_dec2hex(&(f = -1.40129846e-45f)), 0x80000001);
    EXPECT_EQ(*sp_dec2hex(&(f = 1.40129846e-45f)), 0x00000001);
    EXPECT_EQ(*sp_dec2hex(&(f = 1.17549421e-38f)), 0x007FFFFF);
}

TEST(Dec2Hex, Zero)
{
    float f;

    EXPECT_EQ(*sp_dec2hex(&(f = 0)), 0x00000000);
}

int main()
{
    testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}