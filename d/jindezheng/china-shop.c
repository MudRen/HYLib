// Room: /d/jindezheng/china-shop.c

inherit ROOM;

void create()
{
	set("short", "�¼��ϵ�");
	set("long", @LONG
�¼��ϵ�Ҳ���Ǿ���������Ҳ������һ���մɵ���,�ӿ�������, 
��˵�м�������,���ķֵ�鼰ȫ��,���ǵ����г��˼����ź�Ļ��֮ 
��,ֻ����һ����ĺ�ľ����,������һ���մ�����Ӱ��. 
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "enter" : __DIR__"yuanzi",
  "north" : __DIR__"jindezhen",
]));
	set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/huoji.c" : 1,
  __DIR__"npc/wenfang.c" : 1,
]));

	setup();
	replace_program(ROOM);
}
