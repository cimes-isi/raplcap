#ifndef _RAPLCAP_CPUID_H_
#define _RAPLCAP_CPUID_H_

#ifdef __cplusplus
extern "C" {
#endif

#pragma GCC visibility push(hidden)

#define CPUID_VENDOR_ID_GENUINE_INTEL "GenuineIntel"

/* 
 * See: Software Developer's Manual, Volume 4 (March 2018)
 * See: https://en.wikichip.org/wiki/intel/cpuid
 */

//----
// Sandy Bridge is the first to support RAPL
#define CPUID_MODEL_SANDYBRIDGE       0x2A
#define CPUID_MODEL_SANDYBRIDGE_X     0x2D

#define CPUID_MODEL_IVYBRIDGE         0x3A
#define CPUID_MODEL_IVYBRIDGE_X       0x3E

#define CPUID_MODEL_HASWELL_CORE      0x3C
#define CPUID_MODEL_HASWELL_X         0x3F
#define CPUID_MODEL_HASWELL_ULT       0x45
#define CPUID_MODEL_HASWELL_GT3E      0x46

#define CPUID_MODEL_BROADWELL_CORE    0x3D
#define CPUID_MODEL_BROADWELL_GT3E    0x47
#define CPUID_MODEL_BROADWELL_X       0x4F
#define CPUID_MODEL_BROADWELL_XEON_D  0x56

#define CPUID_MODEL_SKYLAKE_MOBILE    0x4E
#define CPUID_MODEL_SKYLAKE_X         0x55
#define CPUID_MODEL_SKYLAKE_DESKTOP   0x5E

#define CPUID_MODEL_KABYLAKE_MOBILE   0x8E
#define CPUID_MODEL_KABYLAKE_DESKTOP  0x9E

#define CPUID_MODEL_CANNONLAKE_MOBILE 0x66

#define CPUID_MODEL_XEON_PHI_KNL      0x57
#define CPUID_MODEL_XEON_PHI_KNM      0x85

#define CPUID_MODEL_ATOM_SILVERMONT1  0x37 // Bay Trail
#define CPUID_MODEL_ATOM_MERRIFIELD   0x4A // Tangier
// "SILVERMONT2" is specified in, but not used by, the Linux kernel
// Disabled SILVERMONT2 b/c it's documentation is strange; no use supporting an apparently non-existent CPU
// #define CPUID_MODEL_ATOM_SILVERMONT2  0x4D // Avoton, Rangeley;
#define CPUID_MODEL_ATOM_AIRMONT      0x4C // Cherry Trail, Braswell
#define CPUID_MODEL_ATOM_MOOREFIELD   0x5A // Anniedale
// "SoFIA" does not appear to have Linux kernel support
#define CPUID_MODEL_ATOM_SOFIA        0x5D

#define CPUID_MODEL_ATOM_GOLDMONT     0x5C
#define CPUID_MODEL_ATOM_DENVERTON    0x5F
#define CPUID_MODEL_ATOM_GEMINI_LAKE  0x7A
//----

/**
 * Check that the CPU vendor is GenuineIntel.
 *
 * @return 1 if Intel, 0 otherwise
 */
int cpuid_is_vendor_intel(void);

/**
 * Get the CPU family and model.
 * Model parsing assumes that family=6.
 *
 * @param family not NULL
 * @param model not NULL
 */
void cpuid_get_family_model(uint32_t* family, uint32_t* model);

/**
 * Check that family=6 and model is one of those listed above.
 *
 * @param family
 * @param model
 * @return 1 if supported, 0 otherwise
 */
int cpuid_is_cpu_supported(uint32_t family, uint32_t model);

#pragma GCC visibility pop

#ifdef __cplusplus
}
#endif

#endif