// Room: /city/zuixianlou2.c
// YZC 1995/12/04 

inherit ROOM;


void create()
{
	set("name", "С�ƹ�");
	set("short", "С�ƹݶ�¥");
	set("long", @LONG
	����������������ѧʿ������������ʫ��������������Ҳ������߳Ժȱ�
�����ס�����Ҳ�ǳ���ٰ�ϲ�����ѳ�������վ��¥��������ֻ�����Ŀ�������
�����Ǽ����أ�����ͦ�Ρ�
    ǽ�Ϲ��ż۸�����(paizi)��
LONG
	);

	set("item_desc", ([
		"paizi" : "������ۿ�Ѽ���ϵȻ���ơ�\n",
	]));


	set("exits", ([
		"down" : __DIR__"jiudian",
	]));

	setup();
	replace_program(ROOM);
}
