// Room: /d/yanjing/tianjin.c

inherit ROOM;

void create()
{
	set("short", "�쾮��");
	set("long", @LONG
һ���ϻ���֦Ҷ�߲���ռ�˰���쾮,���滹��������û�ܻ���ѩ.
����һ���Ͼ�,���ķ���ʯ���м�����Բ��,�����ֳɵľ�Ȧ.ˮ������
��һ��ˮ��,װ������ˮ.
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"kefang",
  "east" : __DIR__"zoudao",
]));
	set("no_clean_up", 0);
	set("outdoors", "yanjing");

	setup();
	replace_program(ROOM);
}
