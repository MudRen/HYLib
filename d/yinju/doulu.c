inherit ROOM;

void create()
{
  set("short","��·");
  set("long",@LONG
����һ�����͵�ɽ·����ɽ�򶼲�һ����ȥ��
LONG);
  set("outdoors","yinju");
set("exits",([
   "westdown"    : __DIR__"yangchang",
   "eastup"  : __DIR__"pubu",
        ]));
  setup();
}