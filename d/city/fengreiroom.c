// Room: /d/city/fengreiroom
inherit ROOM;

void create ()
{
  set ("short", "���ҵ�");
  set ("long", @LONG
���������֪�������Ϸ��ҵ꣬����һ��������Ů���Ծ��ؿ���С�ꡣ
��˵�����Ծ��ؼ����������ҵ�һ��ΪҶ���Ĵ���·�����ݣ������ֳ�ǮΪ
���������СС���ҵ꣬������ʳס���������䡣�����������յ������
������һ��СС���ơ���paizi��
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "northup" : __DIR__"garments",
  "south" : __DIR__"kufang",
]));
  set("item_desc", ([ /* sizeof() == 1 */
  "paizi" : "�����ҹ���[����]���¡�
",
]));
  set("no_fight", 1);
  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/zhaojunrong" : 1,
]));
  set("no_magic", 1);

  setup();
  replace_program(ROOM);
}
