//
// SPI Interface for Ethernet Controller
//

#ifndef SPI_ETH_H__
#define SPI_ETH_H__

#include "spi.h"
#include "gpio.h"

#define SPI_ETH_HANDLE        (&hspi1)
#define SPI_TRANSFER_BUF_LEN  (4 + MAX_FRAMELEN)
#define MAX_UINT8             255



#define ADDR_MASK 0x1F
#define BANK_MASK 0x60
#define BANK_SHIFT 5

/* All-bank registers */
#define EUDASTL 0x16
#define EUDASTH 0x17
#define EUDANDL 0x18
#define EUDANDH 0x19
#define ESTATL 0x1A
#define ESTATH 0x1B
#define EIRL 0x1C
#define EIRH 0x1D
#define ECON1L 0x1E
#define ECON1H 0x1F

#define FRCLNK (1<<2)
/* Bank 0 registers */
#define ETXSTL (0x00 | 0x00)
#define ETXSTH (0x01 | 0x00)
#define ETXLENL (0x02 | 0x00)
#define ETXLENH (0x03 | 0x00)
#define ERXSTL (0x04 | 0x00)
#define ERXSTH (0x05 | 0x00)
#define ERXTAILL (0x06 | 0x00)
#define ERXTAILH (0x07 | 0x00)
#define ERXHEADL (0x08 | 0x00)
#define ERXHEADH (0x09 | 0x00)
#define EDMASTL (0x0A | 0x00)
#define EDMASTH (0x0B | 0x00)
#define EDMALENL (0x0C | 0x00)
#define EDMALENH (0x0D | 0x00)
#define EDMADSTL (0x0E | 0x00)
#define EDMADSTH (0x0F | 0x00)
#define EDMACSL (0x10 | 0x00)
#define EDMACSH (0x11 | 0x00)
#define ETXSTATL (0x12 | 0x00)
#define ETXSTATH (0x13 | 0x00)
#define ETXWIREL (0x14 | 0x00)
#define ETXWIREH (0x15 | 0x00)

/* Bank 1 registers */
#define EHT1L (0x00 | 0x20)
#define EHT1H (0x01 | 0x20)
#define EHT2L (0x02 | 0x20)
#define EHT2H (0x03 | 0x20)
#define EHT3L (0x04 | 0x20)
#define EHT3H (0x05 | 0x20)
#define EHT4L (0x06 | 0x20)
#define EHT4H (0x07 | 0x20)
#define EPMM1L (0x08 | 0x20)
#define EPMM1H (0x09 | 0x20)
#define EPMM2L (0x0A | 0x20)
#define EPMM2H (0x0B | 0x20)
#define EPMM3L (0x0C | 0x20)
#define EPMM3H (0x0D | 0x20)
#define EPMM4L (0x0E | 0x20)
#define EPMM4H (0x0F | 0x20)
#define EPMCSL (0x10 | 0x20)
#define EPMCSH (0x11 | 0x20)
#define EPMOL (0x12 | 0x20)
#define EPMOH (0x13 | 0x20)
#define ERXFCONL (0x14 | 0x20)
#define ERXFCONH (0x15 | 0x20)

/* Bank 2 registers */
#define MACON1L (0x00 | 0x40)
#define MACON1H (0x01 | 0x40)
#define MACON2L (0x02 | 0x40)
#define MACON2H (0x03 | 0x40)
#define MABBIPGL (0x04 | 0x40)
#define MABBIPGH (0x05 | 0x40)
#define MAIPGL (0x06 | 0x40)
#define MAIPGH (0x07 | 0x40)
#define MACLCONL (0x08 | 0x40)
#define MACLCONH (0x09 | 0x40)
#define MAMXFLL (0x0A | 0x40)
#define MAMXFLH (0x0B | 0x40)
#define MICMDL (0x12 | 0x40)
#define MICMDH (0x13 | 0x40)
#define MIREGADRL (0x14 | 0x40)
#define MIREGADRH (0x15 | 0x40)

/* Bank 3 registers */
#define MAADR3L (0x00 | 0x60)
#define MAADR3H (0x01 | 0x60)
#define MAADR2L (0x02 | 0x60)
#define MAADR2H (0x03 | 0x60)
#define MAADR1L (0x04 | 0x60)
#define MAADR1H (0x05 | 0x60)
#define MIWRL (0x06 | 0x60)
#define MIWRH (0x07 | 0x60)
#define MIRDL (0x08 | 0x60)
#define MIRDH (0x09 | 0x60)
#define MISTATL (0x0A | 0x60)
#define MISTATH (0x0B | 0x60)
#define EPAUSL (0x0C | 0x60)
#define EPAUSH (0x0D | 0x60)
#define ECON2L (0x0E | 0x60)
#define ECON2H (0x0F | 0x60)
#define ERXWML (0x10 | 0x60)
#define ERXWMH (0x11 | 0x60)
#define EIEL (0x12 | 0x60)
#define EIEH (0x13 | 0x60)
#define EIDLEDL (0x14 | 0x60)
#define EIDLEDH (0x15 | 0x60)

/* Unbanked registers */
#define EGPDATA (0x00 | 0x80)
#define ERXDATA (0x02 | 0x80)
#define EUDADATA (0x04 | 0x80)
#define EGPRDPTL (0x06 | 0x80)
#define EGPRDPTH (0x07 | 0x80)
#define EGPWRPTL (0x08 | 0x80)
#define EGPWRPTH (0x09 | 0x80)
#define ERXRDPTL (0x0A | 0x80)
#define ERXRDPTH (0x0B | 0x80)
#define ERXWRPTL (0x0C | 0x80)
#define ERXWRPTH (0x0D | 0x80)
#define EUDARDPTL (0x0E | 0x80)
#define EUDARDPTH (0x0F | 0x80)
#define EUDAWRPTL (0x10 | 0x80)
#define EUDAWRPTH (0x11 | 0x80)

/* PHY registers */
#define PHCON1 0x00
#define PHSTAT1 0x01
#define PHANA 0x04
#define PHANLPA 0x05
#define PHANE 0x06
#define PHCON2 0x11
#define PHSTAT2 0x1B
#define PHSTAT3 0x1F

/* Single-byte instructions */
#define BXSEL(bank) (0xC0 + (bank & (BANK_MASK >> BANK_SHIFT)) * 2)
/* Bank X Select */
#define B0SEL 0xC0		/* Bank 0 Select */
#define B1SEL 0xC2		/* Bank 1 Select */
#define B2SEL 0xC4		/* Bank 2 Select */
#define B3SEL 0xC6		/* Bank 3 Select */
#define SETETHRST 0xCA		/* System Reset */
#define FCDISABLE 0xE0		/* Flow Control Disable */
#define FCSINGLE 0xE2		/* Flow Control Single */
#define FCMULTIPLE 0xE4		/* Flow Control Multiple */
#define FCCLEAR 0xE6		/* Flow Control Clear */
#define SETPKTDEC 0xCC		/* Decrement Packet Counter */
#define DMASTOP 0xD2		/* DMA Stop */
#define DMACKSUM 0xD8		/* DMA Start Checksum */
#define DMACKSUMS 0xDA		/* DMA Start Checksum with Seed */
#define DMACOPY 0xDC		/* DMA Start Copy */
#define DMACOPYS 0xDE		/* DMA Start Copy and Checksum with Seed */
#define SETTXRTS 0xD4		/* Request Packet Transmission */
#define ENABLERX 0xE8		/* Enable RX */
#define DISABLERX 0xEA		/* Disable RX */
#define SETEIE 0xEC		/* Enable Interrupts */
#define CLREIE 0xEE		/* Disable Interrupts */

/* Two byte instructions */
#define RBSEL 0xC8		/* Read Bank Select */

/* Three byte instructions */
#define WGPRDPT 0x60		/* Write EGPRDPT */
#define RGPRDPT 0x62		/* Read EGPRDPT */
#define WRXRDPT 0x64		/* Write ERXRDPT */
#define RRXRDPT 0x66		/* Read ERXRDPT */
#define WUDARDPT 0x68		/* Write EUDARDPT */
#define RUDARDPT 0x6A		/* Read EUDARDPT */
#define WGPWRPT 0x6C		/* Write EGPWRPT */
#define RGPWRPT 0x6E		/* Read EGPWRPT */
#define WRXWRPT 0x70		/* Write ERXWRPT */
#define RRXWRPT 0x72		/* Read ERXWRPT */
#define WUDAWRPT 0x74		/* Write EUDAWRPT */
#define RUDAWRPT 0x76		/* Read EUDAWRPT */

/* n byte instructions */
#define RCR(addr) (0x00 | (addr & ADDR_MASK))	/* Read Control Register */
#define WCR(addr) (0x40 | (addr & ADDR_MASK))	/* Write Control Register */
#define RCRU 0x20		/* Read Control Register Unbanked */
#define WCRU 0x22		/* Write Control Register Unbanked */
#define BFS(addr) (0x80 | (addr & ADDR_MASK))	/* Bit Field Set */
#define BFC(addr) (0xA0 | (addr & ADDR_MASK))	/* Bit Field Clear */
#define BFSU 0x24		/* Bit Field Set Unbanked */
#define BFCU 0x26		/* Bit Field Clear Unbanked */
#define RGPDATA 0x28		/* Read EGPDATA */
#define WGPDATA 0x2A		/* Write EGPDATA */
#define RRXDATA 0x2C		/* Read ERXDATA */
#define WRXDATA 0x2E		/* Write ERXDATA */
#define RUDADATA 0x30		/* Read EUDADATA */
#define WUDADATA 0x32		/* Write EUDADATA */

/* Register bit definitions */
/* ESTAT */
#define INT     (1 << 15)
#define FCIDLE  (1 << 14)
#define RXBUSY  (1 << 13)
#define CLKRDY  (1 << 12)
#define PHYDPX  (1 << 10)
#define PHYLNK  (1 << 8)

/* EIR */
#define CRYPTEN (1 << 15)
#define MODEXIF (1 << 14)
#define HASHIF  (1 << 13)
#define AESIF   (1 << 12)
#define LINKIF  (1 << 11)
#define PKTIF   (1 << 6)
#define DMAIF   (1 << 5)
#define TXIF    (1 << 3)
#define TXABTIF (1 << 2)
#define RXABTIF (1 << 1)
#define PCFULIF (1 << 0)

/* ECON1 */
#define MODEXST (1 << 15)
#define HASHEN  (1 << 14)
#define HASHOP  (1 << 13)
#define HASHLST (1 << 12)
#define AESST   (1 << 11)
#define AESOP1  (1 << 10)
#define AESOP0  (1 << 9)
#define PKTDEC  (1 << 8)
#define FCOP1   (1 << 7)
#define FCOP0   (1 << 6)
#define DMAST   (1 << 5)
#define DMACPY  (1 << 4)
#define DMACSSD (1 << 3)
#define DMANOCS (1 << 2)
#define TXRTS   (1 << 1)
#define RXEN    (1 << 0)

/* ETXSTAT */
#define LATECOL (1 << 10)
#define MAXCOL  (1 << 9)
#define EXDEFER (1 << 8)
#define ETXSTATL_DEFER (1 << 7)
#define CRCBAD  (1 << 4)
#define COLCNT_MASK 0xF

/* ERXFCON */
#define HTEN    (1 << 15)
#define MPEN    (1 << 14)
#define NOTPM   (1 << 12)
#define PMEN3   (1 << 11)
#define PMEN2   (1 << 10)
#define PMEN1   (1 << 9)
#define PMEN0   (1 << 8)
#define CRCEEN  (1 << 7)
#define CRCEN   (1 << 6)
#define RUNTEEN (1 << 5)
#define RUNTEN  (1 << 4)
#define UCEN    (1 << 3)
#define NOTMEEN (1 << 2)
#define MCEN    (1 << 1)
#define BCEN    (1 << 0)

/* MACON1 */
#define LOOPBK  (1 << 4)
#define RXPAUS  (1 << 2)
#define PASSALL (1 << 1)

/* MACON2 */
#define MACON2_DEFER (1 << 14)
#define BPEN    (1 << 13)
#define NOBKOFF (1 << 12)
#define PADCFG2 (1 << 7)
#define PADCFG1 (1 << 6)
#define PADCFG0 (1 << 5)
#define TXCRCEN (1 << 4)
#define PHDREN  (1 << 3)
#define HFRMEN  (1 << 2)
#define FULDPX  (1 << 0)

/* MAIPG */
/* value of the high byte is given by the reserved bits,
* value of the low byte is recomended setting of the
* IPG parameter.
*/
#define MAIPGH_VAL 0x0C
#define MAIPGL_VAL 0x12

/* MIREGADRH */
#define MIREGADRH_VAL 0x01

/* MIREGADRL */
#define PHREG_MASK 0x1F

/* MICMD */
#define MIISCAN (1 << 1)
#define MIIRD   (1 << 0)

/* MISTAT */
#define NVALID  (1 << 2)
#define SCAN    (1 << 1)
#define BUSY    (1 << 0)

/* ECON2 */
#define ETHEN   (1 << 15)
#define STRCH   (1 << 14)
#define TXMAC   (0 << 13)
#define SHA1MD5 (1 << 12)
#define COCON3  (1 << 11)
#define COCON2  (1 << 10)
#define COCON1  (1 << 9)
#define COCON0  (1 << 8)
#define AUTOFC  (1 << 7)
#define TXRST   (1 << 6)
#define RXRST   (1 << 5)
#define ETHRST  (1 << 4)
#define MODLEN1 (1 << 3)
#define MODLEN0 (1 << 2)
#define AESLEN1 (1 << 1)
#define AESLEN0 (1 << 0)

/* EIE */
#define INTIE   (1 << 15)
#define MODEXIE (1 << 14)
#define HASHIE  (1 << 13)
#define AESIE   (1 << 12)
#define LINKIE  (1 << 11)
#define PKTIE   (1 << 6)
#define DMAIE   (1 << 5)
#define TXIE    (1 << 3)
#define TXABTIE (1 << 2)
#define RXABTIE (1 << 1)
#define PCFULIE (1 << 0)

/* EIDLED */
#define LACFG3  (1 << 15)
#define LACFG2  (1 << 14)
#define LACFG1  (1 << 13)
#define LACFG0  (1 << 12)
#define LBCFG3  (1 << 11)
#define LBCFG2  (1 << 10)
#define LBCFG1  (1 << 9)
#define LBCFG0  (1 << 8)
#define DEVID_SHIFT 5
#define DEVID_MASK (0x7 << DEVID_SHIFT)
#define REVID_SHIFT 0
#define REVID_MASK (0x1F << REVID_SHIFT)

/* PHANA */
/* Default value for PHY initialization*/
#define PHANA_DEFAULT 0x05E1

/* PHCON1 */
#define PRST    (1 << 15)
#define PLOOPBK (1 << 14)
#define SPD100  (1 << 13)
#define ANEN    (1 << 12)
#define PSLEEP  (1 << 11)
#define RENEG   (1 << 9)
#define PFULDPX (1 << 8)

/* PHSTAT */
#define FULL100 (1 << 14)
#define HALF100 (1 << 13)
#define FULL10  (1 << 12)
#define HALF10  (1 << 11)
#define ANDONE  (1 << 5)
#define LRFAULT (1 << 4)
#define ANABLE  (1 << 3)
#define LLSTAT  (1 << 2)
#define EXTREGS (1 << 0)

#define EUDAST_TEST_VAL 0x1234

#define TSV_SIZE 7

#define ENC424J600_DEV_ID 0x1

/* Configuration */

/* Led is on when the link is present and driven low
* temporarily when packet is TX'd or RX'd */
#define LED_A_SETTINGS 0xC

/* Led is on if the link is in 100 Mbps mode */
#define LED_B_SETTINGS 0x8

/* maximum ethernet frame length
* Currently not used as a limit anywhere
* (we're using the "huge frame enable" feature of
* enc424j600). */
#define MAX_FRAMELEN (1536 + 8 + 2)

/* Size in bytes of the receive buffer in enc424j600.
* Must be word aligned (even).
*/
#define RX_BUFFER_SIZE (9 * MAX_FRAMELEN)

/* Start of the general purpose area in sram */
#define SRAM_GP_START 0x0

/* SRAM size */
#define SRAM_SIZE 0x6000

/* Start of the receive buffer */
#define ERXST_VAL (SRAM_SIZE - RX_BUFFER_SIZE)

#define RSV_RXLONGEVDROPEV	16
#define RSV_CARRIEREV		18
#define RSV_CRCERROR		20
#define RSV_LENCHECKERR		21
#define RSV_LENOUTOFRANGE	22
#define RSV_RXOK		23
#define RSV_RXMULTICAST		24
#define RSV_RXBROADCAST		25
#define RSV_DRIBBLENIBBLE	26
#define RSV_RXCONTROLFRAME	27
#define RSV_RXPAUSEFRAME	28
#define RSV_RXUNKNOWNOPCODE	29
#define RSV_RXTYPEVLAN		30

#define RSV_RUNTFILTERMATCH	31
#define RSV_NOTMEFILTERMATCH	32
#define RSV_HASHFILTERMATCH	33
#define RSV_MAGICPKTFILTERMATCH	34
#define RSV_PTRNMTCHFILTERMATCH	35
#define RSV_UNICASTFILTERMATCH	36

#define RSV_SIZE		8
#define RSV_BITMASK(x)		(1 << ((x) - 16))
#define RSV_GETBIT(x, y)	(((x) & RSV_BITMASK(y)) ? 1 : 0)

/* Put RX buffer at 0 as suggested by the Errata datasheet */

#define RXSTART_INIT	ERXST_VAL
#define RXEND_INIT		0x5FFF
#define SRAMSIZE		0x6000
#define TXSTART			0x0000
#define RXSTART			0x1600

/*
enum {
	RXWINDOW,
	USERWINDOW,
	GPWINDOW
}MAC_window;
*/

void            enc424j600_write_sfr(unsigned char sfr, unsigned short data);
unsigned short  enc424j600_read_sfr(unsigned char sfr);
void            enc424j600_set_bits(unsigned char addr, unsigned short mask);
void            enc424j600_clear_bits(unsigned char addr, unsigned short mask);
void            enc424j600_phy_write(unsigned short address, unsigned short data);
unsigned short  enc424j600_phy_read(unsigned short address);

int enc424j600_set_hw_macaddr(unsigned char* dev_addr);
int enc424j600_get_hw_macaddr(unsigned char dev_addr[6]);
int enc424j600_hw_init(void);
void enc424j600_hw_enable(void);
int enc424j600_hw_tx(unsigned char* data, unsigned short len);
void enc424j600_irq_work_handler(void);
void enc424j600_hw_setlink(void);
int enc424j600_wait_for_autoneg(void);
void enc424j600_clear_unprocessed_rx_area(void);
extern int enc424j600_check_link_status(void);
int enc424j600_hw_rx(unsigned char *buff);
int enc424j600_read_rx_area(unsigned char *dst, int len, unsigned short srcaddr);
int enc_424j600_rcv_process(unsigned char *buff);
int enc424j600_write_sram(const unsigned char *data, int len, unsigned short dstaddr);

static inline void spiEthAssertCs(void)
{
  HAL_GPIO_WritePin(ETH_SPI_CS_GPIO_Port, ETH_SPI_CS_Pin, GPIO_PIN_RESET);
}

static inline void spiEthDeassertCs(void)
{
  HAL_GPIO_WritePin(ETH_SPI_CS_GPIO_Port, ETH_SPI_CS_Pin, GPIO_PIN_SET);
}

static inline uint8_t spiEthTransfert(uint8_t txData)
{
  uint8_t rxData;
  HAL_SPI_TransmitReceive(SPI_ETH_HANDLE, &txData, &rxData, 1, HAL_MAX_DELAY);
  return rxData;
}

static inline void spiEthTransmitBuffer(const void *buffer, int len)
{
  HAL_SPI_Transmit(SPI_ETH_HANDLE, (uint8_t *) buffer, len, HAL_MAX_DELAY);
}

static inline void spiEthReceiveBuffer(void *buffer, int len)
{
  HAL_SPI_Receive(SPI_ETH_HANDLE, (uint8_t *) buffer, len, HAL_MAX_DELAY);
}

static inline void spiEthTransmitReceiveBuffer(void *buffer, int len)
{
  HAL_SPI_TransmitReceive(SPI_ETH_HANDLE, (uint8_t *) buffer, (uint8_t *) buffer, len, HAL_MAX_DELAY);
}

static inline void spiEthInit(void)
{
  // deassert CS
  spiEthDeassertCs();

  // power-on/reset the ethernet module
  HAL_GPIO_WritePin(ETH_ON_GPIO_Port, ETH_ON_Pin, GPIO_PIN_RESET);
  HAL_Delay(100);
  HAL_GPIO_WritePin(ETH_ON_GPIO_Port, ETH_ON_Pin, GPIO_PIN_SET);
  HAL_Delay(100);
}

#endif // SPI_ETH_H__
