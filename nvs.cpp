/*
 * Reference: https://github.com/bsiever/microbit-pxt-flashstorage
 */
#include "pxt.h"
#include "MicroBit.h"

using namespace pxt;

namespace nvs {
    
    //% 
    Buffer getBuffer(String key, int dataSize) {
        if(!key) return mkBuffer(NULL, 0);
        KeyValuePair *pair = uBit.storage.get(key->getUTF8Data());
        if (pair == NULL) {
            return mkBuffer(NULL, 0);
        } else{
            Buffer buf = mkBuffer((const uint8_t *)pair->value, dataSize);
            delete pair;
            return buf;
        }
    }

    //% 
    void remove(String key) {
        if(!key) return;
        uBit.storage.remove(key->getUTF8Data());
    }

    //% 
    int size() {
        int size = uBit.storage.size();
        return size;
    }

    //%
    void putBuffer(String key, Buffer buf) {
        if(!key) return;
        uBit.storage.put(
            key->getUTF8Data(),
            buf->data,
            buf->length);        
    }
}
