inherit ROOM;

void create()
{
  set("short","����");
  set("long",@LONG
����������֮ɽ������֮�����й������������������Ҹ���
���⡢����������һȺ����С���������ڷ���ǰ�ĵ����о���
�����������󳪽�����һ�����ӷ����黨ǳЦ�����ݣ����˶�
ʱ���𼸷�����֮�С�
LONG);
  set("outdoors","yinju");
set("exits",([
   "north"  : __DIR__"dadian",
  "east"  : __DIR__"shiliang",
        ]));
  setup();
}