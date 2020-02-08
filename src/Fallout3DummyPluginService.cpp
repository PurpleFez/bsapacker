#include "Fallout3DummyPluginService.h"

namespace BsaPacker
{
	Fallout3DummyPluginService::Fallout3DummyPluginService(
			const IFileWriterService* fileWriterService,
			const IDummyPluginLogic* dummyPluginLogic)
		: m_FileWriterService(fileWriterService),
		  m_DummyPluginLogic(dummyPluginLogic)
	{
	}

	bool Fallout3DummyPluginService::CreatePlugin(const std::string& modPath, const std::string& archiveNameBase) const
	{
		const std::string& fileNameNoExtension = modPath + '/' + archiveNameBase;
		if (!this->m_DummyPluginLogic->canCreateDummyESP(fileNameNoExtension))
		{
			return false;
		}
		const std::string& absoluteFileName = fileNameNoExtension + ".esp";
		return this->m_FileWriterService->Write(absoluteFileName,
												reinterpret_cast<const char*>(Fallout3DummyPluginService::RAW_FALLOUT3),
												sizeof(Fallout3DummyPluginService::RAW_FALLOUT3));
	}
}
