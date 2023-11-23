#include <float.h>
#include <gtest/gtest.h>
#include <math.h>

extern "C" {
#include <fpc.h>
}

TEST(Hex2Dec, Nan) {
  unsigned n;

  EXPECT_TRUE(isnan(*sp_hex2dec(&(n = 0xFFFFFFFF))));
  EXPECT_TRUE(isnan(*sp_hex2dec(&(n = 0xFF800001))));
  EXPECT_TRUE(isnan(*sp_hex2dec(&(n = 0x7F800001))));
  EXPECT_TRUE(isnan(*sp_hex2dec(&(n = 0x7FFFFFFF))));
}

TEST(Hex2Dec, Inf) {
  unsigned n;

  EXPECT_TRUE(isinf(*sp_hex2dec(&(n = 0xFF800000))));
  EXPECT_TRUE(isinf(*sp_hex2dec(&(n = 0x7F800000))));
}

TEST(Hex2Dec, Normalized) {
  unsigned n;

  EXPECT_FLOAT_EQ(*sp_hex2dec(&(n = 0xFF7FFFFF)), -FLT_MAX);
  EXPECT_FLOAT_EQ(*sp_hex2dec(&(n = 0x80800000)), -FLT_MIN);
  EXPECT_FLOAT_EQ(*sp_hex2dec(&(n = 0x00800000)), FLT_MIN);
  EXPECT_FLOAT_EQ(*sp_hex2dec(&(n = 0x7F7FFFFF)), FLT_MAX);
}

TEST(Hex2Dec, Denormalized) {
  unsigned n;

  EXPECT_FLOAT_EQ(*sp_hex2dec(&(n = 0x807FFFFF)), -FLT_MIN + FLT_TRUE_MIN);
  EXPECT_FLOAT_EQ(*sp_hex2dec(&(n = 0x80000001)), -FLT_TRUE_MIN);
  EXPECT_FLOAT_EQ(*sp_hex2dec(&(n = 0x00000001)), FLT_TRUE_MIN);
  EXPECT_FLOAT_EQ(*sp_hex2dec(&(n = 0x007FFFFF)), FLT_MIN - FLT_TRUE_MIN);
}

TEST(Hex2Dec, Zero) {
  unsigned n;

  EXPECT_FLOAT_EQ(*sp_hex2dec(&(n = 0x80000000)), 0);
  EXPECT_FLOAT_EQ(*sp_hex2dec(&(n = 0x00000000)), 0);
}

TEST(Dec2Hex, Normalized) {
  float f;

  EXPECT_EQ(*sp_dec2hex(&(f = -FLT_MAX)), 0xFF7FFFFF);
  EXPECT_EQ(*sp_dec2hex(&(f = -FLT_MIN)), 0x80800000);
  EXPECT_EQ(*sp_dec2hex(&(f = FLT_MIN)), 0x00800000);
  EXPECT_EQ(*sp_dec2hex(&(f = FLT_MAX)), 0x7F7FFFFF);
}

TEST(Dec2Hex, Denormalized) {
  float f;

  EXPECT_EQ(*sp_dec2hex(&(f = -FLT_MIN + FLT_TRUE_MIN)), 0x807FFFFF);
  EXPECT_EQ(*sp_dec2hex(&(f = -FLT_TRUE_MIN)), 0x80000001);
  EXPECT_EQ(*sp_dec2hex(&(f = FLT_TRUE_MIN)), 0x00000001);
  EXPECT_EQ(*sp_dec2hex(&(f = FLT_MIN - FLT_TRUE_MIN)), 0x007FFFFF);
}

TEST(Dec2Hex, Zero) {
  float f;

  EXPECT_EQ(*sp_dec2hex(&(f = 0)), 0x00000000);
}

int main() {
  testing::InitGoogleTest();
  return RUN_ALL_TESTS();
}