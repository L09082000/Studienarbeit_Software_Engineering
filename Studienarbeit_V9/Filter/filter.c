#include "filter.h"
#include "../Sensors/AccelerationSensor/lsm6dsl.h"
#include "../Sensors/MagnetometerSensor/lis3mdl.h"

/* Filterparameter: LPF, 0 < alpha < 1, kleiner alpha = stärker glättend */
#define FILTER_ALPHA 0.1f

/* interne statische Variable für vorherige gefilterte Werte */
static LSM6DSL_FILTERED_VALUES prev_filtered_imu;
static LIS3MDL_FILTERED_VALUES prev_filtered_mag;

/* --- LSM6DSL --- */
void Filter_Init(void) {
    prev_filtered_imu.acc_x = 0.0f;
    prev_filtered_imu.acc_y = 0.0f;
    prev_filtered_imu.acc_z = 0.0f;
    prev_filtered_imu.gyro_x = 0.0f;
    prev_filtered_imu.gyro_y = 0.0f;
    prev_filtered_imu.gyro_z = 0.0f;
    prev_filtered_imu.temperature = 0.0f;
}

/* LSM6DSL Filter Update */
LSM6DSL_FILTERED_VALUES Filter_Update(LSM6DSL_VALUES current) {
    LSM6DSL_FILTERED_VALUES filtered;

    filtered.acc_x = FILTER_ALPHA * current.acc_x + (1.0f - FILTER_ALPHA) * prev_filtered_imu.acc_x;
    filtered.acc_y = FILTER_ALPHA * current.acc_y + (1.0f - FILTER_ALPHA) * prev_filtered_imu.acc_y;
    filtered.acc_z = FILTER_ALPHA * current.acc_z + (1.0f - FILTER_ALPHA) * prev_filtered_imu.acc_z;

    filtered.gyro_x = FILTER_ALPHA * current.gyro_x + (1.0f - FILTER_ALPHA) * prev_filtered_imu.gyro_x;
    filtered.gyro_y = FILTER_ALPHA * current.gyro_y + (1.0f - FILTER_ALPHA) * prev_filtered_imu.gyro_y;
    filtered.gyro_z = FILTER_ALPHA * current.gyro_z + (1.0f - FILTER_ALPHA) * prev_filtered_imu.gyro_z;

    filtered.temperature = FILTER_ALPHA * current.temperature + (1.0f - FILTER_ALPHA) * prev_filtered_imu.temperature;

    prev_filtered_imu = filtered;
    return filtered;
}

/* --- LIS3MDL --- */
void LIS3MDL_Filter_Init(void) {
    prev_filtered_mag.x = 0.0f;
    prev_filtered_mag.y = 0.0f;
    prev_filtered_mag.z = 0.0f;
}

LIS3MDL_FILTERED_VALUES LIS3MDL_Filter_Update(LIS3MDL_VALUES current) {
    LIS3MDL_FILTERED_VALUES filtered;

    filtered.x = FILTER_ALPHA * current.x + (1.0f - FILTER_ALPHA) * prev_filtered_mag.x;
    filtered.y = FILTER_ALPHA * current.y + (1.0f - FILTER_ALPHA) * prev_filtered_mag.y;
    filtered.z = FILTER_ALPHA * current.z + (1.0f - FILTER_ALPHA) * prev_filtered_mag.z;

    prev_filtered_mag = filtered;
    return filtered;
}
