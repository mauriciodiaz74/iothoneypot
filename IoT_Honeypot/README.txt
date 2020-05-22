HOW TO TEST de IoT devices:

Once inside a device:

Commands:

info
(general info about the system)

help
(more commands)

ifconfig
(to query hardware address)

txtsnd
(to send a message to other interface)

EXAMPLE:
In the receiver device:
ifconfig
iface 5 HWaddr: 06:21:63:6c:2b:10
        L2-PDU:1500 Source address length: 6

In the sender device:
txtsnd 5 06:21:63:6c:2b:10 TESTING_TAP-1_INTERFACE

In the receiver device:
 PKTDUMP: data received:
~~ SNIP 0 - size 23 byte, type: NETTTYPE_UNDEF (0)
00000000  54  45  53  54  49  4E  47  5F  54  41  50  2D  31  5F  49  4E
00000010  54  45  52  46  41  43  45

Note: The message is received in HEX. So, you should convert it in order to read it.

One site to convert Hex: http://www.unit-conversion.info/texttools/hexadecimal/

Mauricio Diaz
