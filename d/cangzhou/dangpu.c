inherit ROOM;

void create()
{
	set("short", "���ݵ���");
	set("long", @LONG
����һ������������ƽ���Ƶ����ֺŵ��̣�һ���ĳ߸ߵĹ�̨���������
ǰ����̨�ϰ���һ������(paizi)�� ��̨�����ŵ��̵��ϰ壬һ˫���������
���������´������㡣
LONG
	);
	set("no_fight",1);
	set("no_sleep_room",1);

	set("item_desc", ([
		"paizi" : "��ƽ���ף��������ۡ�\n",
	]));
	set("objects", ([
		__DIR__"npc/laoban" : 1,
	]));
	set("exits", ([
		"north" : __DIR__"xijie1",
	]));

	setup();
	replace_program(ROOM);
}