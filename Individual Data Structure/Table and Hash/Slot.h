#ifndef __SLOT_H__
#define __SLOT_H__

#include "Person.h"

typedef int Key;        // 주민등록번호
typedef Person * Value;

enum SlotStatus {EMPTY, DELETED, INUSE};

typedef struct _slot {
    Key key;
    Value val;
    enum SlotStatus status;
} Slot;

#endif
