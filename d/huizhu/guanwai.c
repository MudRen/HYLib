// Room: /d/huizhu/guanwai
inherit ROOM;

void create()
{
  set ("short", "��������");
  set ("long", @LONG
��������һƬƶ�գ�ɢ�����ʯ�м伸��С���ڷ��в�����ԶԶ�Ļ�
ɳ������𣬻�ɳ����һ�ӳ������նӣ�һ�����ϵ������ڳ�����һ����
����,�����᲻��,ǰ���Ǹ��,������ɳ̲.����������,Զ����Ұ������һ
����·ͨ����ɽ��
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "northwest" : __DIR__"huanglu1",
  "southwest" : __DIR__"shamo",
  "east" : __DIR__"jiayuguan",
  "southeast" : "d/jyguan/ximen",
]));
  set("outdoors", "huizhu");
  setup();
  replace_program(ROOM);
}
