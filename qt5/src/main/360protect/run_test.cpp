//
// Created by xxzyjy on 05/11/2017.
//
#include <QFile>
#include <QDebug>
#include <QtWidgets/private/qstylesheetstyle_p.h>
#include "catch.hpp"
#include "fixture.h"
#include "MainWindow.h"
#include "AnimationButton.h"
#include "ThreeStateButton.h"
#include "HeadButton.h"
#include "ScoreLabel.h"
#include "WordLineButton.h"
#include "TwoStateButton.h"
#include "MaskMainWidget.h"
#include "BottomWidget.h"
#include "TopWidget.h"
#include "AbstractMainWidget.h"
#include "CsxfWidget.h"
#include "DnqlWidget.h"

QString loadStyleSheet(const QString &sheetName) {
  QFile file(sheetName);
  file.open(QFile::ReadOnly);
  auto styleSheet = QString::fromLatin1(file.readAll());
  qDebug() << styleSheet;
  return styleSheet;
}

TEST_CASE_METHOD(TestFixture, "360", "[360]") {
  MainWindow mainWindow;
  mainWindow.show();

  application.exec();
}

TEST_CASE_METHOD(TestFixture, "animation_button", "[360]") {
  AnimationButton button;
  button.setStyleSheet("qproperty-normalImage:url(:/image/safe.png);"
                         "qproperty-normalEnterAnimationImage:url(:/image/safe_Hover.png);"
                         "qproperty-normalEnterAnimationFrameCount:10;"
                         "qproperty-normalEnterAnimationDuration:600;"
                         "qproperty-normalLeaveAnimationImage:url(:/image/safe_Leave.png);"
                         "qproperty-normalLeaveAnimationFrameCount:8;"
                         "qproperty-normalLeaveAnimationDuration:600;"
  );
  button.setFixedSize(95, 95);
//  button.setMinimumSize(QSize(95,95));
//  button.setMaximumSize(QSize(95,95));
  button.show();
  application.exec();
}

TEST_CASE_METHOD(TestFixture, "animation_button_no_leaving", "[360]") {
  AnimationButton button;
  button.setStyleSheet("qproperty-normalImage:url(:/image/safe.png);"
                         "qproperty-normalEnterAnimationImage:url(:/image/safe_Hover.png);"
                         "qproperty-normalEnterAnimationFrameCount:10;"
                         "qproperty-normalEnterAnimationDuration:600;");
  button.setFixedSize(95, 95);
//  button.setMinimumSize(QSize(95,95));
//  button.setMaximumSize(QSize(95,95));
  button.show();
  application.exec();
}

TEST_CASE_METHOD(TestFixture, "animation_button_no_entering", "[360]") {
  AnimationButton button;
  button.setStyleSheet("qproperty-normalImage:url(:/image/safe.png);"
                         "qproperty-normalLeaveAnimationImage:url(:/image/safe_Leave.png);"
                         "qproperty-normalLeaveAnimationFrameCount:8;"
                         "qproperty-normalLeaveAnimationDuration:600;");
  button.setFixedSize(95, 95);
//  button.setMinimumSize(QSize(95,95));
//  button.setMaximumSize(QSize(95,95));
  button.show();
  application.exec();
}

TEST_CASE_METHOD(TestFixture,"animation_button_with_two_states","[360]") {
  AnimationButton button;
  button.setStyleSheet("qproperty-normalImage:url(:/image/safe.png);"
                         "qproperty-normalEnterAnimationImage:url(:/image/clean/clean_trace_anim.png);"
                         "qproperty-normalEnterAnimationFrameCount:17;"
                         "qproperty-normalEnterAnimationDuration:600;"
                         "qproperty-checkedImage:url(:/image/clean.png);"
                         "qproperty-checkedEnterAnimationImage:url(:/image/clean/clean_trace_anim_gray.png);"
                         "qproperty-checkedEnterAnimationFrameCount:17;"
                         "qproperty-checkedEnterAnimationDuration:600;");
  button.setCheckable(true);
  button.setAutoDefault(false);
  button.setFixedSize(95, 95);
//  button.setMinimumSize(QSize(95,95));
//  button.setMaximumSize(QSize(95,95));
  button.show();
  application.exec();
}

TEST_CASE_METHOD(TestFixture,"animation_button_only_normal","[360]"){
  AnimationButton button;
  button.setStyleSheet("qproperty-normalImage:url(:/image/safe.png);");
  button.setFixedSize(95, 95);
  button.show();
  application.exec();
}

TEST_CASE_METHOD(TestFixture, "three_state_button", "[360]") {
  ThreeStateButton button;
  button.setIndex(0);
  button.setPixmapUrl(":/image/min.png");
  button.show();
  application.exec();
}

TEST_CASE_METHOD(TestFixture, "head_button", "[360]") {
  HeadButton button;
  button.show();
  application.exec();
}

TEST_CASE_METHOD(TestFixture, "ScoreLabel", "[360]") {
  ScoreLabel label;
  label.setPixmap(QPixmap(":/image/100.png"));
  label.setFixedSize(191, 191);
  label.show();
  application.exec();
}

TEST_CASE_METHOD(TestFixture, "WordLineButton", "[360]") {
  WordLineButton button;
  button.setText("Test");
  button.show();
  application.exec();
}

TEST_CASE_METHOD(TestFixture, "TwoStateButton", "[360]") {
  TwoStateButton button;
  button.setPixmap(QPixmap(":/image/rjgj.png"));
  button.setText("软件管家");
  button.show();
  application.exec();
}

TEST_CASE_METHOD(TestFixture, "MaskMainWidget", "[360]") {
  application.setStyleSheet(loadStyleSheet(":/qss/styles"));
  MaskMainWidget main;
  main.show();
  application.exec();
}

TEST_CASE_METHOD(TestFixture, "BottomWidget", "[360]") {
  application.setStyleSheet(loadStyleSheet(":/qss/styles"));
  BottomWidget main;
//  main.setFillLowBar(true);
  main.show();
  application.exec();
}

TEST_CASE_METHOD(TestFixture, "TopWidget", "[360]") {
  application.setStyleSheet(loadStyleSheet(":/qss/styles"));
  TopWidget main;
  main.show();
  application.exec();
}

TEST_CASE_METHOD(TestFixture, "AbstractMainWidget", "[360]") {
  application.setStyleSheet(loadStyleSheet(":/qss/styles"));
  AbstractMainWidget main;
  main.show();
  application.exec();
}
TEST_CASE_METHOD(TestFixture, "CsxfWidget", "[360]") {
  application.setStyleSheet(loadStyleSheet(":/qss/styles"));
  CsxfWidget main;
  main.show();
  application.exec();
}


TEST_CASE_METHOD(TestFixture,"AddressBookMainWindow","[360]"){
  application.setStyleSheet(loadStyleSheet(":/qss/styles"));
  QStyle *style = application.style();
  MainWindow main;
  main.show();
  application.exec();
}

TEST_CASE_METHOD(TestFixture,"DnqlWidget","[360]"){
  application.setStyleSheet(loadStyleSheet(":/qss/styles"));
  QStyle *style = application.style();
  DnqlWidget main;
  main.show();
  application.exec();

}
