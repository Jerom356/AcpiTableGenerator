/** OEMdata struct of chipidea controller in dbg2
    Reference to:
      \Windows
   Kits\10\Debuggers\ddk\samples\kdnet\usb\usbfn\miniport\chipidea\usbfnmp.c
*/

#include "common.h"

#define DBG2_DEVICE_OEM_DATA_CHIPIDEA_WRITE_ENTRIES_MAX 16
#define DBG2_DEVICE_OEM_DATA_CHIPIDEA_MAGIC '1', 'X', 'I', 'F' // "FIX1"

typedef struct {
  UINT8 BaseAddressReg;
  UINT8 Reserved;
  UINT16 Offset;
  UINT32 Val2And;
  UINT32 Val2Or;
} __attribute__((packed)) DBG2_DEVICE_OEM_DATA_CHIPIDEA_WRITE_ENTRY;

typedef struct {
  UINT16 PortType;
  UINT16 Reserved;
  UINT32 Magic;
  UINT32 NumOfEntries;
  DBG2_DEVICE_OEM_DATA_CHIPIDEA_WRITE_ENTRY
  WriteEntries[DBG2_DEVICE_OEM_DATA_CHIPIDEA_WRITE_ENTRIES_MAX];
} __attribute__((packed)) DBG2_DEVICE_OEM_DATA_CHIPIDEA;

// Helper macro to define CHIPIDEA OEM data
#define DBG2_DEVICE_OEM_DATA_CHIPIDEA_ENTRY(base_addr_reg, offset, val2and,    \
                                            val2or)                            \
  {                                                                            \
      .BaseAddressReg = base_addr_reg,                                         \
      .Reserved = 0,                                                           \
      .Offset = offset,                                                        \
      .Val2And = val2and,                                                      \
      .Val2Or = val2or,                                                        \
  }
