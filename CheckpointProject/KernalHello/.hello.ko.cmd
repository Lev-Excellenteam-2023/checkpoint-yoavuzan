cmd_/home/yoav/Kernalwork/hello.ko := ld -r -m elf_x86_64 -z noexecstack --build-id=sha1  -T scripts/module.lds -o /home/yoav/Kernalwork/hello.ko /home/yoav/Kernalwork/hello.o /home/yoav/Kernalwork/hello.mod.o;  true