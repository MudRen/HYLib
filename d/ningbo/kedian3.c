// /u/beyond/ningbo/kedian3.c
// Beyond make 1997.6.8
inherit ROOM;

void create()
{
	set("short", "�͵��¥");
	set("long", @LONG
����һ��ܴ�Ŀͷ�������ʮ�ּ�ª����ǽ����ʮ����Сľ�������ٿ�
�������¶��ԣ������Ӷ��Ǻ����Ĵ������������Ŵ��ǿյģ����������
�����˹�ȥ��
LONG
	);

	set("sleep_room", "1");
	set("no_fight", "1");

	set("exits", ([
		"out" : __DIR__"kedian2",
	]));

	setup();
}

int valid_leave(object me, string dir)
{
	if ( dir == "out" ) me->delete_temp("rent_paid");

	return ::valid_leave(me, dir);
}

