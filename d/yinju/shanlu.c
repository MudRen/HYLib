inherit ROOM;

void create()
{
  set("short","ɽ·");
  set("long",@LONG
�����Ƕ��͵�ɽ·��һ���˲��ᵽ����������
С�ĺ����ױ����鵽�¹�֮�С�
LONG);
  set("outdoors","yinju");
 set("exits",([
   "east"    : __DIR__"shanpo",
   "west"  : __DIR__"shiliang",
        ]));
  setup();
}