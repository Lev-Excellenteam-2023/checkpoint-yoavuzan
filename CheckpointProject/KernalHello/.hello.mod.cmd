cmd_/home/yoav/Kernalwork/hello.mod := printf '%s\n'   hello.o | awk '!x[$$0]++ { print("/home/yoav/Kernalwork/"$$0) }' > /home/yoav/Kernalwork/hello.mod
