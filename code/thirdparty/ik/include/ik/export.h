/* ----------------------------------------------------------------
 * Export and visibility amcros
 * ----------------------------------------------------------------
 * Substitution variables:
 *  - IK_LIB_TYPE   : Set to either SHARED or STATIC.
 *  - IK_PLATFORM   : Set to WINDOWS, OSX, LINUX, ANDROID, or IOS
 * Global definitions (non substitution)
 *  - IK_BUILDING   : Define this if the library is being built.
 * ------------------------------------------------------------- */

#ifndef IK_EXPORT_H
#   define IK_EXPORT_H

    /*
     * define public API macro, depending on whether the library is being
     * built or being linked against.
     */
#   define IK_PUBLIC_API
#   define IK_PRIVATE_API

    /* --------------------------------------------------------------
     * C linkage
     * --------------------------------------------------------------*/

#   ifdef __cplusplus
#       define C_HEADER_BEGIN extern "C" {
#   else
#       define C_HEADER_BEGIN
#   endif

#   ifdef __cplusplus
#       define C_HEADER_END }
#   else
#       define C_HEADER_END
#   endif

#endif /* IK_EXPORT_H */
