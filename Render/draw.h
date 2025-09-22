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
	inline void DrawCorneredBox(int X, int Y, int W, int H, const ImU32& color, int thickness)
	{
		float lineW = (W / 3);
		float lineH = (H / 3);



		// Enhanced corner lines with some extra length
		ImGui::GetBackgroundDrawList()->AddLine(ImVec2(X - 1, Y), ImVec2(X - 1, Y + lineH), ImGui::GetColorU32(color), thickness);
		ImGui::GetBackgroundDrawList()->AddLine(ImVec2(X - 1, Y), ImVec2(X + lineW, Y - 1), ImGui::GetColorU32(color), thickness);
		ImGui::GetBackgroundDrawList()->AddLine(ImVec2(X + W - lineW, Y - 1), ImVec2(X + W + 1, Y - 1), ImGui::GetColorU32(color), thickness);
		ImGui::GetBackgroundDrawList()->AddLine(ImVec2(X + W + 1, Y), ImVec2(X + W + 1, Y + lineH), ImGui::GetColorU32(color), thickness);
		ImGui::GetBackgroundDrawList()->AddLine(ImVec2(X - 1, Y + H - lineH), ImVec2(X - 1, Y + H + 1), ImGui::GetColorU32(color), thickness);
		ImGui::GetBackgroundDrawList()->AddLine(ImVec2(X - 1, Y + H + 1), ImVec2(X + lineW, Y + H + 1), ImGui::GetColorU32(color), thickness);
		ImGui::GetBackgroundDrawList()->AddLine(ImVec2(X + W - lineW, Y + H + 1), ImVec2(X + W + 1, Y + H + 1), ImGui::GetColorU32(color), thickness);
		ImGui::GetBackgroundDrawList()->AddLine(ImVec2(X + W + 1, Y + H - lineH), ImVec2(X + W + 1, Y + H + 1), ImGui::GetColorU32(color), thickness);
	}
}
#endif