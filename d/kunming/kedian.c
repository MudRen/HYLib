// Room: /city/kedian.c
// YZC 1995/12/04 

inherit ROOM;

void create()
{
	set("short", "��ջ");
	set("long", @LONG
����һ�Ҽۼ�ª��ջ��������Ȼ��������ȴ�������������˶�ϲ��
ѡ��������ţ���Ϊ����ĵ���ʶ��һЩ�������ˣ����Ժ������˻��������£�
С��æǰæ����к����ˣ�����Ҳ����Ц�ݵ�����˵�û������˾����й�ҵ�
�о�һ�㡣
LONG
	);

	set("no_fight", 1);
	set("valid_startroom", 1);
        set("no_sleep_room",1);

	set("objects", ([
		__DIR__"npc/xiaoer" : 1,
		__DIR__"npc/laoban" : 1,
	]));

	set("exits", ([
                "west" : __DIR__"majiu",
		"east" : __DIR__"nandajie2",
		"westup" : __DIR__"kedian1",
	]));

	setup();
}

int valid_leave(object me, string dir)
{

	if ( !me->query_temp("rent_paid") && dir == "up" )
	return notify_fail("����Ц�Ŷ���˵�����͹��������︶��Ǯ����¥ס�ꡣ\n");

	return ::valid_leave(me, dir);
}
