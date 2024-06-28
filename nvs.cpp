#include "pxt.h"

namespace nvs {
    
    //%
    void init() {
        KeyValuePair* firstTime = uBit.storage.get("boot");
    
        int stored;
    
        if(firstTime == NULL)
        {
            //this is the first boot after a flash. Store a value!
            stored = 1;
            uBit.storage.put("boot", (uint8_t *)&stored, sizeof(int));
            uBit.display.scroll("Stored!");
        }
        else
        {
            //this is not the first boot, scroll our stored value.
            memcpy(&stored, firstTime->value, sizeof(int));
            delete firstTime;
            uBit.display.scroll(stored);
        }
    }
}
