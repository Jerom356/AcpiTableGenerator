/** OEMdata struct of synopsys controller in dbg2

  Reference to:
    \Windows
  Kits\10\Debuggers\ddk\samples\kdnet\usb\usbfn\miniport\synopsys\usbfnmp.c File
  copyright: Copyright (c) Microsoft Corporation
*/
#include "common.h"

#define DBG2_DEVICE_OEM_DATA_SYNOPSYS_WRITE_ENTRIES_MAX 16
#define DBG2_DEVICE_OEM_DATA_SYNOPSYS_MAGIC '2', 'X', 'I', 'F' // "FIX2"

typedef struct {
  UINT8 BaseAddressReg;
  UINT8 Phase;
  UINT8 Reserved[2];
  UINT32 Offset;
  UINT32 Val2And;
  UINT32 Val2Or;
} __attribute__((packed)) DBG2_DEVICE_OEM_DATA_SYNOPSYS_WRITE_ENTRY;

typedef struct {
  UINT16 PortType;
  UINT16 Reserved;
  CHAR8 Magic[4];
  UINT32 NumOfEntries;
  DBG2_DEVICE_OEM_DATA_SYNOPSYS_WRITE_ENTRY
  WriteEntries[DBG2_DEVICE_OEM_DATA_SYNOPSYS_WRITE_ENTRIES_MAX];
} __attribute__((packed)) DBG2_DEVICE_OEM_DATA_SYNOPSYS;

// Helper macro to define synopsys OEM data
#define DBG2_DEVICE_OEM_DATA_SYNOPSYS_ENTRY(phase, offset, val2and, val2or)    \
  {                                                                            \
      .BaseAddressReg = 0,                                                     \
      .Phase = phase,                                                          \
      .Reserved = {0},                                                         \
      .Offset = offset,                                                        \
      .Val2And = val2and,                                                      \
      .Val2Or = val2or,                                                        \
  }
