/*
 * Copyright (C) 2021 ~ 2022 Uniontech Software Technology Co.,Ltd.
 *
 * Author:     zhaoyingzhen <zhaoyingzhen@uniontech.com>
 *
 * Maintainer: zhaoyingzhen <zhaoyingzhen@uniontech.com>
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
#ifndef USER_LIST_WIDGET_H
#define USER_LIST_WIDGET_H

#include <memory>
#include <DListView>

DWIDGET_USE_NAMESPACE

class User;
class SessionBaseModel;
class UserItemDelegate;
class QStandardItemModel;

/*!
 * \brief The UserListPopupWidget class
 */
class UserListPopupWidget : public DListView
{
    Q_OBJECT
public:
    explicit UserListPopupWidget(const SessionBaseModel *model, QWidget *parent = nullptr);

signals:
    void requestSwitchToUser(std::shared_ptr<User> user);

private slots:
    void userInfoChanged();
    void currentUserChanged(const std::shared_ptr<User> &user);

private:
    void initUI();
    void initConnections();
    void loadUsers();

    void handlerBeforeAddUser(const std::shared_ptr<User> &user);
    void addUser(const std::shared_ptr<User> &user);
    void removeUser(const std::shared_ptr<User> &user);
    void setItemData(QStandardItem *item, const User *user);
    QString accountStrType(int accountType) const;

    void updateViewWidth();
    void updateViewHeight();
    int calculateItemWidth();
    int stringWidth(const QString &str, int fontSize, bool isBold = false);

private:
    const SessionBaseModel *m_model;
    UserItemDelegate *m_userItemDelegate;
    QStandardItemModel *m_userItemModel;

    QMap<uid_t, QStandardItem *> m_userItemMap;
    std::shared_ptr<User> m_currentUser;
};

#endif // USER_LIST_WIDGET_H
