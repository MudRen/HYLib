//Cracked by Kafei
// minority or tribe village
// acep

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
���������������ϣ�ס���ǰ�޼�������Բ�����޼����̨�ģ���
����˸����غ�������⣬��Ҫ�Բ���Ϊ�����ٺ���������������
�߲�Զ�����洬�����С��ͷ���ϱ�ɽ���в���Ұ�ޣ����Բ�������
����ǰȥ���ԡ�
LONG
        );

	set("exits", ([
		"north" : __DIR__"minov73",
		"south" : __DIR__"minov74",
		"west" : __DIR__"minov75",
		"northeast" : __DIR__"minov65",
		]));

	set("objects", ([
		__DIR__"npc/tyshang" : 1,
	]));

	set("outdoors","dali");
	set("cost", 2);
	setup();
}
