cmd_/home/yoav/Kernalwork/modules.order := {   echo /home/yoav/Kernalwork/hello.ko; :; } | awk '!x[$$0]++' - > /home/yoav/Kernalwork/modules.order
