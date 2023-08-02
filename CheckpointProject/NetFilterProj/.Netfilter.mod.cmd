cmd_/home/yoav/NetFilterProj/Netfilter.mod := printf '%s\n'   Netfilter.o | awk '!x[$$0]++ { print("/home/yoav/NetFilterProj/"$$0) }' > /home/yoav/NetFilterProj/Netfilter.mod
