#ifndef _PERSON_H_
#define _PERSON_H_

#include <QWidget>

class QLabel;
class Person : public QWidget {
	Q_OBJECT
public:
	Person(QWidget *parent = 0);
	virtual ~Person();

	void setInformation(const QString &, const QString &);

private:
	QLabel *pixLab;
	QLabel *nameLab;
};


#endif

