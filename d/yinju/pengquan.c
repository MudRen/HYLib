inherit ROOM;

void create()
{
  set("short","��Ȫ");
  set("long",@LONG
������ɽ�ƶ��γɵ���Ȼ��Ȫ����Ȼ�ĺ����˹��ĺۼ���
LONG);
  set("outdoors","yinju");
set("exits",([
   "westdown"    : __DIR__"tiezhou",
   "eastup"  : __DIR__"xishui",
        ]));
  setup();
}