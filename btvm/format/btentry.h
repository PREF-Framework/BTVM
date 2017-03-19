#ifndef BTENTRY_H
#define BTENTRY_H

#include <memory>
#include <string>
#include <vector>
#include "../vm/vmvalue.h"

enum BTEndianness
{
    LittleEndian,
    BigEndian,
};

struct BTLocation
{
    BTLocation(): offset(0), size(0) { }
    BTLocation(uint64_t offset, uint64_t size): offset(offset), size(size) { }

    uint64_t offset;
    uint64_t size;
};

struct BTEntry
{
    BTEntry() { }
    BTEntry(const VMValuePtr& value, size_t endianness): name(value->value_id), value(value), endianness(endianness), backcolor(0xFFFFFFFF), forecolor(0xFFFFFFFF) { }

    std::string name;
    VMValuePtr value;
    BTLocation location;
    size_t endianness;
    uint32_t backcolor;
    uint32_t forecolor;
    std::vector< std::shared_ptr<BTEntry> > children;
};

typedef std::shared_ptr<BTEntry> BTEntryPtr;
typedef std::vector<BTEntryPtr> BTEntryList;


#endif // BTENTRY_H
