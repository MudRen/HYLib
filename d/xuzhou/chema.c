inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
һ�ҵ͵��ĳ����ջ�������൱�¾ɣ��ܲ����ۣ��������ڼ�Ǯ��
���������ڶ��ŵĽ�ͨҪ���ϣ����̾�����ѡ��������ţ�����Ҳ�൱
������Ҳ������������������صķ������顣
LONG );
	set("no_fight", 1);
        set("no_sleep_room",1);
	set("objects", ([
		__DIR__"npc/xiaoer" : 1,
	]));
	set("exits", ([
		"south" : __DIR__"dongdajie",
		"up"   : __DIR__"chemaup",
	]));
	setup();
}

int valid_leave(object me, string dir)
{

	if ( !me->query_temp("gived_money") && dir == "up" )
	return notify_fail("��С��һ�µ���¥��ǰ������һ���������ţ����ס����\n");

	if ( me->query_temp("gived_money") && dir == "south" )
	return notify_fail("��С���ܵ��ű���ס���͹��Ѿ��������ӣ����᲻ס��������أ�
���˻���ΪС���ź����أ�\n");

	return ::valid_leave(me, dir);
}
