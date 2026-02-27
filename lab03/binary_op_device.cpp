#include "binary_op_device.h"

std::string BinaryOpDevice::DeviceName() const {
    return Device::DeviceName() + " [binary]";
}
