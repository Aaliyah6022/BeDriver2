BeDriver2
======

A Kernel mode driver made for reading and writing protected memory from kernel access. Efficient for bypassing kernel anticheats.

Anticheats Bypassed Utilizing Kernel Modules
======
BattleEye, Xigncode, Easy Anti Cheat, Vanguard


What is a kernel mode driver & Kernel Mode vs User Mode
======

A processor in a Windows computer has two different modes: kernel mode and user mode. The processor switches between the two modes depending on what type of code is running. Normal .exe programs run in user mode & core operating system components run in kernel mode. The Usermode & Kernelmode construct is built into the CPU. The low level core functionality of the operating system is done in kernel mode, which is a privileged part of memory that is not accessible from user mode and executes with privileged status on the CPU. Drivers are not just limited to Hardware Drivers, you can make a .sys driver to do anything you want in kernel mode, including bypass anticheat and perform cheat functionality.

A user mode process resides in it's own personal virtual address space that is private and doesn't interact with other processes's memory normally. Each application runs in isolation, if a regular program crashes, the crash is limited to that one application. Other applications and the operating system are not affected by the crash.

All code that runs in kernel mode shares a single virtual address space. This means that a kernel-mode driver is not isolated from other drivers and the operating system itself. If a kernel-mode driver accidentally writes to the wrong virtual address, data that belongs to the operating system or another driver could be compromised. If a kernel-mode driver crashes, the entire operating system crashes.

![download](https://user-images.githubusercontent.com/56796801/162623183-da69f689-3052-465b-ad87-97da0076b5d8.png)


How does this apply to bypassing Anticheat?
======

If you are dealing with a strong usermode anticheat, you can write a kernel mode driver to bypass it. Because you are in the kernel and the anticheat is not, you can modify the anticheat to stop it's detection or you can hide your usermode module from it entirely. A user mode anticheat has no idea what you're doing in kernel.

If the anticheat has a kernel driver then you must also be in kernel mode, because nothing you do in usermode is going to be able to bypass or hide from a kernel anticheat. Generally speaking, kernel mode drivers are not necessary to hack 99% of games. In fact, kernel mode drivers are very easy to detect by anticheat if not done correctly.

Coding a kernel driver is much more complicated than user mode applications, for which reason your functionality which provides the "bypass" is done in the kernel but in most cases, the actual cheat logic is done in a usermode module. In this situation, you load your driver, enable your "bypass" functionality and then inject your DLL. Alternatively you can write your entire hack to run in kernel mode, which is more difficult.

Driver Signing & Test Signing
======

.. code:: cpp
bcdedit.exe -set loadoptions DDISABLE_INTEGRITY_CHECKS
bcdedit.exe -set TESTSIGNING ON

bcdedit /set {default} bootmenupolicy legacy


KDMapper
=====

Utilizes an embedded vulnerable Intel driver
Manually Maps your driver
Provides a simple command line interface
You just pass it 1 argument and you're driver is loaded
KDMapper comes embedded with the vulnerable iqvw64e.sys Intel Ethernet diagnostics driver driver. The driver is embedded as a byte array in intel_driver_resource.hpp

The driver was signed in 2013. The vulnerability was officially published in 2015 as CVE 2015 2291 with a severity score of 7.8. Amazingly it's certificate has not been revoked yet.

KdMapper utilizes IOCTL code 0x80862007 for arbitrary kernel execute

![download1](https://user-images.githubusercontent.com/56796801/162623385-3a568ee3-60ae-444f-877d-c1cc7c21d276.png)
