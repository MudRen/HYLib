//Cracked by Kafei
// minority or tribe village
// acep

inherit ROOM;

void create()
{
	set("short", "�̼�ɽ��");
	set("long", @LONG
�̼�ɽ���ڵ�ص������ϣ����ض��Ǹ�ˮ������ɽ�Ƹ������ƣ�
ɽ�����繫������ɽ��ľ�Դ����Ρ��˴����Ǽ������Ѵ��ƶˣ�����
���һƬ��������ʤ�ա�ɽ��������������ݡ�����������ɽ֮·��
LONG
        );

	set("exits", ([
		"eastdown" : __DIR__"minov19",
		"down" : __DIR__"qingxi",
		]));

	set("objects", ([
		__DIR__"npc/youke1.c" : 1,
		]));

	set("outdoors","dali");
	set("cost", 5);
	setup();
}
