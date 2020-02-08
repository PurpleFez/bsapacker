#include "SkyrimSEDummyPluginService.h"

namespace BsaPacker
{
	SkyrimSEDummyPluginService::SkyrimSEDummyPluginService(
			const IFileWriterService* fileWriterService,
			const IDummyPluginLogic* dummyPluginLogic)
		: m_FileWriterService(fileWriterService),
		  m_DummyPluginLogic(dummyPluginLogic)
	{
	}

	bool SkyrimSEDummyPluginService::CreatePlugin(const std::string& modPath, const std::string& archiveNameBase) const
	{
		const std::string& fileNameNoExtension = modPath + '/' + archiveNameBase;
		if (!this->m_DummyPluginLogic->canCreateDummyESP(fileNameNoExtension))
		{
			return false;
		}
		const std::string& absoluteFileName = fileNameNoExtension + ".esp";
		return this->m_FileWriterService->Write(absoluteFileName,
												reinterpret_cast<const char*>(SkyrimSEDummyPluginService::RAW_SKYRIMSE),
												sizeof(SkyrimSEDummyPluginService::RAW_SKYRIMSE));
	}
}
