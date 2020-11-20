#pragma once
#include "libretro.h"

typedef void (*retro_set_environment_t)(retro_environment_t);
static retro_set_environment_t api_retro_set_environment = NULL;

typedef void (*retro_set_video_refresh_t)(retro_video_refresh_t);
static retro_set_video_refresh_t api_retro_set_video_refresh = NULL;

typedef void (*retro_set_audio_sample_t)(retro_audio_sample_t);
static retro_set_audio_sample_t api_retro_set_audio_sample = NULL;

typedef void (*retro_set_audio_sample_batch_t)(retro_audio_sample_batch_t);
static retro_set_audio_sample_batch_t api_retro_set_audio_sample_batch = NULL;

typedef void (*retro_set_input_poll_t)(retro_input_poll_t);
static retro_set_input_poll_t api_retro_set_input_poll = NULL;

typedef void (*retro_set_input_state_t)(retro_input_state_t);
static retro_set_input_state_t api_retro_set_input_state = NULL;

typedef void (*retro_init_t)(void);
static retro_init_t api_retro_init = NULL;

typedef void (*retro_deinit_t)(void);
static retro_deinit_t api_retro_deinit = NULL;

typedef unsigned (*retro_api_version_t)(void);
static retro_api_version_t api_retro_api_version = NULL;

typedef void (*retro_get_system_info_t)(struct retro_system_info* info);
static retro_get_system_info_t api_retro_get_system_info = NULL;

typedef void (*retro_get_system_av_info_t)(struct retro_system_av_info* info);
static retro_get_system_av_info_t api_retro_get_system_av_info = NULL;

typedef void (*retro_set_controller_port_device_t)(unsigned port, unsigned device);
static retro_set_controller_port_device_t api_retro_set_controller_port_device = NULL;

typedef void (*retro_reset_t)(void);
static retro_reset_t api_retro_reset = NULL;

typedef void (*retro_run_t)(void);
static retro_run_t api_retro_run = NULL;

typedef size_t (*retro_serialize_size_t)(void);
static retro_serialize_size_t api_retro_serialize_size = NULL;

typedef bool (*retro_serialize_t)(void* data, size_t size);
static retro_serialize_t api_retro_serialize = NULL;

typedef bool (*retro_unserialize_t)(const void* data, size_t size);
static retro_unserialize_t api_retro_unserialize = NULL;

typedef void (*retro_cheat_reset_t)(void);
static retro_cheat_reset_t api_retro_cheat_reset = NULL;

typedef void (*retro_cheat_set_t)(unsigned index, bool enabled, const char* code);
static retro_cheat_set_t api_retro_cheat_set = NULL;

typedef bool (*retro_load_game_t)(const struct retro_game_info* game);
static retro_load_game_t api_retro_load_game = NULL;

typedef bool (*retro_load_game_special_t)(
	unsigned game_type,
	const struct retro_game_info* info, size_t num_info
);
static retro_load_game_special_t api_retro_load_game_special = NULL;

typedef void (*retro_unload_game_t)(void);
static retro_unload_game_t api_retro_unload_game = NULL;

typedef unsigned (*retro_get_region_t)(void);
static retro_get_region_t api_retro_get_region = NULL;

typedef void* (*retro_get_memory_data_t)(unsigned id);
static retro_get_memory_data_t api_retro_get_memory_data = NULL;

typedef size_t (*retro_get_memory_size_t)(unsigned id);
static retro_get_memory_size_t api_retro_get_memory_size = NULL;
