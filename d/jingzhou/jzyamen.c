// Room: /jingzhou/jzyamen
// 980830 congw 

inherit ROOM;

void create()
{
	set("short", "��������");
	set("long", @LONG
���������Ŵ��ţ�������ľ���Ž����ر��š����ྲ�����رܡ������ӷַ���ͷʯ
ʨ�ӵ��Աߡ�ǰ����һ����ģ���Ȼ�ǹ�С����ԩ�õġ�������������ǰѲ�ߡ�
LONG
	);

	set("exits", ([
		"south" : __DIR__"ymzhengting",
		"north" : __DIR__"xidajie1",
	]));

	set("objects", ([
		__DIR__"npc/yayi" : 4,
	]));

	setup();
}

int valid_leave(object me, string dir)
{
	if (!wizardp(me) && objectp(present("ya yi", environment(me))) && dir == "south")
		return notify_fail("���ۺȵ������������䡭������\n");
	return ::valid_leave(me, dir);
}
