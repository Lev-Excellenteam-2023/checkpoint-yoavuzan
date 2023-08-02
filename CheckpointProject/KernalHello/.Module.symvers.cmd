cmd_/home/yoav/Kernalwork/Module.symvers := sed 's/ko$$/o/' /home/yoav/Kernalwork/modules.order | scripts/mod/modpost -m -a  -o /home/yoav/Kernalwork/Module.symvers -e -i Module.symvers   -T -
