// Room: /d/jingzhou/shuyuan.c

inherit ROOM;

void create()
{
	set("short", "������Ժ");
	set("long", @LONG
��������Ժ�Ľ��ã�����������һ����Ⱦ��һλׯ���������������̫ʦ���Ͻ�ѧ
���Ǿ��ǵ�����庫�����ˡ�������������������ѧ��ѧ����һ�Ź��ⰻȻ���鰸
������������ǰ�棬���ϰ��ż��������˵���װ�鼮��
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  
  "north" : __DIR__"dongdajie1",
  "south" : __DIR__"shuyuan1",
]));
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/xiaoxiang" : 1,
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
