inherit ROOM;

void create()
{
  set("short","����");
  set("long",@LONG
 ��ǰ��һƬ���������кɻ����ĺ�ʢ�����˲�������һ��ʫ
������Ҷ����̣�ӳ�պɻ������죬�����������������
���㡣ʱ������ˮ�棬�Ƕ�����ˮ�ס�
LONG);
  set("outdoors","yinju");
set("exits",([
   "west"  : __DIR__"dadian",
  "east"  : __DIR__"zhulin",
        ]));
  setup();
}