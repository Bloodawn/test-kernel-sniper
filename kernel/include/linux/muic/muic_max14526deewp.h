//===========================================================================
//
//  MAX14526 REGISTERS
//
//===========================================================================
#define SLAVE_ADDR    0x88

//0x00
#define DEVICEID_REG  0x00
#define VENDOR_ID_M   0xF0
#define CHIP_REV_M    0x0F

//0x01
#define CTRL1_REG     0x01
#define ID_2P2_M      0x40
#define ID_620_M      0x20
#define ID_200_M      0x10
#define VLDO_M        0x08
#define SEMREN_M      0x04
#define ADC_EN_M      0x02
#define CP_EN_M       0x01

//0x02
#define CTRL2_REG     0x02
#define INTPOL_M      0x80
#define INT_EN_M      0x40
#define MIC_LP_M      0x20
#define CP_AUD_M      0x10
#define CHG_TYPE_M    0x02
#define USB_DET_DIS_M 0x01

//0x03
#define SW_CTRL_REG   0x03
#define VID_ON_M      0x80
#define MIC_ON_M      0x40
#define DP2_M         0x38
#define DM1_M         0x07
// DP2_M
#define COMP2_TO_DP2  0x00
#define COMP2_TO_U2   0x08
#define COMP2_TO_AUD2 0x10
#define COMP2_TO_HZ   0x20
// DM1_M
#define COMN1_TO_DN1  0x00
#define COMN1_TO_U1   0x01
#define COMN1_TO_AUD1 0x02
#define COMN1_TO_C1COMP 0x03
#define COMN1_TO_HZ   0x04

//0x04
#define INT_STAT_REG  0x04
#define CHGDET_M      0x80
#define MR_COMP_M     0x40
#define SEND_END_M    0x20
#define VBUS_M        0x10
#define IDNO_M        0x0F
// IDNO_M
#define IDNO_0000     0x00
#define IDNO_0001     0x01
#define IDNO_0010     0x02
#define IDNO_0011     0x03
#define IDNO_0100     0x04
#define IDNO_0101     0x05
#define IDNO_0110     0x06
#define IDNO_0111     0x07
#define IDNO_1000     0x08
#define IDNO_1001     0x09
#define IDNO_1010     0x0A
#define IDNO_1011     0x0B

//0x05
#define STATUS_REG    0x05
#define DCPORT_M      0x80
#define CHPORT_M      0x40
#define C1COMP_M      0x01



#define TD_INT_STAT	70000	// INT_STAT bits settle down time since MUIC INT falls
#define TD_STATUS	250000	// STATUS bits settle down time since MUIC INT falls
#define TD_DP_DM	1000	// DP, DM path settle down time since SW_CONTROL writing


typedef enum {
  DEVICE_NONE,   // 0
  DEVICE_USB_CABLE,   // 1
  DEVICE_TA_CHARGER,   // 2
  DEVICE_LG_PROP_TA,   // 3
  DEVICE_UART_CABLE,   // 4

  DEVICE_VIDEO_CABLE_NO_LOAD,   // 5
  DEVICE_HEADSET,   // 6
  DEVICE_USB_OTG,   // 7
  DEVICE_VIDEO_CABLE_WT_LOAD,   // 8

  DEVICE_TIMER_FOR_HEADSET,  // 9
  DEVICE_TIMER_FOR_TVOUT, //10
//hak hopper
  DEVICE_FACTORY_USB_CABLE,  // 11
  DEVICE_RESERVE2,  // 12
  DEVICE_RESERVE3,  // 13
  DEVICE_RESERVE4,  // 14
  DEVICE_RESERVE5,  // 15

  DEVIDE_MAX  // 16
} max14526_device_type;

//===========================================================================
//
//  TI REGISTERS
//
//===========================================================================
#if 0 
/*---- I2C ADDR ----*/
#define	DEVICEID	(unsigned char) 0
#define	CONTROL_1	(unsigned char) 1
#define	CONTROL_2	(unsigned char) 2
#define	SWCONTROL	(unsigned char) 3
#define	INTSTATUS	(unsigned char) 4
#define	STATUS		(unsigned char) 5

/*---- Control 1 (ADDR 0x01) ----*/
#define	ID_2P2		(unsigned char) 0x40
#define	ID_620		(unsigned char) 0x20
#define	ID_200		(unsigned char) 0x10
#define	VLDO		(unsigned char) 0x08
#define	SEMREN		(unsigned char) 0x04
#define	ADC_EN		(unsigned char) 0x02
#define	CP_EN		(unsigned char) 0x01

/*---- Control 2 (ADDR 0x02) ----*/
#define	INTPOL		(unsigned char) 0x80
#define	INT_EN		(unsigned char) 0x40
#define	MIC_LP		(unsigned char) 0x20
#define	CP_AUD		(unsigned char) 0x10
#define	CHG_TYP		(unsigned char) 0x02
#define	USB_DET_DIS	(unsigned char) 0x01

/*---- SW_Control (ADDR 0x03) ----*/
#define	VIDEO_ON	0x80
#define	MIC_ON		0x40
#define	DP_OPEN		0x20
#define	DP_USB		0x00
#define	DP_UART		0x08
#define	DP_AUDIO	0x10
#define	DM_OPEN		0x04
#define	DM_USB		0x00
#define	DM_UART		0x01
#define	DM_AUDIO	0x02
#define	DM_UART		0x01
#define	DM_USB		0x00

/*---- INT_Status (ADDR 0x04) ----*/
#define	CHGDET		0x80
#define	MR_COMP		0x40
#define	SENDEND		0x20
#define	VBUS		0x10
#define	IDNO_MASK	0x0F

/*---- Status (ADDR 0x05) ----*/
#define	DCPORT		0x80
#define	CHPORT		0x40


/*---- MUIC STATUS ----*/
#define	MUIC_STAT_INITMODE	1
#define	MUIC_STAT_VADCWAIT	2
#define	MUIC_STAT_MADCWAIT	3
#define	MUIC_STAT_CHGDET	4
#define	MUIC_STAT_FACMODE	5
#define	MUIC_STAT_LGTAMODE	6
#define	MUIC_STAT_UTAMODE	7
#define	MUIC_STAT_CHGMODE	8
#define	MUIC_STAT_USBMODE	9
#define	MUIC_STAT_EMICMODE	10
#define	MUIC_STAT_OACCMODE	11
#define	MUIC_STAT_OTGINVALID	12
#define	MUIC_STAT_CHGTYPE	13
#define	MUIC_STAT_VADCWAIT2	14
#endif

//=========================================================
// kibum.lee@lge.com from ls855 GB source

/* I2C addresses of MUIC internal registers */
#define	DEVICE_ID	(u8) 0x00
#define	CONTROL_1	(u8) 0x01
#define	CONTROL_2	(u8) 0x02
#define	SW_CONTROL	(u8) 0x03
#define	INT_STAT	(u8) 0x04
#define	STATUS		(u8) 0x05

/* Masks for the each bit of CONTROL_1 register */
#define	MID_2P2		(u8) 0x40
#define	MID_620		(u8) 0x20
#define	MID_200		(u8) 0x10
#define	MVLDO		(u8) 0x08
#define	MSEMREN		(u8) 0x04
#define	MADC_EN		(u8) 0x02
#define	MCP_EN		(u8) 0x01

/* Masks for the each bit of CONTROL_2 register */
#define	MINTPOL		(u8) 0x80
#define	MINT_EN		(u8) 0x40
#define	MMIC_LP		(u8) 0x20
#define	MCP_AUD		(u8) 0x10
#define	MCHG_TYP	(u8) 0x02
#define	MUSB_DET_DIS	(u8) 0x01

/* Masks for the each bit of SW_CONTROL register */
#define	MMIC_ON		(u8) 0x40
#define MDP		(u8) 0x38
#define MDM		(u8) 0x07
// DP,DM settings
#define DP_USB		(u8) 0x00
#define	DP_UART		(u8) 0x08
#define	DP_AUDIO	(u8) 0x10
#define	DP_OPEN		(u8) 0x38
#define DM_USB		(u8) 0x00
#define	DM_UART		(u8) 0x01
#define	DM_AUDIO	(u8) 0x02
#define	DM_OPEN		(u8) 0x07

/* Masks for the each bit of INT_STATUS register */
#define	MCHGDET		(u8) 0x80
#define	MMR_COMP	(u8) 0x40
#define	MSENDEND	(u8) 0x20
#define	MVBUS		(u8) 0x10
#define	MIDNO		(u8) 0x0f

/* Masks for the each bit of STATUS register */
#define	MDCPORT		(u8) 0x80
#define	MCHPORT		(u8) 0x40

//typedef enum {
//	USIF_AP,	// 0
//	USIF_DP3T,	// 1
//} TYPE_USIF_MODE;

//typedef enum {
//	DP3T_NC,	// 0
//	DP3T_AP_UART,	// 1
//	DP3T_CP_UART,	// 2
//	DP3T_CP_USB,	// 3
//} TYPE_DP3T_MODE;

typedef enum {
	AP_UART,	//0
	USIF,		//1
} TYPE_UART_SW_MODE;

typedef enum {
	AP_USB,		//0
	CP_USB		//1
} TYPE_USB_SW_MODE;

//=========================================================

//===========================================================================
// Model dependent GPIO pin number
//kibum.lee@lge.com 20120502 MUIC re-work start
#define MUIC_INT_GPIO	40	// MUIC_INT_N

#if defined(CONFIG_PRODUCT_LGE_LU6800)
#define GPIO_DP3T_IN_1	38	// OMAP_UART_SW
#define GPIO_DP3T_IN_2	39	// IFX_UART_SW
#else
#define GPIO_DP3T_IN_1	161	// OMAP_UART_SW
#define GPIO_DP3T_IN_2	162	// IFX_UART_SW
#endif
#define GPIO_USIF_IN_1	182	// USIF1_SW
#define GPIO_IFX_USB_VBUS_EN	101	// IFX_VBUS_EN

#if defined(CONFIG_PRODUCT_LGE_LU6800)
#define USB_SW		38	//USB SW for LGT REVA2
#define UART_SW		39	//UART SW for LGT REVA2
#else
#define USB_SW		161	//USB SW for LGT REVA2
#define UART_SW		162	//UART SW for LGT REVA2
#endif
//kibum.lee@lge.com 20120502 MUIC re-work end

//===========================================================================



//===========================================================================
//
//===========================================================================

struct MUIC_device {
	struct i2c_client *client;
	struct task_struct *ts_task;
	struct hrtimer timer;
	wait_queue_head_t ts_wait;
	int polltime_expired;
	int irq_pending;
	int num_irq;
	int intr_gpio;
	int chr_num_irq;
	int chr_intr_gpio;
	int chr_en_gpio;
	spinlock_t ts_lock;
};

typedef enum
{
	CHR_TA ,
	CHR_FACTORY ,
	CHR_DIABLE
} CHR_MODE_TYPE;


#if 0
typedef enum
{
	MUIC_OPEN ,   // 0
	MUIC_CHRGER,   // 1
	MUIC_FACTORY_MODE ,   // 2
	MUIC_HAEDSET ,   // 3
	MUIC_USB ,   // 4
	MUIC_TV_OUT ,   // 5
	MUIC_FULL_USB ,   // 6
	MUIC_OTG ,   // 7
	MUIC_DEVELOP_MODE ,   // 8
	MUIC_RESERVE_1 ,
	MUIC_RESERVE_2 ,
	MUIC_RESERVE_3 ,
	MUIC_END ,
} MUIC_MODE_TYPE;

typedef enum
{
	DP3T_NC ,
	DP3T_S1_AP ,
	DP3T_S2_CP_SW ,
	DP3T_S3_CP_USB
} DP3T_MODE_TYPE;

#endif



max14526_device_type read_device_type (void);
void Set_MAX14526_Usb_Mode_Detect(void);
void MAX14526_Init(void);

