// Room: /d/chengdu/ruin2.c
// Last Modifyed by Winder on Jan. 4 2002

inherit ROOM;

void create()
{
	set("short", "ؤ��ֶ�");
	set("long", @LONG
������һ���ƾɴ�լ�������������ǽ�ڸ��ݶ��Ѿ�����̮���ˣ�
���쬵����ӱ��ߵ�ȱ��ֱ��������������������ǣ�������ɨ��
�൱���࣬������Ǭ���������������һ����(bed)��
LONG	);
	set("exits", ([
		"east": __DIR__"ruin1"
	]));

	set("objects", ([
		CLASS_D("gaibang")+"/obj/jiaohuaji" : 1,
		__DIR__"npc/obj/food/jitui" : 1,
		__DIR__"npc/obj/food/jiudai": 1,
	]));
	set("coor/x", -8080);
	set("coor/y", -3040);
	set("coor/z", 0);
	setup();
}

