//Cracked by Kafei
// minority or tribe village
// acep

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
�����ǽ����������ģ����Ӳ��󣬾�����󲿷��������壬����
ȫ��������Ϊ��������ɽ�ߵغ�������ɽ�ֵ�Ұ�޴��Ƥ��ë����
����Ƥ����������͵������˽��ס�����ɽ��������������Ҳ����
��֮;���ϴ���ɽ��ɵִ�����½��
LONG
        );

	set("exits", ([
		"north" : __DIR__"minov88",
		"south" : __DIR__"minov90",
		]));

	set("objects", ([
		__DIR__"npc/wylieren1.c" : 1,
		__DIR__"npc/phshang.c" : 1,
		]));

	set("outdoors","dali");
	set("cost", 2);
	setup();
}
