// /d/zhuojun/road6.c
// Room in �ÿ�
// modify by yang

inherit ROOM;


void create()
{
	set("short", "��ӡ��");
	set("long", @LONG
��ӡ��λ��������ɽ�������£�Ϊ�ƴ���ɮ��v������
���������ݾ���ǧĶ,�ٸ�����ɮ�����ɽʢ��һʱ������
�ߴ�Ρ�룬ɽ�ſ�������������������ڷ�����ɽ������
������Ƕ�з���12218��Ϊ����֮�����Ϊ�������
����֮һ�����ڵ���ͥ�����ѻָ���ׯ����ΰ�����ҵ�����
LONG );
	set("exits", ([
		"west" : __DIR__"road7",
		"east" : __DIR__"road3",
	]));
	       set("objects",([
        "/d/shaolin/npc/xiao-bei" : 2,
        ]));
 	set("outdoors", "zhuojun");
	setup();
	replace_program(ROOM);
}



