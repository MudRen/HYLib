//Cracked by Kafei
// minority or tribe village
// acep

inherit ROOM;

void create()
{
	set("short", "����ɽ��");
	set("long", @LONG
�˼���������ɽ���£�����������ɽ�¶��ϣ����ؿ���һ��Ҳ��
���֣������ϡ�衣���ĵ���ũҵ������л����ָ��������ڲ�ͬ
�ļ��ڸ�����ͬ����أ���฽�������������������˸�����
LONG
        );

	set("exits", ([
		"west" : __DIR__"minov46",
		]));

	set("objects", ([
		__DIR__"npc/wynong.c" : 1,
		]));

	set("outdoors","dali");
	set("cost", 3);
	setup();
}
