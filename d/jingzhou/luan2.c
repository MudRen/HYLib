// Room: luan2
// congw 980830 

inherit ROOM;

void create()
{
	set("short", "�ҷظ�");
	set("long", @LONG
������һ���ҷظڣ����������˹��˸ߵĳ��ݣ���˵�����ֹ�����û�˸�������Ӵ
��������һ�����������ŵ��������ë�����ס�����������һ���·أ���������
һ�鱮(tablet)��
LONG
	);

	set("exits", ([
		"west" : __DIR__"luan",
			]));

	set("item_desc", ([
		"tablet" : "ֻ������д�ţ�����Ů��˪��֮Ĺ�� \n",
	]));

	setup();
}

void init()
{
        add_action("do_push", "push");
	UPDATE_D->check_user(this_player());
}

int do_push(string arg)
{
	object me;
	me = this_player();

        if( !arg || arg=="" ) return 0;

        if( arg=="bei" ) 
	{
		message("vision",
			me->name() + "��Ӱһ������������Ӱ��\n",
			environment(me), ({me}) );
                me->move("/d/jingzhou/tomb");
                message("vision",
			me->name() + "���˽�����\n",
                	environment(me), ({me}) );
		return 1;
	}
}	
