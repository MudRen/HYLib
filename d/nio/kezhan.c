// Room: /u/jpei/thd/kezhan.c

inherit ROOM;

void create()
{
	set("short", "������ջ");
	set("long", @LONG
����һ�ҿ�����С��ջ��������Ϊ��������������׼���ģ��������ھ�
Ӫ���ƣ������൱�����壬��̨�Ա߷���һ������(paizi)�� ������һ��С��
·��
LONG
	);
	set("no_clean_up", 0);
        set("no_sleep_room", 1);
	set("valid_startroom", 1);
	set("objects", ([
		__DIR__"npc/xiaoer.c":1,
	]));

	set("item_desc", ([
		"paizi" : "¥�Ͽͷ���ÿҹ����������\n",
	]));

	set("exits", ([
		"south": __DIR__"hbroad.c",
		"up" : __DIR__"kezhan2",
	]) );

	setup();
}

int valid_leave(object me, string dir)
{

	if ( !me->query_temp("rent_paid") && dir == "up" )
	return notify_fail("��С��������ס���㣺��ô�ţ����ס����\n");

	if ( me->query_temp("rent_paid") && dir == "south" )
	return notify_fail("�͹��Ѿ��������ӣ���ô��ס��������أ����˻���ΪС���ź����أ�\n");

	return ::valid_leave(me, dir);
}
