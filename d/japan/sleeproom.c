// Room: /d/japan/sleeproom
inherit ROOM;

void create()
{
  set ("short", "˯��");
  set ("long", @LONG
һ�䲻��ķ���,�м��������,��ʰ�û�ͦ�ɾ�.ǽ�ŵĻ�ƿ�л�
����֦��.ǽ�Ϻ����Ǹɾ��İ�ֽ.
LONG);
   set("sleep_room",1);
   set("no_fight",1);
  set("exits", ([ /* sizeof() == 1 */
  "down" : __DIR__"lvdian",
]));
  setup();
         replace_program(ROOM);
}
