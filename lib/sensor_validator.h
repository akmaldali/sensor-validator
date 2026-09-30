#pragma once

// A single measurement from a sensor.
struct SensorReading {
    double value;         // the measured quantity
    double timestamp_s;   // when it was recorded, in seconds
};

// Validates SensorReadings against a fixed range and a maximum age.
class SensorValidator {
public:
    // min_value and max_value define the inclusive valid range.
    // max_age_s is the maximum allowed age of a reading in seconds.
    SensorValidator(double min_value, double max_value, double max_age_s);

    // Returns true only if reading.value is in [min_value, max_value]
    // AND (current_time_s - reading.timestamp_s) <= max_age_s.
    bool isValid(const SensorReading& reading, double current_time_s) const;

private:
    double min_value_;
    double max_value_;
    double max_age_s_;
};
