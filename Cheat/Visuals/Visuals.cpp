#include "Visuals.h"

void HoldFast::Visuals::DrawVisuals(HoldFast::ClientRoundPlayer round_player) {
	ClientPlayerBase player_base = round_player.GetPlayerBase();
	if (!player_base.IsValid())return;

	RoundPlayerInformation player_information = player_base.GetCurrentRoundPlayerInformation();
	if (!player_information.IsValid())return;

	PlayerInitialDetails player_details = player_information.GetInitialDetails();
	if (!player_details.IsValid())return;

	PlayerActorInitializer player_actor = player_base.GetPlayerActorInitializer();
	if (!player_actor.IsValid())return;

	ModelProperties model_properties = player_actor.GetModelProperties();
	if (!model_properties.IsValid())return;

	BipedReferences player_bones = model_properties.GetBipedReferences();
	if (!player_bones.IsValid())return;

	Transformation head = player_bones.GetHead();
	if (!player_bones.GetHead().IsValid())return;

	Vector3 head_positon = player_bones.GetHead().GetPosition();
	if (head_positon.IsZero())return;
	
	std::string username = player_details.GetUsername();
	int rank = player_details.GetRank();

	float distance = (cache.local_player.GetPlayerBase().GetPlayerActorInitializer().GetModelProperties().GetBipedReferences().GetPelvis().GetPosition() - head.GetPosition()).Length();

	if (distance > HoldFast::Features::Visuals::render_distance)return;

	auto bounds = player_bones.get_bounds(5.0f, cache.view_matrix);
	if (bounds.onscreen) {
		ImDrawList* draw_list = ImGui::GetBackgroundDrawList();
		float box_width = bounds.right - bounds.left;
		float box_height = bounds.bottom - bounds.top;
		float center_x = bounds.left + box_width * 0.5f;

		if (HoldFast::Features::Visuals::box)
		{
			draw_list->AddRect(ImVec2(bounds.left - 2, bounds.top - 2), ImVec2(bounds.right + 2, bounds.bottom + 2), IM_COL32(0, 0, 0, 255));
			draw_list->AddRect(ImVec2(bounds.left - 1, bounds.top - 1), ImVec2(bounds.right + 1, bounds.bottom + 1), ImColor(255, 255, 255, 255));
		}

		if (HoldFast::Features::Visuals::corner_box) 
			Draw::DrawCorneredBox(bounds.left, bounds.top, box_width, box_height, ImColor(0, 0, 0, 255),2.5f);
			Draw::DrawCorneredBox(bounds.left, bounds.top, box_width, box_height, ImColor(255, 255, 255, 255),1.0f);
		
		
		float bottom_jump = 3.0f;
		if (HoldFast::Features::Visuals::distance) {
			bottom_jump += 12.0f;
			std::string text = std::string(std::to_string(int(distance)) + "M");
			ImVec2 size = ImGui::CalcTextSize(text.c_str());
			Draw::draw_text_outline_font(bounds.left + (box_width * 0.5f) - (size.x * 0.5f), bounds.bottom + 3, ImColor(255, 0, 0, 255), text.c_str(),1.0f);
		}

		if (HoldFast::Features::Visuals::name) {
			ImVec2 size = ImGui::CalcTextSize(username.c_str());
			Draw::draw_text_outline_font(bounds.left + (box_width * 0.5f) - (size.x * 0.5f), bounds.top - 10, ImColor(0, 255, 0, 255), username.c_str(), 1.0f);
		}

		if (HoldFast::Features::Visuals::rank) {
			std::string text = std::string(std::to_string(rank) + "RK");
			ImVec2 size = ImGui::CalcTextSize(text.c_str());
			Draw::draw_text_outline_font(bounds.left + (box_width * 0.5f) - (size.x * 0.5f), bounds.bottom + bottom_jump, ImColor(255, 0, 0, 255), text.c_str(), 1.0f);
		}

		if (HoldFast::Features::Visuals::skeleton) {

			Vector3 head_pos = player_bones.GetHead().GetPosition();
			Vector3 root_pos = player_bones.GetRoot().GetPosition();
			Vector3 pelvis_pos = player_bones.GetPelvis().GetPosition();
			Vector3 leftThigh_pos = player_bones.GetLeftThigh().GetPosition();
			Vector3 leftCalf_pos = player_bones.GetLeftCalf().GetPosition();
			Vector3 leftFoot_pos = player_bones.GetLeftFoot().GetPosition();
			Vector3 rightThigh_pos = player_bones.GetRightThigh().GetPosition();
			Vector3 rightCalf_pos = player_bones.GetRightCalf().GetPosition();
			Vector3 rightFoot_pos = player_bones.GetRightFoot().GetPosition();
			Vector3 leftUpperArm_pos = player_bones.GetLeftUpperArm().GetPosition();
			Vector3 leftForearm_pos = player_bones.GetLeftForearm().GetPosition();
			Vector3 leftHand_pos = player_bones.GetLeftHand().GetPosition();
			Vector3 rightUpperArm_pos = player_bones.GetRightUpperArm().GetPosition();
			Vector3 rightForearm_pos = player_bones.GetRightForearm().GetPosition();
			Vector3 rightHand_pos = player_bones.GetRightHand().GetPosition();
			Vector3 spine_pos = player_bones.GetHead().GetPosition(); 
			spine_pos.y -= .1f;

			if (
				head_pos.IsZero() || root_pos.IsZero() || pelvis_pos.IsZero() ||
				leftThigh_pos.IsZero() || leftCalf_pos.IsZero() || leftFoot_pos.IsZero() ||
				rightThigh_pos.IsZero() || rightCalf_pos.IsZero() || rightFoot_pos.IsZero() ||
				leftUpperArm_pos.IsZero() || leftForearm_pos.IsZero() || leftHand_pos.IsZero() ||
				rightUpperArm_pos.IsZero() || rightForearm_pos.IsZero() || rightHand_pos.IsZero() ||
				spine_pos.IsZero()
				) return;

			Vector2 head_s, root, pelvis, leftThigh, leftCalf, leftFoot;
			Vector2 rightThigh, rightCalf, rightFoot, leftUpperArm, leftForearm, leftHand;
			Vector2 rightUpperArm, rightForearm, rightHand, spine;

			if (
				!WorldToScreen(head_pos, head_s, cache.view_matrix) || !WorldToScreen(root_pos, root, cache.view_matrix) ||
				!WorldToScreen(pelvis_pos, pelvis, cache.view_matrix) || !WorldToScreen(leftThigh_pos, leftThigh, cache.view_matrix) ||
				!WorldToScreen(leftCalf_pos, leftCalf, cache.view_matrix) || !WorldToScreen(leftFoot_pos, leftFoot, cache.view_matrix) ||
				!WorldToScreen(rightThigh_pos, rightThigh, cache.view_matrix) || !WorldToScreen(rightCalf_pos, rightCalf, cache.view_matrix) ||
				!WorldToScreen(rightFoot_pos, rightFoot, cache.view_matrix) || !WorldToScreen(leftUpperArm_pos, leftUpperArm, cache.view_matrix) ||
				!WorldToScreen(leftForearm_pos, leftForearm, cache.view_matrix) || !WorldToScreen(leftHand_pos, leftHand, cache.view_matrix) ||
				!WorldToScreen(rightUpperArm_pos, rightUpperArm, cache.view_matrix) || !WorldToScreen(rightForearm_pos, rightForearm, cache.view_matrix) ||
				!WorldToScreen(rightHand_pos, rightHand, cache.view_matrix) || !WorldToScreen(spine_pos, spine, cache.view_matrix)
				) return;


			float t = ImGui::GetTime();
			float speed = 0.6f;
			float thickness = 2.0f;
			float outline_thickness = thickness + 1.5f;

			auto rainbow = [&](int index) -> ImColor {
				float hue = fmodf(t * speed + index * 0.05f, 1.0f);
				float r, g, b;
				ImGui::ColorConvertHSVtoRGB(hue, 1.0f, 1.0f, r, g, b);
				return ImColor((int)(r * 255), (int)(g * 255), (int)(b * 255), 255);
				};

			auto draw_line = [&](const Vector2& a, const Vector2& b, int i) {
				draw_list->AddLine(ImVec2(a.x, a.y), ImVec2(b.x, b.y), IM_COL32(0, 0, 0, 255), outline_thickness);
				draw_list->AddLine(ImVec2(a.x, a.y), ImVec2(b.x, b.y), rainbow(i), thickness);
				};

			int idx = 0;
			draw_line(head_s, spine, idx++);
			draw_line(spine, pelvis, idx++);

			draw_line(pelvis, leftThigh, idx++);
			draw_line(leftThigh, leftCalf, idx++);
			draw_line(leftCalf, leftFoot, idx++);

			draw_line(pelvis, rightThigh, idx++);
			draw_line(rightThigh, rightCalf, idx++);
			draw_line(rightCalf, rightFoot, idx++);

			draw_line(spine, leftUpperArm, idx++);
			draw_line(leftUpperArm, leftForearm, idx++);
			draw_line(leftForearm, leftHand, idx++);

			draw_line(spine, rightUpperArm, idx++);
			draw_line(rightUpperArm, rightForearm, idx++);
			draw_line(rightForearm, rightHand, idx++);
		}
	}
}
