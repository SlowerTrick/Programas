FROM fedora:latest

RUN dnf update -y && dnf install -y \
    gcc gcc-c++ make nano git \
    nasm glibc-devel.i686 \
    gcc-riscv64-linux-gnu qemu-user \
    gcc-arm-linux-gnu \
    qemu-arm qemu-riscv64 \
    && dnf clean all

WORKDIR /workspace
CMD ["/bin/bash"]