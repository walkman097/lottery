#ifndef _MAINWIDGET_
#define _MAINWIDGET_

#include <QWidget>

struct PersonInfo {
	PersonInfo() {
		clear();
	}

	void clear() {
		name.clear();
		pix.clear();
	}

	void operator = (const PersonInfo &info) {
		name = info.name;
		pix = info.pix;
	}

	QString name;
	QString pix;
};


class Person;
class QPushButton;
class MainWiget : public QWidget {
	Q_OBJECT
public:
	MainWiget(QWidget *parent = 0);
	virtual ~MainWiget();


private slots:
	void clickedSlot(); 


private:
	int lottery();


private:
	Person *person; 
	QPushButton *operateBut;
	QList<PersonInfo> personList;
}; 


#endif

