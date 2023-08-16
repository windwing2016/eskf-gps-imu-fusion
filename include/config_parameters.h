//
// Created by Zhang Zhimeng on 23-8-16.
//

#ifndef GPS_IMU_FUSION_CONFIG_PARAMETERS_H
#define GPS_IMU_FUSION_CONFIG_PARAMETERS_H

#include <glog/logging.h>
#include <yaml-cpp/yaml.h>

class ConfigParameters {
public:
    ConfigParameters() = default;

    void LoadParameters(const std::string &config_file_path) {
        try {
            YAML::Node config_node = YAML::LoadFile(config_file_path);

            earth_rotation_speed_ = config_node["earth_rotation_speed"].as<double>();
            earth_gravity_ = config_node["earth_gravity"].as<double>();
            ref_longitude_ = config_node["ref_longitude"].as<double>();
            ref_latitude_ = config_node["ref_latitude"].as<double>();
            position_error_prior_std_ = config_node["position_error_prior_std"].as<double>();
            velocity_error_prior_std_ = config_node["velocity_error_prior_std"].as<double>();
            rotation_error_prior_std_ = config_node["rotation_error_prior_std"].as<double>();
            accelerometer_bias_error_prior_std_ = config_node["accelerometer_bias_error_prior_std"].as<double>();
            gyro_bias_error_prior_std_ = config_node["gyro_bias_error_prior_std"].as<double>();
            gyro_noise_std_ = config_node["gyro_noise_std"].as<double>();
            accelerometer_noise_std_ = config_node["accelerometer_noise_std"].as<double>();
            gps_position_std_ = config_node["gps_position_std"].as<double>();

            LOG(INFO) << "####### Config Parameters #######";
            LOG(INFO) << "earth_rotation_speed: " << earth_rotation_speed_;
            LOG(INFO) << "earth_gravity: " << earth_gravity_;
            LOG(INFO) << "ref_longitude: " << ref_longitude_;
            LOG(INFO) << "ref_latitude: " << ref_latitude_;
            LOG(INFO) << "position_error_prior_std: " << position_error_prior_std_;
            LOG(INFO) << "velocity_error_prior_std: " << velocity_error_prior_std_;
            LOG(INFO) << "rotation_error_prior_std: " << rotation_error_prior_std_;
            LOG(INFO) << "accelerometer_bias_error_prior_std: " << accelerometer_bias_error_prior_std_;
            LOG(INFO) << "gyro_bias_error_prior_std: " << gyro_bias_error_prior_std_;
            LOG(INFO) << "gyro_noise_std: " << gyro_noise_std_;
            LOG(INFO) << "accelerometer_noise_std: " << accelerometer_noise_std_;
            LOG(INFO) << "gps_position_std: " << gps_position_std_;
            LOG(INFO) << std::endl;
        } catch (...) {
            LOG(FATAL) << "Load config parameters failure, path: " << config_file_path;
        }
    }

public:
    // earth
    double earth_rotation_speed_{};
    double earth_gravity_{};

    // reference point
    double ref_longitude_{};
    double ref_latitude_{};

    // kalman prediction process std
    double position_error_prior_std_{};
    double velocity_error_prior_std_{};
    double rotation_error_prior_std_{};
    double accelerometer_bias_error_prior_std_{};
    double gyro_bias_error_prior_std_{};

    // imu sensor noise
    double gyro_noise_std_{};
    double accelerometer_noise_std_{};

    // kalman measurement process std
    double gps_position_std_{};
};

#endif //GPS_IMU_FUSION_CONFIG_PARAMETERS_H