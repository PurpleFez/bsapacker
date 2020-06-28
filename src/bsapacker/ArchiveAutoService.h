#ifndef ARCHIVEAUTOSERVICE_H
#define ARCHIVEAUTOSERVICE_H

#include "bsapacker_global.h"
#include <bsapacker/IArchiveAutoService.h>

namespace BsaPacker
{
	class BSAPACKER_EXPORT ArchiveAutoService : public IArchiveAutoService
	{
	public:
		ArchiveAutoService() = default;
		void CreateBSA(libbsarch::bs_archive_auto* archive, const QString& archiveName, bsa_archive_type_e type) const override;
	};
} // namespace BsaPacker

#endif // ARCHIVEAUTOSERVICE_H
