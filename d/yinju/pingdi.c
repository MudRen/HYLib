inherit ROOM;

void create()
{
  set("short","ƽ��");
  set("long",@LONG
 ���˷嶥��ȻһƬ������ɽ�أ�ƽ̹���ơ�
LONG);
  set("outdoors","yinju");
set("exits",([
   "east"    : __DIR__"fengding",
   "west"  : __DIR__"shanpo",
        ]));
  setup();
}