// Room: /d/yanjing/zoudao.c

inherit ROOM;

void create()
{
	set("short", "С�ߵ�");
	set("long", @LONG
С�ߵ����߰���Щɢ�ܵļҾ�.�淢ʹ���ߵ���խ,����û�е�,��
�����ſ�͸���������,ʹ��ط���Ȼ���������Щ,��ֻ��������ű�
����,����ͷ�����㼸��.
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"tianjin",
  "east" : __DIR__"gaosheng",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
