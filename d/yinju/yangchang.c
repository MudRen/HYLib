inherit ROOM;

void create()
{
  set("short","��С��");
  set("long",@LONG
����һ���ɽ�����ͻ����С������Լ�����࣬��������ƾ����
�����о��ߵ�ɫ���ˣ���ͨ��һ�㶼����ͨ����
LONG);
  set("outdoors","yinju");
 set("exits",([
   "westdown"    : __DIR__"aishu",
   "eastup"      : __DIR__"doulu",
        ]));
  setup();
}