// Room: /d/jindezheng/matou.c

inherit ROOM;

void create()
{
	set("short", "��ͷ");
	set("long", @LONG
�Ӽ���ʯ������,����һ����ͷ,�����˴��СС�Ĵ�ֻ,��Щ���� 
�����������,�������ĵ��̶����Ը�����ͷ,ͼ������.��Щ������ 
�ػ�֮�⻹˳������. 
LONG
	);
	set("no_clean_up", 0);
	set("outdoors", "/d/jindezheng");
	set("exits", ([ /* sizeof() == 1 */
  "northup" : __DIR__"yuanzi",
]));
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/chuanfu.c" : 1,
]));

	setup();
	replace_program(ROOM);
}
