#ifndef __SD_CARD_HEADER_H
#define __SD_CARD_HEADER_H

// Header inclusions ---------------------------------------------------------------------------------------------------

#include "nrfx_atomic.h"
#include "nrfx_spim.h"


// Public SD Card API --------------------------------------------------------------------------------------------------

bool sd_card_init(const nrfx_spim_t* spi_instance, nrfx_atomic_flag_t* sd_card_inserted_flag, const uint8_t* full_eui);
void sd_card_create_log(uint32_t current_time);
void sd_card_write(const char *data, uint16_t length, bool flush);
bool sd_card_list_files(char *file_name, uint32_t *file_size, uint8_t continuation);
bool sd_card_erase_file(const char *file_name);
bool sd_card_open_file_for_reading(const char *file_name);
void sd_card_close_reading_file(void);
uint32_t sd_card_get_reading_file_size_bytes(void);
uint32_t sd_card_read_reading_file(uint8_t *data_buffer, uint32_t buffer_length);
void log_ranges(const uint8_t *data, uint16_t length);
void log_battery(uint16_t battery_millivolts, uint32_t current_time, bool flush);
void log_charging(bool plugged_in, bool is_charging, uint32_t current_time, bool flush);
void log_motion(bool in_motion, uint32_t current_time, bool flush);

#endif // #ifndef __SD_CARD_HEADER_H
