// Room: /city/dangpu.c
// YZC 1995/12/04 

inherit ROOM;

void create ()
{
  set ("short", "����");
  set ("long", @LONG
����һ����������ƽ���Ƶĵ��̣�һ����߸ߵĹ�̨���������
ǰ����̨�ϰ���һ������(paizi)����̨���������ϰ壬һ˫������
�������´������㡣
LONG);

  set("item_desc", ([ /* sizeof() == 1 */
  "paizi" : "��ƽ����

sell        �� 
buy         ��
redeem      ��
value       ����
",
]));
  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/tang" : 1,
]));
  set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"dong1",
  "east" : __DIR__"dangpu2",
]));
       set("no_fight",1);
         set("no_steal",1);
         set("pingan",1);
         set("no_beg",1); 	

  setup();
  replace_program(ROOM);
}
