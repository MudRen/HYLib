inherit ROOM;

void create()
{
  set("short","�嶥");
  set("long",@LONG
 ������������ɽ��ķ嶥����ʯ�ܴأ���ߵĵط�һʯ
׿����������֮�ƣ���
LONG);
  set("outdoors","yinju");
set("exits",([
   "down"    : __DIR__"xishui",
   "west"  : __DIR__"pingdi",
        ]));
  setup();
}