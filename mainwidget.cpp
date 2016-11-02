#include "mainwidget.h"
#include "person.h"

#include <QVBoxLayout>
#include <QPushButton>
#include <QDebug>
#include <QLabel>
#include <QTime>
#include <QDir>

MainWiget::MainWiget(QWidget *parent)
	:QWidget(parent)
{
	QVBoxLayout *layout = new QVBoxLayout(this);
	
	QLabel *titleLabel = new QLabel;
	titleLabel->setText("Lottery");
	titleLabel->setAlignment(Qt::AlignHCenter);
	operateBut = new QPushButton(this);
	operateBut->setText("Begin");
	person = new Person;

	layout->addWidget(titleLabel);
	layout->addWidget(operateBut);
	layout->addWidget(person);

	connect(operateBut, SIGNAL(clicked()), this, SLOT(clickedSlot()));

	QString path = QDir::currentPath() + "/" + "pix/";
	for (int i = 1; i <= 6; i++) {
		QString name = QString::number(i);
		QString pix = path + name + ".jpg";
	
		PersonInfo person;
		person.name = name;
		person.pix = pix;
		personList.push_back(person);
	}

	PersonInfo personInfo = personList[0];
	person->setInformation(personInfo.pix, personInfo.name);
	
	qsrand(QTime::currentTime().msec());
}

MainWiget::~MainWiget()
{
}

void MainWiget::clickedSlot()
{
	int luckDog = lottery();
	qDebug() << "MainWiget" << __func__ << "luckDog" << luckDog;

	if (luckDog > 6)
		return;
	PersonInfo personInfo = personList[luckDog];
	person->setInformation(personInfo.pix, personInfo.name);
}


int MainWiget::lottery()
{
	return qrand() % 6 + 1;
}


