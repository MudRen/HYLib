// Room: /d/yanjing/cave.c

inherit ROOM;

void create()
{
	set("short", "��Ѩ��");
	set("long", @LONG
������ں�����,�뿴����Щʲô,ͷ������������Լ�����ɸ�.
�¹��ͷ��������,����ɢ���ż�����������ͷ,�ɽ��µĸо�����,��
Ȼ��Ӳ���,ƾ����书,�����޷�Ծ����ȥ.
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "up" : __DIR__"gardon1",
  "north" : __DIR__"didao",
]));

	setup();
	replace_program(ROOM);
}
