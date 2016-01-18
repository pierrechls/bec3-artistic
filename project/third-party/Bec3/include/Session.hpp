#ifndef SINGLETON_H
#define SINGLETON_H

class Session{
	public:
		static Session& getInstance();
	private:
		Session& operator= (const Session&){}
		Session (const Session&){}

		static Session m_instance;
		Session();
		~Session();
};

#endif
