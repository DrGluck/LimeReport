/***************************************************************************
 *   This file is part of the Lime Report project                          *
 *   Copyright (C) 2015 by Alexander Arin                                  *
 *   arin_a@bk.ru                                                          *
 *                                                                         *
 **                   GNU General Public License Usage                    **
 *                                                                         *
 *   This library is free software: you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation, either version 3 of the License, or     *
 *   (at your option) any later version.                                   *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program.  If not, see <http://www.gnu.org/licenses/>. *
 *                                                                         *
 **                  GNU Lesser General Public License                    **
 *                                                                         *
 *   This library is free software: you can redistribute it and/or modify  *
 *   it under the terms of the GNU Lesser General Public License as        *
 *   published by the Free Software Foundation, either version 3 of the    *
 *   License, or (at your option) any later version.                       *
 *   You should have received a copy of the GNU Lesser General Public      *
 *   License along with this library.                                      *
 *   If not, see <http://www.gnu.org/licenses/>.                           *
 *                                                                         *
 *   This library is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 ****************************************************************************/
#ifndef LRCONNECTIONDIALOG_H
#define LRCONNECTIONDIALOG_H

#include <QDialog>
#include "lrdatadesignintf.h"

namespace Ui {
    class ConnectionDialog;
}

class ConnectionDialog : public QDialog
{
    Q_OBJECT
public:
    explicit ConnectionDialog(LimeReport::IConnectionController* conControl, LimeReport::ConnectionDesc* connectionDesc=0, QWidget *parent = 0);
    ~ConnectionDialog();
protected:
    void showEvent(QShowEvent *);
    void init();
    void checkFieldsFill();
    bool checkConnection();
    LimeReport::ConnectionDesc* uiToConnection();
    void connectionToUI();
signals:
    void conectionRegistred(LimeReport::ConnectionDesc* connectionDesc);
private slots:
    void slotAccept();
    void slotCheckConnection();
    void on_toolButton_clicked();

private:
    Ui::ConnectionDialog *ui;
    LimeReport::ConnectionDesc* m_connection;
    bool m_changeMode;
    LimeReport::IConnectionController* m_controller;
};

#endif // LRCONNECTIONDIALOG_H
