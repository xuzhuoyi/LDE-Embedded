/****************************************************************************
**
** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies).
** Contact: http://www.qt-project.org/legal
**
** This file is part of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:BSD$
** You may use this file under the terms of the BSD license as follows:
**
** "Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are
** met:
**   * Redistributions of source code must retain the above copyright
**     notice, this list of conditions and the following disclaimer.
**   * Redistributions in binary form must reproduce the above copyright
**     notice, this list of conditions and the following disclaimer in
**     the documentation and/or other materials provided with the
**     distribution.
**   * Neither the name of Digia Plc and its Subsidiary(-ies) nor the names
**     of its contributors may be used to endorse or promote products derived
**     from this software without specific prior written permission.
**
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
**
** $QT_END_LICENSE$
**
****************************************************************************/

#include <QtWidgets>
#include <QtNetwork>
#include <QtWebKitWidgets>
#include "mainwindow.h"

int windowNum;

//! [1]

MainWindow::MainWindow(const QUrl& url)
{
    progress = 0;

    QFile file;
    file.setFileName(":/jquery.min.js");
    file.open(QIODevice::ReadOnly);
    jQuery = file.readAll();
    jQuery.append("\nvar qt = { 'jQuery': jQuery.noConflict(true) };");
    file.close();
//! [1]

    QNetworkProxyFactory::setUseSystemConfiguration(true);

//! [2]
    view = new QWebView(this);
    view->load(url);
    connect(view, SIGNAL(loadFinished(bool)), SLOT(adjustLocation()));
    connect(view, SIGNAL(titleChanged(QString)), SLOT(adjustTitle()));
    connect(view, SIGNAL(loadProgress(int)), SLOT(setProgress(int)));
    connect(view, SIGNAL(loadFinished(bool)), SLOT(finishLoading(bool)));

    locationEdit = new QLineEdit(this);
    locationEdit->setSizePolicy(QSizePolicy::Expanding, locationEdit->sizePolicy().verticalPolicy());
    connect(locationEdit, SIGNAL(returnPressed()), SLOT(changeLocation()));

    QAction *closeWindowAction = new QAction(tr("关闭窗口"),this);
    QToolBar *toolBar = addToolBar(tr("导航"));
    toolBar->addAction(view->pageAction(QWebPage::Back));
    toolBar->addAction(view->pageAction(QWebPage::Forward));
    toolBar->addAction(view->pageAction(QWebPage::Reload));
    toolBar->addAction(view->pageAction(QWebPage::Stop));
    toolBar->addAction(closeWindowAction);
    toolBar->addWidget(locationEdit);
//! [2]
    QMenu *fileMenu = menuBar()->addMenu(tr("文件(&F)"));
    QAction *newWindowAction = new QAction(tr("新建窗口"),this);
    connect(newWindowAction, SIGNAL(triggered()),SLOT(newWindow()));
    fileMenu->addAction(newWindowAction);

    connect(closeWindowAction, SIGNAL(triggered()),SLOT(closeWindow()));
    fileMenu->addAction(closeWindowAction);

    QMenu *viewMenu = menuBar()->addMenu(tr("查看(&V)"));
    QAction* viewSourceAction = new QAction(tr("页面源代码"), this);
    connect(viewSourceAction, SIGNAL(triggered()), SLOT(viewSource()));
    viewMenu->addAction(view->pageAction(QWebPage::Stop));
    viewMenu->addAction(view->pageAction(QWebPage::Reload));
    viewMenu->addSeparator();
    viewMenu->addAction(viewSourceAction);

//! [3]

    QMenu *historyMenu = menuBar()->addMenu(tr("历史(&H)"));
    historyMenu->addAction(view->pageAction(QWebPage::Back));
    historyMenu->addAction(view->pageAction(QWebPage::Forward));

    QMenu *effectMenu = menuBar()->addMenu(tr("效果(&E)"));
    effectMenu->addAction(tr("高亮所有链接"), this, SLOT(highlightAllLinks()));
    rotateAction = new QAction(this);
    rotateAction->setIcon(style()->standardIcon(QStyle::SP_FileDialogDetailedView));
    rotateAction->setCheckable(true);
    rotateAction->setText(tr("倒转图像"));
    connect(rotateAction, SIGNAL(toggled(bool)), this, SLOT(rotateImages(bool)));
    effectMenu->addAction(rotateAction);

    QMenu *toolsMenu = menuBar()->addMenu(tr("工具(&T)"));
    toolsMenu->addAction(tr("移除 GIF 动画"), this, SLOT(removeGifImages()));
    toolsMenu->addAction(tr("移除所有内联框架"), this, SLOT(removeInlineFrames()));
    toolsMenu->addAction(tr("移除所有对象元素"), this, SLOT(removeObjectElements()));
    toolsMenu->addAction(tr("移除所有嵌入元素"), this, SLOT(removeEmbeddedElements()));

	QMenu *helpMenu = menuBar()->addMenu(tr("帮助(&H)"));
	helpMenu->addAction(tr("关于 Looplorer"), this, SLOT(aboutLooplorer()));

	setCentralWidget(view);
    setUnifiedTitleAndToolBarOnMac(true);

	view->page()->setLinkDelegationPolicy(QWebPage::DelegateAllLinks);
	clickLink();

    windowNum++;

}
//! [3]

MainWindow::~MainWindow()
{
    windowNum--;
}

void MainWindow::viewSource()
{
    QNetworkAccessManager* accessManager = view->page()->networkAccessManager();
    QNetworkRequest request(view->url());
    QNetworkReply* reply = accessManager->get(request);
    connect(reply, SIGNAL(finished()), this, SLOT(slotSourceDownloaded()));
}

void MainWindow::slotSourceDownloaded()
{
    QNetworkReply* reply = qobject_cast<QNetworkReply*>(const_cast<QObject*>(sender()));
    QTextEdit* textEdit = new QTextEdit(NULL);
    textEdit->setAttribute(Qt::WA_DeleteOnClose);
    textEdit->show();
    textEdit->setPlainText(reply->readAll());
    reply->deleteLater();
}

//! [4]
void MainWindow::adjustLocation()
{
    locationEdit->setText(view->url().toString());
}

void MainWindow::changeLocation()
{
    QUrl url = QUrl::fromUserInput(locationEdit->text());
    view->load(url);
    view->setFocus();
}
//! [4]

//! [5]
void MainWindow::adjustTitle()
{
    if (progress <= 0 || progress >= 100)
        setWindowTitle(view->title());
    else
        setWindowTitle(QString("%1 (%2%)").arg(view->title()).arg(progress));
}

void MainWindow::setProgress(int p)
{
    progress = p;
    adjustTitle();
}
//! [5]

//! [6]
void MainWindow::finishLoading(bool)
{
    progress = 100;
    adjustTitle();
    view->page()->mainFrame()->evaluateJavaScript(jQuery);

    rotateImages(rotateAction->isChecked());
}
//! [6]

//! [7]
void MainWindow::highlightAllLinks()
{
    // We append '; undefined' after the jQuery call here to prevent a possible recursion loop and crash caused by
    // the way the elements returned by the each iterator elements reference each other, which causes problems upon
    // converting them to QVariants.
    QString code = "qt.jQuery('a').each( function () { qt.jQuery(this).css('background-color', 'yellow') } ); undefined";
    view->page()->mainFrame()->evaluateJavaScript(code);
}
//! [7]

//! [8]
void MainWindow::rotateImages(bool invert)
{
    QString code;

    // We append '; undefined' after each of the jQuery calls here to prevent a possible recursion loop and crash caused by
    // the way the elements returned by the each iterator elements reference each other, which causes problems upon
    // converting them to QVariants.
    if (invert)
        code = "qt.jQuery('img').each( function () { qt.jQuery(this).css('-webkit-transition', '-webkit-transform 2s'); qt.jQuery(this).css('-webkit-transform', 'rotate(180deg)') } ); undefined";
    else
        code = "qt.jQuery('img').each( function () { qt.jQuery(this).css('-webkit-transition', '-webkit-transform 2s'); qt.jQuery(this).css('-webkit-transform', 'rotate(0deg)') } ); undefined";
    view->page()->mainFrame()->evaluateJavaScript(code);
}
//! [8]

//! [9]
void MainWindow::removeGifImages()
{
    QString code = "qt.jQuery('[src*=gif]').remove()";
    view->page()->mainFrame()->evaluateJavaScript(code);
}

void MainWindow::removeInlineFrames()
{
    QString code = "qt.jQuery('iframe').remove()";
    view->page()->mainFrame()->evaluateJavaScript(code);
}

void MainWindow::removeObjectElements()
{
    QString code = "qt.jQuery('object').remove()";
    view->page()->mainFrame()->evaluateJavaScript(code);
}

void MainWindow::removeEmbeddedElements()
{
    QString code = "qt.jQuery('embed').remove()";
    view->page()->mainFrame()->evaluateJavaScript(code);
}
//! [9]

void MainWindow::aboutLooplorer()
{
    QMessageBox::information(this,tr("About Looplorer"),tr("Looplorer 1.9.3"));
}

void MainWindow::clickLink()
{
	connect(view, SIGNAL(linkClicked(QUrl)), this, SLOT(loadLink(QUrl)));
}

void MainWindow::loadLink(const QUrl &url)
{
	view->load(url);
}

void MainWindow::newWindow()
{
    QUrl newUrl;
    newUrl = QUrl("http://www.baidu.com");

    MainWindow *newBrowser = new MainWindow(newUrl);
    newBrowser->setAttribute(Qt::WA_DeleteOnClose);
    newBrowser->show();
}

void MainWindow::closeWindow()
{
    this->close();
}


