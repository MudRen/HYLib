// Room: /d/pingan/kefang
inherit ROOM;

void create ()
{
  set ("short", "�ͷ�");
  set ("long", @LONG
�����ƽ����ջ�Ŀͷ����������д���������Ϣ�ĵط�����ֵ������
����ȡ��Ϣ�ѣ����������ǿ������⵽�����˯����
LONG);

  set("no_dazuo",1);set("no_kill",1);set("no_fight",1);
  set("pingan",1);
  set("no_clean_up",1);
  set("sleep_room",1);
  set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"pingankezhan",
]));

  setup();
  replace_program(ROOM);
}
