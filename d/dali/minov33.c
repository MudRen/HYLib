//Cracked by Kafei
// minority or tribe village
// acep

inherit ROOM;

void create()
{
	set("short", "ũ��");
	set("long", @LONG
����һС����ͨ��ˮ�������Ϫ�����������ʮ�ַ��㡣Χ��
ũ�����һƬƬɣ�֣������˲�ɣ�����ϣ���֯�൱���µ�˿֯Ʒ��
����������ӡ�
LONG
        );

	set("exits", ([
		"west" : __DIR__"minov34",
		"south" : __DIR__"minov31",
		]));

	set("objects", ([
		__DIR__"npc/niu.c" : 1,
		__DIR__"npc/bynong.c" : 1,
		]));

	set("outdoors","dali");
	set("cost", 3);
	setup();
}
