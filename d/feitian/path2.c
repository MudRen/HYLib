//Room: /d/feitian/path2.c
inherit ROOM;

void create()
{
   set ("short", "��·");
  set ("long", @LONG
һ�������Ļ��������Զ�����쿪ȥ�����߾�����ʷ�Ŷ�����
Ρ������Ÿ߸ߵ������ţ���������������Ѳ�ӡ����ֵ�����
��ͣ�Ĵ�����
LONG);

  set("exits", ([ /* sizeof() == 1 */
     "northwest" : __DIR__"path1",
      "east" : __DIR__"ximen",
      "north" : __DIR__"zhongxiandao"
]));
  set("outdoors", "feitian");
  setup();
        replace_program(ROOM);
}
