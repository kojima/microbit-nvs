/*
 * Reference: https://github.com/bsiever/microbit-pxt-flashstorage
 */
#include "pxt.h"
#include "MicroBit.h"

using namespace pxt;

namespace nvs {
    
    //% 
    String get(String key) {
        if(!key) return PSTR("");
        KeyValuePair *pair = uBit.storage.get(key->getUTF8Data());
        if (pair == NULL) {
            return PSTR("");
        } else{
            String s = PSTR((char*)pair->value) + '\0';
            delete pair;
            return s;
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
    void put(String key, String value) {
        if(!key) return;
        if(!value) {
            remove(key);
            return;
        }
        uBit.storage.put(
            key->getUTF8Data(),
            (uint8_t*)value->getUTF8Data(),
            value->getUTF8Size());
    }
}
