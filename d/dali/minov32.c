//Cracked by Kafei
// minority or tribe village
// acep

inherit ROOM;

void create()
{
	set("short", "���Ϸ�");
	set("long", @LONG
����һ�������ĸ�����ӣ��˼��²�ȴû��ţ����������ϯ
Χס����һ�����ݣ���������������̣�������һЩɣ�ϡ�һλ����
�������������ʵ�ɣҶι��ɣ�ϡ�
LONG
        );

	set("exits", ([
		"west" : __DIR__"minov31",
		]));

	set("objects", ([
		__DIR__"npc/bycannv" : 1,
		]));

	set("cost", 2);
	setup();
}
