//Cracked by Kafei
// minority or tribe village
// acep

inherit ROOM;

void create()
{
	set("short", "ˮ��");
	set("long", @LONG
����һƬ����ƽ�ص�ũ������﹡��ȫ������ˮ��û�ţ�һЩ
���Ჿ�ĸ�Ů���Ž�������������������ˮ���㣬��Ȼû�н���
�����������ر�Ĺ�ȣ�ÿ������������Ȼ��ˮ������
LONG
        );

	set("exits", ([
		"north" : __DIR__"minov76",
		]));

	set("objects", ([
		__DIR__"npc/tynong" : 1,
		__DIR__"npc/niu" : 1,
	]));

	set("outdoors","dali");
	set("cost", 3);
	setup();
}
