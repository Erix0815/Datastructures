#ifndef universal_h
#define universal_h

/**
 * a function used to compare and sort elements in datastructures
 * \return signed "distance" between `a` and `b` (similar to `b - a`).
 * | Value | Meaning              |
 * |------:|:---------------------|
 * | `> 0` | `a` precedes `b`     |
 * | `= 0` | the values are equal |
 * | `< 0` | `b` precedes `a`     |
 */
typedef int (*compare_fn)(void* a, void* b);

#endif
