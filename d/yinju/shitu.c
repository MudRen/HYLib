inherit ROOM;

void create()
{
  set("short","ʵ����");
  set("long",@LONG
 ������һƬʵ�����ϡ�����̤ʵ���ˣ����洫�������ƹ⡣
LONG);
  set("outdoors","yinju");
set("exits",([
   "out"  : __DIR__"damen",
  "southeast"  : __DIR__"maowu",
      ]));
  setup();
}
