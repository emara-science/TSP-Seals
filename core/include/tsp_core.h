#ifndef TSP_CORE_H
#define TSP_CORE_H

#ifdef __cplusplus
extern "C" {
#endif

#define TSP_PRODUCT_NAME "TSP SEALS"
#define TSP_PRODUCT_TAGLINE "Troubleshoot Problems"

/* Returns the foundation library version string. */
const char *tsp_core_version(void);

/* Returns the product name. */
const char *tsp_product_name(void);

#ifdef __cplusplus
}
#endif

#endif
