inherit ROOM;

void create()
{
  set("short","��̶");
  set("long",@LONG
��������̶�У����ܾ����ĵ��Ĵ�ɢ���Ÿ��ܵ���ζ��
�Ͻ����ҳ�·���뿪��̶Ϊ�á�
LONG);
  set("outdoors","yinju");
set("exits",([
   "east" : __FILE__,
    "north" : __FILE__,
  "west"  : __DIR__"nitang1",
  "south"  : __DIR__"nitang3",
   ]));
  
  setup();
}
