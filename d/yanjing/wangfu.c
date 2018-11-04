// Room: /d/yanjing/wangfu.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
���Ĵ���֮ǰ������˸��ʣ���ͷ������������ʯʨ����������
һ�Ű����ʯֱͨ��ǰ�������ɺ���֮������������д�š�������������
���֡��������Ǵ��������������պ���.
LONG
	);
set("valid_startroom",1);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/qinbing.c" : 2,
]));
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"qianyuan",
  "south" : __DIR__"street4",
]));
	set("no_clean_up", 0);
	set("outdoors", "yanjing");

	setup();
}

int valid_leave(object me,string dir)
{
	object npc1,npc2;

	npc1=present("qin bing",this_object());
	npc2=present("qin bing 2",this_object());

	if(dir=="north" && objectp(npc1) && living(npc1))	{
		write("�����ױ��ȵ�������˽�����������������£�\n");
		npc1->kill_ob(me);
		me->fight_ob(npc1);
	}
	if(dir=="north" && objectp(npc2) && living(npc2))	{
		write("�����ױ��ȵ����ҿ����ǳ��˱��ӵ��ˣ�����������ү���鷳��\n");
		npc2->kill_ob(me);
		me->fight_ob(npc2);
	}
	if(dir=="north" && ((objectp(npc1)&&living(npc1))||
	(objectp(npc2)&&living(npc2)))) 
	return notify_fail("�����ױ���ס���ȥ·��\n");
	return ::valid_leave(me,dir);
}

		
