

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
����һ�Ҽ�ª�Ĵ����̣����İ���һ����¯��¯��������յ�һƬ
ͨ�죬��һ�߽�ȥ�͸е�������ȡ�ǽ�Ƕ��������깤�Ĳ˵���������
������ذ�ס����׵��һλ������ͷ�󺹻�����������ר����־����
�������ſ���һ����(paizi)��
LONG
	);

	set("exits", ([
		"west" : __DIR__"xuanwu-1",
	]));

        set("objects", ([
__DIR__"npc/tiejiang1" : 1,
        ]));
        set("item_desc", ([ /* sizeof() == 1 */
		"paizi" : "������д������������ǽ�Ƕ��š�\n"]));
        set("no_clean_up", 0);
        set("objects", ([
		"/d/gaoli/npc/tiejiang" : 1,
	]));

	setup();
	replace_program(ROOM);
}

