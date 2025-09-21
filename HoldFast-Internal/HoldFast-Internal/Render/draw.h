#ifndef DRAW_H
#define DRAW_H

#include <Windows.h>
#include <iostream>
#include "../imgui/imgui.h"

namespace Draw {
	inline void draw_text_outline_font(float x, float y, ImColor color, const char* string, float size) {

		ImGui::GetBackgroundDrawList()->AddText(ImVec2(x - size, y), ImColor(0.0f, 0.0f, 0.0f, 255.f), string);
		ImGui::GetBackgroundDrawList()->AddText(ImVec2(x + size, y), ImColor(0.0f, 0.0f, 0.0f, 255.f), string);
		ImGui::GetBackgroundDrawList()->AddText(ImVec2(x, y - size), ImColor(0.0f, 0.0f, 0.0f, 255.f), string);
		ImGui::GetBackgroundDrawList()->AddText(ImVec2(x, y + size), ImColor(0.0f, 0.0f, 0.0f, 255.f), string);

		ImGui::GetBackgroundDrawList()->AddText(ImVec2(x, y), color, string);
	}
}
#endif