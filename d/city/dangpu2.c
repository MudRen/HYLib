// Room: /d/city/dangpu2
inherit ROOM;

void create ()
{
  set ("short", "��������");
  set ("long", @LONG
��������ݵ��̵����ң���������ڷ����е�ͬ�������ƹ�ġ���
Ҫ��Ϊ�˰���������˳���Ϸʱ�ݴ�һЩ�����ĵط�����Ȼ���㣬����
����һ��һ��Ĳ�����������Ŷ��������ĺܶ�Ľ�Ǯ����̨��
Ҳ����һ�����ӣ�paizi����
LONG);

  set("item_desc", ([ /* sizeof() == 1 */
  "paizi" : "��������õ����������£�
value  ����
pawn ������
redeem ��ض���
",
]));
  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/xiangling" : 1,
__DIR__"npc/xunbucao" : 1,
]));
  set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"dangpu",
]));
  set("no_magic", 1);
  set("pigging", 1);
 set("no_dazuo",1);
  set("no_fight", 1);

  setup();
  replace_program(ROOM);
}
