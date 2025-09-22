#ifndef RENDER_H
#define RENDER_H

#include <Windows.h>
#include <d3d11.h>
#include <dxgi.h>
#include "../kiero/kiero.h"
#include "../imgui/imgui.h"
#include "../imgui/imgui_impl_win32.h"
#include "../imgui/imgui_impl_dx11.h"

#include "../Cheat/Entry/Entry.h"


typedef HRESULT(__stdcall* Present) (IDXGISwapChain* pSwapChain, UINT SyncInterval, UINT Flags);
typedef LRESULT(CALLBACK* WNDPROC)(HWND, UINT, WPARAM, LPARAM);
typedef uintptr_t PTR;

extern LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

Present oPresent;
HWND window = NULL;
WNDPROC oWndProc;
ID3D11Device* pDevice = NULL;
ID3D11DeviceContext* pContext = NULL;
ID3D11RenderTargetView* mainRenderTargetView;

void InitImGui()
{
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO();
	io.ConfigFlags = ImGuiConfigFlags_NoMouseCursorChange;
	ImGui_ImplWin32_Init(window);
	ImGui_ImplDX11_Init(pDevice, pContext);
}

LRESULT __stdcall WndProc(const HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {

	if (true && ImGui_ImplWin32_WndProcHandler(hWnd, uMsg, wParam, lParam))
		return true;

	return CallWindowProc(oWndProc, hWnd, uMsg, wParam, lParam);
}

HRESULT __stdcall hkPresent(IDXGISwapChain* pSwapChain, UINT SyncInterval, UINT Flags)
{
	static bool init = false;
	if (!init)
	{
		if (SUCCEEDED(pSwapChain->GetDevice(__uuidof(ID3D11Device), (void**)&pDevice)))
		{
			pDevice->GetImmediateContext(&pContext);
			DXGI_SWAP_CHAIN_DESC sd;
			pSwapChain->GetDesc(&sd);
			window = sd.OutputWindow;
			ID3D11Texture2D* pBackBuffer;
			pSwapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), (LPVOID*)&pBackBuffer);
			pDevice->CreateRenderTargetView(pBackBuffer, NULL, &mainRenderTargetView);
			pBackBuffer->Release();
			oWndProc = (WNDPROC)SetWindowLongPtr(window, GWLP_WNDPROC, (LONG_PTR)WndProc);
			InitImGui();
			init = true;
		}

		else
			return oPresent(pSwapChain, SyncInterval, Flags);
	}
	ImGui_ImplDX11_NewFrame();
	ImGui_ImplWin32_NewFrame();
	ImGui::NewFrame();
	static bool draw_menu = false;
	if (GetAsyncKeyState(VK_INSERT) & 0x1)
		draw_menu = !draw_menu;

	if (draw_menu) {
		ImGui::Begin("HoldFast Internal");
		ImGui::Checkbox("box", &HoldFast::Features::Visuals::box);
		ImGui::Checkbox("corner box", &HoldFast::Features::Visuals::corner_box);
		ImGui::Checkbox("distance", &HoldFast::Features::Visuals::distance);
		ImGui::Checkbox("username", &HoldFast::Features::Visuals::name);
		ImGui::Checkbox("rank", &HoldFast::Features::Visuals::rank);
		ImGui::Checkbox("held item", &HoldFast::Features::Visuals::held_item);
		ImGui::Checkbox("health bar", &HoldFast::Features::Visuals::health);
		ImGui::Checkbox("skeleton", &HoldFast::Features::Visuals::skeleton);
		ImGui::Checkbox("remove team", &HoldFast::Features::Visuals::remove_team);
		ImGui::End();
	}
	Draw::draw_text_outline_font(25, 25, ImColor(255, 0, 155, 255), "HoldFast Legend Hack", 1.0f);
	//draw
	HoldFast::Entry::DoCheat();

	ImGui::Render();

	pContext->OMSetRenderTargets(1, &mainRenderTargetView, NULL);
	ImGui_ImplDX11_RenderDrawData(ImGui::GetDrawData());
	return oPresent(pSwapChain, SyncInterval, Flags);
}

#endif