#include <linux/build-salt.h>
#include <linux/module.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

BUILD_SALT;

MODULE_INFO(vermagic, VERMAGIC_STRING);
MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__attribute__((section(".gnu.linkonce.this_module"))) = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

#ifdef CONFIG_RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif

static const struct modversion_info ____versions[]
__used
__attribute__((section("__versions"))) = {
	{ 0xad1a7def, "module_layout" },
	{ 0x7a3acc89, "cdev_init" },
	{ 0xf9a482f9, "msleep" },
	{ 0x2e5810c6, "__aeabi_unwind_cpp_pr1" },
	{ 0x47229b5c, "gpio_request" },
	{ 0x350a004, "gpio_to_desc" },
	{ 0xb1ad28e0, "__gnu_mcount_nc" },
	{ 0xf2564cc6, "spi_setup" },
	{ 0x5f754e5a, "memset" },
	{ 0x18c592b7, "spi_busnum_to_master" },
	{ 0x7c32d0f0, "printk" },
	{ 0x14ba4057, "spi_new_device" },
	{ 0x366ed94b, "gpiod_direction_input" },
	{ 0xe31620ea, "gpiod_direction_output_raw" },
	{ 0xd3c6c6bd, "spi_sync" },
	{ 0x88647e86, "cdev_add" },
	{ 0x6ef4e6c8, "gpiod_set_debounce" },
	{ 0xee90f06e, "gpiod_unexport" },
	{ 0xdb7305a1, "__stack_chk_fail" },
	{ 0xfe990052, "gpio_free" },
	{ 0xddaa5251, "gpiod_export" },
	{ 0xffb0dcd9, "gpiod_set_raw_value" },
	{ 0x8f678b07, "__stack_chk_guard" },
	{ 0xe5cbf037, "spi_unregister_device" },
	{ 0x16e02b99, "gpiod_get_raw_value" },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=";


MODULE_INFO(srcversion, "B722FB2A351DB1CFB188A44");
