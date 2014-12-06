


class player			//strose the porperty of the play
{

	public:
	player(int defense,int threepoints,int shotmedium,int shotclose,int breakthrough,int passball,int rebound,int controlball,int keyball)   // 标准构造函数
	{
		defense_ = defense;
		threepoints_ = threepoints;
		shotmedium_ = shotmedium;
		shotclose_ = shotclose;
		breakthrough_ = breakthrough;
		passball_ = passball;
		rebound_ = rebound;
		controlball_ = controlball;
		keyball_ = keyball;
	};

	virtual ~player();

	// 球员数据

	protected:
		int defense_;
		int threepoints_;
		int shotmedium_;
		int shotclose_;
		int breakthrough_;
		int passball_;
		int rebound_;
		int controlball_;
		int keyball_;
};
