inherit ROOM;

void create()
{
	set("short", "�Ĳ���");
	set("long", @LONG
����һ�����ֺŵ�Ǯׯ�����м��������ʷ����ȫ�����ض��зֵꡣ
�����е���Ʊ�����ǳ��ã�ͨ��ȫ����
LONG );
	set("exits", ([
		"northeast" : __DIR__"beishi",
		]));
	set("objects", ([
		__DIR__"npc/qian":1,
		]));
	setup();
	replace_program(ROOM);
}

