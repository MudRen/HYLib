inherit ROOM;

void create()
{
  set("short","��ɭ��");
  set("long",@LONG
����һƬï�ܵĺ�ɭ�֡��ܶ�ü�ʮ�ɸߵĴ�������һ�飬��һ�Ѱ�����
��ɡ�������¶����ڱεð�Ȼ�޹⡣��ɭ������ɭ�ֲ���
LONG);
  set("outdoors","yinju");
set("exits",([
   "west"  : __DIR__"nitang1",
  "east"  : __DIR__"damen",
     ]));
   
  setup();
}
