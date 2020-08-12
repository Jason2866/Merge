/*
  tasmota_ca.ino - Certificate authorities for Tasmota, LetsEncrypt and AWS

  Copyright (C) 2020  Theo Arends

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

// The below is currenlty not used, CA validation takes too much memory and compute time.
// Please use fingerprint validation instead
// However, the CA are available below for future use if it appears to be useful

#if defined(USE_TLS) && defined(USE_MQTT_TLS_CA_CERT)

/*********************************************************************************************\
 * LetsEncrypt IdenTrust DST Root CA X3 certificate, RSA 2048 bits SHA 256, valid until 20210417
 *
 * https://letsencrypt.org/certificates/
 * Downloaded from https://letsencrypt.org/certs/lets-encrypt-x3-cross-signed.pem.txt
 *
 * to convert do: "bearssl ta lets-encrypt-x3-cross-signed.pem.txt"
 * then copy and paste below, chain the generic names to the same as below
 * remove "static" and add "PROGMEM"
\*********************************************************************************************/

static const unsigned char PROGMEM LetsEncrypt_DN[] = {
	0x30, 0x4A, 0x31, 0x0B, 0x30, 0x09, 0x06, 0x03, 0x55, 0x04, 0x06, 0x13,
	0x02, 0x55, 0x53, 0x31, 0x16, 0x30, 0x14, 0x06, 0x03, 0x55, 0x04, 0x0A,
	0x13, 0x0D, 0x4C, 0x65, 0x74, 0x27, 0x73, 0x20, 0x45, 0x6E, 0x63, 0x72,
	0x79, 0x70, 0x74, 0x31, 0x23, 0x30, 0x21, 0x06, 0x03, 0x55, 0x04, 0x03,
	0x13, 0x1A, 0x4C, 0x65, 0x74, 0x27, 0x73, 0x20, 0x45, 0x6E, 0x63, 0x72,
	0x79, 0x70, 0x74, 0x20, 0x41, 0x75, 0x74, 0x68, 0x6F, 0x72, 0x69, 0x74,
	0x79, 0x20, 0x58, 0x33
};

static const unsigned char PROGMEM LetsEncrypt_RSA_N[] = {
	0x9C, 0xD3, 0x0C, 0xF0, 0x5A, 0xE5, 0x2E, 0x47, 0xB7, 0x72, 0x5D, 0x37,
	0x83, 0xB3, 0x68, 0x63, 0x30, 0xEA, 0xD7, 0x35, 0x26, 0x19, 0x25, 0xE1,
	0xBD, 0xBE, 0x35, 0xF1, 0x70, 0x92, 0x2F, 0xB7, 0xB8, 0x4B, 0x41, 0x05,
	0xAB, 0xA9, 0x9E, 0x35, 0x08, 0x58, 0xEC, 0xB1, 0x2A, 0xC4, 0x68, 0x87,
	0x0B, 0xA3, 0xE3, 0x75, 0xE4, 0xE6, 0xF3, 0xA7, 0x62, 0x71, 0xBA, 0x79,
	0x81, 0x60, 0x1F, 0xD7, 0x91, 0x9A, 0x9F, 0xF3, 0xD0, 0x78, 0x67, 0x71,
	0xC8, 0x69, 0x0E, 0x95, 0x91, 0xCF, 0xFE, 0xE6, 0x99, 0xE9, 0x60, 0x3C,
	0x48, 0xCC, 0x7E, 0xCA, 0x4D, 0x77, 0x12, 0x24, 0x9D, 0x47, 0x1B, 0x5A,
	0xEB, 0xB9, 0xEC, 0x1E, 0x37, 0x00, 0x1C, 0x9C, 0xAC, 0x7B, 0xA7, 0x05,
	0xEA, 0xCE, 0x4A, 0xEB, 0xBD, 0x41, 0xE5, 0x36, 0x98, 0xB9, 0xCB, 0xFD,
	0x6D, 0x3C, 0x96, 0x68, 0xDF, 0x23, 0x2A, 0x42, 0x90, 0x0C, 0x86, 0x74,
	0x67, 0xC8, 0x7F, 0xA5, 0x9A, 0xB8, 0x52, 0x61, 0x14, 0x13, 0x3F, 0x65,
	0xE9, 0x82, 0x87, 0xCB, 0xDB, 0xFA, 0x0E, 0x56, 0xF6, 0x86, 0x89, 0xF3,
	0x85, 0x3F, 0x97, 0x86, 0xAF, 0xB0, 0xDC, 0x1A, 0xEF, 0x6B, 0x0D, 0x95,
	0x16, 0x7D, 0xC4, 0x2B, 0xA0, 0x65, 0xB2, 0x99, 0x04, 0x36, 0x75, 0x80,
	0x6B, 0xAC, 0x4A, 0xF3, 0x1B, 0x90, 0x49, 0x78, 0x2F, 0xA2, 0x96, 0x4F,
	0x2A, 0x20, 0x25, 0x29, 0x04, 0xC6, 0x74, 0xC0, 0xD0, 0x31, 0xCD, 0x8F,
	0x31, 0x38, 0x95, 0x16, 0xBA, 0xA8, 0x33, 0xB8, 0x43, 0xF1, 0xB1, 0x1F,
	0xC3, 0x30, 0x7F, 0xA2, 0x79, 0x31, 0x13, 0x3D, 0x2D, 0x36, 0xF8, 0xE3,
	0xFC, 0xF2, 0x33, 0x6A, 0xB9, 0x39, 0x31, 0xC5, 0xAF, 0xC4, 0x8D, 0x0D,
	0x1D, 0x64, 0x16, 0x33, 0xAA, 0xFA, 0x84, 0x29, 0xB6, 0xD4, 0x0B, 0xC0,
	0xD8, 0x7D, 0xC3, 0x93
};

static const unsigned char LetsEncrypt_RSA_E[] = {
	0x01, 0x00, 0x01
};

static const br_x509_trust_anchor PROGMEM LetsEncryptX3CrossSigned_TA = {
	{ (unsigned char *)LetsEncrypt_DN, sizeof LetsEncrypt_DN },
	BR_X509_TA_CA,
	{
		BR_KEYTYPE_RSA,
		{ .rsa = {
			(unsigned char *)LetsEncrypt_RSA_N, sizeof LetsEncrypt_RSA_N,
			(unsigned char *)LetsEncrypt_RSA_E, sizeof LetsEncrypt_RSA_E,
		} }
	}
};

/*********************************************************************************************\
 * Amazon Root CA, RSA 2048 bits SHA 256, valid until 20380117
 *
 * https://letsencrypt.org/certificates/
 * Downloaded from https://www.amazontrust.com/repository/AmazonRootCA1.pem
 *
 * to convert do: "bearssl ta AmazonRootCA1.pem"
 * then copy and paste below, chain the generic names to the same as below
 * remove "static" and add "PROGMEM"
\*********************************************************************************************/


const unsigned char PROGMEM AmazonRootCA1_DN[] = {
	0x30, 0x39, 0x31, 0x0B, 0x30, 0x09, 0x06, 0x03, 0x55, 0x04, 0x06, 0x13,
	0x02, 0x55, 0x53, 0x31, 0x0F, 0x30, 0x0D, 0x06, 0x03, 0x55, 0x04, 0x0A,
	0x13, 0x06, 0x41, 0x6D, 0x61, 0x7A, 0x6F, 0x6E, 0x31, 0x19, 0x30, 0x17,
	0x06, 0x03, 0x55, 0x04, 0x03, 0x13, 0x10, 0x41, 0x6D, 0x61, 0x7A, 0x6F,
	0x6E, 0x20, 0x52, 0x6F, 0x6F, 0x74, 0x20, 0x43, 0x41, 0x20, 0x31
};

const unsigned char PROGMEM AmazonRootCA1_RSA_N[] = {
	0xB2, 0x78, 0x80, 0x71, 0xCA, 0x78, 0xD5, 0xE3, 0x71, 0xAF, 0x47, 0x80,
	0x50, 0x74, 0x7D, 0x6E, 0xD8, 0xD7, 0x88, 0x76, 0xF4, 0x99, 0x68, 0xF7,
	0x58, 0x21, 0x60, 0xF9, 0x74, 0x84, 0x01, 0x2F, 0xAC, 0x02, 0x2D, 0x86,
	0xD3, 0xA0, 0x43, 0x7A, 0x4E, 0xB2, 0xA4, 0xD0, 0x36, 0xBA, 0x01, 0xBE,
	0x8D, 0xDB, 0x48, 0xC8, 0x07, 0x17, 0x36, 0x4C, 0xF4, 0xEE, 0x88, 0x23,
	0xC7, 0x3E, 0xEB, 0x37, 0xF5, 0xB5, 0x19, 0xF8, 0x49, 0x68, 0xB0, 0xDE,
	0xD7, 0xB9, 0x76, 0x38, 0x1D, 0x61, 0x9E, 0xA4, 0xFE, 0x82, 0x36, 0xA5,
	0xE5, 0x4A, 0x56, 0xE4, 0x45, 0xE1, 0xF9, 0xFD, 0xB4, 0x16, 0xFA, 0x74,
	0xDA, 0x9C, 0x9B, 0x35, 0x39, 0x2F, 0xFA, 0xB0, 0x20, 0x50, 0x06, 0x6C,
	0x7A, 0xD0, 0x80, 0xB2, 0xA6, 0xF9, 0xAF, 0xEC, 0x47, 0x19, 0x8F, 0x50,
	0x38, 0x07, 0xDC, 0xA2, 0x87, 0x39, 0x58, 0xF8, 0xBA, 0xD5, 0xA9, 0xF9,
	0x48, 0x67, 0x30, 0x96, 0xEE, 0x94, 0x78, 0x5E, 0x6F, 0x89, 0xA3, 0x51,
	0xC0, 0x30, 0x86, 0x66, 0xA1, 0x45, 0x66, 0xBA, 0x54, 0xEB, 0xA3, 0xC3,
	0x91, 0xF9, 0x48, 0xDC, 0xFF, 0xD1, 0xE8, 0x30, 0x2D, 0x7D, 0x2D, 0x74,
	0x70, 0x35, 0xD7, 0x88, 0x24, 0xF7, 0x9E, 0xC4, 0x59, 0x6E, 0xBB, 0x73,
	0x87, 0x17, 0xF2, 0x32, 0x46, 0x28, 0xB8, 0x43, 0xFA, 0xB7, 0x1D, 0xAA,
	0xCA, 0xB4, 0xF2, 0x9F, 0x24, 0x0E, 0x2D, 0x4B, 0xF7, 0x71, 0x5C, 0x5E,
	0x69, 0xFF, 0xEA, 0x95, 0x02, 0xCB, 0x38, 0x8A, 0xAE, 0x50, 0x38, 0x6F,
	0xDB, 0xFB, 0x2D, 0x62, 0x1B, 0xC5, 0xC7, 0x1E, 0x54, 0xE1, 0x77, 0xE0,
	0x67, 0xC8, 0x0F, 0x9C, 0x87, 0x23, 0xD6, 0x3F, 0x40, 0x20, 0x7F, 0x20,
	0x80, 0xC4, 0x80, 0x4C, 0x3E, 0x3B, 0x24, 0x26, 0x8E, 0x04, 0xAE, 0x6C,
	0x9A, 0xC8, 0xAA, 0x0D
};

static const unsigned char PROGMEM AmazonRootCA1_RSA_E[] = {
	0x01, 0x00, 0x01
};

const br_x509_trust_anchor PROGMEM AmazonRootCA1_TA = {
	{ (unsigned char *)AmazonRootCA1_DN, sizeof AmazonRootCA1_DN },
	BR_X509_TA_CA,
	{
		BR_KEYTYPE_RSA,
		{ .rsa = {
			(unsigned char *)AmazonRootCA1_RSA_N, sizeof AmazonRootCA1_RSA_N,
			(unsigned char *)AmazonRootCA1_RSA_E, sizeof AmazonRootCA1_RSA_E,
		} }
	}
};

// cumulative CA
const br_x509_trust_anchor PROGMEM Tasmota_TA[] = {
	{
		{ (unsigned char *)LetsEncrypt_DN, sizeof LetsEncrypt_DN },
		BR_X509_TA_CA,
		{
			BR_KEYTYPE_RSA,
			{ .rsa = {
				(unsigned char *)LetsEncrypt_RSA_N, sizeof LetsEncrypt_RSA_N,
				(unsigned char *)LetsEncrypt_RSA_E, sizeof LetsEncrypt_RSA_E,
			} }
		}
	}
	,
	{
		{ (unsigned char *)AmazonRootCA1_DN, sizeof AmazonRootCA1_DN },
		BR_X509_TA_CA,
		{
			BR_KEYTYPE_RSA,
			{ .rsa = {
				(unsigned char *)AmazonRootCA1_RSA_N, sizeof AmazonRootCA1_RSA_N,
				(unsigned char *)AmazonRootCA1_RSA_E, sizeof AmazonRootCA1_RSA_E,
			} }
		}
	}
};

const size_t Tasmota_TA_size = ARRAY_SIZE(Tasmota_TA);

// we add a separate CA for telegram
/*********************************************************************************************\
 * GoDaddy Daddy Secure Certificate Authority - G2, RSA 2048 bits SHA 256, valid until 20220523
 *
 * to convert do: "brssl ta GoDaddyCA.pem"
 * then copy and paste below, chain the generic names to the same as below
 * remove "static" and add "PROGMEM"
\*********************************************************************************************/

const unsigned char GoDaddyCAG2_DN[] PROGMEM = {
	0x30, 0x3E, 0x31, 0x21, 0x30, 0x1F, 0x06, 0x03, 0x55, 0x04, 0x0B, 0x13,
	0x18, 0x44, 0x6F, 0x6D, 0x61, 0x69, 0x6E, 0x20, 0x43, 0x6F, 0x6E, 0x74,
	0x72, 0x6F, 0x6C, 0x20, 0x56, 0x61, 0x6C, 0x69, 0x64, 0x61, 0x74, 0x65,
	0x64, 0x31, 0x19, 0x30, 0x17, 0x06, 0x03, 0x55, 0x04, 0x03, 0x13, 0x10,
	0x61, 0x70, 0x69, 0x2E, 0x74, 0x65, 0x6C, 0x65, 0x67, 0x72, 0x61, 0x6D,
	0x2E, 0x6F, 0x72, 0x67
};

const unsigned char GoDaddyCAG2_RSA_N[] PROGMEM = {
	0xB4, 0xA3, 0x16, 0x9E, 0x5C, 0x57, 0xC9, 0x89, 0x65, 0xED, 0xEA, 0x78,
	0x0B, 0xAE, 0x8A, 0x58, 0x2F, 0xAE, 0x5A, 0xC8, 0x6E, 0x49, 0x8D, 0xFC,
	0x57, 0xA5, 0x98, 0x88, 0x78, 0x2E, 0x0B, 0x3C, 0x40, 0x3C, 0x21, 0x2E,
	0x9A, 0x94, 0x98, 0x33, 0xA7, 0xE3, 0x42, 0xA7, 0x85, 0xFA, 0xD0, 0x73,
	0x84, 0x01, 0x1C, 0x72, 0x39, 0x37, 0x23, 0xB5, 0x56, 0x1D, 0x43, 0xA5,
	0x71, 0x14, 0x08, 0x24, 0xA5, 0x39, 0xCC, 0xDE, 0x58, 0x53, 0x94, 0x8E,
	0x2A, 0x42, 0xA7, 0x4E, 0x2D, 0x07, 0x32, 0x9E, 0xBA, 0x8B, 0xD3, 0x2A,
	0xA9, 0x9E, 0xC0, 0xE3, 0xCE, 0x9A, 0x10, 0x96, 0x45, 0x58, 0x7A, 0xC7,
	0x1E, 0x45, 0x14, 0x23, 0x92, 0xBB, 0x54, 0x82, 0x88, 0x94, 0x49, 0xB6,
	0xBE, 0x81, 0x21, 0x00, 0x29, 0x6D, 0xC9, 0xCE, 0x8B, 0x39, 0x3A, 0xDC,
	0x35, 0x15, 0xD9, 0xEB, 0x47, 0x9C, 0xEF, 0xBA, 0x09, 0x0E, 0x16, 0xE4,
	0xD9, 0xEB, 0x72, 0x30, 0xFA, 0x49, 0xAB, 0x98, 0x31, 0x7C, 0xB3, 0xAC,
	0x2B, 0x29, 0x91, 0x87, 0x08, 0x41, 0x72, 0x5E, 0x35, 0xC7, 0x87, 0x04,
	0x22, 0xF5, 0x48, 0x76, 0x30, 0x6D, 0x88, 0xDF, 0xF2, 0xA5, 0x29, 0x13,
	0x70, 0xB3, 0x87, 0x02, 0xD5, 0x6B, 0x58, 0xB1, 0xE8, 0x73, 0xC7, 0xE4,
	0xEF, 0x79, 0x86, 0xA4, 0x07, 0x5F, 0x67, 0xB4, 0x79, 0x8D, 0xA4, 0x25,
	0x01, 0x82, 0x8C, 0xE0, 0x30, 0x17, 0xCB, 0x4B, 0x5C, 0xFB, 0xEB, 0x4C,
	0x12, 0x51, 0xB9, 0xC9, 0x04, 0x1F, 0x7E, 0xD2, 0xF8, 0xBA, 0xF5, 0x35,
	0x8D, 0x8A, 0x1C, 0x37, 0x82, 0xF0, 0x15, 0x73, 0x00, 0x6E, 0x3D, 0x1C,
	0x76, 0x8B, 0x01, 0x74, 0x81, 0x3D, 0xE4, 0x2C, 0xA7, 0xCC, 0x2F, 0x66,
	0xDC, 0x44, 0xA8, 0x27, 0x3F, 0xEA, 0xD0, 0xA7, 0xA8, 0xF1, 0xCB, 0xEA,
	0xDA, 0x07, 0x38, 0xBD
};

const unsigned char GoDaddyCAG2_RSA_E[] PROGMEM = {
	0x01, 0x00, 0x01
};

const br_x509_trust_anchor GoDaddyCAG2_TA PROGMEM = {
	{ (unsigned char *)GoDaddyCAG2_DN, sizeof GoDaddyCAG2_DN },
	0,
	{
		BR_KEYTYPE_RSA,
		{ .rsa = {
			(unsigned char *)GoDaddyCAG2_RSA_N, sizeof GoDaddyCAG2_RSA_N,
			(unsigned char *)GoDaddyCAG2_RSA_E, sizeof GoDaddyCAG2_RSA_E,
		} }
	}
};

#endif // defined(USE_TLS) && defined(USE_MQTT_TLS_CA_CERT)
