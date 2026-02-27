#include "ternary_op_device.h"

std::string TernaryOpDevice::DeviceName() const {
    return Device::DeviceName() + " [ternary]";
}
