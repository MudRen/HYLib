//Cracked by Kafei
// minority or tribe village
// acep

inherit ROOM;

void create()
{
	set("short", "ũ��");
	set("long", @LONG
�����Ѿ���ƽԭ�ľ�ͷ����������վ���ɽ���ˣ�һЩ��ũ���
��٤������ķ������ǵطֲ���ɽ���£�һЩ�������������������
����·���ϵ�ɽ�����Ѷ�ȥ��
LONG
        );

	set("exits", ([
		"west" : __DIR__"minov13",
		"southeast" : __DIR__"minov17",
		]));

	set("objects", ([
		__DIR__"npc/bynong.c" : 1,
		]));

	set("outdoors","dali");
	set("cost", 3);
	setup();
}
