inherit ROOM;

void create()
{
  set("short","�᷿");
  set("long",@LONG
����һ��ܴ���᷿������ʮ�ּ�ª����ǽ���˼���Сľ����
�������Ŵ��ǿյģ���������ŵ����˹�ȥ��
LONG);
  set("outdoors","yinju");
  set("sleep_room", "1");
set("exits",([
   "south"  : __DIR__"zhulin",
     ]));

  setup();
}
