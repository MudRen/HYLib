inherit ROOM;

void create()
{
  set("short","������");
  set("long",@LONG
����һƬï�ܵİ����֡����ϳ����˳��ݣ�������䲻������
�������л���ʱ������������Ȼ����������
LONG);
  set("outdoors","yinju");
   set("exits",([
   "east"    : __DIR__"nitang1",
   "eastup"  : __DIR__"yangchang",
   "southdown"  : "d/dali/road4",
        ]));
  setup();
}