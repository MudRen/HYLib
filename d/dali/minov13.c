//Cracked by Kafei
// minority or tribe village
// acep

inherit ROOM;

void create()
{
	set("short", "ũ��");
	set("long", @LONG
����һС����ͨ��ˮ��أ���گ��ů��ʪ���Թ�����������ֲˮ
��Ϊ�����⸽���Ǵ�������ټ���ƽԭ���Σ���Ҫ�Ը���Ϊ���İ���
�˿�����һЩ��ũ���ػ��ֳ�С�飬һЩ��������������������
ˮţ�������е�·����ũ���򶫶�ȥ��
LONG
        );

	set("exits", ([
		"west" : __DIR__"minov11",
		"east" : __DIR__"minov16",
		"south" : __DIR__"minov14",
		]));

	set("objects", ([
		__DIR__"npc/niu.c" : 1,
		__DIR__"npc/bynong.c" : 1,
		]));

	set("outdoors","dali");
	set("cost", 3);
	setup();
}
