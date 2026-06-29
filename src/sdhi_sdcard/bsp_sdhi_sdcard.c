/*
 * bsp_sdhi_sdcard.c
 *
 *  Created on: 2026年6月21日
 *      Author: 21068
 */
#include "sdhi_sdcard/bsp_sdhi_sdcard.h"

void SDcard_Init(void)
{
    fsp_err_t err= R_SDHI_Open(&g_sdmmc0_ctrl,&g_sdmmc0_cfg);
    assert(err == FSP_SUCCESS);
}

__IO uint32_t g_transfer_complete =0;
__IO uint32_t g_card_inserted = false;
__IO uint32_t g_erase_complete = 0;

void g_sdmmc0_callback(sdmmc_callback_args_t *p_args)
{
    if(SDMMC_EVENT_TRANSFER_COMPLETE == p_args->event)
    {
        g_transfer_complete=1;
    }
    if(SDMMC_EVENT_CARD_INSERTED == p_args->event)
    {
        g_card_inserted = true;
    }
    if(SDMMC_EVENT_CARD_REMOVED == p_args->event)
        {
            g_card_inserted = false;
        }
    if(SDMMC_EVENT_ERASE_COMPLETE == p_args->event)
            {
                  g_erase_complete = 1;
            }
    if(SDMMC_EVENT_ERASE_BUSY == p_args->event)
                {
                      g_erase_complete = 2;
                }

}


uint8_t g_dest[SDHI_MAX_BLOCK_SIZE] BSP_ALIGN_VARIABLE(4);
uint8_t g_src[SDHI_MAX_BLOCK_SIZE] BSP_ALIGN_VARIABLE(4);


void SDCard_Operation(void)
{
    uint32_t  i;
    sdmmc_status_t status;
    fsp_err_t  err;
    sdmmc_device_t my_sdmmc_device = {0};
    for(i=0 ; i<SDHI_MAX_BLOCK_SIZE;i++)
    {
        g_src[i] = (uint8_t)('A'+(uint8_t)(i%26));
    }
   err = R_SDHI_StatusGet(&g_sdmmc0_ctrl,&status);
   assert(err == FSP_SUCCESS);
   if(!status.card_inserted)
   {
       while(!g_card_inserted)
       {
           printf("\r\n请插入SD卡\r\n");
           R_BSP_SoftwareDelay(1000, BSP_DELAY_UNITS_MILLISECONDS);
       }
       printf("\r\n检测到SD卡已经插入\r\n");
   }
   R_BSP_SoftwareDelay(1, BSP_DELAY_UNITS_MILLISECONDS);
   err = R_SDHI_MediaInit(&g_sdmmc0_ctrl, &my_sdmmc_device);
   assert(err == FSP_SUCCESS);

  err = R_SDHI_Write(&g_sdmmc0_ctrl,g_src,1,1);
  assert(err == FSP_SUCCESS);
  while(g_transfer_complete == 0);
  g_transfer_complete =0;

  err = R_SDHI_Read(&g_sdmmc0_ctrl,g_dest,1,1);
  assert(err == FSP_SUCCESS);
  while(g_transfer_complete == 0);
    g_transfer_complete =0;

    for(i=0;i<SDHI_MAX_BLOCK_SIZE;i++)
    {
        if(i%26 == 0)
            printf(" ");
            printf("%c",g_dest[i]);
    }
    if(strncmp((char *)&g_dest[0],(char *)&g_src[0],SDHI_MAX_BLOCK_SIZE)==0)
    {
        printf("\r\nSD卡读写数据成功\r\n");
    }
    else
    {
        printf("\r\nSD卡读写数据失败\r\n");
    }
}


