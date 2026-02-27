#include <iostream>
#include <memory>

#include "binary_ternary_device.h"
#include "unary_binary_device.h"

int main() {
    UnaryBinaryDevice ub("unary-binary", 1);
    std::cout << ub.DeviceName() << std::endl;
    std::cout << ub.IOCount() << std::endl;
    std::cout << ub.UnaryOp(1) << std::endl;
    std::cout << ub.BinaryOp(1, 2) << std::endl;

    BinaryTernaryDevice bt("binary-ternary", 2);
    std::cout << bt.DeviceName() << std::endl;
    std::cout << bt.IOCount() << std::endl;
    std::cout << bt.BinaryOp(1, 2) << std::endl;
    std::cout << bt.TernaryOp(3, 4, 5) << std::endl;

    std::unique_ptr<Device> dev1 =
        std::make_unique<UnaryBinaryDevice>("smart-ub", 0);
    std::cout << dev1->DeviceName()
              << ", available: " << dev1->IsAvailable()
              << std::endl;

    Device* dev2 = new BinaryTernaryDevice("raw-bt", 0);
    std::cout << dev2->DeviceName()
              << ", available: " << dev2->IsAvailable()
              << std::endl;
    delete dev2;

    const Device& ref1 = ub;
    std::cout << ref1.DeviceName()
              << ", available: " << ref1.IsAvailable()
              << std::endl;

    const Device& ref2 = bt;
    std::cout << ref2.DeviceName()
              << ", available: " << ref2.IsAvailable()
              << std::endl;

    const UnaryOpDevice& uref = ub;
    std::cout << uref.UnaryOp(5) << std::endl;

    const BinaryOpDevice& bref = bt;
    std::cout << bref.BinaryOp(3, 4) << std::endl;
}
