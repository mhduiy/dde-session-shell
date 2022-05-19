/*
 * Copyright (C) 2021 ~ 2021 Deepin Technology Co., Ltd.
 *
 * Author:     wangfeia <wangfeia@uniontech.com>
 *             fanpengcheng <fanpengcheng@uniontech.com>
 *
 * Maintainer: wangfeia <wangfeia@uniontech.com>\
 *             fanpengcheng <fanpengcheng@uniontech.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef PWQUALITYMANAGER_H
#define PWQUALITYMANAGER_H

#include <QObject>

#include "deepin_pw_check.h"

class PwqualityManager : public QObject
{
    Q_OBJECT

public:
    typedef PW_ERROR_TYPE ERROR_TYPE;

    enum CheckType {
        Default,
        Grub2
    };
    static PwqualityManager* instance();

    ERROR_TYPE verifyPassword(const QString &user, const QString &password, CheckType checkType = Default);
    PASSWORD_LEVEL_TYPE newPassWdLevel(const QString &password) const;
    QString getErrorTips(ERROR_TYPE type, CheckType checkType = Default);

private:
    explicit PwqualityManager(QObject *parent = nullptr);
    PwqualityManager(const PwqualityManager &) = delete;
};

#endif // REMINDERDDIALOG_H