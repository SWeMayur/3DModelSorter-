#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include "stdafx.h"
#include "Visualizer.h"
#include "OpenGLWindow.h"
#include "Constants.h"

using namespace std;

Visualizer::Visualizer(QWindow* parent) : QMainWindow(nullptr)
{
    setupUi();
    connect(mAddFileButton, &QPushButton::clicked, this, &Visualizer::openFileSelectionDialog);
    connect(mDoneFileSelectButton, &QPushButton::clicked, this, &Visualizer::completeFileSelect);
    connect(mSortButton, &QPushButton::clicked, this, &Visualizer::callSort);
    connect(mShowModelButton, &QPushButton::clicked, this, &Visualizer::showModel);
    connect(mParameterList, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &Visualizer::handleComboBoxChange);
}

Visualizer::~Visualizer()
{}

void Visualizer::setupUi()
{
    // Created a central widget for the main window
    mCentralWidget = new QWidget(this);

    // Created a horizontal layout for the central widget
    mMainLayout = new QHBoxLayout(mCentralWidget);

    // Created a QmSplitter
    mSplitter = new QSplitter(Qt::Horizontal);

    mRenderer = new OpenGLWindow(QColor(0, 0, 0), this);
    mSplitter->addWidget(mRenderer);

    // Created a vertical layout for the right side of the mSplitter
    mVerticalLayout = new QVBoxLayout;
    mAddFileButton = new QPushButton("Add Model", this);
    mAddFileButton->setMinimumSize(100, 45);
    Constants c;
    mAddFileButton->setStyleSheet(c.mAddFileButtonStyle);
    mVerticalLayout->addWidget(mAddFileButton, 0, Qt::AlignCenter);

    // Assuming mModelTable is your QTableWidget
    mModelTable = new QTableWidget(0, 4, this);  // Columns: 4

    // Set the header labels for each column
    QStringList headerLabels = { "Model Name", "Height (m)", "Cost (Cr)", "Year of Establishment" };
    mModelTable->setHorizontalHeaderLabels(headerLabels);

    // Make the header items bold
    QFont boldFont;
    boldFont.setBold(true);
    mModelTable->horizontalHeader()->setFont(boldFont);

    // Allow columns to stretch when resizing the window
    mModelTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    // Allow rows to stretch when resizing the window
    mModelTable->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    mModelTable->setStyleSheet(c.mTableStyle);
    // Add the table to your layout or wherever you need it
    mVerticalLayout->addWidget(mModelTable);

    mDoneFileSelectButton = new QPushButton("Done", this);
    mDoneFileSelectButton->setMinimumSize(100, 45);
    mDoneFileSelectButton->setStyleSheet(c.mFileSelectButtonStyle);
    mVerticalLayout->addWidget(mDoneFileSelectButton, 0, Qt::AlignCenter);

    mShowModelButton = new QPushButton("Show Model", this);
    mShowModelButton->setMinimumSize(100, 45);
    mShowModelButton->setStyleSheet(c.mShowModelButtonStyle);
    mVerticalLayout->addWidget(mShowModelButton, 0, Qt::AlignCenter);

    mParameterList = new QComboBox(this);
    mParameterList->addItem("Select Parameter");
    mParameterList->addItem("Height");
    mParameterList->addItem("Cost");
    mParameterList->addItem("Year of Establishment");
    mParameterList->setMinimumSize(150, 45); // Adjust size as needed

    // Apply stylesheet for styling
    mParameterList->setStyleSheet(c.mParameterListButtonStyle);

    mVerticalLayout->addWidget(mParameterList, 0, Qt::AlignCenter);

    mSortButton = new QPushButton("Sort", this);
    mSortButton->setMinimumSize(100, 45);
    mSortButton->setStyleSheet(c.mSortButtonStyle);
    mVerticalLayout->addWidget(mSortButton, 0, Qt::AlignCenter);

    // Add a widget (e.g., empty QLabel) to the right side of the mSplitter
    // This will act as a placeholder to allow resizing
    QLabel* placeholder = new QLabel("");
    placeholder->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    mVerticalLayout->addWidget(placeholder);
    mVerticalLayout->setSpacing(50);
    mVerticalLayout->setContentsMargins(10, 10, 10, 10);
    // Set the layout for the right side of the mSplitter
    QWidget* rightWidget = new QWidget;
    rightWidget->setLayout(mVerticalLayout);

    mSplitter->addWidget(rightWidget);

    // Add the QmSplitter to the main layout
    mMainLayout->addWidget(mSplitter);

    setCentralWidget(mCentralWidget);
    setWindowTitle(QCoreApplication::translate("3D Model Sorter", "3D Model Sorter", nullptr));
    showMaximized();
}


void Visualizer::handleComboBoxChange() 
{
    int index = mParameterList->currentIndex();
    mRenderer->choice = index;
}

void Visualizer::openFileSelectionDialog() 
{
    QStringList filePaths = QFileDialog::getOpenFileNames(this, tr("Open STL Files"), "", tr("STL Files (*.stl);;All Files (*)"));
    
    for (const QString& filePath : filePaths) {
        QFileInfo fileInfo(filePath);
        mFileList.append(fileInfo.fileName());
        mFilePathList.append(filePath);
    }
}

void Visualizer::completeFileSelect()
{
    mModelTable->clearContents();
    mRenderer->setTableContent(mFileList, *mModelTable);
}

void Visualizer::callSort()
{
    mRenderer->getAllFiles(mFilePathList);;
}

void Visualizer::showModel()
{
    mRenderer->getAllFiles(mFilePathList);
}