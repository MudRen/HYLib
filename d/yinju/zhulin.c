inherit ROOM;

void create()
{
  set("short","����");
  set("long",@LONG
 ����һƬï�ܵ������֣�һ�߽�������·���ʧ����
�ĺ����У�����һ�����ӵĺõط���
LONG);
  set("outdoors","yinju");
set("exits",([
   "west"  : __DIR__"hetang",
  "east"  : __DIR__"shishi",
"north"  : __DIR__"xiangfan",
        ]));
  setup();
}