#include <SdlAudio.h>
#include <SDL_mixer.h>
#include <Engine.h>

/// <summary>
/// Constructor for SDL audio
/// </summary>
ProjetEngin::SdlAudio::SdlAudio()
{
    Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, 2, 1024);
}

/// <summary>
/// Destructor for SDL audio
/// </summary>
ProjetEngin::SdlAudio::~SdlAudio()
{
    Mix_CloseAudio();
}

/// <summary>
/// Load music through the file name in the params
/// </summary>
/// <param name="filename">= the name of the file you want to use, including the file path</param>
/// <returns></returns>
size_t ProjetEngin::SdlAudio::LoadMusic(const std::string& filename)
{
    const size_t _musId = std::hash<std::string>()(filename);
    if (m_MusicCache.count(_musId) > 0)
    {
        return _musId;
    }

    Mix_Music* _mus = Mix_LoadMUS(filename.c_str());
    if (_mus)
    {
        m_MusicCache.emplace(_musId, _mus);
        return _musId;
    }

    ProjetEngin::Engine::Get()->Logger().Log("Error with music: " + filename);
    ProjetEngin::Engine::Get()->Logger().Log(Mix_GetError());

    return 0;
}

/// <summary>
/// Load sound through the file name in the params
/// </summary>
/// <param name="filename">= the name of the file you want to use, including the file path</param>
/// <returns></returns>
size_t ProjetEngin::SdlAudio::LoadSound(const std::string& filename)
{
    const size_t _sfxId = std::hash<std::string>()(filename);
    if (m_SoundCache.count(_sfxId) > 0)
    {
        return _sfxId;
    }

    Mix_Chunk* _sfx = Mix_LoadWAV(filename.c_str());
    if (_sfx)
    {
        m_SoundCache.emplace(_sfxId, _sfx);
        return _sfxId;
    }

    ProjetEngin::Engine::Get()->Logger().Log("Error with sfx: " + filename);
    ProjetEngin::Engine::Get()->Logger().Log(Mix_GetError());
    return 0;
}

/// <summary>
/// Play the music from the ID in the params
/// </summary>
/// <param name="id">= the ID for the music to be played</param>
void ProjetEngin::SdlAudio::PlayMusic(size_t id)
{
    PlayMusic(id, -1);
}

/// <summary>
/// Plays the music from the ID in the params, with the number of loops it's supposed to repeat
/// </summary>
/// <param name="id">= ID for the music you want to play</param>
/// <param name="loop">= the number of loops you want it to have</param>
void ProjetEngin::SdlAudio::PlayMusic(size_t id, int loop)
{
    Mix_PlayMusic(m_MusicCache[id], loop);
}

/// <summary>
/// Plays the sound from the ID in the params
/// </summary>
/// <param name="id">= the ID of the sound you want to play</param>
void ProjetEngin::SdlAudio::PlaySFX(size_t id)
{
    PlaySFX(id, 0);
}

/// <summary>
/// Plays the sound from the ID in the params, with the number of loops in the params
/// </summary>
/// <param name="id">= the ID of the sound</param>
/// <param name="loop">= the number of loops</param>
void ProjetEngin::SdlAudio::PlaySFX(size_t id, int loop)
{
    Mix_PlayChannel(-1, m_SoundCache[id], loop);
}

/// <summary>
/// Pauses the music currently playing
/// </summary>
void ProjetEngin::SdlAudio::PauseMusic()
{
    Mix_PauseMusic();
}

/// <summary>
/// stops the music currently playing, reseting it to 0 time
/// </summary>
void ProjetEngin::SdlAudio::StopMusic()
{
    Mix_HaltMusic();
}

/// <summary>
/// Plays the music again, from where is was: 0 if stop was used, where ever else if resume was used
/// </summary>
void ProjetEngin::SdlAudio::ResumeMusic()
{
    Mix_ResumeMusic();
}

/// <summary>
/// sets the volume of the music to be played
/// </summary>
/// <param name="volume">= desired volume</param>
void ProjetEngin::SdlAudio::SetVolume(int volume)
{
    Mix_VolumeMusic(volume);
}

/// <summary>
/// Sets the volume of the sounds to be played, individually
/// </summary>
/// <param name="soundId">= the sound's ID</param>
/// <param name="volume">= desired volume</param>
void ProjetEngin::SdlAudio::SetVolume(size_t soundId, int volume)
{
    Mix_VolumeChunk(m_SoundCache[soundId], volume);
}