// /d/taiyuan/road7.c
// Room in ̫ԭ
// modify by yang

inherit ROOM;

void create()
{
	set("short", "����·��");
	set("long", @LONG
������һ������·�ڡ�·���и�СС�Ĳ����·�����ǿڿ��ˣ�
��ȥ�����ȣ������洫�������ˮ����Ӧ�ÿ쵽�ƺӶɿ��ˣ�����ͨ
��������������������·�����Ե��ﳤ���ǡ���������һ����ΰ�Ĵ�ɽ��
LONG );
	set("exits", ([
		"west"  : __DIR__"road8c",
 		"northeast"  : __DIR__"road8",
                "southeast"  : __DIR__"road8a",
///                "southwest":"/d/changan/dadao2",
		
	]));
	
 	set("outdoors", "taiyuan");
	setup();
	replace_program(ROOM);
}



