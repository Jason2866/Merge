/*
  xdrv_23_zigbee_constants.ino - zigbee support for Tasmota

  Copyright (C) 2020  Theo Arends and Stephan Hadinger

  This program is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifdef USE_ZIGBEE

#if defined(USE_ZIGBEE_ZNP) && defined(USE_ZIGBEE_EZSP)
  #error "#define USE_ZIGBEE_ZNP and #define USE_ZIGBEE_EZSP are mutually incompatible"
#endif
#if !defined(USE_ZIGBEE_ZNP) && !defined(USE_ZIGBEE_EZSP)
  #error "You must select one of: #define USE_ZIGBEE_ZNP or #define USE_ZIGBEE_EZSP"
#endif

#define OCCUPANCY "Occupancy"             // global define for Aqara
#define ZIGBEE_EZSP_RESET_LED     4       // Led<x> number to drive the EZSP Reset pin

typedef uint64_t Z_IEEEAddress;
typedef uint16_t Z_ShortAddress;

const uint16_t BAD_SHORTADDR = 0xFFFE;

#ifdef USE_ZIGBEE_ZNP
enum ZnpCommandType {
  Z_POLL = 0x00,
  Z_SREQ = 0x20,
  Z_AREQ = 0x40,
  Z_SRSP = 0x60
};

enum ZnpSubsystem {
  Z_RPC_Error = 0x00,
  Z_SYS = 0x01,
  Z_MAC = 0x02,
  Z_NWK = 0x03,
  Z_AF = 0x04,
  Z_ZDO = 0x05,
  Z_SAPI = 0x06,
  Z_UTIL = 0x07,
  Z_DEBUG = 0x08,
  Z_APP = 0x09
};
#endif // USE_ZIGBEE_ZNP

#ifdef USE_ZIGBEE_EZSP

enum EZSPNodeType {
  EMBER_UNKNOWN_DEVICE = 0x00,
  EMBER_COORDINATOR = 0x01,
  EMBER_ROUTER = 0x02,
  EMBER_END_DEVICE = 0x03,
  EMBER_SLEEPY_END_DEVICE = 0x04
};

enum EZSPDeviceUpdate {
  EMBER_STANDARD_SECURITY_SECURED_REJOIN = 0x00,
  EMBER_STANDARD_SECURITY_UNSECURED_JOIN = 0x01,
  EMBER_DEVICE_LEFT = 0x02,
  EMBER_STANDARD_SECURITY_UNSECURED_REJOIN = 0x03,
};

enum EZSPJoinDecision {
  EMBER_USE_PRECONFIGURED_KEY = 0x00,
  EMBER_SEND_KEY_IN_THE_CLEAR = 0x01,
  EMBER_DENY_JOIN = 0x02,
  EMBER_NO_ACTION = 0x03
};

enum EZSPCurrentSecurytBitMask {
  EMBER_STANDARD_SECURITY_MODE = 0x0000,
  EMBER_DISTRIBUTED_TRUST_CENTER_MODE = 0x0002,
  EMBER_GLOBAL_LINK_KEY = 0x0004,
  EMBER_TRUST_CENTER_GLOBAL_LINK_KEY = 0x0004,
  EMBER_PRECONFIGURED_NETWORK_KEY_MODE = 0x0008,
  EMBER_HAVE_TRUST_CENTER_LINK_KEY = 0x0010,
  EMBER_TRUST_CENTER_USES_HASHED_LINK_KEY = 0x0084,
  EMBER_HAVE_PRECONFIGURED_KEY = 0x0100,
  EMBER_HAVE_NETWORK_KEY = 0x0200,
  EMBER_GET_LINK_KEY_WHEN_JOINING = 0x0400,
  EMBER_REQUIRE_ENCRYPTED_KEY = 0x0800,
  EMBER_NO_FRAME_COUNTER_RESET = 0x1000,
  EMBER_GET_PRECONFIGURED_KEY_FROM_INSTALL_CODE = 0x2000,
  EMBER_HAVE_TRUST_CENTER_EUI64 = 0x0040
};

enum EZSPJoinMethod {
  EMBER_USE_MAC_ASSOCIATION = 0x0,
  EMBER_USE_NWK_REJOIN = 0x1,
  EMBER_USE_NWK_REJOIN_HAVE_NWK_KEY = 0x2,
  EMBER_USE_CONFIGURED_NWK_STATE = 0x3
};

enum EZSPConfigId {
  EZSP_CONFIG_PACKET_BUFFER_COUNT = 0x01,
  EZSP_CONFIG_NEIGHBOR_TABLE_SIZE = 0x02,
  EZSP_CONFIG_APS_UNICAST_MESSAGE_COUNT = 0x03,
  EZSP_CONFIG_BINDING_TABLE_SIZE = 0x04,
  EZSP_CONFIG_ADDRESS_TABLE_SIZE = 0x05,
  EZSP_CONFIG_MULTICAST_TABLE_SIZE = 0x06,
  EZSP_CONFIG_ROUTE_TABLE_SIZE = 0x07,
  EZSP_CONFIG_DISCOVERY_TABLE_SIZE = 0x08,
  EZSP_CONFIG_STACK_PROFILE = 0x0C,
  EZSP_CONFIG_SECURITY_LEVEL = 0x0D,
  EZSP_CONFIG_MAX_HOPS = 0x10,
  EZSP_CONFIG_MAX_END_DEVICE_CHILDREN = 0x11,
  EZSP_CONFIG_INDIRECT_TRANSMISSION_TIMEOUT = 0x12,
  EZSP_CONFIG_END_DEVICE_POLL_TIMEOUT = 0x13,
  EZSP_CONFIG_TX_POWER_MODE = 0x17,
  EZSP_CONFIG_DISABLE_RELAY = 0x18,
  EZSP_CONFIG_TRUST_CENTER_ADDRESS_CACHE_SIZE = 0x19,
  EZSP_CONFIG_SOURCE_ROUTE_TABLE_SIZE = 0x1A,
  EZSP_CONFIG_FRAGMENT_WINDOW_SIZE = 0x1C,
  EZSP_CONFIG_FRAGMENT_DELAY_MS = 0x1D,
  EZSP_CONFIG_KEY_TABLE_SIZE = 0x1E,
  EZSP_CONFIG_APS_ACK_TIMEOUT = 0x1F,
  EZSP_CONFIG_BEACON_JITTER_DURATION = 0x20,
  EZSP_CONFIG_END_DEVICE_BIND_TIMEOUT = 0x21,
  EZSP_CONFIG_PAN_ID_CONFLICT_REPORT_THRESHOLD = 0x22,
  EZSP_CONFIG_REQUEST_KEY_TIMEOUT = 0x24,
  EZSP_CONFIG_CERTIFICATE_TABLE_SIZE = 0x29,
  EZSP_CONFIG_APPLICATION_ZDO_FLAGS = 0x2A,
  EZSP_CONFIG_BROADCAST_TABLE_SIZE = 0x2B,
  EZSP_CONFIG_MAC_FILTER_TABLE_SIZE = 0x2C,
  EZSP_CONFIG_SUPPORTED_NETWORKS = 0x2D,
  EZSP_CONFIG_SEND_MULTICASTS_TO_SLEEPY_ADDRESS = 0x2E,
  EZSP_CONFIG_ZLL_GROUP_ADDRESSES = 0x2F,
  EZSP_CONFIG_ZLL_RSSI_THRESHOLD = 0x30,
  EZSP_CONFIG_MTORR_FLOW_CONTROL = 0x33,
  EZSP_CONFIG_RETRY_QUEUE_SIZE = 0x34,
  EZSP_CONFIG_NEW_BROADCAST_ENTRY_THRESHOLD = 0x35,
  EZSP_CONFIG_BROADCAST_MIN_ACKS_NEEDED = 0x37,
  EZSP_CONFIG_TC_REJOINS_USING_WELL_KNOWN_KEY_TIMEOUT_S = 0x38,
  EZSP_CONFIG_CTUNE_VALUE = 0x39
};

enum EZSPValueId {
  EZSP_VALUE_TOKEN_STACK_NODE_DATA = 0x00,
  EZSP_VALUE_MAC_PASSTHROUGH_FLAGS = 0x01,
  EZSP_VALUE_EMBERNET_PASSTHROUGH_SOURCE_ADDRESS = 0x02,
  EZSP_VALUE_FREE_BUFFERS = 0x03,
  EZSP_VALUE_UART_SYNCH_CALLBACKS = 0x04,
  EZSP_VALUE_MAXIMUM_INCOMING_TRANSFER_SIZE = 0x05,
  EZSP_VALUE_MAXIMUM_OUTGOING_TRANSFER_SIZE = 0x06,
  EZSP_VALUE_STACK_TOKEN_WRITING = 0x07,
  EZSP_VALUE_STACK_IS_PERFORMING_REJOIN = 0x08,
  EZSP_VALUE_MAC_FILTER_LIST = 0x09,
  EZSP_VALUE_EXTENDED_SECURITY_BITMASK = 0x0A,
  EZSP_VALUE_NODE_SHORT_ID = 0x0B,
  EZSP_VALUE_DESCRIPTOR_CAPABILITY = 0x0C,
  EZSP_VALUE_STACK_DEVICE_REQUEST_SEQUENCE_NUMBER = 0x0D,
  EZSP_VALUE_RADIO_HOLD_OFF = 0x0E,
  EZSP_VALUE_ENDPOINT_FLAGS = 0x0F,
  EZSP_VALUE_MFG_SECURITY_CONFIG = 0x10,
  EZSP_VALUE_VERSION_INFO = 0x11,
  EZSP_VALUE_NEXT_HOST_REJOIN_REASON = 0x12,
  EZSP_VALUE_LAST_REJOIN_REASON = 0x13,
  EZSP_VALUE_NEXT_ZIGBEE_SEQUENCE_NUMBER = 0x14,
  EZSP_VALUE_CCA_THRESHOLD = 0x15,
  EZSP_VALUE_SET_COUNTER_THRESHOLD = 0x17,
  EZSP_VALUE_RESET_COUNTER_THRESHOLDS = 0x18,
  EZSP_VALUE_CLEAR_COUNTERS = 0x19,
  EZSP_VALUE_CERTIFICATE_283K1 = 0x1A,
  EZSP_VALUE_PUBLIC_KEY_283K1 = 0x1B,
  EZSP_VALUE_PRIVATE_KEY_283K1 = 0x1C,
  EZSP_VALUE_NWK_FRAME_COUNTER = 0x23,
  EZSP_VALUE_APS_FRAME_COUNTER = 0x24,
  EZSP_VALUE_RETRY_DEVICE_TYPE = 0x25,
  EZSP_VALUE_ENABLE_R21_BEHAVIOR = 0x29,
  EZSP_VALUE_ANTENNA_MODE = 0x30,
  EZSP_VALUE_ENABLE_PTA = 0x31,
  EZSP_VALUE_PTA_OPTIONS = 0x32,
  EZSP_VALUE_MFGLIB_OPTIONS = 0x33,
  EZSP_VALUE_USE_NEGOTIATED_POWER_BY_LPD = 0x34,
  EZSP_VALUE_PTA_PWM_OPTIONS = 0x35,
  EZSP_VALUE_PTA_DIRECTIONAL_PRIORITY_PULSE_WIDTH = 0x36,
  EZSP_VALUE_PTA_PHY_SELECT_TIMEOUT = 0x37,
  EZSP_VALUE_ANTENNA_RX_MODE = 0x38,
  EZSP_VALUE_NWK_KEY_TIMEOUT = 0x39,
  EZSP_VALUE_FORCE_TX_AFTER_FAILED_CCA_ATTEMPTS = 0x3A,
  EZSP_VALUE_TRANSIENT_KEY_TIMEOUT_S = 0x3B,
  ZSP_VALUE_COULOMB_COUNTER_USAGE = 0x3C,
  EZSP_VALUE_MAX_BEACONS_TO_STORE = 0x3D,
  EZSP_VALUE_END_DEVICE_TIMEOUT_OPTIONS_MASK = 0x3E,
  EZSP_VALUE_END_DEVICE_KEEP_ALIVE_SUPPORT_MODE = 0x3F,
  EZSP_VALUE_GPIO_RADIO_POWER_MASK = 0x40,
  EZSP_VALUE_ACTIVE_RADIO_CONFIG = 0x41
};

enum EZSPEmberStatusId {
  EMBER_SUCCESS = 0x00,
  EMBER_ERR_FATAL = 0x01,
  EMBER_BAD_ARGUMENT = 0x02,
  EMBER_EEPROM_MFG_STACK_VERSION_MISMATCH = 0x04,
  EMBER_INCOMPATIBLE_STATIC_MEMORY_DEFINITIONS = 0x05,
  EMBER_EEPROM_MFG_VERSION_MISMATCH = 0x06,
  EMBER_EEPROM_STACK_VERSION_MISMATCH = 0x07,
  EMBER_NO_BUFFERS = 0x18,
  EMBER_SERIAL_INVALID_BAUD_RATE = 0x20,
  EMBER_SERIAL_INVALID_PORT = 0x21,
  EMBER_SERIAL_TX_OVERFLOW = 0x22,
  EMBER_SERIAL_RX_OVERFLOW = 0x23,
  EMBER_SERIAL_RX_FRAME_ERROR = 0x24,
  EMBER_SERIAL_RX_PARITY_ERROR = 0x25,
  EMBER_SERIAL_RX_EMPTY = 0x26,
  EMBER_SERIAL_RX_OVERRUN_ERROR = 0x27,
  EMBER_MAC_TRANSMIT_QUEUE_FULL = 0x39,
  EMBER_MAC_UNKNOWN_HEADER_TYPE = 0x3A,
  EMBER_MAC_SCANNING = 0x3D,
  EMBER_MAC_NO_DATA = 0x31,
  EMBER_MAC_JOINED_NETWORK = 0x32,
  EMBER_MAC_BAD_SCAN_DURATION = 0x33,
  EMBER_MAC_INCORRECT_SCAN_TYPE = 0x34,
  EMBER_MAC_INVALID_CHANNEL_MASK = 0x35,
  EMBER_MAC_COMMAND_TRANSMIT_FAILURE = 0x36,
  EMBER_MAC_NO_ACK_RECEIVED = 0x40,
  EMBER_MAC_INDIRECT_TIMEOUT = 0x42,
  EMBER_SIM_EEPROM_ERASE_PAGE_GREEN = 0x43,
  EMBER_SIM_EEPROM_ERASE_PAGE_RED = 0x44,
  EMBER_SIM_EEPROM_FULL = 0x45,
  EMBER_ERR_FLASH_WRITE_INHIBITED = 0x46,
  EMBER_ERR_FLASH_VERIFY_FAILED = 0x47,
  EMBER_SIM_EEPROM_INIT_1_FAILED = 0x48,
  EMBER_SIM_EEPROM_INIT_2_FAILED = 0x49,
  EMBER_SIM_EEPROM_INIT_3_FAILED = 0x4A,
  EMBER_ERR_FLASH_PROG_FAIL = 0x4B,
  EMBER_ERR_FLASH_ERASE_FAIL = 0x4C,
  EMBER_ERR_BOOTLOADER_TRAP_TABLE_BAD = 0x58,
  EMBER_ERR_BOOTLOADER_TRAP_UNKNOWN = 0x59,
  EMBER_ERR_BOOTLOADER_NO_IMAGE = 0x5A,
  EMBER_DELIVERY_FAILED = 0x66,
  EMBER_BINDING_INDEX_OUT_OF_RANGE = 0x69,
  EMBER_ADDRESS_TABLE_INDEX_OUT_OF_RANGE = 0x6A,
  EMBER_INVALID_BINDING_INDEX = 0x6C,
  EMBER_INVALID_CALL = 0x70,
  EMBER_COST_NOT_KNOWN = 0x71,
  EMBER_MAX_MESSAGE_LIMIT_REACHED = 0x72,
  EMBER_MESSAGE_TOO_LONG = 0x74,
  EMBER_BINDING_IS_ACTIVE = 0x75,
  EMBER_ADDRESS_TABLE_ENTRY_IS_ACTIVE = 0x76,
  EMBER_ADC_CONVERSION_DONE = 0x80,
  EMBER_ADC_CONVERSION_BUSY = 0x81,
  EMBER_ADC_CONVERSION_DEFERRED = 0x82,
  EMBER_ADC_NO_CONVERSION_PENDING = 0x84,
  EMBER_SLEEP_INTERRUPTED = 0x85,
  EMBER_PHY_TX_UNDERFLOW = 0x88,
  EMBER_PHY_TX_INCOMPLETE = 0x89,
  EMBER_PHY_INVALID_CHANNEL = 0x8A,
  EMBER_PHY_INVALID_POWER = 0x8B,
  EMBER_PHY_TX_BUSY = 0x8C,
  EMBER_PHY_TX_CCA_FAIL = 0x8D,
  EMBER_PHY_OSCILLATOR_CHECK_FAILED = 0x8E,
  EMBER_PHY_ACK_RECEIVED = 0x8F,
  EMBER_NETWORK_UP = 0x90,
  EMBER_NETWORK_DOWN = 0x91,
  EMBER_JOIN_FAILED = 0x94,
  EMBER_MOVE_FAILED = 0x96,
  EMBER_CANNOT_JOIN_AS_ROUTER = 0x98,
  EMBER_NODE_ID_CHANGED = 0x99,
  EMBER_PAN_ID_CHANGED = 0x9A,
  EMBER_NO_BEACONS = 0xAB,
  EMBER_RECEIVED_KEY_IN_THE_CLEAR = 0xAC,
  EMBER_NO_NETWORK_KEY_RECEIVED = 0xAD,
  EMBER_NO_LINK_KEY_RECEIVED = 0xAE,
  EMBER_PRECONFIGURED_KEY_REQUIRED = 0xAF,
  EMBER_NOT_JOINED = 0x93,
  EMBER_INVALID_SECURITY_LEVEL = 0x95,
  EMBER_NETWORK_BUSY = 0xA1,
  EMBER_INVALID_ENDPOINT = 0xA3,
  EMBER_BINDING_HAS_CHANGED = 0xA4,
  EMBER_INSUFFICIENT_RANDOM_DATA = 0xA5,
  EMBER_APS_ENCRYPTION_ERROR = 0xA6,
  EMBER_SECURITY_STATE_NOT_SET = 0xA8,
  EMBER_KEY_TABLE_INVALID_ADDRESS = 0xB3,
  EMBER_SECURITY_CONFIGURATION_INVALID = 0xB7,
  EMBER_TOO_SOON_FOR_SWITCH_KEY = 0xB8,
  EMBER_KEY_NOT_AUTHORIZED = 0xBB,
  EMBER_SECURITY_DATA_INVALID = 0xBD,
  EMBER_SOURCE_ROUTE_FAILURE = 0xA9,
  EMBER_MANY_TO_ONE_ROUTE_FAILURE = 0xAA,
  EMBER_STACK_AND_HARDWARE_MISMATCH = 0xB0,
  EMBER_INDEX_OUT_OF_RANGE = 0xB1,
  EMBER_TABLE_FULL = 0xB4,
  EMBER_TABLE_ENTRY_ERASED = 0xB6,
  EMBER_LIBRARY_NOT_PRESENT = 0xB5,
  EMBER_OPERATION_IN_PROGRESS = 0xBA,
};

enum EZSPStatusId {
  EZSP_SUCCESS = 0x00,
  EZSP_SPI_ERR_FATAL = 0x10,
  EZSP_SPI_ERR_NCP_RESET = 0x11,
  EZSP_SPI_ERR_OVERSIZED_EZSP_FRAME = 0x12,
  EZSP_SPI_ERR_ABORTED_TRANSACTION = 0x13,
  EZSP_SPI_ERR_MISSING_FRAME_TERMINATOR = 0x14,
  EZSP_SPI_ERR_WAIT_SECTION_TIMEOUT = 0x15,
  EZSP_SPI_ERR_NO_FRAME_TERMINATOR = 0x16,
  EZSP_SPI_ERR_EZSP_COMMAND_OVERSIZED = 0x17,
  EZSP_SPI_ERR_EZSP_RESPONSE_OVERSIZED = 0x18,
  EZSP_SPI_WAITING_FOR_RESPONSE = 0x19,
  EZSP_SPI_ERR_HANDSHAKE_TIMEOUT = 0x1A,
  EZSP_SPI_ERR_STARTUP_TIMEOUT = 0x1B,
  EZSP_SPI_ERR_STARTUP_FAIL = 0x1C,
  EZSP_SPI_ERR_UNSUPPORTED_SPI_COMMAND = 0x1D,
  EZSP_ASH_IN_PROGRESS = 0x20,
  EZSP_HOST_FATAL_ERROR = 0x21,
  EZSP_ASH_NCP_FATAL_ERROR = 0x22,
  EZSP_DATA_FRAME_TOO_LONG = 0x23,
  EZSP_DATA_FRAME_TOO_SHORT = 0x24,
  EZSP_NO_TX_SPACE = 0x25,
  EZSP_NO_RX_SPACE = 0x26,
  EZSP_NO_RX_DATA = 0x27,
  EZSP_NOT_CONNECTED = 0x28,
  EZSP_ERROR_VERSION_NOT_SET = 0x30,
  EZSP_ERROR_INVALID_FRAME_ID = 0x31,
  EZSP_ERROR_WRONG_DIRECTION = 0x32,
  EZSP_ERROR_TRUNCATED = 0x33,
  EZSP_ERROR_OVERFLOW = 0x34,
  EZSP_ERROR_OUT_OF_MEMORY = 0x35,
  EZSP_ERROR_INVALID_VALUE = 0x36,
  EZSP_ERROR_INVALID_ID = 0x37,
  EZSP_ERROR_INVALID_CALL = 0x38,
  EZSP_ERROR_NO_RESPONSE = 0x39,
  EZSP_ERROR_COMMAND_TOO_LONG = 0x40,
  EZSP_ERROR_QUEUE_FULL = 0x41,
  EZSP_ERROR_COMMAND_FILTERED = 0x42,
  EZSP_ERROR_SECURITY_KEY_ALREADY_SET = 0x43,
  EZSP_ERROR_SECURITY_TYPE_INVALID = 0x44,
  EZSP_ERROR_SECURITY_PARAMETERS_INVALID = 0x45,
  EZSP_ERROR_SECURITY_PARAMETERS_ALREADY_SET = 0x46,
  EZSP_ERROR_SECURITY_KEY_NOT_SET = 0x47,
  EZSP_ERROR_SECURITY_PARAMETERS_NOT_SET = 0x48,
  EZSP_ERROR_UNSUPPORTED_CONTROL = 0x49,
  EZSP_ERROR_UNSECURE_FRAME = 0x4A,
  EZSP_NO_ERROR = 0xFF
};

enum EZSPPolicyId {
  EZSP_TRUST_CENTER_POLICY = 0x00,
  EZSP_BINDING_MODIFICATION_POLICY = 0x01,
  EZSP_UNICAST_REPLIES_POLICY = 0x02,
  EZSP_POLL_HANDLER_POLICY = 0x03,
  EZSP_MESSAGE_CONTENTS_IN_CALLBACK_POLICY = 0x04,
  EZSP_TC_KEY_REQUEST_POLICY = 0x05,
  EZSP_APP_KEY_REQUEST_POLICY = 0x06,
  EZSP_PACKET_VALIDATE_LIBRARY_POLICY = 0x07,
  EZSP_ZLL_POLICY = 0x08,
  EZSP_TC_REJOINS_USING_WELL_KNOWN_KEY_POLICY = 0x09
};

enum EZSPDecisionBitmask {
  EZSP_DECISION_BITMASK_DEFAULT_CONFIGURATION = 0x0000,
  EZSP_DECISION_ALLOW_JOINS = 0x0001,
  EZSP_DECISION_ALLOW_UNSECURED_REJOINS = 0x0002,
  EZSP_DECISION_SEND_KEY_IN_CLEAR = 0x0004,
  EZSP_DECISION_IGNORE_UNSECURED_REJOINS = 0x0008,
  EZSP_DECISION_JOINS_USE_INSTALL_CODE_KEY = 0x0010,
  EZSP_DECISION_DEFER_JOINS = 0x0020
};

enum EZSPDecisionId {
  EZSP_DEFER_JOINS_REJOINS_HAVE_LINK_KEY = 0x07,
  EZSP_DISALLOW_BINDING_MODIFICATION = 0x10,
  EZSP_ALLOW_BINDING_MODIFICATION = 0x11,
  EZSP_CHECK_BINDING_MODIFICATIONS_ARE_VALID_ENDPOINT_CLUSTERS = 0x12,
  EZSP_HOST_WILL_NOT_SUPPLY_REPLY = 0x20,
  EZSP_HOST_WILL_SUPPLY_REPLY = 0x21,
  EZSP_POLL_HANDLER_IGNORE = 0x30,
  EZSP_POLL_HANDLER_CALLBACK = 0x31,
  EZSP_MESSAGE_TAG_ONLY_IN_CALLBACK = 0x40,
  EZSP_MESSAGE_TAG_AND_CONTENTS_IN_CALLBACK = 0x41,
  EZSP_DENY_TC_KEY_REQUESTS = 0x50,
  EZSP_ALLOW_TC_KEY_REQUESTS_AND_SEND_CURRENT_KEY = 0x51,
  EZSP_ALLOW_TC_KEY_REQUEST_AND_GENERATE_NEW_KEY = 0x52,
  EZSP_DENY_APP_KEY_REQUESTS = 0x60,
  EZSP_ALLOW_APP_KEY_REQUESTS = 0x61,
  EZSP_PACKET_VALIDATE_LIBRARY_CHECKS_ENABLED = 0x62,
  EZSP_PACKET_VALIDATE_LIBRARY_CHECKS_DISABLED = 0x63
};

enum EZSP_ZdoConfigurationFlags {
  EMBER_APP_RECEIVES_SUPPORTED_ZDO_REQUESTS = 0x01,
  EMBER_APP_HANDLES_UNSUPPORTED_ZDO_REQUESTS = 0x02,
  EMBER_APP_HANDLES_ZDO_ENDPOINT_REQUESTS = 0x04,
  EMBER_APP_HANDLES_ZDO_BINDING_REQUESTS = 0x08
};

enum EZSP_EmberIncomingMessageType {
  EMBER_INCOMING_UNICAST = 0x00,
  EMBER_INCOMING_UNICAST_REPLY = 0x01,
  EMBER_INCOMING_MULTICAST = 0x02,
  EMBER_INCOMING_MULTICAST_LOOPBACK = 0x03,
  EMBER_INCOMING_BROADCAST = 0x04,
  EMBER_INCOMING_BROADCAST_LOOPBACK = 0x05,
  EMBER_INCOMING_MANY_TO_ONE_ROUTE_REQUEST = 0x06
};

enum EZSP_EmberApsOption {
  EMBER_APS_OPTION_NONE = 0x0000,
  EMBER_APS_OPTION_ENCRYPTION = 0x0020,
  EMBER_APS_OPTION_RETRY = 0x0040,
  EMBER_APS_OPTION_ENABLE_ROUTE_DISCOVERY = 0x0100,
  EMBER_APS_OPTION_FORCE_ROUTE_DISCOVERY = 0x0200,
  EMBER_APS_OPTION_SOURCE_EUI64 = 0x0400,
  EMBER_APS_OPTION_DESTINATION_EUI64 = 0x0800,
  EMBER_APS_OPTION_ENABLE_ADDRESS_DISCOVERY = 0x1000,
  EMBER_APS_OPTION_POLL_RESPONSE = 0x2000,
  EMBER_APS_OPTION_ZDO_RESPONSE_REQUIRED = 0x4000,
  EMBER_APS_OPTION_FRAGMENT = 0x8000
};

enum EZSP_EmberOutgoingMessageType {
  EMBER_OUTGOING_DIRECT = 0x00,
  EMBER_OUTGOING_VIA_ADDRESS_TABLE = 0x01,
  EMBER_OUTGOING_VIA_BINDING = 0x02,
  EMBER_OUTGOING_MULTICAST = 0x03,
  EMBER_OUTGOING_BROADCAST = 0x04
};

// inspired from https://github.com/zigpy/zigpy/blob/dev/zigpy/zdo/types.py
enum EZSP_ZDO {
  ZDO_NWK_addr_req = 0x0000,
  ZDO_IEEE_addr_req = 0x0001,
  ZDO_Node_Desc_req = 0x0002,
  ZDO_Power_Desc_req = 0x0003,
  ZDO_Simple_Desc_req = 0x0004,
  ZDO_Active_EP_req = 0x0005,
  ZDO_Match_Desc_req = 0x0006,
  ZDO_Complex_Desc_req = 0x0010,
  ZDO_User_Desc_req = 0x0011,
  ZDO_Discovery_Cache_req = 0x0012,
  ZDO_Device_annce = 0x0013,
  ZDO_User_Desc_set = 0x0014,
  ZDO_System_Server_Discovery_req = 0x0015,
  ZDO_Discovery_store_req = 0x0016,
  ZDO_Node_Desc_store_req = 0x0017,
  ZDO_Active_EP_store_req = 0x0019,
  ZDO_Simple_Desc_store_req = 0x001A,
  ZDO_Remove_node_cache_req = 0x001B,
  ZDO_Find_node_cache_req = 0x001C,
  ZDO_Extended_Simple_Desc_req = 0x001D,
  ZDO_Extended_Active_EP_req = 0x001E,
  ZDO_Parent_annce = 0x001F,
  // Bind Management Server Services Responses
  ZDO_End_Device_Bind_req = 0x0020,
  ZDO_Bind_req = 0x0021,
  ZDO_Unbind_req = 0x0022,
  // Network Management Server Services Requests
  ZDO_Mgmt_Lqi_req = 0x0031,
  ZDO_Mgmt_Rtg_req = 0x0032,
  ZDO_Mgmt_Leave_req = 0x0034,
  ZDO_Mgmt_Permit_Joining_req = 0x0036,
  ZDO_Mgmt_NWK_Update_req = 0x0038,

  // Responses
  // Device and Service Discovery Server Responses
  ZDO_NWK_addr_rsp = 0x8000,
  ZDO_IEEE_addr_rsp = 0x8001,
  ZDO_Node_Desc_rsp = 0x8002,
  ZDO_Power_Desc_rsp = 0x8003,
  ZDO_Simple_Desc_rsp = 0x8004,
  ZDO_Active_EP_rsp = 0x8005,
  ZDO_Match_Desc_rsp = 0x8006,
  ZDO_Complex_Desc_rsp = 0x8010,
  ZDO_User_Desc_rsp = 0x8011,
  ZDO_Discovery_Cache_rsp = 0x8012,
  ZDO_User_Desc_conf = 0x8014,
  ZDO_System_Server_Discovery_rsp = 0x8015,
  ZDO_Discovery_Store_rsp = 0x8016,
  ZDO_Node_Desc_store_rsp = 0x8017,
  ZDO_Power_Desc_store_rsp = 0x8018,
  ZDO_Active_EP_store_rsp = 0x8019,
  ZDO_Simple_Desc_store_rsp = 0x801A,
  ZDO_Remove_node_cache_rsp = 0x801B,
  ZDO_Find_node_cache_rsp = 0x801C,
  ZDO_Extended_Simple_Desc_rsp = 0x801D,
  ZDO_Extended_Active_EP_rsp = 0x801E,
  ZDO_Parent_annce_rsp = 0x801F,
  // Bind Management Server Services Responses
  ZDO_End_Device_Bind_rsp = 0x8020,
  ZDO_Bind_rsp = 0x8021,
  ZDO_Unbind_rsp = 0x8022,
  // Network Management Server Services Responses
  ZDO_Mgmt_Lqi_rsp = 0x8031,
  ZDO_Mgmt_Rtg_rsp = 0x8032,
  ZDO_Mgmt_Leave_rsp = 0x8034,
  ZDO_Mgmt_Permit_Joining_rsp = 0x8036,
  ZDO_Mgmt_NWK_Update_rsp = 0x8038,
};

enum EZSP_Commands {
  EZSP_version = 0x0000,
  EZSP_getLibraryStatus = 0x0001,
  EZSP_addEndpoint = 0x0002,
  EZSP_getExtendedValue = 0x0003,
  EZSP_getNextBeacon = 0x0004,
  EZSP_nop = 0x0005,
  EZSP_callback = 0x0006,
  EZSP_noCallbacks = 0x0007,
  EZSP_getNumStoredBeacons = 0x0008,
  EZSP_setToken = 0x0009,
  EZSP_getToken = 0x000A,
  EZSP_getMfgToken = 0x000B,
  EZSP_setMfgToken = 0x000C,
  EZSP_stackTokenChangedHandler = 0x000D,
  EZSP_setTimer = 0x000E,
  EZSP_timerHandler = 0x000F,
  EZSP_setConcentrator = 0x0010,
  EZSP_setBrokenRouteErrorCode = 0x0011,
  EZSP_debugWrite = 0x0012,
  EZSP_getXncpInfo = 0x0013,
  EZSP_requestLinkKey = 0x0014,
  EZSP_setManufacturerCode = 0x0015,
  EZSP_setPowerDescriptor = 0x0016,
  EZSP_networkInit = 0x0017,
  EZSP_networkState = 0x0018,
  EZSP_stackStatusHandler = 0x0019,
  EZSP_startScan = 0x001A,
  EZSP_networkFoundHandler = 0x001B,
  EZSP_scanCompleteHandler = 0x001C,
  EZSP_stopScan = 0x001D,
  EZSP_formNetwork = 0x001E,
  EZSP_joinNetwork = 0x001F,
  EZSP_leaveNetwork = 0x0020,
  EZSP_findAndRejoinNetwork = 0x0021,
  EZSP_permitJoining = 0x0022,
  EZSP_childJoinHandler = 0x0023,
  EZSP_trustCenterJoinHandler = 0x0024,
  EZSP_zllClearTokens = 0x0025,
  EZSP_getEui64 = 0x0026,
  EZSP_getNodeId = 0x0027,
  EZSP_getNetworkParameters = 0x0028,
  EZSP_getParentChildParameters = 0x0029,
  EZSP_clearBindingTable = 0x002A,
  EZSP_setBinding = 0x002B,
  EZSP_getBinding = 0x002C,
  EZSP_deleteBinding = 0x002D,
  EZSP_bindingIsActive = 0x002E,
  EZSP_getBindingRemoteNodeId = 0x002F,
  EZSP_setBindingRemoteNodeId = 0x0030,
  EZSP_remoteSetBindingHandler = 0x0031,
  EZSP_remoteDeleteBindingHandler = 0x0032,
  EZSP_maximumPayloadLength = 0x0033,
  EZSP_sendUnicast = 0x0034,
  EZSP_getDutyCycleState = 0x0035,
  EZSP_sendBroadcast = 0x0036,
  EZSP_proxyBroadcast = 0x0037,
  EZSP_sendMulticast = 0x0038,
  EZSP_sendReply = 0x0039,
  EZSP_sendMulticastWithAlias = 0x003A,
  EZSP_joinNetworkDirectly = 0x003B,
  EZSP_clearStoredBeacons = 0x003C,
  EZSP_getFirstBeacon = 0x003D,
  EZSP_getNeighborFrameCounter = 0x003E,
  EZSP_messageSentHandler = 0x003F,
  EZSP_setDutyCycleLimitsInStack = 0x0040,
  EZSP_sendManyToOneRouteRequest = 0x0041,
  EZSP_pollForData = 0x0042,
  EZSP_pollCompleteHandler = 0x0043,
  EZSP_pollHandler = 0x0044,
  EZSP_incomingMessageHandler = 0x0045,
  EZSP_macFilterMatchMessageHandler = 0x0046,
  EZSP_customFrame = 0x0047,
  EZSP_energyScanResultHandler = 0x0048,
  EZSP_getRandomNumber = 0x0049,
  EZSP_getChildData = 0x004A,
  EZSP_getDutyCycleLimits = 0x004B,
  EZSP_getCurrentDutyCycle = 0x004C,
  EZSP_dutyCycleHandler = 0x004D,
  EZSP_getTimer = 0x004E,
  EZSP_getTrueRandomEntropySource = 0x004F,
  EZSP_unicastCurrentNetworkKey = 0x0050,
  EZSP_sendRawMessageExtended = 0x0051,
  EZSP_getConfigurationValue = 0x0052,
  EZSP_setConfigurationValue = 0x0053,
  EZSP_customFrameHandler = 0x0054,
  EZSP_setPolicy = 0x0055,
  EZSP_getPolicy = 0x0056,
  EZSP_invalidCommand = 0x0058,
  EZSP_setSourceRouteDiscoveryMode = 0x005A,
  EZSP_addressTableEntryIsActive = 0x005B,
  EZSP_setAddressTableRemoteEui64 = 0x005C,
  EZSP_setAddressTableRemoteNodeId = 0x005D,
  EZSP_getAddressTableRemoteEui64 = 0x005E,
  EZSP_getAddressTableRemoteNodeId = 0x005F,
  EZSP_lookupNodeIdByEui64 = 0x0060,
  EZSP_lookupEui64ByNodeId = 0x0061,
  EZSP_incomingSenderEui64Handler = 0x0062,
  EZSP_getMulticastTableEntry = 0x0063,
  EZSP_setMulticastTableEntry = 0x0064,
  EZSP_readAndClearCounters = 0x0065,
  EZSP_addOrUpdateKeyTableEntry = 0x0066,
  EZSP_sendTrustCenterLinkKey = 0x0067,
  EZSP_setInitialSecurityState = 0x0068,
  EZSP_getCurrentSecurityState = 0x0069,
  EZSP_getKey = 0x006A,
  EZSP_clearTransientLinkKeys = 0x006B,
  EZSP_updateTcLinkKey = 0x006C,
  EZSP_getTransientKeyTableEntry = 0x006D,
  EZSP_switchNetworkKeyHandler = 0x006E,
  EZSP_aesMmoHash = 0x006F,
  EZSP_gpSinkTableInit = 0x0070,
  EZSP_getKeyTableEntry = 0x0071,
  EZSP_setKeyTableEntry = 0x0072,
  EZSP_broadcastNextNetworkKey = 0x0073,
  EZSP_broadcastNetworkKeySwitch = 0x0074,
  EZSP_findKeyTableEntry = 0x0075,
  EZSP_eraseKeyTableEntry = 0x0076,
  EZSP_becomeTrustCenter = 0x0077,
  EZSP_dsaVerifyHandler = 0x0078,
  EZSP_getNeighbor = 0x0079,
  EZSP_neighborCount = 0x007A,
  EZSP_getRouteTableEntry = 0x007B,
  EZSP_idConflictHandler = 0x007C,
  EZSP_incomingManyToOneRouteRequestHandler = 0x007D,
  EZSP_setExtendedTimeout = 0x007E,
  EZSP_getExtendedTimeout = 0x007F,
  EZSP_incomingRouteErrorHandler = 0x0080,
  EZSP_echo = 0x0081,
  EZSP_replaceAddressTableEntry = 0x0082,
  EZSP_mfglibStart = 0x0083,
  EZSP_mfglibEnd = 0x0084,
  EZSP_mfglibStartTone = 0x0085,
  EZSP_mfglibStopTone = 0x0086,
  EZSP_mfglibStartStream = 0x0087,
  EZSP_mfglibStopStream = 0x0088,
  EZSP_mfglibSendPacket = 0x0089,
  EZSP_mfglibSetChannel = 0x008A,
  EZSP_mfglibGetChannel = 0x008B,
  EZSP_mfglibSetPower = 0x008C,
  EZSP_mfglibGetPower = 0x008D,
  EZSP_mfglibRxHandler = 0x008E,
  EZSP_launchStandaloneBootloader = 0x008F,
  EZSP_sendBootloadMessage = 0x0090,
  EZSP_getStandaloneBootloaderVersionPlatMicroPhy = 0x0091,
  EZSP_incomingBootloadMessageHandler = 0x0092,
  EZSP_bootloadTransmitCompleteHandler = 0x0093,
  EZSP_aesEncrypt = 0x0094,
  EZSP_overrideCurrentChannel = 0x0095,
  EZSP_sendRawMessage = 0x0096,
  EZSP_macPassthroughMessageHandler = 0x0097,
  EZSP_rawTransmitCompleteHandler = 0x0098,
  EZSP_setRadioPower = 0x0099,
  EZSP_setRadioChannel = 0x009A,
  EZSP_zigbeeKeyEstablishmentHandler = 0x009B,
  EZSP_energyScanRequest = 0x009C,
  EZSP_delayTest = 0x009D,
  EZSP_generateCbkeKeysHandler = 0x009E,
  EZSP_calculateSmacs = 0x009F,
  EZSP_calculateSmacsHandler = 0x00A0,
  EZSP_clearTemporaryDataMaybeStoreLinkKey = 0x00A1,
  EZSP_setPreinstalledCbkeData = 0x00A2,
  EZSP_dsaVerify = 0x00A3,
  EZSP_generateCbkeKeys = 0x00A4,
  EZSP_getCertificate = 0x00A5,
  EZSP_dsaSign = 0x00A6,
  EZSP_dsaSignHandler = 0x00A7,
  EZSP_removeDevice = 0x00A8,
  EZSP_unicastNwkKeyUpdate = 0x00A9,
  EZSP_getValue = 0x00AA,
  EZSP_setValue = 0x00AB,
  EZSP_setGpioCurrentConfiguration = 0x00AC,
  EZSP_setGpioPowerUpDownConfiguration = 0x00AD,
  EZSP_setGpioRadioPowerMask = 0x00AE,
  EZSP_addTransientLinkKey = 0x00AF,
  EZSP_dsaVerify283k1 = 0x00B0,
  EZSP_clearKeyTable = 0x00B1,
  EZSP_zllNetworkOps = 0x00B2,
  EZSP_zllSetInitialSecurityState = 0x00B3,
  EZSP_zllStartScan = 0x00B4,
  EZSP_zllSetRxOnWhenIdle = 0x00B5,
  EZSP_zllNetworkFoundHandler = 0x00B6,
  EZSP_zllScanCompleteHandler = 0x00B7,
  EZSP_zllAddressAssignmentHandler = 0x00B8,
  EZSP_setLogicalAndRadioChannel = 0x00B9,
  EZSP_getLogicalChannel = 0x00BA,
  EZSP_zllTouchLinkTargetHandler = 0x00BB,
  EZSP_zllGetTokens = 0x00BC,
  EZSP_zllSetDataToken = 0x00BD,
  EZSP_isZllNetwork = 0x00BE,
  EZSP_zllSetNonZllNetwork = 0x00BF,
  EZSP_gpProxyTableLookup = 0x00C0,
  EZSP_getSourceRouteTableEntry = 0x00C1,
  EZSP_getSourceRouteTableFilledSize = 0x00C2,
  EZSP_getSourceRouteTableTotalSize = 0x00C3,
  EZSP_gpepIncomingMessageHandler = 0x00C5,
  EZSP_dGpSend = 0x00C6,
  EZSP_dGpSentHandler = 0x00C7,
  EZSP_gpProxyTableGetEntry = 0x00C8,
  EZSP_gpProxyTableProcessGpPairing = 0x00C9,
  EZSP_setSecurityKey = 0x00CA,
  EZSP_setSecurityParameters = 0x00CB,
  EZSP_resetToFactoryDefaults = 0x00CC,
  EZSP_getSecurityKeyStatus = 0x00CD,
  EZSP_getTransientLinkKey = 0x00CE,
  EZSP_zllSetSecurityStateWithoutKey = 0x00CF,
  EZSP_setRoutingShortcutThreshold = 0x00D0,
  EZSP_getRoutingShortcutThreshold = 0x00D1,
  EZSP_unusedPanIdFoundHandler = 0x00D2,
  EZSP_findUnusedPanId = 0x00D3,
  EZSP_zllSetRadioIdleMode = 0x00D4,
  EZSP_setZllNodeType = 0x00D5,
  EZSP_setZllAdditionalState = 0x00D6,
  EZSP_zllOperationInProgress = 0x00D7,
  EZSP_zllRxOnWhenIdleGetActive = 0x00D8,
  EZSP_getZllPrimaryChannelMask = 0x00D9,
  EZSP_getZllSecondaryChannelMask = 0x00DA,
  EZSP_setZllPrimaryChannelMask = 0x00DB,
  EZSP_setZllSecondaryChannelMask = 0x00DC,
  EZSP_gpSinkTableGetEntry = 0x00DD,
  EZSP_gpSinkTableLookup = 0x00DE,
  EZSP_gpSinkTableSetEntry = 0x00DF,
  EZSP_gpSinkTableRemoveEntry = 0x00E0,
  EZSP_gpSinkTableFindOrAllocateEntry = 0x00E1,
  EZSP_gpSinkTableClearAll = 0x00E2,
  EZSP_setLongUpTime = 0x00E3,
  EZSP_setHubConnectivity = 0x00E4,
  EZSP_isUpTimeLong = 0x00E5,
  EZSP_isHubConnected = 0x00E6,
  EZSP_setParentClassificationEnabled = 0x00E7,
  EZSP_generateCbkeKeys283k1 = 0x00E8,
  EZSP_generateCbkeKeysHandler283k1 = 0x00E9,
  EZSP_calculateSmacs283k1 = 0x00EA,
  EZSP_calculateSmacsHandler283k1 = 0x00EB,
  EZSP_getCertificate283k1 = 0x00EC,
  EZSP_savePreinstalledCbkeData283k1 = 0x00ED,
  EZSP_clearTemporaryDataMaybeStoreLinkKey283k1 = 0x00EE,
  EZSP_setBeaconClassificationParams = 0x00EF,
  EZSP_getParentClassificationEnabled = 0x00F0,
  EZSP_readCounters = 0x00F1,
  EZSP_counterRolloverHandler = 0x00F2,
  EZSP_getBeaconClassificationParams = 0x00F3,
  EZSP_setMacPollFailureWaitTime = 0x00F4,
  EZSP_sendLinkPowerDeltaRequest = 0x00F7,
  EZSP_multiPhyStart = 0x00F8,
  EZSP_multiPhyStop = 0x00F9,
  EZSP_multiPhySetRadioPower = 0x00FA,
  EZSP_multiPhySetRadioChannel = 0x00FB,
  EZSP_getPhyInterfaceCount = 0x00FC,
  EZSP_getRadioParameters = 0x00FD,
  EZSP_writeNodeData = 0x00FE,
  // Tasmota specifics
  EZSP_rstAck = 0xFFFE,
};

#endif // USE_ZIGBEE_EZSP

// Commands in the SYS subsystem
enum SysCommand {
  SYS_RESET = 0x00,
  SYS_PING = 0x01,
  SYS_VERSION = 0x02,
  SYS_SET_EXTADDR = 0x03,
  SYS_GET_EXTADDR = 0x04,
  SYS_RAM_READ = 0x05,
  SYS_RAM_WRITE = 0x06,
  SYS_OSAL_NV_ITEM_INIT = 0x07,
  SYS_OSAL_NV_READ = 0x08,
  SYS_OSAL_NV_WRITE = 0x09,
  SYS_OSAL_START_TIMER = 0x0A,
  SYS_OSAL_STOP_TIMER = 0x0B,
  SYS_RANDOM = 0x0C,
  SYS_ADC_READ = 0x0D,
  SYS_GPIO = 0x0E,
  SYS_STACK_TUNE = 0x0F,
  SYS_SET_TIME = 0x10,
  SYS_GET_TIME = 0x11,
  SYS_OSAL_NV_DELETE = 0x12,
  SYS_OSAL_NV_LENGTH = 0x13,
  SYS_TEST_RF = 0x40,
  SYS_TEST_LOOPBACK = 0x41,
  SYS_RESET_IND = 0x80,
  SYS_OSAL_TIMER_EXPIRED = 0x81,
};
// Commands in the SAPI subsystem
enum SapiCommand {
  SAPI_START_REQUEST = 0x00,
  SAPI_BIND_DEVICE = 0x01,
  SAPI_ALLOW_BIND = 0x02,
  SAPI_SEND_DATA_REQUEST = 0x03,
  SAPI_READ_CONFIGURATION = 0x04,
  SAPI_WRITE_CONFIGURATION = 0x05,
  SAPI_GET_DEVICE_INFO = 0x06,
  SAPI_FIND_DEVICE_REQUEST = 0x07,
  SAPI_PERMIT_JOINING_REQUEST = 0x08,
  SAPI_SYSTEM_RESET = 0x09,
  SAPI_START_CONFIRM = 0x80,
  SAPI_BIND_CONFIRM = 0x81,
  SAPI_ALLOW_BIND_CONFIRM = 0x82,
  SAPI_SEND_DATA_CONFIRM = 0x83,
  SAPI_FIND_DEVICE_CONFIRM = 0x85,
  SAPI_RECEIVE_DATA_INDICATION = 0x87,
};
enum Z_configuration {
  CONF_EXTADDR = 0x01,
  CONF_BOOTCOUNTER = 0x02,
  CONF_STARTUP_OPTION = 0x03,
  CONF_START_DELAY = 0x04,
  CONF_NIB = 0x21,
  CONF_DEVICE_LIST = 0x22,
  CONF_ADDRMGR = 0x23,
  CONF_POLL_RATE = 0x24,
  CONF_QUEUED_POLL_RATE = 0x25,
  CONF_RESPONSE_POLL_RATE = 0x26,
  CONF_REJOIN_POLL_RATE = 0x27,
  CONF_DATA_RETRIES = 0x28,
  CONF_POLL_FAILURE_RETRIES = 0x29,
  CONF_STACK_PROFILE = 0x2A,
  CONF_INDIRECT_MSG_TIMEOUT = 0x2B,
  CONF_ROUTE_EXPIRY_TIME = 0x2C,
  CONF_EXTENDED_PAN_ID = 0x2D,
  CONF_BCAST_RETRIES = 0x2E,
  CONF_PASSIVE_ACK_TIMEOUT = 0x2F,
  CONF_BCAST_DELIVERY_TIME = 0x30,
  CONF_NWK_MODE = 0x31,
  CONF_CONCENTRATOR_ENABLE = 0x32,
  CONF_CONCENTRATOR_DISCOVERY = 0x33,
  CONF_CONCENTRATOR_RADIUS = 0x34,
  CONF_CONCENTRATOR_RC = 0x36,
  CONF_NWK_MGR_MODE = 0x37,
  CONF_SRC_RTG_EXPIRY_TIME = 0x38,
  CONF_ROUTE_DISCOVERY_TIME = 0x39,
  CONF_NWK_ACTIVE_KEY_INFO = 0x3A,
  CONF_NWK_ALTERN_KEY_INFO = 0x3B,
  CONF_ROUTER_OFF_ASSOC_CLEANUP = 0x3C,
  CONF_NWK_LEAVE_REQ_ALLOWED = 0x3D,
  CONF_NWK_CHILD_AGE_ENABLE = 0x3E,
  CONF_DEVICE_LIST_KA_TIMEOUT = 0x3F,
  CONF_BINDING_TABLE = 0x41,
  CONF_GROUP_TABLE = 0x42,
  CONF_APS_FRAME_RETRIES = 0x43,
  CONF_APS_ACK_WAIT_DURATION = 0x44,
  CONF_APS_ACK_WAIT_MULTIPLIER = 0x45,
  CONF_BINDING_TIME = 0x46,
  CONF_APS_USE_EXT_PANID = 0x47,
  CONF_APS_USE_INSECURE_JOIN = 0x48,
  CONF_COMMISSIONED_NWK_ADDR = 0x49,
  CONF_APS_NONMEMBER_RADIUS = 0x4B,
  CONF_APS_LINK_KEY_TABLE = 0x4C,
  CONF_APS_DUPREJ_TIMEOUT_INC = 0x4D,
  CONF_APS_DUPREJ_TIMEOUT_COUNT = 0x4E,
  CONF_APS_DUPREJ_TABLE_SIZE = 0x4F,
  CONF_DIAGNOSTIC_STATS = 0x50,
  CONF_SECURITY_LEVEL = 0x61,
  CONF_PRECFGKEY = 0x62,
  CONF_PRECFGKEYS_ENABLE = 0x63,
  CONF_SECURITY_MODE = 0x64,
  CONF_SECURE_PERMIT_JOIN = 0x65,
  CONF_APS_LINK_KEY_TYPE = 0x66,
  CONF_APS_ALLOW_R19_SECURITY = 0x67,
  CONF_IMPLICIT_CERTIFICATE = 0x69,
  CONF_DEVICE_PRIVATE_KEY = 0x6A,
  CONF_CA_PUBLIC_KEY = 0x6B,
  CONF_KE_MAX_DEVICES = 0x6C,
  CONF_USE_DEFAULT_TCLK = 0x6D,
  CONF_RNG_COUNTER = 0x6F,
  CONF_RANDOM_SEED = 0x70,
  CONF_TRUSTCENTER_ADDR = 0x71,
  CONF_USERDESC = 0x81,
  CONF_NWKKEY = 0x82,
  CONF_PANID = 0x83,
  CONF_CHANLIST = 0x84,
  CONF_LEAVE_CTRL = 0x85,
  CONF_SCAN_DURATION = 0x86,
  CONF_LOGICAL_TYPE = 0x87,
  CONF_NWKMGR_MIN_TX = 0x88,
  CONF_NWKMGR_ADDR = 0x89,
  CONF_ZDO_DIRECT_CB = 0x8F,
  CONF_TCLK_TABLE_START = 0x0101,
  ZNP_HAS_CONFIGURED = 0xF00
};

//
enum Z_Status {
  Z_SUCCESS = 0x00,
  Z_FAILURE = 0x01,
  Z_INVALIDPARAMETER = 0x02,
  Z_MEMERROR = 0x03,
  Z_CREATED = 0x09,
  Z_BUFFERFULL = 0x11
};

enum Z_App_Profiles {
  Z_PROF_IPM = 0x0101,    // Industrial Plant Monitoring
  Z_PROF_HA = 0x0104,     // Home Automation -- the only supported right now
  Z_PROF_CBA = 0x0105,    // Commercial Building Automation
  Z_PROF_TA = 0x0107,     // Telecom Applications
  Z_PROF_PHHC = 0x0108,   // Personal Home & Hospital Care
  Z_PROF_AMI = 0x0109,    // Advanced Metering Initiative
};

enum Z_Device_Ids {
  Z_DEVID_CONF_TOOL = 0x0005,
  // from https://www.rfwireless-world.com/Terminology/Zigbee-Profile-ID-list.html
  // Generic	0x0000	ON/OFF Switch
  // 0x0001	Level Control Switch
  // 0x0002	ON/OFF Output
  // 0x0003	Level Controllable Output
  // 0x0004	Scene Selector
  // 0x0005	Configuration Tool
  // 0x0006	Remote control
  // 0x0007	Combined Interface
  // 0x0008	Range Extender
  // 0x0009	Mains Power Outlet
  // Lighting	0x0100	ON/OFF Light
  // 0x0101	Dimmable Light
  // 0x0102	Color Dimmable Light
  // 0x0103	ON/OFF Light Switch
  // 0x0104	Dimmer Switch
  // 0x0105	Color Dimmer Switch
  // 0x0106	Light Sensor
  // 0x0107	Occupancy Sensor
  // Closures	0x0200	Shade
  // 0x0201	Shade Controller
  // HVAC	0x0300	Heating/Cooling Unit
  // 0x0301	Thermostat
  // 0x0302	Temperature Sensor
  // 0x0303	Pump
  // 0x0304	Pump Controller
  // 0x0305	Pressure Sensor
  // 0x0306	Flow sensor
  // Intruder Alarm Systems	0x0400	IAS Control and Indicating Equipment
  // 0x0401	IAS Ancillary Control Equipment
  // 0x0402	IAS Zone
  // 0x0403	IAS Warning Device
};

 enum Z_AddrMode : uint8_t {
  Z_Addr_NotPresent = 0,
  Z_Addr_Group = 1,
  Z_Addr_ShortAddress = 2,
  Z_Addr_IEEEAddress = 3,
  Z_Addr_Broadcast = 0xFF
};

// Commands in the AF subsystem
enum AfCommand : uint8_t {
  AF_REGISTER = 0x00,
  AF_DATA_REQUEST = 0x01,
  AF_DATA_REQUEST_EXT = 0x02,
  AF_DATA_REQUEST_SRC_RTG = 0x03,
  AF_INTER_PAN_CTL = 0x10,
  AF_DATA_STORE = 0x11,
  AF_DATA_RETRIEVE = 0x12,
  AF_APSF_CONFIG_SET = 0x13,
  AF_DATA_CONFIRM = 0x80,
  AF_REFLECT_ERROR = 0x83,
  AF_INCOMING_MSG = 0x81,
  AF_INCOMING_MSG_EXT = 0x82
};

// Commands in the ZDO subsystem
enum : uint8_t {
  ZDO_NWK_ADDR_REQ = 0x00,
  ZDO_IEEE_ADDR_REQ = 0x01,
  ZDO_NODE_DESC_REQ = 0x02,
  ZDO_POWER_DESC_REQ = 0x03,
  ZDO_SIMPLE_DESC_REQ = 0x04,
  ZDO_ACTIVE_EP_REQ = 0x05,
  ZDO_MATCH_DESC_REQ = 0x06,
  ZDO_COMPLEX_DESC_REQ = 0x07,
  ZDO_USER_DESC_REQ = 0x08,
  ZDO_DEVICE_ANNCE = 0x0A,
  ZDO_USER_DESC_SET = 0x0B,
  ZDO_SERVER_DISC_REQ = 0x0C,
  ZDO_END_DEVICE_BIND_REQ = 0x20,
  ZDO_BIND_REQ = 0x21,
  ZDO_UNBIND_REQ = 0x22,
  ZDO_SET_LINK_KEY = 0x23,
  ZDO_REMOVE_LINK_KEY = 0x24,
  ZDO_GET_LINK_KEY = 0x25,
  ZDO_MGMT_NWK_DISC_REQ = 0x30,
  ZDO_MGMT_LQI_REQ = 0x31,
  ZDO_MGMT_RTQ_REQ = 0x32,
  ZDO_MGMT_BIND_REQ = 0x33,
  ZDO_MGMT_LEAVE_REQ = 0x34,
  ZDO_MGMT_DIRECT_JOIN_REQ = 0x35,
  ZDO_MGMT_PERMIT_JOIN_REQ = 0x36,
  ZDO_MGMT_NWK_UPDATE_REQ = 0x37,
  ZDO_MSG_CB_REGISTER = 0x3E,
  ZDO_MGS_CB_REMOVE = 0x3F,
  ZDO_STARTUP_FROM_APP = 0x40,
  ZDO_AUTO_FIND_DESTINATION = 0x41,
  ZDO_EXT_REMOVE_GROUP = 0x47,
  ZDO_EXT_REMOVE_ALL_GROUP = 0x48,
  ZDO_EXT_FIND_ALL_GROUPS_ENDPOINT = 0x49,
  ZDO_EXT_FIND_GROUP = 0x4A,
  ZDO_EXT_ADD_GROUP = 0x4B,
  ZDO_EXT_COUNT_ALL_GROUPS = 0x4C,
  ZDO_NWK_ADDR_RSP = 0x80,
  ZDO_IEEE_ADDR_RSP = 0x81,
  ZDO_NODE_DESC_RSP = 0x82,
  ZDO_POWER_DESC_RSP = 0x83,
  ZDO_SIMPLE_DESC_RSP = 0x84,
  ZDO_ACTIVE_EP_RSP = 0x85,
  ZDO_MATCH_DESC_RSP = 0x86,
  ZDO_COMPLEX_DESC_RSP = 0x87,
  ZDO_USER_DESC_RSP = 0x88,
  ZDO_USER_DESC_CONF = 0x89,
  ZDO_SERVER_DISC_RSP = 0x8A,
  ZDO_END_DEVICE_BIND_RSP = 0xA0,
  ZDO_BIND_RSP = 0xA1,
  ZDO_UNBIND_RSP = 0xA2,
  ZDO_MGMT_NWK_DISC_RSP = 0xB0,
  ZDO_MGMT_LQI_RSP = 0xB1,
  ZDO_MGMT_RTG_RSP = 0xB2,
  ZDO_MGMT_BIND_RSP = 0xB3,
  ZDO_MGMT_LEAVE_RSP = 0xB4,
  ZDO_MGMT_DIRECT_JOIN_RSP = 0xB5,
  ZDO_MGMT_PERMIT_JOIN_RSP = 0xB6,
  ZDO_STATE_CHANGE_IND = 0xC0,
  ZDO_END_DEVICE_ANNCE_IND = 0xC1,
  ZDO_MATCH_DESC_RSP_SENT = 0xC2,
  ZDO_STATUS_ERROR_RSP = 0xC3,
  ZDO_SRC_RTG_IND = 0xC4,
  ZDO_LEAVE_IND = 0xC9,
  ZDO_TC_DEV_IND = 0xCA,
  ZDO_PERMIT_JOIN_IND = 0xCB,
  ZDO_MSG_CB_INCOMING = 0xFF
};

//https://e2e.ti.com/support/wireless-connectivity/zigbee-and-thread/f/158/t/475920
enum ZdoStates {
  ZDO_DEV_HOLD = 0x00,              // Initialized - not started automatically
  ZDO_DEV_INIT = 0x01,              // Initialized - not connected to anything
  ZDO_DEV_NWK_DISC = 0x02,          // Discovering PANIDs to join
  ZDO_DEV_NWK_JOINING = 0x03,       // Joining a PAN
  ZDO_DEV_NWK_REJOIN = 0x04,        // ReJoining a PAN, only for end devices
  ZDO_DEV_END_DEVICE_UNAUTH = 0x05, // Joined but not yet authenticated by trust center
  ZDO_DEV_END_DEVICE = 0x06,        // Started as a device after authentication. Note: you'll see this for both Routers or End Devices.
  ZDO_DEV_ROUTER = 0x07,            // Started as a Zigbee Router
  ZDO_DEV_COORD_STARTING = 0x08,    // Starting as a Zigbee Coordinator
  ZDO_DEV_ZB_COORD = 0x09,          // Started as a a Zigbee Coordinator
  ZDO_DEV_NWK_ORPHAN = 0x0A,        // Device has lost information about its parent.
};

// Commands in the UTIL subsystem
enum Z_Util {
  Z_UTIL_GET_DEVICE_INFO = 0x00,
  Z_UTIL_GET_NV_INFO = 0x01,
  Z_UTIL_SET_PANID = 0x02,
  Z_UTIL_SET_CHANNELS = 0x03,
  Z_UTIL_SET_SECLEVEL = 0x04,
  Z_UTIL_SET_PRECFGKEY = 0x05,
  Z_UTIL_CALLBACK_SUB_CMD = 0x06,
  Z_UTIL_KEY_EVENT = 0x07,
  Z_UTIL_TIME_ALIVE = 0x09,
  Z_UTIL_LED_CONTROL = 0x0A,
  Z_UTIL_TEST_LOOPBACK = 0x10,
  Z_UTIL_DATA_REQ = 0x11,
  Z_UTIL_SRC_MATCH_ENABLE = 0x20,
  Z_UTIL_SRC_MATCH_ADD_ENTRY = 0x21,
  Z_UTIL_SRC_MATCH_DEL_ENTRY = 0x22,
  Z_UTIL_SRC_MATCH_CHECK_SRC_ADDR = 0x23,
  Z_UTIL_SRC_MATCH_ACK_ALL_PENDING = 0x24,
  Z_UTIL_SRC_MATCH_CHECK_ALL_PENDING = 0x25,
  Z_UTIL_ADDRMGR_EXT_ADDR_LOOKUP = 0x40,
  Z_UTIL_ADDRMGR_NWK_ADDR_LOOKUP = 0x41,
  Z_UTIL_APSME_LINK_KEY_DATA_GET = 0x44,
  Z_UTIL_APSME_LINK_KEY_NV_ID_GET = 0x45,
  Z_UTIL_ASSOC_COUNT = 0x48,
  Z_UTIL_ASSOC_FIND_DEVICE = 0x49,
  Z_UTIL_ASSOC_GET_WITH_ADDRESS = 0x4A,
  Z_UTIL_APSME_REQUEST_KEY_CMD = 0x4B,
  Z_UTIL_ZCL_KEY_EST_INIT_EST = 0x80,
  Z_UTIL_ZCL_KEY_EST_SIGN = 0x81,
  Z_UTIL_UTIL_SYNC_REQ = 0xE0,
  Z_UTIL_ZCL_KEY_ESTABLISH_IND = 0xE1
};

enum ZCL_Global_Commands {
  ZCL_READ_ATTRIBUTES = 0x00,
  ZCL_READ_ATTRIBUTES_RESPONSE = 0x01,
  ZCL_WRITE_ATTRIBUTES = 0x02,
  ZCL_WRITE_ATTRIBUTES_UNDIVIDED = 0x03,
  ZCL_WRITE_ATTRIBUTES_RESPONSE = 0x04,
  ZCL_WRITE_ATTRIBUTES_NORESPONSE = 0x05,
  ZCL_CONFIGURE_REPORTING = 0x06,
  ZCL_CONFIGURE_REPORTING_RESPONSE = 0x07,
  ZCL_READ_REPORTING_CONFIGURATION = 0x08,
  ZCL_READ_REPORTING_CONFIGURATION_RESPONSE = 0x09,
  ZCL_REPORT_ATTRIBUTES = 0x0a,
  ZCL_DEFAULT_RESPONSE = 0x0b,
  ZCL_DISCOVER_ATTRIBUTES = 0x0c,
  ZCL_DISCOVER_ATTRIBUTES_RESPONSE = 0x0d
};

#define ZF(s) static const char ZS_ ## s[] PROGMEM = #s;
#define Z(s)  ZS_ ## s

typedef struct Z_StatusLine {
  uint32_t     status;          // no need to use uint8_t since it uses 32 bits anyways
  const char * status_msg;
} Z_StatusLine;

// Undocumented Zigbee ZCL code here: https://github.com/dresden-elektronik/deconz-rest-plugin/wiki/Zigbee-Error-Codes-in-the-Log
String getZigbeeStatusMessage(uint8_t status) {
  static const char    StatusMsg[] PROGMEM = "SUCCESS|FAILURE|NOT_AUTHORIZED|RESERVED_FIELD_NOT_ZERO|MALFORMED_COMMAND|UNSUP_CLUSTER_COMMAND|UNSUP_GENERAL_COMMAND"
                                             "|UNSUP_MANUF_CLUSTER_COMMAND|UNSUP_MANUF_GENERAL_COMMAND|INVALID_FIELD|UNSUPPORTED_ATTRIBUTE|INVALID_VALE|READ_ONLY"
                                             "|INSUFFICIENT_SPACE|DUPLICATE_EXISTS|NOT_FOUND|UNREPORTABLE_ATTRIBUTE|INVALID_DATA_TYPE|INVALID_SELECTOR|WRITE_ONLY"
                                             "|INCONSISTENT_STARTUP_STATE|DEFINED_OUT_OF_BAND|INCONSISTENT|ACTION_DENIED|TIMEOUT|ABORT|INVALID_IMAGE|WAIT_FOR_DATA"
                                             "|NO_IMAGE_AVAILABLE|REQUIRE_MORE_IMAGE|NOTIFICATION_PENDING|HARDWARE_FAILURE|SOFTWARE_FAILURE|CALIBRATION_ERROR|UNSUPPORTED_CLUSTER|NO_ROUTE"
                                             "|CHANNEL_ACCESS_FAILURE|NO_ACK|NO_APP_ACK|NO_ROUTE"
                                             ;
  static const uint8_t StatusIdx[] PROGMEM = { 0x00, 0x01, 0x7E, 0x7F, 0x80, 0x81, 0x82,
                                               0x83, 0x84, 0x85, 0x86, 0x87, 0x88,
                                               0x89, 0x8A, 0x8B, 0x8C, 0x8D, 0x8E, 0x8F,
                                               0x90, 0x91, 0x92, 0x93, 0x94, 0x95, 0x96, 0x97,
                                               0x98, 0x99, 0x9A, 0xC0, 0xC1, 0xC2, 0xC3, 0xCD,
                                               0xE1, 0xE9, 0xA7, 0xD0};

  char msg[32];
  int32_t idx = -1;
  for (uint32_t i = 0; i < sizeof(StatusIdx); i++) {
    if (status == pgm_read_byte(&StatusIdx[i])) {
      idx = i;
      break;
    }
  }
  if (idx >= 0) {
    GetTextIndexed(msg, sizeof(msg), idx, StatusMsg);
  } else {
    *msg = 0x00;    // empty string
  }
  return String(msg);
}

#endif // USE_ZIGBEE
