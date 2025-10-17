MPSSE for Linux
---------------

As Linux distributions vary these instructions are a guide to installation 
and use.  FTDI has tested the driver with LTS Ubuntu distributions for 
x86 and x86_64 architectures, and Raspbian on Raspberry Pi.

FTDI developed libmpsse to extend libftd2xx primarily to aid porting Windows 
applications written with D2XX to Linux.  We intend the APIs to behave the 
same on Windows and Linux so if you notice any differences, please contact us 
(see http://www.ftdichip.com/FTSupport.htm).

FTDI do release the source code for libmpsse but not libftd2xx. An up-to-date
copy of libftd2xx is required to use the libmpsse library.

The libftd2xx library must be installed as a shared library on the system.


Installing the D2XX MPSSE Shared Library and Static Library
------------------------------------------------------------

1.  Extract the archive:

    tar xvf libmpsse-x86_64-1.0.8.tgz

This unpacks the archive, creating the following directory structure:

    release/
        ReadMe.txt                  (this installation guide)
        Makefile, targets.mak       (build system files)
        release-notes.txt           (version and update notes)
        copyLib.sh                  (helper script for copying libraries)
        install_libmpsse.sh         (automated installation script)

        build/
            libmpsse.so.1.0.8   (dynamic/shared library)
            libmpsse.so                       (symbolic link to the shared library)
            libmpsse.a                        (static library)
            source/
                ftdi_spi.o
                ftdi_infra.o
                ftdi_mid.o
                ftdi_i2c.o

        include/
            libmpsse_spi.h       (header file for SPI API)
            libmpsse_i2c.h       (header file for I2C API)

        libftd2xx/
            ftd2xx.h             (header file for D2XX API)
            WinTypes.h           (standard Windows C data types)

        source/
            ftdi_spi.c
            ftdi_i2c.c
            ftdi_infra.c
            ftdi_mid.c
            memcpy.c
            ftdi_infra.h
            ftdi_mid.h
            ftdi_common.h

        test/
            test.c               (test program for library and DLL)


2. Method 1: Using the `install_libmpsse.sh` Script (Recommended)

    The `install_libmpsse.sh` script automates the entire installation process, simplifying the setup. To use this script:

    1. Navigate to the `release` directory:

        cd release

    2. Make the script executable (if not already executable):

        chmod +x install_libmpsse.sh

    3. Run the installation script:

        ./install_libmpsse.sh

    This script will handle all the steps required to install the libraries and header files to the appropriate locations.

3. Method 2: Manual Installation

    If you prefer to manually install the libraries, follow these steps:

    1. Navigate to the `release/build` directory:

        cd release/build

    2. Become a superuser to install the libraries:

        sudo -s
        or, if sudo is not available on your system:
        su

    This promotes you to superuser, with installation privileges. If you're already root, then step 3 (and step 7) is not necessary.

    3. Copy the libraries to a central location:

        cp libmpsse.* /usr/local/lib

    This will copy both the shared library (`libmpsse.so`) and static library (`libmpsse.a`) to `/usr/local/lib`.

    4. Set the correct permissions for the shared object:

        chmod 0755 /usr/local/lib/libmpsse.so.1.0.8

    This allows non-root access to the shared object.

    5. If the symbolic link `/usr/local/lib/libmpsse.so` is not present or incorrect, create or update it:

        ln -sf /usr/local/lib/libmpsse.so.1.0.8 /usr/local/lib/libmpsse.so

    This ensures the system can link against the correct version of the shared library. You can verify the link with:

        ls -l /usr/local/lib/libmpsse.so

    6. Copy the header files to a central location:

        cd ..
        cp include/*.h /usr/local/include
        cp libftd2xx/*.h /usr/local/include

    This copies the header files to `/usr/local/include`. The installation of `libftd2xx` will also place `ftd2xx.h` and `WinTypes.h` in this location.

    7. Update the linker shared object cache:

        ldconfig -v

    This updates the shared library cache to include the newly installed library.

    8. Exit your super-user session:

        exit

    This ends your super-user session if you used `sudo` or `su`.



Building the shared-object examples.
------------------------------------

1.  make

This rebuilds the libraries, the shared-object and static library test file.

2. After plugging in FTDI MPSSE device, need to run rmmod ftdi_sio and rmmod usbserial or no MPSSE device will be recognized.

3. sudo build/native/statictest

With an FTDI device connected to a USB port run the static library test file.

4. sudo build/native/dynamictest

With an FTDI device connected to a USB port run the shared object test file.

