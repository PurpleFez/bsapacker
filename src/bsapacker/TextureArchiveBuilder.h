#ifndef TEXTUREARCHIVEBUILDER_H
#define TEXTUREARCHIVEBUILDER_H

#include "bsapacker_global.h"
#include <bsapacker/IArchiveBuilder.h>
#include <bsapacker/IArchiveBuilderHelper.h>
#include <QDir>

namespace BsaPacker
{
	class BSAPACKER_EXPORT TextureArchiveBuilder : public IArchiveBuilder
	{
		Q_OBJECT
			Q_INTERFACES(BsaPacker::IEmitsValueChanged)

	public:
		TextureArchiveBuilder(const IArchiveBuilderHelper* archiveBuilderHelper, const QDir&, const bsa_archive_type_t& type);
		~TextureArchiveBuilder() override = default;
		TextureArchiveBuilder(const TextureArchiveBuilder&) = delete;
		TextureArchiveBuilder& operator=(const TextureArchiveBuilder&) = delete;
		TextureArchiveBuilder(TextureArchiveBuilder&&) = delete;
		TextureArchiveBuilder& operator=(TextureArchiveBuilder&&) = delete;

		uint32_t setFiles() override;
		void setShareData(bool) override;
		[[nodiscard]] std::unique_ptr<libbsarch::bs_archive_auto> getArchive() override;
		[[nodiscard]] uint32_t getFileCount() const override;
		[[nodiscard]] QString getRootPath() const override;

	public Q_SLOTS:
		void cancel() override;

	private:
		const IArchiveBuilderHelper* m_ArchiveBuilderHelper = nullptr;
		std::unique_ptr<libbsarch::bs_archive_auto> m_Archive;
		bool m_Cancelled;
		QDir m_RootDirectory;

		static void DDSCallback(bsa_archive_t archive, const wchar_t* file_path, bsa_dds_info_t* dds_info, void* context);
	};
} // namespace BsaPacker

#endif // TEXTUREARCHIVEBUILDER_H
