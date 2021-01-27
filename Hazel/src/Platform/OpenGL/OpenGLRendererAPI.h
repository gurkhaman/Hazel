#pragma once
#include "Hazel/Renderer/RendererAPI.h"

/*
	OpenGL specific Renderer API, contains glDraw, glClear
*/

namespace Hazel
{
	class OpenGLRendererAPI : public RendererAPI
	{
	public:
		virtual void Init() override;
		
		void SetClearColor(const glm::vec4& color) override;
		void Clear() override;

		void DrawIndexed(const Ref<VertexArray>& vertexArray) override;
	};
}
