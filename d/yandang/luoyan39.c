// Room: /d/yandang/luoyan39
inherit ROOM;

void create ()
{
  set ("short", "����");
  set ("long", @LONG
�ƿ��������ڵ�С��,��һ��СС�Ķ���,ֻ�ǰ��˼��Ű�С������
�и�Сͯ����һ������С��¯�Բ������������Ż�,�����м�����,д��
�ݺῪ��,ϸ����,��½���'�辭'.
LONG);

  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/xiaotong.c" : 1,
]));
  set("exits", ([ /* sizeof() == 2 */
  "southeast" : __DIR__"luoyan38",
  "north" : __DIR__"luoyan13",
]));

  setup();
}
