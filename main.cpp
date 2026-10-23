#include <iostream>
#include <windows.h>
#include <thread>
#include <chrono>

// Roblox'ni ochish
void openRoblox() {
    std::cout << ">> Roblox ishga tushirilmoqda...\n";
    // roblox-player protokolini ishga tushirish
    ShellExecuteA(NULL, "open", "roblox-player:1", NULL, NULL, SW_SHOWNORMAL);
}

// Menyuni ochish (Esc tugmasi)
void openSettingsMenu() {
    int waitTime = 12;
    std::cout << ">> Roblox to'liq ochilishi kutilmoqda (" << waitTime << " soniya)...\n";
    std::this_thread::sleep_for(std::chrono::seconds(waitTime));

    std::cout << ">> 'Esc' tugmasi bosilib, menyu ochilmoqda...\n";
    
    // Esc tugmasini bosish simulyatsiyasi
    keybd_event(VK_ESCAPE, 0, 0, 0); // Bosish
    keybd_event(VK_ESCAPE, 0, KEYEVENTF_KEYUP, 0); // Qo'yib yuborish
    
    std::this_thread::sleep_for(std::chrono::milliseconds(1500));
}

// Emailni harflab kiritish
void changeEmailInRoblox(const std::string& email) {
    std::cout << ">> Email kiritilmoqda: " << email << "\n";

    // Email matnidagi har bir belgini ketma-ket yozish
    for (char c : email) {
        SHORT vkey = VkKeyScanA(c);
        keybd_event(vkey, 0, 0, 0);
        keybd_event(vkey, 0, KEYEVENTF_KEYUP, 0);
        std::this_thread::sleep_for(std::chrono::milliseconds(50)); // Harflar orasidagi tezlik
    }

    // Enter tugmasini bosish
    keybd_event(VK_RETURN, 0, 0, 0);
    keybd_event(VK_RETURN, 0, KEYEVENTF_KEYUP, 0);
    
    std::cout << ">> Email yozildi va Enter bosildi!\n";
}

int main() {
    // Kod o'zbek tilidagi harflarni to'g'ri chiqarishi uchun (agar kerak bo'lsa)
    system("chcp 65001 > nul");

    std::string CUSTOM_EMAIL = "oybekpaxan@gmail.com";

    try {
        openRoblox();
        openSettingsMenu();
        changeEmailInRoblox(CUSTOM_EMAIL);
    } catch (const std::exception& e) {
        std::cout << "❌ Xatolik yuz berdi!\n";
    }

    return 0;
}
