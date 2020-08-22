#pragma once

#ifdef HZ_PLATFORM_WINDOWS

/*
 * This is the entry point and initializes the logging system.
 * Also creates an app, runs it and deletes it
 */

extern Hazel::Application* Hazel::CreateApplication();

int main(int arc, char** argv)
{
	Hazel::Log::Init();
	HZ_CORE_WARN("Initialized Log");
	int nice = 5;
	HZ_INFO("Initialized Log, Var{0}", nice);

	auto *app = Hazel::CreateApplication();
	app->Run();
	delete app;
}
#endif
