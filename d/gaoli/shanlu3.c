// /d/gaoli/xuanwumen
// Room in ����
inherit ROOM;

void create()
{
	set("short", "ɽ·");
	set("long", @LONG
������һ��ɽ·��������һ������������ɽ·������ۣ��㲻��
С��������̧ͷ��ȥ��������һ�����̨�������Ѿ�û��ʲô�����ˡ�
LONG
	);

	set("exits", ([
		"northeast" : __DIR__"edao2",
		"westup":__DIR__"shanlu4",
	]));
	set("objects", ([

		"quest/skills2/wakuang/kuang/kuangmai" : 2,
	
	]));
 	set("outdoors", "/d/gaoli");
	setup();
	replace_program(ROOM);
}


