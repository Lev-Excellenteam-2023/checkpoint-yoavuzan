#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/netfilter.h>
#include <linux/netfilter_ipv4.h>
#include <linux/ip.h> // Include this header for struct iphdr

static struct nf_hook_ops nfho;

static unsigned int drop_packet_hook(void *priv, struct sk_buff *skb, const struct nf_hook_state *state) {
    struct iphdr *ip_header = (struct iphdr *)skb_network_header(skb);

    // Replace "10.0.0.1" with the IP address you want to block.
    if (ip_header->saddr == htonl(0x172ba9e5)) {
        printk(KERN_INFO "Dropping packet from %pI4\n", &ip_header->saddr);
        return NF_DROP;
    }

    return NF_ACCEPT;
}

static int __init netfilter_module_init(void) {
    nfho.hook = drop_packet_hook;
    nfho.pf = PF_INET;
    nfho.hooknum = NF_INET_PRE_ROUTING;
    nfho.priority = NF_IP_PRI_FIRST;

    nf_register_net_hook(&init_net, &nfho);
    printk(KERN_INFO "Netfilter module loaded\n");
    return 0;
}

static void __exit netfilter_module_exit(void) {
    nf_unregister_net_hook(&init_net, &nfho);
    printk(KERN_INFO "Netfilter module unloaded\n");
}

module_init(netfilter_module_init);
module_exit(netfilter_module_exit);
MODULE_LICENSE("GPL");

