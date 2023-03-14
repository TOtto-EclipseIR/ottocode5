#include "SvgFile.h"

SvgFile::SvgFile()
{

}

void SvgFile::clear()
{
    mFileInfo = QFileInfo();
    if (mpFile)
    {
        mpFile->close();
        mpFile->deleteLater();
        mpFile = nullptr;
    }
    mBytes.clear();
    mDocument.clear();
    mBaseSize = QQSize(1024);
    mSizeImageMap.clear();
}
