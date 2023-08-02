cmd_/home/yoav/NetFilterProj/modules.order := {   echo /home/yoav/NetFilterProj/Netfilter.ko; :; } | awk '!x[$$0]++' - > /home/yoav/NetFilterProj/modules.order
