#pragma once
#include "binary_op_device.h"
#include "ternary_op_device.h"

class BinaryTernaryDevice final : public TernaryOpDevice,
                                  public BinaryOpDevice {
public:
    using BinaryOpDevice::BinaryOpDevice;
    virtual ~BinaryTernaryDevice() = default;
    bool IsAvailable() const override final;
    int TernaryOp(int x, int y, int z) const override final;
    int BinaryOp(int x, int y) const override final;
    std::string DeviceName() const override final;
    size_t IOCount() const override final;
};
