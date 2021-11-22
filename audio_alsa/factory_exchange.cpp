#include "framework.h"

extern "C"
void audio_alsa_factory_exchange()
{

   add_factory_item < ::multimedia::audio_alsa::wave_in  , ::wave::in                  > ();

   add_factory_item < ::multimedia::audio_alsa::wave_out ,::wave::out                 > ();

}



