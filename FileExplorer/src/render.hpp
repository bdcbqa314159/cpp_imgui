#pragma once

#include <cstdint>
#include <filesystem>
#include <string_view>

namespace fs = std::filesystem;

class WindowClass
{
public:
    WindowClass() : currentPath(fs::current_path()), selectedEntry(fs::path{})
    {
    }

    void Draw(std::string_view label);

private:
    void DrawMenu();
    void DrawContent();
    void DrawActions();
    void DrawFilter();

    void openFileWithDefaultApplication();

    void renameFilePopup();
    void deleteFilePopup();

    bool renameFile(const fs::path &old, const fs::path &new_path);
    bool deleteFile(const fs::path &path);

private:
    fs::path currentPath{}, selectedEntry{};

    bool renameDialogOpen{false}, deleteDialogOpen{false};
};

void render(WindowClass &window_obj);
