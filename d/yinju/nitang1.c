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
   "south" : __FILE__,
    "north" : __FILE__,
  "west"  : __DIR__"aishu",
  "east"  : __DIR__"nitang2",
   ]));
  
  setup();
}
