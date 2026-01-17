#include <acpi_vendor.h>

#define ACPI_OEM_REVISION 0x8450

/* Platform specific configuration */
#define NUM_CORES 8
#define NUM_CLUSTERS 4
#define NUM_SYSTEM 1
#define NUM_CLUSTER_0_CORES 4
#define NUM_CLUSTER_1_CORES 3
#define NUM_CLUSTER_2_CORES 1
#define L1_CACHES_COUNT 2 + 2
#define L2_CACHES_COUNT 1
#define L3_CACHES_COUNT 1

#define UARD_BASE_ADDRESS 0x99C000ULL
#define UARD_GIC_SPI_INTERRUPT_NUMBER GIC_SPI(0x260)

