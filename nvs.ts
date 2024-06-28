/**
 * NVS blocks
 * icon: http://fontawesome.io/icons
 */
//% weight=100 color=#696969 icon="\uf1b2"
namespace nvs {

    let simMap: any = null

    //% blockId="flash pairs stored" block="flash pairs stored"
    //% shim=nvs::size
    export function size(): number {
        return simMap ? simMap.size : 0;
    }

    //% blockId="flash get or default" block="flash get %key or use %defaultValue if key not saved"
    export function getOrDefault(key: string, defaultValue: string): string {
        let value = get(key)
        return value.length == 0 ? defaultValue : value;
    }

    //% blockId="flash remove key" block="flash remove key %key"
    //% shim=nvs::remove
    export function remove(key: string): void {
        if (simMap) simMap.delete(key);
    }

    //% blockId="flash get key" block="flash get key %key"
    //% shim=nvs::get
    export function get(key: string): string {
        return simMap ? simMap[key] : "";
    }


    //% blockId="flash put value for key" block="flash key %key's value to %value"
    //% shim=nvs::put
    export function put(key: string, value: string) {
        if (!simMap) simMap = {};
        simMap[key] = value;
    }
}