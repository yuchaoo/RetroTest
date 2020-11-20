#include <Windows.h>
#include <iostream>
#include "retro_api.h"

void default_log(const char* format, ...) {
	static char text[256];
	va_list args;
	va_start(args, format);
	vsnprintf(text, sizeof(text), format, args);
	va_end(args);
	printf("%s\n", text);
}

void retro_log(enum retro_log_level level, const char* format, ...) {
	static char text[256];
	va_list args;
	va_start(args, format);
	vsnprintf(text, sizeof(text), format, args);
	va_end(args);
	printf("%s\n", text);
}

void retro_audio_sample_callback(int16_t left, int16_t right) {
	printf("retro_audio_sample_callback , left=%d, right=%d\n", left, right);
}

size_t retro_audio_sample_batch_callback(const int16_t* data, size_t frames) {
	printf("retro_audio_sample_batch_callback, frames = %lld\n",frames);
	return 0;
}

retro_controller_info* controller_infos = NULL;

bool retro_environment_callback(unsigned cmd, void* data) {
	printf("retro_environment_callback , cmd = %u\n",cmd);
	if (cmd == RETRO_ENVIRONMENT_GET_LOG_INTERFACE) {
		retro_log_callback* logcb = (retro_log_callback*)data;
		logcb->log = retro_log;
		default_log("set retro log callback");
	}
	else if (cmd == RETRO_ENVIRONMENT_SET_CONTROLLER_INFO) {
		controller_infos = (retro_controller_info*)(data);
		default_log("set retro controller info");
	}
	else if (cmd == RETRO_ENVIRONMENT_SET_SUPPORT_ACHIEVEMENTS) {
		bool bSupport = *(bool*)data;
		default_log("support achievements:%d", bSupport);
	}
	else if (cmd == RETRO_ENVIRONMENT_GET_INPUT_BITMASKS) {
		default_log("get input bitmasks : true");
	}
	else if (cmd == RETRO_ENVIRONMENT_SET_PIXEL_FORMAT) {
		*(int*)data = retro_pixel_format::RETRO_PIXEL_FORMAT_XRGB8888;
		default_log("set pixel format:%d", *(int*)data);
	}
	else if (cmd == RETRO_ENVIRONMENT_SET_PERFORMANCE_LEVEL) {
		default_log("set performance level:%d", *(int*)data);
	}
	else if (cmd == RETRO_ENVIRONMENT_SET_INPUT_DESCRIPTORS) {
		default_log("set input descriptors");
	}
	else if (cmd == RETRO_ENVIRONMENT_GET_SYSTEM_DIRECTORY) {
		default_log("set system dir");
		const char* dir = "./";
		*(char**)(data) = (char*)dir;
	}
	else if (cmd == RETRO_ENVIRONMENT_GET_SAVE_DIRECTORY) {
		default_log("set save dir");
		const char* dir = "./";
		*(char**)(data) = (char*)dir;
	}
	else if (cmd == RETRO_ENVIRONMENT_GET_CORE_OPTIONS_VERSION) {
		*(int*)data = 1;
		default_log("set core options version:%d",*(int*)data);
	}
	else if (cmd == RETRO_ENVIRONMENT_GET_LANGUAGE) {
		*(int*)data = RETRO_LANGUAGE_ENGLISH;
		default_log("set language:%d",*(int*)data);
	}
	else if (cmd == RETRO_ENVIRONMENT_SET_CORE_OPTIONS_INTL) {
		default_log("set core options intl");
	}
	else if (cmd == RETRO_ENVIRONMENT_GET_VARIABLE) {
		retro_variable* ra = (retro_variable*)data;
		if (!strcmp(ra->key, "fceumm_ramstate")) {
			ra->value = "random";
		}
		else if (!strcmp(ra->key, "fceumm_ntsc_filter")) {
			ra->value = "disabled";
		}
		else if (!strcmp(ra->key, "fceumm_palette")) {
			ra->value = "default";
		}
		else if (!strcmp(ra->key, "fceumm_up_down_allowed")) {
			ra->value = "enabled";
		}
		else if (!strcmp(ra->key, "fceumm_nospritelimit")) {
			ra->value = "enabled";
		}
		else if (!strcmp(ra->key, "fceumm_overclocking")) {
			ra->value = "disabled";
		}
		else if (!strcmp(ra->key, "fceumm_zapper_mode")) {
			ra->value = "mouse";
		}
		else if (!strcmp(ra->key, "fceumm_zapper_tolerance")) {
			ra->value = NULL;
		}
		else if (!strcmp(ra->key, "fceumm_region")) {
			ra->value = "Auto";
		}
		else if (!strcmp(ra->key, "fceumm_show_crosshair")) {
			ra->value = "enabled";
		}
		else if (!strcmp(ra->key, "fceumm_overscan_h")) {
			ra->value = "enabled";
		}
		else if (!strcmp(ra->key, "fceumm_overscan_v")) {
			ra->value = "enabled";
		}
		else if (!strcmp(ra->key, "fceumm_aspect")) {
			ra->value = "8:7 PAR";
		}
		else if (!strcmp(ra->key, "fceumm_turbo_enable")) {
			ra->value = "Player 1";
		}
		else if (!strcmp(ra->key, "fceumm_turbo_delay")) {
			ra->value = "0";
		}
		else if (!strcmp(ra->key, "fceumm_sndquality")) {
			ra->value = "High";
		}
		else if (!strcmp(ra->key, "fceumm_sndvolume")) {
			ra->value = "0.1f";
		}
		else if (!strcmp(ra->key, "fceumm_swapduty")) {
			ra->value = "enabled";
		}
		else if (!strncmp(ra->key, "fceumm_apu_", 11)) {
			ra->value = "disabled";
		}
		else if (!strcmp(ra->key, "fceumm_show_adv_system_options")) {
			ra->value = "enabled";
		}
		else if (!strcmp(ra->key, "fceumm_show_adv_sound_options")) {
			ra->value = "enabled";
		}
		
		default_log("set variable:%s",ra->key);
	}
	else if (cmd == RETRO_ENVIRONMENT_SET_CORE_OPTIONS_DISPLAY) {
		default_log("set core options display");
	}
	else {
		default_log("ddd");
	}
	return true;
}

void retro_input_poll_callback(void) {
	printf("retro_input_poll_callback, retro_input_poll_callback\n");
}

int16_t retro_input_state_callback(unsigned port, unsigned device, unsigned index, unsigned id) {
	printf("retro_input_state_callback, port:%d, device:%d, index:%d, id:%d", port, device, index, id);
	return 0;
}

void retro_video_refresh_callback(const void* data, unsigned width, unsigned height, size_t pitch) {
	printf("retro_video_refresh_callback, width:%u, height:%u, pitch:%lld",width,height,pitch);
}


int main(int argc, char** args) {
	/*HINSTANCE hand = LoadLibrary(TEXT("E:\\project\\RetroTest\\RetroTest\\fceumm_libretro.dll"));
	if (!hand) {
		printf("load dll failed\n");
		return 0;
	}

	api_retro_set_environment = (retro_set_environment_t)GetProcAddress(hand, "retro_set_environment");
	api_retro_set_video_refresh = (retro_set_video_refresh_t)GetProcAddress(hand, "retro_set_video_refresh");
	api_retro_set_audio_sample = (retro_set_audio_sample_t)GetProcAddress(hand, "retro_set_audio_sample");
	api_retro_set_audio_sample_batch = (retro_set_audio_sample_batch_t)GetProcAddress(hand, "retro_set_audio_sample_batch");
	api_retro_set_input_poll = (retro_set_input_poll_t)GetProcAddress(hand, "retro_set_input_poll");
	api_retro_set_input_state = (retro_set_input_state_t)GetProcAddress(hand, "retro_set_input_state");
	api_retro_init = (retro_init_t)GetProcAddress(hand, "retro_init");
	api_retro_deinit = (retro_deinit_t)GetProcAddress(hand, "retro_deinit");
	api_retro_api_version = (retro_api_version_t)GetProcAddress(hand, "retro_api_version");
	api_retro_get_system_info = (retro_get_system_info_t)GetProcAddress(hand, "retro_get_system_info");
	api_retro_get_system_av_info = (retro_get_system_av_info_t)GetProcAddress(hand, "retro_get_system_av_info");
	api_retro_set_controller_port_device = (retro_set_controller_port_device_t)GetProcAddress(hand, "retro_set_controller_port_device");
	api_retro_reset = (retro_reset_t)GetProcAddress(hand, "retro_reset");
	api_retro_run = (retro_run_t)GetProcAddress(hand, "retro_run");
	api_retro_serialize_size = (retro_serialize_size_t)GetProcAddress(hand, "retro_serialize_size");
	api_retro_unserialize = (retro_unserialize_t)GetProcAddress(hand, "retro_unserialize");
	api_retro_cheat_reset = (retro_cheat_reset_t)GetProcAddress(hand, "retro_cheat_reset");
	api_retro_cheat_set = (retro_cheat_set_t)GetProcAddress(hand, "retro_cheat_set");
	api_retro_load_game = (retro_load_game_t)GetProcAddress(hand, "retro_load_game");
	api_retro_load_game_special = (retro_load_game_special_t)GetProcAddress(hand, "retro_load_game_special");
	api_retro_unload_game = (retro_unload_game_t)GetProcAddress(hand, "retro_unload_game");
	api_retro_get_region = (retro_get_region_t)GetProcAddress(hand, "retro_get_region");
	api_retro_get_memory_data = (retro_get_memory_data_t)GetProcAddress(hand, "retro_get_memory_data");
	api_retro_get_memory_size = (retro_get_memory_size_t)GetProcAddress(hand, "retro_get_memory_size");
	*/
	unsigned version = retro_api_version();
	printf("version = %d", version);

	retro_set_audio_sample(retro_audio_sample_callback);
	retro_set_audio_sample_batch(retro_audio_sample_batch_callback);
	retro_set_environment(retro_environment_callback);
	retro_set_input_poll(retro_input_poll_callback);
	retro_set_input_state(retro_input_state_callback);
	retro_set_video_refresh(retro_video_refresh_callback);
	retro_init();

	//api_retro_set_controller_port_device()

	retro_system_info info;
	info.block_extract = true;
	info.library_name = NULL;
	info.library_version = NULL;
	info.valid_extensions = "bin";
	info.need_fullpath = true;
	retro_get_system_info(&info);
	info.need_fullpath = true;
	info.block_extract = true;

	/*FILE* file = fopen("E:\\project\\RetroTest\\RetroTest\\test.nes","rb");
	if (!file) {
		printf("open file failed\n");
		return 0;
	}

	fseek(file, 0, SEEK_END);
	size_t size = ftell(file);
	fseek(file, 0, SEEK_SET);

	char* data = new char[size];
	fread(data, 1, size, file);
	fclose(file);*/

	retro_game_info game_info;
	game_info.path = "E:\\project\\RetroTest\\RetroTest\\3-D Battles of World Runner, The (U).nes";
	game_info.data = NULL;
	game_info.meta = NULL;
	game_info.size = 0;



	bool ret = retro_load_game(&game_info);
	if (ret) {
		retro_system_av_info av_info;
		retro_get_system_av_info(&av_info);

		while (1) {
			retro_run();
		}
	}
	
	//FreeLibrary(hand);
}