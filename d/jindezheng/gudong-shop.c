// Room: /d/jindezheng/gudong-shop.c

inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
�������ϰ��ľ��ӹ,�������������Ķ�ľ���ҵ���,����Ϊ�ε� 
�˿�����ô������,˭����֪��,�����г���һ�Ű��˸ߵĹ�̨֮��,��ǽ 
���ŵĶ��Ǹ߼��ݶ��ĺ�ľ����,���涼�Ǵ�С��һ�ĳ���. 
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"street3",
]));
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/duanmu.c" : 1,
]));

	setup();
	replace_program(ROOM);
}
