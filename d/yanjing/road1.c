// Room: /d/yanjing/road1.c

inherit ROOM;

void create()
{
	set("short", "����ʯС��");
	set("long", @LONG
���Ǵ����ڻ�ľ֮���һ��С��,����ɫʯ��ϸϸ���̳ɻ���,һ��
�����ڻ�ľ��Ʈ��,��������ĵط�һ�����ѵ����ڵ�������.������
������Ժ,������¶������һ��.
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 4 */
  "southwest" : __DIR__"road",
  "north" : __DIR__"gardon2",
  "west" : __DIR__"gardon1",
  "northeast" : __DIR__"lack",
]));
	set("outdoors", "yanjing");

	setup();
	replace_program(ROOM);
}
