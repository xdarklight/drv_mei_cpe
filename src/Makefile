RGSRC=../../../../../../
include $(RGSRC)/envir.mak

obj-$(CONFIG_DSL_MEI_CPE_DRV)=drv_mei_cpe_mod.o

RAMDISK_MODULES_FILES+=drv_mei_cpe_mod.o

O_OBJS=drv_mei_cpe_common.o drv_mei_cpe_api_intern.o \
  drv_mei_cpe_api_atm_ptm_intern.o drv_mei_cpe_msg_process.o \
  drv_mei_cpe_msg_process_ar9.o drv_mei_cpe_msg_map_ar9.o \
  drv_mei_cpe_dbg_access.o drv_mei_cpe_dbg.o drv_mei_cpe_dbg_driver.o \
  drv_mei_cpe_linux.o drv_mei_cpe_linux_proc_config.o drv_mei_cpe_vxworks.o \
  drv_mei_cpe_vxworks_bsp.o drv_mei_cpe_ecos.o drv_mei_cpe_nucleus.o \
  drv_mei_cpe_mei_access_vrx.o drv_mei_cpe_mei_access_ar9.o \
  drv_mei_cpe_device_vrx.o drv_mei_cpe_rom_handler.o drv_mei_cpe_download.o \
  drv_mei_cpe_download_vrx.o drv_mei_cpe_dsm.o \
  drv_mei_cpe_device_cntrl.o drv_mei_cpe_driver_msg.o \
  drv_mei_cpe_atmoam_common.o drv_mei_cpe_clear_eoc_common.o

INTERNAL_HEADERS=\
  drv_mei_cpe_ecos.h drv_mei_cpe_msg_process.h drv_if_vdsl2_atm_oam.h \
  drv_mei_cpe_dbg_access.h drv_mei_cpe_generic_proc.h drv_mei_cpe_nucleus.h \
  drv_if_vdsl2_clear_eoc.h drv_mei_cpe_dbg_driver.h drv_mei_cpe_os.h \
  drv_mei_cpe_dbg.h drv_mei_cpe_linux.h \
  drv_mei_cpe_rom_handler.h drv_mei_cpe_api.h drv_mei_cpe_device_cntrl.h \
  drv_mei_cpe_linux_proc_config.h drv_mei_cpe_rom_handler_if.h \
  drv_mei_cpe_download.h drv_mei_cpe_mailbox.h drv_mei_cpe_vxworks.h \
  drv_mei_cpe_atmoam_common.h \
  drv_mei_cpe_mei_access.h mei_cpe_appl_osmap.h drv_mei_cpe_atmoam.h \
  drv_mei_cpe_mei_interface.h \
  mei_cpe_drv_examp_int_wrap_vxw.h drv_mei_cpe_clear_eoc_common.h \
  drv_mei_cpe_download_vrx_common.h \
  mei_cpe_drv_test_fct.h drv_mei_cpe_clear_eoc.h drv_mei_cpe_download_vrx.h \
  drv_mei_cpe_mei_vrx.h drv_mei_cpe_config_auto.h drv_mei_cpe_driver_msg.h \
  drv_mei_cpe_msg_map_ar9.h drv_mei_cpe_dsm.h drv_mei_cpe_dsm_common.h

EXPORT_HEADERS_DIR=vendor/mei
EXPORT_HEADERS=drv_mei_cpe_api_intern.h drv_mei_cpe_config.h \
  drv_mei_cpe_interface.h cmv_message_format.h drv_mei_cpe_api_atm_ptm_intern.h

MOD_TARGET+=$(obj-y) $(obj-m)
MOD_2_STAT+=$(obj-y)
RAMDISK_MODULES_FILES+=$(obj-m)

include $(RGMK)
