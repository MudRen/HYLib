inherit ROOM;

void create()
{
  set("short","ˮ����");
  set("long",@LONG
 ��������ˮ���ߡ����ղ������˳��������洫�������ĵƹ⡣
LONG);
  set("outdoors","yinju");
set("exits",([
   "out"  : __DIR__"damen",
  "northeast"  : __DIR__"maowu",
   ]));
  setup();
}
