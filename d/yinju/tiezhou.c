inherit ROOM;

void create()
{
  set("short","����");
  set("long",@LONG
 һҶ���ۣ����Ҳ�����������ˡ���ͨ�������Ƶģ�����
Ҳ�����ġ�
LONG);
  set("outdoors","yinju");
   set("exits",([
   "westdown"    : __DIR__"pubu",
   "eastup"  : __DIR__"pengquan",
        ]));
  setup();
}