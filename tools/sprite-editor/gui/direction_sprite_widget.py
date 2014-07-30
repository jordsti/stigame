# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 'direction_sprite_widget.ui'
#
# Created: Wed Jul 30 18:37:40 2014
#      by: PyQt4 UI code generator 4.10.4
#
# WARNING! All changes made in this file will be lost!

from PyQt4 import QtCore, QtGui

try:
    _fromUtf8 = QtCore.QString.fromUtf8
except AttributeError:
    def _fromUtf8(s):
        return s

try:
    _encoding = QtGui.QApplication.UnicodeUTF8
    def _translate(context, text, disambig):
        return QtGui.QApplication.translate(context, text, disambig, _encoding)
except AttributeError:
    def _translate(context, text, disambig):
        return QtGui.QApplication.translate(context, text, disambig)

class Ui_direction_sprite_widget(object):
    def setupUi(self, direction_sprite_widget):
        direction_sprite_widget.setObjectName(_fromUtf8("direction_sprite_widget"))
        direction_sprite_widget.resize(566, 457)
        self.verticalLayoutWidget = QtGui.QWidget(direction_sprite_widget)
        self.verticalLayoutWidget.setGeometry(QtCore.QRect(0, 0, 561, 451))
        self.verticalLayoutWidget.setObjectName(_fromUtf8("verticalLayoutWidget"))
        self.layout_main = QtGui.QVBoxLayout(self.verticalLayoutWidget)
        self.layout_main.setMargin(5)
        self.layout_main.setObjectName(_fromUtf8("layout_main"))
        self.layout_sprite_info = QtGui.QHBoxLayout()
        self.layout_sprite_info.setMargin(2)
        self.layout_sprite_info.setObjectName(_fromUtf8("layout_sprite_info"))
        self.gb_sprite = QtGui.QGroupBox(self.verticalLayoutWidget)
        self.gb_sprite.setMinimumSize(QtCore.QSize(250, 110))
        self.gb_sprite.setObjectName(_fromUtf8("gb_sprite"))
        self.formLayoutWidget = QtGui.QWidget(self.gb_sprite)
        self.formLayoutWidget.setGeometry(QtCore.QRect(20, 20, 191, 74))
        self.formLayoutWidget.setObjectName(_fromUtf8("formLayoutWidget"))
        self.formLayout = QtGui.QFormLayout(self.formLayoutWidget)
        self.formLayout.setMargin(0)
        self.formLayout.setObjectName(_fromUtf8("formLayout"))
        self.lbl_name = QtGui.QLabel(self.formLayoutWidget)
        self.lbl_name.setObjectName(_fromUtf8("lbl_name"))
        self.formLayout.setWidget(0, QtGui.QFormLayout.LabelRole, self.lbl_name)
        self.le_name = QtGui.QLineEdit(self.formLayoutWidget)
        self.le_name.setObjectName(_fromUtf8("le_name"))
        self.formLayout.setWidget(0, QtGui.QFormLayout.FieldRole, self.le_name)
        self.lbl_width = QtGui.QLabel(self.formLayoutWidget)
        self.lbl_width.setObjectName(_fromUtf8("lbl_width"))
        self.formLayout.setWidget(1, QtGui.QFormLayout.LabelRole, self.lbl_width)
        self.le_width = QtGui.QLineEdit(self.formLayoutWidget)
        self.le_width.setObjectName(_fromUtf8("le_width"))
        self.formLayout.setWidget(1, QtGui.QFormLayout.FieldRole, self.le_width)
        self.lbl_height = QtGui.QLabel(self.formLayoutWidget)
        self.lbl_height.setObjectName(_fromUtf8("lbl_height"))
        self.formLayout.setWidget(2, QtGui.QFormLayout.LabelRole, self.lbl_height)
        self.le_height = QtGui.QLineEdit(self.formLayoutWidget)
        self.le_height.setObjectName(_fromUtf8("le_height"))
        self.formLayout.setWidget(2, QtGui.QFormLayout.FieldRole, self.le_height)
        self.layout_sprite_info.addWidget(self.gb_sprite)
        self.gb_preview = QtGui.QGroupBox(self.verticalLayoutWidget)
        self.gb_preview.setMinimumSize(QtCore.QSize(120, 0))
        self.gb_preview.setObjectName(_fromUtf8("gb_preview"))
        self.horizontalLayoutWidget = QtGui.QWidget(self.gb_preview)
        self.horizontalLayoutWidget.setGeometry(QtCore.QRect(10, 20, 121, 80))
        self.horizontalLayoutWidget.setObjectName(_fromUtf8("horizontalLayoutWidget"))
        self.layout_preview = QtGui.QHBoxLayout(self.horizontalLayoutWidget)
        self.layout_preview.setMargin(0)
        self.layout_preview.setObjectName(_fromUtf8("layout_preview"))
        self.lbl_preview = QtGui.QLabel(self.horizontalLayoutWidget)
        self.lbl_preview.setObjectName(_fromUtf8("lbl_preview"))
        self.layout_preview.addWidget(self.lbl_preview)
        self.sp_fps = QtGui.QSpinBox(self.horizontalLayoutWidget)
        self.sp_fps.setMinimumSize(QtCore.QSize(40, 20))
        self.sp_fps.setMaximumSize(QtCore.QSize(40, 20))
        self.sp_fps.setMinimum(15)
        self.sp_fps.setMaximum(150)
        self.sp_fps.setObjectName(_fromUtf8("sp_fps"))
        self.layout_preview.addWidget(self.sp_fps)
        self.layout_sprite_info.addWidget(self.gb_preview)
        self.btn_add_frame = QtGui.QPushButton(self.verticalLayoutWidget)
        self.btn_add_frame.setMinimumSize(QtCore.QSize(120, 0))
        self.btn_add_frame.setObjectName(_fromUtf8("btn_add_frame"))
        self.layout_sprite_info.addWidget(self.btn_add_frame)
        self.layout_main.addLayout(self.layout_sprite_info)
        self.horizontalLayout = QtGui.QHBoxLayout()
        self.horizontalLayout.setObjectName(_fromUtf8("horizontalLayout"))
        self.lbl_frames = QtGui.QLabel(self.verticalLayoutWidget)
        self.lbl_frames.setObjectName(_fromUtf8("lbl_frames"))
        self.horizontalLayout.addWidget(self.lbl_frames)
        self.formLayout_2 = QtGui.QFormLayout()
        self.formLayout_2.setFieldGrowthPolicy(QtGui.QFormLayout.AllNonFixedFieldsGrow)
        self.formLayout_2.setObjectName(_fromUtf8("formLayout_2"))
        self.cb_direction = QtGui.QComboBox(self.verticalLayoutWidget)
        self.cb_direction.setObjectName(_fromUtf8("cb_direction"))
        self.formLayout_2.setWidget(0, QtGui.QFormLayout.FieldRole, self.cb_direction)
        self.lbl_direction = QtGui.QLabel(self.verticalLayoutWidget)
        self.lbl_direction.setObjectName(_fromUtf8("lbl_direction"))
        self.formLayout_2.setWidget(0, QtGui.QFormLayout.LabelRole, self.lbl_direction)
        self.horizontalLayout.addLayout(self.formLayout_2)
        self.layout_main.addLayout(self.horizontalLayout)
        self.sa_frames = QtGui.QScrollArea(self.verticalLayoutWidget)
        self.sa_frames.setWidgetResizable(True)
        self.sa_frames.setAlignment(QtCore.Qt.AlignJustify|QtCore.Qt.AlignVCenter)
        self.sa_frames.setObjectName(_fromUtf8("sa_frames"))
        self.scrollAreaWidgetContents = QtGui.QWidget()
        self.scrollAreaWidgetContents.setGeometry(QtCore.QRect(0, 0, 549, 289))
        self.scrollAreaWidgetContents.setObjectName(_fromUtf8("scrollAreaWidgetContents"))
        self.sa_frames.setWidget(self.scrollAreaWidgetContents)
        self.layout_main.addWidget(self.sa_frames)

        self.retranslateUi(direction_sprite_widget)
        QtCore.QMetaObject.connectSlotsByName(direction_sprite_widget)

    def retranslateUi(self, direction_sprite_widget):
        direction_sprite_widget.setWindowTitle(_translate("direction_sprite_widget", "Form", None))
        self.gb_sprite.setTitle(_translate("direction_sprite_widget", "Sprite Information", None))
        self.lbl_name.setText(_translate("direction_sprite_widget", "Name :", None))
        self.lbl_width.setText(_translate("direction_sprite_widget", "Width :", None))
        self.le_width.setText(_translate("direction_sprite_widget", "0", None))
        self.lbl_height.setText(_translate("direction_sprite_widget", "Height :", None))
        self.le_height.setText(_translate("direction_sprite_widget", "0", None))
        self.gb_preview.setTitle(_translate("direction_sprite_widget", "Preview", None))
        self.lbl_preview.setText(_translate("direction_sprite_widget", "P", None))
        self.btn_add_frame.setText(_translate("direction_sprite_widget", "Add a frame...", None))
        self.lbl_frames.setText(_translate("direction_sprite_widget", "Frame(s)", None))
        self.lbl_direction.setText(_translate("direction_sprite_widget", "Direction :", None))

