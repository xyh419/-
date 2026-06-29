/* generated vector source file - do not edit */
#include "bsp_api.h"
/* Do not build these data structures if no interrupts are currently allocated because IAR will have build errors. */
#if VECTOR_DATA_IRQ_COUNT > 0
        BSP_DONT_REMOVE const fsp_vector_t g_vector_table[BSP_ICU_VECTOR_NUM_ENTRIES] BSP_PLACE_IN_SECTION(BSP_SECTION_APPLICATION_VECTORS) =
        {
                        [0] = sci_b_uart_rxi_isr, /* SCI9 RXI (Receive data full) */
            [1] = sci_b_uart_txi_isr, /* SCI9 TXI (Transmit data empty) */
            [2] = sci_b_uart_tei_isr, /* SCI9 TEI (Transmit end) */
            [3] = sci_b_uart_eri_isr, /* SCI9 ERI (Receive error) */
            [4] = sci_b_spi_rxi_isr, /* SCI5 RXI (Receive data full) */
            [5] = sci_b_spi_txi_isr, /* SCI5 TXI (Transmit data empty) */
            [6] = sci_b_spi_tei_isr, /* SCI5 TEI (Transmit end) */
            [7] = sci_b_spi_eri_isr, /* SCI5 ERI (Receive error) */
            [8] = ceu_isr, /* CEU CEUI (CEU interrupt) */
            [9] = sdhimmc_accs_isr, /* SDHIMMC0 ACCS (Card access) */
            [10] = sdhimmc_card_isr, /* SDHIMMC0 CARD (Card detect) */
            [11] = dmac_int_isr, /* DMAC0 INT (DMAC0 transfer end) */
        };
        #if BSP_FEATURE_ICU_HAS_IELSR
        const bsp_interrupt_event_t g_interrupt_event_link_select[BSP_ICU_VECTOR_NUM_ENTRIES] =
        {
            [0] = BSP_PRV_VECT_ENUM(EVENT_SCI9_RXI,GROUP0), /* SCI9 RXI (Receive data full) */
            [1] = BSP_PRV_VECT_ENUM(EVENT_SCI9_TXI,GROUP1), /* SCI9 TXI (Transmit data empty) */
            [2] = BSP_PRV_VECT_ENUM(EVENT_SCI9_TEI,GROUP2), /* SCI9 TEI (Transmit end) */
            [3] = BSP_PRV_VECT_ENUM(EVENT_SCI9_ERI,GROUP3), /* SCI9 ERI (Receive error) */
            [4] = BSP_PRV_VECT_ENUM(EVENT_SCI5_RXI,GROUP4), /* SCI5 RXI (Receive data full) */
            [5] = BSP_PRV_VECT_ENUM(EVENT_SCI5_TXI,GROUP5), /* SCI5 TXI (Transmit data empty) */
            [6] = BSP_PRV_VECT_ENUM(EVENT_SCI5_TEI,GROUP6), /* SCI5 TEI (Transmit end) */
            [7] = BSP_PRV_VECT_ENUM(EVENT_SCI5_ERI,GROUP7), /* SCI5 ERI (Receive error) */
            [8] = BSP_PRV_VECT_ENUM(EVENT_CEU_CEUI,GROUP0), /* CEU CEUI (CEU interrupt) */
            [9] = BSP_PRV_VECT_ENUM(EVENT_SDHIMMC0_ACCS,GROUP1), /* SDHIMMC0 ACCS (Card access) */
            [10] = BSP_PRV_VECT_ENUM(EVENT_SDHIMMC0_CARD,GROUP2), /* SDHIMMC0 CARD (Card detect) */
            [11] = BSP_PRV_VECT_ENUM(EVENT_DMAC0_INT,GROUP3), /* DMAC0 INT (DMAC0 transfer end) */
        };
        #endif
        #endif
