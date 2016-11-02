#include <QVBoxLayout>
#include <QPixmap>
#include <QLabel>
#include <QDebug>

#include "person.h"

Person::Person(QWidget *parent)
	:QWidget(parent)
{
	QVBoxLayout *layout = new QVBoxLayout(this);
	
	pixLab = new QLabel;
	nameLab = new QLabel;

	layout->addWidget(pixLab);
	layout->addWidget(nameLab);
	layout->setAlignment(Qt::AlignHCenter);
}

Person::~Person()
{
}


void Person::setInformation(const QString &pic, const QString &name)
{
	qDebug() << "Person" << __func__ << "pic" << pic << "name" << name;
	QPixmap pixmap(pic);
	pixLab->setPixmap(pixmap);
	nameLab->setText(name);
	nameLab->setAlignment(Qt::AlignHCenter);
}

