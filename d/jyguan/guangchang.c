// Room: /guangchang.c
// Ver 0.1 by Freeze

inherit ROOM;

void create()
{
	set("short", "��  ��");
	set("long", @LONG
�����Ǽ����ؿ����Ĺ㳡����������ש�̳ɡ��̷�������ó�ס����ͣ��������
�����������Ҳ�����
LONG
	);
        set("no_sleep_room",1);
        set("outdoors", "city");

//	set("item_desc", ([
//		"shudong" : "����һ���ڲ����еĴ󶴣����治֪����Щʲô�Ź֡�\n",
//	]));

	set("exits", ([
		"east" : __DIR__"dongmen",
		"south" : __DIR__"nanmen",
		"west" : __DIR__"ximen",
		"north" : __DIR__"beimen",
	]));

//	set("objects", ([
//		__DIR__"npc/xunbu" : 1,
//		__DIR__"npc/liumangtou" : 1,
//		__DIR__"obj/fake-zi" : 1,
//                "/rtm/npc/rtm.c" : 1
//	]));

	setup();
	replace_program(ROOM);
}
/*
void init()
{
        add_action("do_enter", "enter");
	UPDATE_D->check_user(this_player());
}

int do_enter(string arg)
{
	object me;
	me = this_player();

        if( !arg || arg=="" ) return 0;

        if( arg=="shudong" ) 
	{
		message("vision",
			me->name() + "һ�������������˽�ȥ��\n",
			environment(me), ({me}) );
                me->move("/d/gaibang/inhole");
                message("vision",
			me->name() + "�Ӷ������˽�����\n",
                	environment(me), ({me}) );
		return 1;
	}
}	
*/