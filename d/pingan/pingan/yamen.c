// Room: /city/yamen.c
// YZC 1995/12/04 

inherit ROOM;

void create()
{
	set("short", "���Ŵ���");
	set("long", @LONG
���������Ŵ��ţ�������ľ���Ž����ر��š����ྲ�����رܡ������ӷ�
����ͷʯʨ�ӵ��Աߡ�ǰ����һ����ģ���Ȼ�ǹ�С����ԩ�õġ�������������ǰ
Ѳ�ߡ�
LONG );
	set("exits", ([
		"west" : __DIR__"bei1",
		"east" : __DIR__"ymzhengting",
	]));
	set("objects", ([
		__DIR__"npc/yayi" : 4,
		__DIR__"npc/xunbu" : 1,
]));
        set("no_fight",1);
         set("no_steal",1);
         set("pingan",1);
         set("no_beg",1); 	
//	set("no_clean_up", 0);
	setup();
}

int valid_leave(object me, string dir)
{
	if (!wizardp(me) && objectp(present("ya yi", environment(me))) && dir == "north")
		return notify_fail("���ۺȵ������������䡭������\n");
	return ::valid_leave(me, dir);
}
