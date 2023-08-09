struct MiscConfig {
    bool Spammer{ false };  // Add after line 116

    std::string SpamString{ "ChE47ing f0r fRe3, uSiNG Os1RIs" };  // Add after line 145
}

// Add after killMessage at line 706
void Misc::Spammer() noexcept
{
    if (!miscConfig.Spammer)
        return;

    if (!localPlayer)
        return;

    // Idea from ReportBot
    static auto lastSpamTime = 0.0f;
    static auto SpamDelay = 2;

    if (lastSpamTime + SpamDelay > memory.globalVars->realtime)
        return;

     // Idea from KillMessage
    {
        std::string cmd = "say \"";
        cmd += miscConfig.SpamString;
        cmd += '"';
        engineInterfaces.getEngine().clientCmdUnrestricted(cmd.c_str());
        lastSpamTime = memory.globalVars->realtime;
    }
   
}

// After line 1300
void Misc::drawGUI(Visuals& visuals, inventory_changer::InventoryChanger& inventoryChanger, Glow& glow, bool contentOnly) noexcept
{
    // Add after killMessage
    ImGui::Checkbox("Spammer", &miscConfig.Spammer);
    if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
    {
        ImGui::SetTooltip("Repeatedly sending spam messages");
    }
    ImGui::SameLine();
    ImGui::PushItemWidth(200.0f);
    ImGui::PushID("Spammer");
    ImGui::InputText("", &miscConfig.SpamString);
    ImGui::PopID();
    ImGui::PushItemWidth(120.0f);
}

// After line 1800
static void from_json(const json& j, MiscConfig& m)
{
    read(j, "Spammer", m.Spammer);
    read<value_t::string>(j, "Spam string", m.SpamString);
}

// After line 1900
static void to_json(json& j, const MiscConfig& o)
{
    WRITE("Spammer", Spammer);
    WRITE("Spam string", SpamString);
}