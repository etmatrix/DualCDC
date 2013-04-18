
/*********************************************************************
 * Descriptor specific type definitions are defined in:
 * usb_device.h
 *
 * Configuration options are defined in:
 * usb_config.h
 ********************************************************************/
#ifndef __USB_DESCRIPTORS_C
#define __USB_DESCRIPTORS_C
 
/** INCLUDES *******************************************************/
#include "USB/usb.h"
#include "USB/usb_function_cdc.h"

/** CONSTANTS ******************************************************/
/* Device Descriptor */
const USB_DEVICE_DESCRIPTOR device_dsc=
{
    0x12, // Size of this descriptor in bytes
    USB_DESCRIPTOR_DEVICE, // DEVICE descriptor type
    0x0200, // USB Spec Release Number in BCD format
    0xEF, // Class Code
    0x02, // Subclass code
    0x01, // Protocol code
    USB_EP0_BUFF_SIZE, // Max packet size for EP0, see usb_config.h
    0x04D8, // Vendor ID
    0xdead, // Product ID: CDC RS-232 Emulation Demo
    0x0001, // Device release number in BCD format
    0x01, // Manufacturer string index
    0x02, // Product string index
    0x00, // Device serial number string index
    0x01 // Number of possible configurations
};

/* Configuration 1 Descriptor */
const BYTE configDescriptor1[]={
    /* Configuration Descriptor */
    0x09,//sizeof(USB_CFG_DSC), // Size of this descriptor in bytes
    USB_DESCRIPTOR_CONFIGURATION, // CONFIGURATION descriptor type
    141,0, // Total length of data for this cfg
    4, // Number of interfaces in this cfg
    1, // Index value of this configuration
    0, // Configuration string index
    _DEFAULT | _SELF, // Attributes, see usb_device.h
    250, // Max power consumption (2X mA)

    /* IAD - Interface Association Descriptor */
    8, // Length
    0x0B,	// IAD Constant
    0,	// First Interface
    2,  // Number of Interfaces
    COMM_INTF, // Class code of first interface
    ABSTRACT_CONTROL_MODEL, // Subclass code of first interface
    V25TER, // Protocol code of first interface
    0, // Interface string index

    /* Interface Descriptor CDC1*/
    9,//sizeof(USB_INTF_DSC), // Size of this descriptor in bytes
    USB_DESCRIPTOR_INTERFACE, // INTERFACE descriptor type
    0, // Interface Number
    0, // Alternate Setting Number
    1, // Number of endpoints in this intf
    COMM_INTF, // Class code
    ABSTRACT_CONTROL_MODEL, // Subclass code
    V25TER, // Protocol code
    0, // Interface string index

    /* CDC Class-Specific Descriptors */
    sizeof(USB_CDC_HEADER_FN_DSC),
    CS_INTERFACE,
    DSC_FN_HEADER,
    0x10,0x01,

    sizeof(USB_CDC_ACM_FN_DSC),
    CS_INTERFACE,
    DSC_FN_ACM,
    USB_CDC_ACM_FN_DSC_VAL,

    sizeof(USB_CDC_UNION_FN_DSC),
    CS_INTERFACE,
    DSC_FN_UNION,
    CDC1_COMM_INTF_ID,
    CDC1_DATA_INTF_ID,

    sizeof(USB_CDC_CALL_MGT_FN_DSC),
    CS_INTERFACE,
    DSC_FN_CALL_MGT,
    0x00,
    CDC1_DATA_INTF_ID,

    /* Endpoint Descriptor */
    //sizeof(USB_EP_DSC),DSC_EP,_EP02_IN,_INT,CDC_INT_EP_SIZE,0x02,
    0x07,/*sizeof(USB_EP_DSC)*/
    USB_DESCRIPTOR_ENDPOINT, //Endpoint Descriptor
    _EP02_IN, //EndpointAddress
    _INTERRUPT, //Attributes
    0x08,0x00, //size
    0x02, //Interval

    /* Interface Descriptor */
    9,//sizeof(USB_INTF_DSC), // Size of this descriptor in bytes
    USB_DESCRIPTOR_INTERFACE, // INTERFACE descriptor type
    1, // Interface Number
    0, // Alternate Setting Number
    2, // Number of endpoints in this intf
    DATA_INTF, // Class code
    0, // Subclass code
    NO_PROTOCOL, // Protocol code
    0, // Interface string index

    /* Endpoint Descriptor */
    //sizeof(USB_EP_DSC),DSC_EP,_EP03_OUT,_BULK,CDC_BULK_OUT_EP_SIZE,0x00,
    0x07,/*sizeof(USB_EP_DSC)*/
    USB_DESCRIPTOR_ENDPOINT, //Endpoint Descriptor
    _EP03_OUT, //EndpointAddress
    _BULK, //Attributes
    0x40,0x00, //size
    0x00, //Interval

    /* Endpoint Descriptor */
    //sizeof(USB_EP_DSC),DSC_EP,_EP03_IN,_BULK,CDC_BULK_IN_EP_SIZE,0x00
    0x07,/*sizeof(USB_EP_DSC)*/
    USB_DESCRIPTOR_ENDPOINT, //Endpoint Descriptor
    _EP03_IN, //EndpointAddress
    _BULK, //Attributes
    0x40,0x00, //size
    0x00, //Interval

    /* ---------- BEGIN CDC2 DESCRIPTOR ------------ */

    /* IAD - Interface Association Descriptor */
    8, // Length
    0x0B,	// IAD Constant
    2,  // First Interface
    2,  // Number of Interfaces
    COMM_INTF, // Class code of first interface
    ABSTRACT_CONTROL_MODEL, // Subclass code of first interface
    V25TER, // Protocol code of first interface
    0, // Interface string index

    /* Interface Descriptor CDC2 Control */
    9,//sizeof(USB_INTF_DSC), // Size of this descriptor in bytes
    USB_DESCRIPTOR_INTERFACE, // INTERFACE descriptor type
    2, // Interface Number
    0, // Alternate Setting Number
    1, // Number of endpoints in this intf
    COMM_INTF, // Class code
    ABSTRACT_CONTROL_MODEL, // Subclass code
    V25TER, // Protocol code
    0, // Interface string index

    /* CDC Class-Specific Descriptors */
    sizeof(USB_CDC_HEADER_FN_DSC),
    CS_INTERFACE,
    DSC_FN_HEADER,
    0x10,0x01,

    sizeof(USB_CDC_ACM_FN_DSC),
    CS_INTERFACE,
    DSC_FN_ACM,
    USB_CDC_ACM_FN_DSC_VAL,

    sizeof(USB_CDC_UNION_FN_DSC),
    CS_INTERFACE,
    DSC_FN_UNION,
    CDC2_COMM_INTF_ID,
    CDC2_DATA_INTF_ID,

    sizeof(USB_CDC_CALL_MGT_FN_DSC),
    CS_INTERFACE,
    DSC_FN_CALL_MGT,
    0x00,
    CDC2_DATA_INTF_ID,

    /* Endpoint Descriptor CDC2 Control */
    //sizeof(USB_EP_DSC),DSC_EP,_EP02_IN,_INT,CDC_INT_EP_SIZE,0x02,
    0x07,/*sizeof(USB_EP_DSC)*/
    USB_DESCRIPTOR_ENDPOINT, //Endpoint Descriptor
    _EP04_IN, //EndpointAddress
    _INTERRUPT, //Attributes
    0x08,0x00, //size
    0x02, //Interval

    /* Interface Descriptor CDC2 Data */
    9,//sizeof(USB_INTF_DSC), // Size of this descriptor in bytes
    USB_DESCRIPTOR_INTERFACE, // INTERFACE descriptor type
    3, // Interface Number
    0, // Alternate Setting Number
    2, // Number of endpoints in this intf
    DATA_INTF, // Class code
    0, // Subclass code
    NO_PROTOCOL, // Protocol code
    0, // Interface string index

    /* Endpoint Descriptor CDC2 Data OUT*/
    //sizeof(USB_EP_DSC),DSC_EP,_EP03_OUT,_BULK,CDC_BULK_OUT_EP_SIZE,0x00,
    0x07,/*sizeof(USB_EP_DSC)*/
    USB_DESCRIPTOR_ENDPOINT, //Endpoint Descriptor
    _EP05_OUT, //EndpointAddress
    _BULK, //Attributes
    0x40,0x00, //size
    0x00, //Interval

    /* Endpoint Descriptor CDC2 Data IN*/
    //sizeof(USB_EP_DSC),DSC_EP,_EP03_IN,_BULK,CDC_BULK_IN_EP_SIZE,0x00
    0x07,/*sizeof(USB_EP_DSC)*/
    USB_DESCRIPTOR_ENDPOINT, //Endpoint Descriptor
    _EP05_IN, //EndpointAddress
    _BULK, //Attributes
    0x40,0x00, //size
    0x00, //Interval
};

//Language code string descriptor
const struct{BYTE bLength;BYTE bDscType;WORD string[1];}sd000={
sizeof(sd000),USB_DESCRIPTOR_STRING,{0x0409}};

//Manufacturer string descriptor
const struct{BYTE bLength;BYTE bDscType;WORD string[8];}sd001={
sizeof(sd001),USB_DESCRIPTOR_STRING,
{'E','T','M','a','t','r','i','x'}};

//Product string descriptor
const struct{BYTE bLength;BYTE bDscType;WORD string[8];}sd002={
sizeof(sd002),USB_DESCRIPTOR_STRING,
{'D','u','a','l',' ','C','D','C'}};

//Array of configuration descriptors
const BYTE * USB_CD_Ptr[]=
{
    (const BYTE *)&configDescriptor1
};
//Array of string descriptors
const BYTE *USB_SD_Ptr[]=
{
    (const BYTE *)&sd000,
    (const BYTE *)&sd001,
    (const BYTE *)&sd002
};

#endif
/** EOF usb_descriptors.c ****************************************************/
