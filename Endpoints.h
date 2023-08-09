bool FASTCALL_CONV ClientModeHooks::createMove(FASTCALL_THIS(csgo::ClientMode* thisptr), float inputSampleTime, csgo::UserCmd* cmd) noexcept
{
    features->misc.Spammer();  // After line 224
}