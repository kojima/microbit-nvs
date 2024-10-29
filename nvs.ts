/**
 * NVS blocks
 * icon: http://fontawesome.io/icons
 */
//% weight=100 color=#696969 icon="\uf1b2" block="NVS"
namespace nvs {

    let simMap: any = null

    //% blockId="flash pairs stored" block="flash pairs stored"
    //% shim=nvs::size
    export function size(): number {
        return simMap ? simMap.size : 0;
    }

    //% blockId="flash remove key" block="flash remove key %key"
    //% shim=nvs::remove
    export function remove(key: string): void {
        if (simMap) simMap.delete(key);
    }

    //% blockId="flash get buffer of key with size" block="flash get buffer of key %key with size %dataSize"
    //% shim=nvs::getBuffer
    export function getBuffer(key: string, dataSize: number): Buffer {
        return simMap && simMap[key] ? simMap[key] : -1;
    }

    //% blockId="flash put buffer for key" block="flash key %key's buffer as %data"
    //% shim=nvs::putBuffer
    export function putBuffer(key: string, data: Buffer) {
        if (!simMap) simMap = {};
        simMap[key] = data.toString();
    }
}