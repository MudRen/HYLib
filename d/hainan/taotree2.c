// Room: /d/hainan/taotree2.c

inherit ROOM;

void create()
{
	set("short", "�һ���");
	set("long", @LONG
Ѥ�õ��һ���������,��ȴ��Ҳ�������ȥ��·��.��ǰֻ��һƬ�� 
��ɫ�Ļ���.����������,�ߵ���������......��,����������Ķ�����һ 
��Ů�ӵ���Ц��. 
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"taotree3",
  "south" : __DIR__"taotree1",
  "west" : __DIR__"taotree1",
  "east" : __DIR__"taotree1",
]));
	set("outdoors", "/d/hainan");
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"obj/huaban.c" : 2,
]));

	setup();
	replace_program(ROOM);
}
