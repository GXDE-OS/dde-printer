// SPDX-FileCopyrightText: 2019 - 2022 UnionTech Software Technology Co., Ltd.
//
// SPDX-License-Identifier: GPL-3.0-or-later

#include "printerapplication.h"
#include "reviselogger.h"

#include <DApplication>
#include <DLog>

DWIDGET_USE_NAMESPACE
DCORE_USE_NAMESPACE

int main(int argc, char *argv[])
{

#if (DTK_VERSION >= DTK_VERSION_CHECK(5, 6, 8, 0))
    MLogger loggerConf;
#endif

    int iRet = 0;
    // Qt6中高DPI缩放默认启用，无需手动设置
    DApplication a(argc, argv);

    if (0 != g_printerApplication->create()) {
        qCritical() << "Create printer application failed";
        return -1;
    }

    if (0 != g_printerApplication->launchWithMode(a.arguments())) {
        qCritical() << "Init printer application failed";
        return -2;
    }
    // dtk6中主题保存功能已自动集成，无需手动设置

    iRet = a.exec();
    g_printerApplication->stop();

    return iRet;
}
