// Room: /d/jindezheng/tea-room.c

inherit ROOM;

void create()
{
	set("short", "��ͩ԰���");
	set("long", @LONG
����ſ�,��һ�����,����߸ߵ����˸�����,�ſ�����ʯʨ,ȴ�� 
һ�ߴ�,һ��С,�ϼ���̨��,���ž��Ǹ�������,���˼�ʮ������,������ 
����̨��,��һ��ͷ,�Ի���һ�����,�����,˵���!��֪��������˵ɶ 
���������ѻѻ����Ⱥ��ѻȸ����,����������. 
LONG
	);
	set("no_clean_up", 0);
	set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/oldman.c" : 1,
  __DIR__"npc/bgirl.c" : 1,
]));
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"street2",
]));

	setup();
	replace_program(ROOM);
}
