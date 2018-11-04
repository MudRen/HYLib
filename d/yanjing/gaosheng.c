// Room: /d/yanjing/gaosheng.c

inherit ROOM;

void create()
{
	set("short", "������ջ");
	set("long", @LONG
��յ�������߹�����ͷ����,���е�������"������ջ"�����Һڵ�
����,���������Ⱥ�����ű߻��վ��ӭ��.һ�ߵĽ���ֱ��ͨ���Ժ��
������.
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"street2",
  "west" : __DIR__"zoudao",
]));
	set("valid_startroom", 1);
        set("no_sleep_room",1);
	set("no_clean_up", 0);
	set("outdoors", "yanjing");
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/xiaoer.c" : 1,
]));

	setup();
}

int valid_leave(object me, string dir)
{

	if ( !me->query_temp("rent_paid") && dir == "west" )
	return notify_fail("��С��һ�µ���¥��ǰ������һ���������ţ����ס����\n");

	if ( me->query_temp("rent_paid") && dir == "east" )
	return notify_fail("��С���ܵ��ű���ס���͹��Ѿ��������ӣ����᲻ס��������أ�
���˻���ΪС���ź����أ�\n");

	return ::valid_leave(me, dir);
}