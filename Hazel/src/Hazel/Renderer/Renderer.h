#pragma once
#include "RendererAPI.h"
#include "OrthographicCamera.h"
#include "Shader.h"
/*
 *
 * Main class responsible for beginning scenes, ending scenes and also submitting vertexArray
 * which binds it and sends it to RendererAPI to draw
 * 
 */


namespace Hazel
{
	class Renderer
	{
	public:

		static void BeginScene(OrthographicCamera& camera);
		static void EndScene();

		static void Submit(const std::shared_ptr<VertexArray>& vertexArray, const std::shared_ptr<Shader>& shader,
		                   const glm::mat4& transform = glm::mat4(1.0f));

		inline static RendererAPI::API GetAPI() { return RendererAPI::GetAPI(); }

	private:
		struct SceneData
		{
			glm::mat4 ViewProjectionMatrix;
		};

		static SceneData* m_SceneData;
	};
}
