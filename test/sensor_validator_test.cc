#include "lib/sensor_validator.h"

#include <gtest/gtest.h>

TEST(SensorValidatorTest, ValidReading) {
    SensorValidator validator(0.0, 100.0, 10.0);
    SensorReading reading{50.0, 95.0};

    EXPECT_TRUE(validator.isValid(reading, 100.0));
}

TEST(SensorValidatorTest, ValueBelowMinimumIsInvalid) {
    SensorValidator validator(0.0, 100.0, 10.0);
    SensorReading reading{-1.0, 95.0};

    EXPECT_FALSE(validator.isValid(reading, 100.0));
}

TEST(SensorValidatorTest, ValueAboveMaximumIsInvalid) {
    SensorValidator validator(0.0, 100.0, 10.0);
    SensorReading reading{101.0, 95.0};

    EXPECT_FALSE(validator.isValid(reading, 100.0));
}

TEST(SensorValidatorTest, MinimumValueIsValid) {
    SensorValidator validator(0.0, 100.0, 10.0);
    SensorReading reading{0.0, 95.0};

    EXPECT_TRUE(validator.isValid(reading, 100.0));
}

TEST(SensorValidatorTest, MaximumValueIsValid) {
    SensorValidator validator(0.0, 100.0, 10.0);
    SensorReading reading{100.0, 95.0};

    EXPECT_TRUE(validator.isValid(reading, 100.0));
}

TEST(SensorValidatorTest, MaximumAgeIsValid) {
    SensorValidator validator(0.0, 100.0, 10.0);
    SensorReading reading{50.0, 90.0};

    EXPECT_TRUE(validator.isValid(reading, 100.0));
}

TEST(SensorValidatorTest, ReadingOlderThanMaximumAgeIsInvalid) {
    SensorValidator validator(0.0, 100.0, 10.0);
    SensorReading reading{50.0, 89.0};

    EXPECT_FALSE(validator.isValid(reading, 100.0));
}

TEST(SensorValidatorTest, InvalidValueAndAgeIsInvalid) {
    SensorValidator validator(0.0, 100.0, 10.0);
    SensorReading reading{101.0, 89.0};

    EXPECT_FALSE(validator.isValid(reading, 100.0));
}
