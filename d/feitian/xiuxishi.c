// Room: /d/feitian/xiuxishi
inherit ROOM;

void create()
{
  set ("short", "��Ϣ��");
  set ("long", @LONG
��Ż�����������Ϣ�ҡ����µ�����ϰ���˺������������Ϣ��
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"xiulianshi",
]));
  set("no_clean_up", 1);
set("sleep_room",1);
  set("no_fight", 1);
  set("no_magic", 1);
  setup();
  replace_program(ROOM);
}
