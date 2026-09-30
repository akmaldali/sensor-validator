#include "sensor_validator.h"


SensorValidator::SensorValidator(
    double min_value,
    double max_value,
    double max_age_s)
    : min_value_(min_value),
      max_value_(max_value),
      max_age_s_(max_age_s) {
}

bool SensorValidator::isValid(
    const SensorReading& reading,
    double current_time_s) const {

    const bool value_valid =
        reading.value >= min_value_ &&
        reading.value <= max_value_;

    const bool age_valid =
        (current_time_s - reading.timestamp_s) <= max_age_s_;

    return value_valid && age_valid;
}
