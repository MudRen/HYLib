//Cracked by Kafei
// minority or tribe village
// acep

inherit ROOM;

void create()
{
	set("short", "�������");
	set("long", @LONG
����һ��������ķ��ݡ��˼���������������ɽ�ƿ������ſ�
������İ����ʯ�󷿣�װ����Ϊ���ף������Ǿ��ĵ��Ƶģ�����
�ա��¡������Ⱦ�����ͼ���������������������ļ�����ݡ�
LONG
        );

	set("exits", ([
		"east" : __DIR__"minov42",
		"enter" : __DIR__"minov44",
		]));

	set("outdoors","dali");
	set("cost", 2);
	setup();
}
