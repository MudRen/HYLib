// Room: /jingzhou/lckumen.c
// congw  890830
inherit ROOM;

void create()
{
	set("short", "���ִ���");
	set("long", @LONG
����վ�ھ������ֵ��ſڣ����Կ������������Ʒ��Ĺٱ�����Ѳ�ߣ���ʱ�ش�����
�������ϰ����ǲ������ڴ˹ۿ��ģ�����øϿ��߿���
LONG
	);

	set("exits", ([
		"west" : __DIR__"nandajie2",
		"east" : __DIR__"liangcang",
	]));

	set("objects", ([
		__DIR__"npc/bing" : 2,
	]));

	setup();
}

int valid_leave(object me, string dir)
{
	if (!wizardp(me) && objectp(present("guan bing", environment(me))) && 
		dir == "south")
		return notify_fail("�ٱ���ס�����ȥ·��\n");
	return ::valid_leave(me, dir);
}

