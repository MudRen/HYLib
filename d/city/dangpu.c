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
    ¥���¿���С��ի��
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
__DIR__"npc/xunbucao" : 1,
]));
  set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"nandajie1",
  "east" : __DIR__"dangpu2",
  "up" : __DIR__"xiaobaozhai",
]));
  set("no_beg", 1);
  set("no_fight", 1);
  set("no_steal", 1);

  setup();
  replace_program(ROOM);
}
