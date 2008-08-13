/*
 * Memphis - Cairo Rederer for OSM in C
 * Copyright (C) 2008  <marius.rieder@durchmesser.ch>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
 */


#ifndef LIST_H
#define LIST_H

// Inserts
#define LL_INSERT_ID(node_,list)                        \
    do {                                                \
        __typeof__(list) _node = (node_);               \
        __typeof__(_node) _ptr, _prev;                  \
        for (_ptr = (list), _prev = NULL; _ptr;         \
             _prev = _ptr, _ptr = _ptr->next            \
        ) {                                             \
            if (_node->id <_ptr->id)                    \
                break;                                  \
        }                                               \
        _node->next = _ptr;                             \
        if (_prev)                                      \
            _prev->next = _node;                        \
        else                                            \
            (list) = _node;                             \
    } while (0)

#define LL_INSERT_KEY(node_,list)                       \
    do {                                                \
        __typeof__(list) _node = (node_);               \
        __typeof__(_node) _ptr, _prev;                  \
        for (_ptr = (list), _prev = NULL; _ptr;         \
             _prev = _ptr, _ptr = _ptr->next            \
        ) {                                             \
            if (strcmp(_node->key, _ptr->key) > 0)      \
                break;                                  \
        }                                               \
        _node->next = _ptr;                             \
        if (_prev)                                      \
            _prev->next = _node;                        \
        else                                            \
            (list) = _node;                             \
    } while (0)
   
#define LL_APPEND(node_,list)                           \
    do {                                                \
        __typeof__(list) _node = (node_);               \
        __typeof__(_node) *_nextptr = &(list);          \
        __typeof__(_node) _prev = NULL;                 \
        while (*_nextptr) {                             \
            _prev = *_nextptr;                          \
            _nextptr = &((*_nextptr)->next);            \
        }                                               \
        *_nextptr = _node;                              \
        _node->next = NULL;                             \
    } while (0)

// Search
#define LL_SEARCH_ID(list,target,result)                \
    do {                                                \
        for ((result) = (list); (result); (result) = (result)->next) { \
            int i = (result)->id - (target);            \
            if (i > 0)                                  \
                (result) = NULL;                        \
            if (i >= 0)                                 \
                break;                                  \
        }                                               \
    } while (0)

// LOOP
#define LIST_FOREACH(iter,list)                         \
    for ((iter) = (list); (iter); (iter) = (iter)->next)
        
#endif /* LIST_H */

/*
 * vim: expandtab shiftwidth=4:
 */