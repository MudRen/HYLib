//Cracked by Kafei
// minority or tribe village
// acep

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
�˼�����¥���㣬��һ����Ĵ��ݣ�����һ����̨��ʮ����ʯ
Χ��һȦ����������һ�����ƣ��ϻ汾�������ͼ����Ȧ�����м���
��С�����ƣ�������������������ţ���̨ǰ���Ʒ������ã�ʱ
������ǰ������Ĥ�ݡ�
LONG
        );

	set("exits", ([
		"down" : __DIR__"minov29",
		]));

	set("objects", ([
		__DIR__"npc/tyjisi" : 1,
	]));

	set("cost", 2);
	setup();
}
