/*
 * @file cord.c
 * @brief Implementation of cords library
 *
 * 15-513 Introduction to Computer Systems
 *
 * TODO: fill in your name and Andrew ID below
 * @author Fulun Ma <fulunm@andrew.cmu.edu>
 */

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "cord-interface.h"
#include "xalloc.h"

/***********************************/
/* Implementation (edit this part) */
/***********************************/

/**
 * @brief Checks if a cord is valid
 * @param[in] R
 * @return
 */
bool is_cord(const cord_t *R) {
    if (R == NULL) {
        return true;
    }

    if (R->left == NULL && R->right == NULL) {
        if (R->len > 0 && R->len == strlen(R->data)) {
            return true;
        }
    }

    if (R->left != NULL && R->right != NULL) {
        size_t len = R->left->len + R->right->len;
        if ((len > 0) && (R->len == len) && is_cord(R->left) &&
            is_cord(R->right)) {
            return true;
        }
    }

    return false;
}

/**
 * @brief Returns the length of a cord
 * @param[in] R
 * @return
 */
size_t cord_length(const cord_t *R) {
    if (R == NULL) {
        return 0;
    }

    return R->len;
}

/**
 * @brief Allocates a new cord from a string
 * @param[in] s
 * @return
 */
const cord_t *cord_new(const char *s) {
    if (s == NULL || strlen(s) == 0) {
        return NULL;
    }

    cord_t *new_cord = xmalloc(sizeof(cord_t));

    new_cord->data = s;
    new_cord->left = NULL;
    new_cord->right = NULL;
    new_cord->len = strlen(s);

    return new_cord;
}

/**
 * @brief Concatenates two cords into a new cord
 * @param[in] R
 * @param[in] S
 * @return
 */
const cord_t *cord_join(const cord_t *R, const cord_t *S) {
    if (R == NULL && S == NULL) {
        return NULL;
    }

    if (R == NULL && S != NULL) {
        return S;
    }

    if (R != NULL && S == NULL) {
        return R;
    }

    cord_t *new_cord = xmalloc(sizeof(cord_t));
    new_cord->data = NULL;
    new_cord->left = R;
    new_cord->right = S;
    new_cord->len = R->len + S->len;

    return new_cord;
}

/**
 * @brief Converts a cord to a string
 * @param[in] R
 * @return
 */
char *cord_tostring(const cord_t *R) {
    size_t cord_length_ = cord_length(R);
    char *result = xmalloc(cord_length_ + 1);

    for (size_t i = 0; i < cord_length_; i++) {
        result[i] = cord_charat(R, i);
    }

    result[cord_length_] = '\0';

    return result;
}

/**
 * @brief Returns the character at a position in a cord
 *
 * @param[in] R  A cord
 * @param[in] i  A position in the cord
 * @return The character at position i
 *
 * @requires i is a valid position in the cord R
 */
char cord_charat(const cord_t *R, size_t i) {
    size_t cord_length_ = cord_length(R);
    assert(i <= cord_length_);

    if (i == cord_length_) {
        return '\0';
    }

    // leaf node
    if (R->left == NULL && R->right == NULL) {
        return R->data[i];
    }

    // concatenation node
    size_t left_child_length = R->left->len;

    if (i >= left_child_length) {
        return cord_charat(R->right, i - left_child_length);
    } else {
        return cord_charat(R->left, i);
    }
}

/**
 * @brief Gets a substring of an existing cord
 *
 * @param[in] R   A cord
 * @param[in] lo  The low index of the substring, inclusive
 * @param[in] hi  The high index of the substring, exclusive
 * @return A cord representing the substring R[lo..hi-1]
 *
 * @requires lo and hi are valid indexes in R, with lo <= hi
 */
const cord_t *cord_sub(const cord_t *R, size_t lo, size_t hi) {
    assert(lo <= hi && hi <= cord_length(R));

    if (lo == hi) {
        return NULL;
    }

    // use existing cord node
    if (lo == 0 && hi == R->len) {
        return R;
    }

    // leaf node
    if (R->left == NULL && R->right == NULL) {
        char *new_str = xmalloc(sizeof(char) * (hi - lo));
        strncpy(new_str, R->data + lo, hi - lo);
        new_str[hi - lo] = '\0';

        return cord_new(new_str);
    }

    // concatenation code
    const cord_t *left_sub = NULL;
    const cord_t *right_sub = NULL;

    size_t left_child_length = cord_length(R->left);

    if (lo < left_child_length) {
        size_t min_ = left_child_length;
        if (hi < min_)
            min_ = hi;

        left_sub = cord_sub(R->left, lo, min_);
    }

    if (hi > left_child_length) {
        size_t max_ = left_child_length;
        if (lo > max_)
            max_ = lo;

        right_sub = cord_sub(R->right, max_ - left_child_length,
                             hi - left_child_length);
    }

    return cord_join(left_sub, right_sub);
}
