#ifndef RAM_SEARCH_H
#define RAM_SEARCH_H

#ifdef __cplusplus
extern "C" {
#endif

//64k in Ram_68k[], 8k in Ram_Z80[]   
#define _68K_RAM_SIZE 64*1024
#define Z80_RAM_SIZE 8*1024
/*#define SRAM_SIZE (((SRAM_End - SRAM_Start) > 2) ? SRAM_End - SRAM_Start : 0)
#define BRAM_SIZE ((8 << BRAM_Ex_Size) * 1024)*/
#define GENESIS_RAM_SIZE (_68K_RAM_SIZE + Z80_RAM_SIZE)

//_32X_Ram[]
#define _32X_RAM_SIZE 256*1024

//512k in Ram_Prg, 256k in Ram_Word_1M and Ram_Word_2M
//(docs say 6Mbit of ram, but I'm not sure what's used when)
#define SEGACD_RAM_PRG_SIZE 512*1024
#define SEGACD_1M_RAM_SIZE 256*1024
#define SEGACD_2M_RAM_SIZE 256*1024
#define SEGACD_RAM_SIZE (SEGACD_RAM_PRG_SIZE + SEGACD_2M_RAM_SIZE)


//#define MAX_RAM_SIZE (0x112000)
#define MAX_RAM_SIZE (0xD2000)


extern char rs_type_size;
extern int ResultCount;

unsigned int sizeConv(unsigned int index,char size, char *prevSize = &rs_type_size, bool usePrev = false);
unsigned int GetRamValue(unsigned int Addr,char Size);
unsigned int HexStrToInt(char *);
void prune(char Search, char Operater, char Type, int Value, int OperatorParameter);
void CompactAddrs();
void reset_address_info();
void signal_new_frame();
void signal_new_size();
void UpdateRamSearchTitleBar(int percent = 0);
void SetRamSearchUndoType(HWND hDlg, int type);
unsigned int ReadValueAtHardwareAddress(unsigned int address, unsigned int size);
void WriteValueAtHardwareAdress(unsigned int address, unsigned int value, unsigned int size);
bool IsHardwareAddressValid(unsigned int address);
extern int curr_ram_size;
extern bool noMisalign;
extern bool littleEndian;

#ifdef __cplusplus
}
#endif

#endif

