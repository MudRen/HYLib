// Room: /city/garments.c

inherit ROOM;

void create ()
{
  set ("short", "���µ�");
  set ("long", @LONG
�������������¹󸾳���֮��������Ҳ��������Ҳң�֬�ۺ�ɡ���Ϊ
��������ʱ�У�һֱ�����������Ե�װ�硣�����Ǹ��ܿ��˵�СŮ��������
��һ������ʱ���������������Ů�˼���һ�𣬻�������������
    ���ſں�������д�ż�������(zi)����������С���ֱʡ�
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "down" : __DIR__"zahuopu",
  "southdown" : __DIR__"fengreiroom",
]));
  set("item_desc", ([ /* sizeof() == 1 */
  "zi" : "list ����buy ��
",
]));
  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/zeng" : 1,
]));

  setup();
  replace_program(ROOM);
}
