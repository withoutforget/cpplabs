#include "unary_op_device.h"

std::string UnaryOpDevice::DeviceName() const {
    return Device::DeviceName() + " [unary]";
}
