#pragma once
#include "RendererAPI.h"

/*
 *
 * Main class responsible for beginning scenes, ending scenes and also submitting vertexarray
 * which binds it and sends it to RendererAPI to draw
 * 
 */


namespace Hazel
{
	class Renderer
	{
	public:

		static void BeginScene();
		static void EndScene();

		static void Submit(const std::shared_ptr<VertexArray>& vertexArray);

		inline static RendererAPI::API GetAPI() { return RendererAPI::GetAPI(); }
	};
}
