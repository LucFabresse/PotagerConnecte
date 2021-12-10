#pragma once

// Debug mode is enabled if not zero
#define DEBUG_MODE 0
// Board name
#define BOARD_NAME "ESP8266"

// I2C pins
#define SDA D4
#define SCL D5
// Temperature offset in degrees Celsius
#define TEMPERATURE_CORRECTION_OFFSET 0
// Humidity offset in percent
#define HUMIDITY_CORRECTION_OFFSET 0
// How long to cache the sensor results, in milliseconds
#define READ_INTERVAL 5000
// How many times to try to read the sensor before returning an error
#define READ_TRY_COUNT 5
// Wi-Fi SSID (required)
#define WIFI_SSID "hank"
// Wi-Fi password (required)
#define WIFI_PASSWORD "Hank$234"
// Hostname for DHCP DDNS, overrides the default (uncomment to enable)
#define WIFI_HOSTNAME "esp_potager1"
// Use static IPv4 addressing, disable for DHCPv4
#define WIFI_IPV4_STATIC true
// Static IPv4 address
#define WIFI_IPV4_ADDRESS 10, 3, 141, 20
// Static IPv4 gateway address
#define WIFI_IPV4_GATEWAY 10, 3, 141, 1
// Static IPv4 subnet mask
#define WIFI_IPV4_SUBNET_MASK 255, 255, 255, 0
// Static IPv4 primary DNS server
#define WIFI_IPV4_DNS_1 1, 1, 1, 1
// Static IPv4 secondary DNS server
#define WIFI_IPV4_DNS_2 1, 0, 0, 1
// HTTP server port
#define HTTP_SERVER_PORT 80
// HTTP metrics endpoint
#define HTTP_METRICS_ENDPOINT "/metrics"
// Prometheus namespace, aka metric prefix
#define PROM_NAMESPACE "potager1"
