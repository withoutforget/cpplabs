#pragma once
#include "device.h"

class TernaryOpDevice : public virtual Device {
public:
    virtual ~TernaryOpDevice() = default;
    using Device::Device;
    std::string DeviceName() const override;
    virtual int TernaryOp(int, int, int) const = 0;

protected:
    size_t m_ternary_inputs = 3;
};
